module fadd #(
    parameter FRM_BITS = 3 ,
    parameter FLA_BITS = 5 ,
    parameter SIG_BITS = 53,
    parameter SIG_SIZE = 6 ,
//    parameter FRA_BITS = 53,
    parameter EXP_BITS = 12
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
//parameter QNAN_S = 64'h7fc00000; 
parameter QNAN_D = 64'h7ff80000_00000000; 

//localparam EXPUNOR_MIN_S = 12'b0_0110_1011    ;
localparam EXPUNOR_MIN_D = 12'b0_011_1100_1110;
//localparam EXPUNOR_MAX_S = 12'b0_1000_0001    ;
localparam EXPUNOR_MAX_D = 12'b0_100_0000_0001;
 
assign s_axis_a_tready = s1_ready;
assign s_axis_b_tready = s1_ready;
assign m_axis_res_tvalid = s4_valid;
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

wire is_sub = s1_sel;

//exp compare(12 bits)
wire                comp_exp_ab  = s1_exp_a < s1_exp_b;
wire [EXP_BITS-1:0] exp_diff     = comp_exp_ab ? s1_exp_b - s1_exp_a : s1_exp_a - s1_exp_b;

//sig right shift
/* verilator lint_off WIDTHTRUNC*/
wire [SIG_SIZE    :0] sig_amt = (exp_diff >= SIG_BITS+2) ? SIG_BITS+2 : exp_diff[SIG_SIZE:0];
/* verilator lint_on WIDTHTRUNC*/

