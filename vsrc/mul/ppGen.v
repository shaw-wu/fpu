module ppGen #(
     parameter DATA_WIDTH = 32
)(
    input  [  DATA_WIDTH-1:0] x     ,
    input                     sel_x ,
    input                     sel_2x,
    input                     is_neg,
    output [2*DATA_WIDTH-1:0] pp
);

//no sign extend
wire [2*DATA_WIDTH-1:0] raw_pp;
wire [DATA_WIDTH:0] x_ext = {x[DATA_WIDTH-1], x};

assign raw_pp = sel_x  ? {{(DATA_WIDTH-1){x_ext[DATA_WIDTH]}}, x_ext}                :
                sel_2x ? {{(DATA_WIDTH-1){x_ext[DATA_WIDTH]}}, x_ext << 1} : 0;
assign pp = is_neg ? ~raw_pp : raw_pp; 

endmodule
