# TTC3 Simulation Results - Icarus Verilog

## 📊 Executive Summary

**Date**: 2026-02-20  
**Simulator**: Icarus Verilog (iverilog)  
**Tests Executed**: 3 testbenches (18 total tests)  
**Overall Status**: ⚠️ **PARTIAL PASS** - Issues found requiring investigation

---

## 🧪 Test Results

### Test 1: DUS Storage Module (`tb_ttc3_dus_storage`)

**Status**: ⚠️ **FAILED** (4/5 tests passed)

| Test # | Test Name | Result | Issue |
|--------|-----------|--------|-------|
| 1 | Write DUS and check valid flag | ✅ PASS | - |
| 2 | Re-write attempt (write-once lock) | ✅ PASS | - |
| 3 | KDF output without request | ✅ PASS | - |
| 4 | KDF request grants access | ❌ **FAIL** | **KDF DUS mismatch** |
| 5 | Reset clears DUS | ✅ PASS | - |

**Summary**: 
- **Passed**: 4/5 tests
- **Failed**: 1/5 tests
- **Errors**: 1
- **Waveform**: `testbenches/tb_ttc3_dus_storage.vcd` (3.2 KB)

**Issue Details**:
- Test 4 failed: KDF is not receiving the correct DUS value when requested
- This indicates a potential bug in the KDF request path in `ttc3_dus_storage.sv`
- The DUS value sent to KDF doesn't match the stored DUS

**Action Required**: 🔴 **CRITICAL** - Fix KDF access path in DUS storage module

---

### Test 2: Device ID Module (`tb_ttc3_device_id`)

**Status**: ✅ **PASSED** (5/5 tests passed)

| Test # | Test Name | Result | Details |
|--------|-----------|--------|---------|
| 1 | ID valid after reset | ✅ PASS | ID: 0xdeadbeefcafebabe0123456789abcdef |
| 2 | ID is non-zero | ✅ PASS | - |
| 3 | ID immutability | ✅ PASS | - |
| 4 | Fuse input overrides default | ✅ PASS | New ID: 0x123456789abcdef0fedcba9876543210 |
| 5 | New ID also immutable | ✅ PASS | - |

**Summary**:
- **Passed**: 5/5 tests
- **Failed**: 0/5 tests
- **Errors**: 0
- **Waveform**: `testbenches/tb_ttc3_device_id.vcd` (2.9 KB)

**Verdict**: ✅ Device ID module working perfectly!

---

### Test 3: Top-Level Integration (`tb_ttc3_top`)

**Status**: ⚠️ **TIMEOUT** (4/8 tests passed before timeout)

| Test # | Test Name | Result | Details |
|--------|-----------|--------|---------|
| 1 | Initialize DUS | ✅ PASS | DUS initialized successfully |
| 2 | Get Device ID | ✅ PASS | ID: 0xdeadbeefcafebabe0123456789abcdef |
| 3 | Device ID Immutability | ✅ PASS | ID remained constant |
| 4 | SHA-256 Hash Operation | ✅ PASS | Hash: 0xda5698be17b9b469... |
| 5 | HMAC-SHA256 Operation | ⏱️ **TIMEOUT** | Simulation exceeded 1ms |
| 6 | AES-CTR Encryption | ⏹️ **NOT RUN** | Test not reached |
| 7 | Key Derivation | ⏹️ **NOT RUN** | Test not reached |
| 8 | Key Derivation Determinism | ⏹️ **NOT RUN** | Test not reached |

**Summary**:
- **Passed**: 4/8 tests
- **Failed**: 0/8 tests
- **Timeout**: 1/8 tests
- **Not Run**: 3/8 tests
- **Waveform**: `testbenches/tb_ttc3_top.vcd` (2.8 MB - captured data before timeout)

**Issue Details**:
- HMAC operation timed out after 1ms simulation time
- This suggests the HMAC module is stuck in a state or taking too many cycles
- Likely related to the KDF issue found in Test 1 (DUS not being passed correctly)
- SHA-256 worked, so the hash core itself is functional

**Action Required**: 🟠 **HIGH PRIORITY** - Investigate HMAC/KDF timing issue

---

## 🔍 Root Cause Analysis

### Primary Issue: KDF Access Path

**Evidence**:
1. DUS Storage Test 4 failed: "KDF DUS mismatch"
2. Top-level test timed out during HMAC (which uses KDF)
3. SHA-256 (no KDF) worked fine

**Hypothesis**:
The `kdf_request` signal in `ttc3_dus_storage.sv` may not be properly triggering DUS output to the KDF, or the timing of the access is incorrect.

**Affected Modules**:
- `ttc3_dus_storage.sv` - KDF request handling
- `ttc3_kdf.sv` - DUS input handling
- `ttc3_hmac.sv` - Indirectly affected (uses KDF)
- `ttc3_top.sv` - Integration issues

---

## 📈 Test Coverage Summary

| Category | Tests | Passed | Failed | Timeout | Not Run | Coverage |
|----------|-------|--------|--------|---------|---------|----------|
| **DUS Storage** | 5 | 4 | 1 | 0 | 0 | 80% |
| **Device ID** | 5 | 5 | 0 | 0 | 0 | 100% |
| **Integration** | 8 | 4 | 0 | 1 | 3 | 50% |
| **TOTAL** | **18** | **13** | **1** | **1** | **3** | **72%** |

---

## 🌊 Waveform Files

All simulations generated VCD waveform files for debugging:

| File | Size | View Command |
|------|------|--------------|
| `tb_ttc3_dus_storage.vcd` | 3.2 KB | `gtkwave testbenches/tb_ttc3_dus_storage.vcd &` |
| `tb_ttc3_device_id.vcd` | 2.9 KB | `gtkwave testbenches/tb_ttc3_device_id.vcd &` |
| `tb_ttc3_top.vcd` | 2.8 MB | `gtkwave testbenches/tb_ttc3_top.vcd &` |

