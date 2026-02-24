# How to Run Simulations with CogniChip

## ✅ DEPS.yml File Created

I've created `DEPS.yml` which defines 3 simulation targets for your testbenches:

| Target | Testbench | Tests | Description |
|--------|-----------|-------|-------------|
| `bench_ttc3_top` | `tb_ttc3_top` | 8 tests | **Full integration test** - Complete TTC3 system |
| `bench_ttc3_dus_storage` | `tb_ttc3_dus_storage` | 5 tests | DUS storage module test |
| `bench_ttc3_device_id` | `tb_ttc3_device_id` | 5 tests | Device ID module test |

---

## 🚀 How to Run Simulation

### Using CogniChip Built-in Simulation Tool

#### Option 1: Right-Click Method
1. **Open** `DEPS.yml` file in editor
2. **Right-click** anywhere in the file
3. **Select** "Run Simulation" (or similar option)
4. **Choose target** from dropdown:
   - `bench_ttc3_top` - Integration test (recommended)
   - `bench_ttc3_dus_storage` - DUS storage test
   - `bench_ttc3_device_id` - Device ID test
5. **Wait** for simulation to complete
6. **View** results in output window

#### Option 2: Command Palette
1. **Open** Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P`)
2. **Type**: "Run Simulation"
3. **Select** `DEPS.yml` file
4. **Choose** target from list
5. **View** results

#### Option 3: Using Built-in Function (if available)
```
Call run_simulation with:
- deps_file_path: "DEPS.yml"
- target: "bench_ttc3_top"
```

---

## 📊 Expected Results

### Test 1: bench_ttc3_top (Integration Test)

**Command**: Select target `bench_ttc3_top`

**Expected Output**:
```
TEST START
========================================
Testing TTC3 Top-Level Integration
========================================

Test 1: Initialize Device Unique Secret
  PASS: DUS initialization completed

Test 2: Get Device ID
  PASS: Device ID retrieved
  Device ID: 0xdeadbeefcafebabe0123456789abcdef

Test 3: Device ID Immutability
  PASS: Device ID is immutable

Test 4: SHA-256 Hash Operation
  PASS: SHA-256 hash computed

Test 5: HMAC-SHA256 Operation
  PASS: HMAC tag computed

Test 6: AES-CTR Encryption
  PASS: AES-CTR ciphertext generated

Test 7: Key Derivation
  PASS: Key derived

Test 8: Key Derivation Determinism
  PASS: Key derivation is deterministic

========================================
TEST SUMMARY
========================================
Total Tests: 8
Errors:      0
TEST PASSED
========================================
```

**Runtime**: ~5-10 seconds

---

### Test 2: bench_ttc3_dus_storage (DUS Storage Test)

**Command**: Select target `bench_ttc3_dus_storage`

**Expected Output**:
```
TEST START
========================================
Testing TTC3 DUS Storage Module
========================================

Test 1: Write DUS and check valid flag
  PASS: DUS valid flag asserted

Test 2: Attempt to re-write DUS (should be locked)
  PASS: DUS remains locked (write-once behavior)

Test 3: KDF output without request
  PASS: KDF DUS is zero when not requested

Test 4: KDF request grants access
  PASS: KDF receives correct DUS when requested

Test 5: Reset clears DUS
  PASS: DUS cleared and not valid after reset

========================================
TEST SUMMARY
========================================
Total Tests: 5
Errors:      0
TEST PASSED
========================================
```

**Runtime**: ~1-2 seconds

---

### Test 3: bench_ttc3_device_id (Device ID Test)

**Command**: Select target `bench_ttc3_device_id`

**Expected Output**:
```
TEST START
========================================
Testing TTC3 Device ID Module
========================================

Test 1: Device ID valid after reset
  PASS: ID valid flag is asserted
  Device ID: 0xdeadbeefcafebabe0123456789abcdef

Test 2: Device ID is non-zero
  PASS: Device ID is non-zero

Test 3: Device ID immutability
  PASS: Device ID remained constant

Test 4: Fuse input overrides default
  PASS: Fuse value correctly loaded
  Device ID: 0x123456789abcdef0fedcba9876543210

Test 5: New ID is also immutable
  PASS: New Device ID remained constant

