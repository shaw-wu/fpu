// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench__pch.h"

void Vtestbench___024root___ctor_var_reset(Vtestbench___024root* vlSelf);

Vtestbench___024root::Vtestbench___024root(Vtestbench__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtestbench___024root___ctor_var_reset(this);
}

void Vtestbench___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtestbench___024root::~Vtestbench___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
