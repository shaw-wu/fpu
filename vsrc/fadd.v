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
    input                 s_axis_a_isQNAN,
    input                 s_axis_a_isSNAN,
    input                 s_axis_a_isINf ,
    input                 s_axis_a_isZero,
//finb
	input                 s_axis_b_tvalid,
	output                s_axis_b_tready,

	input                 s_axis_b_sign  ,
	input  [SIG_BITS-1:0] s_axis_b_sig   ,
	input  [EXP_BITS-1:0] s_axis_b_exp   ,
    input                 s_axis_b_isQNAN,
    input                 s_axis_b_isSNAN,
    input                 s_axis_b_isINf ,
    input                 s_axis_b_isZero,
//fresult
	output                m_axis_res_tvalid,
	input                 m_axis_res_tready,

	output                m_axis_res_sign  ,
	output [SIG_BITS-1:0] m_axis_res_sig   ,
	output [EXP_BITS-1:0] m_axis_res_exp   ,
    //output                m_axis_res_isQNAN,
    //output                m_axis_res_isINf ,
    output [FLA_BITS-1:0] m_axis_res_fflags
);
parameter QNAN = 32'h7fc00000; 
 
assign s_axis_a_tready = 1;
assign s_axis_b_tready = 1;
assign m_axis_res_tvalid = s_axis_a_tvalid;

wire isSNAN = s_axis_a_isSNAN || s_axis_b_isSNAN;
wire isQNAN = s_axis_a_isQNAN || s_axis_b_isQNAN;
wire isINf  = s_axis_a_isINf  || s_axis_b_isINf ;
wire isZero = s_axis_a_isZero || s_axis_b_isZero;

wire                sign_a = s_axis_a_sign;
wire [SIG_BITS-1:0] sig_a  = s_axis_a_sig ;
wire [EXP_BITS-1:0] exp_a  = s_axis_a_exp ;
wire                sign_b = s_axis_b_sign;
wire [SIG_BITS-1:0] sig_b  = s_axis_b_sig ;
wire [EXP_BITS-1:0] exp_b  = s_axis_b_exp ;

wire is_sub = s_axis_sel;

//exp compare(9 bits)
wire                comp_exp_ab  = exp_a < exp_b;
wire [EXP_BITS-1:0] exp_diff     = comp_exp_ab ? exp_b - exp_a : exp_a - exp_b;

//sig right shift
/* verilator lint_off WIDTHTRUNC*/
wire [SIG_SIZE    :0] sig_amt = (exp_diff >= 32) ? 32 : exp_diff;
/* verilator lint_on WIDTHTRUNC*/
wire [2*SIG_BITS-1:0] full_sigShift_a =  comp_exp_ab ? {sig_a, {SIG_BITS{1'b0}}} >> sig_amt : {sig_a, {SIG_BITS{1'b0}}};
wire [2*SIG_BITS-1:0] full_sigShift_b = !comp_exp_ab ? {sig_b, {SIG_BITS{1'b0}}} >> sig_amt : {sig_b, {SIG_BITS{1'b0}}};
wire sticky_a = |full_sigShift_a[SIG_BITS-1:0];
wire sticky_b = |full_sigShift_b[SIG_BITS-1:0];

wire sticky_shift = comp_exp_ab ? sticky_a : sticky_b; 

wire [SIG_BITS-1:0] sigShift_a = full_sigShift_a[SIG_BITS+:SIG_BITS];
wire [SIG_BITS-1:0] sigShift_b = full_sigShift_b[SIG_BITS+:SIG_BITS];

//sig origin add/sub(32 bits)
wire                overflow;

wire                sel_sign_b   = sign_b ^ is_sub;
wire                is_effsub    = sel_sign_b ^ sign_a;
wire                comp_op      = sigShift_a > sigShift_b;

/* verilator lint_off WIDTHEXPAND */
wire [SIG_BITS-1:0] eff_sub_res  = comp_op ? sigShift_a - sigShift_b - sticky_b: sigShift_b - sigShift_a - sticky_a;//sticky : Borrow in
/* verilator lint_on WIDTHEXPAND */
wire                eff_sub_sign = comp_op ? sign_a : sel_sign_b;
wire [SIG_BITS-1:0] eff_add_res;
assign {overflow,   eff_add_res} = sigShift_a + sigShift_b;
wire                eff_add_sign = sign_a;

wire [SIG_BITS-1:0] add_sub_res  = is_effsub ? eff_sub_res  : eff_add_res ;
wire                add_sub_sign = is_effsub ? eff_sub_sign : eff_add_sign;
wire                of           = is_effsub ? 1'b0         : overflow    ;

//sig left shift
wire [SIG_SIZE:0] pos;
ldz #(
    .DATA_BITS(SIG_BITS),
    .DATA_SIZE(SIG_SIZE)
) LDZ (
    .in  (add_sub_res),
    .out (pos        )
);

