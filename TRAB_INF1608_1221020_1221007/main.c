/* TRABALHO 01: Movimento de um Pêndulo
* INF1608 - Análise Numérica
* 03/11/2017
* arquivo: main.c
* Autores: Rafael AZEVEDO MOSCOSO SILVA CRUZ; Rodrigo PUMAR.
* PUC-Rio
*
*/

#include"simulacao.h"
#include<stdio.h>

#define INTERVAL 25.0

int main(void) {

	double tet0 = 0.01, w0 = 0.0, g = 10, l = 5.0, h = 0.1, T = 0.0;
	double* prd = NULL;
	double simulTime, stepSimulTime;
	int stepExceeded;

	T = simulacao(h, "pendulo.txt", tet0, w0, g, l, INTERVAL, 0, SIMPLIFIED, &simulTime, &stepSimulTime, &stepExceeded);

	printf("\n\nTempo de Simulacao: segundos\n\n");
	printf("\n\nPeriodo (T) = %.16g\n\n", T);

	avaliaPeriodo(w0, l, INTERVAL);

	return 0;
}

