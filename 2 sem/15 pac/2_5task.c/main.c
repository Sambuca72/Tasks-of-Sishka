//gcc -o program main.c factorize.c -lm
#include <stdio.h>  
#include <stdlib.h> 

typedef struct Factors 
{
    int k;
    int primes[32]; 
    int powers[32]; 
} Factors;

void Factorize(int X, Factors *res);

int main() 
{
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 

    int number1;
    scanf("%d", &number1); 

    for (int i = 0; i < number1; i++) 
    {
        int number2;
        scanf("%d", &number2);

        Factors res;
        Factorize(number2, &res); // Вызываем функцию разложения

        // Вывод разложения
        printf("%d = ", number2);
        if (res.k == 0) // Если k = 0, значит число X = 1
        { 
            printf("1\n");
        } else 
        {
            for (int j = 0; j < res.k; j++) 
            {
                if (j > 0) printf(" * ");
                printf("%d^%d", res.primes[j], res.powers[j]); // Выводим p^t
            }
            printf("\n");
        }
    }

    fclose(stdin);  
    fclose(stdout); 

    return 0;
}
