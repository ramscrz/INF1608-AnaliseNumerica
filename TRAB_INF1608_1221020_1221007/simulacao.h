#ifndef SIMULACAO_H
#define SIMULACAO

/* TRABALHO 01: Movimento de um Pêndulo
* INF1608 - Análise Numérica
* 03/11/2017
* arquivo: simulacao.h
* Autores: Rafael AZEVEDO MOSCOSO SILVA CRUZ; Rodrigo PUMAR.
* PUC-Rio
*
*/

typedef enum {

	SIMPLIFIED = 0,
	TAYLORBASED = 1,
	MAXPRECISION = 2,
	ADAPTATIVE = 3

} RKMODEL;


double fe(double tet, double gl);

double fs(double tet, double gl);

double fTaylor(double tet, double gl);

double solveRungeKuttaAdaptativo(double h, double tet0, double w0, double g, double l, double* r, double(*f) (double ftet, double fgl), double emax, double *t, int* evol);

void solveRungeKutta(double h, double tet0, double w0, double g, double l, double* r, double(*f) (double ftet, double fgl), double *t);

double simulacao(double h, char* file, double tet0, double w0, double g, double l, double interval, int enableVerbose, RKMODEL model, double *simulTime, double *stepSimulTime, int *stepExceeded);

double* simulacaoCompleta(double h, char* file, double tet0, double w0, double g, double l, double interval, int enableVerbose, double *simulTime, double *stepSimulTime, int *stepExceeded);

void avaliaPeriodo(double w0, double l, double interval);

#endif
