/* Lab 4: Sistemas Lineares
 * INF1608 - Análise Numérica
 * 13/09/2017
 * arquivo: sistlinear.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *       
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "sistlinear.h"
#include "matriz.h"

void executaPivotamento(int rows, int cols, int j, double** A, int* p) {

	int pivot = j;
	int i, tmp;
	double tmpM = 0;
	i = tmp = 0; 

	for(i = j + 1; i < rows; i++) {

		if(fabs(A[i][j]) > fabs(A[pivot][j])) {
			pivot = i;
		}

	}

	if(pivot != j) {

		for(i = 0; i < cols; i++) {

			tmpM = A[pivot][i];
			A[pivot][i] = A[j][i];
			A[j][i] = tmpM;

		}

		tmp = p[j];
		p[j] = p[pivot];
		p[pivot] = tmp;

	}	
	
}

int* fatoracao(int n, double ** A) {

	int j, i, k = 0;
	int cols, rows;
	double f;
	int *p = (int*) malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		p[i] = i;
	}

	rows = n;
	cols = n;

	for(j = 0; j < cols - 1; j++) {

		executaPivotamento(rows, cols, j, A, p);

		for(i = j + 1; i < rows; i++) {

			f = A[i][j] / A[j][j];

			for(k = j + 1; k < cols; k++) {
				A[i][k] = A[i][k] - f * A[j][k];
			}

			A[i][j] = f;

		}

	}

	return p;
}

double* substituicao (int n, double** A, int* p, double* b) {

	double * Y = (double*) malloc(n * sizeof(double));
	double * X = (double*) malloc(n * sizeof(double));
	int rows, cols, i, j;
	double sum = 0;

	rows = cols = i = j = rows = n;

	// Determinação de y por substituição top-down.
	for(i = 0; i < rows; i++) {

		for(j = 0; j < i; j++) {
			sum += (A[i][j] * Y[j]);
		}

		Y[i] = b[p[i]] - sum;
		sum = 0;
	}

	// Determinação de x por substituição bottom-up.
	for(i = rows - 1; i >= 0; i--) {
		sum = 0;

		for(j = i + 1; j < cols; j++) {
			sum += (A[i][j] * X[j]);
		}

		X[i] = (Y[i] - sum) / A[i][i];
	}

	free(Y);
	Y = NULL;

	return X;

}
