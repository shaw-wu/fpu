module fadd #(
    parameter FRM_BITS = 3 ,
    parameter FLA_BITS = 5 ,
    parameter SIG_BITS = 32,
    parameter SIG_SIZE = 5 ,
    parameter FRA_BITS = 24,
    parameter EXP_BITS = 9 
)(
/*verilator lint_off UNUSED*/
	input                 aclk			 ,
    input                 areset         ,
//add-sub sel
    input                 s_axis_sel     ,
    input  [FRM_BITS-1:0] s_axis_frm     ,
//fina
	input                 s_axis_a_tvalid,
	output                s_axis_a_tready,

	input                 s_axis_a_sign  ,
	input  [SIG_BITS-1:0] s_axis_a_sig   ,
	input  [EXP_BITS-1:0] s_axis_a_exp   ,
    input                 s_axis_a_isNAN ,
    input                 s_axis_a_isINf ,
//finb
	input                 s_axis_b_tvalid,
	output                s_axis_b_tready,

	input                 s_axis_b_sign  ,
	input  [SIG_BITS-1:0] s_axis_b_sig   ,
	input  [EXP_BITS-1:0] s_axis_b_exp   ,
    input                 s_axis_b_isNAN ,
    input                 s_axis_b_isINf ,
//fresult
	output                m_axis_res_tvalid,
	input                 m_axis_res_tready,

	output                m_axis_res_sign  ,
	output [SIG_BITS-1:0] m_axis_res_sig   ,
	output [EXP_BITS-1:0] m_axis_res_exp   ,
    output                m_axis_res_isNAN ,
    output                m_axis_res_isINf ,
    output [FLA_BITS-1:0] m_axis_res_fflags
);
 
assign s_axis_a_tready = 1;
assign s_axis_b_tready = 1;
assign m_axis_res_tvalid = s_axis_a_tvalid;

wire                sign_a = s_axis_a_sign;
wire [SIG_BITS-1:0] sig_a  = s_axis_a_sig ;
wire [EXP_BITS-1:0] exp_a  = s_axis_a_exp ;
wire                sign_b = s_axis_b_sign;
wire [SIG_BITS-1:0] sig_b  = s_axis_b_sig ;
wire [EXP_BITS-1:0] exp_b  = s_axis_b_exp ;

wire is_sub = s_axis_sel;

//exp compare(9 bits)
wire [EXP_BITS-1:0] comp_exp_a   = {!exp_a[EXP_BITS-1], exp_a[0 +: EXP_BITS-1]};//to two's complement
wire [EXP_BITS-1:0] comp_exp_b   = {!exp_b[EXP_BITS-1], exp_b[0 +: EXP_BITS-1]};//to two's complement

wire [EXP_BITS-1:0] neg_exp_b    = ~comp_exp_b  + 1        ;
wire [EXP_BITS-1:0] exp_diff     =  comp_exp_a  + neg_exp_b;//a - b
wire [EXP_BITS-1:0] neg_exp_diff = ~exp_diff    + 1        ;//b - a

wire sign_exp_diff = exp_diff[EXP_BITS-1];//a < b

//sig right shift
/* verilator lint_off WIDTHTRUNC*/
wire [SIG_SIZE    :0] sig_amt_a = (neg_exp_diff >= 32) ? 32 : neg_exp_diff + 1;
wire [SIG_SIZE    :0] sig_amt_b = (exp_diff     >= 32) ? 32 : exp_diff     + 1;
/* verilator lint_on WIDTHTRUNC*/
wire [2*SIG_BITS-1:0] full_sigShift_a =  sign_exp_diff ? {sig_a, {SIG_BITS{1'b0}}} >> sig_amt_a : {sig_a, {SIG_BITS{1'b0}}};
wire [2*SIG_BITS-1:0] full_sigShift_b = !sign_exp_diff ? {sig_b, {SIG_BITS{1'b0}}} >> sig_amt_b : {sig_b, {SIG_BITS{1'b0}}};
wire sticky_a = |full_sigShift_a[0+:(2*SIG_BITS-FRA_BITS)];
wire sticky_b = |full_sigShift_b[0+:(2*SIG_BITS-FRA_BITS)];

