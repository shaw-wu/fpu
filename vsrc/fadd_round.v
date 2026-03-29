module fadd_round #(
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

    input                  i_sel_sign_b,
    input                  i_sign_a    ,
    input  [SIG_BITS -1:0] i_sig_a     ,
    input  [EXP_BITS -1:0] i_exp_a     ,
    input                  i_isQNAN_a  ,
    input                  i_isSNAN_a  ,
    input                  i_isINf_a   ,
    input                  i_isZero_a  ,
    input  [SIG_BITS -1:0] i_sig_b     ,
    input  [EXP_BITS -1:0] i_exp_b     ,
    input                  i_isQNAN_b  ,
    input                  i_isSNAN_b  ,
    input                  i_isINf_b   ,
    input                  i_isZero_b  ,

    output                 o_valid     ,
    input                  o_ready     ,

	output                 underUnormal,
	output [          4:0] fflags      ,
	output [SIG_BITS -1:0] o_sig       ,
	output [EXP_BITS -1:0] o_exp       ,
    output                 o_sign      ,

    output                 o_sel_sign_b,
	output [          2:0] o_frm       ,
    output                 o_sign_a    ,
    output [SIG_BITS -1:0] o_sig_a     ,
    output [EXP_BITS -1:0] o_exp_a     ,
    output                 o_isQNAN_a  ,
    output                 o_isSNAN_a  ,
    output                 o_isINf_a   ,
    output                 o_isZero_a  ,
    output [SIG_BITS -1:0] o_sig_b     ,
    output [EXP_BITS -1:0] o_exp_b     ,
    output                 o_isQNAN_b  ,
    output                 o_isSNAN_b  ,
    output                 o_isINf_b   ,
    output                 o_isZero_b   
);

assign i_ready = s4_ready;
assign o_valid = s4_valid;

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

/* ====== stage 4 ====== */
reg                s4_sel_sign_b;
reg                s4_sign_a    ;
reg [SIG_BITS-1:0] s4_sig_a     ;
reg [EXP_BITS-1:0] s4_exp_a     ;
reg                s4_isQNAN_a  ;
reg                s4_isSNAN_a  ;
reg                s4_isINf_a   ;
reg                s4_isZero_a  ;
reg [SIG_BITS-1:0] s4_sig_b     ;
reg [EXP_BITS-1:0] s4_exp_b     ;
reg                s4_isQNAN_b  ;
reg                s4_isSNAN_b  ;
reg                s4_isINf_b   ;
reg                s4_isZero_b  ;

reg [EXP_BITS-1:0] s4_exp           ;
reg                s4_sign          ;
reg                s4_Inguard       ;
reg                s4_Inround       ;
reg                s4_Insticky      ;
reg 		  	   s4_nv            ;
reg 		  	   s4_dz            ;
reg [         2:0] s4_frm           ;

reg                s4_i_underUnormal;
reg                s4_is_zero       ;
reg                s4_i_isUnormalize;
reg [SIG_BITS-1:0] s4_shift_sig     ;
reg                s4_guard         ;
reg                s4_round         ;
reg                s4_sticky        ;

localparam S4_IDLE = 2'b01; 
localparam S4_WAIT = 2'b10; 

reg [1:0] s4_current_state, s4_next_state;

always@(*) begin
    case(s4_current_state)
        S4_IDLE : begin
            if(i_valid) s4_next_state = S4_WAIT;
            else        s4_next_state = S4_IDLE;
        end
        S4_WAIT : begin
            if     (o_ready && i_valid) s4_next_state = S4_WAIT;
            else if(o_ready           ) s4_next_state = S4_IDLE;
            else                         s4_next_state = S4_WAIT;
        end
        default : s4_next_state = S4_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s4_current_state  <= S4_IDLE;

        s4_sel_sign_b     <= 0;
        s4_sign_a         <= 0;
        s4_sig_a          <= 0;
        s4_exp_a          <= 0;
        s4_isQNAN_a       <= 0;
        s4_isSNAN_a       <= 0;
        s4_isINf_a        <= 0;
        s4_isZero_a       <= 0;
        s4_sig_b          <= 0;
        s4_exp_b          <= 0;
        s4_isQNAN_b       <= 0;
        s4_isSNAN_b       <= 0;
        s4_isINf_b        <= 0;
        s4_isZero_b       <= 0;

        s4_exp            <= 0;
        s4_sign           <= 0;
        s4_Inguard        <= 0;
        s4_Inround        <= 0;
        s4_Insticky       <= 0;
        s4_nv             <= 0;
        s4_dz             <= 0;
        s4_frm            <= 0;

        s4_i_underUnormal <= 0;
        s4_is_zero        <= 0;
        s4_i_isUnormalize <= 0;
        s4_shift_sig      <= 0;
        s4_guard          <= 0;
        s4_round          <= 0;
        s4_sticky         <= 0;

    end else begin
        s4_current_state <= s4_next_state;
        if(i_valid && s4_ready) begin
            s4_sel_sign_b     <= i_sel_sign_b  ;
            s4_sign_a         <= i_sign_a      ;
            s4_sig_a          <= i_sig_a       ;
            s4_exp_a          <= i_exp_a       ;
            s4_isQNAN_a       <= i_isQNAN_a    ;
            s4_isSNAN_a       <= i_isSNAN_a    ;
            s4_isINf_a        <= i_isINf_a     ;
            s4_isZero_a       <= i_isZero_a    ;
            s4_sig_b          <= i_sig_b       ;
            s4_exp_b          <= i_exp_b       ;
            s4_isQNAN_b       <= i_isQNAN_b    ;
            s4_isSNAN_b       <= i_isSNAN_b    ;
            s4_isINf_b        <= i_isINf_b     ;
            s4_isZero_b       <= i_isZero_b    ;
            
            s4_exp            <= exp           ;
            s4_sign           <= sign          ;
            s4_Inguard        <= Inguard       ;
            s4_Inround        <= Inround       ;
            s4_Insticky       <= Insticky      ;
            s4_nv             <= nv            ;
            s4_dz             <= dz            ;
            s4_frm            <= frm           ;
                                                  
            s4_i_underUnormal <= i_underUnormal;
            s4_is_zero        <= is_zero       ;
            s4_i_isUnormalize <= i_isUnormalize;
            s4_shift_sig      <= shift_sig     ;
            s4_guard          <= guard         ;
            s4_round          <= round         ;
            s4_sticky         <= sticky        ;
        end
    end
