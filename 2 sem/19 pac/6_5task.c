#include <stdio.h>
#include <string.h>
#define MAX 100
int A, B, C;
int g[MAX][MAX]; // матрица совместимости
int targ[MAX]; 
char used[MAX]; 

int dfs(int u)
{
    for (int v = 1; v <= B; ++v)  // перебираем все задания
    {
        if (g[u][v] && !used[v])
        {
            used[v] = 1;  

            if (targ[v] == 0 || dfs(targ[v]))
            {
                targ[v] = u;  // назначаем ученика u на задание v
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &A, &B, &C);

    // Считываем совместимости ученик x может выполнить задание y
    for (int i = 0; i < C; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
    }

    int res = 0;
    // Назначаем каждому ученику задания
    for (int u = 1; u <= A; ++u)
    {
        memset(used, 0, sizeof(used));  
        if (dfs(u)) // если получилось назначить
        {
            res++;
        }
    }
    printf("%d\n", res);

    for (int v = 1; v <= B; ++v)
    {
        if (targ[v])
        {
            printf("%d %d \n", targ[v], v);
        }
    }
    return 0;
}
