`timescale 1ns / 1ps
`ifdef VERILATOR
import "DPI-C" function void fdiv_D(input byte aclk, input byte a_valid, output byte a_ready, input longint a_data, input byte b_valid, output byte b_ready, input longint b_data, output byte result_valid, input byte result_ready, output longint result_data, output byte result_tuser);
`endif
module fdiv(
	input         aclk,
	input		  s_axis_a_tvalid,
	output 		  s_axis_a_tready,
	input [63:0]  s_axis_a_tdata ,
	input		  s_axis_b_tvalid,
	output 		  s_axis_b_tready,
	input [63:0]  s_axis_b_tdata ,
	output		  m_axis_result_tvalid,
	input 		  m_axis_result_tready,
	output [63:0] m_axis_result_tdata ,
	output [3:0]  m_axis_result_tuser
);
`ifdef VERILATOR
    /*verilator lint_off UNUSEDSIGNAL*/
	reg [7 :0] a_tready;
	reg [7 :0] b_tready;
	reg	[7 :0] result_tvalid;
	reg [7 :0] result_tuser ;
    /*verilator lint_on UNUSEDSIGNAL*/
	reg [63:0] result_tdata ;

	assign s_axis_a_tready      = a_tready[0]      ;
	assign s_axis_b_tready      = b_tready[0]      ;
	assign m_axis_result_tvalid = result_tvalid[0] ;
	assign m_axis_result_tdata  = result_tdata     ;
	assign m_axis_result_tuser  = result_tuser[3:0];

	always @(posedge aclk) begin
		fdiv_D({7'b0, aclk}, {7'b0, s_axis_a_tvalid}, a_tready, s_axis_a_tdata, {7'b0, s_axis_b_tvalid}, b_tready, s_axis_b_tdata, result_tvalid, {7'b0, m_axis_result_tready}, result_tdata, result_tuser);
	end
`endif
endmodule
