module csa #(
    parameter DATA_WIDTH = 32
)(
    input  [DATA_WIDTH-1:0] a    ,
    input  [DATA_WIDTH-1:0] b    ,
    input  [DATA_WIDTH-1:0] c    ,
    output [DATA_WIDTH-1:0] sum  ,
    output [DATA_WIDTH-1:0] carry
);

assign sum = a ^ b ^ c;
assign carry = ((a & b) | (b & c) | (a & c)) << 1;

endmodule
