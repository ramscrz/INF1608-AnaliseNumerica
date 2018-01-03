/* Lab 7: Derivação e Integração Numéricas
 * INF1608 - Análise Numérica
 * 04/10/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 *    
 */

#include<stdio.h>
#include<math.h>
#include"integral.h"

#define PI 3.14159265358979323846

double function(double x);
double dfunction(double x);
double fA(double x);
double fB(double x);
double fC(double x);
void testeDerivadaSegundaOrdem();
void computeIntegral(double (*f) (double x), double a, double b);

int main() {

	printf("\n======== LAB07 Derivacao e Integracao Numericas ========\n");

	printf("\nAutor: Rafael Azevedo Moscoso Silva Cruz, 1221020\n");

	testeDerivadaSegundaOrdem();

	printf("\n\n=======\n\nIntegral( (x dx) / sqrt((x * x) + 9) )\n");

	computeIntegral(fA, 0, 4);

	printf("\n\n=======\n\nIntegral( (x * x) * log(x) * dx )\n");

	computeIntegral(fB, 1, 3);

	printf("\n\n=======\n\nIntegral( (x * x) * sin(x) * dx )\n");

	computeIntegral(fC, 0, PI);

	return 0;

}


double function(double x) {

	return (cos(x) - 2 * sin(x));

}

double dfunction(double x) {

	return (-(2 * cos(x)) - sin(x));

}


double fA(double x) {

	return (x / sqrt((x * x) + 9));

}

double fB(double x) {  

	return ((x * x) * log(x));

}

double fC(double x) {

	return ( (x * x) * sin(x) );

}

void testeDerivadaSegundaOrdem() {

	FILE *results = fopen("results.txt", "w");

	double derivative = 0.0;
	double realDerivative = dfunction(0);
	double h = 1.0, error = 0.0;

	int i = 0;

	printf("\n\n=====\n\nTeste de Derivada (Método de Segunda Ordem)\n");

	printf("\nFunction: f(x) = cos(x) - 2 * sin(x)\n");

	printf("\n\t  h \t\t\tf'(0) \t\t\tErro \t\n\n");

	for(i = 1; i < 13; i++) {

		h /= 10;

		derivative = derivada(function, h, 0);

		error = fabs(realDerivative - derivative);

		printf("\n\t| 10e(-%d) \t %.16g \t %.16g |\n", i, derivative, error);

		if(results != 0) {
			fprintf(results, "%.16g,%.16g\n", h, error);
		}

	}

	if(results != 0) {
		fclose(results);
	}

	return;
}

void computeIntegral(double (*f) (double x), double a, double b) {

	int n = 16;

	double simpsonResult = 0.0, pmResult = 0.0;;

	simpsonResult = simpson(f, a, b, n);

	pmResult = pontomedio(f, a, b, n);

	printf("\n\tSimpson(n = 16) = %.16g\n", simpsonResult);	
	printf("\n\tPonto Medio(n = 16) = %.16g\n", pmResult);

	n = 32;

	simpsonResult = simpson(f, a, b, n);

	pmResult = pontomedio(f, a, b, n);

	printf("\n\tSimpson(n = 32) = %.16g\n", simpsonResult); 
	printf("\n\tPonto Medio(n = 32) = %.16g\n", pmResult);	

	return;
}

