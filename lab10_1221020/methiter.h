#ifndef METHITER_H
#define METHITER_H

int Jacobi (int n, double** A, double* b, double* x, double tol);

int GaussSeidel (int n, double** A, double* b, double* x, double tol);

int SOR (int n, double** A, double* b, double* x, double tol, double w);


#endif
