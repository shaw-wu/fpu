`timescale 1ns / 1ps
module tostdFN #(
	parameter FP_BITS     = 32            ,
	parameter EXP_BITS    = 8             ,
	parameter FRA_BITS    = 23            ,
	parameter SIG_BITS    = 32            ,
	parameter RECEXP_BITS = 9             ,
	parameter EXP_OFFSET  = 9'b1_0000_0001
)(
/*verilator lint_off UNUSED*/
	input 					 sign        ,
	input  [RECEXP_BITS-1:0] exp		 ,
	input  [SIG_BITS   -1:0] sig		 ,
	input 					 isNAN       ,
	input 					 isINf       ,
	output [FP_BITS    -1:0] fp           
);

wire [EXP_BITS-1 :0] exp_st ;
wire [FRA_BITS-1 :0] fra_st ;

//exception value
wire isZero       =  exp[RECEXP_BITS-1-:3] == 3'b000;
wire isNormalize  = (exp >= 9'b0_1000_0010) && (exp <= 9'b1_0111_1111);
wire isUnormalize = (exp >= 9'b0_0110_1011) && (exp <= 9'b0_1000_0001);

wire [REEXP_BITS-1:0] Unormalize_n = 9'b0_1000_0001 - exp //-127 - e

/*verilator lint_off UNUSED*/
wire [RECEXP_BITS-1:0] _exp;
assign _exp = exp - EXP_OFFSET;

//EXP/SIG logic      
assign exp_st = isNAN        ? {EXP_BITS{1'b1}} :
				isINf  		 ? {EXP_BITS{1'b1}} :
				isZero 		 ? {EXP_BITS{1'b0}} :
				isUnormalize ? {EXP_BITS{1'b0}} :
				isNormalize  ? _exp[7:0]        : {EXP_BITS{1'b1}}; 

assign fra_st = isNAN        ? sig[SIG_BITS-1 -: FRA_BITS]       :
				isINf  		 ? {FRA_BITS{1'b0}}			         :
				isZero 		 ? {FRA_BITS{1'b0}}			         :
				isUnormalize ? sig[SIG_BITS-1:0] >> Unormalize_n :
				isNormalize  ? sig[SIG_BITS-2-:FRA_BITS]         : sig[SIG_BITS-2-:FRA_BITS] ;	

assign fp = {sign, exp_st, fra_st};

endmodule
