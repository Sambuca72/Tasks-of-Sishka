#include <stdio.h>
#define MAX_N 5000

int A[MAX_N]; // массив чисел
int dp[MAX_N]; // длина самой длинной возрастающей подпоследовательности
int prev[MAX_N]; 

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // инициализируем dp и prev
    for (int i = 0; i < N; i++) 
    {
        dp[i] = 1;
        prev[i] = -1; // пока нет предыдущего элемента

        // пробегаем все предыдущие элементы и ищем, можно ли продолжить возрастающую подпоследовательность
        for (int j = 0; j < i; j++) 
        {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) 
            {
                dp[i] = dp[j] + 1;
                prev[i] = j; // запоминаем откуда пришли
            }
        }
    }

    // ищем индекс с максимальным значением в dp
    int max_len = 0;
    int max_idx = 0;

    for (int i = 0; i < N; i++) 
    {
        if (dp[i] > max_len) 
        {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // восстанавливаем саму последовательность через prev
    int result_idx[MAX_N];
    int k = 0;

    for (int i = max_idx; i != -1; i = prev[i])
    result_idx[k++] = i;  // записываем текущий индекс и двигаемся к предыдущему
    printf("%d\n", max_len);

    for (int i = k - 1; i >= 0; i--)
        printf("A[%d] = %d\n", result_idx[i] + 1, A[result_idx[i]]);
    return 0;
}
