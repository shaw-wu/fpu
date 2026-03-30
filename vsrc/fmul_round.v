module fmul_round #(
    parameter SIG_BITS    = 24,
	parameter EXP_BITS    = 9 
)(
    input                  clk         ,
    input                  rst         ,

    input                  i_valid     ,
    output                 i_ready     ,
	input  [SIG_BITS -1:0] sig         ,
	input  [EXP_BITS -1:0] exp         ,
	input                  sign        ,
	input                  Inguard     ,
	input                  Inround     ,
	input                  Insticky    ,
	input 				   nv          ,
	input 				   dz          ,
	input  [          2:0] frm         ,
    input                  i_sign_a    ,
    input                  i_sign_b    ,
    input                  i_isQNAN_a  ,
    input                  i_isSNAN_a  ,
    input                  i_isINf_a   ,
    input                  i_isZero_a  ,
    input                  i_isQNAN_b  ,
    input                  i_isSNAN_b  ,
    input                  i_isINf_b   ,
    input                  i_isZero_b  ,

    output                 o_valid     ,
    input                  o_ready     ,
	output [          4:0] fflags      ,
	output                 underUnormal,
    output                 o_sign_a    ,
    output                 o_sign_b    ,
    output                 o_isQNAN_a  ,
    output                 o_isSNAN_a  ,
    output                 o_isINf_a   ,
    output                 o_isZero_a  ,
    output                 o_isQNAN_b  ,
    output                 o_isSNAN_b  ,
    output                 o_isINf_b   ,
    output                 o_isZero_b  ,
	output [SIG_BITS -1:0] o_sig       ,
	output [EXP_BITS -1:0] o_exp       ,
    output                 o_sign      
);

assign i_ready = s8_ready;
assign o_valid = s8_valid;
//localparam EXPNOR_MAX_S  = 12'b1_0111_1111    ;
localparam EXPNOR_MAX_D  = 12'b1_011_1111_1111;

//localparam EXPUNOR_MIN_S = 12'b0_0110_1011    ;
localparam EXPUNOR_MIN_D = 12'b0_011_1100_1110;
//localparam EXPUNOR_MAX_S = 12'b0_1000_0001    ;
localparam EXPUNOR_MAX_D = 12'b0_100_0000_0001;

wire i_underUnormal = (exp < EXPUNOR_MIN_D);
wire is_zero = exp[EXP_BITS-1-:3] == 3'b000;
wire i_isUnormalize = (exp   <= EXPUNOR_MAX_D);

