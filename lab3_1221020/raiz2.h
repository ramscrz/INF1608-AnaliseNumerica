#ifndef RAIZ2_H
#define RAIZ2_H

/* Lab 3: Secante e Interpolação Inversa Quadrática
 * INF1608 - Análise Numérica
 * 06/09/2017
 * arquivo: raiz2.h
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

// Determina a raiz da função f através método da secante a partir das estimativas x0 e x1 
// (precisão 0.5 * 10^(-p)); armazena a raiz calculada no endereço r e retorna o número de iterações.
// Após 50 iterações, o algoritmo assume que o método diverge.
int secante(double x0, double x1, int p, double (*f) (double x), double * r);

// Determina a raiz da função f através método da secante a partir das estimativas x0 e x1 
// (precisão 0.5 * 10^(-p)); armazena a raiz calculada no endereço r e retorna o número de iterações.
// Após 50 iterações, o algoritmo assume que o método diverge. Utiliza a Regra de Crammer.
int IQI(double x0, double x1, double x2, double p, double (*f) (double x), double *r);

#endif
