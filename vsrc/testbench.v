`timescale 1ns/1ps
module testbench;
  parameter NUM = 100000;
	reg [127:0] test_vectors [0:NUM-1]; 
	reg [5:0] sel;
	reg [31:0] ina;
	reg [31:0] inb;
	reg [2:0] frm;
	wire [4:0] _fflags;
	wire [31:0] _result;
	reg [4:0] tst_fflags;
	reg [31:0] tst_result;
	reg right;

integer i;

always @(*) begin
	if(tst_result == _result) begin
		right = 1;
	end else begin
		right = 0;
  end
end

FPU i0(
	.io_sel(sel),
	.io_ina(ina),
	.io_inb(inb),
	.io_frm(frm),
	.io_fflags(_fflags),
	.io_result(_result)
);

initial begin
	$readmemh("test-examples/fpu_test_vectors.hex", test_vectors);
//	$dumpfile("dump.vcd");
	$dumpvars(0, test_vectors);  // 指定 dump memory
	for(i = 0; i < NUM; i = i + 1) begin
	  sel = test_vectors[i][6+32+32+4+32+8-1:32+32+4+32+8];
	  ina = test_vectors[i][32+32+4+32+8-1:32+4+32+8];
	  inb = test_vectors[i][32+4+32+8-1:4+32+8];
	  frm = test_vectors[i][3+32+8-1:32+8];
	  tst_result = test_vectors[i][32+8-1:8];
	  tst_fflags = test_vectors[i][5-1:0];
	  #10;
    $display("Test %0d: sel=%h, ina=%h, inb=%h, frm=%h, result=%h, fflags=%h, fpu_res=%h, fpu_fflags=%h, right=%d", i, sel, ina, inb, frm, tst_result, tst_fflags, _result, _fflags, right);
	end
	$finish;
end

endmodule
