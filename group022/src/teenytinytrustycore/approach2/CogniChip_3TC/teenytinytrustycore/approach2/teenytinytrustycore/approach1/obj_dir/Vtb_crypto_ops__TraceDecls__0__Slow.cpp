// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vtb_crypto_ops___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"INIT_IDLE", "INIT_PUF_DUS", "INIT_PUF_DEVID", 
                                "INIT_WAIT_DUS", "INIT_DERIVE_KEYS", 
                                "INIT_WAIT_KDF", "INIT_DISTRIBUTE_KEYS", 
                                "INIT_COMPLETE", "FAULT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000"};
        tracep->declDTypeEnum(1, "root_of_trust_top.init_state_t", 9, 4, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "KEY_EXPAND", "ENCRYPT_CTR", "XOR_DATA", 
                                "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100"};
        tracep->declDTypeEnum(2, "aes_ctr.state_t", 5, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "INNER_INIT", "INNER_HASH", "OUTER_INIT", 
                                "OUTER_HASH", "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(3, "hmac_sha256.state_t", 6, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "LOAD", "COMPUTE", "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(4, "sha256_core.state_t", 4, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXTRACT_INIT", "EXTRACT_INNER", 
                                "EXTRACT_OUTER", "EXPAND_HMAC_1", 
                                "EXPAND_HMAC_2", "EXPAND_AES_1", 
                                "EXPAND_AES_2", "EXPAND_SHA_1", 
                                "EXPAND_SHA_2", "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010"};
        tracep->declDTypeEnum(5, "kdf_module.state_t", 11, 4, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "VALIDATE_KEYS", "DISTRIBUTE", "ACTIVE", 
                                "ZEROIZE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100"};
        tracep->declDTypeEnum(6, "secure_key_distributor.state_t", 5, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "ENROLLING", "READING", "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(7, "puf_device_id.state_t", 4, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "ENROLL_MEASURE", "ENROLL_GENERATE", 
                                "REGEN_MEASURE", "REGEN_CORRECT", 
                                "DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(8, "puf_dus.state_t", 6, 3, __VenumItemNames, __VenumItemValues);
    }
}

void Vtb_crypto_ops___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtb_crypto_ops___024root__traceDeclTypesSub0(tracep);
}
