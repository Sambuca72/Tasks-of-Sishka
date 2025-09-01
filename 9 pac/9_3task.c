#include <stdio.h>  
#include <stdlib.h> 

//функция сравнения для qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); //сравнивает два элемента массива
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n); //количество элементов в массиве

    int *A = (int *)malloc(n * sizeof(int)); //выделение памяти для массива A
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); //считывание элементов массива
    }

    //сортировка массива
    qsort(A, n, sizeof(int), compare); //использование qsort для сортировки массива

    //вычисление суммы минимумов
    long long sum = 0; //задаем сумму
    for (int i = 0; i < n; i++) {
        sum += (long long)A[i] * (n - i - 1); //суммирование произведений A[i] и (n - i - 1)
    }
    printf("%lld\n", sum);
    free(A);
    fclose(stdin);
    fclose(stdout);
    return 0; 
}
