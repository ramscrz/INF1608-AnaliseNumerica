/* Lab 11: Gradientes Conjugados
 * INF1608 - Análise Numérica
 * 01/11/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<stdlib.h>
#include"gradconj.h"
#include"matriz.h"

int main() {

	double x[] = {0.9, 0.9, 0.5};
	double tol = 0.01;

	double **A = (double**) malloc ( 3 * sizeof(double*));
	double b[3];

	int iter = 0, i = 0;

	printf("\n==== LAB11: Gradientes Conjugados ====\n");
	printf("\nAutor: Rafael Azevedo Moscoso Silva Cruz, 1221020\n");

	if(A == NULL) {
		printf("\n\nMalloc Error: matrix A could not be allocated.\n\n");
		exit(1);
	}

	for(i = 0; i < 3; i++) {
		A[i] = (double*) malloc(3 * sizeof(double));
	}

	A[0][0] = 1;
	A[0][1] = -1;
	A[0][2] = 0;
	A[1][0] = -1;
	A[1][1] = 2;
	A[1][2] = 1;
	A[2][0] = 0;
	A[2][1] = 1;
	A[2][2] = 2;

	b[0] = 0;
	b[1] = 2;
	b[2] = 3;

	iter = GradienteConjugado(3, A, b, x, tol);

	printf("\nFirst Matrix A (tol = 0.1, 3x3, x = {0.9, 0.9, 0.5})\n\n");
	mat_imprime (3, 3, A, "%.8g");
	for(i = 0; i < 3; i++) {
		printf("\n\tx[%d] = %.16g", i, x[i]);
	}
	printf("\n\n\tNumber of iterations = %d\n\n", iter);

	A[0][0] = 1;
	A[0][1] = -1;
	A[0][2] = 0;
	A[1][0] = -1;
	A[1][1] = 2;
	A[1][2] = 1;
	A[2][0] = 0;
	A[2][1] = 1;
	A[2][2] = 5;

	b[0] = 3;
	b[1] = -3;
	b[2] = 4;

	x[0] = 0.9;
	x[1] = 0.9;
	x[2] = 0.5;

	iter = GradienteConjugado(3, A, b, x, tol);

	printf("\nSecond Matrix A (tol = 0.1, 3x3, x = {0.9, 0.9, 0.5})\n\n");
	mat_imprime (3, 3, A, "%.8g");
	for(i = 0; i < 3; i++) {
		printf("\n\tx[%d] = %.16g", i, x[i]);
	}
	printf("\n\n\tNumber of iterations = %d\n\n", iter);

	for(i = 0; i < 3; i++) {
      free(A[i]);
		A[i] = NULL;
   }

	free(A);
	A = NULL;

	return 0;

}
