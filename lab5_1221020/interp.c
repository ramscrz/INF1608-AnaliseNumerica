/* Lab 5: Interpolação Linear
 * INF1608 - Análise Numérica
 * 21/09/2017
 * arquivo: interp.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *
 */


#include"interp.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

#define PI 3.14159265358979323846

// Determina n amostras de Chebyshev no intervalo [a, b]
double* Chebyshev(int n, double a, double b) {

	double* x = (double*) malloc (n * sizeof(double) );
	double p = (b - a) / 2, c = (a + b) / 2;
	int i = 0, beta = 1;
	double d = 2 * n;

	for(i = 0; i < n; i++) {
		x[i] = p * cos( (beta * PI) / d ) + c;
		beta = beta + 2;
	}

	return x;

}

// Determina os n coeficientes de Newton.
double* NewtonCoef(int n, double* xi, double (*f) (double)) {

	double* b = (double*) malloc(n * sizeof(double));
	double** B = (double**) malloc(n * sizeof(double*));
	int i = 0, j = 0;

	for(i = 0; i < n; i++) {

		B[i] = (double*) malloc(n * sizeof(double));

	}

	for(i = 0; i < n; i++) {

		for(j = i; j >= 0; j--) {

			if(i == j) {
				B[j][i] = f(xi[i]);
			} else {
				B[j][i] = (B[j + 1][i] - B[j][i - 1]) / (xi[i] - xi[j]);
			}

		}

		b[i] = B[0][i];
	}

	for(i = 0; i < n; i++) {
		free(B[i]);
		B[i] = NULL;
	}

	free(B);
	B = NULL;

	return b;

}

// Avalia um polinômio de Newton em um ponto x dado.
double NewtonAval(int n, double *xi, double* bi, double x) {

	int i = 0;
	double result = bi[0];
	double cache = 1;

	for(i = 1; i < n; i++) {
		cache *= (x - xi[i - 1]);
		result += bi[i] * cache;
	}

	return result;

}