wire [EXP_BITS-1:0] Unormalize_n   = EXPUNOR_MAX_D - exp; //-127 - e
wire [SIG_BITS+2:0] full_shift_sig = {sig, Inguard, Inround, Insticky};
wire [SIG_BITS-1:0] shift_sig = i_isUnormalize ? full_shift_sig[SIG_BITS+2:3] >> (Unormalize_n + 1) : sig; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire [SIG_BITS+2:0] guardmask  =  (1                    << (Unormalize_n + 3));
wire [SIG_BITS+2:0] roundmask  =  (1                    << (Unormalize_n + 2));
wire [SIG_BITS+2:0] stickymask = ~({(SIG_BITS+3){1'b1}} << (Unormalize_n + 2));
wire guard  = |(guardmask  & full_shift_sig);
wire round  = |(roundmask  & full_shift_sig);
wire sticky = |(stickymask & full_shift_sig);

/* ====== stage 8 ====== */
reg                s8_sign_a        ;
reg                s8_sign_b        ;
reg                s8_isQNAN_a      ;
reg                s8_isSNAN_a      ;
reg                s8_isINf_a       ;
reg                s8_isZero_a      ;
reg                s8_isQNAN_b      ;
reg                s8_isSNAN_b      ;
reg                s8_isINf_b       ;
reg                s8_isZero_b      ;

reg [EXP_BITS-1:0] s8_exp           ;
reg                s8_sign          ;
reg                s8_Inguard       ;
reg                s8_Inround       ;
reg                s8_Insticky      ;
reg 		  	   s8_nv            ;
reg 		  	   s8_dz            ;
reg [         2:0] s8_frm           ;

reg                s8_i_underUnormal;
reg                s8_is_zero       ;
reg                s8_i_isUnormalize;
reg [SIG_BITS-1:0] s8_shift_sig     ;
reg                s8_guard         ;
reg                s8_round         ;
reg                s8_sticky        ;

localparam S8_IDLE = 2'b01; 
localparam S8_WAIT = 2'b10; 

reg [1:0] s8_current_state, s8_next_state;

always@(*) begin
    case(s8_current_state)
        S8_IDLE : begin
            if(i_valid) s8_next_state = S8_WAIT;
            else        s8_next_state = S8_IDLE;
        end
        S8_WAIT : begin
            if     (o_ready && i_valid) s8_next_state = S8_WAIT;
            else if(o_ready           ) s8_next_state = S8_IDLE;
            else                         s8_next_state = S8_WAIT;
        end
        default : s8_next_state = S8_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s8_current_state  <= S8_IDLE;

        s8_sign_a         <= 0;
        s8_sign_b         <= 0;
        s8_isQNAN_a       <= 0;
        s8_isSNAN_a       <= 0;
        s8_isINf_a        <= 0;
        s8_isZero_a       <= 0;
        s8_isQNAN_b       <= 0;
        s8_isSNAN_b       <= 0;
        s8_isINf_b        <= 0;
        s8_isZero_b       <= 0;

        s8_exp            <= 0;
        s8_sign           <= 0;
        s8_Inguard        <= 0;
        s8_Inround        <= 0;
        s8_Insticky       <= 0;
        s8_nv             <= 0;
        s8_dz             <= 0;
        s8_frm            <= 0;

        s8_i_underUnormal <= 0;
        s8_is_zero        <= 0;
        s8_i_isUnormalize <= 0;
        s8_shift_sig      <= 0;
        s8_guard          <= 0;
        s8_round          <= 0;
        s8_sticky         <= 0;

    end else begin
        s8_current_state <= s8_next_state;
        if(i_valid && s8_ready) begin
            s8_sign_a         <= i_sign_a      ;
            s8_sign_b         <= i_sign_b      ;
            s8_isQNAN_a       <= i_isQNAN_a    ;
            s8_isSNAN_a       <= i_isSNAN_a    ;
            s8_isINf_a        <= i_isINf_a     ;
            s8_isZero_a       <= i_isZero_a    ;
            s8_isQNAN_b       <= i_isQNAN_b    ;
            s8_isSNAN_b       <= i_isSNAN_b    ;
            s8_isINf_b        <= i_isINf_b     ;
            s8_isZero_b       <= i_isZero_b    ;
            
            s8_exp            <= exp           ;
            s8_sign           <= sign          ;
            s8_Inguard        <= Inguard       ;
            s8_Inround        <= Inround       ;
            s8_Insticky       <= Insticky      ;
            s8_nv             <= nv            ;
            s8_dz             <= dz            ;
            s8_frm            <= frm           ;
                                                  
            s8_i_underUnormal <= i_underUnormal;
            s8_is_zero        <= is_zero       ;
            s8_i_isUnormalize <= i_isUnormalize;
            s8_shift_sig      <= shift_sig     ;
            s8_guard          <= guard         ;
            s8_round          <= round         ;
            s8_sticky         <= sticky        ;
        end
    end
end

wire s8_valid = (s8_current_state == S8_WAIT);
wire s8_ready = (s8_current_state == S8_IDLE) || (s8_valid && o_ready);

wire lsbBit     = s8_shift_sig[0];
wire guardBit   = s8_i_isUnormalize ? s8_guard   : s8_Inguard ;
wire roundBit   = s8_i_isUnormalize ? s8_round   : s8_Inround ;
wire stickyBits = s8_i_isUnormalize ? s8_sticky  : s8_Insticky;
wire roundIncre = (s8_frm == 3'b000) ? guardBit && (lsbBit || stickyBits || roundBit)    : //rte
				  (s8_frm == 3'b001) ? 0 											     :	//rtz
				  (s8_frm == 3'b010) ?  s8_sign && (guardBit || roundBit || stickyBits)  :	//rdn
				  (s8_frm == 3'b011) ? !s8_sign && (guardBit || roundBit || stickyBits)  :	//rup
				  (s8_frm == 3'b100) ?  guardBit                                         : 0; //rmm	

wire [SIG_BITS-1:0] sig_res;
wire sig_cout;
/*verilator lint_off WIDTHEXPAND*/
assign {sig_cout, sig_res} = s8_shift_sig[SIG_BITS-1:0] + roundIncre;
/*verilator lint_on WIDTHEXPAND*/

wire [SIG_BITS-1:0] of_sig = (s8_frm == 3'b000) ? {1'b1, {(SIG_BITS-1){1'b0    }}} :
                             (s8_frm == 3'b001) ? {SIG_BITS{1'b1}}                 :
                             (s8_frm == 3'b010) ? {1'b1, {(SIG_BITS-1){!s8_sign}}} :
                             (s8_frm == 3'b011) ? {1'b1, {(SIG_BITS-1){ s8_sign}}} :
                             (s8_frm == 3'b100) ? {1'b1, {(SIG_BITS-1){1'b0    }}} : 0;
wire [EXP_BITS-1:0] of_exp = (s8_frm == 3'b000) ? EXPNOR_MAX_D + 1        :
                             (s8_frm == 3'b001) ? EXPNOR_MAX_D            :
/*verilator lint_off WIDTHEXPAND*/
                             (s8_frm == 3'b010) ? EXPNOR_MAX_D + s8_sign  :
                             (s8_frm == 3'b011) ? EXPNOR_MAX_D + !s8_sign :
/*verilator lint_on WIDTHEXPAND*/
                             (s8_frm == 3'b100) ? EXPNOR_MAX_D + 1        : 0;

wire isUnormalize   = (o_exp <= EXPUNOR_MAX_D);
assign o_exp = of                                       ? of_exp           : 
               s8_i_underUnormal && roundIncre          ? EXPUNOR_MIN_D    : 
/*verilator lint_off WIDTHEXPAND*/
               s8_i_isUnormalize && sig_res[SIG_BITS-1] ? s8_exp + 1       : s8_exp + sig_cout;
/*verilator lint_on WIDTHEXPAND*/
assign o_sig = of                                  ? of_sig                       : 
               sig_cout                            ? {1'b1, {(SIG_BITS-1){1'b0}}} : sig_res;
assign o_sign = s8_sign;

wire nx = guardBit || roundBit || stickyBits || of || (underUnormal && !s8_is_zero);
wire of = (s8_exp > EXPNOR_MAX_D) || ((s8_exp + {{(EXP_BITS-1){1'b0}}, sig_cout}) > EXPNOR_MAX_D);//exp > 127
wire uf = (isUnormalize && nx   ) || (underUnormal && !s8_is_zero); //exp < -126-23 

assign underUnormal = (o_exp <  EXPUNOR_MIN_D);
assign fflags = {s8_nv, s8_dz, of, uf, nx};

assign o_sign_a   = s8_sign_a  ;
assign o_sign_b   = s8_sign_b  ;
assign o_isQNAN_a = s8_isQNAN_a;
assign o_isSNAN_a = s8_isSNAN_a;
assign o_isINf_a  = s8_isINf_a ;
assign o_isZero_a = s8_isZero_a;
assign o_isQNAN_b = s8_isQNAN_b;
assign o_isSNAN_b = s8_isSNAN_b;
assign o_isINf_b  = s8_isINf_b ;
assign o_isZero_b = s8_isZero_b;

endmodule
