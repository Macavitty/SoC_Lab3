void log2(float x, float *y){
	#pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE s_axilite port=y
	#pragma HLS INTERFACE s_axilite port=x
	const float LN2 = 0.69314718056;
	float a = 0;
	float b = (x - 1) / (x + 1);
	int k = 1;
	int loop_count = 21;
	float pow_b = b;

	*y = 0;

	// ln(x)
	for (int i = 0; i < loop_count; i++){
	#pragma HLS PIPELINE II=4
		a = pow_b / k;
		*y += a;
		k += 2;
		pow_b *= b * b;
	}

	*y += *y;

	// log2(x) = ln(x) / ln(2)
	*y /= LN2;
}
