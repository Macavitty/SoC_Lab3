// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "C:/Users/mavity/VivadoProjects/soc3/accelerator/log2.c"
# 1 "C:/Users/mavity/VivadoProjects/soc3/accelerator/log2.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/mavity/VivadoProjects/soc3/accelerator/log2.c" 2
# 1 "C:/Users/mavity/VivadoProjects/soc3/accelerator/log2.h" 1



void l_log2(float x, float *y);
# 2 "C:/Users/mavity/VivadoProjects/soc3/accelerator/log2.c" 2
void l_log2(float x, float *y){
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
 const float LN2 = 0.69314718056;
 float a = 0;
 float b = (x - 1) / (x + 1);
 int k = 1;
 int loop_count = 21;
 float pow_b = b;

 float tmp_y = 0;


 for (int i = 0; i < loop_count; i++){
#pragma HLS PIPELINE II=4
 a = pow_b / k;
  tmp_y += a;
  k += 2;
  pow_b *= b * b;
 }


 *y = (tmp_y + tmp_y) / LN2;
}
