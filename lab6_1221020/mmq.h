#ifndef MMQ_H
#define MMQ_H

/* Lab 6: Método dos Mínimos Quadrados
 * INF1608 - Análise Numérica
 * 27/09/2017
 * arquivo: mmq.h
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

// Resolve o sistema A(m x n) x(n) = b(m) utilizando o método dos mínimos quadrados.
double* mmq(int m, int n, double** A, double* b);

// Determina a norma-2 do resíduo para o sistema A(m x n) x(n) = b(m) onde x é a solução conhecida
// e o resíduo é definido como r = b - Ax.
double norma2(int m, int n, double** A, double* b, double* x);

// Determina os coeficientes a e b do modelo que descreve o comportamento da concentração
// de droga na corrente sanguínea do paciente em função do tempo t. Os vetores pa e pb são
// os respectivos coeficientes a e b calculados e a função retorna a norma-2 do resíduo.
double concentracao(int n, double* t, double* c, double* pa, double* pb);

#endif


