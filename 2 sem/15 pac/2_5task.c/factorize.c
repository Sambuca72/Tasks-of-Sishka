typedef struct Factors
{
    int k; // Количество различных простых множителей
    int primes[32]; // Простые множители в порядке возрастания
    int powers[32]; // Их степени
} Factors;

// Разложение числа x
void Factorize(int X, Factors *res) 
{
    res->k = 0; // Обнуляем количество множителей
    if (X == 1) 
    {
        return;
    }

    // Проверяем делимость на 2
    int count = 0;
    while (X % 2 == 0)
    { 
        X /= 2;
        count++; // Увеличиваем степень
    }
    if (count > 0) // Если 2 встретилось хотя бы раз
    { 
        res->primes[res->k] = 2;  // Добавляем 2 в список простых множителей
        res->powers[res->k] = count; // Запоминаем степень 2
        res->k++; // Увеличиваем количество множителей
    }

    // Проверяем делимость на нечётные числа от 3 до sqrt(X)
    for (int p = 3; (long long)p * p <= X; p += 2) 
    {
        count = 0;
        while (X % p == 0)
        { 
            X /= p;
            count++;
        }
        if (count > 0)
        { 
            res->primes[res->k] = p; 
            res->powers[res->k] = count; 
            res->k++;
        }
    }

    // Если после всех проверок X > 1, значит, оно само является простым
    if (X > 1) 
    {
        res->primes[res->k] = X; 
        res->powers[res->k] = 1;
        res->k++;
    }
}
