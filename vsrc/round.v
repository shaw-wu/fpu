module round #(
    parameter SIG_BITS    = 32,
	parameter EXP_BITS    = 9 ,
	parameter FRA_BITS    = 24 //{1, fraction}, 1 + 23
)(
	input  [SIG_BITS -1:0] sig         ,
	input  [EXP_BITS -1:0] exp         ,
	input                  sign        ,
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

localparam EXPNOR_MAX = {3'b101, {(EXP_BITS-3){1'b1}}};

assign underUnormal = (exp < 9'b0_0110_1011);
wire isUnormalize = (exp >= 9'b0_0110_1011) && (exp <= 9'b0_1000_0001);
wire [EXP_BITS-1:0] Unormalize_n = 9'b0_1000_0001 - exp; //-127 - e

wire [SIG_BITS-1:0] shift_sig = isUnormalize ? sig >> (Unormalize_n + 1) : sig; //sig[SIG_BITS-1:SIG_BITS-2] = 2e-126, 2e-127

wire lsbBit   = shift_sig[SIG_BITS-FRA_BITS  ];
wire guardBit = shift_sig[SIG_BITS-FRA_BITS-1];
wire roundBit = shift_sig[SIG_BITS-FRA_BITS-2];
wire stickyBit = |shift_sig[SIG_BITS-FRA_BITS-3:0] || Insticky;
wire roundIncre = (frm == 3'b000) ? guardBit && (lsbBit || stickyBit || roundBit) : //rte
				  (frm == 3'b001) ? 0 											  :	//rtz
				  (frm == 3'b010) ?  sign && (guardBit || roundBit || stickyBit)  :	//rdn
				  (frm == 3'b011) ? !sign && (guardBit || roundBit || stickyBit)  :	//rup
				  (frm == 3'b100) ?  guardBit                                     : 0; //rmm	

wire [FRA_BITS-1:0] sig_res;
wire sig_cout;
/*verilator lint_off WIDTHEXPAND*/
assign {sig_cout, sig_res} = shift_sig[SIG_BITS-1-:FRA_BITS] + roundIncre;
/*verilator lint_on WIDTHEXPAND*/

wire [SIG_BITS-1:0] of_sig = (frm == 3'b000) ? {1'b1, {(SIG_BITS-1){1'b0 }}} :
                             (frm == 3'b001) ? {SIG_BITS{1'b1}}              :
                             (frm == 3'b010) ? {1'b1, {(SIG_BITS-1){!sign}}} :
                             (frm == 3'b011) ? {1'b1, {(SIG_BITS-1){ sign}}} :
                             (frm == 3'b100) ? {1'b1, {(SIG_BITS-1){1'b0 }}} : 0;
wire [EXP_BITS-1:0] of_exp = (frm == 3'b000) ? EXPNOR_MAX + 1     :
                             (frm == 3'b001) ? EXPNOR_MAX         :
/*verilator lint_off WIDTHEXPAND*/
                             (frm == 3'b010) ? EXPNOR_MAX + sign  :
                             (frm == 3'b011) ? EXPNOR_MAX + !sign :
/*verilator lint_on WIDTHEXPAND*/
                             (frm == 3'b100) ? EXPNOR_MAX + 1     : 0;

assign o_exp = of ? of_exp : exp + {{(EXP_BITS-1){1'b0}}, sig_cout};
assign o_sig = of       ? of_sig                       : 
               sig_cout ? {1'b1, {(SIG_BITS-1){1'b0}}} : {sig_res, {(SIG_BITS-FRA_BITS){1'b0}}};
assign o_sign = sign;

wire nx = guardBit || roundBit || stickyBit || of || underUnormal;
wire of = (exp > EXPNOR_MAX) || ((exp + {{(EXP_BITS-1){1'b0}}, sig_cout}) > EXPNOR_MAX);//exp > 127
wire uf = (isUnormalize && nx) || underUnormal; //exp < -126-23 

assign fflags = {nv, dz, of, uf, nx};

endmodule
