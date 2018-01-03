/* Lab 7: Derivação e Integração Numéricas
 * INF1608 - Análise Numérica
 * 04/10/2017
 * arquivo: integral.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include"integral.h"

double derivada (double (*f) (double x), double h, double x) {

	return (f(x + h) - f(x - h)) / (2 * h);
}

double simpson (double (*f) (double), double a, double b, int n) {
	
	double h = (b - a) / n;
	double middleSum = 0.0, delimiterSum = 0.0;
	double fa = f(a);
	double fb = f(b);

	double x = 0.0;
	
	double middleIncrement = h / 2;

	for(x = a; x <= b - h; x += h) {
		middleSum += f(x + middleIncrement);
	}

	middleSum *= 4;

	for(x = a + h; x <= b - h; x += h) {
		delimiterSum += f(x);
	}

	delimiterSum *= 2;

	return ((fa + fb + delimiterSum + middleSum) * h) / 6;
}

double pontomedio (double (*f) (double), double a, double b, int n) {
	
	double h = (b - a) / n;
	double result = 0.0;
	double step = h / 2;
	double x = 0.0;

	for(x = a; x <= b - h; x += h) {
		result += f(x + step);
	}

	return result * h;
}


