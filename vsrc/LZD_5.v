`timescale 1ns / 1ps
module LZD_5 (
	input  [31:0] in , 
	output [4 :0] out
);

wire [31:0] valid0 = in;

//level-1
wire [15:0] valid1;
wire [4:0] pos1 [15:0] ;

genvar i;
generate
	for(i = 0; i < 16; i = i + 1) begin
		assign valid1[i] = valid0[2*i] | valid0[2*i+1];
	  assign pos1[i]   = valid0[2*i+1] ? 2*i+1 : 2*i;
	end
endgenerate

//level-2
wire [7:0] valid2;
wire [4:0] pos2 [7:0];

genvar j;
generate
	for(j = 0; j < 8; j = j + 1) begin
		assign valid2[j] = valid1[2*j] | valid1[2*j+1];
	  assign pos2[j]   = valid1[2*j+1] ? pos1[2*j+1] : pos1[2*j];	
	end
endgenerate

//level-3
wire [3:0] valid3;
wire [4:0] pos3 [3:0];

genvar k;
generate
	for(k = 0; k < 4; k = k + 1) begin
		assign valid3[k] = valid2[2*k] | valid2[2*k+1];
	  assign pos3[k]   = valid2[2*k+1] ? pos2[2*k+1] : pos2[2*k];	
	end
endgenerate

//level-4
/* verilator lint_off UNUSED */
wire [1:0] valid4;
/* verilator lint_off UNUSED */
wire [4:0] pos4 [1:0];

genvar p;
generate
	for(p = 0; p < 2; p = p + 1) begin
		assign valid4[p] = valid3[2*p] | valid3[2*p+1];
	  assign pos4[p]   = valid3[2*p+1] ? pos3[2*p+1] : pos3[2*p];	
	end
endgenerate

//level-5
/* verilator lint_off UNUSED */
wire [4:0] pos;
/* verilator lint_off UNUSED */
assign pos = valid4[1] ? pos4[1] : pos4[0];	

assign out = 31 - pos;

endmodule
