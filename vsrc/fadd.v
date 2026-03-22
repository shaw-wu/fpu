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
//    output                busy           ,
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
 
assign s_axis_a_tready = s1_ready;
assign s_axis_b_tready = s1_ready;
assign m_axis_res_tvalid = s3_valid;
wire i_valid = s_axis_a_tvalid && s_axis_b_tvalid;
wire o_ready = m_axis_res_tready;

/*======== stage 1  ========*/
reg                s1_sel     ;
reg [FRM_BITS-1:0] s1_frm     ;

reg                s1_sign_a  ;
reg [SIG_BITS-1:0] s1_sig_a   ;
reg [EXP_BITS-1:0] s1_exp_a   ;
reg                s1_isQNAN_a;
reg                s1_isSNAN_a;
reg                s1_isINf_a ;
reg                s1_isZero_a;

reg                s1_sign_b  ;
reg [SIG_BITS-1:0] s1_sig_b   ;
reg [EXP_BITS-1:0] s1_exp_b   ;
reg                s1_isQNAN_b;
reg                s1_isSNAN_b;
reg                s1_isINf_b ;
reg                s1_isZero_b;

wire s1_valid;
wire s1_ready;

localparam S1_IDLE = 2'b01;
localparam S1_WAIT = 2'b10;

reg [1:0] s1_current_state, s1_next_state;

always @(*) begin
    case(s1_current_state)
        S1_IDLE : begin //s0_ready == 1
            if (i_valid) s1_next_state = S1_WAIT; 
            else         s1_next_state = S1_IDLE;
        end
        S1_WAIT : begin //s1_valid == 1
            if      (s2_ready && i_valid) s1_next_state = S1_WAIT;
            else if (s2_ready           ) s1_next_state = S1_IDLE;
            else                          s1_next_state = S1_WAIT;
        end
        default : s1_next_state = S1_IDLE;
    endcase
end

always @(posedge aclk, posedge areset) begin
    if(areset) begin
        s1_current_state <= S1_IDLE;

        s1_sel      <= 0;
        s1_frm      <= 0;

	    s1_sign_a   <= 0;
	    s1_sig_a    <= 0;
	    s1_exp_a    <= 0;
        s1_isQNAN_a <= 0;
        s1_isSNAN_a <= 0;
        s1_isINf_a  <= 0;
        s1_isZero_a <= 0;

	    s1_sign_b   <= 0;
	    s1_sig_b    <= 0;
	    s1_exp_b    <= 0;
        s1_isQNAN_b <= 0;
        s1_isSNAN_b <= 0;
        s1_isINf_b  <= 0;
        s1_isZero_b <= 0;
    end else begin
        s1_current_state <= s1_next_state;
        if(i_valid && s1_ready) begin
            s1_sel      <= s_axis_sel     ;
            s1_frm      <= s_axis_frm     ;

	        s1_sign_a   <= s_axis_a_sign  ;
	        s1_sig_a    <= s_axis_a_sig   ;
	        s1_exp_a    <= s_axis_a_exp   ;
            s1_isQNAN_a <= s_axis_a_isQNAN;
            s1_isSNAN_a <= s_axis_a_isSNAN;
            s1_isINf_a  <= s_axis_a_isINf ;
            s1_isZero_a <= s_axis_a_isZero;

	        s1_sign_b   <= s_axis_b_sign  ;
	        s1_sig_b    <= s_axis_b_sig   ;
	        s1_exp_b    <= s_axis_b_exp   ;
            s1_isQNAN_b <= s_axis_b_isQNAN;
            s1_isSNAN_b <= s_axis_b_isSNAN;
            s1_isINf_b  <= s_axis_b_isINf ;
            s1_isZero_b <= s_axis_b_isZero;
        end
    end
end

assign s1_valid = s1_current_state == S1_WAIT;
assign s1_ready = s1_current_state == S1_IDLE || (s1_valid && s2_ready);

