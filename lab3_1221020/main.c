/* Lab 3: Secante e Interpolação Inversa Quadrática
 * INF1608 - Análise Numérica
 * 06/09/2017
 * arquivo: main.c
 * Autor: Rafael AZEVEDO MOSCOSO SILVA CRUZ
 * PUC-Rio
 */

#include <stdio.h>
#include <math.h>
#include "raiz2.h"

// Raiz = 1.15961
static double f(double x) {

	return (cos(x) - pow(x, 3) + x); 

}

int main() {

	double r = -1;
	int i = 0;

	double x0 = 0.0;
	double x1 = 1.5;
	double x2 = 3.0;

	printf("\n\nf(1.15961) = %lf\n\n", f(1.15961));

	printf("\n\n<<< Teste 1 do Método da Secante >>>\n\n");
	printf("f(x) = cos(x) - x^3 + x\n\n");
	printf("Estimativas: x0 = %.5g \tx1 = %.5g\n\n", x0, x1);

	i = secante(x1, x0, 6, f, &r);

	printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = -1.5;
   x1 = 2.3;

	printf("\n\n<<< Teste 2 do Método da Secante >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g\n\n", x0, x1);

   i = secante(x1, x0, 6, f, &r);

   printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = -11.5;
   x1 = 31.3;

   printf("\n\n<<< Teste 3 do Método da Secante >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g\n\n", x0, x1);

   i = secante(x1, x0, 6, f, &r);

   printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = -1.5;
   x1 = 2.3;

	printf("\n\n<<< Teste 1 do Método IQI >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g \tx2 = %.5g\n\n", x0, x1, x2);

	i = IQI(x0, x1, x2, 6, f, &r);

	printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = -1.5;
	x1 = 2.3;
	x2 = 4;

	printf("\n\n<<< Teste 2 do Método IQI >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g \tx2 = %.5g\n\n", x0, x1, x2);

   i = IQI(x0, x1, x2, 6, f, &r);

   printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = 0.0;
   x1 = 1.5;
   x2 = 3.0;

   printf("\n\n<<< Teste 3 do Método IQI >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g \tx2 = %.5g\n\n", x0, x1, x2);

   i = IQI(x0, x1, x2, 6, f, &r);

   printf("#iterations: %d \t Raiz = %.6g\n", i, r);

	x0 = -7.5;
   x1 = 7.3;
   x2 = 10;

   printf("\n\n<<< Teste 4 do Método IQI >>>\n\n");
   printf("f(x) = cos(x) - x^3 + x\n\n");
   printf("Estimativas: x0 = %.5g \tx1 = %.5g \tx2 = %.5g\n\n", x0, x1, x2);

   i = IQI(x0, x1, x2, 6, f, &r);

   printf("#iterations: %d \t Raiz = %.6g \n\n", i, r);

	return 0;
}

