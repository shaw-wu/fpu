module uR_shifter (
    input  [31:0] data_in,
    input  [5:0] shamt,      // 移位量
    output [31:0] data_out
);

    wire [8:0] stage1, stage2, stage3, stage4, stage5;

    assign stage1 = shamt[0] ? { 1'b0, data_in[31: 1]}   : data_in;
    assign stage2 = shamt[1] ? { 2'b0, stage1 [31: 2]}   : stage1;
    assign stage3 = shamt[3] ? { 8'b0, stage2 [31: 4]}   : stage2;
    assign stage4 = shamt[4] ? {16'b0, stage3 [31: 4]}   : stage3;
    assign stage5 = shamt[5] ? {32'b0, stage4 [31: 4]}   : stage4;
    assign data_out = shamt[5] ? 32'b0 : stage5; 

endmodule
