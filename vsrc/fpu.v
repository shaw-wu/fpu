module fpu #(
	parameter FDATA_WIDTH = 32            ,
	parameter FDATA_SIZE  = 5             ,
	parameter DATA_WIDTH  = 32            ,
	parameter FRA_BITS    = 52            ,
	parameter EXP_BITS    = 11            ,
	parameter SIG_BITS    = 32            ,
	parameter BIAS        = 1023          ,
    parameter EXP_OFFSET  = 9'b1_0000_0001
)(
	input clk,
	input rst,

    input                    i_valid,
    output                   i_ready,
	input  [            3:0] sel    ,
	input  [            2:0] frm    ,
	input  [FDATA_WIDTH-1:0] fina   ,
	input  [FDATA_WIDTH-1:0] finb   ,
//	input [ DATA_WIDTH-1:0]  ina,
	output		             o_valid,
	input                    o_ready,
	output [            4:0] fflags ,
	output [FDATA_WIDTH-1:0] fresult
);


wire fadd_s = sel == 'd0 ;
wire fsub_s = sel == 'd1 ;
wire fmul_s = sel == 'd2 ;
wire fdiv_s = sel == 'd3 ;
wire feq_s  = sel == 'd4 ;
wire flt_s  = sel == 'd5 ;
wire fle_s  = sel == 'd6 ;
wire fsgnj_s   = sel == 'd7 ;
wire fcvt_w_s  = sel == 'd8 ;
wire fcvt_wu_s = sel == 'd8 ;
wire fcvt_s_w  = sel == 'd9 ;
wire fcvt_s_wu = sel == 'd10;

parameter IDLE		   = 3'b000;
parameter WAIT_READY   = 3'b100;
parameter WAIT_A_READY = 3'b101;
parameter WAIT_B_READY = 3'b110;
parameter WORK         = 3'b011;

reg [2:0] current_state, next_state;

always @(*) begin
	case(current_state)
		IDLE : begin
			if     (i_valid && (fadd_d || fsub_d || fmul_d || fdiv_d) && fa_ready && fb_ready) next_state = WORK        ;
			else if(i_valid && (fadd_d || fsub_d || fmul_d || fdiv_d) && fa_ready            ) next_state = WAIT_B_READY;
			else if(i_valid && (fadd_d || fsub_d || fmul_d || fdiv_d) &&             fb_ready) next_state = WAIT_A_READY;
			else if(i_valid &&  fadd_d || fsub_d || fmul_d || fdiv_d                         ) next_state = WAIT_READY  ;
			else																	           next_state = IDLE        ;
		end
		WAIT_READY : begin
			if     (fa_ready && fb_ready) next_state = WORK        ;
            else if(fa_ready            ) next_state = WAIT_B_READY;
            else if(            fb_ready) next_state = WAIT_A_READY;
			else                          next_state = WAIT_READY  ;
		end
		WAIT_A_READY : begin
			if(fa_ready) next_state = WORK        ;
			else         next_state = WAIT_A_READY;
		end
		WAIT_B_READY : begin
			if(fb_ready) next_state = WORK        ;
			else         next_state = WAIT_B_READY;
		end
		WORK			 : begin
			if(o_valid && o_ready) next_state = IDLE;
			else				   next_state = WORK;
		end
	endcase
end

always @(posedge clk or posedge rst) begin
	if(rst) begin
		current_state <= IDLE:
	end else begin
		current_state <= next_state;
	end
end

wire   fa_ready, fb_ready;
assign fa_ready = fadd_d ? add_fina_ready :
				  fsub_d ? sub_fina_ready :
				  fmul_d ? mul_fina_ready :
				  fdiv_d ? div_fina_ready : 0;
assign fb_ready = fadd_d ? add_finb_ready :
				  fsub_d ? sub_finb_ready :
				  fmul_d ? mul_finb_ready :
				  fdiv_d ? div_finb_ready : 0;
assign i_ready = ((current_state == WAIT_READY  ) && fa_ready && fb_ready) ||
                 ((current_state == WAIT_A_READY) && fa_ready            ) ||
                 ((current_state == WAIT_B_READY) &&          && fb_ready)   ; 

