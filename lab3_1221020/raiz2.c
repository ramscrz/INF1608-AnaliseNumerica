/* Lab 3: Secante e Interpolação Inversa Quadrática
 * INF1608 - Análise Numérica
 * 06/09/2017
 * arquivo: raiz2.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

#include "raiz2.h"
#include <stdio.h>
#include <math.h>

// Determina a raíz x da interpolação inversa pela Regra de Crammer.
double getCoefCrammerRule(double fx0, double fx1, double fx2, double x0, double x1, double x2) {

	double fx02 = fx0 * fx0;
	double fx12 = fx1 * fx1;
	double fx22 = fx2 * fx2;
	double fx12fx2 = fx12 * fx2;
	double fx22fx1 = fx22 * fx1;
	double last = fx12fx2 - fx22fx1;

	double detA = (fx02 * (fx1 - fx2)) - (fx0 * (fx12 - fx22)) + last;
	double detAc = (fx02 * ((fx1 * x2) - (fx2 * x1))) - (fx0 * ((fx12 * x2) - (fx22 * x1))); 
	detAc += (last * x0);

	if(detA == 0) {
		return x0;
	}

	return (detAc / detA); 

}

// Determina a raiz da função f através método da secante a partir das estimativas x0 e x1 
// (precisão 0.5 * 10^(-p)); armazena a raiz calculada no endereço r e retorna o número de iterações.
// Após 50 iterações, o algoritmo assume que o método diverge.
int secante(double x0, double x1, int p, double (*f) (double x), double * r) {

	double fx1 = f(x1);
	double fx0 = f(x0);
	double dfx1 = 0;
	double tmp = 0;
	double tol = 0.5 * pow(10, -p);
	int i = 0;

	// Ordena x0 e x1 de modo que f(x0) seja menor que fx1.
	if(fx1 < fx0) {

		tmp = x0;
		x0 = x1;
		x1 = tmp;

		tmp = fx0;
		fx0 = fx1;
		fx1 = tmp;
	}

	dfx1 = (fx1 - fx0) / (x1 - x0);

	while(fabs(fx0) >= tol && i < 51) {

		if(i == 50) {

			*r = 0;

			return 0;

		}

		tmp = x0;
		x0 = x1 - (fx1/dfx1);
		x1 = tmp;

		fx1 = fx0;
		fx0 = f(x0);
		dfx1 = (fx1 - fx0) / (x1 - x0);
	
		i++;
	}

	*r = x0;

	return i;

}

// Determina a raiz da função f através método da secante a partir das estimativas x0 e x1 
// (precisão 0.5 * 10^(-p)); armazena a raiz calculada no endereço r e retorna o número de iterações.
// Após 50 iterações, o algoritmo assume que o método diverge. Utiliza a Regra de Crammer.
int IQI(double x0, double x1, double x2, double p, double (*f) (double x), double *r) {

	double y0 = f(x0);
	double y1 = f(x1);
	double y2 = f(x2);

	double tol = 10 * pow(10, -p);
	double tmp0, tmp1 = 0;

	int i = 0;
	
	double fxr, xr = 0;

	// Ordena os pares { (x0, y0), (x1, y1), (x2, y2) } em ordem tal que menor o indice i, maior xi.	
	 if(x1 > x0) {
      tmp0 = y1;
      y1 = y0;
      y0 = tmp0;

      tmp0 = x1;
      x1 = x0;
      x0 = tmp0;
   }


	if(x2 > x1) {
		tmp0 = y2;
		y2 = y1;
		y1 = tmp0;

		tmp0 = x2;
		x2 = x1;
		x1 = tmp0;
	}

	// Função f chamada uma única vez por iteração.
	while(fabs(y2) >= tol && i < 51) {

		// Excedeu o número máximo de iterações.
		if(i == 50) {
			*r = 0;
			return 0;
		}

		// Determina o coeficiente c pela Regra de Crammer.
		xr = getCoefCrammerRule(y0, y1, y2, x0, x1, x2);

		fxr = f(xr);

		// Descarta x0 que possui maior valor em f e inclui xr no conjunto de três estimativas.
		tmp0 = y2;
		y2 = fxr;
		tmp1 = y1;
		y1 = tmp0;
		y0 = tmp1;
			
		tmp0 = x2;
      x2 = xr;
      tmp1 = x1;
      x1 = tmp0;
      x0 = tmp1;

		i++;

	}

	*r = x2;

	return i;

}

