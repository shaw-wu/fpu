module fpu #(
	parameter XLEN = 32,
	parameter OP_BITS = 4,
	parameter FRM_BITS = 3,
	parameter FFLAGS_BITS = 5
)(
	input [XLEN-1:0] fa,
	input [XLEN-1:0] fb,
	input [OP_BITS -1:0] opcode,
	input [FRM_BITS-1:0] frm	 ,
	output [FFLAGS_BITS-1:0] fflags,
	output [XLEN			 -1:0] result
);

//opcode
wire isfadd, isfsub, isfsgnj, isfsgnjn, isfsgnjx, 
		 isfeq, isflt, isfle, isfmin, isfmax;
wire is_sub;
assign isfadd   = opcode == 'd0;
assign isfsub   = opcode == 'd1;
assign isfsgnj  = opcode == 'd2;
assign isfsgnjn = opcode == 'd3;
assign isfsgnjx = opcode == 'd4;
assign isfeq    = opcode == 'd5;
assign isflt    = opcode == 'd6;
assign isfle    = opcode == 'd7;
assign isfmin   = opcode == 'd8;
assign isfmax   = opcode == 'd9;
assign is_sub = isfsub || isfeq || isflt || isfle || isfmin || isfmax;

//torecFN unpack
wire			  sign_a, sign_b;       
wire [8 :0]  exp_a, exp_b ;				 
wire [31:0]  sig_a, sig_b ;				 
wire  isNAN_a, isNAN_b ;    
wire  isINf_a, isINf_b ;
wire isZero_a, isZero_b;
wire  isNormalize_a, isNormalize_b ;
wire isUnormalize_a, isUnormalize_b;
torecFN encod_a(
	.fp          (fa						), 
	.sign        (sign_a				),
	.exp				 (exp_a				  ),
	.sig				 (sig_a				  ),
	.isNAN       (isNAN_a			  ),
	.isINf       (isINf_a			  ),
	.isZero      (isZero_a			),
	.isNormalize (isNormalize_a ),
	.isUnormalize(isUnormalize_a) 
);
torecFN encod_b(
	.fp          (fb						), 
	.sign        (sign_b				),
	.exp				 (exp_b				  ),
	.sig				 (sig_b				  ),
	.isNAN       (isNAN_b			  ),
	.isINf       (isINf_b			  ),
	.isZero      (isZero_b			),
	.isNormalize (isNormalize_b ),
	.isUnormalize(isUnormalize_b) 
);

//exp_cmp
wire [8:0] cmp_abs;
wire a_ge_b;
comparator cmp(
	.ina		(exp_a  ),
	.inb		(exp_b  ),
	.cmp_abs(cmp_abs),
	.ge			(a_ge_b )
);

//shifter_0
wire [XLEN-1:0] urshift_i, urshift_o;
assign urshift_i = a_ge_b ? sig_a : sig_b;
uRshifter shifter_0(
	.data_in (urshift_i		),
	.shamt	 (cmp_abs[5:0]),
	.data_out(urshift_o		)
);

//sig_adder
wire [XLEN-1:0] adda, addb;
wire [XLEN:0] fina, finb;
wire cin;
wire [XLEN:0] fsum;
wire cout;
assign adda = a_ge_b	? urshift_o :		 sig_a ;
assign addb = a_ge_b	? sig_b		  : urshift_o;
assign fina = {sign_a, sign_a ? ~adda+1 : adda};  
assign finb = is_sub ^ sign_b ? {1'b1, ~addb} : {1'b0, addb};  
assign cin  = is_sub ^ sign_b ? 1				      : 0				    ;
CLA adder(
	.a	 (fina),
	.b	 (finb),
	.cin (cin ),
	.sum (fsum),
	.cout(cout)
);
wire [XLEN-1:0] sig_result;
wire sign_res;
assign sig_result = fsum[XLEN] ? ~fsum[XLEN-1:0]+1 : fsum[XLEN-1:0];
assign sign_res   = fsum[XLEN];


//LZD shifter_1
wire [4:0] lshamt;
LZD_5 lead0det(
	.in(sig_result),
	.out(lshamt)
);
L_shifter shifter_1(
	.data_in (sig_result    ),
	.shamt	 ({1'b0, lshamt}),
	.data_out(sig_shift     )
);

//sexp_res
wire [8:0] sexp_res, _sexp_res;
assign _sexp_res = a_ge_b ? exp_b : exp_a; 
assign sexp_res  = _sexp_res - {3'b0, lshamt};

//
wire  isNAN_res;    
wire  isINf_res;
wire isZero_res;
wire  isNormalize_res;
wire isUnormalize_res;
assign isNAN_res  = (!isINf_res && !isZero_res && !isNormalize_res && !isUnormalize_res);
assign isINf_res  = sexp_res[8 -: 3] == 3'b110;
assign isZero_res = (sexp_res[8 -: 3] == 3'b000) && (sig_shift == 0);
assign isNormalize_res  = sexp_res >= 9'b1_0000_0000 && sexp_res <= 9'b1_0111_1111; 
assign isUnormalize_res = sexp_res >= 9'b0_0110_1011 && sexp_res <= 9'b1_0000_0010;
wire [8:0] Unormalize_n;
assign Unormalize_n = 9'b1_0000_0010 - sexp_res;
tosdtFN decod_res(
	.sign(sign_res),
	.exp(sexp_res),
	.sig(sig_shift),
	.isNAN(isNAN_res),
	.isINf(isINf_res),
	.isZero(isZero_res),
	.isNormalize(isNormalize_res),
	.isUnormalize(isUnormalize_res),
	.Unormalize_n(Unormalize_n),
	.fp(result)
);
	
endmodule
