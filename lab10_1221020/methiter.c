#include"methiter.h"
#include<stdio.h>
#include<math.h>

double norm2(int n, double* a, double* b) {

	double c = 0.0, diff = 0.0;
	int i = 0;

	for(i = 0; i < n; i++) {
		c = a[i] - b[i];
		diff += (c * c);
	}

	return sqrt(diff);
}

int Jacobi (int n, double** A, double* b, double* x, double tol) {

	double nx[n];
	double dif = tol + 1;
	int niter = 0, i = 0, j = 0;

	while(dif > tol) {

		dif = 0.0;

		for(i = 0; i < n; i++) {

			nx[i] = b[i];

			for(j = 0; j < n; j++) {

				if(j != i) {
					nx[i] -= (A[i][j] * x[j]);
				}
			}

			nx[i] /= A[i][i];
		}

		dif = norm2(n, x, nx);

		for(i = 0; i < n; i++) {
			x[i] = nx[i];
		}

		niter++;

	}

	return niter;
}

int GaussSeidel (int n, double** A, double* b, double* x, double tol) {

	double nx[n];
	double dif = tol + 1.0;
	int niter = 0, i = 0, j = 0;

	while(dif > tol) {

		niter++;

		dif = 0;

		for(i = 0; i < n; i++) {

			nx[i] = b[i];

			for(j = 0; j < n; j++) {

				if(j != i) {

					if(j > i) {
						// U (Triangular superior)
						nx[i] -= (A[i][j] * x[j]);
					} else {
						// L (Triangular inferior)
						nx[i] -= (A[i][j] * nx[j]);
					}

				}
			}

			nx[i] /= A[i][i];
		}

		dif = norm2(n, x, nx);

		for(i = 0; i < n; i++) {
			x[i] = nx[i];
		}
	}

	return niter;

}

int SOR (int n, double** A, double* b, double* x, double tol, double w) {

	double nx[n];
	double dif = tol + 1.0;
	int niter = 0, i = 0, j = 0;

	while(dif > tol) {

		niter++;

		dif = 0;

		for(i = 0; i < n; i++) {

			nx[i] = b[i];

			for(j = 0; j < n; j++) {

				if(j != i) {

					if(j > i) {
						// U (Triangular superior)
						nx[i] -= (A[i][j] * x[j]);
					} else {
						// L (Triangular inferior)
						nx[i] -= (A[i][j] * nx[j]);
					}
				}
			}

			nx[i] /= A[i][i];
			nx[i] = ((1 - w) * x[i]) + (w * nx[i]);
		}

      dif = norm2(n, x, nx);

      for(i = 0; i < n; i++) {
         x[i] = nx[i];
      }

	}

	return niter;

}