wire sticky_shift = sign_exp_diff ? sticky_a : sticky_b; 

wire [SIG_BITS-1:0] sigShift_a = full_sigShift_a[SIG_BITS+:SIG_BITS];
wire [SIG_BITS-1:0] sigShift_b = full_sigShift_b[SIG_BITS+:SIG_BITS];

//sig add/sub(32 bits)
wire                sel_sign_b = sign_b ^ is_sub;
wire [SIG_BITS-2:0] sign_a31   = {(SIG_BITS-1){sign_a}}             ;
wire [SIG_BITS-2:0] neg_sig_a  = sign_a31 ^ sigShift_a[SIG_BITS-2:0];
wire [SIG_BITS-2:0] sign_b31   = {(SIG_BITS-1){sign_b}}             ;
wire [SIG_BITS-2:0] neg_sig_b  = sign_b31 ^ sigShift_b[SIG_BITS-2:0];

/*verilator lint_off WIDTHEXPAND */
wire [SIG_BITS-1:0] nsig_a  = {(sigShift_a != 0) && sign_a    , neg_sig_a + sign_a};
wire [SIG_BITS-1:0] nsig_b  = {(sigShift_b != 0) && sel_sign_b, neg_sig_b + sign_b};
/*verilator lint_on WIDTHEXPAND */
wire                s_sign_res = add_res[SIG_BITS-1];
wire [SIG_BITS-1:0] add_res = nsig_a + nsig_b; 
/*verilator lint_off WIDTHCONCAT */
wire [SIG_BITS-1:0] sig_res = {s_sign_res, s_sign_res ? ~add_res[SIG_BITS-2:0] + 1 : add_res[SIG_BITS-2:0]}; 
/*verilator lint_on WIDTHCONCAT*/
wire                of      = sig_res[SIG_BITS-1] ^ sig_res[SIG_BITS-2];

//sig left shift
wire [SIG_SIZE:0] pos;
ldz #(
    .DATA_BITS(SIG_BITS),
    .DATA_SIZE(SIG_SIZE)
) LDZ (
    .in  ({sig_res[0+:SIG_BITS-1], 1'b0}),
    .out (pos                           )
);

wire [SIG_SIZE-1:0] lamt = pos[SIG_SIZE-1:0];
wire [SIG_BITS-1:0] s_sig_res = sig_res << lamt;

//exp sign
/* verilator lint_off WIDTHEXPAND */
wire [EXP_BITS-1:0] s_exp_res  = sign_exp_diff ? exp_b : exp_a ;
/* verilator lint_on WIDTHEXPAND */

//exception
wire res_isNAN  = s_axis_a_isNAN || s_axis_b_isNAN;
wire res_isINf  = s_axis_a_isINf || s_axis_b_isINf;

//round
wire [SIG_BITS -1:0] o_sig ;
wire [EXP_BITS -1:0] o_exp ;
wire                 o_sign;
wire [FRM_BITS -1:0] frm   ;
wire [FLA_BITS -1:0] fflags;

assign frm = s_axis_frm;

round #(
    .SIG_BITS(SIG_BITS),
    .EXP_BITS(EXP_BITS),
    .FRA_BITS(FRA_BITS)
) ROUND (
	.sig     (s_sig_res   ),
	.exp     (s_exp_res   ),
	.sign    (s_sign_res  ),
	.Insticky(sticky_shift),
	.nv      (res_isNAN   ),
	.dz      (1'b0        ),
	.frm     (frm         ),
	.fflags  (fflags      ),
	.o_sig   (o_sig       ),
	.o_exp   (o_exp       ),
    .o_sign  (o_sign      )
);

//ASSIGN output 
assign m_axis_res_sign   = o_sign   ;
assign m_axis_res_sig    = o_sig    ;
assign m_axis_res_exp    = o_exp    ;
assign m_axis_res_isNAN  = res_isNAN;
assign m_axis_res_isINf  = res_isINf;
assign m_axis_res_fflags = fflags   ;

endmodule
