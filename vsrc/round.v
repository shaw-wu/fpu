module round #(
    parameter SIG_BITS = 32,
	parameter EXP_BITS = 9 ,
	parameter FRA_BITS = 23
)(
	input  [SIG_BITS -1:0] sig         ,
	input  [EXP_BITS -1:0] exp         ,
	input                  sign        ,
	input 				   isNAN       ,
	input 				   isINf       ,
	input 				   isZero      ,
	input 				   isNormalize ,
	input 				   isUnormalize,
	input 				   nv          ,
	input 				   dz          ,
	input  [          2:0] frm         ,
	input  [          4:0] fflags      ,
	output [SIG_BITS -1:0] o_sig       ,
	output [EXP_BITS -1:0] o_exp       ,
    output                 o_sign      
);

wire guardBit;
wire roundBit;
wire stickyBit;
wire roundIncre;

wire of = &sig[SIG_BITS-1 -: FRA_BITS] && roundIncre;

assign guardBit = sig[SIG_BITS-FRA_BITS-1];
assign roundBit = sig[SIG_BITS-FRA_BITS-2];
assign stickyBit = |sig[SIG_BITS-FRA_BITS-3:0];
assign roundIncre = (frm == 3'b000) ? (roundBit && stickyBit) || (roundBit && !stickyBit && guardBit) :
					(frm == 3'b001) ? 0 															  :	
					(frm == 3'b010) ?  sign && (roundBit || stickyBit)								  :	
					(frm == 3'b011) ? !sign && (roundBit || stickyBit)								  :	
					(frm == 3'b100) ?  roundBit														  : 0;	

assign o_exp = of ? exp + 1 : exp;
assign o_sig = of ? {1'b1, {(SIG_BITS-1){1'b0}} : {sig[SIG_BITS-1:SIG_BITS-FRA_BITS-1] + roudIncre, {(SIG_BITS-FRA_BITS-1){1'b0}}};
assign o_sign = sign;

wire nx = (roundBit || stickyBit) && ((!roundBit || !stickyBit) && roundIncre);
wire of = &exp;
wire uf = isUnormalize;

assign fflags = {nv, dz, of, uf, nx};
endmodule
