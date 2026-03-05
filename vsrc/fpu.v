module fpu #(
	parameter FDATA_WIDTH = 64  ,
	parameter  DATA_WIDTH = 32  ,
	parameter FRA_BITS    = 52  ,
	parameter EXP_BITS    = 11  ,
	parameter EXP_START   = 53  ,
	parameter SIGN_START  = 63  ,
	parameter BIAS        = 1023
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

wire fadd_d = sel == 'd0 ;
wire fsub_d = sel == 'd1 ;
wire fmul_d = sel == 'd2 ;
wire fdiv_d = sel == 'd3 ;
wire feq_d  = sel == 'd4 ;
wire flt_d  = sel == 'd5 ;
wire fle_d  = sel == 'd6 ;
wire fsgnj_d   = sel == 'd7 ;
wire fcvt_w_d  = sel == 'd8 ;
wire fcvt_wu_d = sel == 'd8 ;
wire fcvt_d_w  = sel == 'd9 ;
wire fcvt_d_wu = sel == 'd10;

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
wire [EXP_BITS-1:0] exp_a;
wire [FRA_BITS-1:0] fra_a;
wire sign_b;
wire [EXP_BITS-1:0] exp_b;
wire [FRA_BITS-1:0] fra_b;
assign sign_a = fina[SIGN_START];
assign exp_a  = fina[EXP_START+:EXP_BITS];
assign fra_a  = fina[0        +:FRA_BITS];
assign sign_b = finb[SIGN_START];
assign exp_b  = finb[EXP_START+:EXP_BITS];
assign fra_b  = finb[0        +:FRA_BITS];

