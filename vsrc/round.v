module round #(
	parameter SIG_BITS = 32,
	parameter FRA_BITS = 23
)(
	input  [SIG_BITS -1:0] sig ,
	input	 [EXP_BITS -1:0] exp ,
	input									 sign,
	input	 [FRAM_BITS-1:0] frm ,
	output [SIG_BITS -1:0] o_sig,
	output [EXP_BITS -1:0] o_exp
);

wire of = &sig[SIG_BITS-1:SIG_BITS-FRA_BITS-1] && roundIncre;

wire guardBit;
wire roundBit;
wire stickyBit;
wire roundIncre;
assign guardBit = sig[SIG_BITS-FRA_BITS-1];
assign roundBit = sig[SIG_BITS-FRA_BITS-2];
assign stickyBit = |sig[SIG_BITS-FRA_BITS-3:0];
assign roundIncre = (frm == 3'b000) ? (roundBit && stickyBit) || (roundBit && !stickyBit && guardBit) :
								    (frm == 3'b001) ? 0 																															:	
								    (frm == 3'b010) ?  sign && (roundBit || stickyBit)																:	
								    (frm == 3'b011) ? !sign && (roundBit || stickyBit)																:	
								    (frm == 3'b100) ?  roundBit																												: 0;	

assign o_exp = of ? exp + 1 : exp;
assign o_sig = of ? {1'b1, {(SIG_BITS-1){1'b0}} : {sig[SIG_BITS-1:SIG_BITS-FRA_BITS-1] + roudIncre, {(SIG_BITS-FRA_BITS-1){1'b0}}};
endmodule
