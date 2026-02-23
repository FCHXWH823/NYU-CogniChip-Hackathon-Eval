// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_up_down_counter.h for the primary calling header

#ifndef VERILATED_VTB_UP_DOWN_COUNTER___024ROOT_H_
#define VERILATED_VTB_UP_DOWN_COUNTER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_up_down_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_up_down_counter___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_up_down_counter__DOT__clock;
    CData/*0:0*/ tb_up_down_counter__DOT__reset;
    CData/*0:0*/ tb_up_down_counter__DOT__enable;
    CData/*0:0*/ tb_up_down_counter__DOT__direction;
    CData/*2:0*/ tb_up_down_counter__DOT__count;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_up_down_counter__DOT__clock__0;
    IData/*31:0*/ tb_up_down_counter__DOT__error_count;
    IData/*31:0*/ tb_up_down_counter__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_up_down_counter__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h758a99c0__0;

    // INTERNAL VARIABLES
    Vtb_up_down_counter__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_up_down_counter___024root(Vtb_up_down_counter__Syms* symsp, const char* namep);
    ~Vtb_up_down_counter___024root();
    VL_UNCOPYABLE(Vtb_up_down_counter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
