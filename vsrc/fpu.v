module fpu #(
	parameter FDATA_BITS  = 32            ,
	parameter FDATA_SIZE  = 5             ,
	parameter DATA_WIDTH  = 32            ,
	parameter FRA_BITS    = 23            ,
	parameter EXP_BITS    = 8             ,
	parameter SIG_BITS    = 32            ,
	parameter SIG_SIZE    = 5             ,
	parameter FRM_BITS    = 3             ,
    parameter EXP_OFFSET  = 9'b1_0000_0001
)(
	input clk,
	input rst,

    input                   i_valid,
    output                  i_ready,
	input  [           3:0] sel    ,
	input  [FRM_BITS  -1:0] frm    ,
	input  [FDATA_BITS-1:0] fina   ,
	input  [FDATA_BITS-1:0] finb   ,
	input  [DATA_WIDTH-1:0] ina    ,
	output		            o_valid,
	input                   o_ready,
	output [           4:0] fflags ,//mask
	output [FDATA_BITS-1:0] fresult
);

wire fadd_s = sel == 'd0 ;
wire fsub_s = sel == 'd1 ;
//wire fmul_s = sel == 'd2 ;
//wire fdiv_s = sel == 'd3 ;
wire feq_s  = sel == 'd4 ;
wire flt_s  = sel == 'd5 ;
wire fle_s  = sel == 'd6 ;
wire fsgnj_s   = sel == 'd7 ;
wire fsgnjn_s  = sel == 'd8 ;
wire fsgnjx_s  = sel == 'd9 ;
wire fcvt_w_s  = sel == 'd10;
wire fcvt_wu_s = sel == 'd11;
wire fcvt_s_w  = sel == 'd12;
wire fcvt_s_wu = sel == 'd13;

wire add_fina_ready;
wire add_finb_ready;
wire add_fresult_valid;

parameter IDLE		   = 3'b000;
parameter WAIT_READY   = 3'b100;
parameter WAIT_A_READY = 3'b101;
parameter WAIT_B_READY = 3'b110;
parameter WORK         = 3'b011;

reg [2:0] current_state, next_state;

always @(*) begin
	case(current_state)
		IDLE : begin
			if     (i_valid && fadd_s && fa_ready && fb_ready) next_state = WORK        ;
			else if(i_valid && fadd_s && fa_ready            ) next_state = WAIT_B_READY;
			else if(i_valid && fadd_s &&             fb_ready) next_state = WAIT_A_READY;
			else if(i_valid && fadd_s                        ) next_state = WAIT_READY  ;
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
        default : next_state = IDLE;
	endcase
end

always @(posedge clk or posedge rst) begin
	if(rst) begin
		current_state <= IDLE;
	end else begin
		current_state <= next_state;
	end
end

wire   fa_ready, fb_ready;
assign fa_ready = fadd_s ? add_fina_ready : 0;
assign fb_ready = fadd_s ? add_finb_ready : 0;
assign i_ready = ((current_state == WAIT_READY  ) && fa_ready && fb_ready) ||
                 ((current_state == WAIT_A_READY) && fa_ready            ) ||
                 ((current_state == WAIT_B_READY)             && fb_ready)   ; 

assign o_valid = fadd_s ? add_fresult_valid : i_valid;


wire add_fina_valid    = fadd_s && i_valid;
wire add_finb_valid    = fadd_s && i_valid;
wire add_fresult_ready = fadd_s && o_ready && (current_state == WORK);

//torecFN
wire sign_a;
wire [EXP_BITS  :0] exp_a;//recFN exp
wire [SIG_BITS-1:0] sig_a;
wire isNAN_a       ;
wire isINf_a       ;

wire sign_b;
wire [EXP_BITS  :0] exp_b;//recFN exp
wire [SIG_BITS-1:0] sig_b;
wire isNAN_b       ;
wire isINf_b       ;

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
	.isINf       (isINf_a       )
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
	.isINf       (isINf_b       )
);

//fadd / sign
wire add_sub_sel = fsub_s;

wire                add_res_sign        ;
wire [SIG_BITS-1:0] add_res_sig         ;
wire [EXP_BITS  :0] add_res_exp         ;
wire                add_res_isNAN       ;
wire                add_res_isINf       ;
wire [         4:0] add_res_fflags      ;

fadd #(
    .FRM_BITS(FRM_BITS  ),
    .FLA_BITS(5         ),
    .SIG_BITS(SIG_BITS  ),
    .SIG_SIZE(SIG_SIZE  ),
    .FRA_BITS(FRA_BITS+1),
    .EXP_BITS(EXP_BITS+1)
) FADD (
	.aclk			        (clk			     ),
    .areset                 (rst                 ),
//add-sub sel
    .s_axis_sel             (add_sub_sel         ),
    .s_axis_frm             (frm                 ),
//fina
	.s_axis_a_tvalid        (add_fina_valid      ),
	.s_axis_a_tready        (add_fina_ready      ),

	.s_axis_a_sign          (sign_a              ),
	.s_axis_a_sig           (sig_a               ),
	.s_axis_a_exp           (exp_a               ),
	.s_axis_a_isNAN         (isNAN_a             ),
	.s_axis_a_isINf         (isINf_a             ),
//finb
	.s_axis_b_tvalid        (add_finb_valid      ),
	.s_axis_b_tready        (add_finb_ready      ),

	.s_axis_b_sign          (sign_b              ),
	.s_axis_b_sig           (sig_b               ),
	.s_axis_b_exp           (exp_b               ),
	.s_axis_b_isNAN         (isNAN_b             ),
	.s_axis_b_isINf         (isINf_b             ),
//fresult
	.m_axis_res_tvalid      (add_fresult_valid   ),
	.m_axis_res_tready      (add_fresult_ready   ),

	.m_axis_res_sign        (add_res_sign        ),
	.m_axis_res_sig         (add_res_sig         ),
	.m_axis_res_exp         (add_res_exp         ),
	.m_axis_res_isNAN       (add_res_isNAN       ),
	.m_axis_res_isINf       (add_res_isINf       ),
	.m_axis_res_fflags      (add_res_fflags      )
);

