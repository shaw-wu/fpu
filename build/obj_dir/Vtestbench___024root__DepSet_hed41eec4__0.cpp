// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench__pch.h"
#include "Vtestbench___024root.h"

VL_ATTR_COLD void Vtestbench___024root___eval_initial__TOP(Vtestbench___024root* vlSelf);
VlCoroutine Vtestbench___024root___eval_initial__TOP__Vtiming__0(Vtestbench___024root* vlSelf);

void Vtestbench___024root___eval_initial(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_initial\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestbench___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtestbench___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtestbench___024root___eval_initial__TOP__Vtiming__0(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "/home/shaw/fpu/vsrc/testbench.v", 
                                         28);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.testbench__DOT__fp = 0x7fa00000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "/home/shaw/fpu/vsrc/testbench.v", 
                                         30);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("/home/shaw/fpu/vsrc/testbench.v", 30, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

void Vtestbench___024root___act_sequent__TOP__0(Vtestbench___024root* vlSelf);

void Vtestbench___024root___eval_act(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_act\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtestbench___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtestbench___024root___act_sequent__TOP__0(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___act_sequent__TOP__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_16;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_16 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_17;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_17 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_18;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_18 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_19;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_19 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_20;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_20 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_21;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_21 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24 = 0;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25 = 0;
    // Body
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__0__KET__ 
        = (IData)((0U != (3U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[0U] 
        = ((2U & vlSelfRef.testbench__DOT__fp) ? 1U
            : 0U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[1U] 
        = ((8U & vlSelfRef.testbench__DOT__fp) ? 3U
            : 2U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[2U] 
        = ((0x20U & vlSelfRef.testbench__DOT__fp) ? 5U
            : 4U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[3U] 
        = ((0x80U & vlSelfRef.testbench__DOT__fp) ? 7U
            : 6U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[4U] 
        = ((0x200U & vlSelfRef.testbench__DOT__fp) ? 9U
            : 8U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[5U] 
        = ((0x800U & vlSelfRef.testbench__DOT__fp) ? 0xbU
            : 0xaU);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[6U] 
        = ((0x2000U & vlSelfRef.testbench__DOT__fp)
            ? 0xdU : 0xcU);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[7U] 
        = ((0x8000U & vlSelfRef.testbench__DOT__fp)
            ? 0xfU : 0xeU);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[8U] 
        = ((0x20000U & vlSelfRef.testbench__DOT__fp)
            ? 0x11U : 0x10U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[9U] 
        = ((0x80000U & vlSelfRef.testbench__DOT__fp)
            ? 0x13U : 0x12U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos1[0xaU] 
        = ((0x200000U & vlSelfRef.testbench__DOT__fp)
            ? 0x15U : 0x14U);
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__8__KET__ 
        = (IData)((0U != (0x30000U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__4__KET__ 
        = (IData)((0U != (0x300U & vlSelfRef.testbench__DOT__fp)));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_21 
        = ((0x400000U & vlSelfRef.testbench__DOT__fp)
            ? 0x16U : ((0x200000U & vlSelfRef.testbench__DOT__fp)
                        ? 0x15U : 0x14U));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__2__KET__ 
        = (IData)((0U != (0x30U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__1__KET__ 
        = (IData)((0U != (0xcU & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__10__KET__ 
        = (IData)((0U != (0x300000U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__9__KET__ 
        = (IData)((0U != (0xc0000U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__6__KET__ 
        = (IData)((0U != (0x3000U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__5__KET__ 
        = (IData)((0U != (0xc00U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__3__KET__ 
        = (IData)((0U != (0xc0U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__7__KET__ 
        = (IData)((0U != (0xc000U & vlSelfRef.testbench__DOT__fp)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[5U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_21;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__0__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__0__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__1__KET__));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_16 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__1__KET__)
            ? ((8U & vlSelfRef.testbench__DOT__fp) ? 3U
                : 2U) : ((2U & vlSelfRef.testbench__DOT__fp)
                          ? 1U : 0U));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__5__KET__ 
        = (1U & ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__10__KET__) 
                 | (vlSelfRef.testbench__DOT__fp >> 0x16U)));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__4__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__8__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__9__KET__));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_20 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__9__KET__)
            ? ((0x80000U & vlSelfRef.testbench__DOT__fp)
                ? 0x13U : 0x12U) : ((0x20000U & vlSelfRef.testbench__DOT__fp)
                                     ? 0x11U : 0x10U));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__2__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__4__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__5__KET__));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_18 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__5__KET__)
            ? ((0x800U & vlSelfRef.testbench__DOT__fp)
                ? 0xbU : 0xaU) : ((0x200U & vlSelfRef.testbench__DOT__fp)
                                   ? 9U : 8U));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__1__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__2__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__3__KET__));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_17 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__3__KET__)
            ? ((0x80U & vlSelfRef.testbench__DOT__fp)
                ? 7U : 6U) : ((0x20U & vlSelfRef.testbench__DOT__fp)
                               ? 5U : 4U));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_19 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__7__KET__)
            ? ((0x8000U & vlSelfRef.testbench__DOT__fp)
                ? 0xfU : 0xeU) : ((0x2000U & vlSelfRef.testbench__DOT__fp)
                                   ? 0xdU : 0xcU));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__3__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__6__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__7__KET__));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[0U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_16;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__4__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__5__KET__));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[4U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_20;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__5__KET__)
            ? (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_21)
            : (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_20));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[2U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_18;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__0__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__0__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__1__KET__));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[1U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_17;
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__1__KET__)
            ? (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_17)
            : (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_16));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos2[3U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_19;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__1__KET__ 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__2__KET__) 
           | (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__3__KET__));
    testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__3__KET__)
            ? (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_19)
            : (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_18));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos4[1U] 
        = vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[2U] 
        = vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[0U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos3[1U] 
        = testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25;
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28 
        = ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__1__KET__)
            ? (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25)
            : (IData)(testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24));
    vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__pos4[0U] 
        = vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28;
    vlSelfRef.testbench__DOT__sig = ((IData)(((0x7f800000U 
                                               == (0x7f800000U 
                                                   & vlSelfRef.testbench__DOT__fp)) 
                                              & (0U 
                                                 != 
                                                 (0x7fffffU 
                                                  & vlSelfRef.testbench__DOT__fp))))
                                      ? ([&]() {
                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__4__fr 
                    = (0x7fffffU & vlSelfRef.testbench__DOT__fp);
                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__4__Vfuncout 
                    = (0x20000000U | (vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__4__fr 
                                      << 6U));
            }(), vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__4__Vfuncout)
                                      : ((IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.testbench__DOT__fp)))
                                          ? 0x3fffffc0U
                                          : ((IData)(
                                                     (0U 
                                                      == 
                                                      (0x7fffffffU 
                                                       & vlSelfRef.testbench__DOT__fp)))
                                              ? 0x20000000U
                                              : ((IData)(
                                                         ((0U 
                                                           == 
                                                           (0x7f800000U 
                                                            & vlSelfRef.testbench__DOT__fp)) 
                                                          & (0U 
                                                             != 
                                                             (0x7fffffU 
                                                              & vlSelfRef.testbench__DOT__fp))))
                                                  ? 
                                                 ([&]() {
                            vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__7__fr 
                                = (0x7fffffU & VL_SHIFTL_III(23,23,22, vlSelfRef.testbench__DOT__fp, 
                                                             (0x1fU 
                                                              & ((IData)(1U) 
                                                                 + 
                                                                 (((IData)(0x1fU) 
                                                                   - 
                                                                   ((IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__)
                                                                     ? (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26)
                                                                     : (IData)(vlSelfRef.testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28))) 
                                                                  - (IData)(9U))))));
                            vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__7__Vfuncout 
                                = (0x20000000U | (vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__7__fr 
                                                  << 6U));
                        }(), vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__7__Vfuncout)
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
                                                  ([&]() {
                                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__8__fr 
                                    = (0x7fffffU & vlSelfRef.testbench__DOT__fp);
                                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__8__Vfuncout 
                                    = (0x20000000U 
                                       | (vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__8__fr 
                                          << 6U));
                            }(), vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__8__Vfuncout)
                                                   : 
                                                  ([&]() {
                                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__9__fr 
                                    = (0x7fffffU & vlSelfRef.testbench__DOT__fp);
                                vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__9__Vfuncout 
                                    = (0x20000000U 
                                       | (vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__9__fr 
                                          << 6U));
                            }(), vlSelfRef.__Vfunc_testbench__DOT__l1__DOT__fill_sig__9__Vfuncout))))));
}

void Vtestbench___024root___eval_nba(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_nba\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtestbench___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

void Vtestbench___024root___timing_resume(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___timing_resume\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtestbench___024root___eval_triggers__act(Vtestbench___024root* vlSelf);

bool Vtestbench___024root___eval_phase__act(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_phase__act\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtestbench___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtestbench___024root___timing_resume(vlSelf);
        Vtestbench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtestbench___024root___eval_phase__nba(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_phase__nba\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtestbench___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__nba(Vtestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__act(Vtestbench___024root* vlSelf);
#endif  // VL_DEBUG

void Vtestbench___024root___eval(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtestbench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/shaw/fpu/vsrc/testbench.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtestbench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/shaw/fpu/vsrc/testbench.v", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtestbench___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtestbench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtestbench___024root___eval_debug_assertions(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_debug_assertions\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
