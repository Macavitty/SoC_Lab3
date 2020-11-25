#include "platform.h"
#include <xil_io.h>
#include <stdio.h>

#define DEBUG_ 0

#define ADDR_GPIO_BASE 0x40000000

#define N_LETTER 0x7FEA //0b[AN7..1][dot][A][B][C]_[D][E][F][G]
#define A_LETTER 0x7F88
#define B_LETTER 0x7FE0
#define C_LETTER 0x7FB1

void get_matrix_size(s32 * n) {
	if (DEBUG_) {
		*n = 5;
	} else {
		xil_printf("Enter the matrix size\n");
		scanf("%d", n);
	}
}

void get_matrix(s32 n, s32 * a) {
	u8 i;
	u8 j;
	if (DEBUG_) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				a[i*n + j] = j;
			}
		}
	} else {
		for (i = 0; i < n; ++i) {
					for (j = 0; j < n; ++j) {
						xil_printf("Enter matrix[%d][%d]\n", i, j);
						scanf("%d", &a[i*n + j]);
					}
				}
	}
}

void get_result_matrix(s32 n, const s32 * a, const s32 * b, s32 * c) {
	u8 i;
	u8 j;
	u8 k;
	for (i = 0; i < n; ++i) {
	        for (j = 0; j < n; ++j) {
	            c[i*n + j] = 0;
	            for (k = 0; k < n; ++k) {
	                c[i*n + j] += a[i*n + k] * b[k*n + j];
	            }
	        }
	    }
}

void print_matrix(s32 n, s32 * a) {
	u8 i;
	u8 j;
	if (DEBUG_) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				Xil_Out16(ADDR_GPIO_BASE, a[i*n + j]);
			}
		}
	} else {
		for (i = 0; i < n; ++i) {
			xil_printf("[%d] = { ", i);
					for (j = 0; j < n; ++j) {
						xil_printf("%d ", a[i*n + j]);
					}
					xil_printf("}\n");
				}
	}
}

int main() {

	init_platform();

	s32 n;
	s32 matrix_a[100];
	s32 matrix_b[100];
	s32 matrix_c[100];

	while (1) {

	Xil_Out16(ADDR_GPIO_BASE, N_LETTER);
	get_matrix_size(&n);
	if (n < 5 || n > 10) {
		if (!DEBUG_)
			xil_printf("Matrix size should be in this bounds: [5;10]\n");
		continue;
	}

	xil_printf("n = %d\n", n);

	Xil_Out16(ADDR_GPIO_BASE, A_LETTER);
	if (!DEBUG_)
		xil_printf("Enter matrix A\n");
	get_matrix(n, matrix_a);

	xil_printf("--MATRIX A--\n");
	print_matrix(n, matrix_a);

	Xil_Out16(ADDR_GPIO_BASE, B_LETTER);
	if (!DEBUG_)
		xil_printf("Enter matrix B\n");
	get_matrix(n, matrix_b);

	xil_printf("--MATRIX B--\n");
	print_matrix(n, matrix_b);

	get_result_matrix(n, matrix_a, matrix_b, matrix_c);
	Xil_Out16(ADDR_GPIO_BASE, C_LETTER);
	xil_printf("--MATRIX C--\n");
	print_matrix(n, matrix_c);

	}

    cleanup_platform();

  return 0;
}
