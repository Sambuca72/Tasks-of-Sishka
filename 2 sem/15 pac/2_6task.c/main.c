//gcc -o program main.c derivative.c func.c -lm
// ./program

#include <stdio.h>
#include <stdlib.h>
double deriv(double x, double h);

int main() 
{
    FILE *input = fopen("input.txt", "r");
    int point;
    fscanf(input, "%d", &point);
    double x;
    double h = 1e-6;

    for (int i = 0; i < point; i++) 
    {
        fscanf(input, "%lf", &x);
        printf("%.15lf\n", deriv(x, h));
    }
    fclose(input);
    return 0;
}
