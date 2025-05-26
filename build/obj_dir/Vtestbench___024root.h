// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench.h for the primary calling header

#ifndef VERILATED_VTESTBENCH___024ROOT_H_
#define VERILATED_VTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestbench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__10__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__9__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__8__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__7__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__6__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__5__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__4__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__3__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__2__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__1__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid1__BRA__0__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__5__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__4__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__3__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__2__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__1__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid2__BRA__0__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__2__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__1__KET__;
    CData/*0:0*/ testbench__DOT__l1__DOT__lzd__DOT__valid3__BRA__0__KET__;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_26;
    CData/*4:0*/ testbench__DOT__l1__DOT__lzd__DOT____VdfgRegularize_h740e574e_0_28;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ testbench__DOT__fp;
    IData/*31:0*/ testbench__DOT__sig;
    IData/*31:0*/ testbench__DOT__l1__DOT__clog2__Vstatic__i;
    IData/*31:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__4__Vfuncout;
    IData/*22:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__4__fr;
    IData/*31:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__7__Vfuncout;
    IData/*22:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__7__fr;
    IData/*31:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__8__Vfuncout;
    IData/*22:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__8__fr;
    IData/*31:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__9__Vfuncout;
    IData/*22:0*/ __Vfunc_testbench__DOT__l1__DOT__fill_sig__9__fr;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*4:0*/, 16> testbench__DOT__l1__DOT__lzd__DOT__pos1;
    VlUnpacked<CData/*4:0*/, 8> testbench__DOT__l1__DOT__lzd__DOT__pos2;
    VlUnpacked<CData/*4:0*/, 4> testbench__DOT__l1__DOT__lzd__DOT__pos3;
    VlUnpacked<CData/*4:0*/, 2> testbench__DOT__l1__DOT__lzd__DOT__pos4;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestbench___024root(Vtestbench__Syms* symsp, const char* v__name);
    ~Vtestbench___024root();
    VL_UNCOPYABLE(Vtestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
