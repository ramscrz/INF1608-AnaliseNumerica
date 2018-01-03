#ifndef SIMPSON_H
#define SIMPSON_H

/* Lab 8: Integração Numérica Adaptativa
 * INF1608 - Análise Numérica
 * 11/10/2017
 * arquivo: simpson.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *           
 */

double DoubleSimpson(double a, double b, double (*f) (double x), double* v);

double AdaptiveSimpson(double a, double b, double (*f) (double x), double tol);

#endif
