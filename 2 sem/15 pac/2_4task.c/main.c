// gcc -o program main.c query.c sum.c -lm 
// ./program
#include <stdio.h>  
#include <stdlib.h>
typedef long long int int64_t;
void Init(const int *arr, int n);
int64_t Sum(int l, int r);
int Query(int l, int64_t sum);

int main() 
{
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int N, M; // Кол-во эл-ов массива и кол-во запросов
    scanf("%d %d", &N, &M);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &A[i]);
    }

    Init(A, N);
    free(A);
    for (int i = 0; i < M; i++)
    {
        int L; // Позиция L 
        int64_t S; // Максимальная сумма S 
        
        scanf("%d %I64d", &L, &S); 
        printf("%d\n", Query(L, S));
    }
    fclose(stdin);
    fclose(stdout); 
    return 0;
}
