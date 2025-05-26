// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench__pch.h"
#include "Vtestbench___024root.h"

VlCoroutine Vtestbench___024root___eval_initial__TOP__Vtiming__0(Vtestbench___024root* vlSelf);

void Vtestbench___024root___eval_initial(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_initial\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestbench___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtestbench___024root___eval_initial__TOP__Vtiming__0(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "/home/shaw/fpu/vsrc/testbench.v", 
                                         20);
    vlSelfRef.testbench__DOT__a = 0x141bfU;
    vlSelfRef.testbench__DOT__b = 0x2250U;
    vlSelfRef.testbench__DOT__cin = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xc350ULL, 
                                         nullptr, "/home/shaw/fpu/vsrc/testbench.v", 
                                         24);
    VL_FINISH_MT("/home/shaw/fpu/vsrc/testbench.v", 24, "");
}

void Vtestbench___024root___act_sequent__TOP__0(Vtestbench___024root* vlSelf);

void Vtestbench___024root___eval_act(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_act\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtestbench___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtestbench___024root___act_sequent__TOP__0(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___act_sequent__TOP__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_2;
    __VdfgRegularize_hd87f99a1_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_3;
    __VdfgRegularize_hd87f99a1_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_8;
    __VdfgRegularize_hd87f99a1_0_8 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_9;
    __VdfgRegularize_hd87f99a1_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_10;
    __VdfgRegularize_hd87f99a1_0_10 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_11;
    __VdfgRegularize_hd87f99a1_0_11 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_20;
    __VdfgRegularize_hd87f99a1_0_20 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_21;
    __VdfgRegularize_hd87f99a1_0_21 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_22;
    __VdfgRegularize_hd87f99a1_0_22 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_23;
    __VdfgRegularize_hd87f99a1_0_23 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_24;
    __VdfgRegularize_hd87f99a1_0_24 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_25;
    __VdfgRegularize_hd87f99a1_0_25 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_26;
    __VdfgRegularize_hd87f99a1_0_26 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_27;
    __VdfgRegularize_hd87f99a1_0_27 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_44;
    __VdfgRegularize_hd87f99a1_0_44 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_45;
    __VdfgRegularize_hd87f99a1_0_45 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_46;
    __VdfgRegularize_hd87f99a1_0_46 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_47;
    __VdfgRegularize_hd87f99a1_0_47 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_48;
    __VdfgRegularize_hd87f99a1_0_48 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_49;
    __VdfgRegularize_hd87f99a1_0_49 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_50;
    __VdfgRegularize_hd87f99a1_0_50 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_51;
    __VdfgRegularize_hd87f99a1_0_51 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_52;
    __VdfgRegularize_hd87f99a1_0_52 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_53;
    __VdfgRegularize_hd87f99a1_0_53 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_54;
    __VdfgRegularize_hd87f99a1_0_54 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_55;
    __VdfgRegularize_hd87f99a1_0_55 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_56;
    __VdfgRegularize_hd87f99a1_0_56 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_57;
    __VdfgRegularize_hd87f99a1_0_57 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_58;
    __VdfgRegularize_hd87f99a1_0_58 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_59;
    __VdfgRegularize_hd87f99a1_0_59 = 0;
    // Body
    vlSelfRef.testbench__DOT__c0__DOT__g = (vlSelfRef.testbench__DOT__a 
                                            & vlSelfRef.testbench__DOT__b);
    vlSelfRef.testbench__DOT__c0__DOT__p = (vlSelfRef.testbench__DOT__a 
                                            ^ vlSelfRef.testbench__DOT__b);
    vlSelfRef.testbench__DOT__c0__DOT__G[0U] = vlSelfRef.testbench__DOT__c0__DOT__g;
    vlSelfRef.testbench__DOT__c0__DOT__P[0U] = vlSelfRef.testbench__DOT__c0__DOT__p;
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_0 = (1U 
                                                & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                                                    >> 0x1fU) 
                                                   | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                                       >> 0x1fU) 
                                                      & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                                         >> 0x1eU))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 = (1U 
                                                & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                                                    >> 0x1eU) 
                                                   | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                                       >> 0x1eU) 
                                                      & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                                         >> 0x1dU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x1dU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x1dU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x1cU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x1cU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x1cU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x1bU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57 
        = (IData)((0xc0000000U == (0xc0000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x1bU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x1bU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x1aU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x1aU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x1aU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x19U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x19U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x19U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x18U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x18U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x18U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x17U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56 
        = (IData)((0x60000000U == (0x60000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x17U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x17U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x16U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x16U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x16U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x15U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_38 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x15U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x15U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x14U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_36 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x14U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x14U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x13U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_34 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x13U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x13U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x12U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55 
        = (IData)((0x30000000U == (0x30000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_32 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x12U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x12U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x11U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_30 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x11U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x11U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0x10U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_28 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0x10U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                >> 0x10U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 0xfU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_26 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xfU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xfU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 0xeU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xeU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xeU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 0xdU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53 
        = (IData)((0x18000000U == (0x18000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xdU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xdU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 0xcU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xcU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xcU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 0xbU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_18 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xbU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xbU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 0xaU))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_16 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 0xaU) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                               >> 0xaU) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                           >> 9U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_14 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 9U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 9U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 8U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_12 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 8U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 8U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 7U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51 
        = (IData)((0xc000000U == (0xc000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_10 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 7U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 7U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 6U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 6U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 6U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 5U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 5U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 5U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 4U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 4U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 4U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 3U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 3U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 3U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 2U))));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49 
        = (IData)((0x6000000U == (0x6000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0 
        = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                  >> 2U) | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                             >> 2U) & (vlSelfRef.testbench__DOT__c0__DOT__g 
                                       >> 1U))));
    __VdfgRegularize_hd87f99a1_0_3 = (IData)((3U == 
                                              (3U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    __VdfgRegularize_hd87f99a1_0_2 = (1U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                                             >> 1U) 
                                            | ((vlSelfRef.testbench__DOT__c0__DOT__p 
                                                >> 1U) 
                                               & vlSelfRef.testbench__DOT__c0__DOT__g)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47 
        = (IData)((0x3000000U == (0x3000000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45 
        = (IData)((0x1800000U == (0x1800000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43 
        = (IData)((0xc00000U == (0xc00000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41 
        = (IData)((0x600000U == (0x600000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39 
        = (IData)((0x300000U == (0x300000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37 
        = (IData)((0x180000U == (0x180000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35 
        = (IData)((0xc0000U == (0xc0000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33 
        = (IData)((0x60000U == (0x60000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31 
        = (IData)((0x30000U == (0x30000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3 
        = (IData)((0xcU == (0xcU & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29 
        = (IData)((0x18000U == (0x18000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27 
        = (IData)((0xc000U == (0xc000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1 
        = (IData)((6U == (6U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25 
        = (IData)((0x6000U == (0x6000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23 
        = (IData)((0x3000U == (0x3000U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21 
        = (IData)((0x1800U == (0x1800U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19 
        = (IData)((0xc00U == (0xc00U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7 
        = (IData)((0x30U == (0x30U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11 
        = (IData)((0xc0U == (0xc0U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15 
        = (IData)((0x300U == (0x300U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5 
        = (IData)((0x18U == (0x18U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17 
        = (IData)((0x600U == (0x600U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9 
        = (IData)((0x60U == (0x60U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13 
        = (IData)((0x180U == (0x180U & vlSelfRef.testbench__DOT__c0__DOT__p)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_4 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                                | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57) 
                                                   & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_5 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_1) 
                                                | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56) 
                                                   & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_6 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54) 
                                                | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55) 
                                                   & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_7 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52) 
                                                | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53) 
                                                   & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_96 = (((IData)(__VdfgRegularize_hd87f99a1_0_3) 
                                                  << 1U) 
                                                 | (1U 
                                                    & vlSelfRef.testbench__DOT__c0__DOT__p));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_92 = (((IData)(__VdfgRegularize_hd87f99a1_0_2) 
                                                  << 1U) 
                                                 | (1U 
                                                    & vlSelfRef.testbench__DOT__c0__DOT__g));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_38)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_36)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_34 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_38) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_34)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_32 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_36) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_32)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_30 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_34) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_30)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_28 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_32) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_28)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_26 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_30) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_26)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31));
    __VdfgRegularize_hd87f99a1_0_10 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_3));
    __VdfgRegularize_hd87f99a1_0_8 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2) 
                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3) 
                                         & (IData)(__VdfgRegularize_hd87f99a1_0_2)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_24 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_28) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_22 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_26) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27));
    __VdfgRegularize_hd87f99a1_0_11 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1) 
                                       & vlSelfRef.testbench__DOT__c0__DOT__p);
    __VdfgRegularize_hd87f99a1_0_9 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0) 
                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1) 
                                         & vlSelfRef.testbench__DOT__c0__DOT__g));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_18)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_16)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_14 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_18) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_14)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_6 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_10) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_10 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_14) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_10)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_12 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_16) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_12)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_8 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_12) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8)));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13));
    vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_12 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_4) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_13 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_5) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44)));
    vlSelfRef.testbench__DOT__c0__DOT__P[1U] = ((((
                                                   (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_39) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_37) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_35) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_33) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_31) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_29) 
                                                             << 0x10U))))) 
                                                | ((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_27) 
                                                       << 0xfU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25) 
                                                         << 0xeU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23) 
                                                         << 0xdU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21) 
                                                           << 0xcU))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_19) 
                                                         << 0xbU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_17) 
                                                           << 0xaU)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_15) 
                                                           << 9U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_13) 
                                                             << 8U)))) 
                                                   | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_11) 
                                                         << 7U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9) 
                                                           << 6U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7) 
                                                           << 5U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5) 
                                                             << 4U))) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1) 
                                                             << 2U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_96))))));
    vlSelfRef.testbench__DOT__c0__DOT__G[1U] = ((((
                                                   (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_1) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_38) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_36) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_34) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_32) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_30) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_28) 
                                                             << 0x10U))))) 
                                                | ((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_26) 
                                                       << 0xfU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24) 
                                                         << 0xeU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22) 
                                                         << 0xdU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20) 
                                                           << 0xcU))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_18) 
                                                         << 0xbU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_16) 
                                                           << 0xaU)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_14) 
                                                           << 9U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_12) 
                                                             << 8U)))) 
                                                   | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_10) 
                                                         << 7U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8) 
                                                           << 6U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6) 
                                                           << 5U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4) 
                                                             << 4U))) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0) 
                                                             << 2U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_92))))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_14 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_6) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_15 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_7) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_16 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_17 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_18 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_34)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_19 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_32)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_30)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_28)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_26 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_34) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_26)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_24 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_32) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_24)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_22 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_30) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_22)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_97 = (((IData)(__VdfgRegularize_hd87f99a1_0_10) 
                                                  << 3U) 
                                                 | (((IData)(__VdfgRegularize_hd87f99a1_0_11) 
                                                     << 2U) 
                                                    | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_96)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_93 = (((IData)(__VdfgRegularize_hd87f99a1_0_8) 
                                                  << 3U) 
                                                 | (((IData)(__VdfgRegularize_hd87f99a1_0_9) 
                                                     << 2U) 
                                                    | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_92)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_20 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_28) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_18 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_26) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_16 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_24) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_14 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_22) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_14)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19));
    __VdfgRegularize_hd87f99a1_0_26 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_3));
    __VdfgRegularize_hd87f99a1_0_22 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_2)));
    __VdfgRegularize_hd87f99a1_0_24 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_10));
    __VdfgRegularize_hd87f99a1_0_20 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_6) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_8)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_10)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_14) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_6)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_10) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3));
    __VdfgRegularize_hd87f99a1_0_27 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1) 
                                       & vlSelfRef.testbench__DOT__c0__DOT__p);
    __VdfgRegularize_hd87f99a1_0_23 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1) 
                                          & vlSelfRef.testbench__DOT__c0__DOT__g));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_12)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17));
    __VdfgRegularize_hd87f99a1_0_25 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_11));
    __VdfgRegularize_hd87f99a1_0_21 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_9)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_8)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_12) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_8) 
           | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9) 
              & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0)));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9));
    vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_28 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_29 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_30 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_26)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_31 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_24)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_32 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_22)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27));
    vlSelfRef.testbench__DOT__c0__DOT__P[2U] = ((((
                                                   (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_35) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_33) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_31) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_29) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_27) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_25) 
                                                             << 0x10U))))) 
                                                | ((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_23) 
                                                       << 0xfU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21) 
                                                         << 0xeU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19) 
                                                         << 0xdU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17) 
                                                           << 0xcU))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_15) 
                                                         << 0xbU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_13) 
                                                           << 0xaU)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_11) 
                                                           << 9U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_9) 
                                                             << 8U)))) 
                                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_7) 
                                                        << 7U) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5) 
                                                          << 6U)) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3) 
                                                          << 5U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1) 
                                                             << 4U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_97))))));
    vlSelfRef.testbench__DOT__c0__DOT__G[2U] = ((((
                                                   (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_4) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_5) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_6) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_7) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_34) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_32) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_30) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_28) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_26) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_24) 
                                                             << 0x10U))))) 
                                                | ((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_22) 
                                                       << 0xfU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20) 
                                                         << 0xeU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18) 
                                                         << 0xdU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16) 
                                                           << 0xcU))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_14) 
                                                         << 0xbU) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_12) 
                                                           << 0xaU)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_10) 
                                                           << 9U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_8) 
                                                             << 8U)))) 
                                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_6) 
                                                        << 7U) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4) 
                                                          << 6U)) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2) 
                                                          << 5U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0) 
                                                             << 4U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_93))))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_33 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_20)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_34 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_18)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_35 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_16)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_36 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_14)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_38 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_26) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_40 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_22) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6)));
    __VdfgRegularize_hd87f99a1_0_52 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_24));
    __VdfgRegularize_hd87f99a1_0_44 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_14) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_20)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7));
    __VdfgRegularize_hd87f99a1_0_56 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_10));
    __VdfgRegularize_hd87f99a1_0_48 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_8)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_42 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_18) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11));
    __VdfgRegularize_hd87f99a1_0_54 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_26));
    __VdfgRegularize_hd87f99a1_0_46 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_22)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3));
    __VdfgRegularize_hd87f99a1_0_58 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_3));
    __VdfgRegularize_hd87f99a1_0_50 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_2)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_37 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_98 = ((((IData)(__VdfgRegularize_hd87f99a1_0_24) 
                                                   << 7U) 
                                                  | ((IData)(__VdfgRegularize_hd87f99a1_0_25) 
                                                     << 6U)) 
                                                 | (((IData)(__VdfgRegularize_hd87f99a1_0_26) 
                                                     << 5U) 
                                                    | (((IData)(__VdfgRegularize_hd87f99a1_0_27) 
                                                        << 4U) 
                                                       | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_97))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_94 = ((((IData)(__VdfgRegularize_hd87f99a1_0_20) 
                                                   << 7U) 
                                                  | ((IData)(__VdfgRegularize_hd87f99a1_0_21) 
                                                     << 6U)) 
                                                 | (((IData)(__VdfgRegularize_hd87f99a1_0_22) 
                                                     << 5U) 
                                                    | (((IData)(__VdfgRegularize_hd87f99a1_0_23) 
                                                        << 4U) 
                                                       | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_93))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_39 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_24) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_41 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_20) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13));
    __VdfgRegularize_hd87f99a1_0_53 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_25));
    __VdfgRegularize_hd87f99a1_0_45 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_21)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5));
    __VdfgRegularize_hd87f99a1_0_57 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_11));
    __VdfgRegularize_hd87f99a1_0_49 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_9)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_43 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_16) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17) 
                                                    & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9));
    __VdfgRegularize_hd87f99a1_0_55 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9) 
                                       & (IData)(__VdfgRegularize_hd87f99a1_0_27));
    __VdfgRegularize_hd87f99a1_0_47 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9) 
                                          & (IData)(__VdfgRegularize_hd87f99a1_0_23)));
    vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0 
        = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17) 
           & (IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1));
    __VdfgRegularize_hd87f99a1_0_59 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1) 
                                       & vlSelfRef.testbench__DOT__c0__DOT__p);
    __VdfgRegularize_hd87f99a1_0_51 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0) 
                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1) 
                                          & vlSelfRef.testbench__DOT__c0__DOT__g));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_76 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_52));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_60 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_28) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_44)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_84 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_24));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_68 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_36) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_20)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_88 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_10));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_72 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_40) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_8)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_80 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_56));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_64 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_32) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_48)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_86 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_26));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_70 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_38) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_22)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_78 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_54));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_62 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_30) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_46)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_90 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_3));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_74 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_42) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_2)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_82 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_58));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_66 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_34) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_50)));
    vlSelfRef.testbench__DOT__c0__DOT__P[3U] = ((((
                                                   (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_27) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_25) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_23) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_21) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_19) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_17) 
                                                             << 0x10U))))) 
                                                | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_15) 
                                                      << 0xfU) 
                                                     | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13) 
                                                        << 0xeU)) 
                                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11) 
                                                        << 0xdU) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9) 
                                                          << 0xcU))) 
                                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7) 
                                                        << 0xbU) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5) 
                                                          << 0xaU)) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3) 
                                                          << 9U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1) 
                                                             << 8U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_98))))));
    vlSelfRef.testbench__DOT__c0__DOT__G[3U] = ((((
                                                   (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12) 
                                                     << 0x1fU) 
                                                    | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13) 
                                                       << 0x1eU)) 
                                                   | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14) 
                                                       << 0x1dU) 
                                                      | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15) 
                                                         << 0x1cU))) 
                                                  | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16) 
                                                       << 0x1bU) 
                                                      | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18) 
                                                         << 0x19U) 
                                                        | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19) 
                                                           << 0x18U)))) 
                                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30) 
                                                       << 0x17U) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28) 
                                                         << 0x16U)) 
                                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_26) 
                                                         << 0x15U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_24) 
                                                           << 0x14U))) 
                                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_22) 
                                                         << 0x13U) 
                                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_20) 
                                                           << 0x12U)) 
                                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_18) 
                                                           << 0x11U) 
                                                          | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_16) 
                                                             << 0x10U))))) 
                                                | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_14) 
                                                      << 0xfU) 
                                                     | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12) 
                                                        << 0xeU)) 
                                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10) 
                                                        << 0xdU) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8) 
                                                          << 0xcU))) 
                                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6) 
                                                        << 0xbU) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4) 
                                                          << 0xaU)) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2) 
                                                          << 9U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0) 
                                                             << 8U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_94))))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_85 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_25));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_69 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_37) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_21)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_77 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_53));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_61 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_29) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_45)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_89 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_11));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_73 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_41) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_9)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_81 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_57));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_65 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_33) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_49)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_87 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_27));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_71 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_39) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_23)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_79 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_55));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_63 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_31) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_47)));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_91 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0) 
                                                 & vlSelfRef.testbench__DOT__c0__DOT__p);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_75 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_43) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0) 
                                                    & vlSelfRef.testbench__DOT__c0__DOT__g));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_99 = (((
                                                   ((IData)(__VdfgRegularize_hd87f99a1_0_52) 
                                                    << 0xfU) 
                                                   | ((IData)(__VdfgRegularize_hd87f99a1_0_53) 
                                                      << 0xeU)) 
                                                  | (((IData)(__VdfgRegularize_hd87f99a1_0_54) 
                                                      << 0xdU) 
                                                     | ((IData)(__VdfgRegularize_hd87f99a1_0_55) 
                                                        << 0xcU))) 
                                                 | ((((IData)(__VdfgRegularize_hd87f99a1_0_56) 
                                                      << 0xbU) 
                                                     | ((IData)(__VdfgRegularize_hd87f99a1_0_57) 
                                                        << 0xaU)) 
                                                    | (((IData)(__VdfgRegularize_hd87f99a1_0_58) 
                                                        << 9U) 
                                                       | (((IData)(__VdfgRegularize_hd87f99a1_0_59) 
                                                           << 8U) 
                                                          | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_98)))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_83 = ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8) 
                                                 & (IData)(__VdfgRegularize_hd87f99a1_0_59));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_95 = (((
                                                   ((IData)(__VdfgRegularize_hd87f99a1_0_44) 
                                                    << 0xfU) 
                                                   | ((IData)(__VdfgRegularize_hd87f99a1_0_45) 
                                                      << 0xeU)) 
                                                  | (((IData)(__VdfgRegularize_hd87f99a1_0_46) 
                                                      << 0xdU) 
                                                     | ((IData)(__VdfgRegularize_hd87f99a1_0_47) 
                                                        << 0xcU))) 
                                                 | ((((IData)(__VdfgRegularize_hd87f99a1_0_48) 
                                                      << 0xbU) 
                                                     | ((IData)(__VdfgRegularize_hd87f99a1_0_49) 
                                                        << 0xaU)) 
                                                    | (((IData)(__VdfgRegularize_hd87f99a1_0_50) 
                                                        << 9U) 
                                                       | (((IData)(__VdfgRegularize_hd87f99a1_0_51) 
                                                           << 8U) 
                                                          | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_94)))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_67 = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_35) 
                                                 | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8) 
                                                    & (IData)(__VdfgRegularize_hd87f99a1_0_51)));
    vlSelfRef.testbench__DOT__c0__DOT__P[4U] = ((((
                                                   ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15) 
                                                    << 0x1fU) 
                                                   | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14) 
                                                      << 0x1eU)) 
                                                  | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13) 
                                                      << 0x1dU) 
                                                     | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12) 
                                                        << 0x1cU))) 
                                                 | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11) 
                                                      << 0x1bU) 
                                                     | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10) 
                                                        << 0x1aU)) 
                                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9) 
                                                        << 0x19U) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8) 
                                                          << 0x18U)))) 
                                                | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7) 
                                                      << 0x17U) 
                                                     | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6) 
                                                        << 0x16U)) 
                                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5) 
                                                        << 0x15U) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4) 
                                                          << 0x14U))) 
                                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3) 
                                                        << 0x13U) 
                                                       | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2) 
                                                          << 0x12U)) 
                                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1) 
                                                          << 0x11U) 
                                                         | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0) 
                                                             << 0x10U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_99))))));
    vlSelfRef.testbench__DOT__c0__DOT__P[5U] = ((((
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_76) 
                                                    << 0x1fU) 
                                                   | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_77) 
                                                      << 0x1eU)) 
                                                  | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_78) 
                                                      << 0x1dU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_79) 
                                                        << 0x1cU))) 
                                                 | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_80) 
                                                      << 0x1bU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_81) 
                                                        << 0x1aU)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_82) 
                                                        << 0x19U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_83) 
                                                          << 0x18U)))) 
                                                | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_84) 
                                                      << 0x17U) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_85) 
                                                        << 0x16U)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_86) 
                                                        << 0x15U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_87) 
                                                          << 0x14U))) 
                                                   | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_88) 
                                                        << 0x13U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_89) 
                                                          << 0x12U)) 
                                                      | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_90) 
                                                          << 0x11U) 
                                                         | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_91) 
                                                             << 0x10U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_99))))));
    vlSelfRef.testbench__DOT__c0__DOT__G[4U] = ((((
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_28) 
                                                    << 0x1fU) 
                                                   | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_29) 
                                                      << 0x1eU)) 
                                                  | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_30) 
                                                      << 0x1dU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_31) 
                                                        << 0x1cU))) 
                                                 | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_32) 
                                                      << 0x1bU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_33) 
                                                        << 0x1aU)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_34) 
                                                        << 0x19U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_35) 
                                                          << 0x18U)))) 
                                                | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_36) 
                                                      << 0x17U) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_37) 
                                                        << 0x16U)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_38) 
                                                        << 0x15U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_39) 
                                                          << 0x14U))) 
                                                   | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_40) 
                                                        << 0x13U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_41) 
                                                          << 0x12U)) 
                                                      | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_42) 
                                                          << 0x11U) 
                                                         | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_43) 
                                                             << 0x10U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_95))))));
    vlSelfRef.testbench__DOT__c0__DOT__G[5U] = ((((
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_60) 
                                                    << 0x1fU) 
                                                   | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_61) 
                                                      << 0x1eU)) 
                                                  | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_62) 
                                                      << 0x1dU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_63) 
                                                        << 0x1cU))) 
                                                 | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_64) 
                                                      << 0x1bU) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_65) 
                                                        << 0x1aU)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_66) 
                                                        << 0x19U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_67) 
                                                          << 0x18U)))) 
                                                | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_68) 
                                                      << 0x17U) 
                                                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_69) 
                                                        << 0x16U)) 
                                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_70) 
                                                        << 0x15U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_71) 
                                                          << 0x14U))) 
                                                   | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_72) 
                                                        << 0x13U) 
                                                       | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_73) 
                                                          << 0x12U)) 
                                                      | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_74) 
                                                          << 0x11U) 
                                                         | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_75) 
                                                             << 0x10U) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_95))))));
    vlSelfRef.testbench__DOT__c0__DOT____VdfgRegularize_h428b52b8_0_0 
        = ((((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_61) 
                 | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_77) 
                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                << 0x1fU) | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_62) 
                              | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_78) 
                                 & (IData)(vlSelfRef.testbench__DOT__cin))) 
                             << 0x1eU)) | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_63) 
                                             | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_79) 
                                                & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                            << 0x1dU) 
                                           | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_64) 
                                               | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_80) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                              << 0x1cU))) 
             | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_65) 
                   | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_81) 
                      & (IData)(vlSelfRef.testbench__DOT__cin))) 
                  << 0x1bU) | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_66) 
                                | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_82) 
                                   & (IData)(vlSelfRef.testbench__DOT__cin))) 
                               << 0x1aU)) | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_67) 
                                               | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_83) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                              << 0x19U) 
                                             | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_68) 
                                                 | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_84) 
                                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                << 0x18U)))) 
            | ((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_69) 
                   | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_85) 
                      & (IData)(vlSelfRef.testbench__DOT__cin))) 
                  << 0x17U) | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_70) 
                                | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_86) 
                                   & (IData)(vlSelfRef.testbench__DOT__cin))) 
                               << 0x16U)) | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_71) 
                                               | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_87) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                              << 0x15U) 
                                             | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_72) 
                                                 | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_88) 
                                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                << 0x14U))) 
               | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_73) 
                     | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_89) 
                        & (IData)(vlSelfRef.testbench__DOT__cin))) 
                    << 0x13U) | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_74) 
                                  | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_90) 
                                     & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                 << 0x12U)) | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_75) 
                                                 | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_91) 
                                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                << 0x11U) 
                                               | (((IData)(__VdfgRegularize_hd87f99a1_0_44) 
                                                   | ((IData)(__VdfgRegularize_hd87f99a1_0_52) 
                                                      & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                  << 0x10U))))) 
           | (((((((IData)(__VdfgRegularize_hd87f99a1_0_45) 
                   | ((IData)(__VdfgRegularize_hd87f99a1_0_53) 
                      & (IData)(vlSelfRef.testbench__DOT__cin))) 
                  << 0xfU) | (((IData)(__VdfgRegularize_hd87f99a1_0_46) 
                               | ((IData)(__VdfgRegularize_hd87f99a1_0_54) 
                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                              << 0xeU)) | ((((IData)(__VdfgRegularize_hd87f99a1_0_47) 
                                             | ((IData)(__VdfgRegularize_hd87f99a1_0_55) 
                                                & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                            << 0xdU) 
                                           | (((IData)(__VdfgRegularize_hd87f99a1_0_48) 
                                               | ((IData)(__VdfgRegularize_hd87f99a1_0_56) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                              << 0xcU))) 
               | (((((IData)(__VdfgRegularize_hd87f99a1_0_49) 
                     | ((IData)(__VdfgRegularize_hd87f99a1_0_57) 
                        & (IData)(vlSelfRef.testbench__DOT__cin))) 
                    << 0xbU) | (((IData)(__VdfgRegularize_hd87f99a1_0_50) 
                                 | ((IData)(__VdfgRegularize_hd87f99a1_0_58) 
                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                << 0xaU)) | ((((IData)(__VdfgRegularize_hd87f99a1_0_51) 
                                               | ((IData)(__VdfgRegularize_hd87f99a1_0_59) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                              << 9U) 
                                             | (((IData)(__VdfgRegularize_hd87f99a1_0_20) 
                                                 | ((IData)(__VdfgRegularize_hd87f99a1_0_24) 
                                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                << 8U)))) 
              | ((((((IData)(__VdfgRegularize_hd87f99a1_0_21) 
                     | ((IData)(__VdfgRegularize_hd87f99a1_0_25) 
                        & (IData)(vlSelfRef.testbench__DOT__cin))) 
                    << 7U) | (((IData)(__VdfgRegularize_hd87f99a1_0_22) 
                               | ((IData)(__VdfgRegularize_hd87f99a1_0_26) 
                                  & (IData)(vlSelfRef.testbench__DOT__cin))) 
                              << 6U)) | ((((IData)(__VdfgRegularize_hd87f99a1_0_23) 
                                           | ((IData)(__VdfgRegularize_hd87f99a1_0_27) 
                                              & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                          << 5U) | 
                                         (((IData)(__VdfgRegularize_hd87f99a1_0_8) 
                                           | ((IData)(__VdfgRegularize_hd87f99a1_0_10) 
                                              & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                          << 4U))) 
                 | (((((IData)(__VdfgRegularize_hd87f99a1_0_9) 
                       | ((IData)(__VdfgRegularize_hd87f99a1_0_11) 
                          & (IData)(vlSelfRef.testbench__DOT__cin))) 
                      << 3U) | (((IData)(__VdfgRegularize_hd87f99a1_0_2) 
                                 | ((IData)(__VdfgRegularize_hd87f99a1_0_3) 
                                    & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                << 2U)) | ((2U & ((vlSelfRef.testbench__DOT__c0__DOT__g 
                                                   | (vlSelfRef.testbench__DOT__c0__DOT__p 
                                                      & (IData)(vlSelfRef.testbench__DOT__cin))) 
                                                  << 1U)) 
                                           | (IData)(vlSelfRef.testbench__DOT__cin))))));
}

void Vtestbench___024root___eval_nba(Vtestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_nba\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtestbench___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
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
