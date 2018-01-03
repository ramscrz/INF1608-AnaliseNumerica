#include<stdio.h>
#include<math.h>
#include"raiz.h"

/* Lab 2: Métodos Bisseção e Ponto Fixo
 * INF1608 - Análise Numérica
 * 30/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * Arquivo main.c
 * PUC-Rio
 */

static double func(double x) {
	return (x * x * x) - (x * sin(2 * x)) + 0.2;
}

static double sfunc(double x) {
	return x * x + x - 20;
}

static double cosfunc(double x) {
	return cos(x);
}

int main(void) {

	double e = 0.5 * pow(10, -6);

	double r0 = bissecao(-0.5, -0.25, 6, func);
	double r1 = bissecao(0.25, 0.5, 6, func);
	double r2 = bissecao(0.75, 1.0, 6, func);
	double r3 = bissecao(-6.0, -3.0, 6, sfunc);
	double r4 = bissecao(2.0, 5.0, 6, sfunc);

	printf("\n\n <<< Teste da Bissecao >>> \n\n");
	printf("r0 = %.16g\n", r0);
	printf("r1 = %.16g\n", r1);
	printf("r2 = %.16g\n", r2);
	printf("r3 = %.16g\n", r3);
	printf("r4 = %.16g\n", r4);

	double h0 = altura_agua(2.0, 10.0);
	double h1 = altura_agua(2.0, 33.51);
	double h2 = altura_agua(4.0, 134.4);
	double h3 = altura_agua(5.0, 200.0);
	double h4 = altura_agua(4.0, 260.4);
	double h5 = altura_agua(5.0, 450.0);

	printf("\n\n <<< Teste de Altura de Agua >>> \n\n");
	printf("vol0 = 10.0(m3) \t raio0 = 2.0(m) \t h0 = %.16g\n", h0);
	printf("vol1 = 33.51(m3) \t raio1 = 2.0(m) \t h1 = %.16g\n", h1);
	printf("vol2 = 134.4(m3) \t raio2 = 4.0(m) \t h2 = %.16g\n", h2);
	printf("vol3 = 200.0(m3) \t raio3 = 5.0(m) \t h3 = %.16g\n", h3);
	printf("vol4 = 260.4(m3) \t raio2 = 4.0(m) \t h2 = %.16g\n", h4);
	printf("vol5 = 450.0(m3) \t raio3 = 5.0(m) \t h3 = %.16g\n", h5);

	double fixedpoint0 = pontofixo (0.5, e, cosfunc);

	printf("\n\n <<< Teste do Ponto Fixo de f(x) >>> \n\n");
	printf("pontofixo(0.5, e, cosfunc) = %.16g\n", fixedpoint0);
	
	double sqrtroot0 = fraiz(4);
	double sqrtroot1 = fraiz(9);
	double sqrtroot2 = fraiz(16);
	double sqrtroot3 = fraiz(2);
	double sqrtroot4 = fraiz(25);
	double sqrtroot5 = fraiz(1);
	double sqrtroot6 = fraiz(8);

	printf("\n\n <<< Teste da Raíz Quadrada de Z >>> \n\n");
	printf("fraiz(4) = %.16g\n", sqrtroot0);
	printf("fraiz(9) = %.16g\n", sqrtroot1);
	printf("fraiz(16) = %.16g\n", sqrtroot2);
	printf("fraiz(2) = %.16g\n", sqrtroot3);
	printf("fraiz(25) = %.16g\n", sqrtroot4);
	printf("fraiz(1) = %.16g\n", sqrtroot5);
	printf("fraiz(8) = %.16g\n", sqrtroot6);
}

