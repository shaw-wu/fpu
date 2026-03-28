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
	//input 					 isNAN       ,
	//input 					 isINf       ,
	output [FP_BITS    -1:0] fp           
);

//localparam EXPUNOR_MIN_S = 12'b0_0110_1011    ;
localparam EXPUNOR_MIN_D = 12'b0_011_1100_1110;
//localparam EXPUNOR_MAX_S = 12'b0_1000_0001    ;
localparam EXPUNOR_MAX_D = 12'b0_100_0000_0001;
localparam EXPNOR_MIN_D = 12'b0_100_0000_0010;
localparam EXPNOR_MAX_D = 12'b1_011_1111_1111;
 
wire [EXP_BITS-1 :0] exp_st ;
wire [FRA_BITS-1 :0] fra_st ;

//exception value
wire isNAN        =  exp[RECEXP_BITS-1-:3] == 3'b111;
wire isINf        =  exp[RECEXP_BITS-1-:3] == 3'b110;
wire isZero       =  exp < EXPUNOR_MIN_D;
wire isNormalize  = (exp >= EXPNOR_MIN_D ) && (exp <= EXPNOR_MAX_D );
wire isUnormalize = (exp >= EXPUNOR_MIN_D) && (exp <= EXPUNOR_MAX_D);

/*verilator lint_off UNUSED*/
wire [RECEXP_BITS-1:0] _exp;
assign _exp = exp - EXP_OFFSET;

//EXP/SIG logic      
assign exp_st = isNAN        ? {EXP_BITS{1'b1}}   :
				isINf  		 ? {EXP_BITS{1'b1}}   :
				isZero 		 ? {EXP_BITS{1'b0}}   :
				isUnormalize ? {EXP_BITS{1'b0}}   :
				isNormalize  ? _exp[EXP_BITS-1:0] : {EXP_BITS{1'b1}}; 

assign fra_st = isNAN        ? sig[SIG_BITS-2 -: FRA_BITS]       :
				isINf  		 ? {FRA_BITS{1'b0}}			         :
				isZero 		 ? {FRA_BITS{1'b0}}			         :
				isUnormalize ? sig[SIG_BITS-2-:FRA_BITS]         :   //unormalize : sigshift done
				isNormalize  ? sig[SIG_BITS-2-:FRA_BITS]         : sig[SIG_BITS-2-:FRA_BITS] ;	

assign fp = {sign, exp_st, fra_st};

endmodule
