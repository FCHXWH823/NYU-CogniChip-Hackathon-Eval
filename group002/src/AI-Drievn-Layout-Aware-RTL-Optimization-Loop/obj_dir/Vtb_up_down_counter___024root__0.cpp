// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_up_down_counter.h for the primary calling header

#include "Vtb_up_down_counter__pch.h"

VL_ATTR_COLD void Vtb_up_down_counter___024root___eval_initial__TOP(Vtb_up_down_counter___024root* vlSelf);
VlCoroutine Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_up_down_counter___024root* vlSelf);
VlCoroutine Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_up_down_counter___024root* vlSelf);

void Vtb_up_down_counter___024root___eval_initial(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_initial\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_up_down_counter___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_up_down_counter__DOT__clock = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000000032ULL, 
                                             nullptr, 
                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                             19);
        vlSelfRef.tb_up_down_counter__DOT__clock = 
            (1U & (~ (IData)(vlSelfRef.tb_up_down_counter__DOT__clock)));
    }
    co_return;}

VlCoroutine Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__0__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__0__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__0__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__1__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__1__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__1__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__1__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__1__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__1__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__2__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__2__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__2__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__3__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__3__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__3__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__4__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__4__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__4__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__4__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__4__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__4__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__5__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__5__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__5__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__5__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__5__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__5__exp_min = 0;
    CData/*2:0*/ __Vtask_tb_up_down_counter__DOT__check__6__exp_count;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_count = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__6__exp_max;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_max = 0;
    CData/*0:0*/ __Vtask_tb_up_down_counter__DOT__check__6__exp_min;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_min = 0;
    // Body
    VL_WRITEF_NX("TEST START\n",0);
    vlSelfRef.tb_up_down_counter__DOT__error_count = 0U;
    vlSelfRef.tb_up_down_counter__DOT__reset = 1U;
    vlSelfRef.tb_up_down_counter__DOT__enable = 0U;
    vlSelfRef.tb_up_down_counter__DOT__direction = 1U;
    co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_up_down_counter.clock)", 
                                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_up_down_counter__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_up_down_counter.clock)", 
                                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_min = 1U;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_max = 0U;
    __Vtask_tb_up_down_counter__DOT__check__0__exp_count = 0U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__0__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    VL_WRITEF_NX("LOG: Test 1 - Reset check\n",0);
    vlSelfRef.tb_up_down_counter__DOT__enable = 1U;
    vlSelfRef.tb_up_down_counter__DOT__direction = 1U;
    vlSelfRef.tb_up_down_counter__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 7U, vlSelfRef.tb_up_down_counter__DOT__unnamedblk1__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_up_down_counter.clock)", 
                                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                             74);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                             74);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.tb_up_down_counter__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__unnamedblk1__DOT__i);
    }
    __Vtask_tb_up_down_counter__DOT__check__1__exp_min = 0U;
    __Vtask_tb_up_down_counter__DOT__check__1__exp_max = 1U;
    __Vtask_tb_up_down_counter__DOT__check__1__exp_count = 7U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__1__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    VL_WRITEF_NX("LOG: Test 2 - Count UP reached 7\n",0);
    co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_up_down_counter.clock)", 
                                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                         80);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         80);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_min = 1U;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_max = 0U;
    __Vtask_tb_up_down_counter__DOT__check__2__exp_count = 0U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__2__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    VL_WRITEF_NX("LOG: Test 3 - UP wrap 7\342\206\2220\n",0);
    vlSelfRef.tb_up_down_counter__DOT__direction = 0U;
    co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_up_down_counter.clock)", 
                                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                         86);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         86);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_min = 0U;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_max = 1U;
    __Vtask_tb_up_down_counter__DOT__check__3__exp_count = 7U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__3__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    VL_WRITEF_NX("LOG: Test 4 - DOWN wrap 0\342\206\2227\n",0);
    vlSelfRef.tb_up_down_counter__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 7U, vlSelfRef.tb_up_down_counter__DOT__unnamedblk2__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_up_down_counter.clock)", 
                                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                             92);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                             92);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.tb_up_down_counter__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__unnamedblk2__DOT__i);
    }
    __Vtask_tb_up_down_counter__DOT__check__4__exp_min = 1U;
    __Vtask_tb_up_down_counter__DOT__check__4__exp_max = 0U;
    __Vtask_tb_up_down_counter__DOT__check__4__exp_count = 0U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__4__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    VL_WRITEF_NX("LOG: Test 5 - Count DOWN reached 0\n",0);
    vlSelfRef.tb_up_down_counter__DOT__enable = 0U;
    tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_up_down_counter.clock)", 
                                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                             100);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                             100);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_tb_up_down_counter__DOT__check__5__exp_min = 1U;
        __Vtask_tb_up_down_counter__DOT__check__5__exp_max = 0U;
        __Vtask_tb_up_down_counter__DOT__check__5__exp_count = 0U;
        if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                          != (IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_count))))) {
            VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         3,(IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_count),
                         3,vlSelfRef.tb_up_down_counter__DOT__count);
            vlSelfRef.tb_up_down_counter__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
        }
        if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                          != (IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_max))))) {
            VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         1,(IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_max),
                         1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
            vlSelfRef.tb_up_down_counter__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
        }
        if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                          != (IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_min))))) {
            VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         1,(IData)(__Vtask_tb_up_down_counter__DOT__check__5__exp_min),
                         1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
            vlSelfRef.tb_up_down_counter__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
        }
        tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_up_down_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_WRITEF_NX("LOG: Test 6 - Enable=0 holds\n",0);
    vlSelfRef.tb_up_down_counter__DOT__enable = 1U;
    vlSelfRef.tb_up_down_counter__DOT__direction = 1U;
    tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 = 3U;
    while (VL_LTS_III(32, 0U, tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_up_down_counter.clock)", 
                                                             "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                             108);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_up_down_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    vlSelfRef.tb_up_down_counter__DOT__reset = 1U;
    co_await vlSelfRef.__VtrigSched_h758a99c0__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_up_down_counter.clock)", 
                                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                                         110);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         110);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_min = 1U;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_max = 0U;
    __Vtask_tb_up_down_counter__DOT__check__6__exp_count = 0U;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_count))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : count : expected 3'd%0# actual 3'd%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,3,(IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_count),
                     3,vlSelfRef.tb_up_down_counter__DOT__count);
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_max))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_max : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_max),
                     1,(7U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)) 
                      != (IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_min))))) {
        VL_WRITEF_NX("LOG: %0t : ERROR : at_min : expected %0b actual %0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(__Vtask_tb_up_down_counter__DOT__check__6__exp_min),
                     1,(0U == (IData)(vlSelfRef.tb_up_down_counter__DOT__count)));
        vlSelfRef.tb_up_down_counter__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.tb_up_down_counter__DOT__error_count);
    }
    vlSelfRef.tb_up_down_counter__DOT__reset = 0U;
    VL_WRITEF_NX("LOG: Test 7 - Reset mid-count\n",0);
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000064ULL, 
                                         nullptr, "/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 
                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_LIKELY(((0U == vlSelfRef.tb_up_down_counter__DOT__error_count)))) {
        VL_WRITEF_NX("TEST PASSED\n",0);
    } else {
        VL_WRITEF_NX("ERROR\n[%0t] %%Error: up_down_counter_tb.sv:121: Assertion failed in %Ntb_up_down_counter: TEST FAILED - %0d errors\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     32,vlSelfRef.tb_up_down_counter__DOT__error_count);
        VL_STOP_MT("/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 121, "");
    }
    VL_FINISH_MT("/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 123, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_up_down_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb_up_down_counter___024root___eval_triggers__act(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_triggers__act\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.tb_up_down_counter__DOT__clock) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_up_down_counter__DOT__clock__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_up_down_counter__DOT__clock__0 
        = vlSelfRef.tb_up_down_counter__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_up_down_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtb_up_down_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 64> Vtb_up_down_counter__ConstPool__TABLE_hca4b5ad0_0;
extern const VlUnpacked<CData/*2:0*/, 64> Vtb_up_down_counter__ConstPool__TABLE_ha1c21975_0;

void Vtb_up_down_counter___024root___nba_sequent__TOP__0(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___nba_sequent__TOP__0\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.tb_up_down_counter__DOT__count) 
                     << 3U) | (((IData)(vlSelfRef.tb_up_down_counter__DOT__direction) 
                                << 2U) | (((IData)(vlSelfRef.tb_up_down_counter__DOT__enable) 
                                           << 1U) | (IData)(vlSelfRef.tb_up_down_counter__DOT__reset))));
    if (Vtb_up_down_counter__ConstPool__TABLE_hca4b5ad0_0
        [__Vtableidx1]) {
        vlSelfRef.tb_up_down_counter__DOT__count = 
            Vtb_up_down_counter__ConstPool__TABLE_ha1c21975_0
            [__Vtableidx1];
    }
}

