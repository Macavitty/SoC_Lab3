//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
//Date        : Sun Nov 22 22:18:52 2020
//Host        : DESKTOP-KGH6VBG running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (UART_0_rxd,
    UART_0_txd,
    clk_100MHz,
    gpio_out,
    rst_i);
  input UART_0_rxd;
  output UART_0_txd;
  input clk_100MHz;
  output [31:0]gpio_out;
  input rst_i;

  wire UART_0_rxd;
  wire UART_0_txd;
  wire clk_100MHz;
  wire [31:0]gpio_out;
  wire rst_i;

  design_1 design_1_i
       (.UART_0_rxd(UART_0_rxd),
        .UART_0_txd(UART_0_txd),
        .clk_100MHz(clk_100MHz),
        .gpio_out(gpio_out),
        .rst_i(rst_i));
endmodule
