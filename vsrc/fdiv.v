`timescale 1ns / 1ps

module fdiv(
    input         aclk,
    input         areset,
    input         s_axis_a_tvalid,
    output        s_axis_a_tready,
    input  [63:0] s_axis_a_tdata,
    input         s_axis_b_tvalid,
    output        s_axis_b_tready,
    input  [63:0] s_axis_b_tdata,
    input  [ 2:0] s_axis_frm,
    output        m_axis_result_tvalid,
    input         m_axis_result_tready,
    output [63:0] m_axis_result_tdata,
    output [ 4:0] m_axis_result_tuser
);

localparam [1:0] S_IDLE = 2'b00;
localparam [1:0] S_CALC = 2'b01;
localparam [1:0] S_OUT  = 2'b10;

localparam [63:0] CANONICAL_NAN_D = 64'h7ff8_0000_0000_0000;
localparam [63:0] MAX_FIN_D  = 64'h7fef_ffff_ffff_ffff;
localparam [63:0] POS_INF_D  = 64'h7ff0_0000_0000_0000;

reg [1:0] state;
reg [63:0] op_a;
reg [63:0] op_b;
reg [2:0]  op_frm;

reg [63:0] result_reg;
reg [4:0]  flags_reg;

assign s_axis_a_tready      = (state == S_IDLE);
assign s_axis_b_tready      = (state == S_IDLE);
assign m_axis_result_tvalid = (state == S_OUT);
assign m_axis_result_tdata  = result_reg;
assign m_axis_result_tuser  = flags_reg;

wire in_fire = s_axis_a_tvalid && s_axis_b_tvalid && (state == S_IDLE);

function [5:0] clz52;
    input [51:0] value;
    integer i;
    begin : fn_clz52
        clz52 = 6'd52;
        for (i = 51; i >= 0; i = i - 1) begin
            if (value[i]) begin
                clz52 = 6'd51 - i[5:0];
                disable fn_clz52;
            end
        end
    end
endfunction

function round_inc;
    input [2:0] frm;
    input       sign;
    input       lsb;
    input       any_rem;
    input       gt_half;
    input       eq_half;
    begin
        case (frm)
            3'b000: round_inc = gt_half || (eq_half && lsb);  // RNE
            3'b001: round_inc = 1'b0;                         // RTZ
            3'b010: round_inc = sign && any_rem;             // RDN
            3'b011: round_inc = !sign && any_rem;            // RUP
            3'b100: round_inc = gt_half || eq_half;          // RMM
            default: round_inc = gt_half || (eq_half && lsb);
        endcase
    end
endfunction

function [63:0] pack_inf;
    input sign;
    begin
        pack_inf = POS_INF_D | ({63'b0, sign} << 63);
    end
endfunction

function [63:0] pack_max_finite;
    input sign;
    begin
        pack_max_finite = MAX_FIN_D | ({63'b0, sign} << 63);
    end
endfunction

function [63:0] pack_overflow;
    input       sign;
    input [2:0] frm;
    begin
        case (frm)
            3'b001: pack_overflow = pack_max_finite(sign);   // RTZ
            3'b010: pack_overflow = sign ? pack_inf(sign) : pack_max_finite(sign);
            3'b011: pack_overflow = sign ? pack_max_finite(sign) : pack_inf(sign);
            default: pack_overflow = pack_inf(sign);         // RNE / RMM / default
        endcase
    end
endfunction

reg        a_sign;
reg        b_sign;
reg [10:0] a_exp;
reg [10:0] b_exp;
reg [51:0] a_frac;
reg [51:0] b_frac;

reg a_is_zero;
reg b_is_zero;
reg a_is_inf;
reg b_is_inf;
reg a_is_nan;
reg b_is_nan;
reg a_is_snan;
reg b_is_snan;

reg        res_sign;
reg [52:0] mant_a;
reg [52:0] mant_b;
reg [53:0] num;
reg [52:0] den;

integer exp_a_unb;
integer exp_b_unb;
integer exp_res;
integer exp_final;
integer shift_a;
integer shift_b;
integer sub_shift;

reg [105:0] scaled_norm;
reg [104:0] scaled_sub;
/* verilator lint_off UNUSEDSIGNAL */
reg [105:0] quo_norm_full;
reg [105:0] rem_norm_full;
reg [104:0] quo_sub_full;
reg [104:0] rem_sub_full;
/* verilator lint_on UNUSEDSIGNAL */
reg [52:0] quo_norm;
reg [52:0] quo_sub;
reg [52:0] rem_norm;
reg [52:0] rem_sub;
reg [53:0] rounded_norm;
reg [52:0] rounded_sub;
/* verilator lint_off UNUSEDSIGNAL */
reg [52:0] mant_final;
/* verilator lint_on UNUSEDSIGNAL */
reg [10:0] exp_field;

reg [53:0] twice_rem_norm;
reg [53:0] twice_rem_sub;
reg        inc;
reg        gt_half;
reg        eq_half;
reg        any_rem;
reg        nx;
reg        uf;
reg [63:0] calc_result;
reg [ 4:0] calc_flags;

always @(*) begin
    a_sign = op_a[63];
    b_sign = op_b[63];
    a_exp  = op_a[62:52];
    b_exp  = op_b[62:52];
    a_frac = op_a[51:0];
    b_frac = op_b[51:0];

    a_is_zero = (a_exp == 11'd0)    && (a_frac == 52'd0);
    b_is_zero = (b_exp == 11'd0)    && (b_frac == 52'd0);
    a_is_inf  = (a_exp == 11'h7ff)  && (a_frac == 52'd0);
    b_is_inf  = (b_exp == 11'h7ff)  && (b_frac == 52'd0);
    a_is_nan  = (a_exp == 11'h7ff)  && (a_frac != 52'd0);
    b_is_nan  = (b_exp == 11'h7ff)  && (b_frac != 52'd0);
    a_is_snan = a_is_nan && !a_frac[51];
    b_is_snan = b_is_nan && !b_frac[51];

    res_sign = a_sign ^ b_sign;
    mant_a   = 53'd0;
    mant_b   = 53'd0;
    num      = 54'd0;
    den      = 53'd0;

    exp_a_unb = 0;
    exp_b_unb = 0;
    exp_res   = 0;
    exp_final = 0;
    shift_a   = 0;
    shift_b   = 0;
    sub_shift = 0;

    scaled_norm = 106'd0;
    scaled_sub  = 105'd0;
    quo_norm_full = 106'd0;
    rem_norm_full = 106'd0;
    quo_sub_full  = 105'd0;
    rem_sub_full  = 105'd0;
    quo_norm    = 53'd0;
    quo_sub     = 53'd0;
    rem_norm    = 53'd0;
    rem_sub     = 53'd0;
    rounded_norm = 54'd0;
    rounded_sub  = 53'd0;
    mant_final   = 53'd0;
    exp_field    = 11'd0;

    twice_rem_norm = 54'd0;
    twice_rem_sub  = 54'd0;
    inc            = 1'b0;
    gt_half        = 1'b0;
    eq_half        = 1'b0;
    any_rem        = 1'b0;
    nx             = 1'b0;
    uf             = 1'b0;

    calc_result = 64'd0;
    calc_flags  = 5'd0;

    if (a_is_nan || b_is_nan) begin
        calc_result = CANONICAL_NAN_D;
        calc_flags  = {(a_is_snan || b_is_snan), 4'b0000};
    end else if ((a_is_inf && b_is_inf) || (a_is_zero && b_is_zero)) begin
        calc_result = CANONICAL_NAN_D;
        calc_flags  = 5'b10000;
    end else if (a_is_inf) begin
        calc_result = pack_inf(res_sign);
        calc_flags  = 5'b00000;
    end else if (b_is_inf) begin
        calc_result = {res_sign, 63'd0};
        calc_flags  = 5'b00000;
    end else if (b_is_zero) begin
        calc_result = pack_inf(res_sign);
        calc_flags  = a_is_zero ? 5'b10000 : 5'b01000;
    end else if (a_is_zero) begin
        calc_result = {res_sign, 63'd0};
        calc_flags  = 5'b00000;
    end else begin
        if (a_exp != 11'd0) begin
            mant_a    = {1'b1, a_frac};
            exp_a_unb = {21'd0, a_exp} - 32'd1023;
        end else begin
            shift_a   = {26'd0, clz52(a_frac)} + 32'd1;
            mant_a    = {1'b0, a_frac} << shift_a;
            exp_a_unb = -1022 - shift_a;
        end

        if (b_exp != 11'd0) begin
            mant_b    = {1'b1, b_frac};
            exp_b_unb = {21'd0, b_exp} - 32'd1023;
        end else begin
            shift_b   = {26'd0, clz52(b_frac)} + 32'd1;
            mant_b    = {1'b0, b_frac} << shift_b;
            exp_b_unb = -1022 - shift_b;
        end

        den = mant_b;
        if (mant_a < mant_b) begin
            num     = {mant_a, 1'b0};
            exp_res = exp_a_unb - exp_b_unb - 1;
        end else begin
            num     = {1'b0, mant_a};
            exp_res = exp_a_unb - exp_b_unb;
        end

        if (exp_res > 1023) begin
            calc_result = pack_overflow(res_sign, op_frm);
            calc_flags  = 5'b00101;
        end else if (exp_res >= -1022) begin
            scaled_norm   = num << 52;
            quo_norm_full = scaled_norm / {53'd0, den};
            rem_norm_full = scaled_norm % {53'd0, den};
            quo_norm      = quo_norm_full[52:0];
            rem_norm      = rem_norm_full[52:0];
            twice_rem_norm = {1'b0, rem_norm} << 1;
            gt_half       = twice_rem_norm > {1'b0, den};
            eq_half       = twice_rem_norm == {1'b0, den};
            any_rem       = rem_norm != 0;
            inc           = round_inc(op_frm, res_sign, quo_norm[0], any_rem, gt_half, eq_half);
            rounded_norm  = {1'b0, quo_norm} + {{53{1'b0}}, inc};
            exp_final     = exp_res;
            if (rounded_norm[53]) begin
                mant_final = rounded_norm[53:1];
                exp_final  = exp_res + 1;
            end else begin
                mant_final = rounded_norm[52:0];
            end

            nx = any_rem;
            if (exp_final > 1023) begin
                calc_result = pack_overflow(res_sign, op_frm);
                calc_flags  = 5'b00101;
            end else begin
                exp_field   = exp_final[10:0] + 11'd1023;
                calc_result = {res_sign, exp_field, mant_final[51:0]};
                calc_flags  = {4'b0000, nx};
            end
        end else begin
            if (exp_res >= -1074) begin
                sub_shift     = exp_res + 1074;
                scaled_sub    = {51'd0, num} << sub_shift;
                quo_sub_full  = scaled_sub / {52'd0, den};
                rem_sub_full  = scaled_sub % {52'd0, den};
                quo_sub       = quo_sub_full[52:0];
                rem_sub       = rem_sub_full[52:0];
                twice_rem_sub = {1'b0, rem_sub} << 1;
                gt_half       = twice_rem_sub > {1'b0, den};
                eq_half       = twice_rem_sub == {1'b0, den};
                any_rem       = rem_sub != 0;
                inc           = round_inc(op_frm, res_sign, quo_sub[0], any_rem, gt_half, eq_half);
                rounded_sub   = quo_sub + {{52{1'b0}}, inc};
            end else if (exp_res == -1075) begin
                gt_half     = num > {1'b0, den};
                eq_half     = num == {1'b0, den};
                any_rem     = 1'b1;
                inc         = round_inc(op_frm, res_sign, 1'b0, any_rem, gt_half, eq_half);
                rounded_sub = {52'd0, inc};
            end else begin
                any_rem     = 1'b1;
                inc         = round_inc(op_frm, res_sign, 1'b0, any_rem, 1'b0, 1'b0);
                rounded_sub = {52'd0, inc};
            end

            nx = any_rem;
            if (rounded_sub[52]) begin
                calc_result = {res_sign, 11'd1, 52'd0};
                calc_flags  = {3'b000, nx, nx};
            end else begin
                uf          = nx;
                calc_result = {res_sign, 11'd0, rounded_sub[51:0]};
                calc_flags  = {3'b000, uf, nx};
            end
        end
    end
end

always @(posedge aclk or posedge areset) begin
    if (areset) begin
        state      <= S_IDLE;
        op_a       <= 64'd0;
        op_b       <= 64'd0;
        op_frm     <= 3'd0;
        result_reg <= 64'd0;
        flags_reg  <= 5'd0;
    end else begin
        case (state)
            S_IDLE: begin
                if (in_fire) begin
                    op_a   <= s_axis_a_tdata;
                    op_b   <= s_axis_b_tdata;
                    op_frm <= s_axis_frm;
                    state  <= S_CALC;
                end
            end
            S_CALC: begin
                result_reg <= calc_result;
                flags_reg  <= calc_flags;
                state      <= S_OUT;
            end
            S_OUT: begin
                if (m_axis_result_tready) begin
                    state <= S_IDLE;
                end
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

endmodule
