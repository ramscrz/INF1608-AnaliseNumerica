#ifndef MATRIZ_H
#define MATRIZ_H

// Cria dinamicamente uma matriz de dimensão m x n,
// onde m representa o número mde linhas e n representa o número de colunas.
double** mat_cria (int m, int n);

// Libera a memória de uma matriz A previamente criada de m linhas.
void mat_libera (int m, double** A);

// Preenche a matriz T de dimensão n x m, matriz transposta da matriz A de dimensão m x n.
void mat_transposta (int m, int n, double** A, double** T);

// Preenche o vetor w de dimensão m com o resultado da multiplicação da matriz pelo vetor.
void mat_multv (int m, int n, double** A, double* v, double* w);

// Calcula a multiplicação de duas matrizes: C = AB. 
// A tem dimensão m x n, B tem dimensão n x q e C tem dimensão m x q.
void mat_multm (int m, int n, int q, double** A, double** B, double** C);

// Verifica se duas matrizes A e B são iguais, elemento a elemento, 
// considerando uma tolerância tol tal que a diferença entre dois elementos deve ser menor 
// que a tolerância para serem considerados iguais.
int mat_iguais (int m, int n, double** A, double** B, double to1);

// Imprime a matriz A no formato format especificado. 
void mat_imprime (int m, int n, double** A, char* format);

// Imprime o vetor V no formato especificado.
void vet_imprime (int n, double* V, char* format);

#endif
