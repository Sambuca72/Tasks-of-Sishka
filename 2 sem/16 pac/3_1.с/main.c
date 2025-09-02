#include <stdio.h>
#include "myblas.h"

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {4.0, 5.0, 6.0};
    int n = 3;

    // Проверим ddot (скалярное произведение)
    double result = ddot(n, x, y);
    printf("ddot = %lf\n", result); // Должно быть 1*4 + 2*5 + 3*6 = 32

    // Проверим daxpy (y = y + alpha * x)
    daxpy(n, 2.0, x, y);
    printf("y после daxpy:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lf ", y[i]);
    }
    printf("\n");

    return 0;
}