//fadd/fsub result
wire                  sign_res  = add_res_sign ;
wire [EXP_BITS    :0] exp_res   = add_res_exp  ;
wire [SIG_BITS  -1:0] sig_res   = add_res_sig  ;
wire                  isNAN_res = add_res_isNAN;
wire                  isINf_res = add_res_isINf;

//torecFN
wire [FDATA_BITS-1:0] fpu_result;
tostdFN#(
    .FP_BITS    (FDATA_BITS ),
    .EXP_BITS   (EXP_BITS   ),
    .FRA_BITS   (FRA_BITS   ),
    .SIG_BITS   (SIG_BITS   ),
    .RECEXP_BITS(EXP_BITS+1 ),
    .EXP_OFFSET (EXP_OFFSET )
) tostdFN (
	.sign        (sign_res        ),
	.exp		 (exp_res	      ),
	.sig		 (sig_res	      ),
	.isNAN       (isNAN_res       ),
	.isINf       (isINf_res       ),
	.fp          (fpu_result      )
);

//feq
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] feq_fresult = !(isNAN_a || isNAN_b) && (fina == finb); //feq_fflags = 0;
/* verilator lint_on WIDTHEXPAND */

//flt
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] flt_fresult = isNAN_a || isNAN_b ? 0             :
                                    sign_a ^ sign_b    ? sign_a        :
                                    !sign_a            ? exp_a < exp_b : exp_a > exp_b;
/* verilator lint_on WIDTHEXPAND */
wire [4:0] flt_fflags = {isNAN_a || isNAN_b, 4'b0};                                               

//fle
/* verilator lint_off WIDTHEXPAND */
wire [FDATA_BITS-1:0] fle_fresult = isNAN_a || isNAN_b ? 0              :
                                    sign_a ^ sign_b    ? sign_a         :
                                    !sign_a            ? exp_a <= exp_b : exp_a >= exp_b;
/* verilator lint_on WIDTHEXPAND */
wire [4:0] fle_fflags = {isNAN_a || isNAN_b, 4'b0};

wire                st_sign_a = fina[FDATA_BITS-1          ];
wire [EXP_BITS-1:0] st_exp_a  = fina[FDATA_BITS-2-:EXP_BITS];
wire [FRA_BITS-1:0] st_fra_a  = fina[FRA_BITS  -1 :0       ];
wire                st_sign_b = finb[FDATA_BITS-1          ];
//fsgnj
wire [FDATA_BITS-1:0] fsgnj_fresult = {st_sign_b, st_exp_a, st_fra_a}; //fsgnj_fflags = 0;

//fsgnjn
wire [FDATA_BITS-1:0] fsgnjn_fresult = {!st_sign_b, st_exp_a, st_fra_a}; //fsgnjn_fflags = 0;

//fsgnjx
wire [FDATA_BITS-1:0] fsgnjx_fresult = {st_sign_a ^ st_sign_b, st_exp_a, st_fra_a}; //fsgnjx_fflags = 0;

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
	.u_i   (fcvt_wu_s	   ),
	.sign  (sign_a         ),
	.exp   (exp_a          ),
	.sig   (sig_a          ),
	.w_res (fcss_fresult   ),
	.wu_res(fcsu_fresult   ),
	.frm   (frm			   ),
	.isnan (isNAN_a        ),
	.isinf (isINf_a		   ),
	.nv	   (cvt_fw_nv	   ),
	.nx	   (cvt_fw_nx	   )
);
wire [4:0] fcvt_w_s_fflags = {cvt_fw_nv, 1'b0, 1'b0, 1'b0, cvt_fw_nx};

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
	.xdata (ina		 ),
	.frm   (frm		 ),
	.sign  (fcxs_sign),
	.exp   (fcxs_exp ),
	.sig   (fcxs_sig ),
	.nx    (cvt_wf_nx)
);
assign fcxs_fresult = {fcxs_sign, fcxs_exp, fcxs_sig[FRA_BITS-1:0]};
wire [4:0] fcvt_s_w_fflags = {4'b0, cvt_wf_nx};

//fresult
assign fresult = fadd_s || fsub_s                     ? fpu_result     :
                 feq_s                                ? feq_fresult    :
                 flt_s                                ? flt_fresult    :
                 fle_s                                ? fle_fresult    : 
                 fsgnj_s                              ? fsgnj_fresult  : 
                 fsgnjx_s                             ? fsgnjx_fresult : 
                 fsgnjn_s                             ? fsgnjn_fresult : 
                 fcvt_w_s                             ? fcss_fresult   :
                 fcvt_wu_s                            ? fcsu_fresult   :
                 fcvt_s_w                             ? fcxs_fresult   :
                 fcvt_s_wu                            ? fcxs_fresult   : 0;

assign fflags = fadd_s || fsub_s                          ? add_res_fflags  :
                feq_s  || fsgnj_s || fsgnjn_s || fsgnjx_s ? 5'b0            :
                flt_s                                     ? flt_fflags      :
                fle_s                                     ? fle_fflags      : 
                fcvt_w_s || fcvt_wu_s                     ? fcvt_w_s_fflags :
                fcvt_s_w || fcvt_s_wu                     ? fcvt_s_w_fflags : 5'b0;

endmodule
