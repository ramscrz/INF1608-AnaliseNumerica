#ifndef INTERP_H
#define INTERP_H

/* Lab 5: Interpolação Linear
 * INF1608 - Análise Numérica
 * 21/09/2017
 * arquivo: interp.h
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 * 
 */

// Determina n amostras de Chebyshev no intervalo [a, b]
double* Chebyshev(int n, double a, double b);

// Determina os n coeficientes de Newton.
double* NewtonCoef(int n, double* xi, double (*f) (double));

// Avalia um polinômio de Newton em um ponto x dado.
double NewtonAval(int n, double *xi, double *bi, double x);

#endif
