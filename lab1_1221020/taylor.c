/* Lab 1: Série de Taylor
 * INF1608 - Análise Numérica
 * 23/08/2017
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

#include"taylor.h"

// Definição precisa do valor de PI.
#define PI 3.14159265358979323846

// Função que aproxima a função f(x) = cos(x) usando o polinômio de
// Taylor de grau 4 com centro em x0 = PI/2.
double fcos(double x) {

	// Termo 1 = 0
	// Termo 2 = -sen(PI/2) * (x - PI/2)
	// Termo 3 = 0
	// Termo 4 = (sen(PI/2) / 6) * (x - PI/2)^3
	// Termo 5 = 0

	double base = (x - PI/2.0);
	double thirdBase =  base * base * base;

	// Os valores dos 3o. e 5o. termos são nulos pois as derivadas f^2(PI/2) e f^4(PI/2) são nulas 
	// dado serem cossenos. Por isso esses termos dessa série de Taylor foram ignorados.     
	// f(PI/2) = cos(PI/2) = 0, logo o primeiro termo é nulo.
	
	return (thirdBase/6.0 - base);

}

// Função que retorna o valor absoluto do resíduo máximo da avaliação do
// polinômio em x (f(x) = cos(x)), no intervalo x in [0, PI].
double fcos_erro(double x) {

	// f^(5)(C) = -sen(C), C in [0, PI].
	
	double base = (x - PI/2.0);
	double secondBase = base * base;
	double thirdBase = secondBase * secondBase;
	
	double rmax = (thirdBase * base) / 120;

	if(rmax < 0.0)
		return (-rmax);

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

