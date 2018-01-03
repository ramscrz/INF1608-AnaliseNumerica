/* Lab 0: Matrizes
 * INF1608 - Análise Numérica
 * 2017.2
 * arquivo: matriz.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

// Cria dinamicamente uma matriz de dimensão m x n,
// onde m representa o número mde linhas e n representa o número de colunas.
double** mat_cria (int m, int n) {

	double** matrix = (double**) malloc(m * sizeof(double*));

	int i = 0, rows = 0, cols = 0;

	if(matrix == NULL) {
		printf("\nError: malloc failed while creating a matrix.\n");
		return NULL;
	}

	for(rows = 0; rows < m; rows++) {
		matrix[rows] = (double*) malloc(n * sizeof(double));

		if(matrix[rows] == NULL) {

			printf("\nError: malloc failed while creating a row in a matrix.\n");

			for(i = 0; i < rows; i++) {
				free(matrix[rows]);
			}

			free(matrix);
			return  NULL;
		}

		for(cols = 0; cols < n; cols++) {
			matrix[rows][cols] = 0;
		}
	}

	return matrix;

}

// Libera a memória de uma matriz A previamente criada de m linhas.
void mat_libera (int m, double** A) {

	int rows = 0;

	for(rows = 0; rows < m; rows++) {
		A[rows] = NULL;
		free(A[rows]);
	}

	free(A);
	A = NULL;

}

// Preenche a matriz T de dimensão n x m, matriz transposta da matriz A de dimensão m x n.
void mat_transposta (int m, int n, double** A, double** T) {

	int rows = 0;
	int cols = 0;

	for(rows = 0; rows < m; rows++) {
		for(cols = 0; cols < n; cols++) {
			T[cols][rows] = A[rows][cols];
		}
	}
	
}

// Preenche o vetor w de dimensão m com o resultado da multiplicação da matriz pelo vetor.
void mat_multv (int m, int n, double** A, double* v, double* w) {

	int rows = 0;
	int cols = 0;
	double accum = 0;

	for(rows = 0; rows < m; rows++) {
		for(cols = 0; cols < n; cols++) {
			accum += (v[cols] * A[rows][cols]);
		}
		w[rows] = accum;
		accum = 0;
	}

}

// Calcula a multiplicação de duas matrizes: C = AB. 
// A tem dimensão m x n, B tem dimensão n x q e C tem dimensão m x q.
void mat_multm (int m, int n, int q, double** A, double** B, double** C) {

	int rows = 0;
	int cols = 0;
	int bcols = 0;
	double accum = 0;

	for(rows = 0; rows < m; rows++) {
		for(bcols = 0; bcols < q; bcols++) {
			for(cols = 0; cols < n; cols++) {
				accum += (A[rows][cols] * B[cols][bcols]);
			}
			C[rows][bcols] = accum;
			accum = 0.0;
		}
	}

	

}

// Verifica se duas matrizes A e B são iguais, elemento a elemento, 
// considerando uma tolerância tol tal que a diferença entre dois elementos deve ser menor 
// que a tolerância para serem considerados iguais.
int mat_iguais (int m, int n, double** A, double** B, double tol) {

	int rows = 0;
	int cols = 0;

	for(rows = 0; rows < m; rows++) {
        for(cols = 0; cols < n; cols++) {
            double diff = A[rows][cols] - B[rows][cols];
			if(diff < -tol || diff > tol) {
				return 0;
			}
        }
    }

	return 1;
}

// Imprime a matriz A no formato format especificado. 
void mat_imprime (int m, int n, double** A, char* format) {

	int rows = 0;
	int cols = 0;

	for(rows = 0; rows < m; rows++) {
		printf("| \t");
		for(cols = 0; cols < n; cols++) {
			if(A[rows][cols] >= 0) {
				printf(" ");
			}
			printf(format, A[rows][cols]);
			printf("\t");
		}
		printf("|\n");
	}
}
