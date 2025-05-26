`timescale 1ns/1ps
module testbench;

reg [31:0] a;
reg [31:0] b;
reg cin;
/*verilator lint_off UNUSED*/
wire cout;
wire [31:0] sum;

CLA c0(
	.a(a),
	.b(b),
	.cin(cin),
	.sum(sum),
	.cout(cout)
);

initial begin
	#2 
	a = 32'd82367;
	b = 32'd8784;
	cin = 0;
	#50 $finish;
end

endmodule
