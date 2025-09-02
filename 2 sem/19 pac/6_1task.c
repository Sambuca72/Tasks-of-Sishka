#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 12

int N, M; // Cтолбцы и строки
char board[MAX_SIZE][MAX_SIZE + 1];
char solution[MAX_SIZE][MAX_SIZE + 1]; // 'X' — ферзь, '.' — пусто
bool used_column[MAX_SIZE];
bool main_diag[2 * MAX_SIZE];
bool supp_diag[2 * MAX_SIZE];

// Расстановка ферзей
bool solve(int row) 
{
    if (row == M)
        return true;

    for (int column = 0; column < N; column++) 
    {
        // Варианты как может ходить ферзь
        if (board[row][column] == '.' || used_column[column] || main_diag[row + column] || 
            supp_diag[row - column + N])
            continue;

        // ставим ферзя
        used_column[column] = true;
        main_diag[row + column] = true;
        supp_diag[row - column + N] = true;
        solution[row][column] = 'X';

        // Расстановка ферзей в следующей строке
        if (solve(row + 1)) 
            return true;

        // если не получилось, то откатываем ферзя (backtraking)
        used_column[column] = false;
        main_diag[row + column] = false;
        supp_diag[row - column + N] = false;
        solution[row][column] = '.';
    }
    return false;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) 
    {
        scanf("%s", board[i]);

        // заполняем решение точками по умолчанию
        for (int j = 0; j < N; j++) 
        {
            solution[i][j] = '.';
        }
        solution[i][N] = '\0';
    }

    if (solve(0)) 
    {
        printf("YES\n");
        for (int i = 0; i < M; i++) 
        {
            printf("%s\n", solution[i]);
        }
    } 
    else 
    {
        printf("NO\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
