module comparator #(
	DATA_BITS = 9
)(
	input [DATA_BITS-1:0] ina,
	input [DATA_BITS-1:0] inb,
	output [DATA_BITS-1:0] cmp_abs,
	output ge 
);

wire [DATA_BITS-1:0]a_sub_b;
wire [DATA_BITS-1:0]b_sub_a;
assign a_sub_b = ina - inb;
assign b_sub_a = inb - ina;

assign ge = a >= b;
assign cmp_abs = ge ? a_sub_b : b_sub_a;

endmodule