wire [SIG_SIZE-1:0] lamt = pos[SIG_SIZE-1:0];
wire [SIG_BITS  :0] ls_sig_res = {add_sub_res, sticky_shift} << lamt;
wire [SIG_BITS-1:0] s_sig_res  = of ? {1'b1, add_sub_res[SIG_BITS-1:1]} : (pos[SIG_SIZE] ? 0 : ls_sig_res[SIG_BITS:1]);//of == 1 -> add_sub_res == 0
wire                stickyBit  = of ? add_sub_res[0] || sticky_shift    : (pos[SIG_SIZE] ? 0 : ls_sig_res[0]         );
wire                s_sign_res = pos[SIG_SIZE] && !of ? frm == 3'b010 : add_sub_sign;

//exp 
/* verilator lint_off WIDTHEXPAND */
wire [EXP_BITS-1:0] s_exp_sel  = comp_exp_ab ? exp_b : exp_a;
wire [EXP_BITS-1:0] s_exp_res  = of ? s_exp_sel + of : (pos[SIG_SIZE] ? 0 : s_exp_sel - lamt);
/* verilator lint_on WIDTHEXPAND */

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
	.Insticky(stickyBit   ),
	.nv      (1'b0        ),
	.dz      (1'b0        ),
	.frm     (frm         ),
	.fflags  (fflags      ),
	.o_sig   (o_sig       ),
	.o_exp   (o_exp       ),
    .o_sign  (o_sign      )
);

//qnan
wire                QNAN_sign_res = s_axis_a_isQNAN ? sign_a : sign_b;
wire [EXP_BITS-1:0] QNAN_exp_res  = s_axis_a_isQNAN ? exp_a  : exp_b ;
wire [SIG_BITS-1:0] QNAN_sig_res  = s_axis_a_isQNAN ? sig_a  : sig_b ;

//snan
wire                SNAN_sign_res = s_axis_a_isSNAN ? sign_a                                         : sign_b                                        ;
wire [EXP_BITS-1:0] SNAN_exp_res  = s_axis_a_isSNAN ? exp_a                                          : exp_b                                         ;
wire [SIG_BITS-1:0] SNAN_sig_res  = s_axis_a_isSNAN ? {sig_a[SIG_BITS-1], 1'b1, sig_a[SIG_BITS-3:0]} : {sig_b[SIG_BITS-1], 1'b1, sig_b[SIG_BITS-3:0]};

//inf 
wire                DINf_sign_res = sign_a ^ sel_sign_b ? QNAN[31]                  : sign_a;//Inf Inf
wire [EXP_BITS-1:0] DINf_exp_res  = sign_a ^ sel_sign_b ? {1'b1, QNAN[30:23]}       : exp_a ;
wire [SIG_BITS-1:0] DINf_sig_res  = sign_a ^ sel_sign_b ? {1'b1, QNAN[22: 0], 8'b0} : sig_a ;

wire                CINf_sign_res = s_axis_a_isINf ? sign_a : sel_sign_b;//Inf C
wire [EXP_BITS-1:0] CINf_exp_res  = s_axis_a_isINf ? exp_a  : exp_b     ;
wire [SIG_BITS-1:0] CINf_sig_res  = s_axis_a_isINf ? sig_a  : sig_b     ;

wire                INf_sign_res = s_axis_a_isINf && s_axis_b_isINf ? DINf_sign_res : CINf_sign_res ;
wire [EXP_BITS-1:0] INf_exp_res  = s_axis_a_isINf && s_axis_b_isINf ? DINf_exp_res  : CINf_exp_res  ;
wire [SIG_BITS-1:0] INf_sig_res  = s_axis_a_isINf && s_axis_b_isINf ? DINf_sig_res  : CINf_sig_res  ;

//zero
wire isUnormalize_a = (exp_a >= 9'b0_0110_1011) && (exp_a <= 9'b0_1000_0001);
wire [EXP_BITS-1:0] Unormalize_n_a = 9'b0_1000_0001 - exp_a; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_a = isUnormalize_a ? sig_a >> (Unormalize_n_a + 1) : sig_a; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire isUnormalize_b = (exp_b >= 9'b0_0110_1011) && (exp_b <= 9'b0_1000_0001);
wire [EXP_BITS-1:0] Unormalize_n_b = 9'b0_1000_0001 - exp_b; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_b = isUnormalize_b ? sig_b >> (Unormalize_n_b + 1) : sig_b; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire                Zero_sign_res = s_axis_a_isZero && s_axis_b_isZero ? (sel_sign_b ^ sign_a ? frm == 3'b010 : sign_a) :           //0 (+/-) 0
                                    s_axis_a_isZero                    ?  sel_sign_b                                    : sign_a;
wire [EXP_BITS-1:0] Zero_exp_res  = s_axis_a_isZero ? exp_b      : exp_a ;
wire [SIG_BITS-1:0] Zero_sig_res  = s_axis_a_isZero ? Zero_sig_b : Zero_sig_a ;

//ASSIGN output 
assign m_axis_res_sign   = isSNAN ? SNAN_sign_res : 
                           isQNAN ? QNAN_sign_res :
                           isINf  ? INf_sign_res  :
                           isZero ? Zero_sign_res : o_sign;
assign m_axis_res_sig    = isSNAN ? SNAN_sig_res  :
                           isQNAN ? QNAN_sig_res  :
                           isINf  ? INf_sig_res   :
                           isZero ? Zero_sig_res  : o_sig ;
assign m_axis_res_exp    = isSNAN ? SNAN_exp_res  : 
                           isQNAN ? QNAN_exp_res  :
                           isINf  ? INf_exp_res   :
                           isZero ? Zero_exp_res  : o_exp ;

//assign m_axis_res_isQNAN = isSNAN || isQNAN || (isINf && s_axis_a_isINf && s_axis_b_isINf && (sign_a ^ sel_sign_b));
//assign m_axis_res_isINf  = isINf ;

assign m_axis_res_fflags = isSNAN ? 5'h10                       :
                           isQNAN ? 5'h00                       :
                           isINf  ? {s_axis_a_isINf && s_axis_b_isINf && (sign_a ^ sel_sign_b), 4'b0} :
                           isZero ? 5'h00                       : fflags;

endmodule
