/* Lab 8: Integração Numérica Adaptativa
 * INF1608 - Análise Numérica
 * 11/10/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include "simpson.h"
#include<stdio.h>
#include<math.h>

double DoubleSimpson(double a, double b, double (*f) (double x), double* v) {

	double h = b - a;
	double c = (a + b) / 2.0;

	double fa = f(a), fb = f(b), fc = f(c);

	double intervalAB = (h / 6) * ( fa + fb + (4 * fc) );
	double intervalAC = ( (c - a) / 6) * ( fa + fc + (4 * f( (a + c) / 2.0)) );
	double intervalCB = ( (b - c) / 6) * ( fc + fb + (4 * f( (c + b) / 2.0)) );

	double intervalACCB = intervalAC + intervalCB;

	double error = fabs(intervalAB - intervalACCB) / 15.0;

	*v = intervalACCB + error;

	return error;

}

double AdaptiveSimpson(double a, double b, double (*f) (double x), double tol) {

	double v = 0.0;
	double error = 0.0;

	double c = (a + b) / 2.0;

	error = DoubleSimpson(a, b, f, &v);

	if(error <= 15.0 * tol) {
		return v;
	}

	return AdaptiveSimpson(a, c, f, tol/2.0) + AdaptiveSimpson(c, b, f, tol/2.0);
}

