// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_crypto_ops.h for the primary calling header

#include "Vtb_crypto_ops__pch.h"
#include "Vtb_crypto_ops__Syms.h"
#include "Vtb_crypto_ops___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_crypto_ops___024root___eval_initial__TOP__Vtiming__2(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x174876e800ULL, 
                                         nullptr, "tb_crypto_ops.sv", 
                                         549);
    VL_WRITEF_NX("LOG: %0t : ERROR : tb_crypto_ops : timeout : expected_value: test_complete actual_value: simulation_timeout\nERROR\n[%0t] %%Fatal: tb_crypto_ops.sv:552: Assertion failed in %Ntb_crypto_ops: Simulation timeout - exceeded 100ms\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,64,VL_TIME_UNITED_Q(1),
                 -12,vlSymsp->name());
    VL_STOP_MT("tb_crypto_ops.sv", 552, "", false);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__act(Vtb_crypto_ops___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_crypto_ops___024root___eval_triggers__act(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_triggers__act\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_crypto_ops__DOT__clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__clock__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.tb_crypto_ops__DOT__reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__reset__0))));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__clock__0 
        = vlSelfRef.tb_crypto_ops__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__reset__0 
        = vlSelfRef.tb_crypto_ops__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_crypto_ops___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_h5b979007_0;

VL_INLINE_OPT void Vtb_crypto_ops___024root___nba_sequent__TOP__2(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___nba_sequent__TOP__2\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U == ((((((((Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U]) 
                                           | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U])) 
                                          | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U])) 
                                         | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U])) 
                                        | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U])) 
                                       | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U])) 
                                      | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U])) 
                                     | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:213: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: HMAC key is all-ones - security violation!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 213, "");
            }
        }
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U == ((((((((Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U]) 
                                           | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U])) 
                                          | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U])) 
                                         | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U])) 
                                        | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U])) 
                                       | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U])) 
                                      | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U])) 
                                     | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:215: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: AES key is all-ones - security violation!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 215, "");
            }
        }
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U == ((((((((Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U]) 
                                           | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U])) 
                                          | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U])) 
                                         | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U])) 
                                        | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U])) 
                                       | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U])) 
                                      | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U])) 
                                     | (Vtb_crypto_ops__ConstPool__CONST_h5b979007_0[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:217: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: SHA key is all-ones - security violation!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 217, "");
            }
        }
    }
    if ((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:223: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: Zeroize must return to IDLE!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 223, "");
            }
        }
    }
    if ((((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state)) 
          & (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_4_0))) 
         & (~ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[0U]) 
                                           | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[1U])) 
                                          | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[2U])) 
                                         | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[3U])) 
                                        | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[4U])) 
                                       | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[5U])) 
                                      | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[6U])) 
                                     | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:229: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: HMAC key changed while active!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 229, "");
            }
        }
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[0U]) 
                                           | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[1U])) 
                                          | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[2U])) 
                                         | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[3U])) 
                                        | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[4U])) 
                                       | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[5U])) 
                                      | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[6U])) 
                                     | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:231: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: AES key changed while active!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 231, "");
            }
        }
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[0U]) 
                                           | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U] 
                                              ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[1U])) 
                                          | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U] 
                                             ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[2U])) 
                                         | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U] 
                                            ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[3U])) 
                                        | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U] 
                                           ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[4U])) 
                                       | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U] 
                                          ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[5U])) 
                                      | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U] 
                                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[6U])) 
                                     | (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U] 
                                        ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[7U])))))) {
                VL_WRITEF_NX("[%0t] %%Error: secure_key_distributor.sv:233: Assertion failed in %Ntb_crypto_ops.dut.key_dist_inst: SHA key changed while active!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("secure_key_distributor.sv", 233, "");
            }
        }
    }
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_4_0 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state;
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[0U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[1U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[2U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[3U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[4U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[5U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[6U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0[7U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg[7U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[0U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[1U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[2U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[3U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[4U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[5U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[6U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0[7U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg[7U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[0U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[1U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[2U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[3U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[4U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[5U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[6U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U];
    vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0[7U] 
        = vlSelfRef.__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U];
}
