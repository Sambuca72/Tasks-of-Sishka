#include <stdio.h>
#include <stdlib.h>

//функция для применения алгоритма Флойда-Уоршелла
void floydWarshall(int **R, int N) {
    //внешний цикл по промежуточным вершинам
    for (int k = 0; k < N; k++) {
        //цикл по стартовым вершинам
        for (int i = 0; i < N; i++) {
            //цикл по конечным вершинам
            for (int j = 0; j < N; j++) {
                //обновление матрицы достижимости
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }
}

//функция для обеспечения рефлексивности
void ensureReflexivity(int **R, int N) {
    //установка диагональных элементов в 1
    for (int i = 0; i < N; i++) {
        R[i][i] = 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    //чтение размера матрицы
    scanf("%d", &N);

    //выделение памяти для матрицы
    int **R = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        R[i] = (int *)malloc(N * sizeof(int));
    }

    //чтение матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &R[i][j]);
        }
    }

    //применение алгоритма Флойда-Уоршелла
    floydWarshall(R, N);

    //обеспечиваем рефлексивности
    ensureReflexivity(R, N);

    //вывод результирующей матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", R[i][j]);
        }
        printf("\n");
    }

    //освобождение выделенной памяти
    for (int i = 0; i < N; i++) {
        free(R[i]);
    }
    free(R);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
