#include<stdio.h>
#include<math.h>
#include"ode.h"

double df(double t, double x) {

	return ( (t * x) + (t * t * t) );

}

double f(double t) {

	return exp((t * t) / 2) - (t * t) - 2;

}

int main() {

	double f0 = -1, t1 = 2.4, h1 = 0.1, h2 = 0.2, h3 = 0.4;
	double result = 0.0;
	double aval;
	int i = 0.1;

	printf("\n==== LAB09: Equacoes Diferenciais Ordinarias (EDO)====\n");
	printf("\nAutor: Rafael Azevedo Moscoso Silva Cruz, 1221020\n");

	printf("\n\nMetodo\t\t  h  \t\ty(2.4)\t\terro");

	aval = f(t1);

	while(h1 >= 0.001) {

		printf("\n--------");

		result = Euler (0, t1, h1, f0, df);
		printf("\nEuler\t\t%lf\t%.10f\t%.10f", h1, result, fabs((result - aval) / aval));
	
		result = MidPoint (0, t1, h2, f0, df);
		printf("\nMidPoint\t%lf\t%.10f\t%.10f", h2, result, fabs((result - aval) / aval));

		result = RungeKutta (0, t1, h3, f0, df);
		printf("\nRungeKutta\t%lf\t%.10f\t%.10f", h3, result, fabs((result - aval) / aval));

		h1 /= 10;
		h2 /= 10;
		h3 /= 10;
	}

	printf("\n\n");

  return 0;
}

