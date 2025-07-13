`timescale 1ns / 1ps
module CLA (
	input  [32:0] a		,
	input	 [32:0] b	 	,
	input				  cin	,
	output [32:0] sum	,
	output			  cout
);

wire [32:0] g, p;
assign g = a & b;
assign p = a ^ b;

wire [33:0] c;
assign c[0] = cin;

localparam STAGE_NUM = clog2(33); 
wire [32:0] G [0:STAGE_NUM];
wire [32:0] P [0:STAGE_NUM];

assign G[0] = g;
assign P[0] = p;

Pretree #(1) p1(G[0], P[0], G[1], P[1]);
Pretree #(2) p2(G[1], P[1], G[2], P[2]);
Pretree #(3) p3(G[2], P[2], G[3], P[3]);
Pretree #(4) p4(G[3], P[3], G[4], P[4]);
Pretree #(5) p5(G[4], P[4], G[5], P[5]);
Pretree #(6) p5(G[5], P[5], G[6], P[6]);

genvar i;
generate
	for(i = 0; i < 33; i = i + 1) begin : carry
		assign c[i+1] = G[STAGE_NUM][i] | (P[STAGE_NUM][i] & cin);
	end
endgenerate

assign sum = p ^ c[32:0];
assign cout = c[33];

function integer clog2;
	input integer value;
	integer k;
	begin
		clog2 = 0;
		for(k = value - 1; k > 0; k = k >> 1)
			clog2 = clog2 + 1;
	end
endfunction

endmodule

