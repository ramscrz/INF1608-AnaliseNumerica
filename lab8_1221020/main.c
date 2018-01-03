/* Lab 8: Integração Numérica Adaptativa
 * INF1608 - Análise Numérica
 * 11/10/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<math.h>
#include"simpson.h"

#define PI 3.14159265358979323846

static double fA(double x);
static double fB(double x);
static double fC(double x);

int main() {

	double tol = 0.5 * pow(10, -7), result = 0.0;

	printf("\n======== LAB08 Integracao Numerica Adaptativa ========\n");

	printf("\nAutor: Rafael Azevedo Moscoso Silva Cruz, 1221020\n");

	printf("\n\n=======\n\nIntegral(0 -> 1)( (x dx) / sqrt((x * x) + 9) )\n");

	result = AdaptiveSimpson(0, 1, fA, tol);
	printf("\nRESULTADO = %.8g\n", result);

	printf("\n\n=======\n\n(1 / sqrt(2 * PI)) * Integral(-1 -> 1)( exp(- (x * x) / 2) dx )\n");

	result = AdaptiveSimpson(-1, 1, fB, tol);
	printf("\nRESULTADO = %.8g\n", (1 / sqrt(2 * PI)) * result);

	printf("\n\n=======\n\n(2 / sqrt(PI)) * Integral(0 -> 3)( exp(- (x * x) ) dx )\n");

	result = AdaptiveSimpson(0, 3, fC, tol);
	printf("\nRESULTADO = %.8g\n", (2 / sqrt(PI)) * result);

	printf("\n\n=======\n\nIntegral(0 -> 4)( (x dx) / sqrt((x * x) + 9) )\n");

	result = AdaptiveSimpson(0, 4, fA, tol);
	printf("\nRESULTADO = %.8g\n\n", result);

	return 0;

}

double fA(double x) {

	return (x / sqrt((x * x) + 9));
}

double fB(double x) {  

	return exp(- (x * x)/ 2);
}

double fC(double x) {

	return exp(-(x * x));
}
