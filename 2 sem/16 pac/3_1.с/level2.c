#include "myblas.h"
#include <stdlib.h>

//dgemv — матрично-векторное умножение (alpha * A * X + beta * Y) 
void dgemv(int m, int n, double alpha, const double *A, const double *X, double beta, double *Y)
{


    for(int i = 0; i < m; i++)
    {
        double temp =0.0;
        for(int j = 0; j < n; j++)
        {
            temp += A[j + i * n] * X[j];
        }
        Y[i] = alpha * temp + beta * Y[i];
    }

    
}

//dger — ранговое обновление матрицы A по формуле (alpha * X * Y^T + A)
void dger (int m, int n, double alpha, const double *X, const double *Y, double *A)
{

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A[j + i * n] += X[i] * Y[j];   
        }

    }

}


