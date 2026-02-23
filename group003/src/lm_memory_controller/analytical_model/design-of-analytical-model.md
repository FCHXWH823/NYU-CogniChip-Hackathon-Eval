# LLM Memory Controller 解析代价模型
## 输入参数
### Tiling 参数
- tile_m, tile_n, tile_k：GEMM 分块维度（对应 M×N×K 三个轴）
- buffer_scheme：缓冲策略
  - SINGLE：无重叠，顺序执行 load → compute
  - DOUBLE_B：权重双缓冲，load_B 与 compute 重叠
  - DOUBLE_A：激活双缓冲，load_A 与内层循环重叠
  - DOUBLE_AB：A/B 均双缓冲，最大重叠
### 硬件参数
- SRAM：总容量（默认 2MB）、bank 数量（4）、单 bank 大小（512KB）
- DRAM：峰值带宽（50 GB/s）、page-hit 延迟（17ns）、page-miss 延迟（52ns）、burst 效率（90%）、page-hit 率（70%）
- 计算阵列：MAC 阵列尺寸（32×32）、频率（500MHz）
- 数据类型：激活 INT8（1B）、权重 INT4（0.5B）、累加器 INT32（4B）、输出 INT8（1B）
### GEMM 形状
- M：输出行数（seq_len，decode=1，prefill=256+）
- N：输出列数（投影输出维度）
- K：内积维度（投影输入维度）
---
## 计算逻辑
### Step 1：SRAM 分配与 J_c 计算
A_tile_bytes = tile_m × tile_k × 1B × (2 if double_A else 1)
B_tile_bytes = tile_k × tile_n × 0.5B × (2 if double_B else 1)
C_tile_bytes = tile_m × tile_n × 4B  # INT32 累加器
剩余SRAM = SRAM_total - A_buf - B_buf
J_c = floor(剩余SRAM / C_tile_bytes)  # 同时保持的输出 tile 数
J_c 是关键优化因子：J_c 越大，A 在多个输出列上复用的次数越多，DRAM 读取 A 的次数越少。
### Step 2：Tile 迭代次数
n_m = ceil(M / tile_m)     # 输出行 tile 数
n_n = ceil(N / tile_n)     # 输出列 tile 数
n_k = ceil(K / tile_k)     # 规约维度 tile 数
n_jg = ceil(n_n / J_c)     # 输出列分组数
### Step 3：DRAM 流量计算（考虑 A 复用）
循环嵌套结构（A-复用 + 输出分组）：
for i in [n_m]:              # 输出行
  for jg in [n_jg]:          # 输出列分组
    init J_c 个 C tiles
    for k in [n_k]:          # 规约
      load A[i,k]            # 在 J_c 列上复用
      for j in [J_c]:
        load B[k, jg·J_c+j]
        C += A × B
    store J_c 个 C tiles
DRAM 流量：
A_loads = n_m × n_jg × n_k           # A 复用因子 = J_c
B_loads = n_m × n_n × n_k            # B 无跨行复用
C_writes = n_m × n_n
DRAM_read_A = A_loads × (tile_m × tile_k × 1B)
DRAM_read_B = B_loads × (tile_k × tile_n × 0.5B)
DRAM_write_C = C_writes × (tile_m × tile_n × 1B)  # 输出已 requant 为 INT8
DRAM_total = DRAM_read_A + DRAM_read_B + DRAM_write_C
### Step 4：计算周期
#### 每 tile 计算周期（考虑 MAC 阵列子分块）
sub_tiles_m = ceil(tile_m / 32)
sub_tiles_n = ceil(tile_n / 32)
compute_per_tile = sub_tiles_m × sub_tiles_n × tile_k
#### 总计算周期
compute_cycles = n_m × n_n × n_k × compute_per_tile
#### 理想周期（100% MAC 利用率）
ideal_cycles = (M × N × K) / 1024  # 1024 = 32×32 MACs/cycle
### Step 5：内存传输周期（物理级模型）
avg_latency = 0.7 × 17ns + 0.3 × 52ns = 27.5ns  # page-hit/miss 加权
sustained_bw = 50 GB/s × 0.9 = 45 GB/s
transfer_time(bytes, num_txn) = num_txn × (avg_latency + bytes/num_txn / sustained_bw)
小 tile 受延迟主导（惩罚），大 tile 受带宽主导（奖励）。
### Step 6：总周期（流水线重叠模型）
单次 k 迭代的时间取决于 buffer scheme：
| Scheme | 每次 k 迭代时间 |
|--------|----------------|
| SINGLE | load_A + J_c × (load_B + compute) |
| DOUBLE_B | load_A + load_B + (J_c-1) × max(load_B, compute) + compute |
| DOUBLE_A | max(load_A, J_c × (load_B + compute)) |
| DOUBLE_AB | max(load_A, load_B + (J_c-1) × max(load_B, compute) + compute) |
total_cycles = n_m × n_jg × (n_k × t_k_iter + t_store_group)
             + startup_cost  # 首个 A tile 无法重叠
---
# 输出指标
| 指标 | 公式 | 单位 |
|------|------|------|
| 总 DRAM 流量 | DRAM_read_A + DRAM_read_B + DRAM_write_C | GB |
| 计算利用率 | ideal_cycles / total_cycles × 100% | % |
| 总周期数 | 流水线重叠模型计算 | cycles |
| MAC 阵列效率 | 有效MACs / 阵列MACs（边缘 tile 损失） | % |
| 算术强度 | total_MACs / DRAM_total | MACs/Byte |
| 是否计算受限 | compute_cycles ≥ memory_cycles | bool |