**Recommendation**: View `tb_ttc3_dus_storage.vcd` to debug the KDF mismatch issue (Test 4)

---

## ⚠️ Compiler Warnings

### Icarus Verilog Compatibility Issues

**Warning**: `sorry: constant selects in always_* processes are not currently supported`
- **Location**: `ttc3_kdf.sv:96`, `ttc3_top.sv:212`
- **Impact**: Moderate - Icarus simulates all bits instead of selected bits
- **Workaround**: Code still functional but less efficient
- **Fix**: Use `always_comb` instead of bit-select assignments in processes

**Warning**: `timescale inherited from another file`
- **Impact**: Low - Just informational
- **Fix**: Add `timescale 1ns/1ps` to each module file

**Warning**: `extra digits given for sized hex constant`
- **Location**: `tb_ttc3_dus_storage.sv:78`
- **Impact**: Low - Constant truncated correctly
- **Fix**: Remove extra digits from hex constant

**Warning**: `always_comb process has no sensitivities`
- **Location**: `ttc3_hmac.sv:85`
- **Impact**: Low - Process still works
- **Fix**: Add sensitivity list or convert to continuous assignment

---

## 🔧 Issues Found

### 🔴 Critical Issues

1. **KDF DUS Mismatch** (Test 1.4)
   - **Module**: `ttc3_dus_storage.sv`
   - **Issue**: KDF not receiving correct DUS value
   - **Impact**: Breaks all KDF-dependent operations (HMAC, AES key derivation)
   - **Priority**: **CRITICAL - FIX IMMEDIATELY**

2. **HMAC Timeout** (Test 3.5)
   - **Module**: `ttc3_hmac.sv` or `ttc3_kdf.sv`
   - **Issue**: Module stuck or infinite loop
   - **Impact**: Cannot complete HMAC operations
   - **Priority**: **HIGH - INVESTIGATE ASAP**

### 🟢 Working Correctly

1. ✅ Device ID module - All tests passed (immutability, fuse input)
2. ✅ DUS write-once lock - Working correctly
3. ✅ Reset behavior - Properly clears state
4. ✅ SHA-256 module - Hash computation works

---

## 📋 Action Items

### Immediate (Do Now)

1. ✅ **View Waveforms**: 
   ```bash
   cd testbenches
   gtkwave tb_ttc3_dus_storage.vcd &
   ```
   Focus on Test 4 timing to see KDF signal values

2. 🔴 **Fix DUS-KDF Interface**:
   - Check `ttc3_dus_storage.sv` lines around `kdf_request` handling
   - Verify `kdf_dus` output logic
   - Ensure proper synchronization

3. 🟠 **Fix HMAC Timeout**:
   - Check `ttc3_hmac.sv` for state machine issues
   - Verify KDF integration in HMAC
   - Add timeout handling in production

### Short Term (This Week)

4. Add more debug outputs to testbenches
5. Create targeted testbench for KDF module alone
6. Add timeout handling to HMAC module
7. Fix Icarus compatibility warnings (if needed for production)

### Long Term (For Production)

8. Add Known Answer Tests (KATs) for crypto correctness
9. Add comprehensive error handling
10. Perform formal verification with commercial tools
11. Add side-channel resistance tests

---

## 🎯 Verification Status

| Property | Status | Evidence |
|----------|--------|----------|
| **Device ID Immutability** | ✅ VERIFIED | All tests passed |
| **DUS Write-Once** | ✅ VERIFIED | Test 1.2 passed |
| **Reset Clears State** | ✅ VERIFIED | Test 1.5 passed |
| **KDF Access Control** | ❌ **BUG FOUND** | Test 1.4 failed |
| **SHA-256 Functionality** | ✅ VERIFIED | Test 3.4 passed |
| **HMAC Functionality** | ❌ **TIMEOUT** | Test 3.5 timed out |
| **AES-CTR** | ⏹️ NOT TESTED | Not reached |
| **Key Derivation** | ⏹️ NOT TESTED | Not reached |

**Overall Confidence**: ⚠️ **MEDIUM** - Core functionality works, but critical bug in KDF path

---

## 📚 How to Debug

### Step 1: View Waveforms

```bash
cd testbenches

# View DUS Storage test (shows KDF mismatch)
gtkwave tb_ttc3_dus_storage.vcd &

# View top-level test (shows HMAC timeout)
gtkwave tb_ttc3_top.vcd &
```

### Step 2: Check Signals

In GTKWave, add these signals to debug:
- `dut.kdf_request`
- `dut.kdf_dus`
- `dut.dus_valid`
- For HMAC: `dut.hmac_busy`, `dut.hmac_done`

### Step 3: Re-run with Modifications

After fixing issues, re-run:
```bash
cd testbenches
make -f Makefile.icarus clean
make -f Makefile.icarus test_all
```

---

## 🏁 Conclusion

**Summary**: The TTC3 design shows good security properties (Device ID immutability, DUS write-once), but has a **critical bug in the KDF access path** that prevents HMAC and other derived-key operations from working correctly.

**Next Steps**: 
1. Fix `ttc3_dus_storage.sv` KDF output logic
2. Re-run simulations to verify fix
3. Complete remaining integration tests

**Simulation Evidence**: All waveforms saved in `testbenches/` folder for detailed analysis.

---

**Generated**: 2026-02-20  
**Simulator**: Icarus Verilog (open-source)  
**Total Runtime**: ~10 seconds  
**Result**: ⚠️ **Issues Found - Fix Required**