void Vtb_up_down_counter___024root___eval_nba(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_nba\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_up_down_counter___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vtb_up_down_counter___024root___timing_commit(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___timing_commit\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h758a99c0__0.commit(
                                                   "@(posedge tb_up_down_counter.clock)");
    }
}

void Vtb_up_down_counter___024root___timing_resume(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___timing_resume\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h758a99c0__0.resume(
                                                   "@(posedge tb_up_down_counter.clock)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_up_down_counter___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_up_down_counter___024root___eval_phase__act(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_phase__act\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_up_down_counter___024root___eval_triggers__act(vlSelf);
    Vtb_up_down_counter___024root___timing_commit(vlSelf);
    Vtb_up_down_counter___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_up_down_counter___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtb_up_down_counter___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_up_down_counter___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_up_down_counter___024root___eval_phase__nba(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_phase__nba\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_up_down_counter___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_up_down_counter___024root___eval_nba(vlSelf);
        Vtb_up_down_counter___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_up_down_counter___024root___eval(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_up_down_counter___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_up_down_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/bhanujakarumuru/Downloads/RTL_Automation_updated/test/up_down_counter_tb.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtb_up_down_counter___024root___eval_phase__act(vlSelf));
    } while (Vtb_up_down_counter___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtb_up_down_counter___024root___eval_debug_assertions(Vtb_up_down_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_up_down_counter___024root___eval_debug_assertions\n"); );
    Vtb_up_down_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
