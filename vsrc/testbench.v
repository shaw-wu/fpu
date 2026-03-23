//`timescale 1ns/1ps
//
//module testbench;
//    parameter DATA_WIDTH = 32;
//    //reg clk;
//    //reg rst;
//    reg [DATA_WIDTH-1:0] m;
//    reg [DATA_WIDTH-1:0] r;
//    wire [2*DATA_WIDTH-1:0] result;
//
//    // 实例化你的乘法器
//    mul #(DATA_WIDTH) uut (
//        //.clk(clk),
//        //.rst(rst),
//        .m(m),
//        .r(r),
//        .result(result)
//    );
//
//    // 测试数据存储
//    reg [DATA_WIDTH-1:0] test_m [0:10000];
//    reg [DATA_WIDTH-1:0] test_r [0:10000];
//    reg [2*DATA_WIDTH-1:0] golden_res [0:10000];
//
//    integer file;
//    // 时钟生成
//    //initial clk = 0;
//    //always #5 clk = ~clk;
//
//    integer i, errors;
//    initial begin
//        // 1. 初始化
//        //rst = 1;
//        errors = 0;
//        m = 0;
//        r = 0;
//        
//        // 2. 加载 C 生成的数据
//        // 注意：数据文件格式需为 $readmemh 可识别的格式，或者用 $fscanf
//        // 这里演示 $fscanf 动态读取
//        file = $fopen("vsrc/mul/mul_test_data.tmp", "r");
//        if (file == 0) begin
//            $display("Error: Cannot open test data file!");
//            $finish;
//        end
//
//        for (i = 0; i < 10000; i = i + 1) begin
//            $fscanf(file, "%h %h %h\n", test_m[i], test_r[i], golden_res[i]);
//        end
//        $fclose(file);
//
//        //#20 rst = 0;
//
//        // 3. 开始测试
//        $display("--- Starting Multiplier Random Test ---");
//        for (i = 0; i < 10000; i = i + 1) begin
//            //@(posedge clk);
//            m = test_m[i];
//            r = test_r[i];
//            #5
//            
//            // 如果你的乘法器有流水线延迟（例如 PP_LEVELS=6 对应 6 拍或更多）
//            // 需要在这里等待相应的节拍数。假设是组合逻辑或 1 拍：
//            //repeat(1) @(posedge clk); 
//            
//            if (result !== golden_res[i]) begin
//                $display("Error at Sample %d: m=%h, r=%h | Got %h, Expected %h", 
//                          i, m, r, result, golden_res[i]);
//                errors = errors + 1;
//            end
//        end
//
//        // 4. 结果统计
//        if (errors == 0)
//            $display("--- PASSED: All 10000 cases correct! ---");
//        else
//            $display("--- FAILED: Found %d errors ---", errors);
//
//        $finish;
//    end
//
//
//endmodule
`timescale 1ns/1ps

module testbench;

parameter FDATA_WIDTH = 32;
parameter CLK_PERIOD  = 10;
parameter MAX_VEC     = 1000000;

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
    .ina(fina),
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

   // sel = 5'd0;       // FADD
    frm = 3'd0;       // RNE

    #(CLK_PERIOD*10);
    rst = 0;

    file_in  = $fopen("fmul-rte.tmp","r");
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
            status = $fscanf(file_in,"%h %h %h %h %h\n",
                             fina, finb, exp_res, exp_flag, sel);

            if(status==5) begin

                // push queue
                exp_res_q[tail]  = exp_res;
                exp_flag_q[tail] = exp_flag;
                tail = tail + 1;
                vector_cnt = vector_cnt + 1;

                i_valid = 1;


                if(vector_cnt % 1000 == 0)
                    $display("[SEND] %0d vectors",vector_cnt);

            end
        end
    end

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
                          "[ERR] id=%0d got=%h %b exp=%h %b",
                          head,
                          fresult, fflags,
                          exp_res_q[head], exp_flag_q[head]);

            end

            head = head + 1;

            if(recv_cnt % 100 == 0)
                $display("[RECV] %0d results  error=%0d",
                         recv_cnt,error_cnt);

            // 自动结束
            if($feof(file_in) && recv_cnt == vector_cnt && vector_cnt!=0) begin

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
