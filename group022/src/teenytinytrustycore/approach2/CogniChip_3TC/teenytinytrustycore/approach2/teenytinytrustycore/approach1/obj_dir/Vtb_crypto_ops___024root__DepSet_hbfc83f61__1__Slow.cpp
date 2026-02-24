// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_crypto_ops.h for the primary calling header

#include "Vtb_crypto_ops__pch.h"
#include "Vtb_crypto_ops___024root.h"

VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_triggers__stl(Vtb_crypto_ops___024root* vlSelf);
VL_ATTR_COLD void Vtb_crypto_ops___024root___eval_stl(Vtb_crypto_ops___024root* vlSelf);

VL_ATTR_COLD bool Vtb_crypto_ops___024root___eval_phase__stl(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___eval_phase__stl\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_crypto_ops___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_crypto_ops___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__act(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___dump_triggers__act\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_crypto_ops.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_crypto_ops.reset)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_crypto_ops___024root___dump_triggers__nba(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___dump_triggers__nba\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_crypto_ops.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_crypto_ops.reset)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_crypto_ops___024root____Vm_traceActivitySetAll(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root____Vm_traceActivitySetAll\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
}

VL_ATTR_COLD void Vtb_crypto_ops___024root___ctor_var_reset(Vtb_crypto_ops___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root___ctor_var_reset\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_crypto_ops__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17866118028386776903ull);
    vlSelf->tb_crypto_ops__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14478205239664225572ull);
    vlSelf->tb_crypto_ops__DOT__system_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12463256472325705031ull);
    vlSelf->tb_crypto_ops__DOT__derive_new_keys = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17594659775536141995ull);
    vlSelf->tb_crypto_ops__DOT__zeroize_all = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3576631003300902487ull);
    vlSelf->tb_crypto_ops__DOT__puf_dus_enroll = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9182346795726045507ull);
    vlSelf->tb_crypto_ops__DOT__puf_dus_regenerate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 99811924336279213ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__puf_dus_helper_in, __VscopeHash, 13716552731940900368ull);
    vlSelf->tb_crypto_ops__DOT__puf_devid_enroll = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12141186356328722207ull);
    vlSelf->tb_crypto_ops__DOT__puf_devid_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8559290299463527814ull);
    vlSelf->tb_crypto_ops__DOT__sha_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8632153059502723010ull);
    vlSelf->tb_crypto_ops__DOT__sha_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8123902847036114584ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_crypto_ops__DOT__sha_message, __VscopeHash, 18338906527160587171ull);
    vlSelf->tb_crypto_ops__DOT__hmac_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8536881014168617485ull);
    vlSelf->tb_crypto_ops__DOT__hmac_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4950836508504319354ull);
    vlSelf->tb_crypto_ops__DOT__hmac_final = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2728296069559480759ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_crypto_ops__DOT__hmac_message, __VscopeHash, 12298024762385675078ull);
    vlSelf->tb_crypto_ops__DOT__aes_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13859860346098721474ull);
    vlSelf->tb_crypto_ops__DOT__aes_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6548527428536069838ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__aes_nonce, __VscopeHash, 16847569051828562398ull);
    vlSelf->tb_crypto_ops__DOT__aes_counter_init = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13468464650801209360ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__aes_data_in, __VscopeHash, 15624107329051649249ull);
    vlSelf->tb_crypto_ops__DOT__cycle_count = 0;
    vlSelf->tb_crypto_ops__DOT__error_count = 0;
    vlSelf->tb_crypto_ops__DOT__test_count = 0;
    vlSelf->tb_crypto_ops__DOT__pass_count = 0;
    vlSelf->tb_crypto_ops__DOT__test_passed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2145550392801026329ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_derive = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9044466598560229105ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_context, __VscopeHash, 15887474507562691233ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 205886354600044092ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12977047821618122465ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_key_internal, __VscopeHash, 13118478466451444697ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3894544280986763319ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_key_internal, __VscopeHash, 7704545060844350797ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__init_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17403894323020024882ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__init_next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13066834332733219546ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__dus_valid_latched = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15373780881934313154ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__enroll_mode_latched = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11634803654174629595ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_keys_valid_latched = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 290117280418164754ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_enroll_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1502712487184642233ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_regenerate_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10301596762825021534ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_enroll_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16212439545665253358ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2570504673329989308ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2635675101006919802ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__puf_raw, __VscopeHash, 9194397959758270652ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__puf_enrolled, __VscopeHash, 3602468185773085384ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__measure_cycles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5666148047453109396ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16881704258425576190ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__helper_data_reg, __VscopeHash, 10498949443677296014ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__secret_reg, __VscopeHash, 16487747117688703909ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9322811917717642864ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__ro_frequencies, __VscopeHash, 8722224182835932350ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__lfsr_noise = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12964438900609334463ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__core_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 276351003001140813ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__noise_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4961525246482987529ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk3__DOT__corrected_puf, __VscopeHash, 11464545462634100966ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk3__DOT__syndrome, __VscopeHash, 9257175511963109785ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk4__DOT__syndrome, __VscopeHash, 3087438361937454793ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk4__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10004037173374663792ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4354446001036061952ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__device_id_reg, __VscopeHash, 5191019097777815013ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__enrolled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4166556246265009327ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__puf_measurement, __VscopeHash, 17010334830432199768ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__measure_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12168550313116243924ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__lfsr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10716375233687945975ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk1__DOT__current_sample, __VscopeHash, 16179060766815610705ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk3__DOT__mixed_id, __VscopeHash, 3656931225754409032ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1969628363000319593ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5972760837725071431ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8719328121963249254ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10483018593031134230ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message, __VscopeHash, 13995523801224539318ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash, __VscopeHash, 3265209298269605537ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__prk, __VscopeHash, 16450944347722525070ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__t_prev, __VscopeHash, 10520304925785983011ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg, __VscopeHash, 12742238004428685227ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg, __VscopeHash, 11775663408814199037ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg, __VscopeHash, 13816932482707981651ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__ipad_key, __VscopeHash, 1033440755065290574ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__opad_key, __VscopeHash, 608904300531692472ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__inner_hash, __VscopeHash, 1403264222389714119ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__block_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 468958444518420882ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7830967147761809318ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17182788335909369629ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18052697391964825343ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6902230234626321539ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2312228361768298961ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12486590561913193050ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11025197986744700694ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2752816113180075911ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3866262132683696515ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16299704441148903619ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2355946171977720106ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1142052417640306163ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16835422448890259987ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14578730245084011493ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15623180002303923679ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2137063580783684547ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17568724533348350716ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13269917497870779091ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13532527211258057281ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16451295576991419493ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5283974671853805787ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13779693845483140151ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2365341899899971243ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 988041897342658436ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round_next = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8990496879677493859ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3541832159638087056ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6305581076083725170ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk6__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16273376669793256048ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16197543963238350825ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg, __VscopeHash, 4715236158820585144ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg, __VscopeHash, 7551184722625499269ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg, __VscopeHash, 9387766174556656517ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8984713565482003295ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_locked = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2519041106241505236ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1021505629792880279ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_fail = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5573952212178842239ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_4_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17141394305159518160ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_6_0, __VscopeHash, 3525993954925498801ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_8_0, __VscopeHash, 8834134814905536607ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT___Vpast_10_0, __VscopeHash, 1804423280700387814ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8531995842507314605ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2591581951865532598ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8603274116941908522ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 868535250695333684ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9344140699469370109ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3898053296974091547ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17437634473764624660ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11269383676114891368ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17898392256655082211ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14298901722393528387ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5501880612623705259ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7433828221338275063ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 650214190791645920ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17417199240176825468ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15648376849516889004ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12431684990819921016ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17488077490313299693ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12089812513602293504ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11586995586370919955ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6304349076511355220ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10077051757247122774ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16304073955806849049ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1309134251572429615ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12206756208355649438ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round_next = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7677965498214270002ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5705103264077657036ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5520020369975680175ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk6__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10267886457857872793ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5825183484493480042ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6177402393420869761ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8842782660094160085ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message, __VscopeHash, 7571827893022051985ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash, __VscopeHash, 1871774119748344755ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__inner_hash, __VscopeHash, 13664103701233814367ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__mac_reg, __VscopeHash, 16961901207794645488ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__first_message_block = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9084193343862132443ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__is_final_block = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5269666775484342985ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 962178462242611417ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6287783844980894479ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10554976053720328371ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9532691019263629631ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10365342654363735569ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3989541207424120876ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4435550355127813909ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9056883035587098319ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5359076580366724361ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16466486846795282837ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1204904714046890313ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1501205489183623477ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16954467569445838153ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1647453837324178618ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11811710789888045629ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 923321482174452211ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5428766470152645666ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6493078881670420100ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5455532437938903660ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13122286585292313825ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16583214100137040625ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4231818125350244753ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12537650008563346610ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14417729830815166802ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round_next = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6767403458141613879ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18214141521039673245ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9218554969505900729ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk6__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16895588646045689292ull);
    }
    for (int __Vi0 = 0; __Vi0 < 15; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9533508654491176981ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10151874543495698863ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7776765803074915176ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8602688990822118368ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13814999509453064787ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 15; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[__Vi0], __VscopeHash, 12453251919384261908ull);
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4250179020730755317ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__counter, __VscopeHash, 647229825111870648ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__counter_block, __VscopeHash, 10229661499948157059ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__keystream, __VscopeHash, 9481729328507354466ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__init_latched = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17799927910440921746ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__key_exp_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11567070422508481808ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__keys_packed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16392303231020282604ull);
    for (int __Vi0 = 0; __Vi0 < 60; ++__Vi0) {
        vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13693181838264393356ull);
    }
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__data_out_reg, __VscopeHash, 11081301406235636755ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output, __VscopeHash, 13301963474041238124ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk3__DOT__r = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk6__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk7__DOT__unnamedblk8__DOT__j = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk9__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1140465106932913913ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8082924285665340988ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15864135705681721776ull);
        }
    }
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__j = 0;
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6154076293402334376ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3943246625622194360ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9504959387024177928ull);
    vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8642734433883233183ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT____Vlvbound_ha0707f26__0, __VscopeHash, 13538803465203594194ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17946698220153747754ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma1__8__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10148416920833379990ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 225140614363942957ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__9__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2558561542130186710ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16675237300369402163ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__10__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10195769213973148705ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3464163693311461059ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__gamma0__11__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16096726743932817116ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14074126926759178153ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__12__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9298145816687473772ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6798183879291788904ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__13__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6288966862949786730ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10920712031759417466ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma1__14__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10155654465121893614ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14139460021381024058ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__15__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16266732890135954524ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16247220069928425020ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__16__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12932642223971265977ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3763142529685082041ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__17__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4957445491039624837ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15309706026534836059ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6251481465525700799ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7462606124392244969ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__ch__18__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4152059148700864615ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10652604626878430592ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__sigma0__19__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2691877421199495212ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15398685798054192936ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__20__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12568253396381946806ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1373958933676297563ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__21__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14333552191110180621ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6082023684180681052ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__rotr__22__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7928809043863454802ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10768590532580248200ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13683034162944521156ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12694922122014434608ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__maj__23__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12857324007938000825ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1911968323206308401ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma1__24__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 756739434536245465ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4079483299646362375ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__25__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11941752621734045054ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11828732552611467525ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__26__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15314298993307089121ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7947895512318895650ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__gamma0__27__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2521395002204324246ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17904119198527504709ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__28__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16712353049242777017ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10435674831323861156ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__29__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 177537063351977727ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13408669653959609037ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma1__30__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1183751836177718405ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12190902147300030160ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__31__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3128977352885569095ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7718564140600888454ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__32__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2241059695599471634ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17389610366664269831ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__33__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6264171845232958131ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4878700117797443894ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9989075744481794529ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3110606113328865282ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__ch__34__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14920636721620243175ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14710647099743298610ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__sigma0__35__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2438488396917075882ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6515396905610080356ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__36__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9076492481559603366ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16453869740414671400ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__37__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3599347242829785297ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18053909913802091980ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__rotr__38__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18063429556527127452ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1459829017098202915ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11236694605473365993ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15470085343333204978ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__maj__39__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 912418746166116620ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1177310334807647387ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma1__40__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4647667531230328434ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4292659432113998272ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__41__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16812583244889014497ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11178058158215067898ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__42__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13124431013784140937ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10996956521214601425ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__gamma0__43__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1473029603409212322ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17425287824756493936ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__44__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1078509311759861658ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17792773940959990189ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__45__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4292225593585213017ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12486694464270763786ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma1__46__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4745083796231234951ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13515327664319302043ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__47__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9980119561331373384ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14160037760605674587ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__48__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14456357969108453602ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17472154340115179710ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__49__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13998743408327586315ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13807497431789528269ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2226505647338346716ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6413515515272775435ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__ch__50__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14833039559438021656ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13101858090818894776ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__sigma0__51__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1407639226024532588ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14940021739769702510ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__52__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4191597928810063483ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3067035355125716569ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__53__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17894931498434020072ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13621662745010925773ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__rotr__54__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17933467225011827443ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16294814593397123965ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__x = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1525139187227071046ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__y = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 124938187841295171ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__maj__55__z = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5820916376522612358ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7226658046969392564ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__56__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14148312108816173102ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4618581351167028991ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__57__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2241982544233117959ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15685268625893404443ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__58__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17643539760706628968ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16817852608033859024ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__59__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3885450853834384307ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12394686897928409158ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__60__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12725358542376048295ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8239223291156011705ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__61__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2876468615996639911ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11020931845251207172ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__62__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 20415000315333736ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14001923107293706892ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__63__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1362159449070658610ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10655261517188476000ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__64__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1536409661454203440ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13621624587277180266ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul3__65__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9855733811449227942ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9320959789274286002ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__66__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8519854956993802682ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6336506025888252041ull);
    vlSelf->__Vfunc_tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__gmul2__67__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13592862790784250220ull);
    vlSelf->__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8530115560212395610ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg, __VscopeHash, 16481828783515341786ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg, __VscopeHash, 3827429204547750129ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->__Vsampled_TOP__tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg, __VscopeHash, 5959516611170043248ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17858442368182805715ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_crypto_ops__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5178540763517980728ull);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
