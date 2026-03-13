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
    tracep->declBus(c+171,0,"FDATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+166,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"i_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"i_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"fina",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"finb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"ina",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+58,0,"fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"file_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"file_log",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+12,0,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+13,0,"exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"exp_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+15,0,"vector_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+16,0,"error_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"FDATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"FDATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"SIG_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+166,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"fina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"finb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"ina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+58,0,"fresult",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    tracep->declBit(c+178,0,"add_fina_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"add_finb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_fresult_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+180,0,"WAIT_A_READY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+181,0,"WAIT_B_READY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+182,0,"WORK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+168,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+169,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+17,0,"fa_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"fb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_fina_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"add_finb_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"add_fresult_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+60,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,0,"isNAN_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"isINf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+64,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"isNAN_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"isINf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"add_sub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"add_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"add_res_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"add_res_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+70,0,"add_res_isNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"add_res_isINf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"add_res_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+67,0,"sign_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+68,0,"sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"isNAN_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"isINf_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"fpu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"feq_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"flt_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"flt_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+48,0,"fle_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"fle_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+30,0,"st_sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"st_exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+33,0,"st_fra_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+31,0,"st_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"fsgnj_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"fsgnjn_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"fsgnjx_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"fcss_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"fcsu_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+76,0,"cvt_fw_nv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"cvt_fw_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"fcvt_w_s_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+79,0,"fcxs_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"fcxs_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+81,0,"fcxs_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+82,0,"fcxs_fresult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+83,0,"cvt_wf_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"fcvt_s_w_fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("FADD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+172,0,"FRM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"FLA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"SIG_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+166,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"areset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"s_axis_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s_axis_frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+29,0,"s_axis_a_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"s_axis_a_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"s_axis_a_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"s_axis_a_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"s_axis_a_exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+61,0,"s_axis_a_isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"s_axis_a_isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"s_axis_b_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"s_axis_b_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"s_axis_b_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"s_axis_b_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"s_axis_b_exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+65,0,"s_axis_b_isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axis_b_isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"m_axis_res_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"m_axis_res_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"m_axis_res_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"m_axis_res_sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"m_axis_res_exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+70,0,"m_axis_res_isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"m_axis_res_isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"m_axis_res_fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+30,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+31,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+18,0,"is_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"comp_exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+86,0,"comp_exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+87,0,"neg_exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+88,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+89,0,"neg_exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+90,0,"sign_exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"sig_amt_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+92,0,"sig_amt_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declQuad(c+93,0,"full_sigShift_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+95,0,"full_sigShift_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+97,0,"sticky_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"sticky_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"sticky_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"sigShift_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"sigShift_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"sel_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"sign_a31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+51,0,"neg_sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+38,0,"sign_b31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+52,0,"neg_sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+53,0,"nsig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"nsig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"s_sign_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"add_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+104,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+106,0,"lamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+107,0,"s_sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"s_exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+70,0,"res_isNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"res_isINf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"o_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"o_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+67,0,"o_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+72,0,"fflags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LDZ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+185,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+110,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("ROUND", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+67,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"Insticky",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"nv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"dz",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+72,0,"fflags",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+68,0,"o_sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"o_exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+67,0,"o_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"Unormalize_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+113,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+114,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"sig_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+120,0,"sig_cout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"uf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("cvt_s_x", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"BIAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"u_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"xdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+79,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+81,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+83,0,"nx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"uint_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"int_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"full_shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+125,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+126,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+128,0,"sigcout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("LDZ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+185,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+134,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("cvt_x_s", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"u_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+60,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"w_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"wu_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"frm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+61,0,"isnan",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"isinf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"nv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"nx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+188,0,"RE_DATAWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declQuad(c+136,0,"shift_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+138,0,"shift_xdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+140,0,"lsbBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"guardBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"roundBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"stickyBit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"roundIncre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"of",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"overflow_wu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"overflow_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"neg_sigres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+57,0,"comp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"of_wres",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("torecFN_a", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"FP_LOG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+5,0,"fp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+30,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+60,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,0,"isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+33,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+147,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+151,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+152,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LZD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+185,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+153,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("torecFN_b", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"FP_LOG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+6,0,"fp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+31,0,"sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"exp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+64,0,"sig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"isNAN",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"isINf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"sign_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+154,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+157,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+158,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+159,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("LZD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"DATA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"DATA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+157,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+185,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+160,0,"found_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tostdFN", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"FP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"EXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"FRA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"SIG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"RECEXP_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"EXP_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+67,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+68,0,"sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"isNAN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"isINf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"fp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"exp_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+162,0,"fra_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+163,0,"isZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"isNormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"isUnormalize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    bufp->fullIData(oldp+171,(0x00000020U),32);
    bufp->fullIData(oldp+172,(3U),32);
    bufp->fullIData(oldp+173,(0x0000000aU),32);
    bufp->fullIData(oldp+174,(5U),32);
    bufp->fullIData(oldp+175,(0x00000017U),32);
    bufp->fullIData(oldp+176,(8U),32);
    bufp->fullSData(oldp+177,(0x0081U),9);
    bufp->fullBit(oldp+178,(1U));
    bufp->fullCData(oldp+179,(0U),3);
    bufp->fullCData(oldp+180,(1U),3);
    bufp->fullCData(oldp+181,(3U),3);
    bufp->fullCData(oldp+182,(2U),3);
    bufp->fullIData(oldp+183,(0x00000018U),32);
    bufp->fullIData(oldp+184,(9U),32);
    bufp->fullIData(oldp+185,(0x00000020U),32);
    bufp->fullBit(oldp+186,(0U));
    bufp->fullIData(oldp+187,(0x0000007fU),32);
    bufp->fullIData(oldp+188,(0x00000120U),32);
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
    bufp->fullIData(oldp+37,((0x7fffffffU & (- (IData)(
                                                       (vlSelfRef.testbench__DOT__fina 
                                                        >> 0x0000001fU))))),31);
    bufp->fullIData(oldp+38,((0x7fffffffU & (- (IData)(
                                                       (vlSelfRef.testbench__DOT__finb 
                                                        >> 0x0000001fU))))),31);
    bufp->fullIData(oldp+39,(((vlSelfRef.testbench__DOT__ina 
                               >> 0x0000001fU) ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSelfRef.testbench__DOT__ina))
                               : vlSelfRef.testbench__DOT__ina)),32);
    bufp->fullIData(oldp+40,(((vlSelfRef.testbench__DOT__fina 
                               >> 0x0000001fU) ? 0x80000000U
                               : 0x7fffffffU)),32);
    bufp->fullIData(oldp+41,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__fina, 9U)),32);
    bufp->fullCData(oldp+42,((0x000000ffU & (vlSelfRef.testbench__DOT__finb 
                                             >> 0x00000017U))),8);
    bufp->fullIData(oldp+43,((0x007fffffU & vlSelfRef.testbench__DOT__finb)),23);
    bufp->fullIData(oldp+44,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__finb, 9U)),32);
    bufp->fullCData(oldp+45,(((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_2)
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
    bufp->fullIData(oldp+46,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)) 
                              & (vlSelfRef.testbench__DOT__fina 
                                 == vlSelfRef.testbench__DOT__finb))),32);
    bufp->fullIData(oldp+47,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                               ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                        : ((vlSelfRef.testbench__DOT__fina 
                                            >> 0x0000001fU)
                                            ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               > (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                            : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
    bufp->fullIData(oldp+48,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                               ? 0U : ((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1)
                                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.testbench__DOT__fina, 0x0000001fU)
                                        : ((vlSelfRef.testbench__DOT__fina 
                                            >> 0x0000001fU)
                                            ? ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))
                                            : ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                               <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))))),32);
    bufp->fullIData(oldp+49,((((IData)(vlSelfRef.testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1) 
                               << 0x0000001fU) | (0x7fffffffU 
                                                  & vlSelfRef.testbench__DOT__fina))),32);
    bufp->fullIData(oldp+50,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
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
    bufp->fullIData(oldp+51,((0x7fffffffU & ((- (IData)(
                                                        (vlSelfRef.testbench__DOT__fina 
                                                         >> 0x0000001fU))) 
                                             ^ (IData)(
                                                       (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                        >> 0x00000020U))))),31);
    bufp->fullIData(oldp+52,((0x7fffffffU & ((- (IData)(
                                                        (vlSelfRef.testbench__DOT__finb 
                                                         >> 0x0000001fU))) 
                                             ^ (IData)(
                                                       (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                        >> 0x00000020U))))),31);
    bufp->fullIData(oldp+53,(((((0U != (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                >> 0x00000020U))) 
                                & (vlSelfRef.testbench__DOT__fina 
                                   >> 0x0000001fU)) 
                               << 0x0000001fU) | (0x7fffffffU 
                                                  & (((- (IData)(
                                                                 (vlSelfRef.testbench__DOT__fina 
                                                                  >> 0x0000001fU))) 
                                                      ^ (IData)(
                                                                (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                                                 >> 0x00000020U))) 
                                                     + 
                                                     (vlSelfRef.testbench__DOT__fina 
                                                      >> 0x0000001fU))))),32);
    bufp->fullIData(oldp+54,(((((0U != (IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                >> 0x00000020U))) 
                                & ((vlSelfRef.testbench__DOT__finb 
                                    >> 0x0000001fU) 
                                   ^ (1U == (IData)(vlSelfRef.testbench__DOT__sel)))) 
                               << 0x0000001fU) | (0x7fffffffU 
                                                  & (((- (IData)(
                                                                 (vlSelfRef.testbench__DOT__finb 
                                                                  >> 0x0000001fU))) 
                                                      ^ (IData)(
                                                                (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                                                 >> 0x00000020U))) 
                                                     + 
                                                     (vlSelfRef.testbench__DOT__finb 
                                                      >> 0x0000001fU))))),32);
    bufp->fullBit(oldp+55,(((vlSelfRef.testbench__DOT__fina 
                             >> 0x0000001fU) ? (0U 
                                                != vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)
                             : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
    bufp->fullBit(oldp+56,(((vlSelfRef.testbench__DOT__fina 
                             >> 0x0000001fU) ? ((0x0120U 
                                                 < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                | ((0x0120U 
                                                    == (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)) 
                                                   & (0x80000000U 
                                                      != vlSelfRef.testbench__DOT__dut__DOT__sig_a)))
                             : (0x011fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))));
    bufp->fullIData(oldp+57,(((vlSelfRef.testbench__DOT__fina 
                               >> 0x0000001fU) ? (0x80000000U 
                                                  | (0x7fffffffU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))))
                               : (0x7fffffffU & vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres))),32);
    bufp->fullIData(oldp+58,(vlSelfRef.testbench__DOT__dut__DOT__fresult),32);
    bufp->fullSData(oldp+59,(vlSelfRef.testbench__DOT__dut__DOT__exp_a),9);
    bufp->fullIData(oldp+60,(vlSelfRef.testbench__DOT__dut__DOT__sig_a),32);
    bufp->fullBit(oldp+61,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan));
    bufp->fullBit(oldp+62,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf));
    bufp->fullSData(oldp+63,(vlSelfRef.testbench__DOT__dut__DOT__exp_b),9);
    bufp->fullIData(oldp+64,(vlSelfRef.testbench__DOT__dut__DOT__sig_b),32);
    bufp->fullBit(oldp+65,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isNAN));
    bufp->fullBit(oldp+66,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isINf));
    bufp->fullBit(oldp+67,((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res 
                            >> 0x0000001fU)));
    bufp->fullIData(oldp+68,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig),32);
    bufp->fullSData(oldp+69,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp),9);
    bufp->fullBit(oldp+70,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN));
    bufp->fullBit(oldp+71,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf));
    bufp->fullCData(oldp+72,((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                               << 4U) | (((0x017fU 
                                           < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                          << 2U) | 
                                         (((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize) 
                                           << 1U) | (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx))))),5);
    bufp->fullIData(oldp+73,(((0x80000000U & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res) 
                              | ((((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
                                    ? 0x000000ffU : 
                                   ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf)
                                     ? 0x000000ffU : 
                                    ((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                   >> 6U)))
                                      ? 0U : (((0x006bU 
                                                <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                               & (0x0081U 
                                                  >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                               ? 0U
                                               : ((
                                                   (0x0082U 
                                                    <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                                                   & (0x017fU 
                                                      >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))
                                                   ? 
                                                  (0x000000ffU 
                                                   & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                                      - (IData)(0x81U)))
                                                   : 0x000000ffU))))) 
                                  << 0x00000017U) | 
                                 (0x007fffffU & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
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
    bufp->fullCData(oldp+74,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN) 
                              << 4U)),5);
    bufp->fullIData(oldp+75,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)
                               ? 0xffffffffU : vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)),32);
    bufp->fullBit(oldp+76,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                            | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                               | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)))));
    bufp->fullBit(oldp+77,(((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                            & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1))));
    bufp->fullCData(oldp+78,(((((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan) 
                                | ((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf) 
                                   | (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of))) 
                               << 4U) | ((~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of)) 
                                         & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1)))),5);
    bufp->fullBit(oldp+79,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sign));
    bufp->fullCData(oldp+80,((0x000000ffU & ((IData)(0x7fU) 
                                             + (((IData)(0x1fU) 
                                                 - 
                                                 (0x0000001fU 
                                                  & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))) 
                                                + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout))))),8);
    bufp->fullIData(oldp+81,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout)
                               ? 0x00800000U : (0x00ffffffU 
                                                & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                                    >> 8U) 
                                                   + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre))))),24);
    bufp->fullIData(oldp+82,(vlSelfRef.testbench__DOT__dut__DOT__fcxs_fresult),32);
    bufp->fullBit(oldp+83,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx));
    bufp->fullCData(oldp+84,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__nx),5);
    bufp->fullSData(oldp+85,(((0x00000100U & ((~ ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a) 
                                                  >> 8U)) 
                                              << 8U)) 
                              | (0x000000ffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),9);
    bufp->fullSData(oldp+86,(((0x00000100U & ((~ ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b) 
                                                  >> 8U)) 
                                              << 8U)) 
                              | (0x000000ffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b)))),9);
    bufp->fullSData(oldp+87,((0x000001ffU & ((IData)(1U) 
                                             + (~ (
                                                   (0x00000100U 
                                                    & ((~ 
                                                        ((IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b) 
                                                         >> 8U)) 
                                                       << 8U)) 
                                                   | (0x000000ffU 
                                                      & (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_b))))))),9);
    bufp->fullSData(oldp+88,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff),9);
    bufp->fullSData(oldp+89,((0x000001ffU & ((IData)(1U) 
                                             + (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))))),9);
    bufp->fullBit(oldp+90,((1U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff) 
                                  >> 8U))));
    bufp->fullCData(oldp+91,(((0x0020U <= (0x000001ffU 
                                           & ((IData)(1U) 
                                              + (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff)))))
                               ? 0x00000020U : (0x0000003fU 
                                                & ((IData)(2U) 
                                                   + 
                                                   (~ (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff)))))),6);
    bufp->fullCData(oldp+92,(((0x0020U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))
                               ? 0x00000020U : (0x0000003fU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))))),6);
    bufp->fullQData(oldp+93,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a),64);
    bufp->fullQData(oldp+95,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b),64);
    bufp->fullBit(oldp+97,((0U != (0x000000ffffffffffULL 
                                   & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))));
    bufp->fullBit(oldp+98,((0U != (0x000000ffffffffffULL 
                                   & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b))));
    bufp->fullBit(oldp+99,(((0x00000100U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__exp_diff))
                             ? (0U != (0x000000ffffffffffULL 
                                       & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a))
                             : (0U != (0x000000ffffffffffULL 
                                       & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b)))));
    bufp->fullIData(oldp+100,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a 
                                       >> 0x00000020U))),32);
    bufp->fullIData(oldp+101,((IData)((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b 
                                       >> 0x00000020U))),32);
    bufp->fullIData(oldp+102,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__add_res),32);
    bufp->fullIData(oldp+103,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res),32);
    bufp->fullBit(oldp+104,((1U & VL_REDXOR_32((0xc0000000U 
                                                & vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res)))));
    bufp->fullCData(oldp+105,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos),6);
    bufp->fullCData(oldp+106,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__pos))),5);
    bufp->fullIData(oldp+107,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_sig_res),32);
    bufp->fullSData(oldp+108,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res),9);
    bufp->fullIData(oldp+109,(VL_SHIFTL_III(32,32,32, vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__sig_res, 1U)),32);
    bufp->fullCData(oldp+110,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__LDZ__DOT__found_index),5);
    bufp->fullBit(oldp+111,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize));
    bufp->fullSData(oldp+112,((0x000001ffU & ((IData)(0x0081U) 
                                              - (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__s_exp_res)))),9);
    bufp->fullIData(oldp+113,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig),32);
    bufp->fullBit(oldp+114,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 8U))));
    bufp->fullBit(oldp+115,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 7U))));
    bufp->fullBit(oldp+116,((1U & (vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                   >> 6U))));
    bufp->fullBit(oldp+117,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__stickyBit));
    bufp->fullBit(oldp+118,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre));
    bufp->fullIData(oldp+119,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig 
                                               >> 8U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre)))),24);
    bufp->fullBit(oldp+120,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__sig_cout));
    bufp->fullBit(oldp+121,(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx));
    bufp->fullBit(oldp+122,((0x017fU < (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp))));
    bufp->fullIData(oldp+123,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__data),32);
    bufp->fullCData(oldp+124,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt),6);
    bufp->fullCData(oldp+125,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt))),5);
    bufp->fullIData(oldp+126,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig),32);
    bufp->fullIData(oldp+127,((0x00ffffffU & ((vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                               >> 8U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre)))),24);
    bufp->fullBit(oldp+128,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout));
    bufp->fullBit(oldp+129,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 8U))));
    bufp->fullBit(oldp+130,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 7U))));
    bufp->fullBit(oldp+131,((1U & (vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig 
                                   >> 6U))));
    bufp->fullBit(oldp+132,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__stickyBit));
    bufp->fullBit(oldp+133,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre));
    bufp->fullCData(oldp+134,(vlSelfRef.testbench__DOT__dut__DOT__cvt_s_x__DOT__LDZ__DOT__found_index),5);
    bufp->fullCData(oldp+135,((0x0000001fU & ((IData)(0x1fU) 
                                              - (IData)(vlSelfRef.testbench__DOT__dut__DOT__exp_a)))),5);
    bufp->fullQData(oldp+136,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig),64);
    bufp->fullIData(oldp+138,((IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                       >> 0x00000020U))),32);
    bufp->fullIData(oldp+139,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres),32);
    bufp->fullBit(oldp+140,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x00000020U)))));
    bufp->fullBit(oldp+141,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x0000001fU)))));
    bufp->fullBit(oldp+142,((1U & (IData)((vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig 
                                           >> 0x0000001eU)))));
    bufp->fullBit(oldp+143,((0U != (0x3fffffffU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig)))));
    bufp->fullBit(oldp+144,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__roundIncre));
    bufp->fullBit(oldp+145,(vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__of));
    bufp->fullIData(oldp+146,((0x7fffffffU & ((IData)(1U) 
                                              + (~ vlSelfRef.testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres)))),31);
    bufp->fullBit(oldp+147,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isZero));
    bufp->fullBit(oldp+148,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isUnormalize));
    bufp->fullBit(oldp+149,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__isNormalize));
    bufp->fullCData(oldp+150,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos),6);
    bufp->fullCData(oldp+151,((0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos)))),5);
    bufp->fullCData(oldp+152,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__pos))),5);
    bufp->fullCData(oldp+153,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_a__DOT__LZD__DOT__found_index),5);
    bufp->fullBit(oldp+154,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isZero));
    bufp->fullBit(oldp+155,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isUnormalize));
    bufp->fullBit(oldp+156,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__isNormalize));
    bufp->fullCData(oldp+157,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos),6);
    bufp->fullCData(oldp+158,((0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos)))),5);
    bufp->fullCData(oldp+159,((0x0000001fU & (IData)(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__pos))),5);
    bufp->fullCData(oldp+160,(vlSelfRef.testbench__DOT__dut__DOT__torecFN_b__DOT__LZD__DOT__found_index),5);
    bufp->fullCData(oldp+161,(((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
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
    bufp->fullIData(oldp+162,((0x007fffffU & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN)
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
    bufp->fullBit(oldp+163,((0U == (7U & ((IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp) 
                                          >> 6U)))));
    bufp->fullBit(oldp+164,(((0x0082U <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                             & (0x017fU >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    bufp->fullBit(oldp+165,(((0x006bU <= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)) 
                             & (0x0081U >= (IData)(vlSelfRef.testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp)))));
    bufp->fullBit(oldp+166,(vlSelfRef.testbench__DOT__clk));
    bufp->fullBit(oldp+167,((((1U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                              & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                             | (((3U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state)) 
                                 & (0U == (IData)(vlSelfRef.testbench__DOT__sel))) 
                                | (0U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
    bufp->fullCData(oldp+168,(vlSelfRef.testbench__DOT__dut__DOT__current_state),3);
    bufp->fullCData(oldp+169,(((4U & (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))
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
    bufp->fullBit(oldp+170,(((0U == (IData)(vlSelfRef.testbench__DOT__sel)) 
                             & ((IData)(vlSelfRef.testbench__DOT__o_ready) 
                                & (2U == (IData)(vlSelfRef.testbench__DOT__dut__DOT__current_state))))));
}
