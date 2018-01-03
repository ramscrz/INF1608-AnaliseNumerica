/* Lab 5: Interpolação Linear
 * INF1608 - Análise Numérica
 * 21/09/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */


#include"interp.h"
#include<stdio.h>
#include<math.h>
#include<assert.h>

#define PI 3.14159265358979323846

int main() {

	double *xi = 0, *bi = 0, result = 0;
	int i = 0, j = 0;
	int n = 6, m = 50;
	double a = 0;
	double b = PI/2.0;
	double nfact = 1;
	double error = 0, err = 0;
	double x = 0;
	double base = b/m;

	xi = Chebyshev(n, a, b);

	printf("\n\nAmostras de Chebyshev (n = %d):\n\n", n);
	for(i = 0; i < n; i++) {
		printf("xi[%d] em [0, PI/2] = %.16g\n", i, xi[i]);
	}

	bi = NewtonCoef(n, xi, cos);

	printf("\nCoeficientes do Polinômio Interpolante por Diferenças de Newton (n = %d):\n\n", n);
	for(i = 0; i < n; i++) {
		printf("bi[%d] = %.16g\n", i, bi[i]);
	}

	nfact = 1;
	for(i = n; i > 0; i--) {
		nfact *= i;
	}

	for(j = 0; j < m; j++) {
	
		x = j * base;

		result = NewtonAval(n, xi, bi, x);

		printf("\ncos(%lf) por interpolação =  %.16g\ncos(%lf) real = %.16g\n", x, fabs(result), x, cos(x));

		err = fabs(cos(x) - result);
		error = (pow( ((b - a)/2.0), n) / pow(2.0, n - 1)) * ( 1 / nfact ); 

		printf("\nerror =  %.16g\n|real - obtido| = %.16g\n\n", error, err);

		assert(err < error);

	}
	
	return 0;
}


