# Hardware Root of Trust - UVM Verification Environment

## Overview

This directory contains the complete UVM-based verification environment for the Hardware Root of Trust (HRoT) design. The testbench implements comprehensive functional and security verification as outlined in the VERIFICATION_PLAN.md.

## Directory Structure

```
tb/
├── README.md                          # This file
├── rot_if.sv                          # Interface definition
├── rot_transaction_pkg.sv             # Transaction classes (sequence items)
├── rot_control_agent.sv               # Control agent (driver, monitor, sequencer)
├── rot_crypto_agents.sv               # Crypto agents (SHA, HMAC, AES)
├── rot_security_monitor.sv            # Security monitoring component
├── rot_env.sv                         # UVM environment (integrates all components)
├── rot_base_test.sv                   # Base test class and sequences
└── rot_tb_top.sv                      # Testbench top module
```

## Architecture

### UVM Component Hierarchy

```
rot_tb_top (module)
└── rot_base_test (uvm_test)
    └── rot_env (uvm_env)
        ├── ctrl_agent (rot_control_agent)
        │   ├── driver (rot_control_driver)
        │   ├── monitor (rot_control_monitor)
        │   └── sequencer (rot_control_sequencer)
        ├── sha_agent (sha256_agent)
        │   ├── driver (sha256_driver)
        │   ├── monitor (sha256_monitor)
        │   └── sequencer (sha256_sequencer)
        ├── hmac_agent (hmac_agent)
        │   ├── driver (hmac_driver)
        │   ├── monitor (hmac_monitor)
        │   └── sequencer (hmac_sequencer)
        ├── aes_agent (aes_agent)
        │   ├── driver (aes_driver)
        │   ├── monitor (aes_monitor)
        │   └── sequencer (aes_sequencer)
        └── security_mon (rot_security_monitor)
```

## Key Components

### 1. Interface (rot_if.sv)
- Connects DUT signals to testbench
- Provides clocking blocks for synchronous operation
- Defines modports for driver, monitor, and DUT

### 2. Transaction Classes (rot_transaction_pkg.sv)
- **rot_control_transaction**: System initialization, zeroization, PUF control
- **sha256_transaction**: SHA-256 hash operations
- **hmac_transaction**: HMAC-SHA-256 MAC operations
- **aes_transaction**: AES-CTR encryption/decryption
- **security_event_transaction**: Security monitoring events

### 3. Agents
- **Control Agent**: Drives system initialization and control signals
- **SHA Agent**: Drives SHA-256 hash operations
- **HMAC Agent**: Drives HMAC-SHA-256 operations
- **AES Agent**: Drives AES-CTR operations

Each agent contains:
- Driver: Drives stimulus to DUT
- Monitor: Observes DUT behavior
- Sequencer: Coordinates sequence execution

### 4. Security Monitor (rot_security_monitor.sv)
Monitors critical security properties:
- **Zeroization**: Verifies keys are cleared on zeroize command
- **Fault Detection**: Tracks security fault events
- **Isolation**: Checks DUS/keys never appear on bus outputs
- **Key Lifecycle**: Monitors key activation/deactivation

### 5. Environment (rot_env.sv)
- Integrates all agents and monitors
- Placeholder for scoreboard (reference models)
- Placeholder for coverage collector

### 6. Base Test and Sequences (rot_base_test.sv)
**Base Sequences:**
- `reset_sequence`: Reset system
- `enroll_sequence`: First-time PUF enrollment
- `regenerate_sequence`: PUF regeneration with helper data
- `zeroize_sequence`: Emergency key zeroization
- `sha_hash_sequence`: SHA-256 hash operation

**Tests:**
- `rot_base_test`: Base test class (runs for 1μs)
- `rot_enrollment_test`: Tests PUF enrollment flow

## Available Tests

### 1. Base Test
```bash
+UVM_TESTNAME=rot_base_test
```
Simple sanity test that runs for 1μs.

### 2. Enrollment Test
```bash
+UVM_TESTNAME=rot_enrollment_test
```
Tests complete PUF enrollment sequence:
1. System initialization
2. PUF DUS enrollment
3. Device ID enrollment
4. Key derivation
5. Key distribution

## Creating New Tests

To create a new test, extend `rot_base_test`:

