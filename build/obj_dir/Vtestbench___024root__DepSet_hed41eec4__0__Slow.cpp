// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench__pch.h"
#include "Vtestbench___024root.h"

VL_ATTR_COLD void Vtestbench___024root___eval_static(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_static\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtestbench___024root___eval_final(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_final\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__stl(Vtestbench___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtestbench___024root___eval_phase__stl(Vtestbench___024root* vlSelf);

VL_ATTR_COLD void Vtestbench___024root___eval_settle(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_settle\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtestbench___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/shaw/CA_project/fpu/vsrc/testbench.v", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtestbench___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__stl(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__stl\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

void Vtestbench___024root___act_sequent__TOP__0(Vtestbench___024root* vlSelf);
VL_ATTR_COLD void Vtestbench___024root____Vm_traceActivitySetAll(Vtestbench___024root* vlSelf);

VL_ATTR_COLD void Vtestbench___024root___eval_stl(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_stl\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtestbench___024root___act_sequent__TOP__0(vlSelf);
        Vtestbench___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtestbench___024root___eval_triggers__stl(Vtestbench___024root* vlSelf);

VL_ATTR_COLD bool Vtestbench___024root___eval_phase__stl(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_phase__stl\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtestbench___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtestbench___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__act(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__act\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__nba(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__nba\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestbench___024root____Vm_traceActivitySetAll(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root____Vm_traceActivitySetAll\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vtestbench___024root___ctor_var_reset(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___ctor_var_reset\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->testbench__DOT__in = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__15__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__14__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__13__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__12__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__11__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__10__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__9__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__8__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__7__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__6__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__5__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__4__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__3__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__2__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__1__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid1__BRA__0__KET__ = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->testbench__DOT__lzd__DOT__pos1[__Vi0] = VL_RAND_RESET_I(5);
    }
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__7__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__6__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__5__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__4__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__3__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__2__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__1__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid2__BRA__0__KET__ = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->testbench__DOT__lzd__DOT__pos2[__Vi0] = VL_RAND_RESET_I(5);
    }
    vlSelf->testbench__DOT__lzd__DOT__valid3__BRA__3__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid3__BRA__2__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid3__BRA__1__KET__ = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__lzd__DOT__valid3__BRA__0__KET__ = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->testbench__DOT__lzd__DOT__pos3[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->testbench__DOT__lzd__DOT__pos4[__Vi0] = VL_RAND_RESET_I(5);
    }
    vlSelf->testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_24 = VL_RAND_RESET_I(5);
    vlSelf->testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_25 = VL_RAND_RESET_I(5);
    vlSelf->testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26 = VL_RAND_RESET_I(5);
    vlSelf->testbench__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_27 = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
