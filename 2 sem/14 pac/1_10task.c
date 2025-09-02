#include <stdio.h>
#include <math.h>
#define MAX_N 10000
#define MAX_M 100000
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M; // N - количество слагаемых, M - количество точек для подсчёта функции
    scanf("%d %d", &N, &M);

    double w[MAX_N], a[MAX_N], b[MAX_N];
    for (int i = 0; i < N; i++) 
    {
        scanf("%lf %lf %lf", &w[i], &a[i], &b[i]);
    }

    for (int j = 0; j < M; j++) 
    {
        double x;
        scanf("%lf", &x);
        double res = 0.0;
        for (int i = 0; i < N; i++) 
        {
            res += w[i] * cos(a[i] * x + b[i]);
        }
        printf("%.20lf\n", res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0; 
}

