module encBooth2 (
    input  [2:0] src   ,
    output       sel_x ,
    output       sel_2x,
    output       is_neg
);
 
assign sel_x  = (src == 3'b001) || (src == 3'b010) || 
                 (src == 3'b101) || (src == 3'b110);
assign sel_2x = (src == 3'b011) || (src == 3'b100);
assign is_neg = (src == 3'b100) || (src == 3'b101) || (src == 3'b110);

endmodule