========================================
TEST SUMMARY
========================================
Total Tests: 5
Errors:      0
TEST PASSED
========================================
```

**Runtime**: ~1-2 seconds

---

## 📁 DEPS.yml Structure

The DEPS.yml file contains:

```yaml
# Testbench targets (for simulation)
bench_ttc3_top:           # Full integration test
  deps:
    - ttc3_dus_storage.sv
    - ttc3_device_id.sv
    - ttc3_kdf.sv
    - ttc3_sha256.sv
    - ttc3_hmac.sv
    - ttc3_aes_ctr.sv
    - ttc3_top.sv
    - testbenches/tb_ttc3_top.sv
  top: tb_ttc3_top

bench_ttc3_dus_storage:   # DUS storage test
  deps:
    - ttc3_dus_storage.sv
    - testbenches/tb_ttc3_dus_storage.sv
  top: tb_ttc3_dus_storage

bench_ttc3_device_id:     # Device ID test
  deps:
    - ttc3_device_id.sv
    - testbenches/tb_ttc3_device_id.sv
  top: tb_ttc3_device_id

# RTL modules (for linting/reference)
dut_ttc3_top:
  deps: [all RTL files]
  top: ttc3_top
```

---

## 🔧 Troubleshooting

### Issue: "Target not found"
**Solution**: Make sure you're selecting from these exact target names:
- `bench_ttc3_top`
- `bench_ttc3_dus_storage`
- `bench_ttc3_device_id`

### Issue: "File not found" errors
**Solution**: Ensure you're running from the project root directory (where DEPS.yml is located)

### Issue: Simulation doesn't start
**Solution**: Check that CogniChip simulation tool is properly configured

### Issue: Unexpected simulation errors
**Solution**: 
1. Try linting first: Right-click on `.sv` files → "Lint"
2. Check the console output for specific error messages
3. Verify all `.sv` files are present in the directory

---

## 🎯 Recommended Test Order

1. **Start with DUS Storage** (fastest, simplest)
   - Target: `bench_ttc3_dus_storage`
   - Verifies basic module functionality
   - ~1 second runtime

2. **Then Device ID** (also fast)
   - Target: `bench_ttc3_device_id`
   - Verifies immutability properties
   - ~1 second runtime

3. **Finally Integration** (comprehensive)
   - Target: `bench_ttc3_top`
   - Tests complete system
   - ~5-10 second runtime
   - **This is the most important test!**

---

## 📊 Success Criteria

All tests should show:
- ✅ `TEST PASSED` at the end
- ✅ `Errors: 0` in summary
- ✅ All individual test steps show `PASS`

If any test shows `FAIL` or `Errors > 0`, there's a functional issue that needs investigation.

---

## 🌊 Viewing Waveforms

After simulation completes:
1. **Look for** `.vcd` or `.fst` file in the output
2. **Open with** waveform viewer (if CogniChip has one integrated)
3. **Or use external** GTKWave:
   ```bash
   gtkwave dumpfile.vcd &
   ```

---

## 📚 Alternative Methods

If CogniChip simulation doesn't work, you can still run with:

### Method 1: Icarus Verilog (Manual)
```bash
cd testbenches
make -f Makefile.icarus test_top
```

### Method 2: Shell Script (Automated)
```bash
cd testbenches
./run_all_tests.sh
```

See `ICARUS_TESTBENCHES_HOWTO.md` for details.

---

## ✨ Summary

✅ **DEPS.yml created**: 3 simulation targets defined  
✅ **Integration test**: `bench_ttc3_top` (8 tests)  
✅ **Unit tests**: `bench_ttc3_dus_storage` (5 tests), `bench_ttc3_device_id` (5 tests)  
✅ **Total coverage**: 18 directed tests  
✅ **Ready to simulate**: Right-click DEPS.yml → Run Simulation  

---

## 🚀 Quick Start

1. **Open** `DEPS.yml`
2. **Right-click** → Run Simulation
3. **Select** `bench_ttc3_top`
4. **Wait** ~5-10 seconds
5. **Verify** output shows "TEST PASSED"

---

**Questions?** Check `ICARUS_TESTBENCHES_HOWTO.md` or `testbenches/README.md`
