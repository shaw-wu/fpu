module torecFN #(
	parameter FP_BITS     = 32,
	parameter SIGN_BITS   = 1 ,
	parameter EXP_BITS    = 8 ,
	parameter FRA_BITS    = 23,
	parameter EXPREC_BITS = 9 ,
	parameter SIG_BITS    = 24,
	parameter EXP_OFFSET  = 9'b0_1000_0001
)(
	input      [FP_BITS-1    :0] fp          , 
	output reg [SIGN_BITS-1  :0] sign        ,
	output reg [EXPREC_BITS-1:0] exp				 ,
	output reg [SIG_BITS-1   :0] sig				 ,
	output reg									 isNAN       ,
	output reg								 	 isINf       ,
	output reg								 	 isZero      ,
	output reg								 	 isNormalize ,
	output reg								 	 isUnormalize
);

wire [SIGN_BITS-1:0] sign_st;
wire [EXP_BITS-1 :0] exp_st ;
wire [FRA_BITS-1 :0] fra_st ;
reg isNAN_st       ;
reg isINf_st       ;
reg isZero_st      ;
reg isNormalize_st ;
reg isUnormalize_st;
wire [EXPREC_BITS-1:0] exp_offset;

//unpack fp
assign sign_st = fp[FP_BITS-1]          ;
assign exp_st  = fp[FP_BITS-2 :FRA_BITS];
assign fra_st  = fp[FRA_BITS-1:       0];

//is logic
always @(*) begin
	isNAN_st				= 0;
	isINf_st 				= 0;
	isZero_st				= 0;
	isNormalize_st  = 0;
	isUnormalize_st = 0;
	if(exp_st == 0) begin
		if(fra_st == 0) isZero_st				= 1;
		else            isUnormalize_st = 1;
	end else if(exp_st == {EXP_BITS{1'b1}}) begin
		if(fra_st == 0) isINf						= 1;
		else						isNAN 					= 1;
	end else				  isNormalize_st  = 1;
end

//Leading Zero Detect
wire [SIG_BITS-1:0] n;
LZD l1 #(
	parameter IN_BITS  = FRA_BITS,
	parameter OUT_BITS = SIG_BITS
)(
	.in (fra_st ),
	.out(n      )
);

//EXP/SIG logic
always @(*) begin
	isNAN        = isNAN_st				;	
	isINf				 = isINf_st				;	
	isZero			 = isZero_st			;	
	isNormalize  = isNormalize_st ;	
	isUnormalize = isUnormalize_st;	
	sign				 = sign_st				;
	if(isNAN_st) begin
		exp = {3'b111, {(EXP_BITS-2){1'b0}}};
		sig = {1'b1  , fra_st}              ; 
	end else if(isInf_st) begin
		exp = {3'b110, {(EXP_BITS-2){1'b0}}};
		sig = {(FRA_BITS+1){1'b0}}          ; 
	end else if(isZero_st) begin
		exp = {3'b000, {(EXP_BITS-2){1'b0}}};
		sig = {(FRA_BITS+1){1'b0}}          ; 
	end else if(isUnormalize_st) begin
		exp = EXP_OFFSET + EXPREC_BITS'b1 - n;
		sig = {1'b1, fra_st << n}; 
	end else if(isNormalize_st) begin
		exp = {1'b0, exp_st} + EXP_OFFSET; 
		sig = {1'b1, fra_st}             ; 
	end else begin
		exp = {3'b111, {(EXP_BITS-2){1'b0}}};
		sig = SIG_BITS'b0                   ; 
	end
end

endmodule
