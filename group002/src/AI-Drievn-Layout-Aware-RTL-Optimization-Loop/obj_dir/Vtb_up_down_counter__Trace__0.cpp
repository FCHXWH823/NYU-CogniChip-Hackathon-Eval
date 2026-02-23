// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_up_down_counter__Syms.h"


void Vtb_up_down_counter___024root__trace_chg_0_sub_0(Vtb_up_down_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_up_down_counter___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root__trace_chg_0\n"); );
    // Body
    Vtb_up_down_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_up_down_counter___024root*>(voidSelf);
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_up_down_counter___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_up_down_counter___024root__trace_chg_0_sub_0(Vtb_up_down_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root__trace_chg_0_sub_0\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb_up_down_counter__DOT__reset));
        bufp->chgBit(oldp+1,(vlSelfRef.tb_up_down_counter__DOT__enable));
        bufp->chgBit(oldp+2,(vlSelfRef.tb_up_down_counter__DOT__direction));
        bufp->chgIData(oldp+3,(vlSelfRef.tb_up_down_counter__DOT__error_count),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_up_down_counter__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_up_down_counter__DOT__unnamedblk2__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgCData(oldp+6,(vlSelfRef.tb_up_down_counter__DOT__count),3);
        bufp->chgBit(oldp+7,((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count))));
        bufp->chgBit(oldp+8,((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count))));
    }
    bufp->chgBit(oldp+9,(vlSelfRef.tb_up_down_counter__DOT__clock));
}

void Vtb_up_down_counter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root__trace_cleanup\n"); );
    // Body
    Vtb_up_down_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_up_down_counter___024root*>(voidSelf);
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
