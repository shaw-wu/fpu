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
        bufp->chgIData(oldp+0,((vlSelfRef.testbench__DOT__c0__DOT__p 
                                ^ vlSelfRef.testbench__DOT__c0__DOT____VdfgRegularize_h428b52b8_0_0)),32);
        bufp->chgIData(oldp+1,(vlSelfRef.testbench__DOT__c0__DOT__g),32);
        bufp->chgIData(oldp+2,(vlSelfRef.testbench__DOT__c0__DOT__p),32);
        bufp->chgIData(oldp+3,(vlSelfRef.testbench__DOT__c0__DOT__G[0]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.testbench__DOT__c0__DOT__G[1]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.testbench__DOT__c0__DOT__G[2]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.testbench__DOT__c0__DOT__G[3]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.testbench__DOT__c0__DOT__G[4]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.testbench__DOT__c0__DOT__G[5]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.testbench__DOT__c0__DOT__P[0]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.testbench__DOT__c0__DOT__P[1]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.testbench__DOT__c0__DOT__P[2]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.testbench__DOT__c0__DOT__P[3]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.testbench__DOT__c0__DOT__P[4]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.testbench__DOT__c0__DOT__P[5]),32);
        bufp->chgIData(oldp+15,((((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                      << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_1) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_54) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_52) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_50) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_48) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_46) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_44) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_42) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_40) 
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
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_24) 
                                        << 0xeU)) | 
                                      (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_22) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_20) 
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
                                          << 7U) | 
                                         ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_8) 
                                          << 6U)) | 
                                        (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_6) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_4) 
                                          << 4U))) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_2) 
                                           << 3U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_0) 
                                            << 2U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_92))))))),32);
        bufp->chgIData(oldp+16,((((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_57) 
                                      << 0x1fU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_56) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_55) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_53) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_51) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_49) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_47) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_45) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_43) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_41) 
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
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_25) 
                                        << 0xeU)) | 
                                      (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_23) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_21) 
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
                                          << 7U) | 
                                         ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_9) 
                                          << 6U)) | 
                                        (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_7) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_5) 
                                          << 4U))) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_3) 
                                           << 3U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p2__DOT____VdfgRegularize_h9519c48d_0_1) 
                                            << 2U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_96))))))),32);
        bufp->chgIData(oldp+17,((((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_4) 
                                      << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_5) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_6) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_7) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_46) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_44) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_42) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_40) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_38) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_36) 
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
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_20) 
                                        << 0xeU)) | 
                                      (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_18) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_16) 
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
                                         << 7U) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_4) 
                                                   << 6U)) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_2) 
                                           << 5U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_0) 
                                            << 4U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_93))))))),32);
        bufp->chgIData(oldp+18,((((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_51) 
                                      << 0x1fU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_50) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_49) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_48) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_47) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_45) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_43) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_41) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_39) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_37) 
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
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_21) 
                                        << 0xeU)) | 
                                      (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_19) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_17) 
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
                                         << 7U) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_5) 
                                                   << 6U)) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_3) 
                                           << 5U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p3__DOT____VdfgRegularize_h14a61d6c_0_1) 
                                            << 4U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_97))))))),32);
        bufp->chgIData(oldp+19,((((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12) 
                                      << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_30) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_28) 
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
                                       << 0xfU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_12) 
                                                   << 0xeU)) 
                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_10) 
                                         << 0xdU) | 
                                        ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_8) 
                                         << 0xcU))) 
                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_6) 
                                         << 0xbU) | 
                                        ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_4) 
                                         << 0xaU)) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_2) 
                                           << 9U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_0) 
                                            << 8U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_94))))))),32);
        bufp->chgIData(oldp+20,((((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_39) 
                                      << 0x1fU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_38) 
                                                   << 0x1eU)) 
                                    | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_37) 
                                        << 0x1dU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_36) 
                                        << 0x1cU))) 
                                   | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_35) 
                                        << 0x1bU) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_34) 
                                        << 0x1aU)) 
                                      | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_33) 
                                          << 0x19U) 
                                         | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_32) 
                                            << 0x18U)))) 
                                  | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_31) 
                                        << 0x17U) | 
                                       ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_29) 
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
                                       << 0xfU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_13) 
                                                   << 0xeU)) 
                                     | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_11) 
                                         << 0xdU) | 
                                        ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_9) 
                                         << 0xcU))) 
                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_7) 
                                         << 0xbU) | 
                                        ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_5) 
                                         << 0xaU)) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_3) 
                                           << 9U) | 
                                          (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p4__DOT____VdfgRegularize_h0661bd1d_0_1) 
                                            << 8U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_98))))))),32);
        bufp->chgIData(oldp+21,(((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_28) 
                                     << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_29) 
                                                  << 0x1eU)) 
                                   | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_30) 
                                       << 0x1dU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_31) 
                                       << 0x1cU))) 
                                  | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_32) 
                                       << 0x1bU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_33) 
                                       << 0x1aU)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_34) 
                                       << 0x19U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_35) 
                                       << 0x18U)))) 
                                 | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_36) 
                                       << 0x17U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_37) 
                                       << 0x16U)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_38) 
                                       << 0x15U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_39) 
                                       << 0x14U))) 
                                    | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_40) 
                                         << 0x13U) 
                                        | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_41) 
                                           << 0x12U)) 
                                       | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_42) 
                                           << 0x11U) 
                                          | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_43) 
                                              << 0x10U) 
                                             | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_95))))))),32);
        bufp->chgIData(oldp+22,(((((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_15) 
                                     << 0x1fU) | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_14) 
                                                  << 0x1eU)) 
                                   | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_13) 
                                       << 0x1dU) | 
                                      ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_12) 
                                       << 0x1cU))) 
                                  | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_11) 
                                       << 0x1bU) | 
                                      ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_10) 
                                       << 0x1aU)) | 
                                     (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_9) 
                                       << 0x19U) | 
                                      ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_8) 
                                       << 0x18U)))) 
                                 | (((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_7) 
                                       << 0x17U) | 
                                      ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_6) 
                                       << 0x16U)) | 
                                     (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_5) 
                                       << 0x15U) | 
                                      ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_4) 
                                       << 0x14U))) 
                                    | ((((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_3) 
                                         << 0x13U) 
                                        | ((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_2) 
                                           << 0x12U)) 
                                       | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_1) 
                                           << 0x11U) 
                                          | (((IData)(vlSelfRef.testbench__DOT__c0__DOT__p5__DOT____VdfgRegularize_ha7d0d37d_0_0) 
                                              << 0x10U) 
                                             | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_99))))))),32);
        bufp->chgIData(oldp+23,(((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_60) 
                                     << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_61) 
                                                  << 0x1eU)) 
                                   | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_62) 
                                       << 0x1dU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_63) 
                                       << 0x1cU))) 
                                  | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_64) 
                                       << 0x1bU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_65) 
                                       << 0x1aU)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_66) 
                                       << 0x19U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_67) 
                                       << 0x18U)))) 
                                 | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_68) 
                                       << 0x17U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_69) 
                                       << 0x16U)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_70) 
                                       << 0x15U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_71) 
                                       << 0x14U))) 
                                    | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_72) 
                                         << 0x13U) 
                                        | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_73) 
                                           << 0x12U)) 
                                       | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_74) 
                                           << 0x11U) 
                                          | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_75) 
                                              << 0x10U) 
                                             | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_95))))))),32);
        bufp->chgIData(oldp+24,(((((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_76) 
                                     << 0x1fU) | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_77) 
                                                  << 0x1eU)) 
                                   | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_78) 
                                       << 0x1dU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_79) 
                                       << 0x1cU))) 
                                  | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_80) 
                                       << 0x1bU) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_81) 
                                       << 0x1aU)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_82) 
                                       << 0x19U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_83) 
                                       << 0x18U)))) 
                                 | (((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_84) 
                                       << 0x17U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_85) 
                                       << 0x16U)) | 
                                     (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_86) 
                                       << 0x15U) | 
                                      ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_87) 
                                       << 0x14U))) 
                                    | ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_88) 
                                         << 0x13U) 
                                        | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_89) 
                                           << 0x12U)) 
                                       | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_90) 
                                           << 0x11U) 
                                          | (((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_91) 
                                              << 0x10U) 
                                             | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_99))))))),32);
    }
    bufp->chgIData(oldp+25,(vlSelfRef.testbench__DOT__a),32);
    bufp->chgIData(oldp+26,(vlSelfRef.testbench__DOT__b),32);
    bufp->chgBit(oldp+27,(vlSelfRef.testbench__DOT__cin));
    bufp->chgBit(oldp+28,(((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_60) 
                           | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_76) 
                              & (IData)(vlSelfRef.testbench__DOT__cin)))));
    bufp->chgQData(oldp+29,((((QData)((IData)(((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_60) 
                                               | ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_76) 
                                                  & (IData)(vlSelfRef.testbench__DOT__cin))))) 
                              << 0x20U) | (QData)((IData)(vlSelfRef.testbench__DOT__c0__DOT____VdfgRegularize_h428b52b8_0_0)))),33);
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