end

wire s4_valid = (s4_current_state == S4_WAIT);
wire s4_ready = (s4_current_state == S4_IDLE) || (s4_valid && o_ready);

wire lsbBit     = s4_shift_sig[0];
wire guardBit   = s4_i_isUnormalize ? s4_guard   : s4_Inguard ;
wire roundBit   = s4_i_isUnormalize ? s4_round   : s4_Inround ;
wire stickyBits = s4_i_isUnormalize ? s4_sticky  : s4_Insticky;
wire roundIncre = (s4_frm == 3'b000) ? guardBit && (lsbBit || stickyBits || roundBit)    : //rte
				  (s4_frm == 3'b001) ? 0 											     :	//rtz
				  (s4_frm == 3'b010) ?  s4_sign && (guardBit || roundBit || stickyBits)  :	//rdn
				  (s4_frm == 3'b011) ? !s4_sign && (guardBit || roundBit || stickyBits)  :	//rup
				  (s4_frm == 3'b100) ?  guardBit                                         : 0; //rmm	

wire [SIG_BITS-1:0] sig_res;
wire sig_cout;
/*verilator lint_off WIDTHEXPAND*/
assign {sig_cout, sig_res} = s4_shift_sig[SIG_BITS-1:0] + roundIncre;
/*verilator lint_on WIDTHEXPAND*/

wire [SIG_BITS-1:0] of_sig = (s4_frm == 3'b000) ? {1'b1, {(SIG_BITS-1){1'b0    }}} :
                             (s4_frm == 3'b001) ? {SIG_BITS{1'b1}}                 :
                             (s4_frm == 3'b010) ? {1'b1, {(SIG_BITS-1){!s4_sign}}} :
                             (s4_frm == 3'b011) ? {1'b1, {(SIG_BITS-1){ s4_sign}}} :
                             (s4_frm == 3'b100) ? {1'b1, {(SIG_BITS-1){1'b0    }}} : 0;
wire [EXP_BITS-1:0] of_exp = (s4_frm == 3'b000) ? EXPNOR_MAX_D + 1        :
                             (s4_frm == 3'b001) ? EXPNOR_MAX_D            :
/*verilator lint_off WIDTHEXPAND*/
                             (s4_frm == 3'b010) ? EXPNOR_MAX_D + s4_sign  :
                             (s4_frm == 3'b011) ? EXPNOR_MAX_D + !s4_sign :
/*verilator lint_on WIDTHEXPAND*/
                             (s4_frm == 3'b100) ? EXPNOR_MAX_D + 1        : 0;

wire isUnormalize   = (o_exp <= EXPUNOR_MAX_D);
assign o_exp = of                                       ? of_exp           : 
               s4_i_underUnormal && roundIncre          ? EXPUNOR_MIN_D    : 
/*verilator lint_off WIDTHEXPAND*/
               s4_i_isUnormalize && sig_res[SIG_BITS-1] ? s4_exp + 1       : s4_exp + sig_cout;
/*verilator lint_on WIDTHEXPAND*/
assign o_sig = of                                  ? of_sig                       : 
               sig_cout                            ? {1'b1, {(SIG_BITS-1){1'b0}}} : sig_res;
assign o_sign = s4_sign;

wire nx = guardBit || roundBit || stickyBits || of || (underUnormal && !s4_is_zero);
wire of = (s4_exp > EXPNOR_MAX_D) || ((s4_exp + {{(EXP_BITS-1){1'b0}}, sig_cout}) > EXPNOR_MAX_D);//exp > 127
wire uf = (isUnormalize && nx   ) || (underUnormal && !s4_is_zero); //exp < -126-23 

assign underUnormal = (o_exp <  EXPUNOR_MIN_D);
assign fflags = {s4_nv, s4_dz, of, uf, nx};

assign o_sel_sign_b = s4_sel_sign_b;
assign o_frm        = s4_frm       ;
assign o_sign_a     = s4_sign_a    ;
assign o_sig_a      = s4_sig_a     ;
assign o_exp_a      = s4_exp_a     ;
assign o_isQNAN_a   = s4_isQNAN_a  ;
assign o_isSNAN_a   = s4_isSNAN_a  ;
assign o_isINf_a    = s4_isINf_a   ;
assign o_isZero_a   = s4_isZero_a  ;
assign o_sig_b      = s4_sig_b     ;
assign o_exp_b      = s4_exp_b     ;
assign o_isQNAN_b   = s4_isQNAN_b  ;
assign o_isSNAN_b   = s4_isSNAN_b  ;
assign o_isINf_b    = s4_isINf_b   ;
assign o_isZero_b   = s4_isZero_b  ;

endmodule
