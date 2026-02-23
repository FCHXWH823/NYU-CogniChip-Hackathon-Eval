// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_up_down_counter.h for the primary calling header

#include "Vtb_up_down_counter__pch.h"

VL_ATTR_COLD void Vtb_up_down_counter___024root___eval_static(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_static\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_up_down_counter__DOT__clock__0 
        = vlSelfRef.tb_up_down_counter__DOT__clock;
}

VL_ATTR_COLD void Vtb_up_down_counter___024root___eval_initial__TOP(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_initial__TOP\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vtb_up_down_counter___024root___eval_final(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_final\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_up_down_counter___024root___eval_settle(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_settle\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_up_down_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_up_down_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_up_down_counter___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_up_down_counter.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_up_down_counter___024root___ctor_var_reset(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___ctor_var_reset\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_up_down_counter__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4823927665273650801ull);
    vlSelf->tb_up_down_counter__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5142018805509963880ull);
    vlSelf->tb_up_down_counter__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5155713432525200070ull);
    vlSelf->tb_up_down_counter__DOT__direction = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6770290041562322717ull);
    vlSelf->tb_up_down_counter__DOT__count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 659042433043342691ull);
    vlSelf->tb_up_down_counter__DOT__error_count = 0;
    vlSelf->tb_up_down_counter__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_up_down_counter__DOT__unnamedblk2__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_up_down_counter__DOT__clock__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
