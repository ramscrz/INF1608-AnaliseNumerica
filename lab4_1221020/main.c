/* Lab 4: Sistemas Lineares
 * INF1608 - Análise Numérica
 * 13/09/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include"matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include"sistlinear.h"

int main(void) {

	double** A = mat_cria(3, 3);
	double bA[] = {3, 3, -6};
	
	double** B = mat_cria(6, 6);
	double bB[] = {2.5, 1.5, 1.0, 1.0, 1.5, 2.5};

	double** C = mat_cria(2, 2);
	double bC[] = {3, -5};

	double** D = mat_cria(3, 3);
	double bD[] = {0, 4, 17};

	double** E = mat_cria(6, 6);
	double bE[] = {3, 6, 8, 1, 3, -1};
	
	int* pA, *pB, *pC, *pD, *pE;
	double* xA, *xB, *xC, *xD, *xE;

	double vet[] = {1.0, 2.0, 2.0, 3.0};
	double w[4] = {0};
	int rows = 0;
	int cols = 0;
	int i = 0;
	
	C[0][0] = 3.0;
	C[0][1] = 1.0;
	C[1][0] = -6.0;
	C[1][1] = -4.0;

	
	D[0][0] = 3.0;
	D[0][1] = 1.0;
	D[0][2] = 6.0;
	D[1][0] = -6.0;
	D[1][1] = 0;
	D[1][2] = -16.0;
	D[2][0] = 0;
	D[2][1] = 8.0;
	D[2][2] = -17.0;

	A[0][0] = 1.0;
	A[0][1] = 2.0;
	A[0][2] = -1.0;

	A[1][0] = 2.0;
	A[1][1] = 1.0; 
	A[1][2] = -2.0;

	A[2][0] = -3.0;
	A[2][1] = 1.0;
	A[2][2] = 1.0;

	B[0][0] = 3.0;
	B[0][1] = -1.0;
	B[0][2] = 0;
	B[0][3] = 0;
	B[0][4] = 0;
	B[0][5] = 0.5;

	B[1][0] = -1.0; 
	B[1][1] = 3.0; 
	B[1][2] = -1.0; 
	B[1][3] = 0; 
	B[1][4] = 0.5;
	B[1][5] = 0;

	B[2][0] = 0;
	B[2][1] = -1.0;      
	B[2][2] = 3.0;     
	B[2][3] = -1.0;     
	B[2][4] = 0;
	B[2][5] = 0;

	B[3][0] = 0;
	B[3][1] = 0;      
	B[3][2] = -1.0;     
	B[3][3] = 3.0;     
	B[3][4] = -1.0;
	B[3][5] = 0;

	B[4][0] = 0;
	B[4][1] = 0.5;      
	B[4][2] = 0;     
	B[4][3] = -1.0;     
	B[4][4] = 3.0;
	B[4][5] = -1.0;

	B[5][0] = 0.5;
	B[5][1] = 0;      
	B[5][2] = 0;
	B[5][3] = 0;     
	B[5][4] = -1.0;
	B[5][5] = 3.0;

	E[0][0] = 0;
	E[0][1] = -1.0;
	E[0][2] = 0;
	E[0][3] = 0;
	E[0][4] = 0;
	E[0][5] = 0.5;

	E[1][0] = -1.0;
	E[1][1] = 0;	
	E[1][2] = -1.0;
	E[1][3] = 0;
	E[1][4] = 0.5;
	E[1][5] = 0;

	E[2][0] = 0;
	E[2][1] = -1.0;
	E[2][2] = 0;
	E[2][3] = -1.0;
	E[2][4] = 0;
	E[2][5] = 0;

	E[3][0] = 0;
	E[3][1] = 0;
	E[3][2] = -1.0;
	E[3][3] = 0;
	E[3][4] = -1.0;
	E[3][5] = 0;

	E[4][0] = 0;
	E[4][1] = 0.5;
	E[4][2] = 0;
	E[4][3] = -1.0;
	E[4][4] = 0;	
	E[4][5] = -1.0;

	E[5][0] = 0.5;
	E[5][1] = 0;      
	E[5][2] = 0;      
	E[5][3] = 0;     
	E[5][4] = -1.0;
	E[5][5] = 0;
		
	printf("\n \n Matriz A: \n \n");
	mat_imprime(3, 3, A, "%.5g");
	printf("\n \n Matriz bA: \n \n");
	vet_imprime(3, bA, "%.5g");
	printf("\n \n");
	printf("\n \n Matriz B: \n \n");
	mat_imprime(6, 6, B, "%.5g");
	printf("\n \n Matriz bB: \n \n");
	vet_imprime(6, bB, "%.5g");
	printf("\n \n");
	printf("\n \n Matriz C: \n \n");
	mat_imprime(2, 2, C, "%.5g");
	printf("\n \n Matriz bC: \n \n");
	vet_imprime(2, bC, "%.5g");
	printf("\n \n");
	printf("\n \n Matriz D: \n \n");
	mat_imprime(3, 3, D, "%.5g");
	printf("\n \n Matriz bD: \n \n");
	vet_imprime(3, bD, "%.5g");
	printf("\n \n");
	printf("\n \n Matriz E: \n \n");
	mat_imprime(6, 6, E, "%.5g");
	printf("\n \n Matriz bE: \n \n");
	vet_imprime(6, bE, "%.5g");
	printf("\n \n");

	pA = fatoracao(3, A);
	pB = fatoracao(6, B);
	pC = fatoracao(2, C);
	pD = fatoracao(3, D);
	pE = fatoracao(6, E);

	printf("\n \n Matriz A Fatorada: \n \n");
	mat_imprime(3, 3, A, "%.3g");
	printf("|\t");
	for(i = 0; i < 3; i++) {
		printf("%d\t", pA[i]);
	}

	printf("|\n");

	printf("\n \n Matriz B Fatorada: \n \n");
	mat_imprime(6, 6, B, "%.3g");
	printf("|\t");
	for(i = 0; i < 6; i++) {
		printf("%d\t", pB[i]);
	}
	printf("|\n");

	printf("\n \n Matriz C Fatorada: \n \n");
	mat_imprime(2, 2, C, "%.3g");
	printf("|\t");
	for(i = 0; i < 2; i++) {
		printf("%d \t", pC[i]);
	}
	printf("|\n");

	xC = substituicao (2, C, pC, bC);

	printf("\n \n Solução da Matriz C: xC\n \n");
	vet_imprime(2, xC, "%.3g");

	C[1][0] = 3.0;
	C[1][1] = 1.0;
	C[0][0] = -6.0;
	C[0][1] = -4.0;

	printf("\n \n Matriz C Alterada: \n \n");
	mat_imprime(2, 2, C, "%.3g");
	printf("|\t");
	for(i = 0; i < 2; i++) {
		printf("%d\t", pC[i]);
	}
	printf("|\n");

	pC = fatoracao(2, C);

	xC = substituicao (2, C, pC, bC);

	printf("\n \n Solução da Matriz C Alterada: xC\n \n");
	vet_imprime(2, xC, "%.3g");

	printf("\n \n Matriz D Fatorada: \n \n");
	mat_imprime(3, 3, D, "%.3g");
	printf("|\t");
	for(i = 0; i < 3; i++) {
		printf("%d \t", pD[i]);
	}
	printf("\n");

	printf("\n \n Matriz E Fatorada: \n \n");
	mat_imprime(6, 6, E, "%.3g");
	printf("|\t");
	for(i = 0; i < 6; i++) {
		printf("%d\t", pE[i]);
	}
	printf("|\n");

	xA = substituicao (3, A, pA, bA);
	
	printf("\n \n Solução da Matriz A: xA\n \n");
	vet_imprime(3, xA, "%.3g");

	xB = substituicao (6, B, pB, bB);

	printf("\n \n Solução da Matriz B: xB\n \n");
	vet_imprime(6, xB, "%.3g");

	xD = substituicao(3, D, pD, bD);

	printf("\n \n Solução da Matriz D: xD\n \n");
	vet_imprime(3, xD, "%.3g");

	xE = substituicao(6, E, pE, bE);

	printf("\n \n Solução da Matriz E: xD\n \n");
	vet_imprime(6, xE, "%.3g");

	free(A);
	A = NULL;
	free(B);
	B = NULL;
	free(C);
	C = NULL;
	free(D);
	D = NULL;
	free(E);
	E = NULL;

	free(pA);
	pA = NULL;
	free(pB);
	pB = NULL;
	free(pC);
	pC = NULL;
	free(pD);
	pD = NULL;
	free(pE);
	pE = NULL;

	free(xA);
	xA = NULL;
	free(xB);
	xB = NULL;
	free(xC);
	xC = NULL;
	free(xD);
	xD = NULL;
	free(xE);
	xE = NULL;

	return 0;
}

