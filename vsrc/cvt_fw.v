`timescale 1ns / 1ps
module cvt_fw #(
	parameter DATA_BITS = 32,
    parameter FP_BITS   = 64,
    parameter EXP_BITS  = 11,
    parameter FRA_BITS  = 52
)(
	input				   u_i	   ,
    input  [FP_BITS  -1:0] fp      ,
	output [DATA_BITS-1:0] w_res   ,
	output [DATA_BITS-1:0] wu_res  ,
	input  [          2:0] frm	   ,
	output		           nv	   ,
	output		           nx	   
);

localparam [DATA_BITS-1:0] SIGNED_MAX = {1'b0, {DATA_BITS-1{1'b1}}};
localparam [DATA_BITS-1:0] SIGNED_MIN = {1'b1, {DATA_BITS-1{1'b0}}};
localparam [DATA_BITS-1:0] UNSIGNED_MAX = {DATA_BITS{1'b1}};

localparam [FRA_BITS:0] SIGNED_MAX_MAG = ({{FRA_BITS{1'b0}}, 1'b1} << (DATA_BITS-1)) - 1'b1;
localparam [FRA_BITS:0] SIGNED_MIN_MAG =  ({{FRA_BITS{1'b0}}, 1'b1} << (DATA_BITS-1));
localparam [FRA_BITS:0] UNSIGNED_MAX_MAG = ({{FRA_BITS{1'b0}}, 1'b1} << DATA_BITS) - 1'b1;

function round_inc;
    input [2:0] round_mode;
    input       sign_bit;
    input       lsb;
    input       any_rem;
    input       gt_half;
    input       eq_half;
    begin
        case (round_mode)
            3'b000: round_inc = gt_half || (eq_half && lsb); // RNE
            3'b001: round_inc = 1'b0;                        // RTZ
            3'b010: round_inc = sign_bit && any_rem;         // RDN
            3'b011: round_inc = !sign_bit && any_rem;        // RUP
            3'b100: round_inc = gt_half || eq_half;          // RMM
            default: round_inc = gt_half || (eq_half && lsb);
        endcase
    end
endfunction

reg                sign;
reg [EXP_BITS-1:0] exp_field;
reg [FRA_BITS-1:0] frac_field;
reg                is_nan;
reg                is_inf;
reg                is_zero;
reg                is_norm;
reg [FRA_BITS  :0] sig;
reg [FRA_BITS  :0] int_part;
reg [FRA_BITS  :0] frac_part;
reg [FRA_BITS  :0] half_ulp;
reg [FRA_BITS  :0] rounded_mag;
reg                any_rem;
reg                gt_half;
reg                eq_half;
reg                inc;
reg                huge_mag;
reg [DATA_BITS-1:0] w_res_reg;
reg [DATA_BITS-1:0] wu_res_reg;
reg                signed_nv;
reg                signed_nx;
reg                unsigned_nv;
reg                unsigned_nx;
integer            unbiased_exp;
integer            shift;

always @(*) begin
    sign      = fp[FP_BITS-1];
    exp_field = fp[FP_BITS-2:FRA_BITS];
    frac_field = fp[FRA_BITS-1:0];

    is_nan  = (exp_field == {EXP_BITS{1'b1}}) && (frac_field != {FRA_BITS{1'b0}});
    is_inf  = (exp_field == {EXP_BITS{1'b1}}) && (frac_field == {FRA_BITS{1'b0}});
    is_zero = (exp_field == {EXP_BITS{1'b0}}) && (frac_field == {FRA_BITS{1'b0}});
    is_norm = (exp_field != {EXP_BITS{1'b0}}) && (exp_field != {EXP_BITS{1'b1}});

    sig         = {1'b0, {FRA_BITS{1'b0}}};
    int_part    = {1'b0, {FRA_BITS{1'b0}}};
    frac_part   = {1'b0, {FRA_BITS{1'b0}}};
    half_ulp    = {1'b0, {FRA_BITS{1'b0}}};
    rounded_mag = {1'b0, {FRA_BITS{1'b0}}};
    any_rem     = 1'b0;
    gt_half     = 1'b0;
    eq_half     = 1'b0;
    inc         = 1'b0;
    huge_mag    = 1'b0;

    w_res_reg   = {DATA_BITS{1'b0}};
    wu_res_reg  = {DATA_BITS{1'b0}};
    signed_nv   = 1'b0;
    signed_nx   = 1'b0;
    unsigned_nv = 1'b0;
    unsigned_nx = 1'b0;
    unbiased_exp = 0;
    shift = 0;

    if (is_nan) begin
        w_res_reg   = SIGNED_MAX;
        wu_res_reg  = UNSIGNED_MAX;
        signed_nv   = 1'b1;
        unsigned_nv = 1'b1;
    end else if (is_inf) begin
        w_res_reg   = sign ? SIGNED_MIN : SIGNED_MAX;
        wu_res_reg  = sign ? {DATA_BITS{1'b0}} : UNSIGNED_MAX;
        signed_nv   = 1'b1;
        unsigned_nv = 1'b1;
    end else if (!is_zero) begin
        sig = is_norm ? {1'b1, frac_field} : {1'b0, frac_field};
        if (is_norm) begin
            /* verilator lint_off WIDTHEXPAND */
            unbiased_exp = exp_field;
            /* verilator lint_on WIDTHEXPAND */
            unbiased_exp = unbiased_exp - 1023;
        end else begin
            unbiased_exp = -1022;
        end

        if (unbiased_exp > FRA_BITS) begin
            huge_mag = 1'b1;
        end else begin
            if (unbiased_exp == FRA_BITS) begin
                int_part = sig;
            end else if (unbiased_exp >= 0) begin
                shift     = FRA_BITS - unbiased_exp;
                int_part  = sig >> shift;
                frac_part = sig & (({{FRA_BITS{1'b0}}, 1'b1} << shift) - 1'b1);
                any_rem   = frac_part != {FRA_BITS+1{1'b0}};
                half_ulp  = {{FRA_BITS{1'b0}}, 1'b1} << (shift - 1);
                gt_half   = frac_part > half_ulp;
                eq_half   = frac_part == half_ulp;
            end else if (unbiased_exp == -1) begin
                frac_part = sig;
                any_rem   = sig != {FRA_BITS+1{1'b0}};
                half_ulp  = {{FRA_BITS{1'b0}}, 1'b1} << FRA_BITS;
                gt_half   = sig > half_ulp;
                eq_half   = sig == half_ulp;
            end else begin
                frac_part = sig;
                any_rem   = sig != {FRA_BITS+1{1'b0}};
            end

            inc = round_inc(frm, sign, int_part[0], any_rem, gt_half, eq_half);
            rounded_mag = int_part + {{FRA_BITS{1'b0}}, inc};
        end

        if (huge_mag) begin
            w_res_reg = sign ? SIGNED_MIN : SIGNED_MAX;
            signed_nv = 1'b1;
        end else if (!sign) begin
            if (rounded_mag > SIGNED_MAX_MAG) begin
                w_res_reg = SIGNED_MAX;
                signed_nv = 1'b1;
            end else begin
                w_res_reg = rounded_mag[DATA_BITS-1:0];
                signed_nx = any_rem;
            end
        end else begin
            if (rounded_mag > SIGNED_MIN_MAG) begin
                w_res_reg = SIGNED_MIN;
                signed_nv = 1'b1;
            end else begin
                w_res_reg = (rounded_mag == {FRA_BITS+1{1'b0}}) ? {DATA_BITS{1'b0}} :
                            (~rounded_mag[DATA_BITS-1:0]) + 1'b1;
                signed_nx = any_rem;
            end
        end

        if (huge_mag) begin
            wu_res_reg  = sign ? {DATA_BITS{1'b0}} : UNSIGNED_MAX;
            unsigned_nv = 1'b1;
        end else if (!sign) begin
            if (rounded_mag > UNSIGNED_MAX_MAG) begin
                wu_res_reg  = UNSIGNED_MAX;
                unsigned_nv = 1'b1;
            end else begin
                wu_res_reg  = rounded_mag[DATA_BITS-1:0];
                unsigned_nx = any_rem;
            end
        end else begin
            if (rounded_mag == {FRA_BITS+1{1'b0}}) begin
                wu_res_reg  = {DATA_BITS{1'b0}};
                unsigned_nx = any_rem;
            end else begin
                wu_res_reg  = {DATA_BITS{1'b0}};
                unsigned_nv = 1'b1;
            end
        end
    end
end

assign w_res  = w_res_reg;
assign wu_res = wu_res_reg;
assign nv     = u_i ? unsigned_nv : signed_nv;
assign nx     = u_i ? unsigned_nx : signed_nx;

endmodule
