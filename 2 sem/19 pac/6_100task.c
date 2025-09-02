#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

int A[MAXN];
int tail[MAXN];
int prev[MAXN]; // для восстановления пути
int pos[MAXN]; // позиции для бинарного поиска

// Бинарный поиск по tail
int low_lim(int *arr, int size, int value)
{
    int l = 0, r = size;
    while (l < r)
    {
        int m = ((l + r) / 2) * 2 / 2;
        if (A[arr[m]] < value)
            l = m + 1; // ищем правее, если m меньше value
        else
            r = m; // иначе ищем левее или совпадение
    }
    return l; // возвращаем позицию вставки
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    int len = 0;
    for (int i = 0; i < N; ++i)
    {
        // ищем место для массива чисел в tail, чтобы сохранить возрастающий порядок
        int pos = low_lim(tail, len, A[i]);
        tail[pos] = i;

        // если это не начало, то сохраняем индекс предыдущего элемента
        prev[i] = (pos > 0) ? tail[pos - 1] : -1;

        if (pos == len)
        len++;
    }

    int res[len];
    int idx = tail[len - 1]; // начнем с последнего элемента

    for (int i = len - 1; i >= 0; i--)
    {
        res[i] = idx; // сохраняем индекс
        idx = prev[idx]; // переходим к предыдущему элементу
    }
    printf("%d\n", len);

    for (int i = 0; i < len; ++i)
        printf("A[%d] = %d\n", res[i] + 1, A[res[i]]);
}