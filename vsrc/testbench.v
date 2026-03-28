`timescale 1ns/1ps

module testbench;

parameter FDATA_WIDTH = 64;
parameter CLK_PERIOD  = 10;
parameter MAX_VEC     = 10000000;

reg clk;
reg rst;

reg i_valid;
wire i_ready;

reg [4:0] sel;
reg [2:0] frm;

reg [FDATA_WIDTH-1:0] fina;
reg [FDATA_WIDTH-1:0] finb;

wire o_valid;
reg  o_ready;

wire [4:0] fflags;
wire [FDATA_WIDTH-1:0] fresult;

// ======== queue 保存期望结果 ========
reg [FDATA_WIDTH-1:0] exp_res_q   [0:MAX_VEC-1];
reg [4:0]             exp_flag_q  [0:MAX_VEC-1];
reg [4:0]             exp_sel_q  [0:MAX_VEC-1];

integer head = 0;
integer tail = 0;

reg [31:0] gap;
// ======== 统计 ========
integer vector_cnt = 0;
integer error_cnt  = 0;
integer recv_cnt   = 0;

// ======== 文件 ========
integer file_in;
integer file_log;
integer status;

reg [FDATA_WIDTH-1:0] exp_res;
reg [4:0]             exp_flag;


// ======== DUT ========
fpu #(
    .FDATA_BITS(FDATA_WIDTH)
) dut (
    .clk(clk),
    .rst(rst),
    .i_valid(i_valid),
    .i_ready(i_ready),
    .sel(sel),
    .frm(frm),
    .fina(fina),
    .finb(finb),
    .ina(fina[31:0]),
    .o_valid(o_valid),
    .o_ready(o_ready),
    .fflags(fflags),
    .fresult(fresult)
);


// ======== 时钟 ========
initial clk = 0;
always #(CLK_PERIOD/2) clk = ~clk;
always @(posedge clk)  gap <= (gap + 1) % 8;


// ======== 输入线程（发射流水）=======
initial begin

    rst     = 1;
    i_valid = 0;
    o_ready = 1;

    //sel = 5'd6;       // FADD
    //frm = 3'd0;       // RNE
    //frm = 3'd1;       // RTZ
    //frm = 3'd2;       // RDN
    //frm = 3'd3;       // RUP
    //frm = 3'd4;       // RMM

    #(CLK_PERIOD*10);
    rst = 0;

    file_in  = $fopen("fpu_test_suite.tmp","r");
    file_log = $fopen("log.tmp","w");

    if(file_in==0 || file_log==0) begin
        $display("ERROR: file open failed");
        $finish;
    end

    $display("===== FPU PIPELINE TEST START =====");
    $fdisplay(file_log,"===== FPU TEST START =====");

    while(!$feof(file_in)) begin

        @(posedge clk);
        if(i_ready) begin

            #1
            status = $fscanf(file_in,"%h %h %h %h %h %h\n",
                             fina, finb, exp_res, exp_flag, frm, sel);

            if(status==6) begin

                // push queue
                exp_res_q[tail]  = exp_res;
                exp_flag_q[tail] = exp_flag;
                exp_sel_q[tail] = sel;
                tail = tail + 1;
                vector_cnt = vector_cnt + 1;

                i_valid = 1;


                if(vector_cnt % 1000 == 0)
                    $display("[SEND] %0d vectors",vector_cnt);

            end
        end
    end
    i_valid = 0;

    $display("All vectors issued = %0d",vector_cnt);

end
// ======== 输出线程（流水接收）=======
initial begin

    forever begin
        @(posedge clk);

        if(o_valid) begin

            recv_cnt = recv_cnt + 1;

            if(fresult !== exp_res_q[head] ||
               fflags  !== exp_flag_q[head]) begin

                error_cnt = error_cnt + 1;

                //$display("[ERR] id=%0d  A=%h B=%h  got=%h flag=%b exp=%h flag=%b",
                //          head, fina, finb,
                //          fresult, fflags,
                //          exp_res_q[head], exp_flag_q[head]);

                $fdisplay(file_log,
                          "[ERR] id=%0d sel=%h got=%h %b exp=%h %b",
                          head, exp_sel_q[head],
                          fresult, fflags,
                          exp_res_q[head], exp_flag_q[head]);

            end

            head = head + 1;

            if(recv_cnt % 100 == 0)
                $display("[RECV] %0d results  error=%0d",
                         recv_cnt,error_cnt);
        // 自动结束
        if($feof(file_in)) begin

            $display("==================================");
            $display("TEST FINISH");
            $display("Total  = %0d",vector_cnt);
            $display("Error  = %0d",error_cnt);
            $display("==================================");

            $fdisplay(file_log,
                      "FINISH total=%0d error=%0d",
                      vector_cnt,error_cnt);

            $fclose(file_in);
            $fclose(file_log);

            #(CLK_PERIOD*20);
            $finish;
        end


        end
    end

end

endmodule
