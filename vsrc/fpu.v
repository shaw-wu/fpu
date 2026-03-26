module fpu #(
	parameter FDATA_BITS  = 32            ,
//	parameter DDATA_BITS  = 64            ,
	parameter FDATA_SIZE  = 5             ,
	parameter DATA_WIDTH  = 32            ,
	parameter FRA_BITS    = 23            ,
	parameter EXP_BITS    = 8             ,
	parameter SIG_BITS    = 32            ,
	parameter SIG_SIZE    = 5             ,
	parameter FRM_BITS    = 3             ,
    parameter EXP_OFFSET  = 9'b0_1000_0001
)(
	input clk,
	input rst,

    input                   i_valid,
    output                  i_ready,
	input  [           4:0] sel    ,
	input  [FRM_BITS  -1:0] frm    ,
	input  [FDATA_BITS-1:0] fina   ,
	input  [FDATA_BITS-1:0] finb   ,
	input  [DATA_WIDTH-1:0] ina    ,
	output		            o_valid,
	input                   o_ready,
	output [           4:0] fflags ,//mask
	output [FDATA_BITS-1:0] fresult
);

assign i_ready = s0_ready;
//localparam QNAN_S = 32'h7FC00000;
reg [5:0] cntTrans0_add; //pipeline transactions counter : highest priority 0 -- medium priority 1 -- lowest priority 2
reg [5:0] cntTrans0_mul; //pipeline transactions counter : highest priority 0 -- medium priority 1 -- lowest priority 2
reg [5:0] cntTrans1; //pipeline transactions counter : highest priority 0 -- medium priority 1 -- lowest priority 2
//reg [5:0] cntTrans2; //pipeline transactions counter : highest priority 0 -- medium priority 1 -- lowest priority 2
wire isTrans0 = isTrans0_add || isTrans0_mul;
wire isTrans0_add = pre_fadd_s || pre_fsub_s;
wire isTrans0_mul = pre_fmul_s;
wire isTrans1 = pre_fcvt_wu_s || pre_fcvt_w_s;
wire isTrans2 = !isTrans0 && !isTrans1;

wire haveTrans0 = haveTrans0_add || haveTrans0_mul;
wire haveTrans0_add = cntTrans0_add != 0;
wire haveTrans0_mul = cntTrans0_mul != 0;
wire haveTrans1 = cntTrans1 != 0;
//wire haveTrans2 = cntTrans2 != 0;

wire pre_fadd_s = sel == 'd0 ;
wire pre_fsub_s = sel == 'd1 ;
wire pre_fmul_s = sel == 'd2 ;
//wire pre_fdiv_s = sel == 'd3 ;
wire pre_fcvt_w_s  = sel == 'd10;
wire pre_fcvt_wu_s = sel == 'd11;

/*========  stage 0 ========*/
reg [FDATA_BITS-1:0] s0_fina;
reg [FDATA_BITS-1:0] s0_finb;
reg [DATA_WIDTH-1:0] s0_ina ;

reg [FRM_BITS  -1:0] s0_frm;
reg [           4:0] s0_sel;

wire s0_valid;
wire s0_ready;

localparam S0_IDLE     = 5'b00001;
localparam S0_WAIT2    = 5'b00010;
localparam S0_WAIT1    = 5'b00100;
localparam S0_WAIT_ADD = 5'b01000;
localparam S0_WAIT_MUL = 5'b10000;

reg [4:0] s0_current_state, s0_next_state;