wire iszero_a = (exp_a == 0) && (fra_a == 0);
wire isunormalize_a = (exp_a == 0) && (fra_a != 0);
wire isnormalize_a  = (exp_a != 0) && (fra_a != 0);
wire isinf_a = (exp_a == {EXP_BITS{1'b1}}) && (fra_a == 0);
wire isnan_a = (exp_a == {EXP_BITS{1'b1}}) && (fra_a != 0);
wire iszero_b = (exp_b == 0) && (fra_b == 0);
wire isunormalize_b = (exp_b == 0) && (fra_b != 0);
wire isnormalize_b  = (exp_b != 0) && (fra_b != 0);
wire isinf_b = (exp_b == {EXP_BITS{1'b1}}) && (fra_b == 0);
wire isnan_b = (exp_b == {EXP_BITS{1'b1}}) && (fra_b != 0);

torecFN #(
    .FP_BITS    (),
    .FP_LOG     (),
    .EXP_BITS   (),
    .FRA_BITS   (),
    .SIG_BITS   (),
    .RECEXP_BITS(),
    .EXP_OFFSET ()
) torecFN_a (
	.fp          (fina), 
	.sign        (sign_a),
	.exp		 (exp),
	.sig		 (),
	.isNAN       (),
	.isINf       (),
	.isZero      (),
	.isNormalize (),
	.isUnormalize()
);

//fadd
wire add_fina_valid;
wire add_fina_ready;
wire [FDATA_BITS-1:0] add_fina_data;
wire add_finb_valid;
wire add_finb_ready;
wire [FDATA_BITS-1:0] add_finb_data;
wire add_fresult_valid;
wire add_fresult_ready;
wire [FDATA_BITS-1:0] add_fresult_data;
wire [2:0] add_fresult_flags;
FADD fadd(
	.aclk			(clk							 ),
	.s_axis_a_tvalid   (add_fina_valid	 ),
	.s_axis_a_tready   (add_fina_ready	 ),
	.s_axis_a_tdata	   (add_fina_data 	 ),
	.s_axis_b_tvalid   (add_finb_valid	 ),
	.s_axis_b_tready   (add_finb_ready	 ),
	.s_axis_b_tdata	   (add_finb_data 	 ),
	.m_axis_result_tvalid(add_fresult_valid),
	.m_axis_result_tready(add_fresult_ready),
	.m_axis_result_tdata (add_fresult_data ),
	.m_axis_result_tuser (add_fresult_flags)
);

//fsub
wire sub_fina_valid;
wire sub_fina_ready;
wire [FDATA_BITS-1:0] sub_fina_data;
wire sub_finb_valid;
wire sub_finb_ready;
wire [FDATA_BITS-1:0] sub_finb_data;
wire sub_fresult_valid;
wire sub_fresult_ready;
wire [FDATA_BITS-1:0] sub_fresult_data;
wire [2:0] sub_fresult_flags;
FSUB fsub(
	.aclk							 (clk							 ),
	.s_axis_a_tvalid   (sub_fina_valid	 ),
	.s_axis_a_tready   (sub_fina_ready	 ),
	.s_axis_a_tdata	   (sub_fina_data 	 ),
	.s_axis_b_tvalid   (sub_finb_valid	 ),
	.s_axis_b_tready   (sub_finb_ready	 ),
	.s_axis_b_tdata	   (sub_finb_data 	 ),
	.m_axis_result_tvalid(sub_fresult_valid),
	.m_axis_result_tready(sub_fresult_ready),
	.m_axis_result_tdata (sub_fresult_data ),
	.m_axis_result_tuser (sub_fresult_flags)
);

//fmul
wire mul_fina_valid;
wire mul_fina_ready;
wire [FDATA_BITS-1:0] mul_fina_data;
wire mul_finb_valid;
wire mul_finb_ready;
wire [FDATA_BITS-1:0] mul_finb_data;
wire mul_fresult_valid;
wire mul_fresult_ready;
wire [FDATA_BITS-1:0] mul_fresult_data;
wire [2:0] mul_fresult_flags;
FMUL fmul(
	.aclk							 (clk							 ),
	.s_axis_a_tvalid   (mul_fina_valid	 ),
	.s_axis_a_tready   (mul_fina_ready	 ),
	.s_axis_a_tdata	   (mul_fina_data 	 ),
	.s_axis_b_tvalid   (mul_finb_valid	 ),
	.s_axis_b_tready   (mul_finb_ready	 ),
	.s_axis_b_tdata	   (mul_finb_data 	 ),
	.m_axis_result_tvalid(mul_fresult_valid),
	.m_axis_result_tready(mul_fresult_ready),
	.m_axis_result_tdata (mul_fresult_data ),
	.m_axis_result_tuser (mul_fresult_flags)
);

//fdiv
wire div_fina_valid;
wire div_fina_ready;
wire [FDATA_BITS-1:0] div_fina_data;
wire div_finb_valid;
wire div_finb_ready;
wire [FDATA_BITS-1:0] div_finb_data;
wire div_fresult_valid;
wire div_fresult_ready;
wire [FDATA_BITS-1:0] div_fresult_data;
wire [3:0] div_fresult_flags;
FIV fiv(
	.aclk			   (clk			     ),
	.s_axis_a_tvalid   (div_fina_valid	 ),
	.s_axis_a_tready   (div_fina_ready	 ),
	.s_axis_a_tdata	   (div_fina_data 	 ),
	.s_axis_b_tvalid   (div_finb_valid	 ),
	.s_axis_b_tready   (div_finb_ready	 ),
	.s_axis_b_tdata	   (div_finb_data 	 ),
	.m_axis_result_tvalid(div_fresult_valid),
	.m_axis_result_tready(div_fresult_ready),
	.m_axis_result_tdata (div_fresult_data ),
	.m_axis_result_tuser (div_fresult_flags)
);
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

//fcvt_w_d and fcvt_wu_d
wire [DATA_WIDTH-1:0] fcds_fresult;
wire [DATA_WIDTH-1:0] fcdu_fresult;
wire cvt_fw_nv;
wire cvt_fw_of;
wire cvt_fw_nx;
cvt_fw #(
	.DATA_WIDTH(DATA_WIDTH),
	.SIG_BITS  (FRA_BITS+1),
	.EXP_BITS  (EXP_BITS  ),
	.BIAS      (BIAS	  )
) cvt_x_d(
	.u_i   (fcvt_d_wu	 ),
	.sign  (sign_a	 	 ),
	.exp   (exp_a		 ),
	.sig   ({1'b1, fra_a}),
	.w_res (fcds_fresult ),
	.wu_res(fcdu_fresult ),
	.frm   (frm			 ),
	.isnan (isnan_a		 ),
	.nv	   (cvt_fw_nv	 ),
	.of	   (cvt_fw_of	 ),
	.nx	   (cvt_fw_nx	 )
);

//fcvt_d_w and fcvt_d_wu
wire                fcxd_sign;
wire [EXP_BITS-1:0] fcxd_exp;
wire [FRA_BITS  :0] fcxd_sig;
wire [FDATA_WIDTH-1:0] fcxd_fresult;
cvt_wf #(
	.DATA_WIDTH(DATA_WIDTH),
	.SIG_BITS  (FRA_BITS+1),
	.EXP_BITS  (EXP_BITS  ),
	.BIAS      (BIAS	  )
) cvt_d_x(
	.u_i   (fcvt_d_wu),
	.xdata (ina		 ),
	.sign  (fcxd_sign),
	.exp   (fcxd_exp ),
	.sig   (fcxd_sig )
);
assign fcxd_fresult = {fcxd_sign, fcxd_exp, fcxd_sig[0+:FRA_BITS]};

endmodule
