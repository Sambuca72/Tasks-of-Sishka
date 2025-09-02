#include <stdio.h>  
#include <stdlib.h>  

//функция для нахождения рефлексивно-транзитивного замыкания с использованием алгоритма флойда-уоршелла
void find_closure(int N, int **matrix) {
    //применение алгоритма флойда-уоршелла
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);  //обновление матрицы
            }
        }
    }

    //устанавливаем рефлексивность матрицы
    for (int i = 0; i < N; i++) {
        matrix[i][i] = 1;  //установка диагональных элементов в 1
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);  //чтение размера множества

    //выделение памяти для матрицы
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }

    //чтение матрицы смежности
    for (int i = 0; i < N; i++) {
        char line[N + 1];
        scanf("%s", line);  //чтение строки символов
        for (int j = 0; j < N; j++) {
            matrix[i][j] = line[j] - '0'; //преобразование символа в число
        }
    }

    //нахождение рефлексивно-транзитивного замыкания
    find_closure(N, matrix);

    //вывод результирующей матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matrix[i][j]);  //вывод элемента матрицы
        }
        printf("\n"); 
    }

    //освобождение выделенной памяти
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
