#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double my_stepen(double ch1, int ch2) {
    double res = 1;
    while (ch2 > 0) {
        res *= ch1;
        ch2--;
    }
    return res;
}

double my_factorial(int i) {
    if (i <= 1) return 1;
    double res = 1;
    for (int j = 2; j <= i; j++) {
        res *= j;
    }
    return res;
}

double my_element(int i, double x) {
    return my_stepen(x, i) / my_factorial(i);
}

double my_sin(double x) {
    double res = 0;
    double term;
    int sign = 1;
    for (int i = 1; i < 90; i += 2) { // Достаточное количество членов
        term = my_element(i, x);
        res += term * sign;
        sign *= -1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        double rad_value;
        scanf("%lf", &rad_value);
        printf("%.15lf\n", my_sin(rad_value));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}