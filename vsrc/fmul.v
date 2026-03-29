module fmul #(
    parameter DATA_WIDTH = 64,
    parameter FRM_BITS   = 3 ,
    parameter FLA_BITS   = 5 ,
    parameter SIG_BITS   = 53,
//    parameter SIG_SIZE   = 5 ,
    parameter EXP_BITS   = 12 
)(
/*verilator lint_off UNUSED*/
	input                 aclk			 ,
    input                 areset         ,

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
//localparam QNAN_S = 64'h7fc00000;
localparam QNAN_D = 64'h7ff80000_00000000;

wire i_valid = s_axis_a_tvalid && s_axis_b_tvalid;
wire o_ready = m_axis_res_tready;
assign s_axis_a_tready   = s1_ready;
assign s_axis_b_tready   = s1_ready;
assign m_axis_res_tvalid = s7_valid;

/*======== stage 1 ========*/
reg [FRM_BITS-1:0] frm   ;

reg                sign_a;
reg [EXP_BITS-1:0] exp_a ;
reg [SIG_BITS-1:0] sig_a ;

reg                sign_b;
reg [EXP_BITS-1:0] exp_b ;
reg [SIG_BITS-1:0] sig_b ;

reg isQNAN_a;
reg isSNAN_a;
reg isINf_a ;
reg isZero_a;
reg isQNAN_b;
reg isSNAN_b;
reg isINf_b ;
reg isZero_b;

wire s1_valid, s1_ready;

localparam S1_IDLE = 2'b01;
localparam S1_WAIT = 2'b10;

reg [1:0] s1_current_state, s1_next_state;

always@(*) begin
    case(s1_current_state)
        S1_IDLE : begin
            if(i_valid) s1_next_state = S1_WAIT;
            else        s1_next_state = S1_IDLE;
        end
        S1_WAIT : begin
            if     (s2_ready && i_valid) s1_next_state = S1_WAIT;
            else if(s2_ready           ) s1_next_state = S1_IDLE;
            else                        s1_next_state = S1_IDLE;
        end
        default : s1_next_state = S1_IDLE;
    endcase
end

always@(posedge aclk or posedge areset) begin
    if(areset) begin
        s1_current_state <= S1_IDLE;

        frm    <= 0;
        
        sign_a <= 0;
        exp_a  <= 0;
        sig_a  <= 0;
        
        sign_b <= 0;
        exp_b  <= 0;
        sig_b  <= 0;
        
        isQNAN_a <= 0;
        isSNAN_a <= 0;
        isINf_a  <= 0;
        isZero_a <= 0;
        isQNAN_b <= 0;
        isSNAN_b <= 0;
        isINf_b  <= 0;
        isZero_b <= 0;
    end else begin
        s1_current_state <= s1_next_state;
        if(s1_ready && i_valid) begin
            frm    <= s_axis_frm   ;
            
            sign_a <= s_axis_a_sign;
            exp_a  <= s_axis_a_exp ;
            sig_a  <= s_axis_a_sig ;
            
            sign_b <= s_axis_b_sign;
            exp_b  <= s_axis_b_exp ;
            sig_b  <= s_axis_b_sig ;
            
            isQNAN_a <= s_axis_a_isQNAN;
            isSNAN_a <= s_axis_a_isSNAN;
            isINf_a  <= s_axis_a_isINf ;
            isZero_a <= s_axis_a_isZero;
            isQNAN_b <= s_axis_b_isQNAN;
            isSNAN_b <= s_axis_b_isSNAN;
            isINf_b  <= s_axis_b_isINf ;
            isZero_b <= s_axis_b_isZero;
        end
    end
end

assign s1_valid = s1_current_state == S1_WAIT;
assign s1_ready = (s1_current_state == S1_IDLE) || ((s1_current_state == S1_WAIT) && s2_ready);

//exp adder
wire [EXP_BITS-1:0] compl_exp_a = {!exp_a[EXP_BITS-1], exp_a[EXP_BITS-2:0]};
wire [EXP_BITS-1:0] compl_exp_b = {!exp_b[EXP_BITS-1], exp_b[EXP_BITS-2:0]};

wire [EXP_BITS-1:0] compl_add_exp = compl_exp_a + compl_exp_b;
wire neg_overflow =  compl_exp_a[EXP_BITS-1] &&  compl_exp_b[EXP_BITS-1] ? !compl_add_exp[EXP_BITS-1] : 0;
wire pos_overflow = !compl_exp_a[EXP_BITS-1] && !compl_exp_b[EXP_BITS-1] ?  compl_add_exp[EXP_BITS-1] : 0;

/*======== stage 2 ========*/
reg [FRM_BITS-1:0] s2_frm   ;
reg                s2_sign_a;
reg [SIG_BITS-1:0] s2_sig_a ;
reg                s2_sign_b;
reg [SIG_BITS-1:0] s2_sig_b ;

reg [EXP_BITS-1:0] s2_compl_add_exp;
reg                s2_neg_overflow ;
reg                s2_pos_overflow ;

reg s2_isQNAN_a;
reg s2_isSNAN_a;
reg s2_isINf_a ;
reg s2_isZero_a;
reg s2_isQNAN_b;
reg s2_isSNAN_b;
reg s2_isINf_b ;
reg s2_isZero_b;

localparam S2_IDLE = 2'b01; 
localparam S2_WAIT = 2'b10; 

reg [1:0] s2_current_state, s2_next_state;

always@(*) begin
    case(s2_current_state)
        S2_IDLE : begin
            if(s1_valid) s2_next_state = S2_WAIT;
            else        s2_next_state = S2_IDLE;
        end
        S2_WAIT : begin
            if     (s3_ready && s1_valid) s2_next_state = S2_WAIT;
            else if(s3_ready           ) s2_next_state = S2_IDLE;
            else                         s2_next_state = S2_WAIT;
        end
        default : s2_next_state = S2_IDLE;
    endcase
end

always@(posedge aclk, posedge areset) begin
    if(areset) begin
        s2_current_state <= S2_IDLE;
        s2_frm           <= 0;
        s2_sign_a        <= 0;
        s2_sig_a         <= 0;
        s2_sign_b        <= 0;
        s2_sig_b         <= 0;
        s2_compl_add_exp <= 0;
        s2_neg_overflow  <= 0;
        s2_pos_overflow  <= 0;
        s2_isQNAN_a      <= 0;
        s2_isSNAN_a      <= 0;
        s2_isINf_a       <= 0;
        s2_isZero_a      <= 0;
        s2_isQNAN_b      <= 0;
        s2_isSNAN_b      <= 0;
        s2_isINf_b       <= 0;
        s2_isZero_b      <= 0;
    end else begin
        s2_current_state <= s2_next_state;
        if(s1_valid && s2_ready) begin
            s2_frm           <= frm          ;
            s2_sign_a        <= sign_a       ;
            s2_sig_a         <= sig_a        ;
            s2_sign_b        <= sign_b       ;
            s2_sig_b         <= sig_b        ;
            s2_compl_add_exp <= compl_add_exp;
            s2_neg_overflow  <= neg_overflow ;
            s2_pos_overflow  <= pos_overflow ;
            s2_isQNAN_a      <= isQNAN_a     ;
            s2_isSNAN_a      <= isSNAN_a     ;
            s2_isINf_a       <= isINf_a      ;
            s2_isZero_a      <= isZero_a     ;
            s2_isQNAN_b      <= isQNAN_b     ;
            s2_isSNAN_b      <= isSNAN_b     ;
            s2_isINf_b       <= isINf_b      ;
            s2_isZero_b      <= isZero_b     ;
        end
    end
end

wire s2_valid = (s2_current_state == S2_WAIT);
wire s2_ready = (s2_current_state == S2_IDLE) || (s2_valid && s3_ready);

/*====== stage 3-6 ======*/
//sig multiplier
wire s3_valid;
wire s3_ready;

wire [FRM_BITS-1:0] s6_frm   ;
wire                s6_sign_a;
wire                s6_sign_b;
wire [EXP_BITS-1:0] s6_compl_add_exp;
wire                s6_neg_overflow ;
wire                s6_pos_overflow ;
wire                s6_isQNAN_a;
wire                s6_isSNAN_a;
wire                s6_isINf_a ;
wire                s6_isZero_a;
wire                s6_isQNAN_b;
wire                s6_isSNAN_b;
wire                s6_isINf_b ;
wire                s6_isZero_b;

wire [2*SIG_BITS+1:0] compl_sig_res;
mul #(
    .DATA_WIDTH(SIG_BITS+1),
    .FRM_BITS  (FRM_BITS  ),
    .EXP_BITS  (EXP_BITS  )
) MUL(
    .clk            (aclk            ),
    .rst            (areset          ),
    .i_valid        (s2_valid        ),
    .i_ready        (s3_ready        ),

    .i_frm          (s2_frm          ),
    .i_sign_a       (s2_sign_a       ),
    .i_sign_b       (s2_sign_b       ),
    .i_compl_add_exp(s2_compl_add_exp),
    .i_neg_overflow (s2_neg_overflow ),
    .i_pos_overflow (s2_pos_overflow ),
    .i_isQNAN_a     (s2_isQNAN_a     ),
    .i_isSNAN_a     (s2_isSNAN_a     ),
    .i_isINf_a      (s2_isINf_a      ),
    .i_isZero_a     (s2_isZero_a     ),
    .i_isQNAN_b     (s2_isQNAN_b     ),
    .i_isSNAN_b     (s2_isSNAN_b     ),
    .i_isINf_b      (s2_isINf_b      ),
    .i_isZero_b     (s2_isZero_b     ),

    .m              ({1'b0, s2_sig_a}),
    .r              ({1'b0, s2_sig_b}),
    .o_valid        (s3_valid        ),
    .o_ready        (s7_ready        ),

    .o_frm          (s6_frm          ),
    .o_sign_a       (s6_sign_a       ),
    .o_sign_b       (s6_sign_b       ),
    .o_compl_add_exp(s6_compl_add_exp),
    .o_neg_overflow (s6_neg_overflow ),
    .o_pos_overflow (s6_pos_overflow ),
    .o_isQNAN_a     (s6_isQNAN_a     ),
    .o_isSNAN_a     (s6_isSNAN_a     ),
    .o_isINf_a      (s6_isINf_a      ),
    .o_isZero_a     (s6_isZero_a     ),
    .o_isQNAN_b     (s6_isQNAN_b     ),
    .o_isSNAN_b     (s6_isSNAN_b     ),
    .o_isINf_b      (s6_isINf_b      ),
    .o_isZero_b     (s6_isZero_b     ),

    .result         (compl_sig_res   )
);

/*======== stage 7 ========*/
reg [FRM_BITS-1:0] s7_frm   ;
reg                s7_sign_a;
reg                s7_sign_b;

reg [EXP_BITS-1:0] s7_compl_add_exp;
reg                s7_neg_overflow ;
reg                s7_pos_overflow ;

reg s7_isQNAN_a;
reg s7_isSNAN_a;
reg s7_isINf_a ;
reg s7_isZero_a;
reg s7_isQNAN_b;
reg s7_isSNAN_b;
reg s7_isINf_b ;
reg s7_isZero_b;

reg [2*SIG_BITS+1:0] s7_compl_sig_res;

wire s7_valid, s7_ready;

localparam S7_IDLE = 2'b01;
localparam S7_WAIT = 2'b10;

reg [1:0] s7_current_state, s7_next_state;

always@(*) begin
    case(s7_current_state)
        S7_IDLE : begin
            if(s3_valid) s7_next_state = S7_WAIT;
            else         s7_next_state = S7_IDLE;
        end
        S7_WAIT : begin
            if     (o_ready && s3_valid) s7_next_state = S7_WAIT;
            else if(o_ready            ) s7_next_state = S7_IDLE;
            else                         s7_next_state = S7_IDLE;
        end
        default : s7_next_state = S7_IDLE;
    endcase
end

always@(posedge aclk or posedge areset) begin
    if(areset) begin
        s7_current_state <= S7_IDLE;

        s7_frm           <= 0;
        s7_sign_a        <= 0;
        s7_sign_b        <= 0;
        
        s7_compl_add_exp <= 0;
        s7_neg_overflow  <= 0;
        s7_pos_overflow  <= 0;
      
        s7_isQNAN_a <= 0;
        s7_isSNAN_a <= 0;
        s7_isINf_a  <= 0;
        s7_isZero_a <= 0;
        s7_isQNAN_b <= 0;
        s7_isSNAN_b <= 0;
        s7_isINf_b  <= 0;
        s7_isZero_b <= 0;
        
        s7_compl_sig_res <= 0;
    end else begin
        s7_current_state <= s7_next_state;
        if(s7_ready && s3_valid) begin
            s7_frm           <= s6_frm          ;
            s7_sign_a        <= s6_sign_a       ;
            s7_sign_b        <= s6_sign_b       ;
                                
            s7_compl_add_exp <= s6_compl_add_exp;
            s7_neg_overflow  <= s6_neg_overflow ;
            s7_pos_overflow  <= s6_pos_overflow ;

            s7_isQNAN_a      <= s6_isQNAN_a     ;
            s7_isSNAN_a      <= s6_isSNAN_a     ;
            s7_isINf_a       <= s6_isINf_a      ;
            s7_isZero_a      <= s6_isZero_a     ;
            s7_isQNAN_b      <= s6_isQNAN_b     ;
            s7_isSNAN_b      <= s6_isSNAN_b     ;
            s7_isINf_b       <= s6_isINf_b      ;
            s7_isZero_b      <= s6_isZero_b     ;

            s7_compl_sig_res <= compl_sig_res   ;
        end
    end
end

assign s7_valid = s7_current_state == S7_WAIT;
assign s7_ready = (s7_current_state == S7_IDLE) || ((s7_current_state == S7_WAIT) && o_ready);

wire [2*SIG_BITS-1:0] sig_res = s7_compl_sig_res[2*SIG_BITS-1:0];


wire                  carry      = sig_res[2*SIG_BITS-1];
wire [2*SIG_BITS-1:0] s_sig_res  = carry ? sig_res : sig_res << 1;
wire                  s_sign_res = s7_sign_a ^ s7_sign_b;
wire                  guardBit   =  s_sig_res[SIG_BITS-1  ];
wire                  roundBit   =  s_sig_res[SIG_BITS-2  ];
wire                  stickyBit  = |s_sig_res[SIG_BITS-3:0];
/* verilator lint_off WIDTHEXPAND */
wire [EXP_BITS-1:0] exp_res = s7_compl_add_exp + carry;
wire res_over = !s7_compl_add_exp[EXP_BITS-1] && exp_res[EXP_BITS-1];
/* verilator lint_on WIDTHEXPAND */
wire [EXP_BITS-1:0] s_exp_res = s7_neg_overflow             ? 0                              : 
                                s7_pos_overflow || res_over ? {3'b110, {(EXP_BITS-3){1'b0}}} : {!exp_res[EXP_BITS-1], exp_res[EXP_BITS-2:0]};

//round
wire underUnormal;
wire [SIG_BITS-1:0] r_sig ;
wire [EXP_BITS-1:0] r_exp ;
wire                r_sign;
wire [FLA_BITS-1:0] fflags;

round #(
    .SIG_BITS(SIG_BITS),
    .EXP_BITS(EXP_BITS)
) ROUND (
	.sig         (s_sig_res[2*SIG_BITS-1:SIG_BITS]),
	.exp         (s_exp_res                       ),
	.sign        (s_sign_res                      ),
	.Inguard     (guardBit                        ),
	.Inround     (roundBit                        ),
	.Insticky    (stickyBit                       ),
	.nv          (1'b0                            ),
	.dz          (1'b0                            ),
	.frm         (s7_frm                          ),
	.fflags      (fflags                          ),
	.underUnormal(underUnormal                    ),
	.o_sig       (r_sig                           ),
	.o_exp       (r_exp                           ),
    .o_sign      (r_sign                          )
);

wire [SIG_BITS-1:0] o_sig  = underUnormal ? 0 : r_sig;
wire [EXP_BITS-1:0] o_exp  = underUnormal ? 0 : r_exp;
wire                o_sign = r_sign;

//inf 
wire                INf_sign_res = (s7_isZero_a && s7_isINf_b) || (s7_isZero_b && s7_isINf_a) ? QNAN_D[DATA_WIDTH-1] : s7_sign_a ^ s7_sign_b;//Inf Inf
wire [EXP_BITS-1:0] INf_exp_res  = (s7_isZero_a && s7_isINf_b) || (s7_isZero_b && s7_isINf_a) ? {1'b1, QNAN_D[SIG_BITS-1+:EXP_BITS-1]} : {3'b110, {(EXP_BITS-3){1'b0}}};
wire [SIG_BITS-1:0] INf_sig_res  = (s7_isZero_a && s7_isINf_b) || (s7_isZero_b && s7_isINf_a) ? {1'b1, QNAN_D[SIG_BITS-2 :         0]} : 0                             ;

//zero

wire                Zero_sign_res = s7_sign_a ^ s7_sign_b;
wire [EXP_BITS-1:0] Zero_exp_res  = 0;
wire [SIG_BITS-1:0] Zero_sig_res  = 0;

wire isSNAN = s7_isSNAN_a || s7_isSNAN_b;
wire isQNAN = s7_isQNAN_a || s7_isQNAN_b;
wire isINf  = s7_isINf_a  || s7_isINf_b ;
wire isZero = s7_isZero_a || s7_isZero_b;
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
                           isINf  ? {(s7_isZero_a && s7_isINf_b) || (s7_isZero_b && s7_isINf_a), 4'b0} :
                           isZero ? 5'h00                       : fflags;
endmodule
