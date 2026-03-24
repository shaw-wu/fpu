module fmul #(
    parameter DATA_WIDTH = 32,
    parameter FRM_BITS   = 3 ,
    parameter FLA_BITS   = 5 ,
    parameter SIG_BITS   = 24,
//    parameter SIG_SIZE   = 5 ,
    parameter FRA_BITS   = 24,
    parameter EXP_BITS   = 9
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
localparam QNAN = 32'h7fc00000;
wire i_valid = s_axis_a_tvalid && s_axis_b_tvalid;
wire o_ready = m_axis_res_tready;
assign s_axis_a_tready   = s1_ready;
assign s_axis_b_tready   = s1_ready;
assign m_axis_res_tvalid = s1_valid;

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
            if     (o_ready && i_valid) s1_next_state = S1_WAIT;
            else if(o_ready           ) s1_next_state = S1_IDLE;
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
assign s1_ready = (s1_current_state == S1_IDLE) || ((s1_current_state == S1_WAIT) && o_ready);

//exp adder
wire [EXP_BITS-1:0] compl_exp_a = {!exp_a[EXP_BITS-1], exp_a[EXP_BITS-2:0]};
wire [EXP_BITS-1:0] compl_exp_b = {!exp_b[EXP_BITS-1], exp_b[EXP_BITS-2:0]};

wire [EXP_BITS-1:0] compl_add_exp = compl_exp_a + compl_exp_b;
wire neg_overflow =  compl_exp_a[EXP_BITS-1] &&  compl_exp_b[EXP_BITS-1] ? !compl_add_exp[EXP_BITS-1] : 0;
wire pos_overflow = !compl_exp_a[EXP_BITS-1] && !compl_exp_b[EXP_BITS-1] ?  compl_add_exp[EXP_BITS-1] : 0;

//sig multiplier
wire [2*SIG_BITS+1:0] compl_sig_res;
mul #(
    .DATA_WIDTH(SIG_BITS+1)
) MUL(
    .m     ({1'b0, sig_a  }),
    .r     ({1'b0, sig_b  }),
    .result(compl_sig_res  )
);
wire [2*SIG_BITS-1:0] sig_res = compl_sig_res[2*SIG_BITS-1:0];


//sig left shift
//wire [SIG_SIZE+1:0] pos;
//ldz #(
//    .DATA_BITS(2*SIG_BITS),
//    .DATA_SIZE(SIG_SIZE+1)
//) LDZ (
//    .in  (sig_res),
//    .out (pos    )
//);
//
//wire [  SIG_SIZE-1:0] lamt = pos[SIG_SIZE-1:0];
wire                  carry = sig_res[2*SIG_BITS-1];
wire [2*SIG_BITS-1:0] s_sig_res  = carry ? sig_res : sig_res << 1;
wire                  s_sign_res = sign_a ^ sign_b;
/* verilator lint_off WIDTHEXPAND */
wire [EXP_BITS-1:0] exp_res = compl_add_exp + carry;
wire res_over = !compl_add_exp[EXP_BITS-1] && exp_res[EXP_BITS-1];
/* verilator lint_on WIDTHEXPAND */
wire [EXP_BITS-1:0] s_exp_res = neg_overflow             ? 0                              : 
                                pos_overflow || res_over ? {3'b110, {(EXP_BITS-3){1'b0}}} : {!exp_res[EXP_BITS-1], exp_res[EXP_BITS-2:0]};
//wire [EXP_BITS-1:0] s_exp_res = {!exp_res[EXP_BITS-1], exp_res[EXP_BITS-2:0]};

//round
wire underUnormal;
wire [2*SIG_BITS-1:0] r_sig ;
wire [EXP_BITS  -1:0] r_exp ;
wire                  r_sign;
wire [FLA_BITS  -1:0] fflags;

round #(
    .SIG_BITS(2*SIG_BITS),
    .EXP_BITS(EXP_BITS  ),
    .FRA_BITS(FRA_BITS  )
) ROUND (
	.sig         (s_sig_res   ),
	.exp         (s_exp_res   ),
	.sign        (s_sign_res  ),
	.Insticky    (1'b0        ),
	.nv          (1'b0        ),
	.dz          (1'b0        ),
	.frm         (frm         ),
	.fflags      (fflags      ),
	.underUnormal(underUnormal),
	.o_sig       (r_sig       ),
	.o_exp       (r_exp       ),
    .o_sign      (r_sign      )
);

wire [SIG_BITS-1:0] o_sig  = underUnormal ? 0 : r_sig[2*SIG_BITS-1:SIG_BITS];
wire [EXP_BITS-1:0] o_exp  = underUnormal ? 0 : r_exp ;
wire                o_sign = r_sign;

//inf 
wire                INf_sign_res = (isZero_a && isINf_b) || (isZero_b && isINf_a) ? QNAN[DATA_WIDTH-1] : sign_a ^ sign_b;//Inf Inf
wire [EXP_BITS-1:0] INf_exp_res  = (isZero_a && isINf_b) || (isZero_b && isINf_a) ? {1'b1, QNAN[FRA_BITS-1+:EXP_BITS-1]} : {3'b110, {(EXP_BITS-3){1'b0}}};
wire [SIG_BITS-1:0] INf_sig_res  = (isZero_a && isINf_b) || (isZero_b && isINf_a) ? {1'b1, QNAN[FRA_BITS-2 :         0]} : 0                             ;

//zero

wire                Zero_sign_res = sign_a ^ sign_b;
wire [EXP_BITS-1:0] Zero_exp_res  = 0;
wire [SIG_BITS-1:0] Zero_sig_res  = 0;

wire isSNAN = isSNAN_a || isSNAN_b;
wire isQNAN = isQNAN_a || isQNAN_b;
wire isINf  = isINf_a  || isINf_b ;
wire isZero = isZero_a || isZero_b;
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
                           isINf  ? {(isZero_a && isINf_b) || (isZero_b && isINf_a), 4'b0} :
                           isZero ? 5'h00                       : fflags;
endmodule
