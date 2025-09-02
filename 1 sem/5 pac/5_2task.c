#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
//массив для хранения всех биномиальных значений
//binom[n][k] это C(n, k)
double binom[MAX_N + 1][MAX_N + 1];
//функция для построения треугольника Паскаля
void compute_binomials() {
    //для каждого значения n от 0 до MAX_N(1000)
    for (int n = 0; n <= MAX_N; n++) 
    {
        binom[n][0] = 1;  //каждый коэффициент C(n, 0) == 1
        //вычисляем значения для C(n, k) при 1 <= k <= n
        for (int k = 1; k <= n; k++) 
        {
            //используем рекуррентную формулу треугольника Паскаля:
            binom[n][k] = binom[n - 1][k - 1] + binom[n - 1][k];
        }
    }
}
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int zaprosi;
    scanf("%d", &zaprosi);
    //вычисляем все биномиальные значения до MAX_N с помощью треугольника Паскаля
    compute_binomials();
    //обрабатываем каждый запрос
    for (int i = 0; i < zaprosi; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%0.10g\n", binom[n][k]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
