#ifndef TAYLOR_H
#define TAYLOR_H

/* Lab 1: Série de Taylor
 * INF1608 - Análise Numérica
 * 23/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

// Função que aproxima a função f(x) = cos(x) usando o polinômio de
// Taylor de grau 4 com centro em x0 = PI/2.
double fsin(double x);

// Função que retorna o valor absoluto do resíduo máximo da avaliação do
// polinômio em x (f(x) = cos(x)), no intervalo x in [0, PI].
double fsin_erro(double x);

// Função que aproxima a função f(x) = x^(1/2) usando o polinômio de Taylor
// de grau 3 com centro em x0 = 1.
double fsqrt(double x);

// Função que retorna o valor absoluto do resíduo máximo da avaliação do
// polinômio em x (f(x) = x^(1/2)), no intervalo x in [1, 2].
double fsqrt_erro(double x);

#endif
