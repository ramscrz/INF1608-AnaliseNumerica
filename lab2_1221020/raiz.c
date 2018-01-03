#include<raiz.h>
#include<math.h>

/* Lab 2: Métodos Bisseção e Ponto Fixo
 * INF1608 - Análise Numérica
 * 30/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * Arquivo raiz.c
 * PUC-Rio
 */


#define PI 3.14159265358979323846

static double vol = 0;

static double raio = 0;

static double zv = 0;

static double hfunc(double h) {

	return (vol - ((1/3.0) * PI * h * h * ((3 * raio) - h)));

}

static double gfunc(double x) {

	return ( x + (zv / x) ) / 2;

}

// Determina a raíz de f(x) no intervalo [a, b] com erro de precisão de p dígitos (e < 0.5 x 10^(-p))// onde e = (b - a)/2^(n + 1).
double bissecao (double a, double b, int p, double (*f) (double x)) {

	int i = 0;
	double fa = f(a);
	double fb = f(b);
	double c = (a + b)/2;
	double fc = f((a + b)/2);
	double fafb = fa * fb;
	double an = a;
	double bn = b;
	double pr = 0.5 * pow(10, -p);
	double tol = (b - a)/2;

	while(tol > pr && fafb < 0) {

		if( (fa * fc) < 0) {
			fb = fc;
			bn = c;
		} else {
			fa = fc;
			an = c;
		}
		
		c = (an + bn) / 2;
		fc = f(c);
		fafb = fa * fb;

		tol = tol / 2;
	}

	return c;

}

// Determina a altura da água de uma calota esférica de água com volume v e raio r 
// (com 4 dígitos de precisão).
double altura_agua (double r, double v) {

	vol = v;
	raio = r;

 	return bissecao(0, 2 * raio, 4, hfunc);

}

// Determina o ponto fixo de uma função g(x) com precisão epsilon; x0 é a estimativa inicial. 
double pontofixo (double x0, double epsilon, double (*g) (double x)) {

	int n = 0;
	double xff = x0;
	double xf  = x0;
	double e = epsilon;

	do {
		xf = xff;
		xff = g(xff);
		n++;
		e = fabs(xff - xf);
	} while(e > epsilon);

	return xff;

}

// Determina a raíz quadrada de um número z via a determinação do ponto fixo da função 
// g(x) = ( x + (z/x) ) / 2.
double fraiz (double z) {

	double p = 0.5 * pow(10, -6);

	zv = z;

	return pontofixo(z/2, p, gfunc);

}
