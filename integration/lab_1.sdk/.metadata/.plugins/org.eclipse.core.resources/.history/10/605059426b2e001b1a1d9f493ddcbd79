#include "platform.h"
#include <xil_io.h>

#define ADDR_GPIO	0x40000000

float abs(float a){
	if (a < 0)
		a *= -1;
	return a;
}

int ln(float x, float *y){
	if (x < 0)
		return -1;

	float res = 0;
	float a = 0;
	float b = (x - 1) / (x + 1);
	int k = 1;
	float pow_b = b;

	while (abs(a = pow_b / k) > 1e-4){
		res += a;
		k += 2;
		pow_b *= b * b;
	}

	*y = res * 2;
	return 0;
}

void log2(float x, float *y){
	const float LN2 = 0.69314718056;
	ln(x, y);
	*y /= LN2;
}

int main() {

	init_platform();

	float x[] = {0.5, 2.0, 8.0, 13.0};
	union {
		float f;
		int32_t i; } res;

	Xil_Out32(ADDR_GPIO, 0xfffffff8);

	for (int j = 0; j < 4; j++){
		log2(x[j], &res.f);
		Xil_Out32(ADDR_GPIO, res.i);
	}

	cleanup_platform();

  return 0;
}
