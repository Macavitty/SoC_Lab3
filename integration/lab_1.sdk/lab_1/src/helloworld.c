#include "platform.h"
#include <xil_io.h>

#define ADDR_GPIO	0x40000000

float abs(float a){
	if (a < 0)
		a *= -1;
	return a;
}

void log2(float x, float *y){
	const float LN2 = 0.69314718056;
	float a = 0;
	float b = (x - 1) / (x + 1);
	float pow_b = b;
	int k = 1;
	int loop_count = 21;
	*y = 0;
	// ln(x)
	for (int i = 0; i < loop_count; i++){
		a = pow_b / k;
		*y += a;
		k += 2;
		pow_b *= b * b;
	}
	*y += *y;

	// log2(x) = ln(x) / ln(2)
	*y /= LN2;
}

int main() {

	init_platform();

	float x[] = {0.5, 2.0, 8.0, 13.0};
	union {
		float f;
		int32_t i; } res;

	Xil_Out32(ADDR_GPIO, 0xffffffff);

	for (int j = 0; j < 4; j++){
		log2(x[j], &res.f);
		Xil_Out32(ADDR_GPIO, res.i);
	}

	cleanup_platform();

  return 0;
}
