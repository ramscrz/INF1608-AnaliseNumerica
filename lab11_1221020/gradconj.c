/* Lab 11: Gradientes Conjugados
 * INF1608 - Análise Numérica
 * 01/11/2017
 * arquivo: gradconj.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<stdlib.h>
#include"gradconj.h"
#include"matriz.h"
#include<math.h>

double norma2(int n, double* r);
void arrayMultByValue(int n, double* a, double c, double* result);
double arrayTMult(int n, double* a, double* b);
double* arraySubtraction(int n, double* a, double* b);
void arraySum(int n, double* a, double* b);

int GradienteConjugado(int n, double** A, double* b, double* x, double tol) {

	double* Ax = (double*) malloc (n * sizeof(double));
	double* tmp = (double*) malloc (n * sizeof(double));
	double* Ad = (double*) malloc (n * sizeof(double));
	double* nr = (double*) malloc (n * sizeof(double));
	double* d = NULL;
	double* r = NULL;

	int k = 0, i = 0;	
	double norma2r = 0.0, alpha = 0.0, beta = 0.0, rtr = 0.0;

	if(Ax == NULL || tmp == NULL || Ad == NULL) {
		printf("\nMalloc error: memory allocation for Ax failed.\n");
		exit(1);
	}

	mat_multv (n, n, A, x, Ax); // Determine A * x.

	d = arraySubtraction(n, b, Ax);
	r = arraySubtraction(n, b, Ax);

	if(d == NULL || r == NULL) {
		printf("\nMalloc error: memory allocation for d and/or r failed.\n");
		exit(1);
	}

	norma2r = norma2(n, r);
	
	while(k < n && norma2r >= tol) {

		mat_multv(n, n, A, d, Ad);				// Calculate A * dk.
		rtr = arrayTMult(n, r, r); 			// Calculate r[k] * r[k]T.
		alpha = rtr / arrayTMult(n, Ad, d); // Determine Alpha = (r[k] * r[k]T) / (d[k]T * A * d[k]).

		arrayMultByValue(n, d, alpha, tmp);	// Determine Alpha * d[k].
		arraySum(n, tmp, x); 					// Determine x[k+1] = x[k] + (Alpha * d[k]).
														// x[k] is updated and becomes x[k + 1].

		arrayMultByValue(n, Ad, alpha, nr); // Determine Alpha * A * d[k].

		// Determine r[k + 1] = r[k] - Alpha * A * d[k].
		for(i = 0; i < n; i++) {
			r[i] -= nr[i];
		}

		beta = arrayTMult(n, r, r) / rtr;	// Determine Beta = (r[k+1]T * r[k+1]) / (r[k] * r[k]T).
		arrayMultByValue(n, d, beta, d); 	// Determine d[k+1] = Beta * d.
		arraySum(n, r, d);						// Determine d[k + 1] = d[k + 1] + r[k+1].

		norma2r = norma2(n, r);					// Update Norm2(r).

		k++;											// Go to next iteration.
	}

	free(Ax);
	Ax = NULL;
	free(tmp);
	tmp = NULL;
	free(Ad);
	Ad = NULL;
	free(nr);
	nr = NULL;
	free(d);
	d = NULL;
	free(r);
	r = NULL;

	return k;
}

double norma2(int n, double* r) {

	double diff = 0.0;
	int i = 0;

	if(r == NULL) {
		printf("\nnorm2 Error: r is NULL.\n");
		return -1;
	}

	for(i = 0; i < n; i++) {
		diff += (r[i] * r[i]);
	}

	return sqrt(diff);
}

void arrayMultByValue(int n, double* a, double c, double* result) {

	int i = 0;

	if(result == NULL) {
		printf("\narrayMultByValue Error: result is NULL.\n");
		return;
	}

	for(i = 0; i < n; i++) {
		result[i] = a[i] * c;
	}

	return;
}

double arrayTMult(int n, double* a, double* b) {

	double result = 0.0;

	int i = 0;

	if(a == NULL || b == NULL) {
		printf("\narrayTMult Error: a and/or b are NULL.\n");
		return -1;
	}

	for(i = 0; i < n; i++) {
		result += (a[i] * b[i]);
	}

	return result;

}

double* arraySubtraction(int n, double* a, double* b) {

	double* result = (double*) malloc (n * sizeof(double));

	if(result == NULL) {
		printf("\nMalloc error (arraySubtraction function)!\n");
		return NULL;
	}
   
	int i = 0;

	for(i = 0; i < n; i++) {
		result[i] = a[i] - b[i];
	}

	return result;

}

void arraySum(int n, double* a, double* b) {

	int i = 0;

	if(a == NULL || b == NULL) {
		printf("\narrayTMult Error: a and/or b are NULL.\n");
		return;
	}

	for(i = 0; i < n; i++) {
		b[i] += a[i];
	}

	return;

}
