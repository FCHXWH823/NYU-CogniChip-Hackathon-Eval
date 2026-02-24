// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_crypto_ops.h for the primary calling header

#include "Vtb_crypto_ops__pch.h"
#include "Vtb_crypto_ops___024root.h"

VL_INLINE_OPT void Vtb_crypto_ops___024root___nba_sequent__TOP__1(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___nba_sequent__TOP__1\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T1 
        = ((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h 
              + ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__x, 6U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__x, 0x1aU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__x, 0xbU) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__x, 0x15U));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__Vfuncout)) 
                                   ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__x, 0x19U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__x, 7U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__Vfuncout));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__Vfuncout)) 
             + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__z 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__y 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__Vfuncout 
                            = ((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__x 
                                & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__y) 
                               ^ ((~ vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__x) 
                                  & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__z));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__Vfuncout)) 
            + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K
            [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round]) 
           + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W
           [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round]);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T2 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__Vfuncout 
                    = ((([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__x, 2U) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__x, 0x1eU));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__Vfuncout) 
                        ^ ([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__x, 0xdU) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__x, 0x13U));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__Vfuncout)) 
                       ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__x 
                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__x;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__Vfuncout 
                                = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__x, 0x16U) 
                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__Vfuncout));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__Vfuncout) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__z 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__y 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__Vfuncout 
                    = (((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__x 
                         & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__y) 
                        ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__x 
                           & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__z)) 
                       ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__y 
                          & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__z));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__Vfuncout));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e;
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [4U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T1);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T1 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T2);
    }
}

