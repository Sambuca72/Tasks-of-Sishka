#include "myblas.h"
#include <stdlib.h>

//dgemm — матричное произведение с весами:
void dgemm(int m, int n, int k, double alpha, const double *A, const double *B, double beta, double *C)
{
    {    
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                double AxB = 0.0;
                for (int u = 0; u < k; u++) {
                    AxB += A[i * k + u] * B[u * n + j];
                }   
                C[i * n + j] = C[i * n + j] * beta + alpha * AxB;
            }
        }
    }
}