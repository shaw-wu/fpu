`timescale 1ns/1ps
module testbench;

reg [31:0] fp;
/* verilator lint_off UNUSED */
wire sign              ; 
wire [8:0]  exp				 ; 
wire [23:0] sig				 ; 
wire isNAN						 ; 
wire isINf       			 ; 
wire isZero      			 ; 
wire isNormalize 			 ; 
wire isUnormalize			 ;
/* verilator lint_off UNUSED */

torecFN l1 (
	.fp          (fp          ), 
	.sign        (sign        ),
	.exp				 (exp				 ),
	.sig				 (sig				 ),
	.isNAN       (isNAN       ),
	.isINf       (isINf       ),
	.isZero      (isZero      ),
	.isNormalize (isNormalize ),
	.isUnormalize(isUnormalize)
);

initial begin
	#2 fp = 32'b1_1111_1111_000_0000_0000_0000_0000_0000;
	#50 $finish;
end

endmodule
