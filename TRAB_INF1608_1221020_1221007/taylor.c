/* Lab 1: Série de Taylor
 * INF1608 - Análise Numérica
 * 23/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

#include"taylor.h"

// Definição precisa do valor de PI.
#define PI 3.14159265358979323846

// Função que aproxima a função f(x) = sin(x) usando o polinômio de
// Taylor de grau 5 com centro em x0 = 3*(PI/2).
double fsin(double x) {

	// Termo 1 = 0
	// Termo 2 = cos(0) * (x - (0)) = x
	// Termo 3 = (-sin(0) / 2) * (x - (0))^2 = 0 * (x - (0))^2
	// Termo 4 = (-cos(0) / 6) * (x - (0))^3 = (-1 / 6) * x^3
	// Termo 5 = (sin(0) / 24) * (x - (0))^4 = 0 * (x - (0))^4

	double base, thirdBase;

	if(x < 0) {
		x *= (-1);
	}

	base = x;
	thirdBase = base * base * base;

	// Os valores dos 3o. e 5o. termos são nulos pois as derivadas f^2(PI/2) e f^4(PI/2) são nulas 
	// dado serem cossenos. Por isso esses termos dessa série de Taylor foram ignorados.     
	// f(PI/2) = cos(PI/2) = 0, logo o primeiro termo é nulo.

	return (base + thirdBase / 6.0);

}

// Função que retorna o valor absoluto do resíduo máximo da avaliação do
// polinômio em x (f(x) = cos(x)), no intervalo x in [0, PI].
double fsin_erro(double x) {

	// f^(6)(C) = cos(C), C in [0, PI].
	
	double base = x;
	double secondBase = base * base;
	double fifthBase = secondBase * secondBase * base;
	
	double rmax = fifthBase / 120.0;

	if(rmax < 0.0) {
		return (-rmax);
	}

	return rmax;
}

// Função que aproxima a função f(x) = x^(1/2) usando o polinômio de Taylor
// de grau 3 com centro em x0 = 1.
double fsqrt(double x) {

	// Termo 1 = 1
	// Termo 2 = 1/2  (x - 1)
	// Termo 3 = - 1/8  (x - 1)^2
	// Termo 4 = 1/16 (x - 1)^3

	double base = (x - 1.000);
	double secondBase = base * base;
	double common = base * 0.125;

	double result = 1.0 + common * (4.00 - base + secondBase * 0.500);
	
	return result;
}

// Função que retorna o valor absoluto do resíduo máximo da avaliação do
// polinômio em x (f(x) = x^(1/2)), no intervalo x in [1, 2].
double fsqrt_erro(double x) {

	// Termo 5 = -15/384 (x - 1)^4
	
	double base = (x - 1.00);
	double secondBase = base * base;
	double thirdBase = secondBase * secondBase;

	// Sinal negativo omitido para favorecer rmax positivo (módulo de rmax).
	double rmax = (15.0/384.0) * thirdBase;

	if(rmax < 0.0)
		return (-rmax);

	return rmax;

}

