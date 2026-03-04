`timescale 1ns/1ps
module testbench;

reg [31:0] in;
/*verilator lint_off UNUSED*/
wire [4:0] out;

LZD_5 lzd(
	.in(in),
	.out(out)
);

initial begin
	#2 
	in = 32'h07fc_0100;
	#10 $finish;
end

endmodule