wire [SIG_BITS-1:0] guardmask  = sig_amt >= 1 ?  (1                << (sig_amt-1)) : 0;
wire [SIG_BITS-1:0] roundmask  = sig_amt >= 2 ?  (1                << (sig_amt-2)) : 0;
wire [SIG_BITS-1:0] stickymask = sig_amt >= 3 ? ~({SIG_BITS{1'b1}} << (sig_amt-2)) : 0;
//wire [SIG_BITS-1:0] full_sigShift_a =  comp_exp_ab ? s1_sig_a >> sig_amt : s1_sig_a;
//wire [SIG_BITS-1:0] full_sigShift_b = !comp_exp_ab ? s1_sig_b >> sig_amt : s1_sig_b;
wire [SIG_BITS-1:0] sigShift_a =  comp_exp_ab ? s1_sig_a >> sig_amt : s1_sig_a;
wire [SIG_BITS-1:0] sigShift_b = !comp_exp_ab ? s1_sig_b >> sig_amt : s1_sig_b;

/*======== stage 2 ========*/
reg                s2_comp_exp_ab ;
reg [SIG_BITS-1:0] s2_guardmask   ;
reg [SIG_BITS-1:0] s2_roundmask   ;
reg [SIG_BITS-1:0] s2_stickymask  ;
reg [SIG_BITS-1:0] s2_sigShift_a  ;
reg [SIG_BITS-1:0] s2_sigShift_b  ;

reg                s2_is_sub;

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
        s2_guardmask    <= 0;
        s2_roundmask    <= 0;
        s2_stickymask   <= 0;
        s2_sigShift_a   <= 0;
        s2_sigShift_b   <= 0;

        s2_is_sub   <= 0;

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
            s2_guardmask    <= guardmask   ;
            s2_roundmask    <= roundmask   ;
            s2_stickymask   <= stickymask  ;
            s2_sigShift_a   <= sigShift_a  ;
            s2_sigShift_b   <= sigShift_b  ;

            s2_is_sub   <= is_sub     ;

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

wire guard_a  = |(s2_guardmask  & s2_sig_a);
wire guard_b  = |(s2_guardmask  & s2_sig_b);
wire round_a  = |(s2_roundmask  & s2_sig_a);
wire round_b  = |(s2_roundmask  & s2_sig_b);
wire sticky_a = |(s2_stickymask & s2_sig_a);
wire sticky_b = |(s2_stickymask & s2_sig_b);

wire guardBit  = s2_comp_exp_ab ? guard_a  : guard_b ; 
wire roundBit  = s2_comp_exp_ab ? round_a  : round_b ; 
wire stickyBit = s2_comp_exp_ab ? sticky_a : sticky_b; 

wire stickyBits_a = guard_a || round_a || sticky_a;
wire stickyBits_b = guard_b || round_b || sticky_b;
//sig origin add/sub(53 bits)

wire                sel_sign_b   = s2_sign_b ^ s2_is_sub;
wire                is_effsub    = sel_sign_b ^ s2_sign_a;
wire                comp_op      = s2_sigShift_a > s2_sigShift_b;

wire                overflow;
/* verilator lint_off WIDTHEXPAND */
wire [SIG_BITS-1:0] eff_sub_res  = comp_op ? s2_sigShift_a - s2_sigShift_b - stickyBits_b : s2_sigShift_b - s2_sigShift_a - stickyBits_a;//sticky : Borrow in
/* verilator lint_on WIDTHEXPAND */
wire                eff_sub_sign = comp_op ? s2_sign_a : sel_sign_b;
wire [SIG_BITS-1:0] eff_add_res;
assign {overflow,   eff_add_res} = s2_sigShift_a + s2_sigShift_b;
wire                eff_add_sign = s2_sign_a;

wire [SIG_BITS-1:0] add_sub_res  = is_effsub ? eff_sub_res  : eff_add_res ;
wire                add_sub_sign = is_effsub ? eff_sub_sign : eff_add_sign;
wire                of           = is_effsub ? 1'b0         : overflow    ;

wire [2:0] borrow_grs     = 3'b0 - {guardBit, roundBit, stickyBit};
wire       real_guardBit  = is_effsub ? borrow_grs[2] : guardBit ;
wire       real_roundBit  = is_effsub ? borrow_grs[1] : roundBit ;
wire       real_stickyBit = is_effsub ? borrow_grs[0] : stickyBit;
wire [SIG_BITS+2:0] real_sig = {add_sub_res, real_guardBit, real_roundBit, real_stickyBit};

//sig left shift
wire [SIG_SIZE:0] pos;
ldz #(
    .DATA_BITS(SIG_BITS+3),
    .DATA_SIZE(SIG_SIZE  )
) LDZ (
    .in  (real_sig),
    .out (pos     )
);

wire [SIG_SIZE-1:0] lamt = pos[SIG_SIZE-1:0];
wire [SIG_BITS+2:0] ls_sig_res  = real_sig << lamt;

wire [SIG_BITS-1:0] s_sig_res   = of ? {1'b1, add_sub_res[SIG_BITS-1:1]} : (pos[SIG_SIZE] ? 0              : ls_sig_res[SIG_BITS+2:3]);
wire                s_guardBit  = of ? add_sub_res[0]                    : (pos[SIG_SIZE] ? real_guardBit  : ls_sig_res[2]           );
wire                s_roundBit  = of ? real_guardBit                     : (pos[SIG_SIZE] ? real_roundBit  : ls_sig_res[1]           );
wire                s_stickyBit = of ? real_roundBit || real_stickyBit   : (pos[SIG_SIZE] ? real_stickyBit : ls_sig_res[0]           );
wire                s_sign_res  = pos[SIG_SIZE] && !of ? s2_frm == 3'b010 : add_sub_sign;

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
reg                s3_guardBit  ;
reg                s3_roundBit  ;
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
            if      (s4_ready && s2_valid) s3_next_state = S3_WAIT;
            else if (s4_ready            ) s3_next_state = S3_IDLE;
            else                           s3_next_state = S3_WAIT;
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
        s3_guardBit   <= 0;
        s3_roundBit   <= 0;
        s3_stickyBit  <= 0;
        s3_s_sign_res <= 0;
        s3_s_exp_res  <= 0;
    end else begin
        s3_current_state <= s3_next_state;
        if(s2_valid && s3_ready) begin
            s3_sel_sign_b <= sel_sign_b;
                                          
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
            s3_guardBit   <= s_guardBit   ;
            s3_roundBit   <= s_roundBit   ;
            s3_stickyBit  <= s_stickyBit  ;
            s3_s_sign_res <= s_sign_res   ;
            s3_s_exp_res  <= s_exp_res    ;
        end
    end
end

assign s3_valid = s3_current_state == S3_WAIT;
assign s3_ready = s3_current_state == S3_IDLE || (s3_valid && s4_ready);

//round
wire s4_valid;
wire s4_ready;

wire [SIG_BITS -1:0] o_sig ;
wire [EXP_BITS -1:0] o_exp ;
wire                 o_sign;
wire [FLA_BITS -1:0] fflags;

wire                r_sel_sign_b;

wire [FRM_BITS-1:0] r_frm     ;
wire                r_sign_a  ;
wire [SIG_BITS-1:0] r_sig_a   ;
wire [EXP_BITS-1:0] r_exp_a   ;
wire                r_isQNAN_a;
wire                r_isSNAN_a;
wire                r_isINf_a ;
wire                r_isZero_a;

wire [SIG_BITS-1:0] r_sig_b   ;
wire [EXP_BITS-1:0] r_exp_b   ;
wire                r_isQNAN_b;
wire                r_isSNAN_b;
wire                r_isINf_b ;
wire                r_isZero_b;

fadd_round #(
    .SIG_BITS(SIG_BITS),
    .EXP_BITS(EXP_BITS)
) ROUND (
    .clk         (aclk         ),
    .rst         (areset       ),

    .i_valid     (s3_valid     ),
    .i_ready     (s4_ready     ),

	.sig         (s3_s_sig_res ),
	.exp         (s3_s_exp_res ),
	.sign        (s3_s_sign_res),
	.Inguard     (s3_guardBit  ),
	.Inround     (s3_roundBit  ),
	.Insticky    (s3_stickyBit ),
	.nv          (1'b0         ),
	.dz          (1'b0         ),
	.frm         (s3_frm       ),

    .i_sel_sign_b(s3_sel_sign_b),
    .i_sign_a    (s3_sign_a    ),
    .i_sig_a     (s3_sig_a     ),
    .i_exp_a     (s3_exp_a     ),
    .i_isQNAN_a  (s3_isQNAN_a  ),
    .i_isSNAN_a  (s3_isSNAN_a  ),
    .i_isINf_a   (s3_isINf_a   ),
    .i_isZero_a  (s3_isZero_a  ),
    .i_sig_b     (s3_sig_b     ),
    .i_exp_b     (s3_exp_b     ),
    .i_isQNAN_b  (s3_isQNAN_b  ),
    .i_isSNAN_b  (s3_isSNAN_b  ),
    .i_isINf_b   (s3_isINf_b   ),
    .i_isZero_b  (s3_isZero_b  ),

    .o_valid     (s4_valid     ),
    .o_ready     (o_ready      ),

	.fflags      (fflags       ),
/*verilator lint_off PINCONNECTEMPTY*/
	.underUnormal(             ),
/*verilator lint_on PINCONNECTEMPTY*/
	.o_sig       (o_sig        ),
	.o_exp       (o_exp        ),
    .o_sign      (o_sign       ),

    .o_sel_sign_b(r_sel_sign_b ),
    .o_frm       (r_frm        ),
    .o_sign_a    (r_sign_a     ),
    .o_sig_a     (r_sig_a      ),
    .o_exp_a     (r_exp_a      ),
    .o_isQNAN_a  (r_isQNAN_a   ),
    .o_isSNAN_a  (r_isSNAN_a   ),
    .o_isINf_a   (r_isINf_a    ),
    .o_isZero_a  (r_isZero_a   ),
    .o_sig_b     (r_sig_b      ),
    .o_exp_b     (r_exp_b      ),
    .o_isQNAN_b  (r_isQNAN_b   ),
    .o_isSNAN_b  (r_isSNAN_b   ),
    .o_isINf_b   (r_isINf_b    ),
    .o_isZero_b  (r_isZero_b   ) 
);


//inf 
wire                DINf_sign_res = r_sign_a ^ r_sel_sign_b ? QNAN_D[63]            : r_sign_a;//Inf Inf
wire [EXP_BITS-1:0] DINf_exp_res  = r_sign_a ^ r_sel_sign_b ? {1'b1, QNAN_D[62:52]} : r_exp_a ;
wire [SIG_BITS-1:0] DINf_sig_res  = r_sign_a ^ r_sel_sign_b ? {1'b1, QNAN_D[51: 0]} : r_sig_a ;

wire                CINf_sign_res = r_isINf_a ? r_sign_a : r_sel_sign_b;//Inf C
wire [EXP_BITS-1:0] CINf_exp_res  = r_isINf_a ? r_exp_a  : r_exp_b     ;
wire [SIG_BITS-1:0] CINf_sig_res  = r_isINf_a ? r_sig_a  : r_sig_b     ;

wire                INf_sign_res = r_isINf_a && r_isINf_b ? DINf_sign_res : CINf_sign_res ;
wire [EXP_BITS-1:0] INf_exp_res  = r_isINf_a && r_isINf_b ? DINf_exp_res  : CINf_exp_res  ;
wire [SIG_BITS-1:0] INf_sig_res  = r_isINf_a && r_isINf_b ? DINf_sig_res  : CINf_sig_res  ;

//zero
wire isUnormalize_a = (r_exp_a >= EXPUNOR_MIN_D) && (r_exp_a <= EXPUNOR_MAX_D);
wire [EXP_BITS-1:0] Unormalize_n_a = EXPUNOR_MAX_D - r_exp_a; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_a = isUnormalize_a ? r_sig_a >> (Unormalize_n_a + 1) : r_sig_a; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire isUnormalize_b = (r_exp_b >= EXPUNOR_MIN_D) && (r_exp_b <= EXPUNOR_MAX_D);
wire [EXP_BITS-1:0] Unormalize_n_b = EXPUNOR_MAX_D - r_exp_b; //-127 - e
wire [SIG_BITS-1:0] Zero_sig_b = isUnormalize_b ? r_sig_b >> (Unormalize_n_b + 1) : r_sig_b; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire                Zero_sign_res = r_isZero_a && r_isZero_b ? (r_sel_sign_b ^ r_sign_a ? r_frm == 3'b010 : r_sign_a) ://0 (+/-) 0
                                    r_isZero_a                ?  r_sel_sign_b                                             : r_sign_a;
wire [EXP_BITS-1:0] Zero_exp_res  = r_isZero_a ? r_exp_b   : r_exp_a  ;
wire [SIG_BITS-1:0] Zero_sig_res  = r_isZero_a ? Zero_sig_b : Zero_sig_a;

wire isSNAN = r_isSNAN_a || r_isSNAN_b;
wire isQNAN = r_isQNAN_a || r_isQNAN_b;
wire isINf  = r_isINf_a  || r_isINf_b ;
wire isZero = r_isZero_a || r_isZero_b;
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
                           isINf  ? {r_isINf_a && r_isINf_b && (r_sign_a ^ r_sel_sign_b), 4'b0} :
                           isZero ? 5'h00                       : fflags;
//assign busy = (s1_ready && i_valid) || s1_current_state != S1_IDLE || s2_current_state != S2_IDLE || r_current_state != r_IDLE;

endmodule
