#ifndef SISTLINEAR_H
#define SISTLINEAR

/* Lab 4: Sistemas Lineares
 * INF1608 - Análise Numérica
 * 13/09/2017
 * arquivo: sistlinear.h
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

// Determina as matrizes de fatoração da matriz quadrada A(nxn): L e U; retorna a matriz A que armazena L e U.
// A técnica de pivotamento é implementada para melhorar a estabilidade numérica do método.
int* fatoracao (int n, double** A);

// Determina a solução do sistema linear Ax = b, fatorando A(nxn), determinando y tal que Ly = b' 
// (b após pivotamento) por substituição top-down e determinando x por substituição regressiva 
// tal que Ux = y. A função retorna a solução x de Ax = b.
double* substituicao (int n, double** A, int* p, double* b);

#endif
