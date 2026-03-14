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
        bufp->chgIData(oldp+36,(((vlSelfRef.testbench__DOT__ina 
                                  >> 0x0000001fU) ? 
                                 ((IData)(1U) + (~ vlSelfRef.testbench__DOT__ina))
                                  : vlSelfRef.testbench__DOT__ina)),32);
        bufp->chgIData(oldp+37,(((vlSelfRef.testbench__DOT__fina 
                                  >> 0x0000001fU) ? 0x80000000U
                                  : 0x7fffffffU)),32);
        bufp->chgIData(oldp+38,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__fina, 9U)),32);
        bufp->chgCData(oldp+39,((0x000000ffU & (vlSelfRef.testbench__DOT__finb 
                                                >> 0x00000017U))),8);
        bufp->chgIData(oldp+40,((0x007fffffU & vlSelfRef.testbench__DOT__finb)),23);
        bufp->chgIData(oldp+41,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__finb, 9U)),32);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [1U] | vlSelfRef.__Vm_traceActivity
                        [2U]) | vlSelfRef.__Vm_traceActivity
                       [3U]) | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgCData(oldp+42,(((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_2)
                                  ? (((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                      << 4U) | (((0x017fU 
                                                  < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                                 << 2U) 
                                                | ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                                     & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx)) 
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
        bufp->chgIData(oldp+43,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)) 
                                 & (vlSelfRef.testbench__DOT__fina 
                                    == vlSelfRef.testbench__DOT__finb))),32);
        bufp->chgIData(oldp+44,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                  ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                           ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                           : ((vlSelfRef.testbench__DOT__fina 
                                               >> 0x0000001fU)
                                               ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  > (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                               : (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab))))),32);
        bufp->chgIData(oldp+45,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                  ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                           ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                           : ((vlSelfRef.testbench__DOT__fina 
                                               >> 0x0000001fU)
                                               ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                               : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
        bufp->chgIData(oldp+46,((((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1) 
                                  << 0x0000001fU) | 
                                 (0x7fffffffU & vlSelfRef.testbench__DOT__fina))),32);
        bufp->chgIData(oldp+47,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
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
        bufp->chgBit(oldp+48,((1U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op)
                                      ? (vlSelfRef.testbench__DOT__fina 
                                         >> 0x0000001fU)
                                      : (vlSelfRef.testbench__DOT__finb 
                                         >> 0x0000001fU)))));
        bufp->chgBit(oldp+49,(((vlSelfRef.testbench__DOT__fina 
                                >> 0x0000001fU) ? (0U 
                                                   != vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)
                                : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
        bufp->chgBit(oldp+50,(((vlSelfRef.testbench__DOT__fina 
                                >> 0x0000001fU) ? (
                                                   (0x0120U 
                                                    < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                   | ((0x0120U 
                                                       == (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                      & (0x80000000U 
                                                         != vlSelfRef.testbench__DOT__dut__DOT__sig_a)))
                                : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
        bufp->chgIData(oldp+51,(((vlSelfRef.testbench__DOT__fina 
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
        bufp->chgIData(oldp+52,(vlSelfRef.testbench__DOT__dut__DOT__fresult),32);
        bufp->chgSData(oldp+53,(vlSelfRef.testbench__DOT__dut__DOT__exp_a),9);
        bufp->chgIData(oldp+54,(vlSelfRef.testbench__DOT__dut__DOT__sig_a),32);
        bufp->chgBit(oldp+55,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan));
        bufp->chgBit(oldp+56,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf));
        bufp->chgSData(oldp+57,(vlSelfRef.testbench__DOT__dut__DOT__exp_b),9);
        bufp->chgIData(oldp+58,(vlSelfRef.testbench__DOT__dut__DOT__sig_b),32);
        bufp->chgBit(oldp+59,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isNAN));
        bufp->chgBit(oldp+60,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isINf));
        bufp->chgBit(oldp+61,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sign));
        bufp->chgIData(oldp+62,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig),32);
        bufp->chgSData(oldp+63,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp),9);
        bufp->chgBit(oldp+64,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN));
        bufp->chgBit(oldp+65,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf));
        bufp->chgCData(oldp+66,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                  << 4U) | (((0x017fU 
                                              < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                             << 2U) 
                                            | ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                                 & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx)) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))))),5);
        bufp->chgIData(oldp+67,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sign) 
                                  << 0x0000001fU) | 
                                 ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                     ? 0x000000ffU : 
                                    ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                      ? 0x000000ffU
                                      : ((0U == (7U 
                                                 & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                    >> 6U)))
                                          ? 0U : ((
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
                                  | (0x007fffffU & 
                                     ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                       ? (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                          >> 9U) : 
                                      ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                        ? 0U : ((0U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                     >> 6U)))
                                                 ? 0U
                                                 : 
                                                (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                                 >> 8U)))))))),32);
        bufp->chgCData(oldp+68,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                 << 4U)),5);
        bufp->chgIData(oldp+69,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                                  ? 0xffffffffU : vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)),32);
        bufp->chgBit(oldp+70,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                               | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                  | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)))));
        bufp->chgBit(oldp+71,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                               & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1))));
        bufp->chgCData(oldp+72,(((((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                                   | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                      | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of))) 
                                  << 4U) | ((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                                            & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1)))),5);
        bufp->chgBit(oldp+73,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sign));
        bufp->chgCData(oldp+74,((0x000000ffU & ((IData)(0x7fU) 
                                                + (
                                                   ((IData)(0x1fU) 
                                                    - 
                                                    (0x0000001fU 
                                                     & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))) 
                                                   + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout))))),8);
        bufp->chgIData(oldp+75,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout)
                                  ? 0x00800000U : (0x00ffffffU 
                                                   & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                       >> 8U) 
                                                      + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre))))),24);
        bufp->chgIData(oldp+76,(vlSelfRef.testbench__DOT__dut__DOT__fcxs_fresult),32);
        bufp->chgBit(oldp+77,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx));
        bufp->chgCData(oldp+78,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx),5);
        bufp->chgBit(oldp+79,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab));
        bufp->chgSData(oldp+80,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff),9);
        bufp->chgCData(oldp+81,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_amt),6);
        bufp->chgQData(oldp+82,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a),64);
        bufp->chgQData(oldp+84,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b),64);
        bufp->chgBit(oldp+86,((0U != (0x000000ffffffffffULL 
                                      & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))));
        bufp->chgBit(oldp+87,((0U != (0x000000ffffffffffULL 
                                      & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))));
        bufp->chgBit(oldp+88,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab)
                                ? (0U != (0x000000ffffffffffULL 
                                          & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                                : (0U != (0x000000ffffffffffULL 
                                          & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b)))));
        bufp->chgIData(oldp+89,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                         >> 0x00000020U))),32);
        bufp->chgIData(oldp+90,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                         >> 0x00000020U))),32);
        bufp->chgBit(oldp+91,((1U & (IData)((1ULL & 
                                             (((QData)((IData)(
                                                               (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                                >> 0x00000020U))) 
                                               + (QData)((IData)(
                                                                 (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                                  >> 0x00000020U)))) 
                                              >> 0x00000020U))))));
        bufp->chgBit(oldp+92,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__is_effsub));
        bufp->chgBit(oldp+93,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op));
        bufp->chgIData(oldp+94,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op)
                                  ? ((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                              >> 0x00000020U)) 
                                     - (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                >> 0x00000020U)))
                                  : ((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                              >> 0x00000020U)) 
                                     - (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                >> 0x00000020U))))),32);
        bufp->chgIData(oldp+95,(((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                          >> 0x00000020U)) 
                                 + (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                            >> 0x00000020U)))),32);
        bufp->chgIData(oldp+96,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_sub_res),32);
        bufp->chgBit(oldp+97,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__of));
        bufp->chgCData(oldp+98,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos),6);
        bufp->chgCData(oldp+99,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos))),5);
        bufp->chgIData(oldp+100,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_sig_res),32);
        bufp->chgBit(oldp+101,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__of) 
                                 & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_sub_res) 
                                | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab)
                                    ? (0U != (0x000000ffffffffffULL 
                                              & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                                    : (0U != (0x000000ffffffffffULL 
                                              & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))))));
        bufp->chgSData(oldp+102,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res),9);
        bufp->chgCData(oldp+103,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__LDZ__DOT__found_index),5);
        bufp->chgBit(oldp+104,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize));
        bufp->chgSData(oldp+105,((0x000001ffU & ((IData)(0x0081U) 
                                                 - (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res)))),9);
        bufp->chgIData(oldp+106,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig),32);
        bufp->chgBit(oldp+107,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 8U))));
        bufp->chgBit(oldp+108,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 7U))));
        bufp->chgBit(oldp+109,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                      >> 6U))));
        bufp->chgBit(oldp+110,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__stickyBit));
        bufp->chgBit(oldp+111,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre));
        bufp->chgIData(oldp+112,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                                  >> 8U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre)))),24);
        bufp->chgBit(oldp+113,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__sig_cout));
        bufp->chgBit(oldp+114,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx));
        bufp->chgBit(oldp+115,((0x017fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp))));
        bufp->chgBit(oldp+116,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))));
        bufp->chgIData(oldp+117,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__data),32);
        bufp->chgCData(oldp+118,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt),6);
        bufp->chgCData(oldp+119,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))),5);
        bufp->chgIData(oldp+120,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig),32);
        bufp->chgIData(oldp+121,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                  >> 8U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre)))),24);
        bufp->chgBit(oldp+122,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout));
        bufp->chgBit(oldp+123,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 8U))));
        bufp->chgBit(oldp+124,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 7U))));
        bufp->chgBit(oldp+125,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                      >> 6U))));
        bufp->chgBit(oldp+126,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__stickyBit));
        bufp->chgBit(oldp+127,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre));
        bufp->chgCData(oldp+128,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__LDZ__DOT__found_index),5);
        bufp->chgCData(oldp+129,((0x0000001fU & ((IData)(0x1fU) 
                                                 - (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),5);
        bufp->chgQData(oldp+130,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig),64);
        bufp->chgIData(oldp+132,((IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                          >> 0x00000020U))),32);
        bufp->chgIData(oldp+133,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres),32);
        bufp->chgBit(oldp+134,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x00000020U)))));
        bufp->chgBit(oldp+135,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x0000001fU)))));
        bufp->chgBit(oldp+136,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                              >> 0x0000001eU)))));
        bufp->chgBit(oldp+137,((0U != (0x3fffffffU 
                                       & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig)))));
        bufp->chgBit(oldp+138,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__roundIncre));
        bufp->chgBit(oldp+139,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of));
        bufp->chgIData(oldp+140,((0x7fffffffU & ((IData)(1U) 
                                                 + 
                                                 (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),31);
        bufp->chgBit(oldp+141,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isZero));
        bufp->chgBit(oldp+142,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isUnormalize));
        bufp->chgBit(oldp+143,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isNormalize));
        bufp->chgCData(oldp+144,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos),6);
        bufp->chgCData(oldp+145,((0x0000001fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos)))),5);
        bufp->chgCData(oldp+146,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos))),5);
        bufp->chgCData(oldp+147,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__LZD__DOT__found_index),5);
        bufp->chgBit(oldp+148,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isZero));
        bufp->chgBit(oldp+149,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isUnormalize));
        bufp->chgBit(oldp+150,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isNormalize));
        bufp->chgCData(oldp+151,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos),6);
        bufp->chgCData(oldp+152,((0x0000001fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos)))),5);
        bufp->chgCData(oldp+153,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos))),5);
        bufp->chgCData(oldp+154,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__LZD__DOT__found_index),5);
        bufp->chgCData(oldp+155,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
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
        bufp->chgIData(oldp+156,((0x007fffffU & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
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
        bufp->chgBit(oldp+157,((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                             >> 6U)))));
        bufp->chgBit(oldp+158,(((0x0082U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                & (0x017fU >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
        bufp->chgBit(oldp+159,(((0x006bU <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                & (0x0081U >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    }
    bufp->chgBit(oldp+160,(vlSelfRef.testbench__DOT__clk));
    bufp->chgBit(oldp+161,((((1U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                             & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                            | (((3U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                                & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                               | (0U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
    bufp->chgCData(oldp+162,(vlSelfRef.testbench__DOT__dut__DOT__current_state),3);
    bufp->chgCData(oldp+163,(((4U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
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
    bufp->chgBit(oldp+164,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
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
