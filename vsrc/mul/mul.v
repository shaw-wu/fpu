module mul #(
    parameter DATA_WIDTH = 54,
    parameter FRM_BITS   = 3 ,
    parameter EXP_BITS   = 12
)(
    input                     clk            ,
    input                     rst            ,
    input                     i_valid        ,
    output                    i_ready        ,

    input  [  FRM_BITS  -1:0] i_frm          ,
    input                     i_sign_a       ,
    input                     i_sign_b       ,
    input  [  EXP_BITS  -1:0] i_compl_add_exp,
    input                     i_neg_overflow ,
    input                     i_pos_overflow ,
    input                     i_isQNAN_a     ,
    input                     i_isSNAN_a     ,
    input                     i_isINf_a      ,
    input                     i_isZero_a     ,
    input                     i_isQNAN_b     ,
    input                     i_isSNAN_b     ,
    input                     i_isINf_b      ,
    input                     i_isZero_b     ,

    input  [  DATA_WIDTH-1:0] m              ,
    input  [  DATA_WIDTH-1:0] r              ,
    output                    o_valid        ,
    input                     o_ready        ,
    output [  FRM_BITS  -1:0] o_frm          ,
    output                    o_sign_a       ,
    output                    o_sign_b       ,
    output [  EXP_BITS  -1:0] o_compl_add_exp,
    output                    o_neg_overflow ,
    output                    o_pos_overflow ,
    output                    o_isQNAN_a     ,
    output                    o_isSNAN_a     ,
    output                    o_isINf_a      ,
    output                    o_isZero_a     ,
    output                    o_isQNAN_b     ,
    output                    o_isSNAN_b     ,
    output                    o_isINf_b      ,
    output                    o_isZero_b     ,
    output [2*DATA_WIDTH-1:0] result
);
assign i_ready = s3_ready;
assign o_valid = s6_valid;

localparam PP_NUM = (DATA_WIDTH+1)/2;
localparam L0_NUM = PP_NUM;
localparam L1_NUM = L0_NUM / 3 * 2 + L0_NUM % 3;
localparam L2_NUM = L1_NUM / 3 * 2 + L1_NUM % 3;
localparam L3_NUM = L2_NUM / 3 * 2 + L2_NUM % 3;
localparam L4_NUM = L3_NUM / 3 * 2 + L3_NUM % 3;
localparam L5_NUM = L4_NUM / 3 * 2 + L4_NUM % 3;
localparam L6_NUM = L5_NUM / 3 * 2 + L5_NUM % 3;
localparam L7_NUM = L6_NUM / 3 * 2 + L6_NUM % 3;

/*======== stage 3 ========*/
reg [FRM_BITS  -1:0] s3_frm          ;
reg                  s3_sign_a       ;
reg                  s3_sign_b       ;
reg [EXP_BITS  -1:0] s3_compl_add_exp;
reg                  s3_neg_overflow ;
reg                  s3_pos_overflow ;
reg                  s3_isQNAN_a;
reg                  s3_isSNAN_a;
reg                  s3_isINf_a ;
reg                  s3_isZero_a;
reg                  s3_isQNAN_b;
reg                  s3_isSNAN_b;
reg                  s3_isINf_b ;
reg                  s3_isZero_b;

reg [DATA_WIDTH-1:0] s3_m;
reg [DATA_WIDTH-1:0] s3_r;

localparam S3_IDLE = 2'b01; 
localparam S3_WAIT = 2'b10; 

reg [1:0] s3_current_state, s3_next_state;

