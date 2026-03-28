module mul #(
    parameter DATA_WIDTH = 54 
)(
//    input                     clk   ,
//    input                     rst   ,
    input  [  DATA_WIDTH-1:0] m     ,
    input  [  DATA_WIDTH-1:0] r     ,
    output [2*DATA_WIDTH-1:0] result
);

localparam PP_NUM = (DATA_WIDTH+1)/2;
localparam L0_NUM = PP_NUM;
localparam L1_NUM = L0_NUM / 3 * 2 + L0_NUM % 3;
localparam L2_NUM = L1_NUM / 3 * 2 + L1_NUM % 3;
localparam L3_NUM = L2_NUM / 3 * 2 + L2_NUM % 3;
localparam L4_NUM = L3_NUM / 3 * 2 + L3_NUM % 3;
localparam L5_NUM = L4_NUM / 3 * 2 + L4_NUM % 3;
localparam L6_NUM = L5_NUM / 3 * 2 + L5_NUM % 3;
localparam L7_NUM = L6_NUM / 3 * 2 + L6_NUM % 3;

//PPGEN
wire [2*DATA_WIDTH-1:0] pp [PP_NUM];
//wire [2*DATA_WIDTH-1:0] tail_pp;
wire [DATA_WIDTH:0] boothInx = {r, 1'b0};
wire [PP_NUM-1:0] is_neg;

/* verilator lint_off GENUNNAMED */
genvar i;
generate
    for(i=0; i<PP_NUM; i=i+1) begin : gen_pp 
        integer k = 2*i+1;

        wire [2*DATA_WIDTH-1:0] tmp_pp;
        wire [2:0] src = boothInx[k-1+:3];
        wire sel_x ;
        wire sel_2x;

        encBooth2 ENCB (src, sel_x, sel_2x, is_neg[i]);
        ppGen #(DATA_WIDTH) PPGEN (m, sel_x, sel_2x, is_neg[i], tmp_pp);
        /* verilator lint_off WIDTHEXPAND */
        if     (i == PP_NUM - 1) assign pp[i] = (tmp_pp+is_neg[i]) << (2 * i) | (is_neg[i-1] << ((i-1) * 2));
        else if(i == 0         ) assign pp[i] = (tmp_pp << (2 * i));
        else                     assign pp[i] = (tmp_pp << (2 * i)) | (is_neg[i-1] << ((i-1) * 2));
        /* verilator lint_on WIDTHEXPAND */
    end
endgenerate

//genvar j;
//generate
//    for(j=0; j < 2*DATA_WIDTH; j = j + 1) begin : gen_tail
//        if((j < 2 * PP_NUM) && (j % 2 == 0))
//            assign tail_pp[j] = is_neg[j/2];
//        else
//            assign tail_pp[j] = 1'b0;
//    end
//endgenerate

wire [2*DATA_WIDTH-1:0] stage0 [0:L0_NUM-1];
wire [2*DATA_WIDTH-1:0] stage1 [0:L1_NUM-1];
wire [2*DATA_WIDTH-1:0] stage2 [0:L2_NUM-1];
wire [2*DATA_WIDTH-1:0] stage3 [0:L3_NUM-1];
wire [2*DATA_WIDTH-1:0] stage4 [0:L4_NUM-1];
wire [2*DATA_WIDTH-1:0] stage5 [0:L5_NUM-1];
wire [2*DATA_WIDTH-1:0] stage6 [0:L6_NUM-1];
wire [2*DATA_WIDTH-1:0] stage7 [0:L7_NUM-1];

//levle 0
genvar l0;
generate
    for(l0=0;l0<L0_NUM;l0=l0+1) begin : NODE0
        assign stage0[l0] = pp[l0];
    end
endgenerate

//level 1
genvar l1;
generate
    for(l1=0; l1<L0_NUM/3; l1=l1+1) begin : NODE1
        csa #(2*DATA_WIDTH) CSA1 (stage0[3*l1], stage0[3*l1+1], stage0[3*l1+2], stage1[2*l1], stage1[2*l1+1]);
    end
endgenerate

generate
    if     (L0_NUM%3 == 1) 
        assign stage1[2*(L0_NUM/3)] = stage0[3*(L0_NUM/3)];
    else if(L0_NUM%3 == 2) begin
        assign stage1[2*(L0_NUM/3)  ] = stage0[3*(L0_NUM/3)  ];
        assign stage1[2*(L0_NUM/3)+1] = stage0[3*(L0_NUM/3)+1];
    end
endgenerate
            
//level 2
genvar l2;
generate
    for(l2=0; l2<L1_NUM/3; l2=l2+1) begin : NODE2
        csa #(2*DATA_WIDTH) CSA2 (stage1[3*l2], stage1[3*l2+1], stage1[3*l2+2], stage2[2*l2], stage2[2*l2+1]);
    end
endgenerate
            
generate
    if     (L1_NUM%3 == 1) 
        assign stage2[2*(L1_NUM/3)] = stage1[3*(L1_NUM/3)];
    else if(L1_NUM%3 == 2) begin
        assign stage2[2*(L1_NUM/3)  ] = stage1[3*(L1_NUM/3)  ];
        assign stage2[2*(L1_NUM/3)+1] = stage1[3*(L1_NUM/3)+1];
    end
endgenerate
            
//level 3
genvar l3;
generate
    for(l3=0; l3<L2_NUM/3; l3=l3+1) begin : NODE3
        csa #(2*DATA_WIDTH) CSA3 (stage2[3*l3], stage2[3*l3+1], stage2[3*l3+2], stage3[2*l3], stage3[2*l3+1]);
    end
endgenerate

generate
    if     (L2_NUM%3 == 1) 
        assign stage3[2*(L2_NUM/3)] = stage2[3*(L2_NUM/3)];
    else if(L2_NUM%3 == 2) begin
        assign stage3[2*(L2_NUM/3)  ] = stage2[3*(L2_NUM/3)  ];
        assign stage3[2*(L2_NUM/3)+1] = stage2[3*(L2_NUM/3)+1];
    end
endgenerate
            
//level 4
genvar l4;
generate
    for(l4=0; l4<L3_NUM/3; l4=l4+1) begin : NODE4
        csa #(2*DATA_WIDTH) CSA4 (stage3[3*l4], stage3[3*l4+1], stage3[3*l4+2], stage4[2*l4], stage4[2*l4+1]);
    end
endgenerate

generate
    if     (L3_NUM%3 == 1) 
        assign stage4[2*(L3_NUM/3)] = stage3[3*(L3_NUM/3)];
    else if(L3_NUM%3 == 2) begin
        assign stage4[2*(L3_NUM/3)  ] = stage3[3*(L3_NUM/3)  ];
        assign stage4[2*(L3_NUM/3)+1] = stage3[3*(L3_NUM/3)+1];
    end
endgenerate
            
//level 5
genvar l5;
generate
    for(l5=0; l5<L4_NUM/3; l5=l5+1) begin : NODE5
        csa #(2*DATA_WIDTH) CSA5 (stage4[3*l5], stage4[3*l5+1], stage4[3*l5+2], stage5[2*l5], stage5[2*l5+1]);
    end
endgenerate

generate
    if     (L4_NUM%3 == 1) 
        assign stage5[2*(L4_NUM/3)] = stage4[3*(L4_NUM/3)];
    else if(L4_NUM%3 == 2) begin
        assign stage5[2*(L4_NUM/3)  ] = stage4[3*(L4_NUM/3)  ];
        assign stage5[2*(L4_NUM/3)+1] = stage4[3*(L4_NUM/3)+1];
    end
endgenerate
            
//level 6
genvar l6;
generate
    for(l6=0; l6<L5_NUM/3; l6=l6+1) begin : NODE6
        csa #(2*DATA_WIDTH) CSA6 (stage5[3*l6], stage5[3*l6+1], stage5[3*l6+2], stage6[2*l6], stage6[2*l6+1]);
    end
endgenerate

generate
    if     (L5_NUM%3 == 1) 
        assign stage6[2*(L5_NUM/3)] = stage5[3*(L5_NUM/3)];
    else if(L5_NUM%3 == 2) begin
        assign stage6[2*(L5_NUM/3)  ] = stage5[3*(L5_NUM/3)  ];
        assign stage6[2*(L5_NUM/3)+1] = stage5[3*(L5_NUM/3)+1];
    end
endgenerate
            
/* verilator lint_on GENUNNAMED */
            
//level 7
csa #(2*DATA_WIDTH) CSA7 (
    .a    (stage6[0]), 
    .b    (stage6[1]), 
    .c    (stage6[2]), 
    .sum  (stage7[0]), 
    .carry(stage7[1])
);

//add
assign result = stage7[0] + stage7[1];

endmodule
