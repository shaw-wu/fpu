// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench.h for the primary calling header

#ifndef VERILATED_VTESTBENCH___024ROOT_H_
#define VERILATED_VTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestbench___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ testbench__DOT__clk;
        CData/*0:0*/ testbench__DOT__rst;
        CData/*0:0*/ testbench__DOT__i_valid;
        CData/*3:0*/ testbench__DOT__sel;
        CData/*2:0*/ testbench__DOT__frm;
        CData/*0:0*/ testbench__DOT__o_ready;
        CData/*4:0*/ testbench__DOT__exp_fflags;
        CData/*0:0*/ testbench__DOT__dut__DOT__i_ready;
        CData/*0:0*/ testbench__DOT__dut__DOT__o_valid;
        CData/*4:0*/ testbench__DOT__dut__DOT__fflags;
        CData/*2:0*/ testbench__DOT__dut__DOT__current_state;
        CData/*2:0*/ testbench__DOT__dut__DOT__next_state;
        CData/*0:0*/ testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_1;
        CData/*0:0*/ testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_2;
        CData/*0:0*/ testbench__DOT__dut__DOT____VdfgRegularize_ha416a7ce_0_3;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_a__DOT__isZero;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_a__DOT__isUnormalize;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_a__DOT__isNormalize;
        CData/*5:0*/ testbench__DOT__dut__DOT__torecFN_a__DOT__pos;
        CData/*4:0*/ testbench__DOT__dut__DOT__torecFN_a__DOT__LZD__DOT__found_index;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_b__DOT__isZero;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_b__DOT__isUnormalize;
        CData/*0:0*/ testbench__DOT__dut__DOT__torecFN_b__DOT__isNormalize;
        CData/*5:0*/ testbench__DOT__dut__DOT__torecFN_b__DOT__pos;
        CData/*4:0*/ testbench__DOT__dut__DOT__torecFN_b__DOT__LZD__DOT__found_index;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isNAN;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__s_axis_b_isINf;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isNAN;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_isINf;
        CData/*5:0*/ testbench__DOT__dut__DOT__FADD__DOT__lamt;
        CData/*4:0*/ testbench__DOT__dut__DOT__FADD__DOT__LDZ__DOT__found_index;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__isUnormalize;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__roundIncre;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__sig_cout;
        CData/*0:0*/ testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__nx;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__isnan;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__isinf;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__roundIncre;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__of;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT____VdfgRegularize_hc6099bc8_0_1;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__sign;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__nx;
        CData/*5:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__full_shift_amt;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__sigcout;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__stickyBit;
        CData/*0:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__roundIncre;
        CData/*4:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__LDZ__DOT__found_index;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench__DOT__dut__DOT__i_ready__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__testbench__DOT__dut__DOT__o_valid__0;
        CData/*0:0*/ __VactDidInit;
        SData/*8:0*/ testbench__DOT__dut__DOT__exp_a;
        SData/*8:0*/ testbench__DOT__dut__DOT__exp_b;
        SData/*8:0*/ testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_exp;
        SData/*8:0*/ testbench__DOT__dut__DOT__FADD__DOT__exp_diff;
        SData/*8:0*/ testbench__DOT__dut__DOT__FADD__DOT__s_exp_res;
        IData/*31:0*/ testbench__DOT__fina;
        IData/*31:0*/ testbench__DOT__finb;
        IData/*31:0*/ testbench__DOT__ina;
        IData/*31:0*/ testbench__DOT__file_in;
    };
    struct {
        IData/*31:0*/ testbench__DOT__file_log;
        IData/*31:0*/ testbench__DOT__status;
        IData/*31:0*/ testbench__DOT__exp_res;
        IData/*31:0*/ testbench__DOT__vector_cnt;
        IData/*31:0*/ testbench__DOT__error_cnt;
        IData/*31:0*/ testbench__DOT__dut__DOT__fresult;
        IData/*31:0*/ testbench__DOT__dut__DOT__sig_a;
        IData/*31:0*/ testbench__DOT__dut__DOT__sig_b;
        IData/*31:0*/ testbench__DOT__dut__DOT__fcxs_fresult;
        IData/*31:0*/ testbench__DOT__dut__DOT__FADD__DOT__m_axis_res_sig;
        IData/*31:0*/ testbench__DOT__dut__DOT__FADD__DOT__sig_res;
        IData/*31:0*/ testbench__DOT__dut__DOT__FADD__DOT__ROUND__DOT__shift_sig;
        IData/*31:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__sigres;
        IData/*31:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__data;
        IData/*31:0*/ testbench__DOT__dut__DOT__cvt_s_x__DOT__shift_sig;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__4__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__4__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__7__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__7__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__8__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__8__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__9__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_a__DOT__fill_sig__9__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__14__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__14__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__17__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__17__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__18__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__18__fr;
        IData/*31:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__19__Vfuncout;
        IData/*22:0*/ __Vfunc_testbench__DOT__dut__DOT__torecFN_b__DOT__fill_sig__19__fr;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_a;
        QData/*63:0*/ testbench__DOT__dut__DOT__FADD__DOT__full_sigShift_b;
        QData/*63:0*/ testbench__DOT__dut__DOT__cvt_x_s__DOT__shift_sig;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h094465b4__0;
    VlTriggerScheduler __VtrigSched_h08c4dc9b__0;
    VlTriggerScheduler __VtrigSched_hf4c1b52b__0;

    // INTERNAL VARIABLES
    Vtestbench__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtestbench___024root(Vtestbench__Syms* symsp, const char* namep);
    ~Vtestbench___024root();
    VL_UNCOPYABLE(Vtestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
