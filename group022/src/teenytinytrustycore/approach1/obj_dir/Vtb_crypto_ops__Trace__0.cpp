// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb_crypto_ops__Syms.h"


void Vtb_crypto_ops___024root__trace_chg_0_sub_0(Vtb_crypto_ops___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtb_crypto_ops___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root__trace_chg_0\n"); );
    // Init
    Vtb_crypto_ops___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_crypto_ops___024root*>(voidSelf);
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_crypto_ops___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0;
extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0;
extern const VlWide<8>/*255:0*/ Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0;

void Vtb_crypto_ops___024root__trace_chg_0_sub_0(Vtb_crypto_ops___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root__trace_chg_0_sub_0\n"); );
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<8>/*255:0*/ __Vtemp_6;
    VlWide<8>/*255:0*/ __Vtemp_7;
    VlWide<8>/*255:0*/ __Vtemp_8;
    VlWide<8>/*255:0*/ __Vtemp_9;
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[0]),8);
        bufp->chgCData(oldp+1,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[1]),8);
        bufp->chgCData(oldp+2,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[2]),8);
        bufp->chgCData(oldp+3,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[3]),8);
        bufp->chgCData(oldp+4,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[4]),8);
        bufp->chgCData(oldp+5,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[5]),8);
        bufp->chgCData(oldp+6,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[6]),8);
        bufp->chgCData(oldp+7,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[7]),8);
        bufp->chgCData(oldp+8,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[8]),8);
        bufp->chgCData(oldp+9,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[9]),8);
        bufp->chgCData(oldp+10,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[10]),8);
        bufp->chgCData(oldp+11,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[11]),8);
        bufp->chgCData(oldp+12,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[12]),8);
        bufp->chgCData(oldp+13,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[13]),8);
        bufp->chgCData(oldp+14,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[14]),8);
        bufp->chgCData(oldp+15,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[15]),8);
        bufp->chgCData(oldp+16,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[16]),8);
        bufp->chgCData(oldp+17,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[17]),8);
        bufp->chgCData(oldp+18,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[18]),8);
        bufp->chgCData(oldp+19,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[19]),8);
        bufp->chgCData(oldp+20,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[20]),8);
        bufp->chgCData(oldp+21,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[21]),8);
        bufp->chgCData(oldp+22,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[22]),8);
        bufp->chgCData(oldp+23,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[23]),8);
        bufp->chgCData(oldp+24,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[24]),8);
        bufp->chgCData(oldp+25,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[25]),8);
        bufp->chgCData(oldp+26,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[26]),8);
        bufp->chgCData(oldp+27,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[27]),8);
        bufp->chgCData(oldp+28,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[28]),8);
        bufp->chgCData(oldp+29,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[29]),8);
        bufp->chgCData(oldp+30,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[30]),8);
        bufp->chgCData(oldp+31,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[31]),8);
        bufp->chgCData(oldp+32,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[32]),8);
        bufp->chgCData(oldp+33,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[33]),8);
        bufp->chgCData(oldp+34,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[34]),8);
        bufp->chgCData(oldp+35,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[35]),8);
        bufp->chgCData(oldp+36,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[36]),8);
        bufp->chgCData(oldp+37,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[37]),8);
        bufp->chgCData(oldp+38,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[38]),8);
        bufp->chgCData(oldp+39,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[39]),8);
        bufp->chgCData(oldp+40,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[40]),8);
        bufp->chgCData(oldp+41,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[41]),8);
        bufp->chgCData(oldp+42,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[42]),8);
        bufp->chgCData(oldp+43,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[43]),8);
        bufp->chgCData(oldp+44,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[44]),8);
        bufp->chgCData(oldp+45,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[45]),8);
        bufp->chgCData(oldp+46,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[46]),8);
        bufp->chgCData(oldp+47,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[47]),8);
        bufp->chgCData(oldp+48,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[48]),8);
        bufp->chgCData(oldp+49,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[49]),8);
        bufp->chgCData(oldp+50,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[50]),8);
        bufp->chgCData(oldp+51,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[51]),8);
        bufp->chgCData(oldp+52,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[52]),8);
        bufp->chgCData(oldp+53,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[53]),8);
        bufp->chgCData(oldp+54,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[54]),8);
        bufp->chgCData(oldp+55,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[55]),8);
        bufp->chgCData(oldp+56,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[56]),8);
        bufp->chgCData(oldp+57,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[57]),8);
        bufp->chgCData(oldp+58,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[58]),8);
        bufp->chgCData(oldp+59,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[59]),8);
        bufp->chgCData(oldp+60,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[60]),8);
        bufp->chgCData(oldp+61,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[61]),8);
        bufp->chgCData(oldp+62,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[62]),8);
        bufp->chgCData(oldp+63,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[63]),8);
        bufp->chgCData(oldp+64,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[64]),8);
        bufp->chgCData(oldp+65,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[65]),8);
        bufp->chgCData(oldp+66,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[66]),8);
        bufp->chgCData(oldp+67,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[67]),8);
        bufp->chgCData(oldp+68,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[68]),8);
        bufp->chgCData(oldp+69,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[69]),8);
        bufp->chgCData(oldp+70,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[70]),8);
        bufp->chgCData(oldp+71,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[71]),8);
        bufp->chgCData(oldp+72,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[72]),8);
        bufp->chgCData(oldp+73,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[73]),8);
        bufp->chgCData(oldp+74,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[74]),8);
        bufp->chgCData(oldp+75,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[75]),8);
        bufp->chgCData(oldp+76,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[76]),8);
        bufp->chgCData(oldp+77,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[77]),8);
        bufp->chgCData(oldp+78,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[78]),8);
        bufp->chgCData(oldp+79,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[79]),8);
        bufp->chgCData(oldp+80,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[80]),8);
        bufp->chgCData(oldp+81,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[81]),8);
        bufp->chgCData(oldp+82,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[82]),8);
        bufp->chgCData(oldp+83,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[83]),8);
        bufp->chgCData(oldp+84,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[84]),8);
        bufp->chgCData(oldp+85,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[85]),8);
        bufp->chgCData(oldp+86,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[86]),8);
        bufp->chgCData(oldp+87,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[87]),8);
        bufp->chgCData(oldp+88,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[88]),8);
        bufp->chgCData(oldp+89,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[89]),8);
        bufp->chgCData(oldp+90,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[90]),8);
        bufp->chgCData(oldp+91,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[91]),8);
        bufp->chgCData(oldp+92,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[92]),8);
        bufp->chgCData(oldp+93,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[93]),8);
        bufp->chgCData(oldp+94,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[94]),8);
        bufp->chgCData(oldp+95,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[95]),8);
        bufp->chgCData(oldp+96,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[96]),8);
        bufp->chgCData(oldp+97,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[97]),8);
        bufp->chgCData(oldp+98,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[98]),8);
        bufp->chgCData(oldp+99,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[99]),8);
        bufp->chgCData(oldp+100,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[100]),8);
        bufp->chgCData(oldp+101,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[101]),8);
        bufp->chgCData(oldp+102,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[102]),8);
        bufp->chgCData(oldp+103,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[103]),8);
        bufp->chgCData(oldp+104,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[104]),8);
        bufp->chgCData(oldp+105,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[105]),8);
        bufp->chgCData(oldp+106,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[106]),8);
        bufp->chgCData(oldp+107,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[107]),8);
        bufp->chgCData(oldp+108,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[108]),8);
        bufp->chgCData(oldp+109,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[109]),8);
        bufp->chgCData(oldp+110,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[110]),8);
        bufp->chgCData(oldp+111,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[111]),8);
        bufp->chgCData(oldp+112,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[112]),8);
        bufp->chgCData(oldp+113,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[113]),8);
        bufp->chgCData(oldp+114,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[114]),8);
        bufp->chgCData(oldp+115,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[115]),8);
        bufp->chgCData(oldp+116,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[116]),8);
        bufp->chgCData(oldp+117,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[117]),8);
        bufp->chgCData(oldp+118,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[118]),8);
        bufp->chgCData(oldp+119,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[119]),8);
        bufp->chgCData(oldp+120,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[120]),8);
        bufp->chgCData(oldp+121,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[121]),8);
        bufp->chgCData(oldp+122,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[122]),8);
        bufp->chgCData(oldp+123,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[123]),8);
        bufp->chgCData(oldp+124,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[124]),8);
        bufp->chgCData(oldp+125,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[125]),8);
        bufp->chgCData(oldp+126,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[126]),8);
        bufp->chgCData(oldp+127,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[127]),8);
        bufp->chgCData(oldp+128,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[128]),8);
        bufp->chgCData(oldp+129,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[129]),8);
        bufp->chgCData(oldp+130,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[130]),8);
        bufp->chgCData(oldp+131,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[131]),8);
        bufp->chgCData(oldp+132,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[132]),8);
        bufp->chgCData(oldp+133,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[133]),8);
        bufp->chgCData(oldp+134,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[134]),8);
        bufp->chgCData(oldp+135,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[135]),8);
        bufp->chgCData(oldp+136,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[136]),8);
        bufp->chgCData(oldp+137,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[137]),8);
        bufp->chgCData(oldp+138,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[138]),8);
        bufp->chgCData(oldp+139,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[139]),8);
        bufp->chgCData(oldp+140,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[140]),8);
        bufp->chgCData(oldp+141,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[141]),8);
        bufp->chgCData(oldp+142,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[142]),8);
        bufp->chgCData(oldp+143,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[143]),8);
        bufp->chgCData(oldp+144,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[144]),8);
        bufp->chgCData(oldp+145,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[145]),8);
        bufp->chgCData(oldp+146,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[146]),8);
        bufp->chgCData(oldp+147,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[147]),8);
        bufp->chgCData(oldp+148,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[148]),8);
        bufp->chgCData(oldp+149,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[149]),8);
        bufp->chgCData(oldp+150,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[150]),8);
        bufp->chgCData(oldp+151,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[151]),8);
        bufp->chgCData(oldp+152,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[152]),8);
        bufp->chgCData(oldp+153,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[153]),8);
        bufp->chgCData(oldp+154,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[154]),8);
        bufp->chgCData(oldp+155,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[155]),8);
        bufp->chgCData(oldp+156,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[156]),8);
        bufp->chgCData(oldp+157,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[157]),8);
        bufp->chgCData(oldp+158,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[158]),8);
        bufp->chgCData(oldp+159,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[159]),8);
        bufp->chgCData(oldp+160,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[160]),8);
        bufp->chgCData(oldp+161,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[161]),8);
        bufp->chgCData(oldp+162,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[162]),8);
        bufp->chgCData(oldp+163,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[163]),8);
        bufp->chgCData(oldp+164,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[164]),8);
        bufp->chgCData(oldp+165,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[165]),8);
        bufp->chgCData(oldp+166,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[166]),8);
        bufp->chgCData(oldp+167,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[167]),8);
        bufp->chgCData(oldp+168,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[168]),8);
        bufp->chgCData(oldp+169,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[169]),8);
        bufp->chgCData(oldp+170,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[170]),8);
        bufp->chgCData(oldp+171,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[171]),8);
        bufp->chgCData(oldp+172,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[172]),8);
        bufp->chgCData(oldp+173,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[173]),8);
        bufp->chgCData(oldp+174,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[174]),8);
        bufp->chgCData(oldp+175,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[175]),8);
        bufp->chgCData(oldp+176,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[176]),8);
        bufp->chgCData(oldp+177,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[177]),8);
        bufp->chgCData(oldp+178,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[178]),8);
        bufp->chgCData(oldp+179,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[179]),8);
        bufp->chgCData(oldp+180,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[180]),8);
        bufp->chgCData(oldp+181,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[181]),8);
        bufp->chgCData(oldp+182,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[182]),8);
        bufp->chgCData(oldp+183,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[183]),8);
        bufp->chgCData(oldp+184,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[184]),8);
        bufp->chgCData(oldp+185,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[185]),8);
        bufp->chgCData(oldp+186,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[186]),8);
        bufp->chgCData(oldp+187,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[187]),8);
        bufp->chgCData(oldp+188,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[188]),8);
        bufp->chgCData(oldp+189,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[189]),8);
        bufp->chgCData(oldp+190,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[190]),8);
        bufp->chgCData(oldp+191,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[191]),8);
        bufp->chgCData(oldp+192,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[192]),8);
        bufp->chgCData(oldp+193,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[193]),8);
        bufp->chgCData(oldp+194,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[194]),8);
        bufp->chgCData(oldp+195,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[195]),8);
        bufp->chgCData(oldp+196,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[196]),8);
        bufp->chgCData(oldp+197,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[197]),8);
        bufp->chgCData(oldp+198,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[198]),8);
        bufp->chgCData(oldp+199,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[199]),8);
        bufp->chgCData(oldp+200,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[200]),8);
        bufp->chgCData(oldp+201,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[201]),8);
        bufp->chgCData(oldp+202,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[202]),8);
        bufp->chgCData(oldp+203,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[203]),8);
        bufp->chgCData(oldp+204,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[204]),8);
        bufp->chgCData(oldp+205,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[205]),8);
        bufp->chgCData(oldp+206,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[206]),8);
        bufp->chgCData(oldp+207,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[207]),8);
        bufp->chgCData(oldp+208,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[208]),8);
        bufp->chgCData(oldp+209,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[209]),8);
        bufp->chgCData(oldp+210,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[210]),8);
        bufp->chgCData(oldp+211,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[211]),8);
        bufp->chgCData(oldp+212,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[212]),8);
        bufp->chgCData(oldp+213,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[213]),8);
        bufp->chgCData(oldp+214,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[214]),8);
        bufp->chgCData(oldp+215,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[215]),8);
        bufp->chgCData(oldp+216,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[216]),8);
        bufp->chgCData(oldp+217,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[217]),8);
        bufp->chgCData(oldp+218,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[218]),8);
        bufp->chgCData(oldp+219,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[219]),8);
        bufp->chgCData(oldp+220,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[220]),8);
        bufp->chgCData(oldp+221,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[221]),8);
        bufp->chgCData(oldp+222,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[222]),8);
        bufp->chgCData(oldp+223,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[223]),8);
        bufp->chgCData(oldp+224,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[224]),8);
        bufp->chgCData(oldp+225,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[225]),8);
        bufp->chgCData(oldp+226,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[226]),8);
        bufp->chgCData(oldp+227,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[227]),8);
        bufp->chgCData(oldp+228,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[228]),8);
        bufp->chgCData(oldp+229,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[229]),8);
        bufp->chgCData(oldp+230,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[230]),8);
        bufp->chgCData(oldp+231,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[231]),8);
        bufp->chgCData(oldp+232,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[232]),8);
        bufp->chgCData(oldp+233,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[233]),8);
        bufp->chgCData(oldp+234,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[234]),8);
        bufp->chgCData(oldp+235,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[235]),8);
        bufp->chgCData(oldp+236,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[236]),8);
        bufp->chgCData(oldp+237,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[237]),8);
        bufp->chgCData(oldp+238,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[238]),8);
        bufp->chgCData(oldp+239,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[239]),8);
        bufp->chgCData(oldp+240,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[240]),8);
        bufp->chgCData(oldp+241,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[241]),8);
        bufp->chgCData(oldp+242,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[242]),8);
        bufp->chgCData(oldp+243,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[243]),8);
        bufp->chgCData(oldp+244,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[244]),8);
        bufp->chgCData(oldp+245,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[245]),8);
        bufp->chgCData(oldp+246,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[246]),8);
        bufp->chgCData(oldp+247,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[247]),8);
        bufp->chgCData(oldp+248,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[248]),8);
        bufp->chgCData(oldp+249,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[249]),8);
        bufp->chgCData(oldp+250,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[250]),8);
        bufp->chgCData(oldp+251,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[251]),8);
        bufp->chgCData(oldp+252,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[252]),8);
        bufp->chgCData(oldp+253,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[253]),8);
        bufp->chgCData(oldp+254,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[254]),8);
        bufp->chgCData(oldp+255,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__sbox[255]),8);
        bufp->chgCData(oldp+256,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[0]),8);
        bufp->chgCData(oldp+257,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[1]),8);
        bufp->chgCData(oldp+258,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[2]),8);
        bufp->chgCData(oldp+259,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[3]),8);
        bufp->chgCData(oldp+260,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[4]),8);
        bufp->chgCData(oldp+261,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[5]),8);
        bufp->chgCData(oldp+262,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[6]),8);
        bufp->chgCData(oldp+263,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[7]),8);
        bufp->chgCData(oldp+264,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[8]),8);
        bufp->chgCData(oldp+265,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[9]),8);
        bufp->chgCData(oldp+266,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[10]),8);
        bufp->chgCData(oldp+267,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[11]),8);
        bufp->chgCData(oldp+268,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[12]),8);
        bufp->chgCData(oldp+269,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[13]),8);
        bufp->chgCData(oldp+270,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__rcon[14]),8);
        bufp->chgIData(oldp+271,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[0]),32);
        bufp->chgIData(oldp+272,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[1]),32);
        bufp->chgIData(oldp+273,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[2]),32);
        bufp->chgIData(oldp+274,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[3]),32);
        bufp->chgIData(oldp+275,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[4]),32);
        bufp->chgIData(oldp+276,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[5]),32);
        bufp->chgIData(oldp+277,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[6]),32);
        bufp->chgIData(oldp+278,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[7]),32);
        bufp->chgIData(oldp+279,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[8]),32);
        bufp->chgIData(oldp+280,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[9]),32);
        bufp->chgIData(oldp+281,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[10]),32);
        bufp->chgIData(oldp+282,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[11]),32);
        bufp->chgIData(oldp+283,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[12]),32);
        bufp->chgIData(oldp+284,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[13]),32);
        bufp->chgIData(oldp+285,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[14]),32);
        bufp->chgIData(oldp+286,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[15]),32);
        bufp->chgIData(oldp+287,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[16]),32);
        bufp->chgIData(oldp+288,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[17]),32);
        bufp->chgIData(oldp+289,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[18]),32);
        bufp->chgIData(oldp+290,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[19]),32);
        bufp->chgIData(oldp+291,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[20]),32);
        bufp->chgIData(oldp+292,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[21]),32);
        bufp->chgIData(oldp+293,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[22]),32);
        bufp->chgIData(oldp+294,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[23]),32);
        bufp->chgIData(oldp+295,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[24]),32);
        bufp->chgIData(oldp+296,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[25]),32);
        bufp->chgIData(oldp+297,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[26]),32);
        bufp->chgIData(oldp+298,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[27]),32);
        bufp->chgIData(oldp+299,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[28]),32);
        bufp->chgIData(oldp+300,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[29]),32);
        bufp->chgIData(oldp+301,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[30]),32);
        bufp->chgIData(oldp+302,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[31]),32);
        bufp->chgIData(oldp+303,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[32]),32);
        bufp->chgIData(oldp+304,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[33]),32);
        bufp->chgIData(oldp+305,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[34]),32);
        bufp->chgIData(oldp+306,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[35]),32);
        bufp->chgIData(oldp+307,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[36]),32);
        bufp->chgIData(oldp+308,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[37]),32);
        bufp->chgIData(oldp+309,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[38]),32);
        bufp->chgIData(oldp+310,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[39]),32);
        bufp->chgIData(oldp+311,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[40]),32);
        bufp->chgIData(oldp+312,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[41]),32);
        bufp->chgIData(oldp+313,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[42]),32);
        bufp->chgIData(oldp+314,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[43]),32);
        bufp->chgIData(oldp+315,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[44]),32);
        bufp->chgIData(oldp+316,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[45]),32);
        bufp->chgIData(oldp+317,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[46]),32);
        bufp->chgIData(oldp+318,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[47]),32);
        bufp->chgIData(oldp+319,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[48]),32);
        bufp->chgIData(oldp+320,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[49]),32);
        bufp->chgIData(oldp+321,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[50]),32);
        bufp->chgIData(oldp+322,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[51]),32);
        bufp->chgIData(oldp+323,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[52]),32);
        bufp->chgIData(oldp+324,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[53]),32);
        bufp->chgIData(oldp+325,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[54]),32);
        bufp->chgIData(oldp+326,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[55]),32);
        bufp->chgIData(oldp+327,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[56]),32);
        bufp->chgIData(oldp+328,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[57]),32);
        bufp->chgIData(oldp+329,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[58]),32);
        bufp->chgIData(oldp+330,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[59]),32);
        bufp->chgIData(oldp+331,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[60]),32);
        bufp->chgIData(oldp+332,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[61]),32);
        bufp->chgIData(oldp+333,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[62]),32);
        bufp->chgIData(oldp+334,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__K[63]),32);
        bufp->chgIData(oldp+335,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[0]),32);
        bufp->chgIData(oldp+336,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[1]),32);
        bufp->chgIData(oldp+337,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[2]),32);
        bufp->chgIData(oldp+338,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[3]),32);
        bufp->chgIData(oldp+339,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[4]),32);
        bufp->chgIData(oldp+340,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[5]),32);
        bufp->chgIData(oldp+341,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[6]),32);
        bufp->chgIData(oldp+342,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[7]),32);
        bufp->chgIData(oldp+343,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[8]),32);
        bufp->chgIData(oldp+344,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[9]),32);
        bufp->chgIData(oldp+345,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[10]),32);
        bufp->chgIData(oldp+346,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[11]),32);
        bufp->chgIData(oldp+347,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[12]),32);
        bufp->chgIData(oldp+348,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[13]),32);
        bufp->chgIData(oldp+349,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[14]),32);
        bufp->chgIData(oldp+350,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[15]),32);
        bufp->chgIData(oldp+351,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[16]),32);
        bufp->chgIData(oldp+352,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[17]),32);
        bufp->chgIData(oldp+353,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[18]),32);
        bufp->chgIData(oldp+354,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[19]),32);
        bufp->chgIData(oldp+355,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[20]),32);
        bufp->chgIData(oldp+356,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[21]),32);
        bufp->chgIData(oldp+357,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[22]),32);
        bufp->chgIData(oldp+358,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[23]),32);
        bufp->chgIData(oldp+359,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[24]),32);
        bufp->chgIData(oldp+360,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[25]),32);
        bufp->chgIData(oldp+361,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[26]),32);
        bufp->chgIData(oldp+362,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[27]),32);
        bufp->chgIData(oldp+363,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[28]),32);
        bufp->chgIData(oldp+364,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[29]),32);
        bufp->chgIData(oldp+365,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[30]),32);
        bufp->chgIData(oldp+366,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[31]),32);
        bufp->chgIData(oldp+367,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[32]),32);
        bufp->chgIData(oldp+368,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[33]),32);
        bufp->chgIData(oldp+369,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[34]),32);
        bufp->chgIData(oldp+370,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[35]),32);
        bufp->chgIData(oldp+371,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[36]),32);
        bufp->chgIData(oldp+372,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[37]),32);
        bufp->chgIData(oldp+373,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[38]),32);
        bufp->chgIData(oldp+374,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[39]),32);
        bufp->chgIData(oldp+375,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[40]),32);
        bufp->chgIData(oldp+376,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[41]),32);
        bufp->chgIData(oldp+377,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[42]),32);
        bufp->chgIData(oldp+378,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[43]),32);
        bufp->chgIData(oldp+379,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[44]),32);
        bufp->chgIData(oldp+380,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[45]),32);
        bufp->chgIData(oldp+381,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[46]),32);
        bufp->chgIData(oldp+382,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[47]),32);
        bufp->chgIData(oldp+383,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[48]),32);
        bufp->chgIData(oldp+384,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[49]),32);
        bufp->chgIData(oldp+385,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[50]),32);
        bufp->chgIData(oldp+386,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[51]),32);
        bufp->chgIData(oldp+387,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[52]),32);
        bufp->chgIData(oldp+388,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[53]),32);
        bufp->chgIData(oldp+389,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[54]),32);
        bufp->chgIData(oldp+390,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[55]),32);
        bufp->chgIData(oldp+391,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[56]),32);
        bufp->chgIData(oldp+392,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[57]),32);
        bufp->chgIData(oldp+393,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[58]),32);
        bufp->chgIData(oldp+394,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[59]),32);
        bufp->chgIData(oldp+395,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[60]),32);
        bufp->chgIData(oldp+396,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[61]),32);
        bufp->chgIData(oldp+397,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[62]),32);
        bufp->chgIData(oldp+398,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__K[63]),32);
        bufp->chgIData(oldp+399,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[0]),32);
        bufp->chgIData(oldp+400,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[1]),32);
        bufp->chgIData(oldp+401,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[2]),32);
        bufp->chgIData(oldp+402,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[3]),32);
        bufp->chgIData(oldp+403,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[4]),32);
        bufp->chgIData(oldp+404,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[5]),32);
        bufp->chgIData(oldp+405,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[6]),32);
        bufp->chgIData(oldp+406,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[7]),32);
        bufp->chgIData(oldp+407,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[8]),32);
        bufp->chgIData(oldp+408,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[9]),32);
        bufp->chgIData(oldp+409,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[10]),32);
        bufp->chgIData(oldp+410,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[11]),32);
        bufp->chgIData(oldp+411,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[12]),32);
        bufp->chgIData(oldp+412,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[13]),32);
        bufp->chgIData(oldp+413,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[14]),32);
        bufp->chgIData(oldp+414,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[15]),32);
        bufp->chgIData(oldp+415,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[16]),32);
        bufp->chgIData(oldp+416,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[17]),32);
        bufp->chgIData(oldp+417,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[18]),32);
        bufp->chgIData(oldp+418,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[19]),32);
        bufp->chgIData(oldp+419,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[20]),32);
        bufp->chgIData(oldp+420,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[21]),32);
        bufp->chgIData(oldp+421,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[22]),32);
        bufp->chgIData(oldp+422,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[23]),32);
        bufp->chgIData(oldp+423,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[24]),32);
        bufp->chgIData(oldp+424,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[25]),32);
        bufp->chgIData(oldp+425,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[26]),32);
        bufp->chgIData(oldp+426,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[27]),32);
        bufp->chgIData(oldp+427,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[28]),32);
        bufp->chgIData(oldp+428,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[29]),32);
        bufp->chgIData(oldp+429,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[30]),32);
        bufp->chgIData(oldp+430,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[31]),32);
        bufp->chgIData(oldp+431,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[32]),32);
        bufp->chgIData(oldp+432,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[33]),32);
        bufp->chgIData(oldp+433,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[34]),32);
        bufp->chgIData(oldp+434,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[35]),32);
        bufp->chgIData(oldp+435,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[36]),32);
        bufp->chgIData(oldp+436,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[37]),32);
        bufp->chgIData(oldp+437,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[38]),32);
        bufp->chgIData(oldp+438,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[39]),32);
        bufp->chgIData(oldp+439,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[40]),32);
        bufp->chgIData(oldp+440,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[41]),32);
        bufp->chgIData(oldp+441,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[42]),32);
        bufp->chgIData(oldp+442,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[43]),32);
        bufp->chgIData(oldp+443,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[44]),32);
        bufp->chgIData(oldp+444,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[45]),32);
        bufp->chgIData(oldp+445,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[46]),32);
        bufp->chgIData(oldp+446,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[47]),32);
        bufp->chgIData(oldp+447,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[48]),32);
        bufp->chgIData(oldp+448,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[49]),32);
        bufp->chgIData(oldp+449,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[50]),32);
        bufp->chgIData(oldp+450,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[51]),32);
        bufp->chgIData(oldp+451,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[52]),32);
        bufp->chgIData(oldp+452,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[53]),32);
        bufp->chgIData(oldp+453,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[54]),32);
        bufp->chgIData(oldp+454,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[55]),32);
        bufp->chgIData(oldp+455,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[56]),32);
        bufp->chgIData(oldp+456,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[57]),32);
        bufp->chgIData(oldp+457,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[58]),32);
        bufp->chgIData(oldp+458,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[59]),32);
        bufp->chgIData(oldp+459,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[60]),32);
        bufp->chgIData(oldp+460,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[61]),32);
        bufp->chgIData(oldp+461,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[62]),32);
        bufp->chgIData(oldp+462,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__K[63]),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+463,(vlSelfRef.tb_crypto_ops__DOT__reset));
        bufp->chgBit(oldp+464,(vlSelfRef.tb_crypto_ops__DOT__system_init));
        bufp->chgBit(oldp+465,(vlSelfRef.tb_crypto_ops__DOT__derive_new_keys));
        bufp->chgBit(oldp+466,(vlSelfRef.tb_crypto_ops__DOT__zeroize_all));
        bufp->chgBit(oldp+467,(vlSelfRef.tb_crypto_ops__DOT__puf_dus_enroll));
        bufp->chgBit(oldp+468,(vlSelfRef.tb_crypto_ops__DOT__puf_dus_regenerate));
        bufp->chgWData(oldp+469,(vlSelfRef.tb_crypto_ops__DOT__puf_dus_helper_in),256);
        bufp->chgBit(oldp+477,(vlSelfRef.tb_crypto_ops__DOT__puf_devid_enroll));
        bufp->chgBit(oldp+478,(vlSelfRef.tb_crypto_ops__DOT__puf_devid_read));
        bufp->chgBit(oldp+479,(vlSelfRef.tb_crypto_ops__DOT__sha_start));
        bufp->chgBit(oldp+480,(vlSelfRef.tb_crypto_ops__DOT__sha_init));
        bufp->chgWData(oldp+481,(vlSelfRef.tb_crypto_ops__DOT__sha_message),512);
        bufp->chgBit(oldp+497,(vlSelfRef.tb_crypto_ops__DOT__hmac_start));
        bufp->chgBit(oldp+498,(vlSelfRef.tb_crypto_ops__DOT__hmac_init));
        bufp->chgBit(oldp+499,(vlSelfRef.tb_crypto_ops__DOT__hmac_final));
        bufp->chgWData(oldp+500,(vlSelfRef.tb_crypto_ops__DOT__hmac_message),512);
        bufp->chgBit(oldp+516,(vlSelfRef.tb_crypto_ops__DOT__aes_start));
        bufp->chgBit(oldp+517,(vlSelfRef.tb_crypto_ops__DOT__aes_init));
        bufp->chgWData(oldp+518,(vlSelfRef.tb_crypto_ops__DOT__aes_nonce),128);
        bufp->chgQData(oldp+522,(vlSelfRef.tb_crypto_ops__DOT__aes_counter_init),64);
        bufp->chgWData(oldp+524,(vlSelfRef.tb_crypto_ops__DOT__aes_data_in),128);
        bufp->chgIData(oldp+528,(vlSelfRef.tb_crypto_ops__DOT__error_count),32);
        bufp->chgIData(oldp+529,(vlSelfRef.tb_crypto_ops__DOT__test_count),32);
        bufp->chgIData(oldp+530,(vlSelfRef.tb_crypto_ops__DOT__pass_count),32);
        bufp->chgBit(oldp+531,(vlSelfRef.tb_crypto_ops__DOT__test_passed));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+532,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_derive));
        bufp->chgWData(oldp+533,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_context),256);
        bufp->chgBit(oldp+541,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_enable));
        bufp->chgBit(oldp+542,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_zeroize));
        bufp->chgBit(oldp+543,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_enroll_internal));
        bufp->chgBit(oldp+544,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_regenerate_internal));
        bufp->chgBit(oldp+545,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_enroll_internal));
        bufp->chgCData(oldp+546,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__next_state),3);
        bufp->chgCData(oldp+547,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__next_state),3);
        bufp->chgCData(oldp+548,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__next_state),2);
        bufp->chgCData(oldp+549,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state),3);
        bufp->chgCData(oldp+550,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__next_state),2);
        bufp->chgIData(oldp+551,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[0]),32);
        bufp->chgIData(oldp+552,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[1]),32);
        bufp->chgIData(oldp+553,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[2]),32);
        bufp->chgIData(oldp+554,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[3]),32);
        bufp->chgIData(oldp+555,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[4]),32);
        bufp->chgIData(oldp+556,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[5]),32);
        bufp->chgIData(oldp+557,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[6]),32);
        bufp->chgIData(oldp+558,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H_next[7]),32);
        bufp->chgIData(oldp+559,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[0]),32);
        bufp->chgIData(oldp+560,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[1]),32);
        bufp->chgIData(oldp+561,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[2]),32);
        bufp->chgIData(oldp+562,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[3]),32);
        bufp->chgIData(oldp+563,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[4]),32);
        bufp->chgIData(oldp+564,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[5]),32);
        bufp->chgIData(oldp+565,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[6]),32);
        bufp->chgIData(oldp+566,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[7]),32);
        bufp->chgIData(oldp+567,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[8]),32);
        bufp->chgIData(oldp+568,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[9]),32);
        bufp->chgIData(oldp+569,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[10]),32);
        bufp->chgIData(oldp+570,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[11]),32);
        bufp->chgIData(oldp+571,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[12]),32);
        bufp->chgIData(oldp+572,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[13]),32);
        bufp->chgIData(oldp+573,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[14]),32);
        bufp->chgIData(oldp+574,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[15]),32);
        bufp->chgIData(oldp+575,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[16]),32);
        bufp->chgIData(oldp+576,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[17]),32);
        bufp->chgIData(oldp+577,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[18]),32);
        bufp->chgIData(oldp+578,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[19]),32);
        bufp->chgIData(oldp+579,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[20]),32);
        bufp->chgIData(oldp+580,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[21]),32);
        bufp->chgIData(oldp+581,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[22]),32);
        bufp->chgIData(oldp+582,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[23]),32);
        bufp->chgIData(oldp+583,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[24]),32);
        bufp->chgIData(oldp+584,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[25]),32);
        bufp->chgIData(oldp+585,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[26]),32);
        bufp->chgIData(oldp+586,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[27]),32);
        bufp->chgIData(oldp+587,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[28]),32);
        bufp->chgIData(oldp+588,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[29]),32);
        bufp->chgIData(oldp+589,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[30]),32);
        bufp->chgIData(oldp+590,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[31]),32);
        bufp->chgIData(oldp+591,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[32]),32);
        bufp->chgIData(oldp+592,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[33]),32);
        bufp->chgIData(oldp+593,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[34]),32);
        bufp->chgIData(oldp+594,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[35]),32);
        bufp->chgIData(oldp+595,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[36]),32);
        bufp->chgIData(oldp+596,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[37]),32);
        bufp->chgIData(oldp+597,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[38]),32);
        bufp->chgIData(oldp+598,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[39]),32);
        bufp->chgIData(oldp+599,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[40]),32);
        bufp->chgIData(oldp+600,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[41]),32);
        bufp->chgIData(oldp+601,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[42]),32);
        bufp->chgIData(oldp+602,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[43]),32);
        bufp->chgIData(oldp+603,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[44]),32);
        bufp->chgIData(oldp+604,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[45]),32);
        bufp->chgIData(oldp+605,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[46]),32);
        bufp->chgIData(oldp+606,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[47]),32);
        bufp->chgIData(oldp+607,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[48]),32);
        bufp->chgIData(oldp+608,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[49]),32);
        bufp->chgIData(oldp+609,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[50]),32);
        bufp->chgIData(oldp+610,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[51]),32);
        bufp->chgIData(oldp+611,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[52]),32);
        bufp->chgIData(oldp+612,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[53]),32);
        bufp->chgIData(oldp+613,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[54]),32);
        bufp->chgIData(oldp+614,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[55]),32);
        bufp->chgIData(oldp+615,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[56]),32);
        bufp->chgIData(oldp+616,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[57]),32);
        bufp->chgIData(oldp+617,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[58]),32);
        bufp->chgIData(oldp+618,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[59]),32);
        bufp->chgIData(oldp+619,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[60]),32);
        bufp->chgIData(oldp+620,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[61]),32);
        bufp->chgIData(oldp+621,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[62]),32);
        bufp->chgIData(oldp+622,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W_next[63]),32);
        bufp->chgIData(oldp+623,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+624,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk5__DOT__i),32);
        bufp->chgIData(oldp+625,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk9__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgWData(oldp+626,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__helper_data_reg),256);
        bufp->chgWData(oldp+634,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__device_id_reg),128);
        bufp->chgBit(oldp+638,((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))));
        bufp->chgBit(oldp+639,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))));
        bufp->chgBit(oldp+640,((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))));
        __Vtemp_6[0U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [7U];
        __Vtemp_6[1U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [6U];
        __Vtemp_6[2U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [5U];
        __Vtemp_6[3U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [4U];
        __Vtemp_6[4U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [3U];
        __Vtemp_6[5U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
            [2U];
        __Vtemp_6[6U] = (IData)((((QData)((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
                                                  [0U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
                                                              [1U]))));
        __Vtemp_6[7U] = (IData)(((((QData)((IData)(
                                                   vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
                                                   [0U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H
                                                               [1U]))) 
                                 >> 0x20U));
        bufp->chgWData(oldp+641,(__Vtemp_6),256);
        bufp->chgBit(oldp+649,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state))));
        bufp->chgBit(oldp+650,((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state))));
        bufp->chgWData(oldp+651,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__mac_reg),256);
        bufp->chgBit(oldp+659,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state))));
        bufp->chgBit(oldp+660,((4U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state))));
        bufp->chgWData(oldp+661,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__data_out_reg),128);
        bufp->chgBit(oldp+665,((7U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state))));
        bufp->chgBit(oldp+666,(((8U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state)) 
                                | ((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state)) 
                                   & (0x20U < (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count))))));
        bufp->chgWData(oldp+667,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__secret_reg),256);
        bufp->chgBit(oldp+675,((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))));
        bufp->chgBit(oldp+676,(((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state)) 
                                & (0x20U < (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count)))));
        bufp->chgBit(oldp+677,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state))));
        bufp->chgBit(oldp+678,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state))));
        bufp->chgBit(oldp+679,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__enrolled));
        bufp->chgBit(oldp+680,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal));
        bufp->chgCData(oldp+681,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_state),4);
        bufp->chgBit(oldp+682,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__dus_valid_latched));
        bufp->chgBit(oldp+683,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__enroll_mode_latched));
        bufp->chgBit(oldp+684,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_keys_valid_latched));
        bufp->chgBit(oldp+685,(((0U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state)) 
                                & (4U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state)))));
        bufp->chgCData(oldp+686,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__state),3);
        bufp->chgCData(oldp+687,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [0U][0U]),8);
        bufp->chgCData(oldp+688,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [0U][1U]),8);
        bufp->chgCData(oldp+689,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [0U][2U]),8);
        bufp->chgCData(oldp+690,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [0U][3U]),8);
        bufp->chgCData(oldp+691,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [1U][0U]),8);
        bufp->chgCData(oldp+692,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [1U][1U]),8);
        bufp->chgCData(oldp+693,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [1U][2U]),8);
        bufp->chgCData(oldp+694,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [1U][3U]),8);
        bufp->chgCData(oldp+695,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [2U][0U]),8);
        bufp->chgCData(oldp+696,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [2U][1U]),8);
        bufp->chgCData(oldp+697,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [2U][2U]),8);
        bufp->chgCData(oldp+698,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [2U][3U]),8);
        bufp->chgCData(oldp+699,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [3U][0U]),8);
        bufp->chgCData(oldp+700,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [3U][1U]),8);
        bufp->chgCData(oldp+701,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [3U][2U]),8);
        bufp->chgCData(oldp+702,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state
                                 [3U][3U]),8);
        bufp->chgCData(oldp+703,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [0U][0U]),8);
        bufp->chgCData(oldp+704,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [0U][1U]),8);
        bufp->chgCData(oldp+705,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [0U][2U]),8);
        bufp->chgCData(oldp+706,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [0U][3U]),8);
        bufp->chgCData(oldp+707,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [1U][0U]),8);
        bufp->chgCData(oldp+708,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [1U][1U]),8);
        bufp->chgCData(oldp+709,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [1U][2U]),8);
        bufp->chgCData(oldp+710,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [1U][3U]),8);
        bufp->chgCData(oldp+711,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [2U][0U]),8);
        bufp->chgCData(oldp+712,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [2U][1U]),8);
        bufp->chgCData(oldp+713,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [2U][2U]),8);
        bufp->chgCData(oldp+714,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [2U][3U]),8);
        bufp->chgCData(oldp+715,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [3U][0U]),8);
        bufp->chgCData(oldp+716,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [3U][1U]),8);
        bufp->chgCData(oldp+717,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [3U][2U]),8);
        bufp->chgCData(oldp+718,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_state_next
                                 [3U][3U]),8);
        bufp->chgWData(oldp+719,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[0]),128);
        bufp->chgWData(oldp+723,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[1]),128);
        bufp->chgWData(oldp+727,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[2]),128);
        bufp->chgWData(oldp+731,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[3]),128);
        bufp->chgWData(oldp+735,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[4]),128);
        bufp->chgWData(oldp+739,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[5]),128);
        bufp->chgWData(oldp+743,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[6]),128);
        bufp->chgWData(oldp+747,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[7]),128);
        bufp->chgWData(oldp+751,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[8]),128);
        bufp->chgWData(oldp+755,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[9]),128);
        bufp->chgWData(oldp+759,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[10]),128);
        bufp->chgWData(oldp+763,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[11]),128);
        bufp->chgWData(oldp+767,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[12]),128);
        bufp->chgWData(oldp+771,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[13]),128);
        bufp->chgWData(oldp+775,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round_keys[14]),128);
        bufp->chgCData(oldp+779,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__round),4);
        bufp->chgWData(oldp+780,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__counter),128);
        bufp->chgWData(oldp+784,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__keystream),128);
        bufp->chgBit(oldp+788,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__init_latched));
        bufp->chgCData(oldp+789,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__key_exp_stage),3);
        bufp->chgBit(oldp+790,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__keys_packed));
        bufp->chgIData(oldp+791,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[0]),32);
        bufp->chgIData(oldp+792,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[1]),32);
        bufp->chgIData(oldp+793,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[2]),32);
        bufp->chgIData(oldp+794,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[3]),32);
        bufp->chgIData(oldp+795,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[4]),32);
        bufp->chgIData(oldp+796,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[5]),32);
        bufp->chgIData(oldp+797,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[6]),32);
        bufp->chgIData(oldp+798,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[7]),32);
        bufp->chgIData(oldp+799,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[8]),32);
        bufp->chgIData(oldp+800,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[9]),32);
        bufp->chgIData(oldp+801,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[10]),32);
        bufp->chgIData(oldp+802,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[11]),32);
        bufp->chgIData(oldp+803,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[12]),32);
        bufp->chgIData(oldp+804,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[13]),32);
        bufp->chgIData(oldp+805,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[14]),32);
        bufp->chgIData(oldp+806,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[15]),32);
        bufp->chgIData(oldp+807,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[16]),32);
        bufp->chgIData(oldp+808,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[17]),32);
        bufp->chgIData(oldp+809,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[18]),32);
        bufp->chgIData(oldp+810,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[19]),32);
        bufp->chgIData(oldp+811,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[20]),32);
        bufp->chgIData(oldp+812,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[21]),32);
        bufp->chgIData(oldp+813,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[22]),32);
        bufp->chgIData(oldp+814,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[23]),32);
        bufp->chgIData(oldp+815,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[24]),32);
        bufp->chgIData(oldp+816,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[25]),32);
        bufp->chgIData(oldp+817,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[26]),32);
        bufp->chgIData(oldp+818,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[27]),32);
        bufp->chgIData(oldp+819,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[28]),32);
        bufp->chgIData(oldp+820,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[29]),32);
        bufp->chgIData(oldp+821,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[30]),32);
        bufp->chgIData(oldp+822,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[31]),32);
        bufp->chgIData(oldp+823,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[32]),32);
        bufp->chgIData(oldp+824,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[33]),32);
        bufp->chgIData(oldp+825,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[34]),32);
        bufp->chgIData(oldp+826,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[35]),32);
        bufp->chgIData(oldp+827,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[36]),32);
        bufp->chgIData(oldp+828,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[37]),32);
        bufp->chgIData(oldp+829,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[38]),32);
        bufp->chgIData(oldp+830,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[39]),32);
        bufp->chgIData(oldp+831,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[40]),32);
        bufp->chgIData(oldp+832,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[41]),32);
        bufp->chgIData(oldp+833,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[42]),32);
        bufp->chgIData(oldp+834,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[43]),32);
        bufp->chgIData(oldp+835,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[44]),32);
        bufp->chgIData(oldp+836,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[45]),32);
        bufp->chgIData(oldp+837,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[46]),32);
        bufp->chgIData(oldp+838,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[47]),32);
        bufp->chgIData(oldp+839,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[48]),32);
        bufp->chgIData(oldp+840,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[49]),32);
        bufp->chgIData(oldp+841,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[50]),32);
        bufp->chgIData(oldp+842,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[51]),32);
        bufp->chgIData(oldp+843,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[52]),32);
        bufp->chgIData(oldp+844,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[53]),32);
        bufp->chgIData(oldp+845,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[54]),32);
        bufp->chgIData(oldp+846,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[55]),32);
        bufp->chgIData(oldp+847,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[56]),32);
        bufp->chgIData(oldp+848,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[57]),32);
        bufp->chgIData(oldp+849,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[58]),32);
        bufp->chgIData(oldp+850,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__w[59]),32);
        bufp->chgWData(oldp+851,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__aes_output),128);
        bufp->chgIData(oldp+855,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+856,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [0U][0U]),8);
        bufp->chgCData(oldp+857,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [0U][1U]),8);
        bufp->chgCData(oldp+858,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [0U][2U]),8);
        bufp->chgCData(oldp+859,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [0U][3U]),8);
        bufp->chgCData(oldp+860,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [1U][0U]),8);
        bufp->chgCData(oldp+861,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [1U][1U]),8);
        bufp->chgCData(oldp+862,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [1U][2U]),8);
        bufp->chgCData(oldp+863,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [1U][3U]),8);
        bufp->chgCData(oldp+864,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [2U][0U]),8);
        bufp->chgCData(oldp+865,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [2U][1U]),8);
        bufp->chgCData(oldp+866,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [2U][2U]),8);
        bufp->chgCData(oldp+867,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [2U][3U]),8);
        bufp->chgCData(oldp+868,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [3U][0U]),8);
        bufp->chgCData(oldp+869,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [3U][1U]),8);
        bufp->chgCData(oldp+870,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [3U][2U]),8);
        bufp->chgCData(oldp+871,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_subbytes
                                 [3U][3U]),8);
        bufp->chgCData(oldp+872,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [0U][0U]),8);
        bufp->chgCData(oldp+873,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [0U][1U]),8);
        bufp->chgCData(oldp+874,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [0U][2U]),8);
        bufp->chgCData(oldp+875,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [0U][3U]),8);
        bufp->chgCData(oldp+876,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [1U][0U]),8);
        bufp->chgCData(oldp+877,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [1U][1U]),8);
        bufp->chgCData(oldp+878,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [1U][2U]),8);
        bufp->chgCData(oldp+879,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [1U][3U]),8);
        bufp->chgCData(oldp+880,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [2U][0U]),8);
        bufp->chgCData(oldp+881,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [2U][1U]),8);
        bufp->chgCData(oldp+882,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [2U][2U]),8);
        bufp->chgCData(oldp+883,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [2U][3U]),8);
        bufp->chgCData(oldp+884,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [3U][0U]),8);
        bufp->chgCData(oldp+885,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [3U][1U]),8);
        bufp->chgCData(oldp+886,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [3U][2U]),8);
        bufp->chgCData(oldp+887,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_shiftrows
                                 [3U][3U]),8);
        bufp->chgCData(oldp+888,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [0U][0U]),8);
        bufp->chgCData(oldp+889,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [0U][1U]),8);
        bufp->chgCData(oldp+890,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [0U][2U]),8);
        bufp->chgCData(oldp+891,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [0U][3U]),8);
        bufp->chgCData(oldp+892,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [1U][0U]),8);
        bufp->chgCData(oldp+893,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [1U][1U]),8);
        bufp->chgCData(oldp+894,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [1U][2U]),8);
        bufp->chgCData(oldp+895,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [1U][3U]),8);
        bufp->chgCData(oldp+896,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [2U][0U]),8);
        bufp->chgCData(oldp+897,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [2U][1U]),8);
        bufp->chgCData(oldp+898,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [2U][2U]),8);
        bufp->chgCData(oldp+899,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [2U][3U]),8);
        bufp->chgCData(oldp+900,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [3U][0U]),8);
        bufp->chgCData(oldp+901,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [3U][1U]),8);
        bufp->chgCData(oldp+902,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [3U][2U]),8);
        bufp->chgCData(oldp+903,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__after_mixcol
                                 [3U][3U]),8);
        bufp->chgIData(oldp+904,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__j),32);
        bufp->chgCData(oldp+905,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__a),8);
        bufp->chgCData(oldp+906,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__b),8);
        bufp->chgCData(oldp+907,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__c),8);
        bufp->chgCData(oldp+908,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk10__DOT__unnamedblk13__DOT__unnamedblk14__DOT__d),8);
        bufp->chgIData(oldp+909,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+910,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk3__DOT__r),32);
        bufp->chgIData(oldp+911,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+912,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j),32);
        bufp->chgIData(oldp+913,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk6__DOT__i),32);
        bufp->chgIData(oldp+914,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+915,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk7__DOT__unnamedblk8__DOT__j),32);
        bufp->chgIData(oldp+916,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_inst__DOT__unnamedblk9__DOT__i),32);
        bufp->chgBit(oldp+917,(((0U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state)) 
                                & (5U != (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state)))));
        bufp->chgCData(oldp+918,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__state),3);
        bufp->chgBit(oldp+919,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_start));
        bufp->chgBit(oldp+920,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_init));
        bufp->chgBit(oldp+921,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))));
        bufp->chgBit(oldp+922,((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))));
        bufp->chgWData(oldp+923,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_message),512);
        bufp->chgWData(oldp+939,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_hash),256);
        bufp->chgWData(oldp+947,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__inner_hash),256);
        bufp->chgBit(oldp+955,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__first_message_block));
        bufp->chgBit(oldp+956,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__is_final_block));
        bufp->chgCData(oldp+957,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state),2);
        bufp->chgCData(oldp+958,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__next_state),2);
        bufp->chgIData(oldp+959,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a),32);
        bufp->chgIData(oldp+960,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b),32);
        bufp->chgIData(oldp+961,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c),32);
        bufp->chgIData(oldp+962,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d),32);
        bufp->chgIData(oldp+963,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e),32);
        bufp->chgIData(oldp+964,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f),32);
        bufp->chgIData(oldp+965,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g),32);
        bufp->chgIData(oldp+966,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h),32);
        bufp->chgIData(oldp+967,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__a_next),32);
        bufp->chgIData(oldp+968,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__b_next),32);
        bufp->chgIData(oldp+969,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__c_next),32);
        bufp->chgIData(oldp+970,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__d_next),32);
        bufp->chgIData(oldp+971,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__e_next),32);
        bufp->chgIData(oldp+972,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__f_next),32);
        bufp->chgIData(oldp+973,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__g_next),32);
        bufp->chgIData(oldp+974,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__h_next),32);
        bufp->chgIData(oldp+975,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[0]),32);
        bufp->chgIData(oldp+976,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[1]),32);
        bufp->chgIData(oldp+977,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[2]),32);
        bufp->chgIData(oldp+978,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[3]),32);
        bufp->chgIData(oldp+979,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[4]),32);
        bufp->chgIData(oldp+980,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[5]),32);
        bufp->chgIData(oldp+981,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[6]),32);
        bufp->chgIData(oldp+982,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H[7]),32);
        bufp->chgIData(oldp+983,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[0]),32);
        bufp->chgIData(oldp+984,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[1]),32);
        bufp->chgIData(oldp+985,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[2]),32);
        bufp->chgIData(oldp+986,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[3]),32);
        bufp->chgIData(oldp+987,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[4]),32);
        bufp->chgIData(oldp+988,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[5]),32);
        bufp->chgIData(oldp+989,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[6]),32);
        bufp->chgIData(oldp+990,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__H_next[7]),32);
        bufp->chgIData(oldp+991,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[0]),32);
        bufp->chgIData(oldp+992,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[1]),32);
        bufp->chgIData(oldp+993,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[2]),32);
        bufp->chgIData(oldp+994,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[3]),32);
        bufp->chgIData(oldp+995,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[4]),32);
        bufp->chgIData(oldp+996,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[5]),32);
        bufp->chgIData(oldp+997,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[6]),32);
        bufp->chgIData(oldp+998,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[7]),32);
        bufp->chgIData(oldp+999,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[8]),32);
        bufp->chgIData(oldp+1000,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[9]),32);
        bufp->chgIData(oldp+1001,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[10]),32);
        bufp->chgIData(oldp+1002,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[11]),32);
        bufp->chgIData(oldp+1003,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[12]),32);
        bufp->chgIData(oldp+1004,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[13]),32);
        bufp->chgIData(oldp+1005,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[14]),32);
        bufp->chgIData(oldp+1006,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[15]),32);
        bufp->chgIData(oldp+1007,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[16]),32);
        bufp->chgIData(oldp+1008,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[17]),32);
        bufp->chgIData(oldp+1009,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[18]),32);
        bufp->chgIData(oldp+1010,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[19]),32);
        bufp->chgIData(oldp+1011,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[20]),32);
        bufp->chgIData(oldp+1012,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[21]),32);
        bufp->chgIData(oldp+1013,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[22]),32);
        bufp->chgIData(oldp+1014,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[23]),32);
        bufp->chgIData(oldp+1015,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[24]),32);
        bufp->chgIData(oldp+1016,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[25]),32);
        bufp->chgIData(oldp+1017,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[26]),32);
        bufp->chgIData(oldp+1018,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[27]),32);
        bufp->chgIData(oldp+1019,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[28]),32);
        bufp->chgIData(oldp+1020,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[29]),32);
        bufp->chgIData(oldp+1021,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[30]),32);
        bufp->chgIData(oldp+1022,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[31]),32);
        bufp->chgIData(oldp+1023,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[32]),32);
        bufp->chgIData(oldp+1024,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[33]),32);
        bufp->chgIData(oldp+1025,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[34]),32);
        bufp->chgIData(oldp+1026,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[35]),32);
        bufp->chgIData(oldp+1027,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[36]),32);
        bufp->chgIData(oldp+1028,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[37]),32);
        bufp->chgIData(oldp+1029,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[38]),32);
        bufp->chgIData(oldp+1030,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[39]),32);
        bufp->chgIData(oldp+1031,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[40]),32);
        bufp->chgIData(oldp+1032,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[41]),32);
        bufp->chgIData(oldp+1033,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[42]),32);
        bufp->chgIData(oldp+1034,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[43]),32);
        bufp->chgIData(oldp+1035,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[44]),32);
        bufp->chgIData(oldp+1036,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[45]),32);
        bufp->chgIData(oldp+1037,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[46]),32);
        bufp->chgIData(oldp+1038,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[47]),32);
        bufp->chgIData(oldp+1039,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[48]),32);
        bufp->chgIData(oldp+1040,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[49]),32);
        bufp->chgIData(oldp+1041,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[50]),32);
        bufp->chgIData(oldp+1042,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[51]),32);
        bufp->chgIData(oldp+1043,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[52]),32);
        bufp->chgIData(oldp+1044,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[53]),32);
        bufp->chgIData(oldp+1045,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[54]),32);
        bufp->chgIData(oldp+1046,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[55]),32);
        bufp->chgIData(oldp+1047,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[56]),32);
        bufp->chgIData(oldp+1048,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[57]),32);
        bufp->chgIData(oldp+1049,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[58]),32);
        bufp->chgIData(oldp+1050,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[59]),32);
        bufp->chgIData(oldp+1051,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[60]),32);
        bufp->chgIData(oldp+1052,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[61]),32);
        bufp->chgIData(oldp+1053,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[62]),32);
        bufp->chgIData(oldp+1054,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W[63]),32);
        bufp->chgIData(oldp+1055,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[0]),32);
        bufp->chgIData(oldp+1056,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[1]),32);
        bufp->chgIData(oldp+1057,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[2]),32);
        bufp->chgIData(oldp+1058,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[3]),32);
        bufp->chgIData(oldp+1059,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[4]),32);
        bufp->chgIData(oldp+1060,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[5]),32);
        bufp->chgIData(oldp+1061,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[6]),32);
        bufp->chgIData(oldp+1062,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[7]),32);
        bufp->chgIData(oldp+1063,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[8]),32);
        bufp->chgIData(oldp+1064,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[9]),32);
        bufp->chgIData(oldp+1065,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[10]),32);
        bufp->chgIData(oldp+1066,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[11]),32);
        bufp->chgIData(oldp+1067,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[12]),32);
        bufp->chgIData(oldp+1068,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[13]),32);
        bufp->chgIData(oldp+1069,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[14]),32);
        bufp->chgIData(oldp+1070,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[15]),32);
        bufp->chgIData(oldp+1071,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[16]),32);
        bufp->chgIData(oldp+1072,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[17]),32);
        bufp->chgIData(oldp+1073,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[18]),32);
        bufp->chgIData(oldp+1074,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[19]),32);
        bufp->chgIData(oldp+1075,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[20]),32);
        bufp->chgIData(oldp+1076,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[21]),32);
        bufp->chgIData(oldp+1077,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[22]),32);
        bufp->chgIData(oldp+1078,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[23]),32);
        bufp->chgIData(oldp+1079,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[24]),32);
        bufp->chgIData(oldp+1080,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[25]),32);
        bufp->chgIData(oldp+1081,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[26]),32);
        bufp->chgIData(oldp+1082,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[27]),32);
        bufp->chgIData(oldp+1083,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[28]),32);
        bufp->chgIData(oldp+1084,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[29]),32);
        bufp->chgIData(oldp+1085,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[30]),32);
        bufp->chgIData(oldp+1086,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[31]),32);
        bufp->chgIData(oldp+1087,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[32]),32);
        bufp->chgIData(oldp+1088,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[33]),32);
        bufp->chgIData(oldp+1089,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[34]),32);
        bufp->chgIData(oldp+1090,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[35]),32);
        bufp->chgIData(oldp+1091,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[36]),32);
        bufp->chgIData(oldp+1092,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[37]),32);
        bufp->chgIData(oldp+1093,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[38]),32);
        bufp->chgIData(oldp+1094,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[39]),32);
        bufp->chgIData(oldp+1095,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[40]),32);
        bufp->chgIData(oldp+1096,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[41]),32);
        bufp->chgIData(oldp+1097,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[42]),32);
        bufp->chgIData(oldp+1098,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[43]),32);
        bufp->chgIData(oldp+1099,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[44]),32);
        bufp->chgIData(oldp+1100,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[45]),32);
        bufp->chgIData(oldp+1101,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[46]),32);
        bufp->chgIData(oldp+1102,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[47]),32);
        bufp->chgIData(oldp+1103,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[48]),32);
        bufp->chgIData(oldp+1104,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[49]),32);
        bufp->chgIData(oldp+1105,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[50]),32);
        bufp->chgIData(oldp+1106,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[51]),32);
        bufp->chgIData(oldp+1107,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[52]),32);
        bufp->chgIData(oldp+1108,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[53]),32);
        bufp->chgIData(oldp+1109,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[54]),32);
        bufp->chgIData(oldp+1110,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[55]),32);
        bufp->chgIData(oldp+1111,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[56]),32);
        bufp->chgIData(oldp+1112,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[57]),32);
        bufp->chgIData(oldp+1113,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[58]),32);
        bufp->chgIData(oldp+1114,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[59]),32);
        bufp->chgIData(oldp+1115,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[60]),32);
        bufp->chgIData(oldp+1116,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[61]),32);
        bufp->chgIData(oldp+1117,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[62]),32);
        bufp->chgIData(oldp+1118,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__W_next[63]),32);
        bufp->chgCData(oldp+1119,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round),6);
        bufp->chgCData(oldp+1120,(((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__state))
                                    ? (0x3fU & ((IData)(1U) 
                                                + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__round)))
                                    : 0U)),6);
        bufp->chgIData(oldp+1121,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T1),32);
        bufp->chgIData(oldp+1122,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__T2),32);
        bufp->chgIData(oldp+1123,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1124,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+1125,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+1126,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i),32);
        bufp->chgIData(oldp+1127,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk6__DOT__i),32);
        bufp->chgIData(oldp+1128,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+1129,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i),32);
        bufp->chgBit(oldp+1130,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_start));
        bufp->chgBit(oldp+1131,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_init));
        bufp->chgBit(oldp+1132,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))));
        bufp->chgBit(oldp+1133,((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))));
        bufp->chgWData(oldp+1134,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_message),512);
        bufp->chgWData(oldp+1150,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__prk),256);
        bufp->chgWData(oldp+1158,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__t_prev),256);
        bufp->chgWData(oldp+1166,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__ipad_key),256);
        bufp->chgWData(oldp+1174,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__opad_key),256);
        bufp->chgWData(oldp+1182,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__inner_hash),256);
        bufp->chgCData(oldp+1190,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__block_count),3);
        bufp->chgCData(oldp+1191,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state),2);
        bufp->chgCData(oldp+1192,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__next_state),2);
        bufp->chgIData(oldp+1193,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a),32);
        bufp->chgIData(oldp+1194,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b),32);
        bufp->chgIData(oldp+1195,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c),32);
        bufp->chgIData(oldp+1196,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d),32);
        bufp->chgIData(oldp+1197,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e),32);
        bufp->chgIData(oldp+1198,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f),32);
        bufp->chgIData(oldp+1199,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g),32);
        bufp->chgIData(oldp+1200,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h),32);
        bufp->chgIData(oldp+1201,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__a_next),32);
        bufp->chgIData(oldp+1202,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__b_next),32);
        bufp->chgIData(oldp+1203,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__c_next),32);
        bufp->chgIData(oldp+1204,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__d_next),32);
        bufp->chgIData(oldp+1205,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__e_next),32);
        bufp->chgIData(oldp+1206,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__f_next),32);
        bufp->chgIData(oldp+1207,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__g_next),32);
        bufp->chgIData(oldp+1208,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__h_next),32);
        bufp->chgIData(oldp+1209,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[0]),32);
        bufp->chgIData(oldp+1210,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[1]),32);
        bufp->chgIData(oldp+1211,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[2]),32);
        bufp->chgIData(oldp+1212,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[3]),32);
        bufp->chgIData(oldp+1213,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[4]),32);
        bufp->chgIData(oldp+1214,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[5]),32);
        bufp->chgIData(oldp+1215,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[6]),32);
        bufp->chgIData(oldp+1216,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H[7]),32);
        bufp->chgIData(oldp+1217,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[0]),32);
        bufp->chgIData(oldp+1218,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[1]),32);
        bufp->chgIData(oldp+1219,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[2]),32);
        bufp->chgIData(oldp+1220,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[3]),32);
        bufp->chgIData(oldp+1221,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[4]),32);
        bufp->chgIData(oldp+1222,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[5]),32);
        bufp->chgIData(oldp+1223,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[6]),32);
        bufp->chgIData(oldp+1224,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__H_next[7]),32);
        bufp->chgIData(oldp+1225,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[0]),32);
        bufp->chgIData(oldp+1226,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[1]),32);
        bufp->chgIData(oldp+1227,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[2]),32);
        bufp->chgIData(oldp+1228,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[3]),32);
        bufp->chgIData(oldp+1229,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[4]),32);
        bufp->chgIData(oldp+1230,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[5]),32);
        bufp->chgIData(oldp+1231,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[6]),32);
        bufp->chgIData(oldp+1232,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[7]),32);
        bufp->chgIData(oldp+1233,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[8]),32);
        bufp->chgIData(oldp+1234,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[9]),32);
        bufp->chgIData(oldp+1235,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[10]),32);
        bufp->chgIData(oldp+1236,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[11]),32);
        bufp->chgIData(oldp+1237,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[12]),32);
        bufp->chgIData(oldp+1238,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[13]),32);
        bufp->chgIData(oldp+1239,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[14]),32);
        bufp->chgIData(oldp+1240,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[15]),32);
        bufp->chgIData(oldp+1241,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[16]),32);
        bufp->chgIData(oldp+1242,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[17]),32);
        bufp->chgIData(oldp+1243,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[18]),32);
        bufp->chgIData(oldp+1244,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[19]),32);
        bufp->chgIData(oldp+1245,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[20]),32);
        bufp->chgIData(oldp+1246,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[21]),32);
        bufp->chgIData(oldp+1247,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[22]),32);
        bufp->chgIData(oldp+1248,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[23]),32);
        bufp->chgIData(oldp+1249,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[24]),32);
        bufp->chgIData(oldp+1250,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[25]),32);
        bufp->chgIData(oldp+1251,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[26]),32);
        bufp->chgIData(oldp+1252,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[27]),32);
        bufp->chgIData(oldp+1253,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[28]),32);
        bufp->chgIData(oldp+1254,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[29]),32);
        bufp->chgIData(oldp+1255,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[30]),32);
        bufp->chgIData(oldp+1256,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[31]),32);
        bufp->chgIData(oldp+1257,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[32]),32);
        bufp->chgIData(oldp+1258,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[33]),32);
        bufp->chgIData(oldp+1259,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[34]),32);
        bufp->chgIData(oldp+1260,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[35]),32);
        bufp->chgIData(oldp+1261,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[36]),32);
        bufp->chgIData(oldp+1262,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[37]),32);
        bufp->chgIData(oldp+1263,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[38]),32);
        bufp->chgIData(oldp+1264,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[39]),32);
        bufp->chgIData(oldp+1265,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[40]),32);
        bufp->chgIData(oldp+1266,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[41]),32);
        bufp->chgIData(oldp+1267,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[42]),32);
        bufp->chgIData(oldp+1268,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[43]),32);
        bufp->chgIData(oldp+1269,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[44]),32);
        bufp->chgIData(oldp+1270,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[45]),32);
        bufp->chgIData(oldp+1271,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[46]),32);
        bufp->chgIData(oldp+1272,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[47]),32);
        bufp->chgIData(oldp+1273,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[48]),32);
        bufp->chgIData(oldp+1274,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[49]),32);
        bufp->chgIData(oldp+1275,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[50]),32);
        bufp->chgIData(oldp+1276,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[51]),32);
        bufp->chgIData(oldp+1277,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[52]),32);
        bufp->chgIData(oldp+1278,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[53]),32);
        bufp->chgIData(oldp+1279,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[54]),32);
        bufp->chgIData(oldp+1280,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[55]),32);
        bufp->chgIData(oldp+1281,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[56]),32);
        bufp->chgIData(oldp+1282,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[57]),32);
        bufp->chgIData(oldp+1283,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[58]),32);
        bufp->chgIData(oldp+1284,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[59]),32);
        bufp->chgIData(oldp+1285,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[60]),32);
        bufp->chgIData(oldp+1286,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[61]),32);
        bufp->chgIData(oldp+1287,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[62]),32);
        bufp->chgIData(oldp+1288,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W[63]),32);
        bufp->chgIData(oldp+1289,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[0]),32);
        bufp->chgIData(oldp+1290,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[1]),32);
        bufp->chgIData(oldp+1291,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[2]),32);
        bufp->chgIData(oldp+1292,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[3]),32);
        bufp->chgIData(oldp+1293,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[4]),32);
        bufp->chgIData(oldp+1294,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[5]),32);
        bufp->chgIData(oldp+1295,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[6]),32);
        bufp->chgIData(oldp+1296,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[7]),32);
        bufp->chgIData(oldp+1297,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[8]),32);
        bufp->chgIData(oldp+1298,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[9]),32);
        bufp->chgIData(oldp+1299,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[10]),32);
        bufp->chgIData(oldp+1300,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[11]),32);
        bufp->chgIData(oldp+1301,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[12]),32);
        bufp->chgIData(oldp+1302,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[13]),32);
        bufp->chgIData(oldp+1303,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[14]),32);
        bufp->chgIData(oldp+1304,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[15]),32);
        bufp->chgIData(oldp+1305,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[16]),32);
        bufp->chgIData(oldp+1306,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[17]),32);
        bufp->chgIData(oldp+1307,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[18]),32);
        bufp->chgIData(oldp+1308,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[19]),32);
        bufp->chgIData(oldp+1309,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[20]),32);
        bufp->chgIData(oldp+1310,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[21]),32);
        bufp->chgIData(oldp+1311,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[22]),32);
        bufp->chgIData(oldp+1312,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[23]),32);
        bufp->chgIData(oldp+1313,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[24]),32);
        bufp->chgIData(oldp+1314,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[25]),32);
        bufp->chgIData(oldp+1315,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[26]),32);
        bufp->chgIData(oldp+1316,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[27]),32);
        bufp->chgIData(oldp+1317,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[28]),32);
        bufp->chgIData(oldp+1318,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[29]),32);
        bufp->chgIData(oldp+1319,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[30]),32);
        bufp->chgIData(oldp+1320,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[31]),32);
        bufp->chgIData(oldp+1321,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[32]),32);
        bufp->chgIData(oldp+1322,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[33]),32);
        bufp->chgIData(oldp+1323,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[34]),32);
        bufp->chgIData(oldp+1324,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[35]),32);
        bufp->chgIData(oldp+1325,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[36]),32);
        bufp->chgIData(oldp+1326,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[37]),32);
        bufp->chgIData(oldp+1327,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[38]),32);
        bufp->chgIData(oldp+1328,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[39]),32);
        bufp->chgIData(oldp+1329,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[40]),32);
        bufp->chgIData(oldp+1330,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[41]),32);
        bufp->chgIData(oldp+1331,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[42]),32);
        bufp->chgIData(oldp+1332,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[43]),32);
        bufp->chgIData(oldp+1333,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[44]),32);
        bufp->chgIData(oldp+1334,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[45]),32);
        bufp->chgIData(oldp+1335,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[46]),32);
        bufp->chgIData(oldp+1336,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[47]),32);
        bufp->chgIData(oldp+1337,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[48]),32);
        bufp->chgIData(oldp+1338,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[49]),32);
        bufp->chgIData(oldp+1339,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[50]),32);
        bufp->chgIData(oldp+1340,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[51]),32);
        bufp->chgIData(oldp+1341,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[52]),32);
        bufp->chgIData(oldp+1342,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[53]),32);
        bufp->chgIData(oldp+1343,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[54]),32);
        bufp->chgIData(oldp+1344,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[55]),32);
        bufp->chgIData(oldp+1345,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[56]),32);
        bufp->chgIData(oldp+1346,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[57]),32);
        bufp->chgIData(oldp+1347,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[58]),32);
        bufp->chgIData(oldp+1348,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[59]),32);
        bufp->chgIData(oldp+1349,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[60]),32);
        bufp->chgIData(oldp+1350,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[61]),32);
        bufp->chgIData(oldp+1351,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[62]),32);
        bufp->chgIData(oldp+1352,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__W_next[63]),32);
        bufp->chgCData(oldp+1353,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round),6);
        bufp->chgCData(oldp+1354,(((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__state))
                                    ? (0x3fU & ((IData)(1U) 
                                                + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__round)))
                                    : 0U)),6);
        bufp->chgIData(oldp+1355,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T1),32);
        bufp->chgIData(oldp+1356,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__T2),32);
        bufp->chgIData(oldp+1357,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1358,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+1359,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+1360,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk5__DOT__i),32);
        bufp->chgIData(oldp+1361,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk6__DOT__i),32);
        bufp->chgIData(oldp+1362,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+1363,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_inst__DOT__unnamedblk9__DOT__i),32);
        bufp->chgBit(oldp+1364,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_valid_reg));
        bufp->chgBit(oldp+1365,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__keys_locked));
        bufp->chgCData(oldp+1366,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_counter),8);
        bufp->chgBit(oldp+1367,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_fail));
        bufp->chgCData(oldp+1368,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__state),2);
        bufp->chgWData(oldp+1369,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__puf_measurement),128);
        bufp->chgCData(oldp+1373,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__measure_count),8);
        bufp->chgIData(oldp+1374,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__lfsr),32);
        bufp->chgWData(oldp+1375,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk1__DOT__current_sample),128);
        bufp->chgIData(oldp+1379,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i),32);
        bufp->chgWData(oldp+1380,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_inst__DOT__unnamedblk3__DOT__mixed_id),128);
        bufp->chgCData(oldp+1384,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state),3);
        bufp->chgWData(oldp+1385,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__puf_raw),256);
        bufp->chgWData(oldp+1393,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__puf_enrolled),256);
        bufp->chgCData(oldp+1401,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__measure_cycles),8);
        bufp->chgCData(oldp+1402,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__cycle_count),8);
        bufp->chgCData(oldp+1403,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count),8);
        bufp->chgIData(oldp+1404,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__lfsr_noise),32);
        bufp->chgIData(oldp+1405,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__i),32);
        bufp->chgBit(oldp+1406,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__core_bit));
        bufp->chgBit(oldp+1407,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk1__DOT__unnamedblk2__DOT__noise_bit));
        bufp->chgWData(oldp+1408,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk3__DOT__corrected_puf),256);
        bufp->chgWData(oldp+1416,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk3__DOT__syndrome),256);
        bufp->chgWData(oldp+1424,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk4__DOT__syndrome),256);
        bufp->chgIData(oldp+1432,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__unnamedblk4__DOT__unnamedblk5__DOT__i),32);
        bufp->chgCData(oldp+1433,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state),2);
        bufp->chgIData(oldp+1434,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a),32);
        bufp->chgIData(oldp+1435,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b),32);
        bufp->chgIData(oldp+1436,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c),32);
        bufp->chgIData(oldp+1437,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d),32);
        bufp->chgIData(oldp+1438,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e),32);
        bufp->chgIData(oldp+1439,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f),32);
        bufp->chgIData(oldp+1440,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g),32);
        bufp->chgIData(oldp+1441,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h),32);
        bufp->chgIData(oldp+1442,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__a_next),32);
        bufp->chgIData(oldp+1443,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__b_next),32);
        bufp->chgIData(oldp+1444,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__c_next),32);
        bufp->chgIData(oldp+1445,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__d_next),32);
        bufp->chgIData(oldp+1446,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__e_next),32);
        bufp->chgIData(oldp+1447,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__f_next),32);
        bufp->chgIData(oldp+1448,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__g_next),32);
        bufp->chgIData(oldp+1449,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__h_next),32);
        bufp->chgIData(oldp+1450,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[0]),32);
        bufp->chgIData(oldp+1451,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[1]),32);
        bufp->chgIData(oldp+1452,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[2]),32);
        bufp->chgIData(oldp+1453,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[3]),32);
        bufp->chgIData(oldp+1454,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[4]),32);
        bufp->chgIData(oldp+1455,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[5]),32);
        bufp->chgIData(oldp+1456,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[6]),32);
        bufp->chgIData(oldp+1457,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__H[7]),32);
        bufp->chgIData(oldp+1458,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[0]),32);
        bufp->chgIData(oldp+1459,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[1]),32);
        bufp->chgIData(oldp+1460,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[2]),32);
        bufp->chgIData(oldp+1461,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[3]),32);
        bufp->chgIData(oldp+1462,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[4]),32);
        bufp->chgIData(oldp+1463,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[5]),32);
        bufp->chgIData(oldp+1464,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[6]),32);
        bufp->chgIData(oldp+1465,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[7]),32);
        bufp->chgIData(oldp+1466,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[8]),32);
        bufp->chgIData(oldp+1467,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[9]),32);
        bufp->chgIData(oldp+1468,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[10]),32);
        bufp->chgIData(oldp+1469,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[11]),32);
        bufp->chgIData(oldp+1470,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[12]),32);
        bufp->chgIData(oldp+1471,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[13]),32);
        bufp->chgIData(oldp+1472,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[14]),32);
        bufp->chgIData(oldp+1473,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[15]),32);
        bufp->chgIData(oldp+1474,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[16]),32);
        bufp->chgIData(oldp+1475,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[17]),32);
        bufp->chgIData(oldp+1476,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[18]),32);
        bufp->chgIData(oldp+1477,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[19]),32);
        bufp->chgIData(oldp+1478,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[20]),32);
        bufp->chgIData(oldp+1479,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[21]),32);
        bufp->chgIData(oldp+1480,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[22]),32);
        bufp->chgIData(oldp+1481,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[23]),32);
        bufp->chgIData(oldp+1482,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[24]),32);
        bufp->chgIData(oldp+1483,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[25]),32);
        bufp->chgIData(oldp+1484,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[26]),32);
        bufp->chgIData(oldp+1485,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[27]),32);
        bufp->chgIData(oldp+1486,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[28]),32);
        bufp->chgIData(oldp+1487,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[29]),32);
        bufp->chgIData(oldp+1488,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[30]),32);
        bufp->chgIData(oldp+1489,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[31]),32);
        bufp->chgIData(oldp+1490,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[32]),32);
        bufp->chgIData(oldp+1491,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[33]),32);
        bufp->chgIData(oldp+1492,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[34]),32);
        bufp->chgIData(oldp+1493,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[35]),32);
        bufp->chgIData(oldp+1494,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[36]),32);
        bufp->chgIData(oldp+1495,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[37]),32);
        bufp->chgIData(oldp+1496,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[38]),32);
        bufp->chgIData(oldp+1497,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[39]),32);
        bufp->chgIData(oldp+1498,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[40]),32);
        bufp->chgIData(oldp+1499,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[41]),32);
        bufp->chgIData(oldp+1500,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[42]),32);
        bufp->chgIData(oldp+1501,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[43]),32);
        bufp->chgIData(oldp+1502,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[44]),32);
        bufp->chgIData(oldp+1503,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[45]),32);
        bufp->chgIData(oldp+1504,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[46]),32);
        bufp->chgIData(oldp+1505,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[47]),32);
        bufp->chgIData(oldp+1506,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[48]),32);
        bufp->chgIData(oldp+1507,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[49]),32);
        bufp->chgIData(oldp+1508,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[50]),32);
        bufp->chgIData(oldp+1509,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[51]),32);
        bufp->chgIData(oldp+1510,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[52]),32);
        bufp->chgIData(oldp+1511,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[53]),32);
        bufp->chgIData(oldp+1512,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[54]),32);
        bufp->chgIData(oldp+1513,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[55]),32);
        bufp->chgIData(oldp+1514,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[56]),32);
        bufp->chgIData(oldp+1515,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[57]),32);
        bufp->chgIData(oldp+1516,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[58]),32);
        bufp->chgIData(oldp+1517,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[59]),32);
        bufp->chgIData(oldp+1518,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[60]),32);
        bufp->chgIData(oldp+1519,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[61]),32);
        bufp->chgIData(oldp+1520,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[62]),32);
        bufp->chgIData(oldp+1521,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__W[63]),32);
        bufp->chgCData(oldp+1522,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round),6);
        bufp->chgCData(oldp+1523,(((2U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__state))
                                    ? (0x3fU & ((IData)(1U) 
                                                + (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__round)))
                                    : 0U)),6);
        bufp->chgIData(oldp+1524,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T1),32);
        bufp->chgIData(oldp+1525,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__T2),32);
        bufp->chgIData(oldp+1526,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1527,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+1528,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk6__DOT__i),32);
        bufp->chgIData(oldp+1529,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__sha_inst__DOT__unnamedblk7__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[4U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgBit(oldp+1530,(((~ (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__integrity_fail)) 
                                 & (3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state)))));
        if (vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_valid_internal) {
            __Vtemp_7[0U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[0U];
            __Vtemp_7[1U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[1U];
            __Vtemp_7[2U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[2U];
            __Vtemp_7[3U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[3U];
            __Vtemp_7[4U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[4U];
            __Vtemp_7[5U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[5U];
            __Vtemp_7[6U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[6U];
            __Vtemp_7[7U] = vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg[7U];
        } else {
            __Vtemp_7[0U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[0U];
            __Vtemp_7[1U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[1U];
            __Vtemp_7[2U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[2U];
            __Vtemp_7[3U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[3U];
            __Vtemp_7[4U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[4U];
            __Vtemp_7[5U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[5U];
            __Vtemp_7[6U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[6U];
            __Vtemp_7[7U] = Vtb_crypto_ops__ConstPool__CONST_h9e67c271_0[7U];
        }
        bufp->chgWData(oldp+1531,(__Vtemp_7),256);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+1539,((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))));
        bufp->chgBit(oldp+1540,((0xaU == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state))));
        bufp->chgWData(oldp+1541,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__hmac_key_reg),256);
        bufp->chgWData(oldp+1549,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__aes_key_reg),256);
        bufp->chgWData(oldp+1557,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_key_reg),256);
        bufp->chgBit(oldp+1565,((3U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state))));
        bufp->chgWData(oldp+1566,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal),256);
        bufp->chgWData(oldp+1574,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__aes_key_internal),256);
        __Vtemp_8[0U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[0U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[0U]);
        __Vtemp_8[1U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[1U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[1U]);
        __Vtemp_8[2U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[2U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[2U]);
        __Vtemp_8[3U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[3U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[3U]);
        __Vtemp_8[4U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[4U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[4U]);
        __Vtemp_8[5U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[5U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[5U]);
        __Vtemp_8[6U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[6U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[6U]);
        __Vtemp_8[7U] = (Vtb_crypto_ops__ConstPool__CONST_hb6e17ec7_0[7U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[7U]);
        bufp->chgWData(oldp+1582,(__Vtemp_8),256);
        __Vtemp_9[0U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[0U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[0U]);
        __Vtemp_9[1U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[1U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[1U]);
        __Vtemp_9[2U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[2U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[2U]);
        __Vtemp_9[3U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[3U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[3U]);
        __Vtemp_9[4U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[4U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[4U]);
        __Vtemp_9[5U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[5U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[5U]);
        __Vtemp_9[6U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[6U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[6U]);
        __Vtemp_9[7U] = (Vtb_crypto_ops__ConstPool__CONST_h0cd1c8bd_0[7U] 
                         ^ vlSelfRef.tb_crypto_ops__DOT__dut__DOT__hmac_key_internal[7U]);
        bufp->chgWData(oldp+1590,(__Vtemp_9),256);
        bufp->chgCData(oldp+1598,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__state),4);
        bufp->chgWData(oldp+1599,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__sha_hash),256);
        bufp->chgCData(oldp+1607,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__state),3);
        bufp->chgWData(oldp+1608,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__hmac_key_reg),256);
        bufp->chgWData(oldp+1616,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__aes_key_reg),256);
        bufp->chgWData(oldp+1624,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__sha_key_reg),256);
    }
    bufp->chgBit(oldp+1632,(vlSelfRef.tb_crypto_ops__DOT__clock));
    bufp->chgBit(oldp+1633,(((5U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__state)) 
                             & ((0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__next_state)) 
                                & (0U == (IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_dus_inst__DOT__error_count))))));
    bufp->chgCData(oldp+1634,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__init_next_state),4);
    bufp->chgCData(oldp+1635,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__kdf_inst__DOT__next_state),4);
    bufp->chgCData(oldp+1636,(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__key_dist_inst__DOT__next_state),3);
    bufp->chgBit(oldp+1637,(((IData)(vlSelfRef.tb_crypto_ops__DOT__dut__DOT__puf_devid_enroll_internal) 
                             | (IData)(vlSelfRef.tb_crypto_ops__DOT__puf_devid_enroll))));
}

void Vtb_crypto_ops___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_crypto_ops___024root__trace_cleanup\n"); );
    // Init
    Vtb_crypto_ops___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_crypto_ops___024root*>(voidSelf);
    Vtb_crypto_ops__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
