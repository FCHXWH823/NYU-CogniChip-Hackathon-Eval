"""
Configuration data classes for the LLM Memory Controller analytical model.

Defines hardware parameters (edge SoC), model architecture (Qwen3-8B),
and tiling/buffer scheme enumerations.
"""

from dataclasses import dataclass
from enum import Enum
import math


# ---------------------------------------------------------------------------
# Enumerations
# ---------------------------------------------------------------------------


class BufferScheme(Enum):
    """SRAM double-buffering strategy."""

    SINGLE = "single"  # No overlap: load then compute sequentially
    DOUBLE_B = "double_b"  # Double-buffer weights: overlap weight load + compute
    DOUBLE_A = "double_a"  # Double-buffer activations
    DOUBLE_AB = "double_ab"  # Double-buffer both (most SRAM, best overlap)


class InferenceMode(Enum):
    PREFILL = "prefill"
    DECODE = "decode"


# ---------------------------------------------------------------------------
# Model Configuration
# ---------------------------------------------------------------------------


@dataclass(frozen=True)
class ModelConfig:
    """Transformer model architecture parameters."""

    name: str
    num_layers: int
    hidden_size: int
    num_q_heads: int
    num_kv_heads: int
    intermediate_size: int
    head_dim: int
    vocab_size: int
    max_seq_len: int

    @property
    def kv_dim(self) -> int:
        """Total KV projection dimension = num_kv_heads * head_dim."""
        return self.num_kv_heads * self.head_dim

    @property
    def gqa_ratio(self) -> int:
        """GQA group size: how many Q heads share one KV head."""
        return self.num_q_heads // self.num_kv_heads


# Pre-built model configs
QWEN3_8B = ModelConfig(
    name="Qwen3-8B",
    num_layers=36,
    hidden_size=4096,
    num_q_heads=32,
    num_kv_heads=8,
    intermediate_size=12288,
    head_dim=128,
    vocab_size=151936,
    max_seq_len=40960,
)


# ---------------------------------------------------------------------------
# Hardware Configuration
# ---------------------------------------------------------------------------


@dataclass(frozen=True)
class HWConfig:
    """
    Hardware configuration for the target edge SoC.

    Default values target a representative edge configuration:
    - 2 MB on-chip SRAM (4 x 512 KB banks)
    - 50 GB/s LPDDR5-6400 (dual x32 channels)
    - 32x32 INT8 MAC array @ 500 MHz
    """

    # ---- SRAM ----
    sram_total_bytes: int = 2 * 1024 * 1024  # 2 MB
    sram_num_banks: int = 4
    sram_bank_bytes: int = 512 * 1024  # 512 KB per bank

    # ---- DRAM (LPDDR5-6400) ----
    dram_peak_bw_gbps: float = 50.0  # GB/s  (dual x32 @ 6400 MT/s)
    dram_page_hit_latency_ns: float = 17.0  # CAS latency (row already active)
    dram_page_miss_latency_ns: float = 52.0  # tRP + tRCD + tCL (full row cycle)
    dram_burst_bytes: int = 32  # BL16 x 2 bytes (x16 channel)
    dram_burst_efficiency: float = 0.90  # Sustained burst utilization
    dram_page_hit_rate: float = 0.70  # Fraction of accesses hitting open row

    # ---- Compute (MAC array) ----
    mac_array_m: int = 32
    mac_array_n: int = 32
    mac_freq_mhz: int = 500

    # ---- Data types ----
    act_bytes: float = 1.0  # INT8 activations
    weight_bytes: float = 0.5  # INT4 weights
    acc_bytes: int = 4  # INT32 accumulator
    output_bytes: float = 1.0  # INT8 output (post-requantization)

    # ---- Derived properties ----

    @property
    def macs_per_cycle(self) -> int:
        """Peak MAC operations per clock cycle."""
        return self.mac_array_m * self.mac_array_n  # 1024

    @property
    def peak_gops(self) -> float:
        """Peak throughput in GOPS (giga-operations per second)."""
        return self.macs_per_cycle * self.mac_freq_mhz / 1000.0

    @property
    def cycle_time_ns(self) -> float:
        """Clock period in nanoseconds."""
        return 1000.0 / self.mac_freq_mhz  # 2.0 ns @ 500 MHz

    @property
    def dram_bw_bytes_per_ns(self) -> float:
        """Peak DRAM bandwidth in bytes/ns (numerically == GB/s)."""
        return self.dram_peak_bw_gbps

    @property
    def dram_bw_bytes_per_cycle(self) -> float:
        """Peak DRAM bandwidth in bytes per compute clock cycle."""
        return self.dram_bw_bytes_per_ns * self.cycle_time_ns  # 100 B/cyc

    def dram_transfer_cycles(self, num_bytes: int, num_transactions: int = 1) -> float:
        """
        Estimate DRAM transfer time in compute-clock cycles.

        Models each transaction as:
            t = avg_initial_latency + payload / sustained_bandwidth

        This penalises many small transfers (latency-dominated) and
        rewards large sequential bursts (bandwidth-dominated).

        Args:
            num_bytes: Total bytes to transfer.
            num_transactions: Number of separate DMA requests.
        """
        if num_bytes <= 0:
            return 0.0

        bytes_per_txn = num_bytes / num_transactions
        avg_latency_ns = (
            self.dram_page_hit_rate * self.dram_page_hit_latency_ns
            + (1 - self.dram_page_hit_rate) * self.dram_page_miss_latency_ns
        )
        sustained_bw = self.dram_bw_bytes_per_ns * self.dram_burst_efficiency
        time_per_txn_ns = avg_latency_ns + bytes_per_txn / sustained_bw
        total_ns = num_transactions * time_per_txn_ns
        return total_ns / self.cycle_time_ns


# Default hardware configuration
DEFAULT_HW = HWConfig()
