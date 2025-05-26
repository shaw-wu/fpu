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
            VL_FATAL_MT("/home/shaw/fpu/vsrc/testbench.v", 2, "", "Settle region did not converge.");
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
    vlSelf->testbench__DOT__a = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__b = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__cin = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__g = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__c0__DOT__p = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->testbench__DOT__c0__DOT__G[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->testbench__DOT__c0__DOT__P[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->testbench__DOT__c0__DOT__clog2__Vstatic__k = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__c0__DOT____VdfgRegularize_h428b52b8_0_0 = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_10 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_12 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_14 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_16 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_18 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_26 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_28 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_30 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_32 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_34 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_36 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_38 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_6 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_8 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_10 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_12 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_14 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_22 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_24 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_26 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_28 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_30 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_32 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_34 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_14 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_16 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_18 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_20 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_22 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_24 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_26 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14 = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_0 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_1 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_4 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_5 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_6 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_7 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_12 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_13 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_14 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_15 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_16 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_17 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_18 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_19 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_28 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_29 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_30 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_31 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_32 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_33 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_34 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_35 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_36 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_37 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_38 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_39 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_40 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_41 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_42 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_43 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_60 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_61 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_62 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_63 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_64 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_65 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_66 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_67 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_68 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_69 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_70 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_71 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_72 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_73 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_74 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_75 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_76 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_77 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_78 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_79 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_80 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_81 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_82 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_83 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_84 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_85 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_86 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_87 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_88 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_89 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_90 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_91 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_0_92 = VL_RAND_RESET_I(2);
    vlSelf->__VdfgRegularize_hd87f99a1_0_93 = VL_RAND_RESET_I(4);
    vlSelf->__VdfgRegularize_hd87f99a1_0_94 = VL_RAND_RESET_I(8);
    vlSelf->__VdfgRegularize_hd87f99a1_0_95 = VL_RAND_RESET_I(16);
    vlSelf->__VdfgRegularize_hd87f99a1_0_96 = VL_RAND_RESET_I(2);
    vlSelf->__VdfgRegularize_hd87f99a1_0_97 = VL_RAND_RESET_I(4);
    vlSelf->__VdfgRegularize_hd87f99a1_0_98 = VL_RAND_RESET_I(8);
    vlSelf->__VdfgRegularize_hd87f99a1_0_99 = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