always @(*) begin
	case(s0_current_state)
		S0_IDLE : begin
			if     (i_valid && isTrans2 && !haveTrans0 && !haveTrans1 ) s0_next_state = S0_WAIT2   ;
			else if(i_valid && isTrans2 && (haveTrans0 ||  haveTrans1)) s0_next_state = S0_IDLE    ;
			else if(i_valid && isTrans1                               ) s0_next_state = S0_WAIT1   ;
			else if(i_valid && isTrans0_add && !haveTrans0_mul        ) s0_next_state = S0_WAIT_ADD;
			else if(i_valid && isTrans0_mul && !haveTrans0_add        ) s0_next_state = S0_WAIT_MUL;
			else		                                                s0_next_state = S0_IDLE    ;
		end
		S0_WAIT2  : begin//don't need to wait trans1 or trans0
            if     (o_ready && isTrans2     &&  i_valid) s0_next_state = S0_WAIT2   ;
            else if(o_ready && isTrans1     &&  i_valid) s0_next_state = S0_WAIT1   ;
            else if(o_ready && isTrans0_add &&  i_valid) s0_next_state = S0_WAIT_ADD;
            else if(o_ready && isTrans0_mul &&  i_valid) s0_next_state = S0_WAIT_MUL;
            else if(o_ready                 && !i_valid) s0_next_state = S0_IDLE    ;
			else	                                     s0_next_state = S0_WAIT2   ;
		end
		S0_WAIT1 : begin
            if     (s1_ready && isTrans2     &&  i_valid) s0_next_state = S0_IDLE    ;
            else if(s1_ready && isTrans1     &&  i_valid) s0_next_state = S0_WAIT1   ;
            else if(s1_ready && isTrans0_add &&  i_valid) s0_next_state = S0_WAIT_ADD;
            else if(s1_ready && isTrans0_mul &&  i_valid) s0_next_state = S0_WAIT_MUL;
			else if(s1_ready                 && !i_valid) s0_next_state = S0_IDLE    ;
			else	                                      s0_next_state = S0_WAIT1   ;
		end
		S0_WAIT_ADD : begin
            if     (!s1_ready                             ) s0_next_state = S0_WAIT_ADD;
            else if(add_iready && isTrans2     &&  i_valid) s0_next_state = S0_IDLE    ;
            else if(add_iready && isTrans1     &&  i_valid) s0_next_state = S0_WAIT1   ;
            else if(add_iready && isTrans0_mul &&  i_valid) s0_next_state = S0_IDLE    ;
            else if(add_iready && isTrans0_add &&  i_valid) s0_next_state = S0_WAIT_ADD;
			else if(add_iready                 && !i_valid) s0_next_state = S0_IDLE    ;
			else	                                        s0_next_state = S0_WAIT_ADD;
		end
		S0_WAIT_MUL : begin
            if     (!s1_ready                             ) s0_next_state = S0_WAIT_MUL;
            else if(mul_iready && isTrans2     &&  i_valid) s0_next_state = S0_IDLE    ;
            else if(mul_iready && isTrans1     &&  i_valid) s0_next_state = S0_WAIT1   ;
            else if(mul_iready && isTrans0_add &&  i_valid) s0_next_state = S0_IDLE    ;
            else if(mul_iready && isTrans0_mul &&  i_valid) s0_next_state = S0_WAIT_MUL;
			else if(mul_iready                 && !i_valid) s0_next_state = S0_IDLE    ;
			else	                                        s0_next_state = S0_WAIT_MUL;
		end
        default : s0_next_state = S0_IDLE;
	endcase
end

always @(posedge clk or posedge rst) begin
	if(rst) begin
        s0_frm <= 0;
        s0_sel <= 0;

        s0_ina  <= 0;
        s0_fina <= 0;
        s0_finb <= 0;

		s0_current_state <= S0_IDLE;
	end else begin
		s0_current_state <= s0_next_state;
        if(i_valid && s0_ready) begin
            s0_frm <= frm;
            s0_sel <= sel;

            s0_ina  <= ina ;
            s0_fina <= fina;
            s0_finb <= finb;
        end 
        if((s0_current_state == S0_WAIT1) && s1_ready) begin

            if     (s4_valid && o_ready && haveTrans0_add) cntTrans0_add <= cntTrans0_add - 1;
            else if(s4_valid && o_ready && haveTrans0_mul) cntTrans0_mul <= cntTrans0_mul - 1;
            if     (s1_valid && o_ready && !haveTrans0   ) cntTrans1 <= cntTrans1    ;
            else                                           cntTrans1 <= cntTrans1 + 1;

        end else if((s0_current_state == S0_WAIT_ADD) && s1_ready && add_iready) begin
            
            if(s1_valid && o_ready && !haveTrans0) cntTrans1 <= cntTrans1 - 1;
            if(s4_valid && o_ready) cntTrans0_add <= cntTrans0_add    ;
            else                    cntTrans0_add <= cntTrans0_add + 1;

        end else if((s0_current_state == S0_WAIT_MUL) && s1_ready && mul_iready) begin
            
            if(s1_valid && o_ready && !haveTrans0) cntTrans1 <= cntTrans1 - 1;
            if(s4_valid && o_ready) cntTrans0_mul <= cntTrans0_mul    ;
            else                    cntTrans0_mul <= cntTrans0_mul + 1;

        end else begin
            
            if     (s4_valid && o_ready && haveTrans0_add) cntTrans0_add <= cntTrans0_add - 1;
            else if(s4_valid && o_ready && haveTrans0_mul) cntTrans0_mul <= cntTrans0_mul - 1;
            if(s1_valid && o_ready && !isTrans1) cntTrans1 <= cntTrans1 - 1;

        end
	end
