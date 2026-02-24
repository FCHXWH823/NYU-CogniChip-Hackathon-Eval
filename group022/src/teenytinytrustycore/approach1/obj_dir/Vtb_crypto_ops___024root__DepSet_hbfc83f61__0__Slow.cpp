// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_crypto_ops.h for the primary calling header

#include "Vtb_crypto_ops__pch.h"
#include "Vtb_crypto_ops___024root.h"

VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_static(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_static\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__clock__0 
        = vlSelfRef.tb_crypto_ops__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__reset__0 
        = vlSelfRef.tb_crypto_ops__DOT__reset;
}

VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_final(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_final\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__stl(Vtb_crypto_ops___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_crypto_ops___024root___eval_phase__stl(Vtb_crypto_ops___024root* vlSelf);

VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_settle(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_settle\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_crypto_ops___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_crypto_ops.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_crypto_ops___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__stl(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___dump_triggers__stl\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_crypto_ops___024root___stl_sequent__TOP__0(Vtb_crypto_ops___024root* vlSelf);
VL_ATTR_COLD void Vtb_crypto_ops___024root____Vm_traceActivitySetAll(Vtb_crypto_ops___024root* vlSelf);
VL_ATTR_COLD void Vtb_crypto_ops___024root___stl_sequent__TOP__1(Vtb_crypto_ops___024root* vlSelf);

VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_stl(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_stl\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_crypto_ops___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_crypto_ops___024root____Vm_traceActivitySetAll(vlSelf);
        Vtb_crypto_ops___024root___stl_sequent__TOP__1(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 512> Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0;

VL_ATTR_COLD void Vtb_crypto_ops___024root___stl_sequent__TOP__0(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___stl_sequent__TOP__0\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    SData/*8:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    SData/*8:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
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
    IData/*31:0*/ __Vtemp_49;
    IData/*31:0*/ __Vtemp_50;
    IData/*31:0*/ __Vtemp_51;
    IData/*31:0*/ __Vtemp_52;
    IData/*31:0*/ __Vtemp_53;
    IData/*31:0*/ __Vtemp_54;
    IData/*31:0*/ __Vtemp_55;
    IData/*31:0*/ __Vtemp_56;
    IData/*31:0*/ __Vtemp_57;
    IData/*31:0*/ __Vtemp_58;
    IData/*31:0*/ __Vtemp_59;
    IData/*31:0*/ __Vtemp_60;
    IData/*31:0*/ __Vtemp_61;
    IData/*31:0*/ __Vtemp_62;
    IData/*31:0*/ __Vtemp_63;
    IData/*31:0*/ __Vtemp_64;
    IData/*31:0*/ __Vtemp_65;
    IData/*31:0*/ __Vtemp_66;
    IData/*31:0*/ __Vtemp_67;
    IData/*31:0*/ __Vtemp_68;
    IData/*31:0*/ __Vtemp_69;
    IData/*31:0*/ __Vtemp_70;
    IData/*31:0*/ __Vtemp_71;
    IData/*31:0*/ __Vtemp_72;
    IData/*31:0*/ __Vtemp_73;
    IData/*31:0*/ __Vtemp_74;
    IData/*31:0*/ __Vtemp_75;
    IData/*31:0*/ __Vtemp_76;
    IData/*31:0*/ __Vtemp_77;
    IData/*31:0*/ __Vtemp_78;
    IData/*31:0*/ __Vtemp_79;
    IData/*31:0*/ __Vtemp_80;
    IData/*31:0*/ __Vtemp_81;
    IData/*31:0*/ __Vtemp_82;
    IData/*31:0*/ __Vtemp_83;
    IData/*31:0*/ __Vtemp_84;
    IData/*31:0*/ __Vtemp_85;
    IData/*31:0*/ __Vtemp_86;
    IData/*31:0*/ __Vtemp_87;
    IData/*31:0*/ __Vtemp_88;
    IData/*31:0*/ __Vtemp_89;
    IData/*31:0*/ __Vtemp_90;
    IData/*31:0*/ __Vtemp_91;
    IData/*31:0*/ __Vtemp_92;
    IData/*31:0*/ __Vtemp_93;
    IData/*31:0*/ __Vtemp_94;
    IData/*31:0*/ __Vtemp_95;
    IData/*31:0*/ __Vtemp_96;
    IData/*31:0*/ __Vtemp_97;
    IData/*31:0*/ __Vtemp_98;
    IData/*31:0*/ __Vtemp_99;
    IData/*31:0*/ __Vtemp_100;
    IData/*31:0*/ __Vtemp_101;
    IData/*31:0*/ __Vtemp_102;
    IData/*31:0*/ __Vtemp_103;
    IData/*31:0*/ __Vtemp_104;
    IData/*31:0*/ __Vtemp_105;
    IData/*31:0*/ __Vtemp_106;
    IData/*31:0*/ __Vtemp_107;
    IData/*31:0*/ __Vtemp_108;
    IData/*31:0*/ __Vtemp_109;
    IData/*31:0*/ __Vtemp_110;
    IData/*31:0*/ __Vtemp_111;
    IData/*31:0*/ __Vtemp_112;
    IData/*31:0*/ __Vtemp_113;
    IData/*31:0*/ __Vtemp_114;
    IData/*31:0*/ __Vtemp_115;
    IData/*31:0*/ __Vtemp_116;
    IData/*31:0*/ __Vtemp_117;
    IData/*31:0*/ __Vtemp_118;
    IData/*31:0*/ __Vtemp_119;
    IData/*31:0*/ __Vtemp_120;
    IData/*31:0*/ __Vtemp_121;
    IData/*31:0*/ __Vtemp_122;
    IData/*31:0*/ __Vtemp_123;
    IData/*31:0*/ __Vtemp_124;
    IData/*31:0*/ __Vtemp_125;
    IData/*31:0*/ __Vtemp_126;
    IData/*31:0*/ __Vtemp_127;
    IData/*31:0*/ __Vtemp_128;
    IData/*31:0*/ __Vtemp_129;
    IData/*31:0*/ __Vtemp_130;
    IData/*31:0*/ __Vtemp_131;
    IData/*31:0*/ __Vtemp_132;
    IData/*31:0*/ __Vtemp_133;
    IData/*31:0*/ __Vtemp_134;
    IData/*31:0*/ __Vtemp_135;
    IData/*31:0*/ __Vtemp_136;
    IData/*31:0*/ __Vtemp_137;
    IData/*31:0*/ __Vtemp_138;
    IData/*31:0*/ __Vtemp_139;
    IData/*31:0*/ __Vtemp_140;
    IData/*31:0*/ __Vtemp_141;
    IData/*31:0*/ __Vtemp_142;
    IData/*31:0*/ __Vtemp_143;
    IData/*31:0*/ __Vtemp_144;
    IData/*31:0*/ __Vtemp_145;
    IData/*31:0*/ __Vtemp_146;
    IData/*31:0*/ __Vtemp_147;
    IData/*31:0*/ __Vtemp_148;
    // Body
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
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [7U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[1U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                    [5U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [6U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[2U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [5U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                      [6U]))) >> 0x20U));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[4U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                    [2U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [3U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[5U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [2U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                      [3U]))) >> 0x20U));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[6U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                    [0U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [1U]))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash[7U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                     [0U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
                                      [1U]))) >> 0x20U));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[3U] 
        = ((0xffffU & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[3U]) 
           | (0xffff0000U & ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [0U][0U] << 0x18U) | 
                             (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [0U][1U] << 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[3U] 
        = ((0xffff0000U & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[3U]) 
           | ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
               [0U][2U] << 8U) | vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
              [0U][3U]));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[2U] 
        = ((0xffffU & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[2U]) 
           | (0xffff0000U & ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [1U][0U] << 0x18U) | 
                             (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [1U][1U] << 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[2U] 
        = ((0xffff0000U & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[2U]) 
           | ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
               [1U][2U] << 8U) | vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
              [1U][3U]));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[1U] 
        = ((0xffffU & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[1U]) 
           | (0xffff0000U & ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [2U][0U] << 0x18U) | 
                             (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [2U][1U] << 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[1U] 
        = ((0xffff0000U & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[1U]) 
           | ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
               [2U][2U] << 8U) | vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
              [2U][3U]));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[0U] 
        = ((0xffffU & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[0U]) 
           | (0xffff0000U & ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [3U][0U] << 0x18U) | 
                             (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                              [3U][1U] << 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[0U] 
        = ((0xffff0000U & vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output[0U]) 
           | ((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
               [3U][2U] << 8U) | vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
              [3U][3U]));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round_next 
        = ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))
            ? (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round)))
            : 0U);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round_next 
        = ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))
            ? (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round)))
            : 0U);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round_next 
        = ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))
            ? (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round)))
            : 0U);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f;
    __Vtableidx3 = (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_start) 
                     << 8U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round) 
                                << 2U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0
        [__Vtableidx3];
    __Vtableidx4 = (((IData)(vlSelfRef.tb_crypto_ops__DOT__sha_start) 
                     << 8U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round) 
                                << 2U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0
        [__Vtableidx4];
    __Vtableidx6 = (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_start) 
                     << 8U) | (((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round) 
                                << 2U) | (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__next_state 
        = Vtb_crypto_ops__ConstPool__TABLE_h734d4242_0
        [__Vtableidx6];
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
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
        [7U];
    if ((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state)) 
          & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_start)) 
         & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_init))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 8U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[0U] = 0x6a09e667U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[1U] = 0xbb67ae85U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[2U] = 0x3c6ef372U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[3U] = 0xa54ff53aU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[4U] = 0x510e527fU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[5U] = 0x9b05688cU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[6U] = 0x1f83d9abU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[7U] = 0x5be0cd19U;
    } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[0U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [0U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[1U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [1U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[2U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [2U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[3U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [3U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[4U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [4U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[5U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [5U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[6U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [6U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[7U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
               [7U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h);
    }
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
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[4U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[5U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[6U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[7U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
        [7U];
    if ((((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state)) 
          & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_start)) 
         & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_init))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 8U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[0U] = 0x6a09e667U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[1U] = 0xbb67ae85U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[2U] = 0x3c6ef372U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[3U] = 0xa54ff53aU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[4U] = 0x510e527fU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[5U] = 0x9b05688cU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[6U] = 0x1f83d9abU;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[7U] = 0x5be0cd19U;
    } else if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[0U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [0U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[1U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [1U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[2U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [2U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[3U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [3U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[4U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [4U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[5U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [5U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[6U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [6U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[7U] 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
               [7U] + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h);
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal 
        = ((~ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_fail)) 
           & (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_valid_reg));
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[__Vilp1] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [5U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e;
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [5U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e;
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H
            [5U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e;
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xfU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0x10U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0x40U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xeU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xdU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xcU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[4U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xbU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[5U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0xaU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[6U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[9U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[7U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[8U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[8U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[9U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xaU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xbU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xcU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xdU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xeU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0xfU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message[0U];
        __Vtemp_5 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0xeU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                       [9U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [1U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                     [0U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x10U] 
            = __Vtemp_5;
        __Vtemp_6 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0xfU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                       [0xaU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [2U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                     [1U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x11U] 
            = __Vtemp_6;
        __Vtemp_7 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x10U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                       [0xbU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [3U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                     [2U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x12U] 
            = __Vtemp_7;
        __Vtemp_8 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x11U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                       [0xcU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [4U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                     [3U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x13U] 
            = __Vtemp_8;
        __Vtemp_9 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x12U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                       [0xdU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [5U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                     + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                     [4U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x14U] 
            = __Vtemp_9;
        __Vtemp_10 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x13U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0xeU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [6U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [5U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x15U] 
            = __Vtemp_10;
        __Vtemp_11 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x14U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0xfU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [7U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [6U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x16U] 
            = __Vtemp_11;
        __Vtemp_12 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x15U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x10U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [8U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [7U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x17U] 
            = __Vtemp_12;
        __Vtemp_13 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x16U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x11U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [9U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [8U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x18U] 
            = __Vtemp_13;
        __Vtemp_14 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x17U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x12U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xaU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [9U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x19U] 
            = __Vtemp_14;
        __Vtemp_15 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x18U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x13U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xbU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xaU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1aU] 
            = __Vtemp_15;
        __Vtemp_16 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x19U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x14U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xcU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xbU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1bU] 
            = __Vtemp_16;
        __Vtemp_17 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x15U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xdU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xcU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1cU] 
            = __Vtemp_17;
        __Vtemp_18 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x16U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xeU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xdU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1dU] 
            = __Vtemp_18;
        __Vtemp_19 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x17U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0xfU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xeU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1eU] 
            = __Vtemp_19;
        __Vtemp_20 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x18U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x10U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0xfU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x1fU] 
            = __Vtemp_20;
        __Vtemp_21 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x19U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x11U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x10U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x20U] 
            = __Vtemp_21;
        __Vtemp_22 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x1fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x12U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x11U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x21U] 
            = __Vtemp_22;
        __Vtemp_23 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x20U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x13U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x12U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x22U] 
            = __Vtemp_23;
        __Vtemp_24 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x21U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x14U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x13U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x23U] 
            = __Vtemp_24;
        __Vtemp_25 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x22U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x15U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x14U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x24U] 
            = __Vtemp_25;
        __Vtemp_26 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x23U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x16U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x15U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x25U] 
            = __Vtemp_26;
        __Vtemp_27 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x24U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x1fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x17U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x16U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x26U] 
            = __Vtemp_27;
        __Vtemp_28 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x25U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x20U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x18U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x17U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x27U] 
            = __Vtemp_28;
        __Vtemp_29 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x26U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x21U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x19U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x18U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x28U] 
            = __Vtemp_29;
        __Vtemp_30 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x27U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x22U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x19U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x29U] 
            = __Vtemp_30;
        __Vtemp_31 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x28U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x23U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2aU] 
            = __Vtemp_31;
        __Vtemp_32 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x29U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x24U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2bU] 
            = __Vtemp_32;
        __Vtemp_33 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x25U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2cU] 
            = __Vtemp_33;
        __Vtemp_34 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x26U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2dU] 
            = __Vtemp_34;
        __Vtemp_35 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x27U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x1fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2eU] 
            = __Vtemp_35;
        __Vtemp_36 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x28U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x20U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x1fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x2fU] 
            = __Vtemp_36;
        __Vtemp_37 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x29U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x21U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x20U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x30U] 
            = __Vtemp_37;
        __Vtemp_38 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x2fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x22U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x21U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x31U] 
            = __Vtemp_38;
        __Vtemp_39 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x30U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x23U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x22U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x32U] 
            = __Vtemp_39;
        __Vtemp_40 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x31U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x24U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x23U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x33U] 
            = __Vtemp_40;
        __Vtemp_41 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x32U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x25U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x24U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x34U] 
            = __Vtemp_41;
        __Vtemp_42 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x33U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x26U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x25U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x35U] 
            = __Vtemp_42;
        __Vtemp_43 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x34U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x2fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x27U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x26U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x36U] 
            = __Vtemp_43;
        __Vtemp_44 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x35U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x30U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x28U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x27U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x37U] 
            = __Vtemp_44;
        __Vtemp_45 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x36U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x31U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x29U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x28U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x38U] 
            = __Vtemp_45;
        __Vtemp_46 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x37U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x32U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x29U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x39U] 
            = __Vtemp_46;
        __Vtemp_47 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x38U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x33U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3aU] 
            = __Vtemp_47;
        __Vtemp_48 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x39U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x34U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3bU] 
            = __Vtemp_48;
        __Vtemp_49 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x3aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x35U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3cU] 
            = __Vtemp_49;
        __Vtemp_50 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x3bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x36U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3dU] 
            = __Vtemp_50;
        __Vtemp_51 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x3cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x37U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x2fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3eU] 
            = __Vtemp_51;
        __Vtemp_52 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                                [0x3dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout) 
                        + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                        [0x38U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                            [0x30U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout)) 
                      + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next
                      [0x2fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0x3fU] 
            = __Vtemp_52;
    }
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[__Vilp2] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
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
        __Vtemp_53 = (((([&]() {
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
            = __Vtemp_53;
        __Vtemp_54 = (((([&]() {
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
            = __Vtemp_54;
        __Vtemp_55 = (((([&]() {
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
            = __Vtemp_55;
        __Vtemp_56 = (((([&]() {
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
            = __Vtemp_56;
        __Vtemp_57 = (((([&]() {
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
            = __Vtemp_57;
        __Vtemp_58 = (((([&]() {
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
            = __Vtemp_58;
        __Vtemp_59 = (((([&]() {
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
            = __Vtemp_59;
        __Vtemp_60 = (((([&]() {
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
            = __Vtemp_60;
        __Vtemp_61 = (((([&]() {
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
            = __Vtemp_61;
        __Vtemp_62 = (((([&]() {
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
            = __Vtemp_62;
        __Vtemp_63 = (((([&]() {
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
            = __Vtemp_63;
        __Vtemp_64 = (((([&]() {
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
            = __Vtemp_64;
        __Vtemp_65 = (((([&]() {
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
            = __Vtemp_65;
        __Vtemp_66 = (((([&]() {
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
            = __Vtemp_66;
        __Vtemp_67 = (((([&]() {
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
            = __Vtemp_67;
        __Vtemp_68 = (((([&]() {
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
            = __Vtemp_68;
        __Vtemp_69 = (((([&]() {
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
            = __Vtemp_69;
        __Vtemp_70 = (((([&]() {
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
            = __Vtemp_70;
        __Vtemp_71 = (((([&]() {
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
            = __Vtemp_71;
        __Vtemp_72 = (((([&]() {
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
            = __Vtemp_72;
        __Vtemp_73 = (((([&]() {
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
            = __Vtemp_73;
        __Vtemp_74 = (((([&]() {
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
            = __Vtemp_74;
        __Vtemp_75 = (((([&]() {
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
            = __Vtemp_75;
        __Vtemp_76 = (((([&]() {
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
            = __Vtemp_76;
        __Vtemp_77 = (((([&]() {
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
            = __Vtemp_77;
        __Vtemp_78 = (((([&]() {
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
            = __Vtemp_78;
        __Vtemp_79 = (((([&]() {
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
            = __Vtemp_79;
        __Vtemp_80 = (((([&]() {
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
            = __Vtemp_80;
        __Vtemp_81 = (((([&]() {
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
            = __Vtemp_81;
        __Vtemp_82 = (((([&]() {
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
            = __Vtemp_82;
        __Vtemp_83 = (((([&]() {
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
            = __Vtemp_83;
        __Vtemp_84 = (((([&]() {
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
            = __Vtemp_84;
        __Vtemp_85 = (((([&]() {
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
            = __Vtemp_85;
        __Vtemp_86 = (((([&]() {
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
            = __Vtemp_86;
        __Vtemp_87 = (((([&]() {
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
            = __Vtemp_87;
        __Vtemp_88 = (((([&]() {
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
            = __Vtemp_88;
        __Vtemp_89 = (((([&]() {
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
            = __Vtemp_89;
        __Vtemp_90 = (((([&]() {
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
            = __Vtemp_90;
        __Vtemp_91 = (((([&]() {
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
            = __Vtemp_91;
        __Vtemp_92 = (((([&]() {
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
            = __Vtemp_92;
        __Vtemp_93 = (((([&]() {
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
            = __Vtemp_93;
        __Vtemp_94 = (((([&]() {
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
            = __Vtemp_94;
        __Vtemp_95 = (((([&]() {
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
            = __Vtemp_95;
        __Vtemp_96 = (((([&]() {
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
            = __Vtemp_96;
        __Vtemp_97 = (((([&]() {
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
            = __Vtemp_97;
        __Vtemp_98 = (((([&]() {
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
            = __Vtemp_98;
        __Vtemp_99 = (((([&]() {
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
            = __Vtemp_99;
        __Vtemp_100 = (((([&]() {
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
            = __Vtemp_100;
    }
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[__Vilp3] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W
            [__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xfU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0x10U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0x40U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xeU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xdU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xcU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[4U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xbU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[5U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0xaU];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[6U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[9U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[7U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[8U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[8U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[7U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[9U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[6U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xaU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[5U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xbU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[4U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xcU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xdU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xeU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0xfU] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message[0U];
        __Vtemp_101 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0xeU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [9U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [1U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x10U] 
            = __Vtemp_101;
        __Vtemp_102 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0xfU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xaU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [2U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [1U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x11U] 
            = __Vtemp_102;
        __Vtemp_103 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x10U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xbU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [3U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [2U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x12U] 
            = __Vtemp_103;
        __Vtemp_104 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x11U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xcU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [4U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [3U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x13U] 
            = __Vtemp_104;
        __Vtemp_105 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x12U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xdU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [5U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [4U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x14U] 
            = __Vtemp_105;
        __Vtemp_106 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x13U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xeU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [6U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [5U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x15U] 
            = __Vtemp_106;
        __Vtemp_107 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x14U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0xfU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [7U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [6U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x16U] 
            = __Vtemp_107;
        __Vtemp_108 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x15U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x10U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [8U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [7U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x17U] 
            = __Vtemp_108;
        __Vtemp_109 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x16U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x11U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [9U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [8U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x18U] 
            = __Vtemp_109;
        __Vtemp_110 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x17U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x12U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xaU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [9U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x19U] 
            = __Vtemp_110;
        __Vtemp_111 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x18U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x13U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xbU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xaU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1aU] 
            = __Vtemp_111;
        __Vtemp_112 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x19U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x14U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xcU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xbU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1bU] 
            = __Vtemp_112;
        __Vtemp_113 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x15U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xdU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xcU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1cU] 
            = __Vtemp_113;
        __Vtemp_114 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x16U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xeU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xdU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1dU] 
            = __Vtemp_114;
        __Vtemp_115 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x17U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0xfU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xeU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1eU] 
            = __Vtemp_115;
        __Vtemp_116 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x18U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x10U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0xfU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x1fU] 
            = __Vtemp_116;
        __Vtemp_117 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x19U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x11U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x10U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x20U] 
            = __Vtemp_117;
        __Vtemp_118 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x1fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x12U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x11U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x21U] 
            = __Vtemp_118;
        __Vtemp_119 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x20U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x13U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x12U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x22U] 
            = __Vtemp_119;
        __Vtemp_120 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x21U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x14U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x13U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x23U] 
            = __Vtemp_120;
        __Vtemp_121 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x22U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x15U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x14U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x24U] 
            = __Vtemp_121;
        __Vtemp_122 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x23U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x16U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x15U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x25U] 
            = __Vtemp_122;
        __Vtemp_123 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x24U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x1fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x17U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x16U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x26U] 
            = __Vtemp_123;
        __Vtemp_124 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x25U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x20U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x18U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x17U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x27U] 
            = __Vtemp_124;
        __Vtemp_125 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x26U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x21U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x19U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x18U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x28U] 
            = __Vtemp_125;
        __Vtemp_126 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x27U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x22U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x19U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x29U] 
            = __Vtemp_126;
        __Vtemp_127 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x28U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x23U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2aU] 
            = __Vtemp_127;
        __Vtemp_128 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x29U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x24U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2bU] 
            = __Vtemp_128;
        __Vtemp_129 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x25U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2cU] 
            = __Vtemp_129;
        __Vtemp_130 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x26U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2dU] 
            = __Vtemp_130;
        __Vtemp_131 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x27U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x1fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2eU] 
            = __Vtemp_131;
        __Vtemp_132 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x28U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x20U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x1fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x2fU] 
            = __Vtemp_132;
        __Vtemp_133 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2eU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x29U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x21U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x20U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x30U] 
            = __Vtemp_133;
        __Vtemp_134 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x2fU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2aU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x22U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x21U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x31U] 
            = __Vtemp_134;
        __Vtemp_135 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x30U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2bU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x23U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x22U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x32U] 
            = __Vtemp_135;
        __Vtemp_136 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x31U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2cU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x24U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x23U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x33U] 
            = __Vtemp_136;
        __Vtemp_137 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x32U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2dU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x25U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x24U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x34U] 
            = __Vtemp_137;
        __Vtemp_138 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x33U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2eU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x26U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x25U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x35U] 
            = __Vtemp_138;
        __Vtemp_139 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x34U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x2fU]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x27U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x26U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x36U] 
            = __Vtemp_139;
        __Vtemp_140 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x35U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x30U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x28U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x27U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x37U] 
            = __Vtemp_140;
        __Vtemp_141 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x36U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x31U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x29U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x28U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x38U] 
            = __Vtemp_141;
        __Vtemp_142 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x37U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x32U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2aU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x29U]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x39U] 
            = __Vtemp_142;
        __Vtemp_143 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x38U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x33U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2bU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2aU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3aU] 
            = __Vtemp_143;
        __Vtemp_144 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x39U];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x34U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2cU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2bU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3bU] 
            = __Vtemp_144;
        __Vtemp_145 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x3aU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x35U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2dU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2cU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3cU] 
            = __Vtemp_145;
        __Vtemp_146 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x3bU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x36U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2eU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2dU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3dU] 
            = __Vtemp_146;
        __Vtemp_147 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x3cU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x37U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x2fU];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2eU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3eU] 
            = __Vtemp_147;
        __Vtemp_148 = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                                [0x3dU];
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0x11U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x, 0xfU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0x13U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x, 0xdU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout)) 
                                   ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout) 
                         + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                         [0x38U]) + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                            [0x30U];
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout 
                            = ((([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 7U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x, 0x19U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout) 
                                ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0x12U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x, 0xeU));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x, 3U));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout)) 
                       + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next
                       [0x2fU]);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0x3fU] 
            = __Vtemp_148;
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T1 
        = ((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h 
              + ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__x, 6U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__x, 0x1aU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__x, 0xbU) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__x, 0x15U));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__Vfuncout)) 
                                   ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__x, 0x19U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__x, 7U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__Vfuncout));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__Vfuncout)) 
             + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__z 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__y 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__Vfuncout 
                            = ((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__x 
                                & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__y) 
                               ^ ((~ vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__x) 
                                  & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__z));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__Vfuncout)) 
            + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K
            [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round]) 
           + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W
           [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round]);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T2 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__Vfuncout 
                    = ((([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__x, 2U) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__x, 0x1eU));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__Vfuncout) 
                        ^ ([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__x, 0xdU) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__x, 0x13U));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__Vfuncout)) 
                       ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__x 
                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__x;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__Vfuncout 
                                = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__x, 0x16U) 
                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__Vfuncout));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__Vfuncout) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__z 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__y 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__Vfuncout 
                    = (((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__x 
                         & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__y) 
                        ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__x 
                           & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__z)) 
                       ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__y 
                          & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__z));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__Vfuncout));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e;
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H
            [4U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T1);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T1 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T2);
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T1 
        = ((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h 
              + ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__x 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__Vfuncout 
                                = ((([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__x, 6U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__x, 0x1aU));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__x 
                                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__x;
                                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__x, 0xbU) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__x, 0x15U));
                                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__Vfuncout)) 
                                   ^ ([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__x 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__x;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__x, 0x19U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__x, 7U));
                                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__Vfuncout));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__Vfuncout)) 
             + ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__z 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__y 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__x 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__Vfuncout 
                            = ((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__x 
                                & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__y) 
                               ^ ((~ vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__x) 
                                  & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__z));
                    }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__Vfuncout)) 
            + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K
            [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round]) 
           + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W
           [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round]);
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T2 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__Vfuncout 
                    = ((([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__x, 2U) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__x, 0x1eU));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__Vfuncout) 
                        ^ ([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__x 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__x;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__x, 0xdU) 
                                       | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__x, 0x13U));
                            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__Vfuncout)) 
                       ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__x 
                                = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__x;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__Vfuncout 
                                = (VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__x, 0x16U) 
                                   | VL_SHIFTL_III(32,32,32, vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__x, 0xaU));
                        }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__Vfuncout));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__Vfuncout) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__z 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__y 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__x 
                    = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a;
                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__Vfuncout 
                    = (((vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__x 
                         & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__y) 
                        ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__x 
                           & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__z)) 
                       ^ (vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__y 
                          & vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__z));
            }(), vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__Vfuncout));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e_next 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e;
    if ((1U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e_next 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [4U];
    } else if ((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T1);
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a_next 
            = (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T1 
               + vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T2);
    }
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
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[0U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [0U][0U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[0U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [0U][1U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[0U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [0U][2U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[0U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [0U][3U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[1U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [1U][0U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[1U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [1U][1U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[1U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [1U][2U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[1U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [1U][3U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[2U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [2U][0U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[2U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [2U][1U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[2U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [2U][2U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[2U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [2U][3U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[3U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [3U][0U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[3U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [3U][1U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[3U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [3U][2U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[3U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox
        [vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
        [3U][3U]];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[0U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [0U][0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[0U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [0U][1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[0U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [0U][2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[0U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [0U][3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[1U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [1U][1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[1U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [1U][2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[1U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [1U][3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[1U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [1U][0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[2U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [2U][2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[2U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [2U][3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[2U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [2U][0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[2U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [2U][1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[3U][0U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [3U][3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[3U][1U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [3U][0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[3U][2U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [3U][1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[3U][3U] 
        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
        [3U][2U];
    if ((0xdU > (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))) {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__j = 4U;
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][0U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout)) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout))) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][0U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout))) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout 
                            = (([&]() {
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a 
                                        = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a;
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout 
                                        = (0xffU & 
                                           ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U)));
                                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout)) 
                               ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout))) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][0U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout 
                            = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a))
                                         ? (0x1bU ^ 
                                            VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U))
                                         : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout))) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout 
                        = (([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout 
                                    = (0xffU & ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a))
                                                 ? 
                                                (0x1bU 
                                                 ^ 
                                                 VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U))
                                                 : 
                                                VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U)));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout)) 
                           ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][0U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout)) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout 
                        = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a))
                                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U))
                                     : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][1U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout)) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout))) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][1U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout))) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout 
                            = (([&]() {
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a 
                                        = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a;
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout 
                                        = (0xffU & 
                                           ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U)));
                                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout)) 
                               ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout))) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][1U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout 
                            = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a))
                                         ? (0x1bU ^ 
                                            VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U))
                                         : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout))) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout 
                        = (([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout 
                                    = (0xffU & ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a))
                                                 ? 
                                                (0x1bU 
                                                 ^ 
                                                 VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U))
                                                 : 
                                                VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U)));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout)) 
                           ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][1U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout)) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout 
                        = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a))
                                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U))
                                     : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][2U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout)) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout))) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][2U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout))) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout 
                            = (([&]() {
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a 
                                        = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a;
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout 
                                        = (0xffU & 
                                           ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U)));
                                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout)) 
                               ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout))) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][2U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout 
                            = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a))
                                         ? (0x1bU ^ 
                                            VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U))
                                         : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout))) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout 
                        = (([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout 
                                    = (0xffU & ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a))
                                                 ? 
                                                (0x1bU 
                                                 ^ 
                                                 VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U))
                                                 : 
                                                VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U)));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout)) 
                           ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][2U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout)) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout 
                        = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a))
                                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U))
                                     : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][3U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout)) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout))) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][3U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ ([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout 
                                = (0xffU & ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a), 1U)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout))) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout 
                            = (([&]() {
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a 
                                        = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a;
                                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout 
                                        = (0xffU & 
                                           ((0x80U 
                                             & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a))
                                             ? (0x1bU 
                                                ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U))
                                             : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a), 1U)));
                                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout)) 
                               ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout))) 
               ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][3U] 
            = ((((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ ([&]() {
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a 
                            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c;
                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout 
                            = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a))
                                         ? (0x1bU ^ 
                                            VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U))
                                         : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a), 1U)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout))) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout 
                        = (([&]() {
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a 
                                    = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a;
                                vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout 
                                    = (0xffU & ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a))
                                                 ? 
                                                (0x1bU 
                                                 ^ 
                                                 VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U))
                                                 : 
                                                VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a), 1U)));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout)) 
                           ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout)));
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][3U] 
            = (((([&]() {
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a 
                                = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a;
                            vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout 
                                = (([&]() {
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a 
                                            = vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a;
                                        vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout 
                                            = (0xffU 
                                               & ((0x80U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a))
                                                   ? 
                                                  (0x1bU 
                                                   ^ 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U))
                                                   : 
                                                  VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a), 1U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout)) 
                                   ^ (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout)) 
                 ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b)) 
                ^ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c)) 
               ^ ([&]() {
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a 
                        = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d;
                    vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout 
                        = (0xffU & ((0x80U & (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a))
                                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U))
                                     : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a), 1U)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout)));
    } else {
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[0U][3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [0U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[1U][3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [1U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[2U][3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [2U][3U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][0U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][0U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][1U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][1U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][2U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][2U];
        vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[3U][3U] 
            = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
            [3U][3U];
    }
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h65830f14_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h67c3227c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h71bbe140_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h2a418c91_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_hfaddc2ce_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_ha0144a61_0;
extern const VlUnpacked<VlWide<8>/*255:0*/, 128> Vtb_crypto_ops__ConstPool__TABLE_h8cd937f3_0;
extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_crypto_ops__ConstPool__TABLE_hd1ef4c23_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vtb_crypto_ops__ConstPool__TABLE_h874e84c6_0;
extern const VlUnpacked<CData/*3:0*/, 256> Vtb_crypto_ops__ConstPool__TABLE_h4e86509f_0;

VL_ATTR_COLD void Vtb_crypto_ops___024root___stl_sequent__TOP__1(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___stl_sequent__TOP__1\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    SData/*9:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    // Body
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[0U][0U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [0U][0U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                   : 0U) << 8U) | (
                                                   ((0xeU 
                                                     >= 
                                                     (0xfU 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                                     ? 
                                                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                                    [
                                                    (0xfU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                                     : 0U) 
                                                   >> 0x18U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[0U][1U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [0U][1U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                   : 0U) << 0x10U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                     : 0U) >> 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[0U][2U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [0U][2U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                   : 0U) << 0x18U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                     : 0U) >> 8U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[0U][3U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [0U][3U] ^ ((0xeU >= (0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                 ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                [(0xfU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][3U]
                                 : 0U)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[1U][0U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [1U][0U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                   : 0U) << 8U) | (
                                                   ((0xeU 
                                                     >= 
                                                     (0xfU 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                                     ? 
                                                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                                    [
                                                    (0xfU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                                     : 0U) 
                                                   >> 0x18U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[1U][1U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [1U][1U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                   : 0U) << 0x10U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                     : 0U) >> 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[1U][2U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [1U][2U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                   : 0U) << 0x18U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                     : 0U) >> 8U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[1U][3U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [1U][3U] ^ ((0xeU >= (0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                 ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                [(0xfU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][2U]
                                 : 0U)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[2U][0U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [2U][0U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                   : 0U) << 8U) | (
                                                   ((0xeU 
                                                     >= 
                                                     (0xfU 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                                     ? 
                                                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                                    [
                                                    (0xfU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                                     : 0U) 
                                                   >> 0x18U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[2U][1U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [2U][1U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                   : 0U) << 0x10U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                     : 0U) >> 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[2U][2U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [2U][2U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                   : 0U) << 0x18U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                     : 0U) >> 8U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[2U][3U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [2U][3U] ^ ((0xeU >= (0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                 ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                [(0xfU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][1U]
                                 : 0U)));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[3U][0U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [3U][0U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                   : 0U) << 8U) | (
                                                   ((0xeU 
                                                     >= 
                                                     (0xfU 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                                     ? 
                                                    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                                    [
                                                    (0xfU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                                     : 0U) 
                                                   >> 0x18U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[3U][1U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [3U][1U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                   : 0U) << 0x10U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                     : 0U) >> 0x10U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[3U][2U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [3U][2U] ^ ((((0xeU >= (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                   ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                  [(0xfU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                   : 0U) << 0x18U) 
                                | (((0xeU >= (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                     ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                    [(0xfU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                     : 0U) >> 8U))));
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[3U][3U] 
        = (0xffU & (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                    [3U][3U] ^ ((0xeU >= (0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round))))
                                 ? vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys
                                [(0xfU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round)))][0U]
                                 : 0U)));
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
}
