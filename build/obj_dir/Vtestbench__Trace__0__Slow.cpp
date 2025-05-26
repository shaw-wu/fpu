// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtestbench__Syms.h"


VL_ATTR_COLD void Vtestbench___024root__trace_init_sub__TOP__0(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_init_sub__TOP__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("testbench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"fp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+39,0,"sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"isNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"isINf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("l1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+1,0,"fp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+39,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"isZero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"isNormalize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"isUnormalize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"FP_LOG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"sign_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+40,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+56,0,"clog2__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("lzd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+10,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"valid0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"valid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("pos1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+42,0,"valid2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("pos2", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+27+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+43,0,"valid3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("pos3", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+35+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+44,0,"valid4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("pos4", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+45+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+47,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtestbench___024root__trace_init_top(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_init_top\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestbench___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtestbench___024root__trace_register(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_register\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtestbench___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtestbench___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtestbench___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtestbench___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_const_0\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtestbench___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_const_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+50,(0x20U),32);
    bufp->fullIData(oldp+51,(8U),32);
    bufp->fullIData(oldp+52,(0x17U),32);
    bufp->fullIData(oldp+53,(9U),32);
    bufp->fullSData(oldp+54,(0x101U),9);
    bufp->fullIData(oldp+55,(5U),32);
    bufp->fullIData(oldp+56,(vlSelfRef.testbench__DOT__l1__DOT__clog2__Vstatic__i),32);
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtestbench___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.testbench__DOT__fp),32);
    bufp->fullBit(oldp+2,((vlSelfRef.testbench__DOT__fp 
                           >> 0x1fU)));
    bufp->fullBit(oldp+3,((IData)(((0x7f800000U == 
                                    (0x7f800000U & vlSelfRef.testbench__DOT__fp)) 
                                   & (0U != (0x7fffffU 
                                             & vlSelfRef.testbench__DOT__fp))))));
    bufp->fullBit(oldp+4,((IData)((0x7f800000U == (0x7fffffffU 
                                                   & vlSelfRef.testbench__DOT__fp)))));
    bufp->fullBit(oldp+5,((IData)((0U == (0x7fffffffU 
                                          & vlSelfRef.testbench__DOT__fp)))));
    bufp->fullBit(oldp+6,(((0U != (0xffU & (vlSelfRef.testbench__DOT__fp 
                                            >> 0x17U))) 
                           & (0xffU != (0xffU & (vlSelfRef.testbench__DOT__fp 
                                                 >> 0x17U))))));
    bufp->fullBit(oldp+7,((IData)(((0U == (0x7f800000U 
                                           & vlSelfRef.testbench__DOT__fp)) 
                                   & (0U != (0x7fffffU 
                                             & vlSelfRef.testbench__DOT__fp))))));
    bufp->fullCData(oldp+8,((0xffU & (vlSelfRef.testbench__DOT__fp 
                                      >> 0x17U))),8);
    bufp->fullIData(oldp+9,((0x7fffffU & vlSelfRef.testbench__DOT__fp)),23);
    bufp->fullIData(oldp+10,((0x7fffffU & vlSelfRef.testbench__DOT__fp)),32);
    bufp->fullCData(oldp+11,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[0]),5);
    bufp->fullCData(oldp+12,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[1]),5);
    bufp->fullCData(oldp+13,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[2]),5);
    bufp->fullCData(oldp+14,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[3]),5);
    bufp->fullCData(oldp+15,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[4]),5);
    bufp->fullCData(oldp+16,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[5]),5);
    bufp->fullCData(oldp+17,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[6]),5);
    bufp->fullCData(oldp+18,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[7]),5);
    bufp->fullCData(oldp+19,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[8]),5);
    bufp->fullCData(oldp+20,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[9]),5);
    bufp->fullCData(oldp+21,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[10]),5);
    bufp->fullCData(oldp+22,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[11]),5);
    bufp->fullCData(oldp+23,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[12]),5);
    bufp->fullCData(oldp+24,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[13]),5);
    bufp->fullCData(oldp+25,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[14]),5);
    bufp->fullCData(oldp+26,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[15]),5);
    bufp->fullCData(oldp+27,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[0]),5);
    bufp->fullCData(oldp+28,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[1]),5);
    bufp->fullCData(oldp+29,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[2]),5);
    bufp->fullCData(oldp+30,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[3]),5);
    bufp->fullCData(oldp+31,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[4]),5);
    bufp->fullCData(oldp+32,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[5]),5);
    bufp->fullCData(oldp+33,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[6]),5);
    bufp->fullCData(oldp+34,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[7]),5);
    bufp->fullCData(oldp+35,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[0]),5);
    bufp->fullCData(oldp+36,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[1]),5);
    bufp->fullCData(oldp+37,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[2]),5);
    bufp->fullCData(oldp+38,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[3]),5);
    bufp->fullIData(oldp+39,(vlSelfRef.testbench__DOT__sig),32);
    bufp->fullCData(oldp+40,((0x1fU & (((IData)(0x1fU) 
                                        - ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__)
                                            ? (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26)
                                            : (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28))) 
                                       - (IData)(9U)))),5);
    bufp->fullCData(oldp+41,((0x1fU & ((IData)(1U) 
                                       + (((IData)(0x1fU) 
                                           - ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__)
                                               ? (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26)
                                               : (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28))) 
                                          - (IData)(9U))))),5);
    bufp->fullCData(oldp+42,(((((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__5__KET__) 
                                << 5U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__4__KET__) 
                                           << 4U) | 
                                          ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__3__KET__) 
                                           << 3U))) 
                              | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__2__KET__) 
                                  << 2U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__1__KET__) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__0__KET__))))),8);
    bufp->fullCData(oldp+43,((((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                               << 2U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__1__KET__) 
                                          << 1U) | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__0__KET__)))),4);
    bufp->fullCData(oldp+44,((((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                               << 1U) | ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__0__KET__) 
                                         | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__1__KET__)))),2);
    bufp->fullCData(oldp+45,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos4[0]),5);
    bufp->fullCData(oldp+46,(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos4[1]),5);
    bufp->fullCData(oldp+47,(((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__)
                               ? (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26)
                               : (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28))),5);
    bufp->fullSData(oldp+48,(((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.testbench__DOT__fp)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.testbench__DOT__fp))))
                               ? 0x1ffU : ((IData)(
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelfRef.testbench__DOT__fp)))
                                            ? 0x1bfU
                                            : ((IData)(
                                                       (0U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & vlSelfRef.testbench__DOT__fp)))
                                                ? 0x3fU
                                                : (0x1ffU 
                                                   & ((IData)(
                                                              ((0U 
                                                                == 
                                                                (0x7f800000U 
                                                                 & vlSelfRef.testbench__DOT__fp)) 
                                                               & (0U 
                                                                  != 
                                                                  (0x7fffffU 
                                                                   & vlSelfRef.testbench__DOT__fp))))
                                                       ? 
                                                      ((IData)(0x102U) 
                                                       - 
                                                       (0x1fU 
                                                        & ((IData)(1U) 
                                                           + 
                                                           (((IData)(0x1fU) 
                                                             - 
                                                             ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__)
                                                               ? (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26)
                                                               : (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28))) 
                                                            - (IData)(9U)))))
                                                       : 
                                                      (((0U 
                                                         != 
                                                         (0xffU 
                                                          & (vlSelfRef.testbench__DOT__fp 
                                                             >> 0x17U))) 
                                                        & (0xffU 
                                                           != 
                                                           (0xffU 
                                                            & (vlSelfRef.testbench__DOT__fp 
                                                               >> 0x17U))))
                                                        ? 
                                                       ((IData)(0x101U) 
                                                        + 
                                                        (0xffU 
                                                         & (vlSelfRef.testbench__DOT__fp 
                                                            >> 0x17U)))
                                                        : 0x1ffU))))))),9);
    bufp->fullSData(oldp+49,(((((0x800U & (vlSelfRef.testbench__DOT__fp 
                                           >> 0xbU)) 
                                | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__10__KET__) 
                                    << 0xaU) | ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__9__KET__) 
                                                << 9U))) 
                               | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__8__KET__) 
                                   << 8U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__7__KET__) 
                                              << 7U) 
                                             | ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__6__KET__) 
                                                << 6U)))) 
                              | ((((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__5__KET__) 
                                   << 5U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__4__KET__) 
                                              << 4U) 
                                             | ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__3__KET__) 
                                                << 3U))) 
                                 | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__2__KET__) 
                                     << 2U) | (((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__1__KET__) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__0__KET__)))))),16);
}
