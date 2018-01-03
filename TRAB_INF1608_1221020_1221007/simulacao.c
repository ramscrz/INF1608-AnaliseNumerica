/* TRABALHO 01: Movimento de um Pêndulo
 * INF1608 - Análise Numérica
 * 03/11/2017
 * arquivo: simulacao.c
 * Autores: Rafael AZEVEDO MOSCOSO SILVA CRUZ; Rodrigo PUMAR.
 * PUC-Rio
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include"taylor.h"
#include"simulacao.h"

#define RKMODEL_MAX 4
#define PI 3.14159265358979323846
#define INTERVAL 25.0

double fe(double tet, double gl) {

	return -(gl * sin(tet));

}

double fs(double tet, double gl) {

	return -(gl * tet);

}

double fTaylor(double tet, double gl) {

	double sinTet = fsin(tet);

	if(tet < 0) {
		sinTet *= (-1);
	}

	return -(gl * sinTet);

}

double getMilliseconds() {

	return ((double)(clock())/CLOCKS_PER_SEC) * 1000;
	
}

//RungeKutta com passo adaptativo.
double solveRungeKuttaAdaptativo(double h, double tet0, double w0, double g, double l, double* r, double(*f) (double ftet, double fgl), double emax, double *t, int *evol) {
	double error, hnew;
	double rcontrol[2]= { tet0, w0 }, rhalf[2]= { tet0, w0 }, rhalfnext[2] = { tet0, w0 };
	double ptlixo;
	//avaliacao de controle
	solveRungeKutta(h, tet0, w0, g, l, rcontrol, f, &ptlixo); 

	 //avaliacao de teste
	solveRungeKutta(h/2, tet0, w0, g, l, rhalf, f, &ptlixo);
	solveRungeKutta(h/2, rhalf[0], rhalf[1], g, l, rhalfnext, f, &ptlixo);
	error = fabs(rhalfnext[0] - rcontrol[0]);
	hnew = h *sqrt(emax / error);
	if (error <=emax) {//error aceitavel
		r[1] = rhalfnext[1]; //aceita velocidade
		r[0] = rhalfnext[0]; //aceita theta
		*t = *t+h ; // aceita o passo
		(*evol)++; // mais um evolucao aceita
		//printf("\n %d", *evol);
		if ((*evol) >= 2) {  //somente aumento h se deu duas evolucoes dentro da tolerancia
			if (hnew > 1.2*h)
			{
				hnew = 1.2*h;
			}
			h = hnew;//aumenta h

		}
		return h; //nao aumento h, pois nao deu duas evolucoes dentro da tolerancia
	}
	else {
		h = hnew; // diminui h
		(*evol) = 0; // essa evolucao nao foi aceita
	}
	return h;
}

void solveRungeKutta(double h, double tet0, double w0, double g, double l, double* r, double(*f) (double ftet, double fgl), double *t) {

	double stet[4] = {0}, sw[4] = {0};
	double tet = tet0, w = w0;
	double gl = g / l;
	int i = 0;

	stet[0]  = h * f(tet, gl); //dv1
	sw[0]    = h * w; //dtheta

	tet = tet0 + (sw[0] / 2.0);
	w = w0 + (stet[0] / 2.0);

	stet[1] 	= h * f(tet, gl); //
	sw[1] 	= h * w;  //

	tet = tet0 + (sw[1] / 2.0);
	w = w0 + (stet[1] / 2.0);

	stet[2] 	= h * f(tet, gl);
	sw[2] 	= h * w;

	tet = tet0 + sw[2];
	w = w0 + stet[2];

	stet[3] 	= h * f(tet, gl);
	sw[3] 	= h * w;

	r[0] = tet0 + (sw[0] + 2 * sw[1] + 2 * sw[2] + sw[3]) / 6.0;
	r[1] = w0 + (stet[0] + 2 * stet[1] + 2 * stet[2] + stet[3]) / 6.0;

	*t +=  h;
	return;

}

double simulacao(double h, char* file, double tet0, double w0, double g, double l, double interval, int enableVerbose, RKMODEL model, double *simulTime, double *stepSimulTime, int *stepExceeded) {

	double r[2] = { tet0, w0 };
	double t = 0.0;
	double tf = 0.0, t0 = 0.0, tff = 0.0;
	double wf = w0, sum = 0.0, timeT = 0.0;
	double emax = pow(10, -8);  //tolerancia para passo adaptativo
	int evolucoes = 0;
	int k = 0, i = 0;
	double startTime, endTime, startStepTime, endStepTime;
	FILE* results = NULL;

	if(file == NULL || simulTime == NULL || stepSimulTime == NULL || stepExceeded == NULL) {
		printf("\nError(simulacao): NULL pointers as parameters.\n");
		return -1;
	}

	results = fopen(file, "w");

	if (results == NULL) {
		printf("\nError(fopen): %s could be opened.\n", file);
		return -1;
	}
	
	if(interval == 0) {
		return 0;
	}

	if (enableVerbose > 0) {
		printf("\n\t Time \t Angular Position \t X Coord \t Y Coord \t Angular Velocity\n ");
		printf("-----------------------------------------------------------------------------\n");
	}

	fprintf(results, "t,tetAngular,w");

	t = 0.0;
	double hnext = h;
	double tnext = t;

	startTime = getMilliseconds();

	*stepExceeded = 0;
	*stepSimulTime = 0;

	while (t < interval) {
	
		if (t + h > interval) {
			h = interval - t;
		}

		startStepTime = getMilliseconds();

		switch (model) {

			case MAXPRECISION:
				solveRungeKutta(h, r[0], r[1], g, l, r, fe, &tnext);
				break;
			case TAYLORBASED:
				solveRungeKutta(h, r[0], r[1], g, l, r, fTaylor, &tnext);
				break;
			case SIMPLIFIED:
				solveRungeKutta(h, r[0], r[1], g, l, r,fs,&tnext);
				break;
			case ADAPTATIVE:
				hnext = solveRungeKuttaAdaptativo(h, r[0], r[1], g, l, r, fe, emax, &tnext, &evolucoes);
				break;
			default:
				solveRungeKutta(h, r[0], r[1], g, l, r, fe, &tnext);
				break;
		}

		endStepTime = getMilliseconds();

		double sTime = endStepTime - startStepTime;

		if(sTime > h) {
			*stepExceeded = 1;
			*stepSimulTime = sTime; 
		}

		if (wf * r[1] < 0) {

			if (k == 0) {
				t0 = t + (fabs(wf) / (fabs(wf) + fabs(r[1]))) * h;
			}
			else if (k % 2 == 0) {
				tf = t + (fabs(wf) / (fabs(wf) + fabs(r[1]))) * h;
			}
			k++;
		}

		wf = r[1];

		if (enableVerbose > 0) {
			printf("\n\t%lf \t %.8g \t %.8g \t %.8g \t %.8g\n", t, r[0], l * cos(r[0]), l * sin(r[0]), r[1]);
		}

		fprintf(results, "%lf,%.8g,%.8g\n", t, r[0], r[1]);
		h = hnext;
		t = tnext;
	}

	endTime = getMilliseconds();
	
	*simulTime = endTime - startTime;

	if (enableVerbose > 0) {
		printf("\n%d inversoes detectadas!\n", k);
		printf("\nMaior tempo de inversao medido = %lf segundos\n", tf);
	}

	if (k > 2) {
		if (k % 2 == 1) {
			timeT = (tf - t0) / ((k - 1) / 2);
		}
		else {
			timeT = (tf - t0) / ((k - 2) / 2);
		}
	}

	if (enableVerbose > 0) {
		printf("\n\nTime of the simulation = %lf milliseconds \nDiferença (Tempo Simulado - Tempo Simulacao) =  %lf", *simulTime, interval - *simulTime);
	}

	fclose(results);

	return timeT;

}

double* simulacaoCompleta(double h, char* file, double tet0, double w0, double g, double l, double interval, int enableVerbose, double *simulTime, double *stepSimulTime, int *stepExceeded) {

	double r[2] = { tet0, w0 };
	double t = 0.0;
	double tf = 0.0, t0 = 0.0;
	double wf = w0, timeT = 0.0;
	RKMODEL model = SIMPLIFIED;
	int finished = 0;

	double *periodo = NULL;

	periodo = (double*) malloc(RKMODEL_MAX * sizeof(double));
	if (periodo == NULL) {
		return NULL;
	}

	int k = 0, i = 0;

	/*	FILE* results = fopen(file, "w");

	if(results == NULL) {
	printf("\nError(fopen): %s could be opened.\n", file);
	exit(1);
	}
	*/
	if (enableVerbose > 0) {
		printf("\n\t Time \t Angular Position \t X Coord \t Y Coord \t Angular Velocity\n ");
		printf("-----------------------------------------------------------------------------\n");
	}

	//	fprintf(results, "t,tetAngular,w");

	t = 0.0;

	t = simulacao(h, "pendulo.txt", tet0, w0, g, l, interval, 0, SIMPLIFIED, &simulTime[SIMPLIFIED], &stepSimulTime[SIMPLIFIED], &stepExceeded[SIMPLIFIED]);

	periodo[SIMPLIFIED] = t;
	//	printf("\nF PERIODO = %lf ; MODEL %d ; tet0 %lf\n", periodo[SIMPLIFIED], SIMPLIFIED, tet0);

	t = simulacao(h, "pendulo.txt", tet0, w0, g, l, interval, 0, TAYLORBASED, &simulTime[TAYLORBASED], &stepSimulTime[TAYLORBASED], &stepExceeded[TAYLORBASED]);

	periodo[TAYLORBASED] = t;

	//	printf("\nF PERIODO = %lf ; MODEL %d ; tet0 %lf\n", periodo[TAYLORBASED], TAYLORBASED, tet0);
	t = simulacao(h, "pendulo.txt", tet0, w0, g, l, interval, 0, MAXPRECISION, &simulTime[MAXPRECISION], &stepSimulTime[MAXPRECISION], &stepExceeded[MAXPRECISION]);

	periodo[MAXPRECISION] = t;

	//	printf("\nF PERIODO = %lf ; MODEL %d ; tet0 %lf\n", periodo[MAXPRECISION], MAXPRECISION, tet0);
	t = simulacao(h, "pendulo.txt", tet0, w0, g, l, interval, 0, ADAPTATIVE, &simulTime[ADAPTATIVE], &stepSimulTime[ADAPTATIVE], &stepExceeded[ADAPTATIVE]);

	periodo[ADAPTATIVE] = t;

	//	printf("\nF PERIODO = %lf ; MODEL %d ; tet0 %lf\n", periodo[MAXPRECISION], MAXPRECISION, tet0);

	return periodo;

}