```systemverilog
class my_custom_test extends rot_base_test;
    `uvm_component_utils(my_custom_test)
    
    function new(string name = "my_custom_test", uvm_component parent = null);
        super.new(name, parent);
    endfunction
    
    task run_phase(uvm_phase phase);
        // Your custom sequences
        enroll_sequence enroll_seq;
        sha_hash_sequence sha_seq;
        
        phase.raise_objection(this);
        
        // Run enrollment
        enroll_seq = enroll_sequence::type_id::create("enroll_seq");
        enroll_seq.start(env.ctrl_agent.sequencer);
        
        // Run SHA hash
        sha_seq = sha_hash_sequence::type_id::create("sha_seq");
        sha_seq.message = 512'hABCD...;
        sha_seq.start(env.sha_agent.sequencer);
        
        #10us;
        phase.drop_objection(this);
    endtask
endclass
```

## Creating New Sequences

To create a new sequence:

```systemverilog
class my_sequence extends uvm_sequence #(rot_control_transaction);
    `uvm_object_utils(my_sequence)
    
    function new(string name = "my_sequence");
        super.new(name);
    endfunction
    
    task body();
        rot_control_transaction trans;
        
        repeat(10) begin
            trans = rot_control_transaction::type_id::create("trans");
            start_item(trans);
            assert(trans.randomize() with {
                // Your constraints
            });
            finish_item(trans);
        end
    endtask
endclass
```

## Running Simulations

### Using Questa/ModelSim
```bash
# Compile
vlog -sv +incdir+$UVM_HOME/src rot_tb_top.sv

# Simulate
vsim -c rot_tb_top -do "run -all; quit" \
    +UVM_TESTNAME=rot_enrollment_test \
    +UVM_VERBOSITY=UVM_MEDIUM
```

### Using VCS
```bash
# Compile and run
vcs -sverilog +incdir+$UVM_HOME/src rot_tb_top.sv \
    -R +UVM_TESTNAME=rot_enrollment_test \
    +UVM_VERBOSITY=UVM_MEDIUM
```

### Using Xcelium
```bash
# Compile
xrun -uvm +incdir+$UVM_HOME/src rot_tb_top.sv \
    +UVM_TESTNAME=rot_enrollment_test \
    +UVM_VERBOSITY=UVM_MEDIUM
```

## UVM Verbosity Levels

Control output detail with `+UVM_VERBOSITY`:
- `UVM_NONE`: No messages
- `UVM_LOW`: Minimal output (default)
- `UVM_MEDIUM`: Standard debug info
- `UVM_HIGH`: Detailed transaction info
- `UVM_FULL`: All debug info
- `UVM_DEBUG`: Maximum detail

## Logging Format

All testbench messages follow the format:
```
LOG: <sim_time> : <level> : <component> : <signal> : expected_value: <exp> actual_value: <act>
```

Example:
```
LOG: 1250 : ERROR : sha256_monitor : sha_hash : expected_value: 0xABCD1234 actual_value: 0x12345678
```

## Viewing Waveforms

The testbench automatically generates FST waveforms in `dumpfile.fst`.

View with VaporView (recommended):
```bash
vaporview dumpfile.fst
```

Or GTKWave:
```bash
gtkwave dumpfile.fst
```

## Security Monitoring

The `rot_security_monitor` continuously checks:

1. **Zeroization Verification**
   - Keys cleared within 10 cycles
   - `keys_active` deasserted
   - Fault state entered

2. **Isolation Checks**
   - DUS never appears on bus outputs
   - Keys never appear on bus outputs
   - Crypto operations only valid when keys active

3. **Fault Detection**
   - Security fault events logged
   - Fault state transitions tracked

### Security Statistics

At end of test, security monitor reports:
```
=== SECURITY MONITOR STATISTICS ===
Zeroization events: 5
Fault events: 2
Isolation violations: 0
SECURITY TEST PASSED: No isolation violations detected
```

## Next Steps

### To Complete the Environment:

1. **Implement Scoreboard** (crypto reference models)
   - SHA-256 reference (OpenSSL/Python)
   - HMAC-SHA-256 reference
   - AES-CTR reference
   - Compare DUT outputs with golden model

2. **Implement Coverage Collector**
   - Functional coverage from verification plan
   - Security event coverage
   - Protocol coverage

3. **Add More Tests**
   - Regeneration test (warm boot)
   - Zeroization test
   - Crypto operations test
   - Fault injection tests
   - Random stress tests

4. **Enhance Security Monitor**
   - DUS isolation tracking (probe internal signals)
   - Key correlation analysis
   - Timing analysis
   - Fault injection controller

## Contact and Support

For questions about this testbench:
- See ../VERIFICATION_PLAN.md for detailed test scenarios
- Check UVM documentation: https://www.accellera.org/downloads/standards/uvm

## Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2024 | Initial UVM environment implementation |
