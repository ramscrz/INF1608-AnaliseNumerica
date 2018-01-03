/* Lab 6: Método dos Mínimos Quadrados
 * INF1608 - Análise Numérica
 * 27/09/2017
 * arquivo: mmq.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include"mmq.h"
#include"matriz.h"
#include"sistlinear.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double* mmq(int m, int n, double** A, double* b) {

	double** At 	= (double**) malloc(n * sizeof(double*));
	double** AtA 	= (double**) malloc(n * sizeof(double*));
	double*  W 		= (double* ) malloc(m * sizeof(double));
	double* result = 0;
	int *p		= 0;
	int i 		= 0;

	for(i = 0; i < n; i++) {
		At[i]	= (double*) malloc(m * sizeof(double));
		AtA[i] 	= (double*) malloc(n * sizeof(double));
	}

	mat_transposta(m, n, A, At);

	mat_multm(n, m, n, At, A, AtA);

	mat_multv(n, m, At, b, W);

	p = fatoracao(n, AtA);
	
	result = substituicao(n, AtA, p, W);

	free(W);
	W = NULL;

	for(i = 0; i < n; i++) {
		free(At[i]);
		At[i] = NULL;
		free(AtA[i]);
		AtA[i] = NULL;
	}

	return result;

}

double norma2(int m, int n, double** A, double* b, double* x) {

	double* W 	= (double*) malloc(m * sizeof(double));
	double sum 	= 0.0;
	
	int i = 0;
	double r = 0.0;

	mat_multv(m, n, A, x, W);

	for(i = 0; i < m; i++) {

		r = b[i] - W[i];

		sum += (r * r);

	}

	free(W);
	W = NULL;

	return sqrt(sum);
}

/* 
 * Modelo: c = a t exp(bt)
 *
 * Equivalente a: log(c) = log(a) + log(t) + bt
 *                bt + log(a) = log(c) - log(t)
 *
 * | t[1]  1 |                    | log(c[1]) - log(t[1]) |
 * | t[2]  1 |     |   b    |     | log(c[2]) - log(t[2]) |
 * | ...   1 |     |        |     |          ...          |
 * | t[i]  1 |  *  |        |  =  | log(c[i]) - log(t[i]) |
 * | ...   1 |     | log(a) |     |          ...          |
 * | t[n]  1 |                    | log(c[n]) - log(t[n]) |
 *
 *
 * T * x = v
 *
 */
double concentracao(int n, double* t, double* c, double* pa, double* pb) {

	double**  T = mat_cria(n, 2);
	double*   v = (double*) malloc(n * sizeof(double));
	double*   x = (double*) malloc(2 * sizeof(double));
	
	double r = 0;

	int i = 0;

	for(i = 0; i < n; i++) { 

		T[i][0] = t[i];  
		T[i][1] = 1;

		v[i] = log(c[i]) - log(t[i]);

	}

	x = mmq(n, 2, T, v);

	*pa = exp(x[1]);
	*pb = x[0];

	r = norma2(n, 2, T, v, x);

	mat_libera(n, T);

	free(v);
	v = NULL;
	free(x);
	x = NULL;

	return r;

}
