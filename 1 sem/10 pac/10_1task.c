#include <stdio.h>
#include <stdlib.h>

//функция сравнения для qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

//функция бинарного поиска
int binary_search(int *arr, int size, int key) {
    int left = 0, right = size - 1; //задаем границы поиска

    while (left <= right) { //пока границы не пересеклись
        int mid = left + (right - left) / 2; //находим средний элемент

        if (arr[mid] == key) {
            return 1; //если средний элемент равен искомому, возвращаем 1 (найдено)
        }

        if (arr[mid] < key) {
            left = mid + 1; //если средний элемент меньше искомого, сдвигаем левую границу
        } else {
            right = mid - 1; //если средний элемент больше искомого, сдвигаем правую границу
        }
    }

    return 0; //если элемент не найден, возвращаем 0
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d", &N); //считываем количество элементов массива A

    int *A = (int *)malloc(N * sizeof(int)); //выделяем память для массива A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); //считываем элементы массива A
    }

    scanf("%d", &M); //считываем количество элементов массива B
    int *B = (int *)malloc(M * sizeof(int)); //выделяем память для массива B
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]); //считываем элементы массива B
    }

    //сортировка массива B
    qsort(B, M, sizeof(int), compare);

    //найти все элементы A, которых нет в B
    int *result = (int *)malloc(N * sizeof(int)); //выделяем память для результата
    int result_size = 0; //задаем размер результата

    for (int i = 0; i < N; i++) {
        if (!binary_search(B, M, A[i])) { //проверяем, есть ли элемент A[i] в массиве B
            result[result_size++] = A[i]; //если нет, добавляем его в результат
        }
    }

    //удаление дубликатов из результата
    qsort(result, result_size, sizeof(int), compare); //сортируем результат
    int unique_size = 0; //задаем размер уникальных элементов
    for (int i = 0; i < result_size; i++) {
        if (i == 0 || result[i] != result[i - 1]) { //проверяем на уникальность
            result[unique_size++] = result[i]; //добавляем уникальный элемент в результат
        }
    }

    //вывод результата
    printf("%d\n", unique_size); //выводим количество уникальных элементов
    for (int i = 0; i < unique_size; i++) {
        printf("%d ", result[i]); //выводим уникальные элементы
    }
    printf("\n");

    //освобождение памяти
    free(A);
    free(B);
    free(result);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
