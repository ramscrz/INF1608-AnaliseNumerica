/* Lab 6: Método dos Mínimos Quadrados
 * INF1608 - Análise Numérica
 * 27/09/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<stdlib.h>
#include"mmq.h"
#include"matriz.h"
#include<math.h>

void vet_imprime(int n, double* V, char* format);
void executaPrimeiroTeste();
void executaSegundoTeste();

int main() {

	printf("\n\n========== TESTE DE MMQ (MÉTODO DOS MÍNIMOS QUADRADOS) ==========\n\n");

	printf("\n\n====== Primeiro Teste ======\n\n");

	executaPrimeiroTeste();

	printf("\n\n====== Segundo Teste ======\n\n");

	executaSegundoTeste();

	return 0;
}


void vet_imprime(int n, double* V, char* format) {

   int cols = 0;

   printf("| ");
   for(cols = 0; cols < n - 1; cols++) {

      printf(format, V[cols]);
      printf(" ; ");
   }

	printf(format, V[cols]);
   printf("\t|\n");
}


void executaPrimeiroTeste() {

	double 	**A	= mat_cria(5, 3);
	double 	*b		= (double*) malloc(5 * sizeof(double));
	double 	*x		= (double*) malloc(3 * sizeof(double));
	int 		i 		= 0;
	double 	r 		= 0;

	A[0][0] 	= 3;	A[0][1] 	= -1;	A[0][2] 	= 2;

	A[1][0] 	= 4;	A[1][1] 	= 1;	A[1][2] 	= 0;

	A[2][0] 	= -3;	A[2][1] 	= 2;	A[2][2] 	= 1;

	A[3][0] 	= 1;	A[3][1] 	= 1;	A[3][2] 	= 5;

	A[4][0] 	= -2;	A[4][1] 	= 0;	A[4][2] 	= 3;


	b[0] = 10;	b[1] = 10;	b[2] = -5;	b[3] = 15;	b[4]	= 0;


	x[0] = 0;	x[1] = 0;	x[2] = 0;

	mat_imprime (5, 3, A, "%.5g");

	printf("\n\t\t\t * \n");

	printf("|\tx1\t|\n|\tx2\t|\n|\tx3\t|\n\n");

	printf("\t\t\t=\n\n");

	vet_imprime(5, b, "%.5g");
	
	printf("\n===> RESULTADO <===\n\n");

	x = mmq(5, 3, A, b);

	vet_imprime(3, x, "%.5g");

	r = norma2(5, 3, A, b, x);

	printf("\n\nNorma-2 do Resíduo: %.7g\n\n", r);

	printf("\n\n------------------- OUTRO TESTE -------------------\n\n");

	free(x);
	x = (double*) malloc(4 * sizeof(double));

	mat_libera(5, A);

	A = mat_cria(5, 4);

	A[0][0] = 4; 	A[0][1] = 2; 	A[0][2] = 3; 	A[0][3] = 0;

	A[1][0] = -2; 	A[1][1] = 3;	A[1][2] = -1;	A[1][3] = 1;

	A[2][0] = 1;	A[2][1] = 3;	A[2][2] = -4;	A[2][3] = 2;

	A[3][0] = 1;	A[3][1] = 0;	A[3][2] = 1;	A[3][3] = -1;

	A[4][0] = 3;	A[4][1] = 1;	A[4][2] = 3;	A[4][3] = -2;


	b[0] = 10;	b[1] = 0;	b[2] = 2;	b[3] = 0;	b[4] = 5;


	for(i = 0; i < 4; i++) {
		x[i] = 0;
	}

	mat_imprime(5, 4, A, "%.5g");

	printf("\n * \n");

	printf("|\tx1\t|\n|\tx2\t|\n|\tx3\t|\n|\tx4\t|\n\n");

	printf("\n =\n\n");

	vet_imprime(5, b, "%.5g");

	printf("\n===> RESULTADO <===\n\n");

	x = mmq(5, 4, A, b);

	vet_imprime(4, x, "%.5g");

	r = norma2(5, 4, A, b, x);

	printf("\n\nNorma-2 do Resíduo: %.7g\n\n", r);

	free(b);
	b = NULL;
	free(x);
	x = NULL;

	mat_libera(5, A);

	return;
}

void executaSegundoTeste() {

	double** T = mat_cria(8, 1);
	double a = 0, b = 0;

	double c[8] = {0}, t[8] = {0};

	double ti = 0, r = 0, cr = 0;

	FILE *results = fopen("results.txt", "w"); 

	c[0] = 8; 
	c[1] = 12.3;
	c[2] = 15.5;
	c[3] = 16.8;
	c[4] = 17.1;
	c[5] = 15.8;
	c[6] = 15.2;
	c[7] = 14.0;

	t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 4;
	t[4] = 5;
	t[5] = 6;
	t[6] = 7;
	t[7] = 8;

	r = concentracao(8, t, c, &a, &b);

	printf("\n===> RESULTADO <===\n");

	printf("\nNorma-2 do Resíduo: %.7g\n", r);

	printf("\nCoeficientes: a = %.6g\tb = %.6g\n", a, b);

	printf("\n\n===== Pares (ti, ci) =====\n");

	for(ti = 0; ti < 16; ti = ti + 0.1) {

		cr = ti * a * exp(ti * b);

		printf("\n(%.3g, %.7g)", ti, cr);
		
		if(results != 0) {
			fprintf(results, "%lf,%.7g\n", ti, cr);
		}
	}

	mat_libera(8, T);

	if(results != 0) {
		fclose(results);
	}

	return;
}
