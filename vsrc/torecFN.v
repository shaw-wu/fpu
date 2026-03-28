`timescale 1ns / 1ps
module torecFN #(
	parameter FP_BITS     = 32            ,
	parameter FP_LOG      = 5             ,//clog2(FP_BITS)
	parameter EXP_BITS    = 8             ,
	parameter FRA_BITS    = 23            ,
	parameter SIG_BITS    = 32            ,
	parameter RECEXP_BITS = 9             ,
	parameter EXP_OFFSET  = 9'b0_1000_0001
)(
	input  [FP_BITS    -1:0] fp          , 
	output 					 sign        ,
	output [RECEXP_BITS-1:0] exp         ,
	output [SIG_BITS   -1:0] sig         ,
	output 					 isQNAN      ,
	output 					 isSNAN      ,
	output 					 isINf       ,
	output 					 isUnormalize,
	output 					 isNormalize ,
	output 					 isZero
);

wire			     sign_st;
wire [EXP_BITS-1 :0] exp_st ;
wire [FRA_BITS-1 :0] fra_st ;

//unpack fp
assign sign_st = fp[FP_BITS-1]          ;
assign exp_st  = fp[FP_BITS -2:FRA_BITS];
assign fra_st  = fp[FRA_BITS-1:       0];

//expection
assign isQNAN 		= (exp_st == {EXP_BITS{1'b1}} &&  fra_st[FRA_BITS-1]               );
assign isSNAN 		= (exp_st == {EXP_BITS{1'b1}} && !fra_st[FRA_BITS-1] && fra_st != 0);
assign isINf		= (exp_st == {EXP_BITS{1'b1}} &&  fra_st == 0);
assign isZero		= (exp_st == 0 && fra_st == 0);
assign isUnormalize = (exp_st == 0 && fra_st != 0);
assign isNormalize  = (exp_st != 0 && exp_st != {EXP_BITS{1'b1}});

//Leading Zero Detect
/*verilator lint_off UNUSED*/
wire [FP_LOG  :0] pos;
/*verilator lint_on UNUSED*/
wire [FP_LOG-1:0] n  ;
ldz #(
    .DATA_BITS(FP_BITS),
    .DATA_SIZE(FP_LOG )
) LZD (
	.in ({fra_st, {(FP_BITS-FRA_BITS){1'b0}}}),
	.out(pos)
);
wire [FP_LOG-1:0] shift_amt = pos[FP_LOG-1:0];
assign n = shift_amt;  

function [RECEXP_BITS-1:0] fill_exp(input [2:0] top);
	fill_exp = {top , {(RECEXP_BITS-3){1'b1}}};
endfunction;	

function [SIG_BITS-1:0] fill_sig(input [FRA_BITS-1:0] fr);
	fill_sig = {1'b1, fr, {(SIG_BITS-FRA_BITS-1){1'b0}}};
endfunction;	
                     
//EXP/SIG logic      
assign exp = isQNAN || isSNAN ? fill_exp(3'b111)                :
			 isINf  	      ? fill_exp(3'b110)                :
			 isZero 	      ? 0                               :
             /* verilator lint_off WIDTHEXPAND */
			 isUnormalize     ? (EXP_OFFSET - n)                : 
             /* verilator lint_on WIDTHEXPAND */
			 isNormalize      ? ({1'b0, exp_st} + EXP_OFFSET)	: fill_exp(3'b111); 

assign sig = isQNAN || isSNAN ? fill_sig(fra_st)									     :
			 isINf  	      ? fill_sig({FRA_BITS{1'b1}})							     :
			 isZero 	      ? 0                            						     :
			 isUnormalize     ? {fra_st << n, {(SIG_BITS-FRA_BITS){1'b0}}}               :
			 isNormalize      ? fill_sig(fra_st)									     : fill_sig(fra_st);

assign sign = sign_st;

endmodule
