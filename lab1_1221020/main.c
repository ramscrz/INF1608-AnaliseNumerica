/* Lab 1: Série de Taylor
 * INF1608 - Análise Numérica
 * 23/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

#include<assert.h>
#include"taylor.h"
#include<math.h>
#include<stdio.h>

int main(void) {

	// Testes sobre as funções implementadas usando série de taylor para aproximar funções matemáticas.
	int index = 0;
	double x = 0.0;

	// Testing Taylor Series Approximation for function cos(x)
	printf("\nTesting Taylor Series Approximation for function cos(x)...\n\n");
	for(index = 0; index < 30; index++) {
		x = index * 0.1;
		printf("Expected: %.8g \t Computed: %.8g \t Error: %.8g \t x = %.8g \n", 
					(double)cos(x), fcos(x), fcos_erro(x), x);

		assert(fabs(cos(x) - fcos(x)) < fcos_erro(x));
	}

	printf("Expected: %.8g \t Computed: %.8g \t Error: %.8g \t x = %.8g \n",
               (double)cos(M_PI), fcos(M_PI), fcos_erro(M_PI), M_PI);
	assert(fabs(cos(M_PI) - fcos(M_PI)) < fcos_erro(M_PI));

	// Testing Taylor Series Approximation for function cos(x)
	printf("\nTesting Taylor Series Approximation for function sqrt(x)...\n\n");
	for(index = 1; index < 100; index++) {
		x = index * 0.01 + 1.0;
		printf("Expected: %.8g \t Computed: %.8g \t Error: %.8g \t x = %.8g \n", 
               (double)sqrt(x), fsqrt(x), fsqrt_erro(x), x);
		assert(fabs(sqrt(x) - fsqrt(x)) < fsqrt_erro(x));
	}

	printf("Expected: %.8g \t Computed: %.8g \t Error: %.8g \t x = %.8g \n",
               (double)sqrt(2.0), fsqrt(2.0), fsqrt_erro(2.0), 2.0);
      assert(fabs(sqrt(2.0) - fsqrt(2.0)) < fsqrt_erro(2.0));

	return 0;
}