always@(*) begin
    case(s3_current_state)
        S3_IDLE : begin
            if(i_valid) s3_next_state = S3_WAIT;
            else        s3_next_state = S3_IDLE;
        end
        S3_WAIT : begin
            if     (s4_ready && i_valid) s3_next_state = S3_WAIT;
            else if(s4_ready           ) s3_next_state = S3_IDLE;
            else                         s3_next_state = S3_WAIT;
        end
        default : s3_next_state = S3_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s3_current_state <= S3_IDLE;
        s3_frm           <= 0;
        s3_sign_a        <= 0;
        s3_sign_b        <= 0;
        s3_compl_add_exp <= 0;
        s3_neg_overflow  <= 0;
        s3_pos_overflow  <= 0;
        s3_isQNAN_a      <= 0;
        s3_isSNAN_a      <= 0;
        s3_isINf_a       <= 0;
        s3_isZero_a      <= 0;
        s3_isQNAN_b      <= 0;
        s3_isSNAN_b      <= 0;
        s3_isINf_b       <= 0;
        s3_isZero_b      <= 0;
        s3_m <= 0;
        s3_r <= 0;
    end else begin
        s3_current_state <= s3_next_state;
        if(i_valid && s3_ready) begin
            s3_frm           <= i_frm          ;
            s3_sign_a        <= i_sign_a       ;
            s3_sign_b        <= i_sign_b       ;
            s3_compl_add_exp <= i_compl_add_exp;
            s3_neg_overflow  <= i_neg_overflow ;
            s3_pos_overflow  <= i_pos_overflow ;
            s3_isQNAN_a      <= i_isQNAN_a     ;
            s3_isSNAN_a      <= i_isSNAN_a     ;
            s3_isINf_a       <= i_isINf_a      ;
            s3_isZero_a      <= i_isZero_a     ;
            s3_isQNAN_b      <= i_isQNAN_b     ;
            s3_isSNAN_b      <= i_isSNAN_b     ;
            s3_isINf_b       <= i_isINf_b      ;
            s3_isZero_b      <= i_isZero_b     ;
            s3_m <= m;
            s3_r <= r;
        end
    end
end

wire s3_valid = (s3_current_state == S3_WAIT);
wire s3_ready = (s3_current_state == S3_IDLE) || (s3_valid && s4_ready);