extern const VlUnpacked<CData/*1:0*/, 512> Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vtb_crypto_ops__ConstPool__TABLE_h874e84c6_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_crypto_ops__ConstPool__TABLE_hd1ef4c23_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h65830f14_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h67c3227c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h71bbe140_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h2a418c91_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_hfaddc2ce_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_ha0144a61_0;
extern const VlUnpacked<VlWide<8>/*255:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0;

VL_INLINE_OPT void Vtb_crypto_ops___024root___nba_comb__TOP__0(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___nba_comb__TOP__0\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*7:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    SData/*9:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    IData/*31:0*/ __Vtemp_1;
    IData/*31:0*/ __Vtemp_2;
    IData/*31:0*/ __Vtemp_3;
    IData/*31:0*/ __Vtemp_4;
    IData/*31:0*/ __Vtemp_5;
    IData/*31:0*/ __Vtemp_6;
    IData/*31:0*/ __Vtemp_7;
    IData/*31:0*/ __Vtemp_8;
    IData/*31:0*/ __Vtemp_9;
    IData/*31:0*/ __Vtemp_10;
    IData/*31:0*/ __Vtemp_11;
    IData/*31:0*/ __Vtemp_12;
    IData/*31:0*/ __Vtemp_13;
    IData/*31:0*/ __Vtemp_14;
    IData/*31:0*/ __Vtemp_15;
    IData/*31:0*/ __Vtemp_16;
    IData/*31:0*/ __Vtemp_17;
    IData/*31:0*/ __Vtemp_18;
    IData/*31:0*/ __Vtemp_19;
    IData/*31:0*/ __Vtemp_20;
    IData/*31:0*/ __Vtemp_21;
    IData/*31:0*/ __Vtemp_22;
    IData/*31:0*/ __Vtemp_23;
    IData/*31:0*/ __Vtemp_24;
    IData/*31:0*/ __Vtemp_25;
    IData/*31:0*/ __Vtemp_26;
    IData/*31:0*/ __Vtemp_27;
    IData/*31:0*/ __Vtemp_28;
    IData/*31:0*/ __Vtemp_29;
    IData/*31:0*/ __Vtemp_30;
    IData/*31:0*/ __Vtemp_31;
    IData/*31:0*/ __Vtemp_32;
    IData/*31:0*/ __Vtemp_33;
    IData/*31:0*/ __Vtemp_34;
    IData/*31:0*/ __Vtemp_35;
    IData/*31:0*/ __Vtemp_36;
    IData/*31:0*/ __Vtemp_37;
    IData/*31:0*/ __Vtemp_38;
    IData/*31:0*/ __Vtemp_39;
    IData/*31:0*/ __Vtemp_40;
    IData/*31:0*/ __Vtemp_41;
    IData/*31:0*/ __Vtemp_42;
    IData/*31:0*/ __Vtemp_43;
    IData/*31:0*/ __Vtemp_44;
    IData/*31:0*/ __Vtemp_45;
    IData/*31:0*/ __Vtemp_46;
    IData/*31:0*/ __Vtemp_47;
    IData/*31:0*/ __Vtemp_48;
    // Body
    __Vtableidx4 = (((IData)(vlSelfRef.tb_crypto_ops__DOT__sha_start) 
                     << 8U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round) 
                                << 2U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0
        [__Vtableidx4];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
        [7U];
    if ((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state)) 
          & (IData)(vlSelfRef.tb_crypto_ops__DOT__sha_start)) 
         & (IData)(vlSelfRef.tb_crypto_ops__DOT__sha_init))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 8U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[0U] = 0x6a09e667U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[1U] = 0xbb67ae85U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[2U] = 0x3c6ef372U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[3U] = 0xa54ff53aU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[4U] = 0x510e527fU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[5U] = 0x9b05688cU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[6U] = 0x1f83d9abU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[7U] = 0x5be0cd19U;
    } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[0U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [0U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[1U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [1U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[2U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [2U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[3U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [3U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[4U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [4U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[5U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [5U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[6U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [6U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[7U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
               [7U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h);
    }
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[__Vilp1] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xfU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0x10U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0x40U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[1U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xeU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[2U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xdU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[3U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xcU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[4U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xbU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[5U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0xaU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[6U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[9U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[7U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[8U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[8U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[9U] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xaU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xbU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xcU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xdU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xeU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0xfU] 
            = vlSelfRef.tb_crypto_ops__DOT__sha_message[0U];
        __Vtemp_1 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0xeU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [9U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [1U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [0U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x10U] 
            = __Vtemp_1;
        __Vtemp_2 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0xfU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xaU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [2U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [1U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x11U] 
            = __Vtemp_2;
        __Vtemp_3 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x10U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xbU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [3U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [2U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x12U] 
            = __Vtemp_3;
        __Vtemp_4 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x11U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xcU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [4U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [3U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x13U] 
            = __Vtemp_4;
        __Vtemp_5 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x12U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xdU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [5U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [4U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x14U] 
            = __Vtemp_5;
        __Vtemp_6 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x13U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xeU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [6U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [5U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x15U] 
            = __Vtemp_6;
        __Vtemp_7 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x14U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0xfU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [7U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [6U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x16U] 
            = __Vtemp_7;
        __Vtemp_8 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x15U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0x10U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [8U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [7U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x17U] 
            = __Vtemp_8;
        __Vtemp_9 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x16U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                       [0x11U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [9U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                     [8U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x18U] 
            = __Vtemp_9;
        __Vtemp_10 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x17U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x12U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xaU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [9U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x19U] 
            = __Vtemp_10;
        __Vtemp_11 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x18U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x13U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xbU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xaU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1aU] 
            = __Vtemp_11;
        __Vtemp_12 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x19U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x14U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xcU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xbU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1bU] 
            = __Vtemp_12;
        __Vtemp_13 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x15U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xdU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xcU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1cU] 
            = __Vtemp_13;
        __Vtemp_14 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x16U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xeU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xdU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1dU] 
            = __Vtemp_14;
        __Vtemp_15 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x17U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0xfU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xeU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1eU] 
            = __Vtemp_15;
        __Vtemp_16 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x18U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x10U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0xfU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x1fU] 
            = __Vtemp_16;
        __Vtemp_17 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x19U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x11U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x10U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x20U] 
            = __Vtemp_17;
        __Vtemp_18 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x1fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x12U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x11U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x21U] 
            = __Vtemp_18;
        __Vtemp_19 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x20U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x13U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x12U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x22U] 
            = __Vtemp_19;
        __Vtemp_20 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x21U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x14U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x13U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x23U] 
            = __Vtemp_20;
        __Vtemp_21 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x22U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x15U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x14U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x24U] 
            = __Vtemp_21;
        __Vtemp_22 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x23U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x16U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x15U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x25U] 
            = __Vtemp_22;
        __Vtemp_23 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x24U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x1fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x17U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x16U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x26U] 
            = __Vtemp_23;
        __Vtemp_24 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x25U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x20U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x18U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x17U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x27U] 
            = __Vtemp_24;
        __Vtemp_25 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x26U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x21U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x19U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x18U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x28U] 
            = __Vtemp_25;
        __Vtemp_26 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x27U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x22U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x19U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x29U] 
            = __Vtemp_26;
        __Vtemp_27 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x28U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x23U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2aU] 
            = __Vtemp_27;
        __Vtemp_28 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x29U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x24U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2bU] 
            = __Vtemp_28;
        __Vtemp_29 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x25U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2cU] 
            = __Vtemp_29;
        __Vtemp_30 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x26U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2dU] 
            = __Vtemp_30;
        __Vtemp_31 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x27U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x1fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2eU] 
            = __Vtemp_31;
        __Vtemp_32 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x28U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x20U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x1fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x2fU] 
            = __Vtemp_32;
        __Vtemp_33 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x29U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x21U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x20U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x30U] 
            = __Vtemp_33;
        __Vtemp_34 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x2fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x22U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x21U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x31U] 
            = __Vtemp_34;
        __Vtemp_35 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x30U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x23U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x22U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x32U] 
            = __Vtemp_35;
        __Vtemp_36 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x31U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x24U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x23U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x33U] 
            = __Vtemp_36;
        __Vtemp_37 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x32U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x25U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x24U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x34U] 
            = __Vtemp_37;
        __Vtemp_38 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x33U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x26U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x25U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x35U] 
            = __Vtemp_38;
        __Vtemp_39 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x34U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x2fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x27U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x26U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x36U] 
            = __Vtemp_39;
        __Vtemp_40 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x35U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x30U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x28U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x27U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x37U] 
            = __Vtemp_40;
        __Vtemp_41 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x36U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x31U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x29U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x28U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x38U] 
            = __Vtemp_41;
        __Vtemp_42 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x37U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x32U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x29U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x39U] 
            = __Vtemp_42;
        __Vtemp_43 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x38U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x33U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3aU] 
            = __Vtemp_43;
        __Vtemp_44 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x39U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x34U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3bU] 
            = __Vtemp_44;
        __Vtemp_45 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x3aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x35U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3cU] 
            = __Vtemp_45;
        __Vtemp_46 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x3bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x36U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3dU] 
            = __Vtemp_46;
        __Vtemp_47 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x3cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x37U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x2fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3eU] 
            = __Vtemp_47;
        __Vtemp_48 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                                [0x3dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                        [0x38U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                            [0x30U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next
                      [0x2fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0x3fU] 
            = __Vtemp_48;
    }
    __Vtableidx7 = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round) 
                      << 6U) | ((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__keys_packed) 
                                << 5U)) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal) 
                                            << 4U) 
                                           | (((IData)(vlSelfRef.tb_crypto_ops__DOT__aes_start) 
                                               << 3U) 
                                              | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h874e84c6_0
        [__Vtableidx7];
    __Vtableidx5 = (((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__is_final_block) 
                       << 7U) | ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state)) 
                                 << 6U)) | (((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state)) 
                                             << 5U) 
                                            | ((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal) 
                                               << 4U))) 
                    | (((IData)(vlSelfRef.tb_crypto_ops__DOT__hmac_start) 
                        << 3U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_hd1ef4c23_0
        [__Vtableidx5];
    __Vtableidx1 = (((IData)(vlSelfRef.tb_crypto_ops__DOT__zeroize_all) 
                     << 6U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__enrolled) 
                                << 5U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__enroll_mode_latched) 
                                           << 4U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_enroll_internal 
        = Vtb_crypto_ops__ConstPool__TABLE_h65830f14_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_regenerate_internal 
        = Vtb_crypto_ops__ConstPool__TABLE_h67c3227c_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_enroll_internal 
        = Vtb_crypto_ops__ConstPool__TABLE_h71bbe140_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_derive 
        = Vtb_crypto_ops__ConstPool__TABLE_h2a418c91_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_enable 
        = Vtb_crypto_ops__ConstPool__TABLE_hfaddc2ce_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize 
        = Vtb_crypto_ops__ConstPool__TABLE_ha0144a61_0
        [__Vtableidx1];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[0U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[1U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[2U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[3U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[4U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[5U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[6U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context[7U] 
        = Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0
        [__Vtableidx1][7U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state;
    if ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_enroll_internal) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 1U;
        } else if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_regenerate_internal) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 3U;
        }
    } else if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        if (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__cycle_count) 
             >= (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__measure_cycles))) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 2U;
        }
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 5U;
    } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        if (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__cycle_count) 
             >= (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__measure_cycles))) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 4U;
        }
    } else if ((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 5U;
    } else if ((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = 0U;
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state;
    if ((2U & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state 
            = ((1U & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))
                ? 0U : 3U);
    } else if ((1U & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))) {
        if ((0x20U <= (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__measure_count))) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state = 3U;
        }
    } else if ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_enroll_internal) 
                 | (IData)(vlSelfRef.tb_crypto_ops__DOT__puf_devid_enroll)) 
                & (~ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__enrolled)))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state = 1U;
    } else if (((IData)(vlSelfRef.tb_crypto_ops__DOT__puf_devid_read) 
                & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__enrolled))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state = 2U;
    }
}

extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0;

VL_INLINE_OPT void Vtb_crypto_ops___024root___nba_sequent__TOP__3(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___nba_sequent__TOP__3\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_crypto_ops__DOT__reset) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state = 0U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state = 0U;
    } else {
        if ((0U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
            if ((1U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
                if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[0U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[1U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[2U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[3U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[4U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[5U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[6U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[7U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[0U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[1U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[2U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[3U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[4U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[5U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[6U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[7U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[0U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[1U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[2U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[3U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[4U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[5U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[6U];
                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U] 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[7U];
                } else if ((3U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
                    if ((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U] 
                            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
                    }
                }
            }
        }
        if ((1U & (~ ((((((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)) 
                            | (1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                           | (2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                          | (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                         | (4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                        | (5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                       | (6U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                      | (7U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)))))) {
            if ((8U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                if ((9U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                    if (((9U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)) 
                         & (0xaU == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state)))) {
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[0U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[0U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[1U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[1U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[2U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[2U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[3U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[3U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[4U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[4U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[5U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[5U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[6U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[6U];
                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[7U] 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[7U];
                    }
                }
            }
        }
        if (((((((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)) 
                   | (1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                  | (2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                 | (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
                | (4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
               | (5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
              | (6U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) 
             | (7U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)))) {
            if ((0U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                if ((1U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                    if ((2U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                        if ((3U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                            if ((4U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                                if ((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                                    if (((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)) 
                                         & (6U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state)))) {
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[0U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[0U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[1U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[1U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[2U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[2U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[3U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[3U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[4U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[4U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[5U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[5U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[6U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[6U];
                                        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[7U] 
                                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[7U];
                                    }
                                }
                                if ((5U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                                    if ((6U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                                        if (((7U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)) 
                                             & (8U 
                                                == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state)))) {
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[0U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[0U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[1U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[1U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[2U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[2U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[3U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[3U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[4U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[4U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[5U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[5U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[6U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[6U];
                                            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[7U] 
                                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[7U];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state;
    }
    if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[4U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[5U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[6U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[7U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[4U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[5U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[6U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[7U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U];
    } else {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[0U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[1U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[2U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[3U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[4U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[5U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[6U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal[7U] 
            = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [7U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[1U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                    [5U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [6U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[2U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [5U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                      [6U]))) >> 0x20U));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[4U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                    [2U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [3U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[5U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [2U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                      [3U]))) >> 0x20U));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[6U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                    [0U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [1U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash[7U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                     [0U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
                                      [1U]))) >> 0x20U));
}

extern const VlUnpacked<CData/*3:0*/, 256> Vtb_crypto_ops__ConstPool__TABLE_h4e86509f_0;

VL_INLINE_OPT void Vtb_crypto_ops___024root___nba_comb__TOP__1(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___nba_comb__TOP__1\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state;
    if ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = 4U;
        } else if ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_enable) 
                     & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_keys_valid_latched)) 
                    & (~ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_locked)))) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state 
            = ((((0U != ((((((((Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U] 
                                ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[0U]) 
                               | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U] 
                                  ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[1U])) 
                              | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U] 
                                 ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[2U])) 
                             | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U] 
                                ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[3U])) 
                            | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U] 
                               ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[4U])) 
                           | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U] 
                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[5U])) 
                          | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U] 
                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[6U])) 
                         | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U] 
                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg[7U]))) 
                 & (0U != ((((((((Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U] 
                                  ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[0U]) 
                                 | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U] 
                                    ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[1U])) 
                                | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U] 
                                   ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[2U])) 
                               | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U] 
                                  ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[3U])) 
                              | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U] 
                                 ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[4U])) 
                             | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U] 
                                ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[5U])) 
                            | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U] 
                               ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[6U])) 
                           | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U] 
                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg[7U])))) 
                & (0U != ((((((((Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U] 
                                 ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[0U]) 
                                | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U] 
                                   ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[1U])) 
                               | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U] 
                                  ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[2U])) 
                              | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U] 
                                 ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[3U])) 
                             | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U] 
                                ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[4U])) 
                            | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U] 
                               ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[5U])) 
                           | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U] 
                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[6U])) 
                          | (Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U] 
                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg[7U]))))
                ? 2U : 0U);
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = 3U;
    } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = 4U;
        }
    } else if ((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = 0U;
    }
    __Vtableidx2 = ((((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state)) 
                      << 7U) | ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state)) 
                                << 6U)) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__dus_valid_latched) 
                                            << 5U) 
                                           | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_derive) 
                                               << 4U) 
                                              | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h4e86509f_0
        [__Vtableidx2];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state;
    if (((((((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state)) 
               | (1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
              | (2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
             | (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
            | (4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
           | (5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
          | (6U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) 
         | (7U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state)))) {
        if ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if (vlSelfRef.tb_crypto_ops__DOT__zeroize_all) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 8U;
            } else if (vlSelfRef.tb_crypto_ops__DOT__system_init) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 1U;
            } else if (((IData)(vlSelfRef.tb_crypto_ops__DOT__derive_new_keys) 
                        & (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state)))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 4U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if (((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state)) 
                 & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__dus_valid_latched))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 2U;
            } else if (((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state)) 
                        & (0x20U < (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count)))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 8U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 3U;
            }
        } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if ((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 4U;
            }
        } else if ((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 5U;
            }
        } else if ((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if ((IData)((0xaU == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state)))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 6U;
            }
        } else if ((6U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))) {
            if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
                vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 7U;
            }
        } else if (vlSelfRef.tb_crypto_ops__DOT__zeroize_all) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 8U;
        } else if (vlSelfRef.tb_crypto_ops__DOT__derive_new_keys) {
            vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state = 4U;
        }
    }
}

void Vtb_crypto_ops___024root___timing_resume(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___timing_resume\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h9a0751a7__0.resume(
                                                   "@(posedge tb_crypto_ops.clock)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_crypto_ops___024root___timing_commit(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___timing_commit\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h9a0751a7__0.commit(
                                                   "@(posedge tb_crypto_ops.clock)");
    }
}

void Vtb_crypto_ops___024root___eval_triggers__act(Vtb_crypto_ops___024root* vlSelf);
void Vtb_crypto_ops___024root___eval_act(Vtb_crypto_ops___024root* vlSelf);

bool Vtb_crypto_ops___024root___eval_phase__act(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_phase__act\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_crypto_ops___024root___eval_triggers__act(vlSelf);
    Vtb_crypto_ops___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_crypto_ops___024root___timing_resume(vlSelf);
        Vtb_crypto_ops___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_crypto_ops___024root___eval_nba(Vtb_crypto_ops___024root* vlSelf);

bool Vtb_crypto_ops___024root___eval_phase__nba(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_phase__nba\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_crypto_ops___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__nba(Vtb_crypto_ops___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__act(Vtb_crypto_ops___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_crypto_ops___024root___eval(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state;
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U];
    vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U];
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_crypto_ops___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_crypto_ops.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_crypto_ops___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_crypto_ops.sv", 5, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_crypto_ops___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_crypto_ops___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_crypto_ops___024root___eval_debug_assertions(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_debug_assertions\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
