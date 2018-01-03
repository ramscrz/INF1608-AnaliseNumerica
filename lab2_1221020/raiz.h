#ifndef RAIZ_H
#define RAIZ_H

/* Lab 2: Métodos Bisseção e Ponto Fixo
 * INF1608 - Análise Numérica
 * 30/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * Arquivo header raiz.h
 * PUC-Rio
 */

// Determina a raíz de f(x) no intervalo [a, b] com erro de precisão de p dígitos (e < 0.5 x 10^(-p))// onde e = (b - a)/2^(n + 1).
double bissecao (double a, double b, int p, double (*f) (double x));

// Determina a altura da água de uma calota esférica de água com volume v e raio r 
// (com 4 dígitos de precisão).
double altura_agua (double r, double v);

// Determina o ponto fixo de uma função g(x) com precisão epsilon; x0 é a estimativa inicial.
double pontofixo (double x0, double epsilon, double (*g) (double x));

// Determina a raíz quadrada de um número z via a determinação do ponto fixo da função 
// g(x) = ( x - (z/x) ) / 2.
double fraiz (double z);

#endif
