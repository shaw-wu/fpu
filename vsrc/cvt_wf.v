`timescale 1ns / 1ps
module cvt_wf #(
	parameter DATA_BITS = 32,
	parameter DATA_SIZE = 5 ,
	parameter SIG_BITS  = 24,
	parameter EXP_BITS  = 8 
)(
	input				   u_i	,
	input  [DATA_BITS-1:0] xdata,
/* verilator lint_off UNUSEDSIGNAL */
	input  [          2:0] frm  ,
/* verilator lint_on UNUSEDSIGNAL */
	output 				   sign ,
	output [EXP_BITS -1:0] exp  ,
	output [SIG_BITS -1:0] sig  ,
    output                 nx
);
localparam BIAS_D = 1023;

wire [DATA_BITS-1:0] uint_data;
wire [DATA_BITS-1:0]  int_data;
assign uint_data = xdata;
assign  int_data = xdata[DATA_BITS-1] ? ~xdata[DATA_BITS-1:0] + 1 : xdata[DATA_BITS-1:0];

wire [DATA_BITS-1:0] data = u_i ? uint_data : int_data;

//32bits shifter(detect lead zero)
/* verilator lint_off UNUSED */
wire [DATA_SIZE  :0] full_shift_amt;
/* verilator lint_on UNUSED */
wire [DATA_SIZE-1:0] shift_amt = full_shift_amt[DATA_SIZE-1:0];
ldz #(
    .DATA_BITS(DATA_BITS),
    .DATA_SIZE(DATA_SIZE)
) LDZ (
    .in (data          ),
    .out(full_shift_amt)
);

wire [DATA_BITS-1:0] shift_sig = data << shift_amt;
 
//round
//wire [SIG_BITS-1:0] sigres ;
//wire                sigcout;
//wire lsbBit    =  shift_sig[DATA_BITS-SIG_BITS    ];
//wire guardBit  =  shift_sig[DATA_BITS-SIG_BITS-1  ];
//wire roundBit  =  shift_sig[DATA_BITS-SIG_BITS-2  ];
//wire stickyBit = |shift_sig[DATA_BITS-SIG_BITS-3:0];
//wire roundIncre = (frm == 3'b000) ? guardBit && (lsbBit || stickyBit || roundBit) : //rte
//				  (frm == 3'b001) ? 0 											  :	//rtz
//				  (frm == 3'b010) ?  sign && (guardBit || roundBit || stickyBit)  :	//rdn
//				  (frm == 3'b011) ? !sign && (guardBit || roundBit || stickyBit)  :	//rup
//				  (frm == 3'b100) ?  guardBit                                     : 0; //rmm	
///* verilator lint_off WIDTHEXPAND */
//assign {sigcout, sigres} = shift_sig[DATA_BITS-1-:SIG_BITS] + roundIncre;
///* verilator lint_on WIDTHEXPAND */
///* verilator lint_off WIDTHEXPAND */
//wire r_exp  = xdata == 0 ? 0 : DATA_BITS - 1 - shift_amt + sigcout + BIAS_D     ;
///* verilator lint_on WIDTHEXPAND */
//wire r_sig  = sigcout ? {1'b1, {(SIG_BITS-1){1'b0}}} : sigres;

//res
assign sign = u_i ? 0 : xdata[DATA_BITS-1]                   ;
/* verilator lint_off WIDTHEXPAND */
assign exp  = xdata == 0 ? 0 : DATA_BITS - 1 - shift_amt + BIAS_D     ;
/* verilator lint_on WIDTHEXPAND */
assign sig  = {shift_sig, {(SIG_BITS-DATA_BITS){1'b0}}};
//assign nx   = guardBit || roundBit || stickyBit              ;
assign nx   = 0;

endmodule
