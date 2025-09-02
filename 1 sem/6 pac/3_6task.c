#include <stdio.h>
#include <stdlib.h>

//функция сравнения для qsort
//сравнивает два элемента и возвращает разницу между ними
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/*бинарный поиск для проверки наличия элемента
принимает массив, его размер и искомый элемент (target) будет
возвращать 1, если элемент найден, и 0, если нет*/
int binary_search(int *array, int size, int target) 
{
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; //находим середину
        if (array[mid] == target) return 1; //если найден, возвращаем 1
        if (array[mid] < target) left = mid + 1; //ищем в правой половине
        else right = mid - 1; //ищем в левой половине
    }
    return 0; //если элемент не найден, возвращаем 0
}
int main() 
{
    int N, M;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //основной цикл для обработки тестовых случаев, пока удается прочитать значение N
    while (scanf("%d", &N) == 1) 
    {
        //динамическое выделение памяти для массива A
        int *A = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) 
        {
            scanf("%d", &A[i]);
        }
        //читаем размер массива B и выделяем для него память
        scanf("%d", &M);
        int *B = (int *)malloc(M * sizeof(int));
        for (int i = 0; i < M; i++) 
        {
            scanf("%d", &B[i]);
        }
        //сортируем массив B, чтобы можно было использовать бинарный поиск
        qsort(B, M, sizeof(int), compare);
        //выделяем память для массива результата
        int *result = (int *)malloc(N * sizeof(int));
        int count = 0; //счетчик уникальных элементов

        //поиск уникальных элементов, которые присутствуют в A, но отсутствуют в B
        for (int i = 0; i < N; i++) {
            //пропускаем дубликаты в массиве A, чтобы каждый уникальный элемент добавлялся только один раз
            if (i > 0 && A[i] == A[i - 1]) continue;

            //проверка на отсутствие элемента в B с помощью бинарного поиска
            if (!binary_search(B, M, A[i])) {
                result[count++] = A[i]; //добавляем элемент в результат
            }
        }
        //выводим количество уникальных элементов
        printf("%d\n", count);
        //выводим сами уникальные элементы
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        if (count > 0) printf("\n"); //переход на новую строку, если есть элементы
        free(A);
        free(B);
        free(result);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}



