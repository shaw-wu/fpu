`timescale 1ns / 1ps
module testbench;
    // 参数定义（与你的模块一致）
    parameter FDATA_WIDTH = 32;
    parameter FRM_BITS    = 3;
    parameter CLK_PERIOD  = 10;

    // 信号定义
    reg clk;
    reg rst;
    reg i_valid;
    wire i_ready;
    reg [4:0] sel;
    reg [FRM_BITS-1:0] frm;
    reg [FDATA_WIDTH-1:0] fina;
    reg [FDATA_WIDTH-1:0] finb;
    //reg [31:0] ina; // 暂时设为32，可根据需求修改
    
    wire o_valid;
    reg o_ready;
    wire [4:0] fflags;
    wire [FDATA_WIDTH-1:0] fresult;

    // 测试向量与日志文件句柄
    integer file_in, file_log;
    integer status;
    reg [FDATA_WIDTH-1:0] exp_res;
    reg [4:0] exp_fflags;
    integer vector_cnt = 0;
    integer error_cnt = 0;

    // 实例化被测设计 (DUT)
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

    // 时钟生成
    initial clk = 0;
    always #(CLK_PERIOD/2) clk = ~clk;

    // 主测试逻辑
    initial begin
        // 初始化信号
        rst = 1;
        i_valid = 0;
        sel = 5'b00000; // 假设 0 是加法，根据你具体的逻辑修改
        frm = 3'b000;
        fina = 0;
        finb = 0;
        //ina = 0;
        o_ready = 1;

        // 打开文件
        file_in = $fopen("fadd-rte.tmp", "r");
        file_log = $fopen("log.tmp", "w");

        if (file_in == 0 || file_log == 0) begin
            $display("错误：无法打开测试文件或日志文件！");
            $finish;
        end

        $fdisplay(file_log, "--- FPU 自动化测试开始 ---");
        $display("开始读取测试向量...");

        // 复位释放
        #(CLK_PERIOD * 5);
        rst = 0;
        #(CLK_PERIOD * 2);

        // 循环读取测试向量
        // 格式: [fina finb res fflags]
        while (!$feof(file_in)) begin
            status = $fscanf(file_in, "%h %h %h %h\n", fina, finb, exp_res, exp_fflags);
            //status = $fscanf(file_in, "%h %h %h\n", fina, exp_res, exp_fflags);
            
            if (status == 4) begin
                vector_cnt = vector_cnt + 1;
                
                // 发起握手请求
                i_valid = 1;
                wait(i_ready); // 等待 DUT 准备好
                @(posedge clk);
                #1; // 模拟些许延迟
                i_valid = 0;

                // 等待结果输出
                wait(o_valid);
                @(posedge clk);
                
                // 比对结果
                if (fresult !== exp_res || fflags !== exp_fflags) begin
                    error_cnt = error_cnt + 1;
                    $fdisplay(file_log, "[Error] Vector %0d: A=%h, B=%h | Got: Res=%h, Flg=%b | Exp: Res=%h, Flg=%b", 
                              vector_cnt, fina, finb, fresult, fflags, exp_res, exp_fflags);
                end else begin
                    $fdisplay(file_log, "[Pass] Vector %0d", vector_cnt);
                end
                
                //if (fresult !== exp_res || fflags !== exp_fflags) begin
                //    error_cnt = error_cnt + 1;
                //    $fdisplay(file_log, "[Error] Vector %0d: A=%h | Got: Res=%h, Flg=%b | Exp: Res=%h, Flg=%b", 
                //              vector_cnt, fina, fresult, fflags, exp_res, exp_fflags);
                //end else begin
                //    $fdisplay(file_log, "[Pass] Vector %0d", vector_cnt);
                //end


                if (vector_cnt % 100 == 0) begin
                    if(vector_cnt > 2500) break;
                    $display("已处理 %0d 条测试向量...", vector_cnt);
                end
            end
        end

        // 结束报告
        $display("---------------------------------------");
        $display("测试完成！总数: %0d, 错误数: %0d", vector_cnt, error_cnt);
        $display("详情请查看 simulation.log");
        $fdisplay(file_log, "--- 测试结束 | 总计: %0d, 错误: %0d ---", vector_cnt, error_cnt);
        
        $fclose(file_in);
        $fclose(file_log);
        $finish;
    end

endmodule