assign o_valid = fadd_d ? add_fresult_valid :
                 fsub_d ? sub_fresult_valid :
                 fmul_d ? mul_fresult_valid :
                 fdiv_d ? div_fresult_valid : 0;


wire add_fina_valid    = fadd_d && i_valid;
wire add_finb_valid    = fadd_d && i_valid;
wire add_fresult_ready = fadd_d && o_ready && (current_state == WORK);
wire sub_fina_valid    = fsub_d && i_valid;
wire sub_finb_valid    = fsub_d && i_valid;
wire sub_fresult_ready = fsub_d && o_ready && (current_state == WORK);
wire mul_fina_valid    = fmul_d && i_valid;
wire mul_finb_valid    = fmul_d && i_valid;
wire mul_fresult_ready = fmul_d && o_ready && (current_state == WORK);
wire div_fina_valid    = fdiv_d && i_valid;
wire div_finb_valid    = fdiv_d && i_valid;
wire div_fresult_ready = fdiv_d && o_ready && (current_state == WORK);

//decode float format
wire sign_a;
wire [EXP_BITS  :0] exp_a;//recFN exp
wire [SIG_BITS-1:0] sig_a;
wire isNAN_a       ;
wire isINf_a       ;
wire isZero_a      ;
wire isNormalize_a ;
wire isUnormalize_a;

wire sign_b;
wire [EXP_BITS  :0] exp_b;//recFN exp
wire [SIG_BITS-1:0] sig_b;
wire isNAN_b       ;
wire isINf_b       ;
wire isZero_b      ;
wire isNormalize_b ;
wire isUnormalize_b;

torecFN #(
    .FP_BITS    (FDATA_BITS ),
    .FP_LOG     (FDATA_SIZE ),
    .EXP_BITS   (EXP_BITS   ),
    .FRA_BITS   (FRA_BITS   ),
    .SIG_BITS   (SIG_BITS   ),
    .RECEXP_BITS(EXP_BITS+1 ),
    .EXP_OFFSET (EXP_OFFSET )
) torecFN_a (
	.fp          (fina          ), 
	.sign        (sign_a        ),
	.exp		 (exp_a	        ),
	.sig		 (sig_a	        ),
	.isNAN       (isNAN_a       ),
	.isINf       (isINf_a       ),
	.isZero      (isZero_a      ),
	.isNormalize (isNormalize_a ),
	.isUnormalize(isUnormalize_a)
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
	.fp          (finb          ), 
	.sign        (sign_b        ),
	.exp		 (exp_b	        ),
	.sig		 (sig_b	        ),
	.isNAN       (isNAN_b       ),
	.isINf       (isINf_b       ),
	.isZero      (isZero_b      ),
	.isNormalize (isNormalize_b ),
	.isUnormalize(isUnormalize_b)
);

//fadd / sign
wire add_sub_sel = fsub_s;

wire                add_res_sign        ;
wire [SIG_BITS-1:0] add_res_sig         ;
wire [EXP_BITS-1:0] add_res_exp         ;
wire                add_res_isNAN       ;
wire                add_res_isINf       ;
wire                add_res_isZero      ;
wire                add_res_isNormalize ;
wire                add_res_isUnormalize;

