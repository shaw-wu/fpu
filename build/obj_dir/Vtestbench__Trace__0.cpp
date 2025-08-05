// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtestbench__Syms.h"


void Vtestbench___024root__trace_chg_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_chg_0\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtestbench___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtestbench___024root__trace_chg_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_chg_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgCData(oldp+0,((0x1fU & ((IData)(0x1fU) 
                                         - (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                                             | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__))
                                             ? ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__)
                                                 ? (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_27)
                                                 : (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26))
                                             : ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__1__KET__)
                                                 ? (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25)
                                                 : (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24)))))),5);
        bufp->chgSData(oldp+1,(((((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__15__KET__) 
                                    << 0xfU) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__14__KET__) 
                                                << 0xeU)) 
                                  | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__13__KET__) 
                                      << 0xdU) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__12__KET__) 
                                                  << 0xcU))) 
                                 | ((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__11__KET__) 
                                      << 0xbU) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__10__KET__) 
                                                  << 0xaU)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__9__KET__) 
                                        << 9U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__8__KET__) 
                                                  << 8U)))) 
                                | (((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__7__KET__) 
                                      << 7U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__6__KET__) 
                                                << 6U)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__5__KET__) 
                                        << 5U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__4__KET__) 
                                                  << 4U))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__3__KET__) 
                                        << 3U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__2__KET__) 
                                                  << 2U)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__1__KET__) 
                                          << 1U) | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid1__BRA__0__KET__)))))),16);
        bufp->chgCData(oldp+2,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[0]),5);
        bufp->chgCData(oldp+3,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[1]),5);
        bufp->chgCData(oldp+4,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[2]),5);
        bufp->chgCData(oldp+5,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[3]),5);
        bufp->chgCData(oldp+6,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[4]),5);
        bufp->chgCData(oldp+7,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[5]),5);
        bufp->chgCData(oldp+8,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[6]),5);
        bufp->chgCData(oldp+9,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[7]),5);
        bufp->chgCData(oldp+10,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[8]),5);
        bufp->chgCData(oldp+11,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[9]),5);
        bufp->chgCData(oldp+12,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[10]),5);
        bufp->chgCData(oldp+13,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[11]),5);
        bufp->chgCData(oldp+14,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[12]),5);
        bufp->chgCData(oldp+15,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[13]),5);
        bufp->chgCData(oldp+16,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[14]),5);
        bufp->chgCData(oldp+17,(vlSelfRef.testbench__DOT__lzd__DOT__pos1[15]),5);
        bufp->chgCData(oldp+18,((((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__7__KET__) 
                                    << 7U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__6__KET__) 
                                              << 6U)) 
                                  | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__5__KET__) 
                                      << 5U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__4__KET__) 
                                                << 4U))) 
                                 | ((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__3__KET__) 
                                      << 3U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__2__KET__) 
                                                << 2U)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__1__KET__) 
                                        << 1U) | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid2__BRA__0__KET__))))),8);
        bufp->chgCData(oldp+19,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[0]),5);
        bufp->chgCData(oldp+20,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[1]),5);
        bufp->chgCData(oldp+21,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[2]),5);
        bufp->chgCData(oldp+22,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[3]),5);
        bufp->chgCData(oldp+23,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[4]),5);
        bufp->chgCData(oldp+24,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[5]),5);
        bufp->chgCData(oldp+25,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[6]),5);
        bufp->chgCData(oldp+26,(vlSelfRef.testbench__DOT__lzd__DOT__pos2[7]),5);
        bufp->chgCData(oldp+27,(((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__) 
                                   << 3U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                                             << 2U)) 
                                 | (((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__1__KET__) 
                                     << 1U) | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__0__KET__)))),4);
        bufp->chgCData(oldp+28,(vlSelfRef.testbench__DOT__lzd__DOT__pos3[0]),5);
        bufp->chgCData(oldp+29,(vlSelfRef.testbench__DOT__lzd__DOT__pos3[1]),5);
        bufp->chgCData(oldp+30,(vlSelfRef.testbench__DOT__lzd__DOT__pos3[2]),5);
        bufp->chgCData(oldp+31,(vlSelfRef.testbench__DOT__lzd__DOT__pos3[3]),5);
        bufp->chgCData(oldp+32,(((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                                   | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__)) 
                                  << 1U) | ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__0__KET__) 
                                            | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__1__KET__)))),2);
        bufp->chgCData(oldp+33,(vlSelfRef.testbench__DOT__lzd__DOT__pos4[0]),5);
        bufp->chgCData(oldp+34,(vlSelfRef.testbench__DOT__lzd__DOT__pos4[1]),5);
        bufp->chgCData(oldp+35,((((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__2__KET__) 
                                  | (IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__))
                                  ? ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__3__KET__)
                                      ? (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_27)
                                      : (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26))
                                  : ((IData)(vlSelfRef.testbench__DOT__lzd__DOT__valid3__BRA__1__KET__)
                                      ? (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25)
                                      : (IData)(vlSelfRef.testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24)))),5);
    }
    bufp->chgIData(oldp+36,(vlSelfRef.testbench__DOT__in),32);
}

void Vtestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_cleanup\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