end

assign s0_valid = ((s0_current_state == S0_WAIT_MUL) && s1_ready) || ((s0_current_state == S0_WAIT_ADD) && s1_ready) ||
                   (s0_current_state == S0_WAIT2) || (s0_current_state == S0_WAIT1); 
assign s0_ready = ( (s0_current_state == S0_IDLE    ) && ((isTrans2 && !haveTrans0 && !haveTrans1) || (isTrans0_add && !haveTrans0_mul) || (isTrans0_mul && !haveTrans0_add)) ) ||
                  ( (s0_current_state == S0_WAIT2   ) && o_ready                                                 ) || 
                  ( (s0_current_state == S0_WAIT1   ) && s1_ready   && !isTrans2                                 ) ||
                  ( (s0_current_state == S0_WAIT_ADD) && s1_ready   && add_iready && !isTrans2 && !isTrans0_mul  ) ||
                  ( (s0_current_state == S0_WAIT_MUL) && s1_ready   && mul_iready && !isTrans2 && !isTrans0_add  ); 

wire fadd_s = s0_sel == 'd0 ;
wire fsub_s = s0_sel == 'd1 ;
wire fmul_s = s0_sel == 'd2 ;
//wire fdiv_s = s0_sel == 'd3 ;
wire feq_s  = s0_sel == 'd4 ;
wire flt_s  = s0_sel == 'd5 ;
wire fle_s  = s0_sel == 'd6 ;
wire fsgnj_s   = s0_sel == 'd7 ;
wire fsgnjn_s  = s0_sel == 'd8 ;
wire fsgnjx_s  = s0_sel == 'd9 ;
wire fcvt_w_s  = s0_sel == 'd10;
wire fcvt_wu_s = s0_sel == 'd11;
wire fcvt_s_w  = s0_sel == 'd12;
wire fcvt_s_wu = s0_sel == 'd13;
wire fclass_s  = s0_sel == 'd14;
wire fmin_s    = s0_sel == 'd15;
wire fmax_s    = s0_sel == 'd16;

//torecFN
wire sign_a;
wire [EXP_BITS  :0] exp_a;//recFN exp
wire [SIG_BITS-1:0] sig_a;
wire isQNAN_a;
wire isSNAN_a;
wire isINf_a ;
wire isZero_a;
wire isUnormalize_a;
wire isNormalize_a ;

wire sign_b;
wire [EXP_BITS  :0] exp_b;//recFN exp
wire [SIG_BITS-1:0] sig_b;
wire isQNAN_b;
wire isSNAN_b;
wire isINf_b ;
wire isZero_b;

torecFN #(
    .FP_BITS    (FDATA_BITS ),
    .FP_LOG     (FDATA_SIZE ),
    .EXP_BITS   (EXP_BITS   ),
    .FRA_BITS   (FRA_BITS   ),
    .SIG_BITS   (SIG_BITS   ),
    .RECEXP_BITS(EXP_BITS+1 ),
    .EXP_OFFSET (EXP_OFFSET )
) torecFN_a (
	.fp          (s0_fina       ), 
	.sign        (sign_a        ),
	.exp		 (exp_a	        ),
	.sig		 (sig_a	        ),
	.isQNAN      (isQNAN_a      ),
	.isSNAN      (isSNAN_a      ),
	.isINf       (isINf_a       ),
	.isUnormalize(isUnormalize_a),
	.isNormalize (isNormalize_a ),
	.isZero      (isZero_a      )
);

torecFN #(
    .FP_BITS    (FDATA_BITS ),
    .FP_LOG     (FDATA_SIZE ),
    .EXP_BITS   (EXP_BITS   ),
    .FRA_BITS   (FRA_BITS   ),
    .SIG_BITS   (SIG_BITS   ),
    .RECEXP_BITS(EXP_BITS+1 ),
    .EXP_OFFSET (EXP_OFFSET )
) torecFN_b (
	.fp          (s0_finb       ), 
	.sign        (sign_b        ),
	.exp		 (exp_b	        ),
	.sig		 (sig_b	        ),
	.isQNAN      (isQNAN_b      ),
	.isSNAN      (isSNAN_b      ),
	.isINf       (isINf_b       ),
    /* verilator lint_off PINCONNECTEMPTY */
	.isUnormalize(              ),
	.isNormalize (              ),
    /* verilator lint_on PINCONNECTEMPTY */
	.isZero      (isZero_b      )
);

