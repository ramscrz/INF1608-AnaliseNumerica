#ifndef INTEGRAL_H

/* Lab 7: Derivação e Integração Numéricas
 * INF1608 - Análise Numérica
 * 04/10/2017
 * arquivo: integral.h
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

double derivada (double (*f) (double x), double h, double x);

double simpson (double (*f) (double), double a, double b, int n);

double pontomedio (double (*f) (double), double a, double b, int n);

#endif