//PPGEN
wire [2*DATA_WIDTH-1:0] pp [0:PP_NUM-1];
//wire [2*DATA_WIDTH-1:0] tail_pp;
wire [DATA_WIDTH:0] boothInx = {s3_r, 1'b0};
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
        ppGen #(DATA_WIDTH) PPGEN (s3_m, sel_x, sel_2x, is_neg[i], tmp_pp);
        /* verilator lint_off WIDTHEXPAND */
        if     (i == PP_NUM - 1) assign pp[i] = (tmp_pp+is_neg[i]) << (2 * i) | (is_neg[i-1] << ((i-1) * 2));
        else if(i == 0         ) assign pp[i] = (tmp_pp << (2 * i));
        else                     assign pp[i] = (tmp_pp << (2 * i)) | (is_neg[i-1] << ((i-1) * 2));
        /* verilator lint_on WIDTHEXPAND */
    end
endgenerate

wire [2*DATA_WIDTH-1:0] stage0 [0:L0_NUM-1];
//levle 0
genvar l0;
generate
    for(l0=0;l0<L0_NUM;l0=l0+1) begin : NODE0
        assign stage0[l0] = pp[l0];
    end
endgenerate

/*======== stage 4 ========*/
reg [FRM_BITS  -1:0] s4_frm          ;
reg                  s4_sign_a       ;
reg                  s4_sign_b       ;
reg [EXP_BITS  -1:0] s4_compl_add_exp;
reg                  s4_neg_overflow ;
reg                  s4_pos_overflow ;
reg                  s4_isQNAN_a;
reg                  s4_isSNAN_a;
reg                  s4_isINf_a ;
reg                  s4_isZero_a;
reg                  s4_isQNAN_b;
reg                  s4_isSNAN_b;
reg                  s4_isINf_b ;
reg                  s4_isZero_b;

reg [2*DATA_WIDTH-1:0] s4_stage0 [0:L0_NUM-1];

localparam S4_IDLE = 2'b01; 
localparam S4_WAIT = 2'b10; 

reg [1:0] s4_current_state, s4_next_state;

always@(*) begin
    case(s4_current_state)
        S4_IDLE : begin
            if(s3_valid) s4_next_state = S4_WAIT;
            else         s4_next_state = S4_IDLE;
        end
        S4_WAIT : begin
            if     (s5_ready && s3_valid) s4_next_state = S4_WAIT;
            else if(s5_ready            ) s4_next_state = S4_IDLE;
            else                          s4_next_state = S4_WAIT;
        end
        default : s4_next_state = S4_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s4_current_state <= S4_IDLE;
        s4_frm           <= 0;
        s4_sign_a        <= 0;
        s4_sign_b        <= 0;
        s4_compl_add_exp <= 0;
        s4_neg_overflow  <= 0;
        s4_pos_overflow  <= 0;
        s4_isQNAN_a      <= 0;
        s4_isSNAN_a      <= 0;
        s4_isINf_a       <= 0;
        s4_isZero_a      <= 0;
        s4_isQNAN_b      <= 0;
        s4_isSNAN_b      <= 0;
        s4_isINf_b       <= 0;
        s4_isZero_b      <= 0;
    end else begin
        s4_current_state <= s4_next_state;
        if(s3_valid && s4_ready) begin
            s4_frm           <= s3_frm          ;
            s4_sign_a        <= s3_sign_a       ;
            s4_sign_b        <= s3_sign_b       ;
            s4_compl_add_exp <= s3_compl_add_exp;
            s4_neg_overflow  <= s3_neg_overflow ;
            s4_pos_overflow  <= s3_pos_overflow ;
            s4_isQNAN_a      <= s3_isQNAN_a;
            s4_isSNAN_a      <= s3_isSNAN_a;
            s4_isINf_a       <= s3_isINf_a ;
            s4_isZero_a      <= s3_isZero_a;
            s4_isQNAN_b      <= s3_isQNAN_b;
            s4_isSNAN_b      <= s3_isSNAN_b;
            s4_isINf_b       <= s3_isINf_b ;
            s4_isZero_b      <= s3_isZero_b;
        end
    end
end

genvar p;
generate
    for(p = 0; p < L0_NUM; p = p + 1) begin : s4_regdata 
        always@(posedge clk, posedge rst) begin
            if     (rst                 ) s4_stage0[p] <= 0        ;
            else if(s3_valid && s4_ready) s4_stage0[p] <= stage0[p];
        end
    end
endgenerate

wire s4_valid = (s4_current_state == S4_WAIT);
wire s4_ready = (s4_current_state == S4_IDLE) || (s4_valid && s5_ready);

wire [2*DATA_WIDTH-1:0] stage1 [0:L1_NUM-1];
wire [2*DATA_WIDTH-1:0] stage2 [0:L2_NUM-1];
wire [2*DATA_WIDTH-1:0] stage3 [0:L3_NUM-1];
//level 1
genvar l1;
generate
    for(l1=0; l1<L0_NUM/3; l1=l1+1) begin : NODE1
        csa #(2*DATA_WIDTH) CSA1 (s4_stage0[3*l1], s4_stage0[3*l1+1], s4_stage0[3*l1+2], stage1[2*l1], stage1[2*l1+1]);
    end
endgenerate

generate
    if     (L0_NUM%3 == 1) 
        assign stage1[2*(L0_NUM/3)] = s4_stage0[3*(L0_NUM/3)];
    else if(L0_NUM%3 == 2) begin
        assign stage1[2*(L0_NUM/3)  ] = s4_stage0[3*(L0_NUM/3)  ];
        assign stage1[2*(L0_NUM/3)+1] = s4_stage0[3*(L0_NUM/3)+1];
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


/*======== stage 5 ========*/
reg [FRM_BITS  -1:0] s5_frm          ;
reg                  s5_sign_a       ;
reg                  s5_sign_b       ;
reg [EXP_BITS  -1:0] s5_compl_add_exp;
reg                  s5_neg_overflow ;
reg                  s5_pos_overflow ;
reg                  s5_isQNAN_a;
reg                  s5_isSNAN_a;
reg                  s5_isINf_a ;
reg                  s5_isZero_a;
reg                  s5_isQNAN_b;
reg                  s5_isSNAN_b;
reg                  s5_isINf_b ;
reg                  s5_isZero_b;

reg [2*DATA_WIDTH-1:0] s5_stage3 [0:L3_NUM-1];

localparam S5_IDLE = 2'b01; 
localparam S5_WAIT = 2'b10; 

reg [1:0] s5_current_state, s5_next_state;

always@(*) begin
    case(s5_current_state)
        S5_IDLE : begin
            if(s4_valid) s5_next_state = S5_WAIT;
            else         s5_next_state = S5_IDLE;
        end
        S5_WAIT : begin
            if     (s6_ready && s4_valid) s5_next_state = S5_WAIT;
            else if(s6_ready            ) s5_next_state = S5_IDLE;
            else                          s5_next_state = S5_WAIT;
        end
        default : s5_next_state = S5_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s5_current_state <= S5_IDLE;
        s5_frm           <= 0;
        s5_sign_a        <= 0;
        s5_sign_b        <= 0;
        s5_compl_add_exp <= 0;
        s5_neg_overflow  <= 0;
        s5_pos_overflow  <= 0;
        s5_isQNAN_a      <= 0;
        s5_isSNAN_a      <= 0;
        s5_isINf_a       <= 0;
        s5_isZero_a      <= 0;
        s5_isQNAN_b      <= 0;
        s5_isSNAN_b      <= 0;
        s5_isINf_b       <= 0;
        s5_isZero_b      <= 0;
    end else begin
        s5_current_state <= s5_next_state;
        if(s4_valid && s5_ready) begin
            s5_frm           <= s4_frm          ;
            s5_sign_a        <= s4_sign_a       ;
            s5_sign_b        <= s4_sign_b       ;
            s5_compl_add_exp <= s4_compl_add_exp;
            s5_neg_overflow  <= s4_neg_overflow ;
            s5_pos_overflow  <= s4_pos_overflow ;
            s5_isQNAN_a      <= s4_isQNAN_a;
            s5_isSNAN_a      <= s4_isSNAN_a;
            s5_isINf_a       <= s4_isINf_a ;
            s5_isZero_a      <= s4_isZero_a;
            s5_isQNAN_b      <= s4_isQNAN_b;
            s5_isSNAN_b      <= s4_isSNAN_b;
            s5_isINf_b       <= s4_isINf_b ;
            s5_isZero_b      <= s4_isZero_b;
        end
    end
end

genvar n;
generate
    for(n = 0; n < L3_NUM; n = n + 1) begin : s5_regdata 
        always@(posedge clk, posedge rst) begin
            if     (rst                 ) s5_stage3[n] <= 0        ;
            else if(s4_valid && s5_ready) s5_stage3[n] <= stage3[n];
        end
    end
endgenerate

wire s5_valid = (s5_current_state == S5_WAIT);
wire s5_ready = (s5_current_state == S5_IDLE) || (s5_valid && s6_ready);

wire [2*DATA_WIDTH-1:0] stage4 [0:L4_NUM-1];
wire [2*DATA_WIDTH-1:0] stage5 [0:L5_NUM-1];
wire [2*DATA_WIDTH-1:0] stage6 [0:L6_NUM-1];
wire [2*DATA_WIDTH-1:0] stage7 [0:L7_NUM-1];
            
//level 4
genvar l4;
generate
    for(l4=0; l4<L3_NUM/3; l4=l4+1) begin : NODE4
        csa #(2*DATA_WIDTH) CSA4 (s5_stage3[3*l4], s5_stage3[3*l4+1], s5_stage3[3*l4+2], stage4[2*l4], stage4[2*l4+1]);
    end
endgenerate

generate
    if     (L3_NUM%3 == 1) 
        assign stage4[2*(L3_NUM/3)] = s5_stage3[3*(L3_NUM/3)];
    else if(L3_NUM%3 == 2) begin
        assign stage4[2*(L3_NUM/3)  ] = s5_stage3[3*(L3_NUM/3)  ];
        assign stage4[2*(L3_NUM/3)+1] = s5_stage3[3*(L3_NUM/3)+1];
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
/*======== stage 6 ========*/
reg [FRM_BITS  -1:0] s6_frm          ;
reg                  s6_sign_a       ;
reg                  s6_sign_b       ;
reg [EXP_BITS  -1:0] s6_compl_add_exp;
reg                  s6_neg_overflow ;
reg                  s6_pos_overflow ;
reg                  s6_isQNAN_a;
reg                  s6_isSNAN_a;
reg                  s6_isINf_a ;
reg                  s6_isZero_a;
reg                  s6_isQNAN_b;
reg                  s6_isSNAN_b;
reg                  s6_isINf_b ;
reg                  s6_isZero_b;

reg [2*DATA_WIDTH-1:0] s6_stage7 [0:L7_NUM-1];

localparam S6_IDLE = 2'b01; 
localparam S6_WAIT = 2'b10; 

reg [1:0] s6_current_state, s6_next_state;

always@(*) begin
    case(s6_current_state)
        S6_IDLE : begin
            if(s5_valid) s6_next_state = S6_WAIT;
            else         s6_next_state = S6_IDLE;
        end
        S6_WAIT : begin
            if     (o_ready && s5_valid) s6_next_state = S6_WAIT;
            else if(o_ready            ) s6_next_state = S6_IDLE;
            else                         s6_next_state = S6_WAIT;
        end
        default : s6_next_state = S6_IDLE;
    endcase
end

always@(posedge clk, posedge rst) begin
    if(rst) begin
        s6_current_state <= S6_IDLE;
        s6_frm           <= 0;
        s6_sign_a        <= 0;
        s6_sign_b        <= 0;
        s6_compl_add_exp <= 0;
        s6_neg_overflow  <= 0;
        s6_pos_overflow  <= 0;
        s6_isQNAN_a      <= 0;
        s6_isSNAN_a      <= 0;
        s6_isINf_a       <= 0;
        s6_isZero_a      <= 0;
        s6_isQNAN_b      <= 0;
        s6_isSNAN_b      <= 0;
        s6_isINf_b       <= 0;
        s6_isZero_b      <= 0;
    end else begin
        s6_current_state <= s6_next_state;
        if(s5_valid && s5_ready) begin
            s6_frm           <= s5_frm          ;
            s6_sign_a        <= s5_sign_a       ;
            s6_sign_b        <= s5_sign_b       ;
            s6_compl_add_exp <= s5_compl_add_exp;
            s6_neg_overflow  <= s5_neg_overflow ;
            s6_pos_overflow  <= s5_pos_overflow ;
            s6_isQNAN_a      <= s5_isQNAN_a;
            s6_isSNAN_a      <= s5_isSNAN_a;
            s6_isINf_a       <= s5_isINf_a ;
            s6_isZero_a      <= s5_isZero_a;
            s6_isQNAN_b      <= s5_isQNAN_b;
            s6_isSNAN_b      <= s5_isSNAN_b;
            s6_isINf_b       <= s5_isINf_b ;
            s6_isZero_b      <= s5_isZero_b;
        end
    end
end

genvar q;
generate
    for(q = 0; q < L7_NUM; q = q + 1) begin : s6_regdata 
        always@(posedge clk, posedge rst) begin
            if     (rst                 ) s6_stage7[q] <= 0        ;
            else if(s5_valid && s6_ready) s6_stage7[q] <= stage7[q];
        end
    end
endgenerate

wire s6_valid = (s6_current_state == S6_WAIT);
wire s6_ready = (s6_current_state == S6_IDLE) || (s6_valid && o_ready);

//add
assign result = s6_stage7[0] + s6_stage7[1];
assign o_frm           = s6_frm          ;
assign o_sign_a        = s6_sign_a       ;
assign o_sign_b        = s6_sign_b       ;
assign o_compl_add_exp = s6_compl_add_exp;
assign o_neg_overflow  = s6_neg_overflow ;
assign o_pos_overflow  = s6_pos_overflow ;
assign o_isQNAN_a      = s6_isQNAN_a;
assign o_isSNAN_a      = s6_isSNAN_a;
assign o_isINf_a       = s6_isINf_a ;
assign o_isZero_a      = s6_isZero_a;
assign o_isQNAN_b      = s6_isQNAN_b;
assign o_isSNAN_b      = s6_isSNAN_b;
assign o_isINf_b       = s6_isINf_b ;
assign o_isZero_b      = s6_isZero_b;

endmodule
