// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_crypto_ops.h for the primary calling header

#include "Vtb_crypto_ops__pch.h"
#include "Vtb_crypto_ops__Syms.h"
#include "Vtb_crypto_ops___024root.h"

// Parameter definitions for Vtb_crypto_ops___024root
constexpr VlUnpacked<IData/*31:0*/, 8> Vtb_crypto_ops___024root::tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H0_INIT;
constexpr VlUnpacked<IData/*31:0*/, 8> Vtb_crypto_ops___024root::tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H0_INIT;
constexpr VlUnpacked<IData/*31:0*/, 8> Vtb_crypto_ops___024root::tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H0_INIT;


void Vtb_crypto_ops___024root___ctor_var_reset(Vtb_crypto_ops___024root* vlSelf);

Vtb_crypto_ops___024root::Vtb_crypto_ops___024root(Vtb_crypto_ops__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_crypto_ops___024root___ctor_var_reset(this);
}

void Vtb_crypto_ops___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_crypto_ops___024root::~Vtb_crypto_ops___024root() {
}
