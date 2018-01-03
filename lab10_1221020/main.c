#include<stdio.h>
#include<stdlib.h>
#include"methiter.h"
#include<math.h>

void vetimprime (int n, double* A, char* format) {

	int cols = 0;

	printf("| ");
	for(cols = 0; cols < n; cols++) {
		printf(format, A[cols]);
		printf(" ");
	}
	printf("|\n");

	return;

}

int main() {

	double **A, *b, *x;
	double **AA, *bb, *xx;	
	int niter = 0, i = 0;
	double tol = pow(10.0, -7);

	A = (double**) malloc(2 * sizeof(double*));

	for(i = 0; i < 2; i++) {
		A[i] = (double*) malloc(2 * sizeof(double));	
	}

	AA = (double**) malloc(6 * sizeof(double*));

   for(i = 0; i < 6; i++) {
      AA[i] = (double*) malloc(6 * sizeof(double));  
   }

	b = (double*) malloc(2 * sizeof(double));
	x = (double*) malloc(2 * sizeof(double));
	bb = (double*) malloc(6 * sizeof(double));
	xx = (double*) malloc(6 * sizeof(double));

	A[0][0] = 3.0;
	A[0][1] = 1.0;
	A[1][0] = 1.0;
	A[1][1] = 2.0;
	
	x[0] = 0.0;
	x[1] = 0.0;

	b[0] = 5;
	b[1] = 5;

	AA[0][0] = 3.0;
	AA[0][1] = -1.0;
	AA[0][2] = 0.0;
	AA[0][3] = 0.0;
	AA[0][4] = 0.0;
	AA[0][5] = 0.5;
	AA[1][0] = -1.0;
	AA[1][1] = 3.0;
	AA[1][2] = -1.0;
	AA[1][3] = 0.0;
	AA[1][4] = 0.5;
	AA[1][5] = 0.0;
	AA[2][0] = 0.0;
	AA[2][1] = -1.0;
	AA[2][2] = 3.0;
	AA[2][3] = -1.0;
	AA[2][4] = 0.0;
	AA[2][5] = 0.0;
	AA[3][0] = 0.0;
	AA[3][1] = 0.0;
	AA[3][2] = -1.0;
	AA[3][3] = 3.0;
	AA[3][4] = -1.0;
	AA[3][5] = 0.0;
	AA[4][0] = 0.0;
	AA[4][1] = 0.5;
	AA[4][2] = 0.0;
	AA[4][3] = -1.0;
	AA[4][4] = 3.0;
	AA[4][5] = -1.0;
	AA[5][0] = 0.5;
	AA[5][1] = 0.0;
	AA[5][2] = 0.0;
	AA[5][3] = 0.0;
	AA[5][4] = -1.0;
	AA[5][5] = 3.0;

	for(i = 0; i < 6; i++) {
		xx[i] = 0.0;
	}

	bb[0] = 2.5;
	bb[1] = 1.5;
	bb[2] = 1.0;
	bb[3] = 1.0;
	bb[4] = 1.5;
	bb[5] = 2.5;

	xx[0] = 0.0;
	xx[1] = 0.0;
	xx[2] = 0.0;
	xx[3] = 0.0;
	xx[4] = 0.0;
	xx[5] = 0.0;

	printf("\n==== LAB10: Equacoes Diferenciais Ordinarias (EDO)====\n");
	printf("\nAutor: Rafael Azevedo Moscoso Silva Cruz, 1221020\n");

	niter = Jacobi (2, A, b, x, tol);
	printf("\n\nJacobi\t  Matriz A (2x2)  \t numero de iteracoes = %d \n\n", niter);

	vetimprime (2, x, "%.7g");

	x[0] = 0.0;
	x[1] = 0.0;

	niter = GaussSeidel (2, A, b, x, tol);
	printf("\n\nGauss-Seidel\t  Matriz A (2x2)  \t numero de iteracoes = %d \n\n", niter);

	vetimprime (2, x, "%.7g");

	x[0] = 0.0;
	x[1] = 0.0;

	niter = SOR (2, A, b, x, tol, 1.1);
	printf("\n\nSOR\t  Matriz A (2x2)  \t w = 1.1 \t numero de iteracoes = %d \n\n", niter);

	vetimprime (2, x, "%.7g");

	niter = Jacobi (6, AA, bb, xx, tol);
	printf("\n\nJacobi\t  Matriz A (6x6)  \t numero de iteracoes = %d \n\n", niter);

	vetimprime (6, xx, "%.7g");

	xx[0] = 0.0;
	xx[1] = 0.0;
	xx[2] = 0.0;
	xx[3] = 0.0;
	xx[4] = 0.0;
	xx[5] = 0.0;

	niter = GaussSeidel (6, AA, bb, xx, tol);
	printf("\n\nGauss-Seidel\t  Matriz A (6x6)  \t numero de iteracoes = %d \n\n", niter);

	vetimprime (6, xx, "%.7g");

	xx[0] = 0.0;
	xx[1] = 0.0;
	xx[2] = 0.0;
	xx[3] = 0.0;
	xx[4] = 0.0;
	xx[5] = 0.0;

	niter = SOR (6, AA, bb, xx, tol, 1.1);
	printf("\n\nSOR\t  Matriz A (6x6) \t w = 1.1 \t numero de iteracoes = %d \n\n", niter);

	vetimprime (6, xx, "%.7g");

	for(i = 0; i < 6; i++) {
		if(i < 2) {
			free(A[i]);
		}

		free(AA[i]);
	}

	free(b);
	free(bb);
	free(x);
	free(xx);
	free(A);
	free(AA);

	return 0;
}

