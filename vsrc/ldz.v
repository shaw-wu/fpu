module ldz #(
    parameter DATA_BITS = 32,
    parameter DATA_SIZE = 5 
)(
    input  [DATA_BITS-1:0] in ,
    output reg [DATA_SIZE  :0] out
);

    integer i;
    reg [DATA_SIZE-1:0] found_index;

    always @(*) begin
        out = DATA_BITS - 1; // default value（如果没有找到1）
        found_index = 0;
        // 从高位向低位扫描
        // 这里的逻辑是：找到最高位的 1，计算它左边有多少个 0
        for (i = 0; i < DATA_BITS; i = i + 1) begin
            if (in[i]) begin
                /*verilator lint_off WIDTHTRUNC*/
                found_index = (DATA_BITS - 1) - i;
                /*verilator lint_on WIDTHTRUNC*/
            end
        end
        out = {in == 0, found_index};
    end

endmodule
