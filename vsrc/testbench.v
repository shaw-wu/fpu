`timescale 1ns/1ps
module testbench;

reg [31:0] fp;
/* verilator lint_off UNUSED */
wire sign               ; 
wire [8:0]  exp				 ; 
wire [31:0] sig				 ; 
wire isNAN						   ; 
wire isINf       			 ; 
wire isZero      			 ; 
wire isNormalize 			 ; 
wire isUnormalize			 ;

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
	#2 
	fp = 32'b0_1111_1111_010_0000_0000_0000_0000_0000;
	#10 $finish;
end

endmodule
