// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtestbench__Syms.h"


void Vtestbench___024root__trace_chg_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_chg_0\n"); );
    // Body
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtestbench___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtestbench___024root__trace_chg_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_chg_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.testbench__DOT__rst));
        bufp->chgBit(oldp+1,(vlSelfRef.testbench__DOT__i_valid));
        bufp->chgCData(oldp+2,(vlSelfRef.testbench__DOT__sel),4);
        bufp->chgCData(oldp+3,(vlSelfRef.testbench__DOT__frm),3);
        bufp->chgIData(oldp+4,(vlSelfRef.testbench__DOT__fina),32);
        bufp->chgIData(oldp+5,(vlSelfRef.testbench__DOT__finb),32);
        bufp->chgIData(oldp+6,(vlSelfRef.testbench__DOT__ina),32);
        bufp->chgBit(oldp+7,(((0U == (IData)(vlSelfRef.testbench__DOT__sel))
                               ? ((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                  & (IData)(vlSelfRef.testbench__DOT__i_valid))
                               : (IData)(vlSelfRef.testbench__DOT__i_valid))));
        bufp->chgBit(oldp+8,(vlSelfRef.testbench__DOT__o_ready));
        bufp->chgIData(oldp+9,(vlSelfRef.testbench__DOT__file_in),32);
        bufp->chgIData(oldp+10,(vlSelfRef.testbench__DOT__file_log),32);
        bufp->chgIData(oldp+11,(vlSelfRef.testbench__DOT__status),32);
        bufp->chgIData(oldp+12,(vlSelfRef.testbench__DOT__exp_res),32);
        bufp->chgCData(oldp+13,(vlSelfRef.testbench__DOT__exp_fflags),5);
        bufp->chgIData(oldp+14,(vlSelfRef.testbench__DOT__vector_cnt),32);
        bufp->chgIData(oldp+15,(vlSelfRef.testbench__DOT__error_cnt),32);
        bufp->chgBit(oldp+16,((0U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+17,((1U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+18,((4U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+19,((5U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+20,((6U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+21,((7U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+22,((8U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+23,((9U == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+24,((0x0aU == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+25,((0x0bU == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+26,((0x0cU == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+27,((0x0dU == (IData)(vlSelfRef.testbench__DOT__sel))));
        bufp->chgBit(oldp+28,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                               & (IData)(vlSelfRef.testbench__DOT__i_valid))));
        bufp->chgBit(oldp+29,((vlSelfRef.testbench__DOT__fina 
                               >> 0x0000001fU)));
        bufp->chgBit(oldp+30,((vlSelfRef.testbench__DOT__finb 
                               >> 0x0000001fU)));
        bufp->chgCData(oldp+31,((0x000000ffU & (vlSelfRef.testbench__DOT__fina 
                                                >> 0x00000017U))),8);
        bufp->chgIData(oldp+32,((0x007fffffU & vlSelfRef.testbench__DOT__fina)),23);
        bufp->chgIData(oldp+33,(((0x80000000U & vlSelfRef.testbench__DOT__finb) 
                                 | (0x7fffffffU & vlSelfRef.testbench__DOT__fina))),32);
        bufp->chgIData(oldp+34,((((~ (vlSelfRef.testbench__DOT__finb 
                                      >> 0x0000001fU)) 
                                  << 0x0000001fU) | 
                                 (0x7fffffffU & vlSelfRef.testbench__DOT__fina))),32);
        bufp->chgBit(oldp+35,(((vlSelfRef.testbench__DOT__finb 
                                >> 0x0000001fU) ^ (1U 
                                                   == (IData)(vlSelfRef.testbench__DOT__sel)))));
        bufp->chgIData(oldp+36,((0x7fffffffU & (- (IData)(
                                                          (vlSelfRef.testbench__DOT__fina 
                                                           >> 0x0000001fU))))),31);
        bufp->chgIData(oldp+37,((0x7fffffffU & (- (IData)(
                                                          (vlSelfRef.testbench__DOT__finb 
                                                           >> 0x0000001fU))))),31);
        bufp->chgIData(oldp+38,(((vlSelfRef.testbench__DOT__ina 
                                  >> 0x0000001fU) ? 
                                 ((IData)(1U) + (~ vlSelfRef.testbench__DOT__ina))
                                  : vlSelfRef.testbench__DOT__ina)),32);
        bufp->chgIData(oldp+39,(((vlSelfRef.testbench__DOT__fina 
                                  >> 0x0000001fU) ? 0x80000000U
                                  : 0x7fffffffU)),32);
        bufp->chgIData(oldp+40,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__fina, 9U)),32);
        bufp->chgCData(oldp+41,((0x000000ffU & (vlSelfRef.testbench__DOT__finb 
                                                >> 0x00000017U))),8);
        bufp->chgIData(oldp+42,((0x007fffffU & vlSelfRef.testbench__DOT__finb)),23);
        bufp->chgIData(oldp+43,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__finb, 9U)),32);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [1U] | vlSelfRef.__Vm_traceActivity
                        [2U]) | vlSelfRef.__Vm_traceActivity
                       [3U]) | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgCData(oldp+44,(((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_2)
                                  ? (((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                      << 4U) | (((0x017fU 
                                                  < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                                 << 2U) 
                                                | (((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))))
                                  : (((4U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                      | ((7U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                         | ((8U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                            | (9U == (IData)(vlSelfRef.testbench__DOT__sel)))))
                                      ? 0U : ((5U == (IData)(vlSelfRef.testbench__DOT__sel))
                                               ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                                  << 4U)
                                               : ((6U 
                                                   == (IData)(vlSelfRef.testbench__DOT__sel))
                                                   ? 
                                                  ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                                   << 4U)
                                                   : 
                                                  (((0x0aU 
                                                     == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                                    | (0x0bU 
                                                       == (IData)(vlSelfRef.testbench__DOT__sel)))
                                                    ? 
                                                   ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                                                      | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                                         | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of))) 
                                                     << 4U) 
                                                    | ((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                                                       & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1)))
                                                    : 
                                                   (((0x0cU 
                                                      == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                                     | (0x0dU 
                                                        == (IData)(vlSelfRef.testbench__DOT__sel)))
                                                     ? (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx)
                                                     : 0U))))))),5);
        bufp->chgIData(oldp+45,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)) 
                                 & (vlSelfRef.testbench__DOT__fina 
                                    == vlSelfRef.testbench__DOT__finb))),32);
        bufp->chgIData(oldp+46,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                  ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                           ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                           : ((vlSelfRef.testbench__DOT__fina 
                                               >> 0x0000001fU)
                                               ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  > (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                               : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
        bufp->chgIData(oldp+47,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                  ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                           ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                           : ((vlSelfRef.testbench__DOT__fina 
                                               >> 0x0000001fU)
                                               ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                               : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
        bufp->chgIData(oldp+48,((((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1) 
                                  << 0x0000001fU) | 
                                 (0x7fffffffU & vlSelfRef.testbench__DOT__fina))),32);
        bufp->chgIData(oldp+49,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                                  ? ((vlSelfRef.testbench__DOT__fina 
                                      >> 0x0000001fU)
                                      ? 0x80000000U
                                      : 0x7fffffffU)
                                  : ((vlSelfRef.testbench__DOT__fina 
                                      >> 0x0000001fU)
                                      ? (0x80000000U 
                                         | (0x7fffffffU 
                                            & ((IData)(1U) 
                                               + (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))))
                                      : (0x7fffffffU 
                                         & vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),32);
        bufp->chgIData(oldp+50,((0x7fffffffU & ((- (IData)(
                                                           (vlSelfRef.testbench__DOT__fina 
                                                            >> 0x0000001fU))) 
                                                ^ (IData)(
                                                          (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                           >> 0x00000020U))))),31);
        bufp->chgIData(oldp+51,((0x7fffffffU & ((- (IData)(
                                                           (vlSelfRef.testbench__DOT__finb 
                                                            >> 0x0000001fU))) 
                                                ^ (IData)(
                                                          (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                           >> 0x00000020U))))),31);
        bufp->chgIData(oldp+52,(((((0U != (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                   >> 0x00000020U))) 
                                   & (vlSelfRef.testbench__DOT__fina 
                                      >> 0x0000001fU)) 
                                  << 0x0000001fU) | 
                                 (0x7fffffffU & (((- (IData)(
                                                             (vlSelfRef.testbench__DOT__fina 
                                                              >> 0x0000001fU))) 
                                                  ^ (IData)(
                                                            (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                             >> 0x00000020U))) 
                                                 + 
                                                 (vlSelfRef.testbench__DOT__fina 
                                                  >> 0x0000001fU))))),32);
        bufp->chgIData(oldp+53,(((((0U != (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                   >> 0x00000020U))) 
                                   & ((vlSelfRef.testbench__DOT__finb 
                                       >> 0x0000001fU) 
                                      ^ (1U == (IData)(vlSelfRef.testbench__DOT__sel)))) 
                                  << 0x0000001fU) | 
                                 (0x7fffffffU & (((- (IData)(
                                                             (vlSelfRef.testbench__DOT__finb 
                                                              >> 0x0000001fU))) 
                                                  ^ (IData)(
                                                            (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                             >> 0x00000020U))) 
                                                 + 
                                                 (vlSelfRef.testbench__DOT__finb 
                                                  >> 0x0000001fU))))),32);
        bufp->chgBit(oldp+54,(((vlSelfRef.testbench__DOT__fina 
                                >> 0x0000001fU) ? (0U 
                                                   != vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)
                                : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
        bufp->chgBit(oldp+55,(((vlSelfRef.testbench__DOT__fina 
                                >> 0x0000001fU) ? (
                                                   (0x0120U 
                                                    < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                   | ((0x0120U 
                                                       == (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                      & (0x80000000U 
                                                         != vlSelfRef.testbench__DOT__dut__DOT__sig_a)))
                                : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
        bufp->chgIData(oldp+56,(((vlSelfRef.testbench__DOT__fina 
                                  >> 0x0000001fU) ? 
                                 (0x80000000U | (0x7fffffffU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))))
                                  : (0x7fffffffU & vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgIData(oldp+57,(vlSelfRef.testbench__DOT__dut__DOT__fresult),32);
        bufp->chgSData(oldp+58,(vlSelfRef.testbench__DOT__dut__DOT__exp_a),9);
        bufp->chgIData(oldp+59,(vlSelfRef.testbench__DOT__dut__DOT__sig_a),32);
        bufp->chgBit(oldp+60,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan));
        bufp->chgBit(oldp+61,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf));
        bufp->chgSData(oldp+62,(vlSelfRef.testbench__DOT__dut__DOT__exp_b),9);
        bufp->chgIData(oldp+63,(vlSelfRef.testbench__DOT__dut__DOT__sig_b),32);
        bufp->chgBit(oldp+64,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isNAN));
        bufp->chgBit(oldp+65,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isINf));
        bufp->chgBit(oldp+66,((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res 
                               >> 0x0000001fU)));
        bufp->chgIData(oldp+67,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig),32);
        bufp->chgSData(oldp+68,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp),9);
        bufp->chgBit(oldp+69,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN));
        bufp->chgBit(oldp+70,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf));
        bufp->chgCData(oldp+71,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                  << 4U) | (((0x017fU 
                                              < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                             << 2U) 
                                            | (((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))))),5);
        bufp->chgIData(oldp+72,(((0x80000000U & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res) 
                                 | ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                       ? 0x000000ffU
                                       : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                           ? 0x000000ffU
                                           : ((0U == 
                                               (7U 
                                                & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                   >> 6U)))
                                               ? 0U
                                               : ((
                                                   (0x006bU 
                                                    <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                                   & (0x0081U 
                                                      >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                                   ? 0U
                                                   : 
                                                  (((0x0082U 
                                                     <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                                    & (0x017fU 
                                                       >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                                    ? 
                                                   (0x000000ffU 
                                                    & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                       - (IData)(0x81U)))
                                                    : 0x000000ffU))))) 
                                     << 0x00000017U) 
                                    | (0x007fffffU 
                                       & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                           ? (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                              >> 9U)
                                           : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                               ? 0U
                                               : ((0U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                       >> 6U)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                                   >> 8U)))))))),32);
        bufp->chgCData(oldp+73,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                 << 4U)),5);
        bufp->chgIData(oldp+74,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                                  ? 0xffffffffU : vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)),32);
        bufp->chgBit(oldp+75,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                               | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                  | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)))));
        bufp->chgBit(oldp+76,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                               & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1))));
        bufp->chgCData(oldp+77,(((((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                                   | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                      | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of))) 
                                  << 4U) | ((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                                            & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1)))),5);
        bufp->chgBit(oldp+78,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sign));
        bufp->chgCData(oldp+79,((0x000000ffU & ((IData)(0x7fU) 
                                                + (
                                                   ((IData)(0x1fU) 
                                                    - 
                                                    (0x0000001fU 
                                                     & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))) 
                                                   + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout))))),8);
        bufp->chgIData(oldp+80,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout)
                                  ? 0x00800000U : (0x00ffffffU 
                                                   & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                       >> 8U) 
                                                      + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre))))),24);
        bufp->chgIData(oldp+81,(vlSelfRef.testbench__DOT__dut__DOT__fcxs_fresult),32);
        bufp->chgBit(oldp+82,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx));
        bufp->chgCData(oldp+83,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx),5);
        bufp->chgSData(oldp+84,(((0x00000100U & ((~ 
                                                  ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                   >> 8U)) 
                                                 << 8U)) 
                                 | (0x000000ffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),9);
        bufp->chgSData(oldp+85,(((0x00000100U & ((~ 
                                                  ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b) 
                                                   >> 8U)) 
                                                 << 8U)) 
                                 | (0x000000ffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))),9);
        bufp->chgSData(oldp+86,((0x000001ffU & ((IData)(1U) 
                                                + (~ 
                                                   ((0x00000100U 
                                                     & ((~ 
                                                         ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b) 
                                                          >> 8U)) 
                                                        << 8U)) 
                                                    | (0x000000ffU 
                                                       & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))))))),9);
        bufp->chgSData(oldp+87,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff),9);
        bufp->chgSData(oldp+88,((0x000001ffU & ((IData)(1U) 
                                                + (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))))),9);
        bufp->chgBit(oldp+89,((1U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff) 
                                     >> 8U))));
        bufp->chgCData(oldp+90,(((0x0020U <= (0x000001ffU 
                                              & ((IData)(1U) 
                                                 + 
                                                 (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff)))))
                                  ? 0x00000020U : (0x0000003fU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff)))))),6);
        bufp->chgCData(oldp+91,(((0x0020U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))
                                  ? 0x00000020U : (0x0000003fU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))))),6);
        bufp->chgQData(oldp+92,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a),64);
        bufp->chgQData(oldp+94,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b),64);
        bufp->chgBit(oldp+96,((0U != (0x000000ffffffffffULL 
                                      & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))));
        bufp->chgBit(oldp+97,((0U != (0x000000ffffffffffULL 
                                      & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))));
        bufp->chgBit(oldp+98,(((0x00000100U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))
                                ? (0U != (0x000000ffffffffffULL 
                                          & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                                : (0U != (0x000000ffffffffffULL 
                                          & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b)))));
        bufp->chgIData(oldp+99,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                         >> 0x00000020U))),32);
        bufp->chgIData(oldp+100,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                          >> 0x00000020U))),32);
        bufp->chgIData(oldp+101,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res),32);
        bufp->chgIData(oldp+102,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res),32);
        bufp->chgBit(oldp+103,((1U & VL_REDXOR_32((0xc0000000U 
                                                   & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res)))));
        bufp->chgCData(oldp+104,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos),6);
        bufp->chgCData(oldp+105,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos))),5);
        bufp->chgIData(oldp+106,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_sig_res),32);
        bufp->chgSData(oldp+107,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res),9);
        bufp->chgIData(oldp+108,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res, 1U)),32);
        bufp->chgCData(oldp+109,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__LDZ__DOT__found_index),5);
        bufp->chgBit(oldp+110,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize));
        bufp->chgSData(oldp+111,((0x000001ffU & ((IData)(0x0081U) 
                                                 - (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res)))),9);
        bufp->chgIData(oldp+112,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig),32);
        bufp->chgBit(oldp+113,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 8U))));
        bufp->chgBit(oldp+114,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 7U))));
        bufp->chgBit(oldp+115,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 6U))));
        bufp->chgBit(oldp+116,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__stickyBit));
        bufp->chgBit(oldp+117,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre));
        bufp->chgIData(oldp+118,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                                  >> 8U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre)))),24);
        bufp->chgBit(oldp+119,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__sig_cout));
        bufp->chgBit(oldp+120,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx));
        bufp->chgBit(oldp+121,((0x017fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp))));
        bufp->chgIData(oldp+122,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__data),32);
        bufp->chgCData(oldp+123,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt),6);
        bufp->chgCData(oldp+124,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))),5);
        bufp->chgIData(oldp+125,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig),32);
        bufp->chgIData(oldp+126,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                  >> 8U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre)))),24);
        bufp->chgBit(oldp+127,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout));
        bufp->chgBit(oldp+128,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 8U))));
        bufp->chgBit(oldp+129,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 7U))));
        bufp->chgBit(oldp+130,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 6U))));
        bufp->chgBit(oldp+131,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__stickyBit));
        bufp->chgBit(oldp+132,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre));
        bufp->chgCData(oldp+133,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__LDZ__DOT__found_index),5);
        bufp->chgCData(oldp+134,((0x0000001fU & ((IData)(0x1fU) 
                                                 - (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),5);
        bufp->chgQData(oldp+135,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig),64);
        bufp->chgIData(oldp+137,((IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                          >> 0x00000020U))),32);
        bufp->chgIData(oldp+138,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres),32);
        bufp->chgBit(oldp+139,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x00000020U)))));
        bufp->chgBit(oldp+140,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x0000001fU)))));
        bufp->chgBit(oldp+141,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x0000001eU)))));
        bufp->chgBit(oldp+142,((0U != (0x3fffffffU 
                                       & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig)))));
        bufp->chgBit(oldp+143,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__roundIncre));
        bufp->chgBit(oldp+144,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of));
        bufp->chgIData(oldp+145,((0x7fffffffU & ((IData)(1U) 
                                                 + 
                                                 (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),31);
        bufp->chgBit(oldp+146,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isZero));
        bufp->chgBit(oldp+147,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isUnormalize));
        bufp->chgBit(oldp+148,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isNormalize));
        bufp->chgCData(oldp+149,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos),6);
        bufp->chgCData(oldp+150,((0x0000001fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos)))),5);
        bufp->chgCData(oldp+151,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos))),5);
        bufp->chgCData(oldp+152,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__LZD__DOT__found_index),5);
        bufp->chgBit(oldp+153,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isZero));
        bufp->chgBit(oldp+154,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isUnormalize));
        bufp->chgBit(oldp+155,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isNormalize));
        bufp->chgCData(oldp+156,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos),6);
        bufp->chgCData(oldp+157,((0x0000001fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos)))),5);
        bufp->chgCData(oldp+158,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos))),5);
        bufp->chgCData(oldp+159,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__LZD__DOT__found_index),5);
        bufp->chgCData(oldp+160,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                   ? 0x000000ffU : 
                                  ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                    ? 0x000000ffU : 
                                   ((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                  >> 6U)))
                                     ? 0U : (((0x006bU 
                                               <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                              & (0x0081U 
                                                 >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                              ? 0U : 
                                             (((0x0082U 
                                                <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                               & (0x017fU 
                                                  >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                               ? (0x000000ffU 
                                                  & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                     - (IData)(0x81U)))
                                               : 0x000000ffU)))))),8);
        bufp->chgIData(oldp+161,((0x007fffffU & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                                  ? 
                                                 (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                                  >> 9U)
                                                  : 
                                                 ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                                   ? 0U
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                        >> 6U)))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                                    >> 8U)))))),23);
        bufp->chgBit(oldp+162,((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                             >> 6U)))));
        bufp->chgBit(oldp+163,(((0x0082U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                & (0x017fU >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
        bufp->chgBit(oldp+164,(((0x006bU <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                & (0x0081U >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    }
    bufp->chgBit(oldp+165,(vlSelfRef.testbench__DOT__clk));
    bufp->chgBit(oldp+166,((((1U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                             & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                            | (((3U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                                & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                               | (0U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
    bufp->chgCData(oldp+167,(vlSelfRef.testbench__DOT__dut__DOT__current_state),3);
    bufp->chgCData(oldp+168,(((4U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
                               ? 0U : ((2U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
                                        ? ((1U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
                                            ? ((0U 
                                                == (IData)(vlSelfRef.testbench__DOT__sel))
                                                ? 2U
                                                : 3U)
                                            : ((((0U 
                                                  == (IData)(vlSelfRef.testbench__DOT__sel))
                                                  ? 
                                                 ((0U 
                                                   == (IData)(vlSelfRef.testbench__DOT__sel)) 
                                                  & (IData)(vlSelfRef.testbench__DOT__i_valid))
                                                  : (IData)(vlSelfRef.testbench__DOT__i_valid)) 
                                                & (IData)(vlSelfRef.testbench__DOT__o_ready))
                                                ? 0U
                                                : 2U))
                                        : ((1U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
                                            ? ((0U 
                                                == (IData)(vlSelfRef.testbench__DOT__sel))
                                                ? 2U
                                                : 1U)
                                            : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1) 
                                                & (0U 
                                                   == (IData)(vlSelfRef.testbench__DOT__sel)))
                                                ? 2U
                                                : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                                    ? 3U
                                                    : 
                                                   (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                     & (0U 
                                                        == (IData)(vlSelfRef.testbench__DOT__sel)))
                                                     ? 1U
                                                     : 0U))))))),3);
    bufp->chgBit(oldp+169,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                            & ((IData)(vlSelfRef.testbench__DOT__o_ready) 
                               & (2U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
}

void Vtestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_cleanup\n"); );
    // Body
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