/*======== stage 1~3 ========*/
//fadd / sign
wire add_sub_sel = fsub_s;

wire add_ivalid = s0_valid && (fadd_s || fsub_s);
wire add_iready = add_iready_a && add_iready_b;
wire add_iready_a;
wire add_iready_b;

wire add_ovalid;
wire add_oready = s4_ready;                            

wire                add_res_sign        ;
wire [SIG_BITS-1:0] add_res_sig         ;
wire [EXP_BITS  :0] add_res_exp         ;
//wire                add_res_isNAN       ;
//wire                add_res_isINf       ;
wire [         4:0] add_res_fflags      ;

fadd #(
    .FRM_BITS(FRM_BITS  ),
    .FLA_BITS(5         ),
    .SIG_BITS(SIG_BITS  ),
    .SIG_SIZE(SIG_SIZE  ),
    .FRA_BITS(FRA_BITS+1),
    .EXP_BITS(EXP_BITS+1)
) FADD (
	.aclk			        (clk		   ),
    .areset                 (rst           ),
//    .busy                   (add_busy      ),
//add-sub sel
    .s_axis_sel             (add_sub_sel   ),
    .s_axis_frm             (s0_frm        ),
//fina
	.s_axis_a_tvalid        (add_ivalid    ),
	.s_axis_a_tready        (add_iready_a  ),

	.s_axis_a_sign          (sign_a        ),
	.s_axis_a_sig           (sig_a         ),
	.s_axis_a_exp           (exp_a         ),
	.s_axis_a_isQNAN        (isQNAN_a      ),
	.s_axis_a_isSNAN        (isSNAN_a      ),
	.s_axis_a_isINf         (isINf_a       ),
	.s_axis_a_isZero        (isZero_a      ),
//finb
	.s_axis_b_tvalid        (add_ivalid    ),
	.s_axis_b_tready        (add_iready_b  ),

	.s_axis_b_sign          (sign_b        ),
	.s_axis_b_sig           (sig_b         ),
	.s_axis_b_exp           (exp_b         ),
	.s_axis_b_isQNAN        (isQNAN_b      ),
	.s_axis_b_isSNAN        (isSNAN_b      ),
	.s_axis_b_isINf         (isINf_b       ),
	.s_axis_b_isZero        (isZero_b      ),
//fresult
	.m_axis_res_tvalid      (add_ovalid    ),
	.m_axis_res_tready      (add_oready    ),

	.m_axis_res_sign        (add_res_sign  ),
	.m_axis_res_sig         (add_res_sig   ),
	.m_axis_res_exp         (add_res_exp   ),
	//.m_axis_res_isQNAN      (add_res_isNAN       ),
	//.m_axis_res_isINf       (add_res_isINf       ),
	.m_axis_res_fflags      (add_res_fflags)
);

//fmul 
wire mul_ivalid = s0_valid && fmul_s;
wire mul_iready = mul_iready_a && mul_iready_b;
wire mul_iready_a;
wire mul_iready_b;

wire mul_ovalid;
wire mul_oready = s4_ready;

wire               mul_res_sign  ;
wire [FRA_BITS :0] mul_res_sig   ;
wire [EXP_BITS :0] mul_res_exp   ;
//wire               mul_res_isNAN ;
//wire               mul_res_isINf ;
wire [        4:0] mul_res_fflags;

fmul #(
    .DATA_WIDTH(FDATA_BITS),
    .FRM_BITS(FRM_BITS  ),
    .FLA_BITS(5         ),
    .SIG_BITS(FRA_BITS+1),