FADD fadd(
	.aclk			           (clk			        ),
    .areset                    (rst                 ),
//add-sub sel
    .s_axis_sel                (add_sub_sel         ),
//fina
	.s_axis_a_tvalid           (add_fina_valid      ),
	.s_axis_a_tready           (add_fina_ready      ),

	.s_axis_a_sign             (sign_a              ),
	.s_axis_a_sig              (sig_a               ),
	.s_axis_a_exp              (exp_a               ),

	.s_axis_a_isNAN            (isNAN               ),
	.s_axis_a_isINf            (isINf               ),
	.s_axis_a_isZero           (isZero              ),
	.s_axis_a_isNormalize      (isNormalize         ),
	.s_axis_a_isUnormalize     (isUnormalize        ),
//finb
	.s_axis_b_tvalid           (add_finb_valid      ),
	.s_axis_b_tready           (add_finb_ready      ),

	.s_axis_b_sign             (sign_b              ),
	.s_axis_b_sig              (sig_b               ),
	.s_axis_b_exp              (exp_b               ),

	.s_axis_b_isNAN            (isNAN_b             ),
	.s_axis_b_isINf            (isINf_b             ),
	.s_axis_b_isZero           (isZero_b            ),
	.s_axis_b_isNormalize      (isNormalize_b       ),
	.s_axis_b_isUnormalize     (isUnormalize_b      ),
//fresult
	.m_axis_result_tvalid      (add_fresult_valid   ),
	.m_axis_result_tready      (add_fresult_ready   ),

	.m_axis_result_sign        (add_res_sign        ),
	.m_axis_result_sig         (add_res_sig         ),
	.m_axis_result_exp         (add_res_exp         ),

	.m_axis_result_isNAN       (add_res_isNAN       ),
	.m_axis_result_isINf       (add_res_isINf       ),
	.m_axis_result_isZero      (add_res_isZero      ),
	.m_axis_result_isNormalize (add_res_isNormalize ),
	.m_axis_result_isUnormalize(add_res_isUnormalize),
);


//feq
wire feq_fresult = fina == finb;

//flt
wire flt_fresult = sign_a ^ sign_b ? sign_a :
									 sign_a == 0     ? ((exp_a != exp_b) ? (exp_a > exp_b) :
																		 ((fra_a != fra_b) ? (fra_a > fra_b) : 0)) :
									 sign_a == 1     ? ((exp_a != exp_b) ? (exp_a < exp_b) :
																		 ((fra_a != fra_b) ? (fra_a < fra_b) : 0)) : 0;

//fle
wire fle_fresult = sign_a ^ sign_b ? sign_a :
									 sign_a == 0     ? ((exp_a != exp_b) ? (exp_a > exp_b) :
																		 ((fra_a != fra_b) ? (fra_a > fra_b) : 1)) :
									 sign_a == 1     ? ((exp_a != exp_b) ? (exp_a < exp_b) :
																		 ((fra_a != fra_b) ? (fra_a < fra_b) : 1)) : 0;

//fsgnj
wire fsgnj_fresult = {sign_b, exp_a, fra_a};

//fcvt_w_s and fcvt_wu_s
wire [DATA_WIDTH-1:0] fcss_fresult;
wire [DATA_WIDTH-1:0] fcsu_fresult;
wire cvt_fw_nv;
wire cvt_fw_of;
wire cvt_fw_nx;
cvt_fw #(
	.DATA_WIDTH(DATA_WIDTH),
	.SIG_BITS  (FRA_BITS+1),
	.EXP_BITS  (EXP_BITS  ),
	.BIAS      (BIAS	  )
) cvt_x_s(
	.u_i   (fcvt_d_wu	 ),
	.sign  (sign_a	 	 ),
	.exp   (exp_a		 ),
	.sig   ({1'b1, fra_a}),
	.w_res (fcss_fresult ),
	.wu_res(fcsu_fresult ),
	.frm   (frm			 ),
	.isnan (isnan_a		 ),
	.nv	   (cvt_fw_nv	 ),
	.of	   (cvt_fw_of	 ),
	.nx	   (cvt_fw_nx	 )
);

//fcvt_s_w and fcvt_s_wu
wire                fcxs_sign;
wire [EXP_BITS-1:0] fcxs_exp;
wire [FRA_BITS  :0] fcxs_sig;
wire [FDATA_WIDTH-1:0] fcxs_fresult;
cvt_wf #(
	.DATA_WIDTH(DATA_WIDTH),
	.SIG_BITS  (FRA_BITS+1),
	.EXP_BITS  (EXP_BITS  ),
	.BIAS      (BIAS	  )
) cvt_s_x(
	.u_i   (fcvt_d_wu),
	.xdata (ina		 ),
	.sign  (fcxs_sign),
	.exp   (fcxs_exp ),
	.sig   (fcxs_sig )
);
assign fcxs_fresult = {fcxs_sign, fcxs_exp, fcxs_sig[0+:FRA_BITS]};

endmodule
