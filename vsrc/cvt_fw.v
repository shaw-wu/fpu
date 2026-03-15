`timescale 1ns / 1ps
module cvt_fw #(
	parameter DATA_BITS = 32,
	parameter SIG_BITS  = 32,
	parameter EXP_BITS  = 9 
)(
	input				   u_i	   ,
	input				   sign	   ,
	input  [EXP_BITS -1:0] exp	   ,
	input  [SIG_BITS -1:0] sig	   ,
	output [DATA_BITS-1:0] w_res   ,
	output [DATA_BITS-1:0] wu_res  ,
	input  [          2:0] frm	   ,
	input		           isnan   ,
	input		           isinf   ,
	output		           nv	   ,
	output		           nx	   
);

localparam RE_DATAWIDTH = DATA_BITS + (1 << (EXP_BITS-1));

//shift amt
wire [EXP_BITS-1:0] shift_amt;
/* verilator lint_off SELRANGE*/
/* verilator lint_off WIDTHTRUNC*/
assign shift_amt = RE_DATAWIDTH - 1 - exp;
/* verilator lint_on SELRANGE */
/* verilator lint_on WIDTHTRUNC*/

//right shift
wire [2*DATA_BITS-1:0]  shift_sig;
wire [  DATA_BITS-1:0]  shift_xdata;
assign  shift_sig = {sig, {(2*DATA_BITS-SIG_BITS){1'b0}}} >>  shift_amt;
assign  shift_xdata = shift_sig[2*DATA_BITS-1:DATA_BITS];

//round
wire [DATA_BITS-1:0] sigres ;
wire lsbBit    =  shift_sig[DATA_BITS    ];
wire guardBit  =  shift_sig[DATA_BITS-1  ];
wire roundBit  =  shift_sig[DATA_BITS-2  ];
wire stickyBit = |shift_sig[DATA_BITS-3:0];
wire roundIncre = (frm == 3'b000) ? guardBit && (lsbBit || stickyBit || roundBit) :    //rte
				  (frm == 3'b001) ? 0 											  :	   //rtz
				  (frm == 3'b010) ?  sign && (guardBit || roundBit || stickyBit)  :	   //rdn
				  (frm == 3'b011) ? !sign && (guardBit || roundBit || stickyBit)  :	   //rup
				  (frm == 3'b100) ?  guardBit                                     : 0; //rmm	
/* verilator lint_off WIDTHEXPAND */
assign sigres = shift_xdata + roundIncre;
/* verilator lint_on WIDTHEXPAND */

//overflow
wire of = (u_i && overflow_wu) || (!u_i && overflow_w);
wire overflow_wu = sign ? (sigres != 0)                                                                     : (exp > (RE_DATAWIDTH - 1));
wire overflow_w  = sign ? (exp > RE_DATAWIDTH) || ((exp == RE_DATAWIDTH) && (sig != (1 << (SIG_BITS - 1)))) : (exp > (RE_DATAWIDTH - 1));

//result
wire [DATA_BITS-2:0] neg_sigres = ~sigres[DATA_BITS-2:0] + 1;
wire [DATA_BITS-1:0] comp_res = sign ? {1'b1, neg_sigres         } : {1'b0, sigres[DATA_BITS-2:0]} ;
wire [DATA_BITS-1:0] of_wres  = sign ? {1'b1, {DATA_BITS-1{1'b0}}} : {1'b0, {DATA_BITS-1{1'b1}}}   ;

assign wu_res = of ? {DATA_BITS{1'b1}} : sigres  ;
assign w_res  = of ? of_wres           : comp_res;

assign nv = isnan || isinf || of;
assign nx = !nv && (guardBit || roundBit || stickyBit);

endmodule
