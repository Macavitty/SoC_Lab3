`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/14/2020 11:47:14 AM
// Design Name: 
// Module Name: all_dev_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module all_dev_tb;

reg clk_100MHz;
reg UART_0_rxd = 0;
wire UART_0_txd;
reg reset_rtl = 1;
wire [31:0] gpio;

design_1_wrapper uut (
    .clk_100MHz(clk_100MHz),
    .rst_i(reset_rtl),
    .UART_0_rxd(UART_0_rxd),
    .UART_0_txd(UART_0_txd),
    .gpio_out(gpio)
);

initial begin
    clk_100MHz = 0;

    reset_rtl = 1;
    #100;
    reset_rtl = 0;
end
always begin
    #5;
    clk_100MHz = ~clk_100MHz;
end

endmodule
