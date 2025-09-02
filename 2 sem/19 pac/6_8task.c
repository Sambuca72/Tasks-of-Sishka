#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE_N 200
#define MAX_SIZE_W 50000 
int dp[MAX_SIZE_N][MAX_SIZE_W]; // Max суммарная стоимость 
int wght[MAX_SIZE_N], cost[MAX_SIZE_N];
int items[MAX_SIZE_N];

// Нахождение максимума двух чисел
int max(int a, int b)
{
    int result;
    if (a > b)
        result = a;
    else
        result = b;
    return result;
}

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, W;
    scanf("%d %d", &N, &W);  // Предметы и вместимость

    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &wght[i], &cost[i]); 

    // Заполнение динамической таблицы
    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 0; j <= W; ++j)
        {
            if (j >= wght[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - wght[i]] + cost[i]); 
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // Находим какие предметы были выбраны
    int price = dp[N][W];
    int weight = 0;
    int count_items = 0;
    int j = W;

    // Идём назад по предметам, чтобы нужные включить в решение
    for (int i = N; i >= 1; i--)
    {
        if (j >= wght[i] && dp[i][j] == dp[i-1][j - wght[i]] + cost[i]) 
        {
            items[count_items++] = i;
            j -= wght[i];          // уменьшаем оставшийся вес
            weight += wght[i];     // увеличиваем суммарный вес
        }
    }

    printf("%d %d %d\n", count_items, weight, price);
    qsort(items, count_items, sizeof(int), compare);
    for (int i = 0; i < count_items; ++i) 
    {
        printf("%d ", items[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
