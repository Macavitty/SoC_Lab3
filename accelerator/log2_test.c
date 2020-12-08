#include <stdio.h>
#include <stdlib.h>
#include "log2.h"

int main () {
	FILE *fin, *fout;

	int test_count = 0, k;
	float x;
	float res = 6;

	fin = fopen("in.dat", "r");
	fout = fopen("out.dat","w");

	fscanf(fin, "%d", &test_count);

	for (k = 0; k < test_count; k++){
		fscanf(fin, "\n%f\n", &x);

		l_log2(x, &res);
		fprintf(fout, "\n%f\n", res);
	}

	fclose(fin);
  	fclose(fout);

  printf ("Comparing against output data \n");
  if (system("diff -w out.dat out.gold.dat")) {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
	fprintf(stdout, "*******************************************\n");
     return 1;
  } else {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "PASS: The output matches the golden output!\n");
	fprintf(stdout, "*******************************************\n");
     return 0;
  }
  return 0;
}