//wire isSNAN = s_axis_a_isSNAN || s_axis_b_isSNAN;
//wire isQNAN = s_axis_a_isQNAN || s_axis_b_isQNAN;
//wire isINf  = s_axis_a_isINf  || s_axis_b_isINf ;
//wire isZero = s_axis_a_isZero || s_axis_b_isZero;

//wire                sign_a = s_axis_a_sign;
//wire [SIG_BITS-1:0] sig_a  = s_axis_a_sig ;
//wire [EXP_BITS-1:0] exp_a  = s_axis_a_exp ;
//wire                sign_b = s_axis_b_sign;
//wire [SIG_BITS-1:0] sig_b  = s_axis_b_sig ;
//wire [EXP_BITS-1:0] exp_b  = s_axis_b_exp ;

wire is_sub = s1_sel;

//exp compare(9 bits)
wire                comp_exp_ab  = s1_exp_a < s1_exp_b;
wire [EXP_BITS-1:0] exp_diff     = comp_exp_ab ? s1_exp_b - s1_exp_a : s1_exp_a - s1_exp_b;

//sig right shift
/* verilator lint_off WIDTHTRUNC*/
wire [SIG_SIZE    :0] sig_amt = (exp_diff >= 32) ? 32 : exp_diff;
/* verilator lint_on WIDTHTRUNC*/

