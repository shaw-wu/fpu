`timescale 1ns / 1ps
module cvt_wf #(
	parameter DATA_BITS = 32,
	parameter DATA_SIZE = 5 ,
	parameter SIG_BITS  = 24,
	parameter EXP_BITS  = 8 ,
	parameter BIAS		= 127 
)(
	input				    u_i	 ,
	input  [DATA_WIDTH-1:0] xdata,
	output 					sign ,
	output [EXP_BITS  -1:0] exp  ,
	output [SIG_BITS  -1:0] sig  ,
    output                  nx
);

wire [DATA_BITS-1:0] uint_data;
wire [DATA_BITS-1:0]  int_data;
assign uint_data = xdata;
assign  int_data = xdata[DATA_BITS-1] ? ~xdata[DATA_BITS-1:0] + 1 : xdata[DATA_BITS-1:0];

wire [DATA_BITS-1:0] data = u_i ? uint_data : int_data;

//32bits shifter(detect lead zero)
wire [DATA_SIZE-1:0] shift_amt;
ldz #(
    .DATA_BITS(DATA_BITS),
    .DATA_SIZE(DATA_SIZE)
) LDZ (
    .in (data     ),
    .out(shift_amt)
);

wire [DATA_BITS-1:0] shift_sig = xdata << shift_amt;
 
//round
wire [SIG_BITS-1:0] sigres;
wire lsbBit    =  shift_sig[DATA_BITS-SIG_BITS    ];
wire guardBit  =  shift_sig[DATA_BITS-SIG_BITS-1  ];
wire roundBit  =  shift_sig[DATA_BITS-SIG_BITS-2  ];
wire stickyBit = |shift_sig[DATA_BITS-SIG_BITS-3:0];
wire roundIncre = (frm == 3'b000) ? guardBit && (lsbBit || stickyBit || roundBit) : //rte
				  (frm == 3'b001) ? 0 											  :	//rtz
				  (frm == 3'b010) ?  sign && (guardBit || roundBit || stickyBit)  :	//rdn
				  (frm == 3'b011) ? !sign && (guardBit || roundBit || stickyBit)  :	//rup
				  (frm == 3'b100) ?  guardBit                                     : 0; //rmm	
assign sigres = shift_xsig[DATA_BITS-:SIG_BITS] + roundIncre;

//res
assign sign = u_i ? 0 : xdata[DATA_WIDTH-1]    ;
assign exp  = DATA_BITS - 1 - shift_amt + BIAS ;
assign sig  = shift_sig                        ; 
assign nx   = guardBit || roundBit || stickyBit;

endmodule