void avaliaPeriodo(double w0, double l, double interval) {

	double tet0 = 0.15, g = 10, h = 0.01, previsto = 0.0;
	int ret = 0;

	double* prdA = NULL, *prdB = NULL, *prdC = NULL;

	int stepExceededA[RKMODEL_MAX], stepExceededB[RKMODEL_MAX], stepExceededC[RKMODEL_MAX]; 

	double simulTimeA[RKMODEL_MAX], stepSimulTimeA[RKMODEL_MAX], simulTimeB[RKMODEL_MAX], stepSimulTimeB[RKMODEL_MAX], simulTimeC[RKMODEL_MAX], stepSimulTimeC[RKMODEL_MAX];

	printf("\n\t\t\t  Diferenca entre Calculado e Previsto\t\t\n");
	printf("\n\t\t\t  h = 0.01  \t  h = 0.001  \t  h = 0.0001  \t  Previsto\n");
	printf("-----------------------------------------------------------------------------------\n");

	for (tet0 = 0.0; tet0 < PI * 0.4;) {

		//previsto = 2 * PI * sqrt(l / g); //simpificada analitica
		if (tet0 == 0.0) {
			previsto = 0.0;
		} else {//Power series solution for the elliptic integral
			previsto = 2 * PI*sqrt(l / g)*(1 + (pow(tet0, 2) / 16.0) + ((11 * pow(tet0, 4)) / 3072.0) + ((173 * pow(tet0, 6)) / 737280.0) + ((22931 * pow(tet0, 8)) / 1321205760.0));
		}

		prdA = simulacaoCompleta(0.01, "pendulo.txt", tet0, w0, g, l, interval, 0, simulTimeA, stepSimulTimeA, stepExceededA);

		if(ret < 0) {
			return;
		}

		prdB = simulacaoCompleta(0.001, "pendulo.txt", tet0, w0, g, l, interval, 0, simulTimeB, stepSimulTimeB, stepExceededB);

		if(ret < 0) {
			return;
		}

		prdC = simulacaoCompleta(0.0001, "pendulo.txt", tet0, w0, g, l, interval, 0, simulTimeC, stepSimulTimeC, stepExceededC);

		if(ret < 0) {
			return;
		}

		printf("\ntet0 = %03g (RKS)\t %0.4g\t %0.4g\t %0.4g\t %0.4g\n", tet0, prdA[SIMPLIFIED] - previsto, prdB[SIMPLIFIED] - previsto, prdC[SIMPLIFIED] - previsto, previsto);
		printf("\nSIMUL.TIME (RKS)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", simulTimeA[SIMPLIFIED], simulTimeB[SIMPLIFIED], simulTimeC[SIMPLIFIED]);
		printf("\nSTEP TIME (RKS)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", stepSimulTimeA[SIMPLIFIED] * stepExceededA[SIMPLIFIED], stepSimulTimeB[SIMPLIFIED] * stepExceededB[SIMPLIFIED], stepSimulTimeC[SIMPLIFIED] * stepExceededC[SIMPLIFIED]);
		printf("\nSTEPTIME EXCEEDED? (RKS)  %08d\t %08d\t %08d\t\n\n", stepExceededA[SIMPLIFIED], stepExceededB[SIMPLIFIED], stepExceededC[SIMPLIFIED]);

		printf("tet0 = %03g (RKT)\t %0.4g\t %0.4g\t %0.4g\t %0.4g\n", tet0, prdA[TAYLORBASED] - previsto, prdB[TAYLORBASED] - previsto, prdC[TAYLORBASED] - previsto, previsto);
		printf("\nSIMUL.TIME (RKT)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", simulTimeA[TAYLORBASED], simulTimeB[TAYLORBASED], simulTimeC[TAYLORBASED]);
		printf("\nSTEP TIME (RKT)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", stepSimulTimeA[TAYLORBASED] * stepExceededA[TAYLORBASED], stepSimulTimeB[TAYLORBASED] * stepExceededB[TAYLORBASED], stepSimulTimeC[TAYLORBASED] * stepExceededC[TAYLORBASED]);
		printf("\nSTEPTIME EXCEEDED? (RKT) %08d\t %08d\t %08d\t\n\n", stepExceededA[TAYLORBASED], stepExceededB[TAYLORBASED], stepExceededC[TAYLORBASED]);
		
		printf("tet0 = %03g (RKMP)\t %0.4g\t %0.4g\t %0.4g\t %0.4g\n", tet0, prdA[MAXPRECISION] - previsto, prdB[MAXPRECISION] - previsto, prdC[MAXPRECISION] - previsto, previsto);
		printf("\nSIMUL.TIME (RKMP)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", simulTimeA[MAXPRECISION], simulTimeB[MAXPRECISION], simulTimeC[MAXPRECISION]);
		printf("\nSTEP TIME (RKMP)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", stepSimulTimeA[MAXPRECISION] * stepExceededA[MAXPRECISION], stepSimulTimeB[MAXPRECISION] * stepExceededB[MAXPRECISION], stepSimulTimeC[MAXPRECISION] * stepExceededC[MAXPRECISION]);
		printf("\nSTEPTIME EXCEEDED? (RKMP) %08d\t %08d\t %08d\t\n\n", stepExceededA[MAXPRECISION], stepExceededB[MAXPRECISION], stepExceededC[MAXPRECISION]);

		printf("tet0 = %03g (RKADAP-MP)\t %0.4g\t %0.4g\t %0.4g\t %0.4g\n", tet0, prdA[ADAPTATIVE] - previsto, prdB[ADAPTATIVE] - previsto, prdC[ADAPTATIVE] - previsto, previsto);
		printf("\nSIMUL.TIME (RKADAP-MP)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", simulTimeA[ADAPTATIVE], simulTimeB[ADAPTATIVE], simulTimeC[ADAPTATIVE]);
		printf("\nSTEP TIME (RKADAP-MP)\t %0.4g ms\t %0.4g ms\t %0.4g ms\t\n", stepSimulTimeA[ADAPTATIVE] * stepExceededA[ADAPTATIVE], stepSimulTimeB[ADAPTATIVE] * stepExceededB[ADAPTATIVE], stepSimulTimeC[ADAPTATIVE] * stepExceededC[ADAPTATIVE]);
		printf("\nSTEPTIME EXCEEDED? (RKADAP-MP) %08d\t %08d\t %08d\t\n\n", stepExceededA[ADAPTATIVE], stepExceededB[ADAPTATIVE], stepExceededC[ADAPTATIVE]);
	
		tet0 += 0.05;
		if (tet0 > 0.244) {	//sin θ ≈ θ at about 0.244 radians
			tet0 += 0.05;
		}

		free(prdA);
		prdA = NULL;
		free(prdB);
		prdB = NULL;
		free(prdC);
		prdC = NULL;
	}
}
