// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtestbench__Syms.h"


VL_ATTR_COLD void Vtestbench___024root__trace_init_sub__TOP__0(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_init_sub__TOP__0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("testbench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"FDATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+161,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"i_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"i_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"fina",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"finb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"ina",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"file_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"file_log",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+12,0,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+13,0,"exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"exp_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+15,0,"vector_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+16,0,"error_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"FDATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"FDATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"SIG_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+161,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"fina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"finb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"ina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"fresult",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+17,0,"fadd_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"fsub_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"feq_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"flt_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"fle_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"fsgnj_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"fsgnjn_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"fsgnjx_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"fcvt_w_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"fcvt_wu_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"fcvt_s_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"fcvt_s_wu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"add_fina_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"add_finb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_fresult_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+174,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+175,0,"WAIT_A_READY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+176,0,"WAIT_B_READY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+177,0,"WORK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+163,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+164,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+17,0,"fa_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"fb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_fina_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_finb_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"add_fresult_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+55,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"isNAN_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"isINf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+59,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+60,0,"isNAN_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"isINf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"add_sub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"add_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"add_res_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"add_res_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+65,0,"add_res_isNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"add_res_isINf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"add_res_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+62,0,"sign_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+63,0,"sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"isNAN_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"isINf_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"fpu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"feq_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"flt_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"flt_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+46,0,"fle_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"fle_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+30,0,"st_sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"st_exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+33,0,"st_fra_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+31,0,"st_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"fsgnj_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"fsgnjn_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"fsgnjx_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"fcss_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"fcsu_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+71,0,"cvt_fw_nv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"cvt_fw_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"fcvt_w_s_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+74,0,"fcxs_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"fcxs_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"fcxs_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+77,0,"fcxs_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"cvt_wf_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"fcvt_s_w_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("FADD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+167,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"FLA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"SIG_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+161,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"areset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"s_axis_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s_axis_frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+29,0,"s_axis_a_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"s_axis_a_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"s_axis_a_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"s_axis_a_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"s_axis_a_exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+56,0,"s_axis_a_isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"s_axis_a_isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"s_axis_b_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"s_axis_b_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"s_axis_b_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"s_axis_b_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"s_axis_b_exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+60,0,"s_axis_b_isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"s_axis_b_isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"m_axis_res_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"m_axis_res_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"m_axis_res_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"m_axis_res_sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"m_axis_res_exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+65,0,"m_axis_res_isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"m_axis_res_isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"m_axis_res_fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+30,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+31,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+18,0,"is_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"comp_exp_ab",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+82,0,"sig_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declQuad(c+83,0,"full_sigShift_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+85,0,"full_sigShift_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+87,0,"sticky_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"sticky_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"sticky_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"sigShift_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"sigShift_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+92,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"sel_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"is_effsub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"comp_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"eff_sub_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"eff_sub_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"eff_add_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+30,0,"eff_add_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"add_sub_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+62,0,"add_sub_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+100,0,"lamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+101,0,"s_sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+102,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"s_exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+65,0,"res_isNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"res_isINf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"o_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"o_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+62,0,"o_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+67,0,"fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LDZ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+180,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+104,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("ROUND", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+62,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"Insticky",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"nv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"dz",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+67,0,"fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+63,0,"o_sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"o_exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+62,0,"o_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"Unormalize_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+107,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+114,0,"sig_cout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"uf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("cvt_s_x", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"BIAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"u_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"xdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+74,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+78,0,"nx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"uint_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"int_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"full_shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+120,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+121,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+123,0,"sigcout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("LDZ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+180,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+129,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("cvt_x_s", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"u_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+55,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"w_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"wu_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+56,0,"isnan",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"isinf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"nv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"nx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+183,0,"RE_DATAWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declQuad(c+131,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+133,0,"shift_xdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+135,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"overflow_wu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"overflow_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+141,0,"neg_sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+52,0,"comp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"of_wres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("torecFN_a", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"FP_LOG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+5,0,"fp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+30,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+55,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+33,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+142,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+145,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+146,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+147,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LZD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+180,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+148,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("torecFN_b", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"FP_LOG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+6,0,"fp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+31,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+59,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+60,0,"isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"sign_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+149,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+153,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+154,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LZD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+180,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+155,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tostdFN", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+62,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+63,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"fp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+157,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+158,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->addConstCb(&Vtestbench___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtestbench___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtestbench___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtestbench___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_const_0\n"); );
    // Body
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtestbench___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_const_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+166,(0x00000020U),32);
    bufp->fullIData(oldp+167,(3U),32);
    bufp->fullIData(oldp+168,(0x0000000aU),32);
    bufp->fullIData(oldp+169,(5U),32);
    bufp->fullIData(oldp+170,(0x00000017U),32);
    bufp->fullIData(oldp+171,(8U),32);
    bufp->fullSData(oldp+172,(0x0081U),9);
    bufp->fullBit(oldp+173,(1U));
    bufp->fullCData(oldp+174,(0U),3);
    bufp->fullCData(oldp+175,(1U),3);
    bufp->fullCData(oldp+176,(3U),3);
    bufp->fullCData(oldp+177,(2U),3);
    bufp->fullIData(oldp+178,(0x00000018U),32);
    bufp->fullIData(oldp+179,(9U),32);
    bufp->fullIData(oldp+180,(0x00000020U),32);
    bufp->fullBit(oldp+181,(0U));
    bufp->fullIData(oldp+182,(0x0000007fU),32);
    bufp->fullIData(oldp+183,(0x00000120U),32);
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0\n"); );
    // Body
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtestbench___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0_sub_0\n"); );
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.testbench__DOT__rst));
    bufp->fullBit(oldp+2,(vlSelfRef.testbench__DOT__i_valid));
    bufp->fullCData(oldp+3,(vlSelfRef.testbench__DOT__sel),4);
    bufp->fullCData(oldp+4,(vlSelfRef.testbench__DOT__frm),3);
    bufp->fullIData(oldp+5,(vlSelfRef.testbench__DOT__fina),32);
    bufp->fullIData(oldp+6,(vlSelfRef.testbench__DOT__finb),32);
    bufp->fullIData(oldp+7,(vlSelfRef.testbench__DOT__ina),32);
    bufp->fullBit(oldp+8,(((0U == (IData)(vlSelfRef.testbench__DOT__sel))
                            ? ((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                               & (IData)(vlSelfRef.testbench__DOT__i_valid))
                            : (IData)(vlSelfRef.testbench__DOT__i_valid))));
    bufp->fullBit(oldp+9,(vlSelfRef.testbench__DOT__o_ready));
    bufp->fullIData(oldp+10,(vlSelfRef.testbench__DOT__file_in),32);
    bufp->fullIData(oldp+11,(vlSelfRef.testbench__DOT__file_log),32);
    bufp->fullIData(oldp+12,(vlSelfRef.testbench__DOT__status),32);
    bufp->fullIData(oldp+13,(vlSelfRef.testbench__DOT__exp_res),32);
    bufp->fullCData(oldp+14,(vlSelfRef.testbench__DOT__exp_fflags),5);
    bufp->fullIData(oldp+15,(vlSelfRef.testbench__DOT__vector_cnt),32);
    bufp->fullIData(oldp+16,(vlSelfRef.testbench__DOT__error_cnt),32);
    bufp->fullBit(oldp+17,((0U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+18,((1U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+19,((4U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+20,((5U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+21,((6U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+22,((7U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+23,((8U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+24,((9U == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+25,((0x0aU == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+26,((0x0bU == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+27,((0x0cU == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+28,((0x0dU == (IData)(vlSelfRef.testbench__DOT__sel))));
    bufp->fullBit(oldp+29,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                            & (IData)(vlSelfRef.testbench__DOT__i_valid))));
    bufp->fullBit(oldp+30,((vlSelfRef.testbench__DOT__fina 
                            >> 0x0000001fU)));
    bufp->fullBit(oldp+31,((vlSelfRef.testbench__DOT__finb 
                            >> 0x0000001fU)));
    bufp->fullCData(oldp+32,((0x000000ffU & (vlSelfRef.testbench__DOT__fina 
                                             >> 0x00000017U))),8);
    bufp->fullIData(oldp+33,((0x007fffffU & vlSelfRef.testbench__DOT__fina)),23);
    bufp->fullIData(oldp+34,(((0x80000000U & vlSelfRef.testbench__DOT__finb) 
                              | (0x7fffffffU & vlSelfRef.testbench__DOT__fina))),32);
    bufp->fullIData(oldp+35,((((~ (vlSelfRef.testbench__DOT__finb 
                                   >> 0x0000001fU)) 
                               << 0x0000001fU) | (0x7fffffffU 
                                                  & vlSelfRef.testbench__DOT__fina))),32);
    bufp->fullBit(oldp+36,(((vlSelfRef.testbench__DOT__finb 
                             >> 0x0000001fU) ^ (1U 
                                                == (IData)(vlSelfRef.testbench__DOT__sel)))));
    bufp->fullIData(oldp+37,(((vlSelfRef.testbench__DOT__ina 
                               >> 0x0000001fU) ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSelfRef.testbench__DOT__ina))
                               : vlSelfRef.testbench__DOT__ina)),32);
    bufp->fullIData(oldp+38,(((vlSelfRef.testbench__DOT__fina 
                               >> 0x0000001fU) ? 0x80000000U
                               : 0x7fffffffU)),32);
    bufp->fullIData(oldp+39,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__fina, 9U)),32);
    bufp->fullCData(oldp+40,((0x000000ffU & (vlSelfRef.testbench__DOT__finb 
                                             >> 0x00000017U))),8);
    bufp->fullIData(oldp+41,((0x007fffffU & vlSelfRef.testbench__DOT__finb)),23);
    bufp->fullIData(oldp+42,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__finb, 9U)),32);
    bufp->fullCData(oldp+43,(((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_2)
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
                                                ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                                                   << 4U)
                                                : (
                                                   ((0x0aU 
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
    bufp->fullIData(oldp+44,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)) 
                              & (vlSelfRef.testbench__DOT__fina 
                                 == vlSelfRef.testbench__DOT__finb))),32);
    bufp->fullIData(oldp+45,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                               ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                        : ((vlSelfRef.testbench__DOT__fina 
                                            >> 0x0000001fU)
                                            ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               > (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                            : (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab))))),32);
    bufp->fullIData(oldp+46,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                               ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                        : ((vlSelfRef.testbench__DOT__fina 
                                            >> 0x0000001fU)
                                            ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                            : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
    bufp->fullIData(oldp+47,((((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1) 
                               << 0x0000001fU) | (0x7fffffffU 
                                                  & vlSelfRef.testbench__DOT__fina))),32);
    bufp->fullIData(oldp+48,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                               ? ((vlSelfRef.testbench__DOT__fina 
                                   >> 0x0000001fU) ? 0x80000000U
                                   : 0x7fffffffU) : 
                              ((vlSelfRef.testbench__DOT__fina 
                                >> 0x0000001fU) ? (0x80000000U 
                                                   | (0x7fffffffU 
                                                      & ((IData)(1U) 
                                                         + 
                                                         (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))))
                                : (0x7fffffffU & vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),32);
    bufp->fullBit(oldp+49,((1U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op)
                                   ? (vlSelfRef.testbench__DOT__fina 
                                      >> 0x0000001fU)
                                   : (vlSelfRef.testbench__DOT__finb 
                                      >> 0x0000001fU)))));
    bufp->fullBit(oldp+50,(((vlSelfRef.testbench__DOT__fina 
                             >> 0x0000001fU) ? (0U 
                                                != vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)
                             : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
    bufp->fullBit(oldp+51,(((vlSelfRef.testbench__DOT__fina 
                             >> 0x0000001fU) ? ((0x0120U 
                                                 < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                | ((0x0120U 
                                                    == (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                   & (0x80000000U 
                                                      != vlSelfRef.testbench__DOT__dut__DOT__sig_a)))
                             : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
    bufp->fullIData(oldp+52,(((vlSelfRef.testbench__DOT__fina 
                               >> 0x0000001fU) ? (0x80000000U 
                                                  | (0x7fffffffU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))))
                               : (0x7fffffffU & vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))),32);
    bufp->fullIData(oldp+53,(vlSelfRef.testbench__DOT__dut__DOT__fresult),32);
    bufp->fullSData(oldp+54,(vlSelfRef.testbench__DOT__dut__DOT__exp_a),9);
    bufp->fullIData(oldp+55,(vlSelfRef.testbench__DOT__dut__DOT__sig_a),32);
    bufp->fullBit(oldp+56,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan));
    bufp->fullBit(oldp+57,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf));
    bufp->fullSData(oldp+58,(vlSelfRef.testbench__DOT__dut__DOT__exp_b),9);
    bufp->fullIData(oldp+59,(vlSelfRef.testbench__DOT__dut__DOT__sig_b),32);
    bufp->fullBit(oldp+60,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isNAN));
    bufp->fullBit(oldp+61,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isINf));
    bufp->fullBit(oldp+62,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sign));
    bufp->fullIData(oldp+63,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig),32);
    bufp->fullSData(oldp+64,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp),9);
    bufp->fullBit(oldp+65,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN));
    bufp->fullBit(oldp+66,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf));
    bufp->fullCData(oldp+67,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                               << 4U) | (((0x017fU 
                                           < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                          << 2U) | 
                                         ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                            & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx)) 
                                           << 1U) | (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))))),5);
    bufp->fullIData(oldp+68,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sign) 
                               << 0x0000001fU) | ((
                                                   ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                                     ? 0x000000ffU
                                                     : 
                                                    ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                                      ? 0x000000ffU
                                                      : 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                           >> 6U)))
                                                       ? 0U
                                                       : 
                                                      (((0x006bU 
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
                                                           >> 8U)))))))),32);
    bufp->fullCData(oldp+69,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                              << 4U)),5);
    bufp->fullIData(oldp+70,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                               ? 0xffffffffU : vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)),32);
    bufp->fullBit(oldp+71,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                            | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                               | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)))));
    bufp->fullBit(oldp+72,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                            & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1))));
    bufp->fullCData(oldp+73,(((((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                                | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                   | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of))) 
                               << 4U) | ((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                                         & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1)))),5);
    bufp->fullBit(oldp+74,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sign));
    bufp->fullCData(oldp+75,((0x000000ffU & ((IData)(0x7fU) 
                                             + (((IData)(0x1fU) 
                                                 - 
                                                 (0x0000001fU 
                                                  & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))) 
                                                + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout))))),8);
    bufp->fullIData(oldp+76,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout)
                               ? 0x00800000U : (0x00ffffffU 
                                                & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                    >> 8U) 
                                                   + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre))))),24);
    bufp->fullIData(oldp+77,(vlSelfRef.testbench__DOT__dut__DOT__fcxs_fresult),32);
    bufp->fullBit(oldp+78,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx));
    bufp->fullCData(oldp+79,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx),5);
    bufp->fullBit(oldp+80,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab));
    bufp->fullSData(oldp+81,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff),9);
    bufp->fullCData(oldp+82,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_amt),6);
    bufp->fullQData(oldp+83,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a),64);
    bufp->fullQData(oldp+85,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b),64);
    bufp->fullBit(oldp+87,((0U != (0x000000ffffffffffULL 
                                   & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))));
    bufp->fullBit(oldp+88,((0U != (0x000000ffffffffffULL 
                                   & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))));
    bufp->fullBit(oldp+89,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab)
                             ? (0U != (0x000000ffffffffffULL 
                                       & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                             : (0U != (0x000000ffffffffffULL 
                                       & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b)))));
    bufp->fullIData(oldp+90,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                      >> 0x00000020U))),32);
    bufp->fullIData(oldp+91,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                      >> 0x00000020U))),32);
    bufp->fullBit(oldp+92,((1U & (IData)((1ULL & (((QData)((IData)(
                                                                   (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                                    >> 0x00000020U))) 
                                                   + (QData)((IData)(
                                                                     (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                                      >> 0x00000020U)))) 
                                                  >> 0x00000020U))))));
    bufp->fullBit(oldp+93,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__is_effsub));
    bufp->fullBit(oldp+94,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op));
    bufp->fullIData(oldp+95,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_op)
                               ? ((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                           >> 0x00000020U)) 
                                  - (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                             >> 0x00000020U)))
                               : ((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                           >> 0x00000020U)) 
                                  - (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                             >> 0x00000020U))))),32);
    bufp->fullIData(oldp+96,(((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                       >> 0x00000020U)) 
                              + (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                         >> 0x00000020U)))),32);
    bufp->fullIData(oldp+97,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_sub_res),32);
    bufp->fullBit(oldp+98,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__of));
    bufp->fullCData(oldp+99,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos),6);
    bufp->fullCData(oldp+100,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos))),5);
    bufp->fullIData(oldp+101,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_sig_res),32);
    bufp->fullBit(oldp+102,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__of) 
                              & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_sub_res) 
                             | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__comp_exp_ab)
                                 ? (0U != (0x000000ffffffffffULL 
                                           & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                                 : (0U != (0x000000ffffffffffULL 
                                           & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))))));
    bufp->fullSData(oldp+103,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res),9);
    bufp->fullCData(oldp+104,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__LDZ__DOT__found_index),5);
    bufp->fullBit(oldp+105,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize));
    bufp->fullSData(oldp+106,((0x000001ffU & ((IData)(0x0081U) 
                                              - (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res)))),9);
    bufp->fullIData(oldp+107,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig),32);
    bufp->fullBit(oldp+108,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 8U))));
    bufp->fullBit(oldp+109,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 7U))));
    bufp->fullBit(oldp+110,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 6U))));
    bufp->fullBit(oldp+111,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__stickyBit));
    bufp->fullBit(oldp+112,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre));
    bufp->fullIData(oldp+113,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                               >> 8U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre)))),24);
    bufp->fullBit(oldp+114,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__sig_cout));
    bufp->fullBit(oldp+115,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx));
    bufp->fullBit(oldp+116,((0x017fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp))));
    bufp->fullBit(oldp+117,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                             & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))));
    bufp->fullIData(oldp+118,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__data),32);
    bufp->fullCData(oldp+119,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt),6);
    bufp->fullCData(oldp+120,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))),5);
    bufp->fullIData(oldp+121,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig),32);
    bufp->fullIData(oldp+122,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                               >> 8U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre)))),24);
    bufp->fullBit(oldp+123,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout));
    bufp->fullBit(oldp+124,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 8U))));
    bufp->fullBit(oldp+125,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 7U))));
    bufp->fullBit(oldp+126,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 6U))));
    bufp->fullBit(oldp+127,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__stickyBit));
    bufp->fullBit(oldp+128,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre));
    bufp->fullCData(oldp+129,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__LDZ__DOT__found_index),5);
    bufp->fullCData(oldp+130,((0x0000001fU & ((IData)(0x1fU) 
                                              - (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),5);
    bufp->fullQData(oldp+131,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig),64);
    bufp->fullIData(oldp+133,((IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                       >> 0x00000020U))),32);
    bufp->fullIData(oldp+134,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres),32);
    bufp->fullBit(oldp+135,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x00000020U)))));
    bufp->fullBit(oldp+136,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x0000001fU)))));
    bufp->fullBit(oldp+137,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x0000001eU)))));
    bufp->fullBit(oldp+138,((0U != (0x3fffffffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig)))));
    bufp->fullBit(oldp+139,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__roundIncre));
    bufp->fullBit(oldp+140,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of));
    bufp->fullIData(oldp+141,((0x7fffffffU & ((IData)(1U) 
                                              + (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),31);
    bufp->fullBit(oldp+142,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isZero));
    bufp->fullBit(oldp+143,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isUnormalize));
    bufp->fullBit(oldp+144,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isNormalize));
    bufp->fullCData(oldp+145,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos),6);
    bufp->fullCData(oldp+146,((0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos)))),5);
    bufp->fullCData(oldp+147,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos))),5);
    bufp->fullCData(oldp+148,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__LZD__DOT__found_index),5);
    bufp->fullBit(oldp+149,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isZero));
    bufp->fullBit(oldp+150,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isUnormalize));
    bufp->fullBit(oldp+151,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isNormalize));
    bufp->fullCData(oldp+152,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos),6);
    bufp->fullCData(oldp+153,((0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos)))),5);
    bufp->fullCData(oldp+154,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos))),5);
    bufp->fullCData(oldp+155,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__LZD__DOT__found_index),5);
    bufp->fullCData(oldp+156,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                ? 0x000000ffU : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                                  ? 0x000000ffU
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                       >> 6U)))
                                                   ? 0U
                                                   : 
                                                  (((0x006bU 
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
                                                     : 0x000000ffU)))))),8);
    bufp->fullIData(oldp+157,((0x007fffffU & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                               ? (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig 
                                                  >> 9U)
                                               : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
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
    bufp->fullBit(oldp+158,((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                          >> 6U)))));
    bufp->fullBit(oldp+159,(((0x0082U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                             & (0x017fU >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    bufp->fullBit(oldp+160,(((0x006bU <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                             & (0x0081U >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    bufp->fullBit(oldp+161,(vlSelfRef.testbench__DOT__clk));
    bufp->fullBit(oldp+162,((((1U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                              & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                             | (((3U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                                 & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                                | (0U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
    bufp->fullCData(oldp+163,(vlSelfRef.testbench__DOT__dut__DOT__current_state),3);
    bufp->fullCData(oldp+164,(((4U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
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
                                                 : 
                                                ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                                  ? 3U
                                                  : 
                                                 (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.testbench__DOT__sel)))
                                                   ? 1U
                                                   : 0U))))))),3);
    bufp->fullBit(oldp+165,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                             & ((IData)(vlSelfRef.testbench__DOT__o_ready) 
                                & (2U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
}
