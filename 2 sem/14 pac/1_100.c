#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_N 10000
#define MAX_M 100000

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d", &N, &M);

    double *w = malloc(N * sizeof(double));
    double *a = malloc(N * sizeof(double));
    double *b = malloc(N * sizeof(double));

    for (int i = 0; i < N; ++i) {
        scanf("%lf %lf %lf", &w[i], &a[i], &b[i]);
    }

    for (int j = 0; j < M; ++j) {
        double x;
        scanf("%lf", &x);
        double sum = 0.0;
        for (int i = 0; i < N; ++i) {
            sum += w[i] * cos(a[i] * x + b[i]);
        }
        printf("%.20lf\n", sum);
    }
    free(w);
    free(a);
    free(b);
    return 0;
}
