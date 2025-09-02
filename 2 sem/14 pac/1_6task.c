#include <stdio.h>
#define MOD 1000000007
#define N_MAX 1000000

// Глобальные массивы под факториалы и обратные факториалы
static long long fact[N_MAX + 1];
static long long inv_fact[N_MAX + 1];

// Функция быстрого возведения в степень по модулю
long long mod_pow(long long base, int exp, long long m) 
{
    // Начинаем с результата == 1 
    long long result = 1;

    // Пока показатель степени не обнулится
    while (exp > 0) 
    {
        // Если степень == 1
        if (exp & 1) 
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;

        // Сдвигаем степень вправо на 1 бит тоже самое, что деление exp на 2
        exp >>= 1;
    }
    // Возвращаем результат (base^exp % m)
    return result;
}


// Функция для предварительного вычисления факториалов и обратных факториалов
void precomp_fact() 
{
    // Вычисляем факториалы: fact[i] = i! mod MOD
    fact[0] = 1;
    for (int i = 1; i <= N_MAX; i++) 
    {
        // Вычисляем i!, сразу беря остаток по модулю MOD
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Вычисляем обратный факториал для N_MAX
    inv_fact[N_MAX] = mod_pow(fact[N_MAX], MOD - 2, MOD);

    // Вычисляем обратные факториалы для остальных чисел по убыванию
    // Это позволяет восстановить все значения, используя ранний inv_fact[N_MAX]
    for (int i = N_MAX; i > 0; i--) 
    {
        inv_fact[i - 1] = (inv_fact[i] * i) % MOD;
    }
}


// Функция для вычисления биномиального коэффициента C(n, k) по модулю MOD
long long binom_coef(int n, int k) 
{
    if (k < 0 || k > n) return 0;

    // Используем заранее вычисленные факториалы и обратные факториалы:    
    // Начинаем с факториала n (fact[n] = n!)
    long long result = fact[n];

    // Умножаем на обратный факториал k (inv_fact[k] = (k!)^(MOD-2) mod MOD),
    result = (result * inv_fact[k]) % MOD;
    result = (result * inv_fact[n - k]) % MOD;
    return result;
}


int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // Предварительно вычислим факториалы и обратные факториалы
    precomp_fact();
    int T;
    scanf("%d", &T);

    while (T--) 
    {
        int N, K;
        scanf("%d %d", &N, &K);
        long long answer = binom_coef(N, K);
        printf("%lld\n", answer);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
