module round #(
    parameter SIG_BITS    = 24,
	parameter EXP_BITS    = 9 
)(
	input  [SIG_BITS -1:0] sig         ,
	input  [EXP_BITS -1:0] exp         ,
	input                  sign        ,
	input                  Inguard     ,
	input                  Inround     ,
	input                  Insticky    ,
	input 				   nv          ,
	input 				   dz          ,
	input  [          2:0] frm         ,
	output                 underUnormal,
	output [          4:0] fflags      ,
	output [SIG_BITS -1:0] o_sig       ,
	output [EXP_BITS -1:0] o_exp       ,
    output                 o_sign      
);

//localparam EXPNOR_MAX_S  = 12'b1_0111_1111    ;
localparam EXPNOR_MAX_D  = 12'b1_011_1111_1111;

//localparam EXPUNOR_MIN_S = 12'b0_0110_1011    ;
localparam EXPUNOR_MIN_D = 12'b0_011_1100_1110;
//localparam EXPUNOR_MAX_S = 12'b0_1000_0001    ;
localparam EXPUNOR_MAX_D = 12'b0_100_0000_0001;

wire i_underUnormal = (exp < EXPUNOR_MIN_D);
wire is_zero = exp[EXP_BITS-1-:3] == 3'b000;
assign underUnormal = (o_exp <  EXPUNOR_MIN_D);
wire i_isUnormalize = (exp   <= EXPUNOR_MAX_D);
wire isUnormalize   = (o_exp <= EXPUNOR_MAX_D);

wire [EXP_BITS-1:0] Unormalize_n   = EXPUNOR_MAX_D - exp; //-127 - e
wire [SIG_BITS+2:0] full_shift_sig = {sig, Inguard, Inround, Insticky};
wire [SIG_BITS-1:0] shift_sig = i_isUnormalize ? full_shift_sig[SIG_BITS+2:3] >> (Unormalize_n + 1) : sig; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire [SIG_BITS+2:0] guardmask  =  (1                    << (Unormalize_n + 3));
wire [SIG_BITS+2:0] roundmask  =  (1                    << (Unormalize_n + 2));
wire [SIG_BITS+2:0] stickymask = ~({(SIG_BITS+3){1'b1}} << (Unormalize_n + 2));
wire guard  = |(guardmask  & full_shift_sig);
wire round  = |(roundmask  & full_shift_sig);
wire sticky = |(stickymask & full_shift_sig);

wire lsbBit     = shift_sig[0];
wire guardBit   = i_isUnormalize ? guard   : Inguard ;
wire roundBit   = i_isUnormalize ? round   : Inround ;
wire stickyBits = i_isUnormalize ? sticky  : Insticky;
wire roundIncre = (frm == 3'b000) ? guardBit && (lsbBit || stickyBits || roundBit) : //rte
				  (frm == 3'b001) ? 0 											   :	//rtz
				  (frm == 3'b010) ?  sign && (guardBit || roundBit || stickyBits)  :	//rdn
				  (frm == 3'b011) ? !sign && (guardBit || roundBit || stickyBits)  :	//rup
				  (frm == 3'b100) ?  guardBit                                      : 0; //rmm	

wire [SIG_BITS-1:0] sig_res;
wire sig_cout;
/*verilator lint_off WIDTHEXPAND*/
assign {sig_cout, sig_res} = shift_sig[SIG_BITS-1:0] + roundIncre;
/*verilator lint_on WIDTHEXPAND*/

wire [SIG_BITS-1:0] of_sig = (frm == 3'b000) ? {1'b1, {(SIG_BITS-1){1'b0 }}} :
                             (frm == 3'b001) ? {SIG_BITS{1'b1}}              :
                             (frm == 3'b010) ? {1'b1, {(SIG_BITS-1){!sign}}} :
                             (frm == 3'b011) ? {1'b1, {(SIG_BITS-1){ sign}}} :
                             (frm == 3'b100) ? {1'b1, {(SIG_BITS-1){1'b0 }}} : 0;
wire [EXP_BITS-1:0] of_exp = (frm == 3'b000) ? EXPNOR_MAX_D + 1     :
                             (frm == 3'b001) ? EXPNOR_MAX_D         :
/*verilator lint_off WIDTHEXPAND*/
                             (frm == 3'b010) ? EXPNOR_MAX_D + sign  :
                             (frm == 3'b011) ? EXPNOR_MAX_D + !sign :
/*verilator lint_on WIDTHEXPAND*/
                             (frm == 3'b100) ? EXPNOR_MAX_D + 1     : 0;

assign o_exp = of                                    ? of_exp        : 
               i_underUnormal && roundIncre          ? EXPUNOR_MIN_D : 
/*verilator lint_off WIDTHEXPAND*/
               i_isUnormalize && sig_res[SIG_BITS-1] ? exp + 1       : exp + sig_cout;
/*verilator lint_on WIDTHEXPAND*/
assign o_sig = of                                  ? of_sig                       : 
               sig_cout                            ? {1'b1, {(SIG_BITS-1){1'b0}}} : sig_res;
assign o_sign = sign;

wire nx = guardBit || roundBit || stickyBits || of || (underUnormal && !is_zero);
wire of = (exp > EXPNOR_MAX_D) || ((exp + {{(EXP_BITS-1){1'b0}}, sig_cout}) > EXPNOR_MAX_D);//exp > 127
wire uf = (isUnormalize && nx) || (underUnormal && !is_zero); //exp < -126-23 

assign fflags = {nv, dz, of, uf, nx};

endmodule