//    .SIG_SIZE(SIG_SIZE  ),
    .FRA_BITS(FRA_BITS+1),
    .EXP_BITS(EXP_BITS+1)
) FMUL (
	.aclk			        (clk		   ),
    .areset                 (rst           ),

    .s_axis_frm             (s0_frm        ),
//fina
	.s_axis_a_tvalid        (mul_ivalid    ),
	.s_axis_a_tready        (mul_iready_a  ),

	.s_axis_a_sign          (sign_a        ),
	.s_axis_a_sig           (sig_a[SIG_BITS-1-:FRA_BITS+1]),
	.s_axis_a_exp           (exp_a         ),
	.s_axis_a_isQNAN        (isQNAN_a      ),
	.s_axis_a_isSNAN        (isSNAN_a      ),
	.s_axis_a_isINf         (isINf_a       ),
	.s_axis_a_isZero        (isZero_a      ),
//finb
	.s_axis_b_tvalid        (mul_ivalid    ),
	.s_axis_b_tready        (mul_iready_b  ),

	.s_axis_b_sign          (sign_b        ),
	.s_axis_b_sig           (sig_b[SIG_BITS-1-:FRA_BITS+1]),
	.s_axis_b_exp           (exp_b         ),
	.s_axis_b_isQNAN        (isQNAN_b      ),
	.s_axis_b_isSNAN        (isSNAN_b      ),
	.s_axis_b_isINf         (isINf_b       ),
	.s_axis_b_isZero        (isZero_b      ),
//fresult
	.m_axis_res_tvalid      (mul_ovalid    ),
	.m_axis_res_tready      (mul_oready    ),

	.m_axis_res_sign        (mul_res_sign  ),
	.m_axis_res_sig         (mul_res_sig   ),
	.m_axis_res_exp         (mul_res_exp   ),
	.m_axis_res_fflags      (mul_res_fflags)
);
/*========  stage 1 ========*/
reg [2:0] s1_frm;

reg s1_sign_a;
reg [EXP_BITS  :0] s1_exp_a;//recFN exp
reg [SIG_BITS-1:0] s1_sig_a;
reg s1_isQNAN_a;
reg s1_isSNAN_a;
reg s1_isINf_a ;
//reg s1_isZero_a;
//reg s1_isUnormalize_a;
//reg s1_isNormalize_a ;

//reg s1_sign_b;
//reg [EXP_BITS  :0] s1_exp_b;//recFN exp
//reg [SIG_BITS-1:0] s1_sig_b;
//reg s1_isQNAN_b;
//reg s1_isSNAN_b;
//reg s1_isINf_b ;
//reg s1_isZero_b;

reg s1_fcvt_w_s ;
reg s1_fcvt_wu_s;

wire s1_valid;
wire s1_ready;

localparam S1_IDLE = 2'b01;
localparam S1_WAIT = 2'b10;

reg [1:0] s1_current_state, s1_next_state;

always @(*) begin
	case(s1_current_state)
		S1_IDLE : begin
			if  (s0_valid && (fcvt_wu_s || fcvt_w_s)) s1_next_state = S1_WAIT;
			else									  s1_next_state = S1_IDLE;
		end
		S1_WAIT : begin
			if     (s0_valid && o_ready && s1_valid && (fcvt_wu_s || fcvt_w_s)) s1_next_state = S1_WAIT;
			else if(o_ready  && s1_valid                                      ) s1_next_state = S1_IDLE;
			else	                                                            s1_next_state = S1_WAIT;
		end
        default : s1_next_state = S1_IDLE;
	endcase
end

always @(posedge clk or posedge rst) begin
	if(rst) begin
        s1_frm            <= 0;

        s1_sign_a         <= 0;
        s1_exp_a          <= 0;
        s1_sig_a          <= 0;
        s1_isQNAN_a       <= 0;
        s1_isSNAN_a       <= 0;
        s1_isINf_a        <= 0;
        //s1_isZero_a       <= 0;
        //s1_isUnormalize_a <= 0;
        //s1_isNormalize_a  <= 0;

        //s1_sign_b         <= 0;
        //s1_exp_b          <= 0;
        //s1_sig_b          <= 0;
        //s1_isQNAN_b       <= 0;
        //s1_isSNAN_b       <= 0;
        //s1_isINf_b        <= 0;
        //s1_isZero_b       <= 0;

        s1_fcvt_w_s  <= 0;
        s1_fcvt_wu_s <= 0;

		s1_current_state <= S1_IDLE;
	end else begin
		s1_current_state <= s1_next_state;
        if(s0_valid && s1_ready) begin
            s1_frm            <= s0_frm        ;

            s1_sign_a         <= sign_a        ;
            s1_exp_a          <= exp_a         ;
            s1_sig_a          <= sig_a         ;
            s1_isQNAN_a       <= isQNAN_a      ;
            s1_isSNAN_a       <= isSNAN_a      ;
            s1_isINf_a        <= isINf_a       ;
            //s1_isZero_a       <= isZero_a      ;
            //s1_isUnormalize_a <= isUnormalize_a;
            //s1_isNormalize_a  <= isNormalize_a ;
                                               
            //s1_sign_b         <= sign_b        ;
            //s1_exp_b          <= exp_b         ;
            //s1_sig_b          <= sig_b         ;
            //s1_isQNAN_b       <= isQNAN_b      ;
            //s1_isSNAN_b       <= isSNAN_b      ;
            //s1_isINf_b        <= isINf_b       ;
            //s1_isZero_b       <= isZero_b      ;

            s1_fcvt_w_s  <= fcvt_w_s ;
            s1_fcvt_wu_s <= fcvt_wu_s;
        end
	end
