// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (lin64) Build 2552052 Fri May 24 14:47:09 MDT 2019
// Date        : Fri May 29 00:02:42 2020
// Host        : LAPTOP-96NLHABC running 64-bit Ubuntu 16.04.6 LTS
// Command     : write_verilog -force -mode synth_stub
//               /mnt/f/2019pt1_vivado_WSL/Vivado_projects/HOG_SVM2/HOG_SVM2.srcs/sources_1/bd/design_1/ip/design_1_clk_wiz_1_0/design_1_clk_wiz_1_0_stub.v
// Design      : design_1_clk_wiz_1_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a200tsbg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module design_1_clk_wiz_1_0(clk_out1, resetn, locked, clk_in1_p, clk_in1_n)
/* synthesis syn_black_box black_box_pad_pin="clk_out1,resetn,locked,clk_in1_p,clk_in1_n" */;
  output clk_out1;
  input resetn;
  output locked;
  input clk_in1_p;
  input clk_in1_n;
endmodule
