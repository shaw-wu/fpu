`timescale 1ns / 1ps
module torecFN #(
	parameter FP_BITS     = 32,
	parameter EXP_BITS    = 8 ,
	parameter FRA_BITS    = 23,
	parameter SIG_BITS    = 32,
	parameter RECEXP_BITS = 9 ,
	parameter EXP_OFFSET  = 9'b1_0000_0001
)(
	input  [FP_BITS    -1:0] fp          , 
	output 								   sign        ,
	output [RECEXP_BITS-1:0] exp				 ,
	output [SIG_BITS   -1:0] sig				 ,
	output 									 isNAN       ,
	output 								 	 isINf       ,
	output 								 	 isZero      ,
	output 								 	 isNormalize ,
	output 								 	 isUnormalize
);

localparam FP_LOG  = clog2(FP_BITS);

wire								 sign_st				;
wire [EXP_BITS-1 :0] exp_st 				;
wire [FRA_BITS-1 :0] fra_st 				;

//unpack fp
assign sign_st = fp[FP_BITS-1]          ;
assign exp_st  = fp[FP_BITS -2:FRA_BITS];
assign fra_st  = fp[FRA_BITS-1:       0];

//is logic
assign isZero				 = (exp_st == 0 && fra_st == 0);
assign isUnormalize  = (exp_st == 0 && fra_st != 0);
assign isINf				 = (exp_st == {EXP_BITS{1'b1}} && fra_st == 0);
assign isNAN 			   = (exp_st == {EXP_BITS{1'b1}} && fra_st != 0);
assign isNormalize   = (exp_st != 0 && exp_st != {EXP_BITS{1'b1}});

//Leading Zero Detect
wire [FP_LOG-1:0] pos;
wire [FP_LOG-1:0] n  ;
LZD_5 lzd (
	.in ({{(FP_BITS-FRA_BITS){1'b0}}, fra_st}),
	.out(pos)
);
assign n = pos + 1;  

function [RECEXP_BITS-1:0] fill_exp(input [2:0] top);
	fill_exp = {top , {(RECEXP_BITS-3){1'b1}}};
endfunction;	

function [SIG_BITS-1:0] fill_sig(input [FRA_BITS-1:0] fr);
	fill_sig = {3'b001, fr, {(SIG_BITS-FRA_BITS-3){1'b0}}};
endfunction;	
                     
//EXP/SIG logic      
assign exp = isNAN				? fill_exp(3'b111)																																	:
						 isINf  			? fill_exp(3'b110)																																	:
						 isZero 			? fill_exp(3'b000)																																	:
						 isUnormalize ? (EXP_OFFSET + {{(RECEXP_BITS-1){1'b0}}, 1'b1} - {{(RECEXP_BITS-FP_LOG){1'b0}}, n}):
						 isNormalize  ? ({1'b0, exp_st} + EXP_OFFSET)																											:
			                      fill_exp(3'b111)                       																						; 

assign sig = isNAN				? fill_sig(fra_st)																	    :
					   isINf  			? fill_sig({FRA_BITS{1'b1}})														:
					   isZero 			? fill_sig({FRA_BITS{1'b0}})													  :
					   isUnormalize ? fill_sig({fra_st << {{(FRA_BITS-FP_LOG-1){1'b0}}, n}}):
					   isNormalize  ? fill_sig(fra_st)														          :
					   		            fill_sig(fra_st)                                      ;	

assign sign = sign_st;

function integer clog2;
	input integer value;
	integer i;
	begin
		clog2 = 0;
		for(i = value - 1; i > 0; i = i >> 1)
			clog2 = clog2 + 1;
	end
endfunction

endmodule