end

assign s1_valid = (s1_current_state == S1_WAIT) && !haveTrans0; 
assign s1_ready = (s1_current_state == S1_IDLE) || (s1_valid && o_ready); 

//fcvt_w_s and fcvt_wu_s
wire [DATA_WIDTH-1:0] fcss_fresult;
wire [DATA_WIDTH-1:0] fcsu_fresult;
wire cvt_fw_nv;
wire cvt_fw_nx;
cvt_fw #(
	.DATA_BITS(DATA_WIDTH),
	.SIG_BITS (SIG_BITS  ),
	.EXP_BITS (EXP_BITS+1)
) cvt_x_s(
	.u_i   (s1_fcvt_wu_s	          ),
	.sign  (s1_sign_a                 ),
	.exp   (s1_exp_a                  ),
	.sig   (s1_sig_a                  ),
	.frm   (s1_frm			          ),
	.isnan (s1_isQNAN_a || s1_isSNAN_a),
	.isinf (s1_isINf_a		          ),
	.w_res (fcss_fresult              ),
	.wu_res(fcsu_fresult              ),
	.nv	   (cvt_fw_nv	              ),
	.nx	   (cvt_fw_nx	              )
);
wire [4:0] fcvt_w_s_fflags = {cvt_fw_nv, 1'b0, 1'b0, 1'b0, cvt_fw_nx};

//================= stage 5 ============
reg                is_add_sub;
reg                s4_add_res_sign        ;
reg [SIG_BITS-1:0] s4_add_res_sig         ;
reg [EXP_BITS  :0] s4_add_res_exp         ;
reg [         4:0] s4_add_res_fflags      ;

reg                is_mul                 ;
reg                s4_mul_res_sign        ;
reg [SIG_BITS-1:0] s4_mul_res_sig         ;
reg [EXP_BITS  :0] s4_mul_res_exp         ;
reg [         4:0] s4_mul_res_fflags      ;

wire s4_valid;
wire s4_ready;

localparam S4_IDLE = 2'b01;
localparam S4_WAIT = 2'b10;

reg [1:0] s4_current_state, s4_next_state;

always @(*) begin
	case(s4_current_state)
		S4_IDLE : begin
			if  (add_ovalid||mul_ovalid) s4_next_state = S4_WAIT;
			else			 s4_next_state = S4_IDLE;
		end
		S4_WAIT : begin
			if     (o_ready && (add_ovalid || mul_ovalid)) s4_next_state = S4_WAIT;
			else if(o_ready              ) s4_next_state = S4_IDLE;
			else	                       s4_next_state = S4_WAIT;
		end
        default : s4_next_state = S4_IDLE;
	endcase
end

always @(posedge clk or posedge rst) begin
	if(rst) begin
        is_add_sub        <= 0;
        s4_add_res_sign   <= 0;
        s4_add_res_sig    <= 0;
        s4_add_res_exp    <= 0;
        s4_add_res_fflags <= 0;
	end else begin
		s4_current_state <= s4_next_state;
        if(add_ovalid && s4_ready) begin
            is_add_sub        <= 1;
            is_mul            <= 0;
            s4_add_res_sign   <= add_res_sign  ;
            s4_add_res_sig    <= add_res_sig   ;
            s4_add_res_exp    <= add_res_exp   ;
            s4_add_res_fflags <= add_res_fflags;
        end
        if(mul_ovalid && s4_ready) begin
            is_add_sub        <= 0;
            is_mul            <= 1;
            s4_mul_res_sign   <= mul_res_sign  ;
            s4_mul_res_sig    <= {mul_res_sig, {(SIG_BITS-FRA_BITS-1){1'b0}}};
            s4_mul_res_exp    <= mul_res_exp   ;
            s4_mul_res_fflags <= mul_res_fflags;
        end
	end
end

assign s4_valid = (s4_current_state == S4_WAIT); 
assign s4_ready = (s4_current_state == S4_IDLE) || (s4_valid && o_ready); 

//fadd/fsub result
wire                  sign_res  = is_add_sub ? s4_add_res_sign :
                                  is_mul     ? s4_mul_res_sign : 0;
wire [EXP_BITS    :0] exp_res   = is_add_sub ? s4_add_res_exp  :
                                  is_mul     ? s4_mul_res_exp  : 0;
wire [SIG_BITS  -1:0] sig_res   = is_add_sub ? s4_add_res_sig  :
                                  is_mul     ? s4_mul_res_sig  : 0;
//wire                  isNAN_res = add_res_isNAN;
//wire                  isINf_res = add_res_isINf;

//tostdFN
wire [FDATA_BITS-1:0] fpu_result;
tostdFN#(
    .FP_BITS    (FDATA_BITS ),
    .EXP_BITS   (EXP_BITS   ),
    .FRA_BITS   (FRA_BITS   ),
    .SIG_BITS   (SIG_BITS   ),
    .RECEXP_BITS(EXP_BITS+1 ),
    .EXP_OFFSET (EXP_OFFSET )
) tostdFN (
	.sign       (sign_res       ),
	.exp		(exp_res	    ),
	.sig		(sig_res	    ),
	//.isNAN      (isNAN_res      ),
	//.isINf      (isINf_res      ),
	.fp         (fpu_result     )
);

//fcvt_s_w and fcvt_s_wu
wire                  fcxs_sign   ;
wire [EXP_BITS  -1:0] fcxs_exp    ;
/* verilator lint_off UNUSED */
wire [FRA_BITS    :0] fcxs_sig    ;
/* verilator lint_on UNUSED */
wire [FDATA_BITS-1:0] fcxs_fresult;
wire cvt_wf_nx;
cvt_wf #(
	.DATA_BITS (DATA_WIDTH),
	.SIG_BITS  (FRA_BITS+1),
	.EXP_BITS  (EXP_BITS  )
) cvt_s_x(
	.u_i   (fcvt_s_wu),
	.xdata (s0_ina   ),
	.frm   (s0_frm   ),
	.sign  (fcxs_sign),
	.exp   (fcxs_exp ),
	.sig   (fcxs_sig ),
	.nx    (cvt_wf_nx)
);
assign fcxs_fresult = {fcxs_sign, fcxs_exp, fcxs_sig[FRA_BITS-1:0]};
wire [4:0] fcvt_s_w_fflags = {4'b0, cvt_wf_nx};

//fclass.s
wire [FDATA_BITS-1:0] fclass_fresult = isINf_a        &&  sign_a ? 0 :
                                       isNormalize_a  &&  sign_a ? 1 :
                                       isUnormalize_a &&  sign_a ? 2 :
                                       isZero_a       &&  sign_a ? 3 :
                                       isZero_a       && !sign_a ? 4 :
                                       isUnormalize_a &&  sign_a ? 5 :
                                       isNormalize_a  &&  sign_a ? 6 :
                                       isINf_a        && !sign_a ? 7 :
                                       isSNAN_a                  ? 8 :
                                       isQNAN_a                  ? 9 : 0;
//fclass_fresult == 0;

wire                st_sign_a = s0_fina[FDATA_BITS-1          ];
wire [EXP_BITS-1:0] st_exp_a  = s0_fina[FDATA_BITS-2-:EXP_BITS];
wire [FRA_BITS-1:0] st_fra_a  = s0_fina[FRA_BITS  -1 :0       ];
wire                st_sign_b = s0_finb[FDATA_BITS-1          ];
//feq
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] feq_fresult = (isSNAN_a || isSNAN_b || isQNAN_a || isQNAN_b) ? 0 : (s0_fina == s0_finb) || ((s0_fina[FDATA_BITS-2:0] == 0) && (s0_finb[FDATA_BITS-2:0] == 0)); 
/* verilator lint_on WIDTHEXPAND */
wire [4:0] feq_fflags = {isSNAN_a || isSNAN_b, 4'b0};                                               

//flt
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] flt_fresult = isSNAN_a || isSNAN_b || isQNAN_a || isQNAN_b                     ? 0                 :
                                    (s0_fina[FDATA_BITS-2:0] == 0) && (s0_finb[FDATA_BITS-2:0] == 0) ? 0                 :
                                    st_sign_a ^ st_sign_b                                            ? st_sign_a            :
                                    !st_sign_a                                                       ? s0_fina < s0_finb : s0_fina > s0_finb;
/* verilator lint_on WIDTHEXPAND */
wire [4:0] flt_fflags = {isSNAN_a || isSNAN_b, 4'b0};                                               

//fle
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] fle_fresult = isSNAN_a || isSNAN_b || isQNAN_a || isQNAN_b                     ? 0                  :
                                    (s0_fina[FDATA_BITS-2:0] == 0) && (s0_finb[FDATA_BITS-2:0] == 0) ? 1                  :
                                    st_sign_a ^ st_sign_b                                            ? st_sign_a          :
                                    !st_sign_a                                                       ? s0_fina <= s0_finb : s0_fina >= s0_finb;
/* verilator lint_on WIDTHEXPAND */
wire [4:0] fle_fflags = {isSNAN_a || isSNAN_b, 4'b0};

//fmin
wire [FDATA_BITS-1:0] fmin_fresult = flt_fresult[0] ? s0_fina : s0_finb;
wire [4:0] fmin_fflags = flt_fflags;

//fmax
wire [FDATA_BITS-1:0] fmax_fresult = flt_fresult[0] ? s0_finb : s0_fina;
wire [4:0] fmax_fflags = flt_fflags;

//fsgnj
wire [FDATA_BITS-1:0] fsgnj_fresult = {st_sign_b, st_exp_a, st_fra_a}; //fsgnj_fflags = 0;

//fsgnjn
wire [FDATA_BITS-1:0] fsgnjn_fresult = {!st_sign_b, st_exp_a, st_fra_a}; //fsgnjn_fflags = 0;

//fsgnjx
wire [FDATA_BITS-1:0] fsgnjx_fresult = {st_sign_a ^ st_sign_b, st_exp_a, st_fra_a}; //fsgnjx_fflags = 0;

wire fadd_s_valid = s4_valid && is_add_sub;
wire fsub_s_valid = s4_valid && is_add_sub;
wire fmul_s_valid = s4_valid && is_mul;
wire fcvt_wu_s_valid = s1_valid && s1_fcvt_wu_s;
wire fcvt_w_s_valid  = s1_valid && s1_fcvt_w_s ;
//wire net_op = s0_ready;

//fresult
assign fresult = fadd_s_valid || fsub_s_valid || fmul_s_valid ? fpu_result     :
                 feq_s                                        ? feq_fresult    :
                 flt_s                                        ? flt_fresult    :
                 fle_s                                        ? fle_fresult    : 
                 fsgnj_s                                      ? fsgnj_fresult  : 
                 fsgnjx_s                                     ? fsgnjx_fresult : 
                 fsgnjn_s                                     ? fsgnjn_fresult : 
                 fcvt_w_s_valid                               ? fcss_fresult   :
                 fcvt_wu_s_valid                              ? fcsu_fresult   :
                 fcvt_s_w                                     ? fcxs_fresult   :
                 fcvt_s_wu                                    ? fcxs_fresult   :
                 fclass_s                                     ? fclass_fresult : 
                 fmin_s                                       ? fmin_fresult   :
                 fmax_s                                       ? fmax_fresult   : 0;

assign fflags = fadd_s_valid || fsub_s_valid                ? s4_add_res_fflags :
                fmul_s_valid                                ? s4_mul_res_fflags :
                fsgnj_s || fsgnjn_s || fsgnjx_s || fclass_s ? 5'b0              :
                feq_s                                       ? feq_fflags        :
                flt_s                                       ? flt_fflags        :
                fle_s                                       ? fle_fflags        : 
                fcvt_w_s_valid || fcvt_wu_s_valid           ? fcvt_w_s_fflags   :
                fcvt_s_w || fcvt_s_wu                       ? fcvt_s_w_fflags   :
                fmin_s                                      ? fmin_fflags       :
                fmax_s                                      ? fmax_fflags       : 5'b0;

assign o_valid = (s0_current_state == S0_WAIT2) || s1_valid || s4_valid;

endmodule
