#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_N 15000000
/*функция для нахождения всех простых чисел до N с помощью решета Эратосфена
 это алгоритм, который позволяет найти все простые числа вплоть до заданного целого числа n*/
void sieve_of_eratosthenes(bool *is_prime, int n) 
{
    //инициализация всех чисел как простых (true)
    for (int i = 2; i <= n; i++)
    {
        is_prime[i] = true;
    }
    //0 и 1 не являются простыми числами
    is_prime[0] = is_prime[1] = false;
    //проходим по всем числам от 2 до корня из n
    for (int i = 2; i * i <= n; i++) 
    {
        //если текущее число простое
        if (is_prime[i]) 
        {
            //отмечаем все кратные ему числа как составные
            for (int j = i * i; j <= n; j += i) 
            {
                is_prime[j] = false;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int max_num, quantity_z;
    scanf("%d %d", &max_num, &quantity_z);
    // Выделение динамической памяти для массива флагов простых чисел
    bool *is_prime = (bool *)malloc((max_num + 1) * sizeof(bool));
    //вычисляем простые числа до N с помощью решета Эратосфена
    sieve_of_eratosthenes(is_prime, max_num);
    //обработка каждого запроса
    for (int i = 0; i < quantity_z; i++) 
    {
        int X;
        scanf("%d", &X);
        //проверка, является ли X простым числом
        if (is_prime[X]) 
        {
            printf("%d prime\n", X);
        } 
        else 
        {
            printf("%d not\n", X);
        }
    }
    free(is_prime);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