wire [SIG_BITS-1:0] mask = ~({SIG_BITS{1'b1}} << sig_amt);
wire [SIG_BITS-1:0] full_sigShift_a =  comp_exp_ab ? s1_sig_a >> sig_amt : s1_sig_a;
wire [SIG_BITS-1:0] full_sigShift_b = !comp_exp_ab ? s1_sig_b >> sig_amt : s1_sig_b;
wire sticky_a = |(mask & s1_sig_a);
wire sticky_b = |(mask & s1_sig_b);

wire sticky_shift = comp_exp_ab ? sticky_a : sticky_b; 

wire [SIG_BITS-1:0] sigShift_a = full_sigShift_a;
wire [SIG_BITS-1:0] sigShift_b = full_sigShift_b;

//sig origin add/sub(32 bits)

wire                sel_sign_b   = s1_sign_b ^ is_sub;
wire                is_effsub    = sel_sign_b ^ s1_sign_a;
wire                comp_op      = sigShift_a > sigShift_b;

/*======== stage 2 ========*/
reg                s2_comp_exp_ab ;
reg                s2_sticky_a    ;
reg                s2_sticky_b    ;
reg                s2_sticky_shift; 
reg [SIG_BITS-1:0] s2_sigShift_a  ;
reg [SIG_BITS-1:0] s2_sigShift_b  ;
reg                s2_sel_sign_b  ;
reg                s2_is_effsub   ;
reg                s2_comp_op     ;

reg [FRM_BITS-1:0] s2_frm     ;

reg                s2_sign_a  ;
reg [SIG_BITS-1:0] s2_sig_a   ;
reg [EXP_BITS-1:0] s2_exp_a   ;
reg                s2_isQNAN_a;
reg                s2_isSNAN_a;
reg                s2_isINf_a ;
reg                s2_isZero_a;

reg                s2_sign_b  ;
reg [SIG_BITS-1:0] s2_sig_b   ;
reg [EXP_BITS-1:0] s2_exp_b   ;
reg                s2_isQNAN_b;
reg                s2_isSNAN_b;
reg                s2_isINf_b ;
reg                s2_isZero_b;

wire s2_valid;
wire s2_ready;

localparam S2_IDLE = 2'b01;
localparam S2_WAIT = 2'b10;

reg [1:0] s2_current_state, s2_next_state;

always @(*) begin
    case(s2_current_state)
        S2_IDLE : begin //s2_ready == 1
            if (s1_valid) s2_next_state = S2_WAIT; 
            else          s2_next_state = S2_IDLE;
        end
        S2_WAIT : begin //s2_valid == 1
            if      (s3_ready && s1_valid) s2_next_state = S2_WAIT;
            else if (s3_ready            ) s2_next_state = S2_IDLE;
            else                           s2_next_state = S2_WAIT;
        end
        default : s2_next_state = S2_IDLE;
    endcase
end

always @(posedge aclk, posedge areset) begin
    if(areset) begin
        s2_current_state <= S2_IDLE;

        s2_comp_exp_ab  <= 0;
        s2_sticky_a     <= 0;
        s2_sticky_b     <= 0;
        s2_sticky_shift <= 0; 
        s2_sigShift_a   <= 0;
        s2_sigShift_b   <= 0;
        s2_sel_sign_b   <= 0;
        s2_is_effsub    <= 0;
        s2_comp_op      <= 0;

        s2_frm      <= 0;

	    s2_sign_a   <= 0;
	    s2_sig_a    <= 0;
	    s2_exp_a    <= 0;
        s2_isQNAN_a <= 0;
        s2_isSNAN_a <= 0;
        s2_isINf_a  <= 0;
        s2_isZero_a <= 0;

	    s2_sign_b   <= 0;
	    s2_sig_b    <= 0;
	    s2_exp_b    <= 0;
        s2_isQNAN_b <= 0;
        s2_isSNAN_b <= 0;
        s2_isINf_b  <= 0;
        s2_isZero_b <= 0;
    end else begin
        s2_current_state <= s2_next_state;
        if(s1_valid && s2_ready) begin
            s2_comp_exp_ab  <= comp_exp_ab ;
            s2_sticky_a     <= sticky_a    ;
            s2_sticky_b     <= sticky_b    ;
            s2_sticky_shift <= sticky_shift; 
            s2_sigShift_a   <= sigShift_a  ;
            s2_sigShift_b   <= sigShift_b  ;
            s2_sel_sign_b   <= sel_sign_b  ;
            s2_is_effsub    <= is_effsub   ;
            s2_comp_op      <= comp_op     ;

            s2_frm      <= s1_frm     ;
                                      
	        s2_sign_a   <= s1_sign_a  ;
	        s2_sig_a    <= s1_sig_a   ;
	        s2_exp_a    <= s1_exp_a   ;
            s2_isQNAN_a <= s1_isQNAN_a;
            s2_isSNAN_a <= s1_isSNAN_a;
            s2_isINf_a  <= s1_isINf_a ;
            s2_isZero_a <= s1_isZero_a;
                                      
	        s2_sign_b   <= s1_sign_b  ;
	        s2_sig_b    <= s1_sig_b   ;
	        s2_exp_b    <= s1_exp_b   ;
            s2_isQNAN_b <= s1_isQNAN_b;
            s2_isSNAN_b <= s1_isSNAN_b;
            s2_isINf_b  <= s1_isINf_b ;
            s2_isZero_b <= s1_isZero_b;
        end
    end
end

assign s2_valid = s2_current_state == S2_WAIT;
assign s2_ready = s2_current_state == S2_IDLE || (s2_valid && s3_ready);

wire                overflow;
/* verilator lint_off WIDTHEXPAND */
wire [SIG_BITS-1:0] eff_sub_res  = s2_comp_op ? s2_sigShift_a - s2_sigShift_b - s2_sticky_b: s2_sigShift_b - s2_sigShift_a - s2_sticky_a;//sticky : Borrow in
/* verilator lint_on WIDTHEXPAND */
wire                eff_sub_sign = s2_comp_op ? s2_sign_a : s2_sel_sign_b;
wire [SIG_BITS-1:0] eff_add_res;
assign {overflow,   eff_add_res} = s2_sigShift_a + s2_sigShift_b;
wire                eff_add_sign = s2_sign_a;

wire [SIG_BITS-1:0] add_sub_res  = s2_is_effsub ? eff_sub_res  : eff_add_res ;
wire                add_sub_sign = s2_is_effsub ? eff_sub_sign : eff_add_sign;
wire                of           = s2_is_effsub ? 1'b0         : overflow    ;

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
wire [SIG_BITS  :0] ls_sig_res = {add_sub_res, s2_sticky_shift} << lamt;
wire [SIG_BITS-1:0] s_sig_res  = of ? {1'b1, add_sub_res[SIG_BITS-1:1]} : (pos[SIG_SIZE] ? 0 : ls_sig_res[SIG_BITS:1]);//of == 1 -> add_sub_res == 0
wire                stickyBit  = of ? add_sub_res[0] || s2_sticky_shift : (pos[SIG_SIZE] ? 0 : ls_sig_res[0]         );
wire                s_sign_res = pos[SIG_SIZE] && !of ? s2_frm == 3'b010 : add_sub_sign;

//exp 
/* verilator lint_off WIDTHEXPAND */
wire [EXP_BITS-1:0] s_exp_sel  = s2_comp_exp_ab ? s2_exp_b : s2_exp_a;
wire [EXP_BITS-1:0] s_exp_res  = of ? s_exp_sel + of : (pos[SIG_SIZE] ? 0 : s_exp_sel - lamt);
/* verilator lint_on WIDTHEXPAND */

/*======== stage 3 ========*/
reg                s3_sel_sign_b  ;

reg [FRM_BITS-1:0] s3_frm     ;

reg                s3_sign_a  ;
reg [SIG_BITS-1:0] s3_sig_a   ;
reg [EXP_BITS-1:0] s3_exp_a   ;
reg                s3_isQNAN_a;
reg                s3_isSNAN_a;
reg                s3_isINf_a ;
reg                s3_isZero_a;

reg                s3_sign_b  ;
reg [SIG_BITS-1:0] s3_sig_b   ;
reg [EXP_BITS-1:0] s3_exp_b   ;
reg                s3_isQNAN_b;
reg                s3_isSNAN_b;
reg                s3_isINf_b ;
reg                s3_isZero_b;

reg [SIG_BITS-1:0] s3_s_sig_res ;
reg                s3_stickyBit ;
reg                s3_s_sign_res;
reg [EXP_BITS-1:0] s3_s_exp_res ;

wire s3_valid;
wire s3_ready;

localparam S3_IDLE = 2'b01;
localparam S3_WAIT = 2'b10;

reg [1:0] s3_current_state, s3_next_state;

always @(*) begin
    case(s3_current_state)
        S3_IDLE : begin //s3_ready == 1
            if (s2_valid) s3_next_state = S3_WAIT; 
            else          s3_next_state = S3_IDLE;
        end
        S3_WAIT : begin //s3_valid == 1
            if      (o_ready && s2_valid) s3_next_state = S3_WAIT;
            else if (o_ready            ) s3_next_state = S3_IDLE;
            else                          s3_next_state = S3_WAIT;
        end
        default : s3_next_state = S3_IDLE;
    endcase
end

always @(posedge aclk, posedge areset) begin
    if(areset) begin
        s3_current_state <= S3_IDLE;

        s3_sel_sign_b <= 0;

        s3_frm        <= 0;

	    s3_sign_a     <= 0;
	    s3_sig_a      <= 0;
	    s3_exp_a      <= 0;
        s3_isQNAN_a   <= 0;
        s3_isSNAN_a   <= 0;
        s3_isINf_a    <= 0;
        s3_isZero_a   <= 0;

	    s3_sign_b     <= 0;
	    s3_sig_b      <= 0;
	    s3_exp_b      <= 0;
        s3_isQNAN_b   <= 0;
        s3_isSNAN_b   <= 0;
        s3_isINf_b    <= 0;
        s3_isZero_b   <= 0;

        s3_s_sig_res  <= 0;
        s3_stickyBit  <= 0;
        s3_s_sign_res <= 0;
        s3_s_exp_res  <= 0;
    end else begin
        s3_current_state <= s3_next_state;
        if(s2_valid && s3_ready) begin
            s3_sel_sign_b <= s2_sel_sign_b;
                                          
            s3_frm        <= s2_frm       ;
                                          
	        s3_sign_a     <= s2_sign_a    ;
	        s3_sig_a      <= s2_sig_a     ;
	        s3_exp_a      <= s2_exp_a     ;
            s3_isQNAN_a   <= s2_isQNAN_a  ;
            s3_isSNAN_a   <= s2_isSNAN_a  ;
            s3_isINf_a    <= s2_isINf_a   ;
            s3_isZero_a   <= s2_isZero_a  ;
                                          
	        s3_sign_b     <= s2_sign_b    ;
	        s3_sig_b      <= s2_sig_b     ;
	        s3_exp_b      <= s2_exp_b     ;
            s3_isQNAN_b   <= s2_isQNAN_b  ;
            s3_isSNAN_b   <= s2_isSNAN_b  ;
            s3_isINf_b    <= s2_isINf_b   ;
            s3_isZero_b   <= s2_isZero_b  ;

            s3_s_sig_res  <= s_sig_res    ;
            s3_stickyBit  <= stickyBit    ;
            s3_s_sign_res <= s_sign_res   ;
            s3_s_exp_res  <= s_exp_res    ;
        end
    end
end

assign s3_valid = s3_current_state == S3_WAIT;
assign s3_ready = s3_current_state == S3_IDLE || (s3_valid && o_ready);

//round
wire [SIG_BITS -1:0] o_sig ;
wire [EXP_BITS -1:0] o_exp ;
wire                 o_sign;
wire [FLA_BITS -1:0] fflags;

round #(
    .SIG_BITS(SIG_BITS),
    .EXP_BITS(EXP_BITS),
    .FRA_BITS(FRA_BITS)
) ROUND (
	.sig     (s3_s_sig_res ),
	.exp     (s3_s_exp_res ),
	.sign    (s3_s_sign_res),
	.Insticky(s3_stickyBit ),
	.nv      (1'b0         ),
	.dz      (1'b0         ),
	.frm     (s3_frm       ),
	.fflags  (fflags       ),
	.o_sig   (o_sig        ),
	.o_exp   (o_exp        ),
    .o_sign  (o_sign       )
);

//qnan
//wire                QNAN_sign_res = s_axis_a_isQNAN ? sign_a : sign_b;
//wire [EXP_BITS-1:0] QNAN_exp_res  = s_axis_a_isQNAN ? exp_a  : exp_b ;
//wire [SIG_BITS-1:0] QNAN_sig_res  = s_axis_a_isQNAN ? sig_a  : sig_b ;
//
////snan
//wire                SNAN_sign_res = s_axis_a_isSNAN ? sign_a                                         : sign_b                                        ;
//wire [EXP_BITS-1:0] SNAN_exp_res  = s_axis_a_isSNAN ? exp_a                                          : exp_b                                         ;
//wire [SIG_BITS-1:0] SNAN_sig_res  = s_axis_a_isSNAN ? {sig_a[SIG_BITS-1], 1'b1, sig_a[SIG_BITS-3:0]} : {sig_b[SIG_BITS-1], 1'b1, sig_b[SIG_BITS-3:0]};

//inf 
wire                DINf_sign_res = s3_sign_a ^ s3_sel_sign_b ? QNAN[31]                  : s3_sign_a;//Inf Inf
wire [EXP_BITS-1:0] DINf_exp_res  = s3_sign_a ^ s3_sel_sign_b ? {1'b1, QNAN[30:23]}       : s3_exp_a ;
wire [SIG_BITS-1:0] DINf_sig_res  = s3_sign_a ^ s3_sel_sign_b ? {1'b1, QNAN[22: 0], 8'b0} : s3_sig_a ;

wire                CINf_sign_res = s3_isINf_a ? s3_sign_a : s3_sel_sign_b;//Inf C
wire [EXP_BITS-1:0] CINf_exp_res  = s3_isINf_a ? s3_exp_a  : s3_exp_b     ;
wire [SIG_BITS-1:0] CINf_sig_res  = s3_isINf_a ? s3_sig_a  : s3_sig_b     ;

wire                INf_sign_res = s3_isINf_a && s3_isINf_b ? DINf_sign_res : CINf_sign_res ;
wire [EXP_BITS-1:0] INf_exp_res  = s3_isINf_a && s3_isINf_b ? DINf_exp_res  : CINf_exp_res  ;
wire [SIG_BITS-1:0] INf_sig_res  = s3_isINf_a && s3_isINf_b ? DINf_sig_res  : CINf_sig_res  ;

//zero
wire isUnormalize_a = (s3_exp_a >= 9'b0_0110_1011) && (s3_exp_a <= 9'b0_1000_0001);
wire [EXP_BITS-1:0] Unormalize_n_a = 9'b0_1000_0001 - s3_exp_a; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_a = isUnormalize_a ? s3_sig_a >> (Unormalize_n_a + 1) : s3_sig_a; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire isUnormalize_b = (s3_exp_b >= 9'b0_0110_1011) && (s3_exp_b <= 9'b0_1000_0001);
wire [EXP_BITS-1:0] Unormalize_n_b = 9'b0_1000_0001 - s3_exp_b; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_b = isUnormalize_b ? s3_sig_b >> (Unormalize_n_b + 1) : s3_sig_b; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire                Zero_sign_res = s3_isZero_a && s3_isZero_b ? (s3_sel_sign_b ^ s3_sign_a ? s3_frm == 3'b010 : s3_sign_a) ://0 (+/-) 0
                                    s3_isZero_a                ?  s3_sel_sign_b                                             : s3_sign_a;
wire [EXP_BITS-1:0] Zero_exp_res  = s3_isZero_a ? s3_exp_b   : s3_exp_a  ;
wire [SIG_BITS-1:0] Zero_sig_res  = s3_isZero_a ? Zero_sig_b : Zero_sig_a;

wire isSNAN = s3_isSNAN_a || s3_isSNAN_b;
wire isQNAN = s3_isQNAN_a || s3_isQNAN_b;
wire isINf  = s3_isINf_a  || s3_isINf_b ;
wire isZero = s3_isZero_a || s3_isZero_b;
//ASSIGN output 
assign m_axis_res_sign   = isSNAN || isQNAN ? 0             : 
                           isINf            ? INf_sign_res  :
                           isZero           ? Zero_sign_res : o_sign;
assign m_axis_res_sig    = isSNAN || isQNAN ? {2'b11, {(SIG_BITS-2){1'b0}}} :
                           isINf            ? INf_sig_res                   :
                           isZero           ? Zero_sig_res                  : o_sig ;
assign m_axis_res_exp    = isSNAN || isQNAN ? {EXP_BITS{1'b1}} : 
                           isINf            ? INf_exp_res      :
                           isZero           ? Zero_exp_res     : o_exp ;

//assign m_axis_res_isQNAN = isSNAN || isQNAN || (isINf && s_axis_a_isINf && s_axis_b_isINf && (sign_a ^ sel_sign_b));
//assign m_axis_res_isINf  = isINf ;

assign m_axis_res_fflags = isSNAN ? 5'h10                       :
                           isQNAN ? 5'h00                       :
                           isINf  ? {s3_isINf_a && s3_isINf_b && (s3_sign_a ^ s3_sel_sign_b), 4'b0} :
                           isZero ? 5'h00                       : fflags;
//assign busy = (s1_ready && i_valid) || s1_current_state != S1_IDLE || s2_current_state != S2_IDLE || s3_current_state != S3_IDLE;

endmodule
