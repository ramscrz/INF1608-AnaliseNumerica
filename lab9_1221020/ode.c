#include<stdio.h>
#include<stdlib.h>

double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x)) {

	double x = x0;
	double t = t0;


	while(t < t1) {
		x += ( h * f(t, x) );
		t += h;
	}

	return x;

}

double MidPoint (double t0, double t1, double h, double x0, double (*f) (double t, double x)) {

	double x = x0;
	double t = t0;
	double k = 0.0;

	while(t < t1) {
		k = h * f(t, x);
		x += ( h * f(t + h/2, x + k/2) );
		t += h;
	}

	return x;
}


double RungeKutta(double t0, double t1, double h, double x0, double (*f) (double t, double x)) {

	double k[4] = {0};
	double x = x0, t = t0;

	int i = 0;

	double a = h / 2;

	while(t < t1) {
		k[0] = h * f(t, x);
		k[1] = h * f(t + a, x + k[0]/2);
		k[2] = h * f(t + a, x + k[1]/2);
		k[3] = h * f(t + h, x + k[2]);

		x += ((k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6);
	
		t += h;
	}
	
	return x;

}
