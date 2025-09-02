#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100000
int N, M;
int *adj[MAX_SIZE], adj_size[MAX_SIZE];
int *trans_graph[MAX_SIZE], trans_size[MAX_SIZE]; 
int visit[MAX_SIZE], component[MAX_SIZE];
int order[MAX_SIZE]; // order - порядок выхода из вершин
int order_ind = 0, comp_num = 0;

void add_edge(int from, int to) 
{
    adj[from][adj_size[from]++] = to; 
    trans_graph[to][trans_size[to]++] = from; // Обратное направление транспонированному графу
}

// Запоминаем порядок выхода из вершин для правильного обхода транспонированного графа
void dfs1(int v) 
{
    visit[v] = 1;
    for (int i = 0; i < adj_size[v]; i++) 
    {
        int to = adj[v][i];
        if (!visit[to])
            dfs1(to);
    }
    order[order_ind++] = v;
}

// Посещаем все вершины достижимые из данной и помечаем их номером текущей компоненты
void dfs2(int v) 
{
    visit[v] = 1;
    component[v] = comp_num;
    for (int i = 0; i < trans_size[v]; i++) 
    {
        int to = trans_graph[v][i];
        if (!visit[to])
            dfs2(to);
    }
}

// Сортировка для упорядоченного ответа
int cmp(const void *a, const void *b) 
{
    return component[*(int*)a] - component[*(int*)b];
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) 
    {
        adj[i] = malloc(MAX_SIZE * sizeof(int));
        trans_graph[i] = malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < M; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    // DFS по графу для получения порядка завершения обхода вершин
    for (int i = 1; i <= N; i++)
        if (!visit[i])
            dfs1(i);
    
    memset(visit, 0, sizeof(visit));

    // DFS по транспонированному графу в порядке обратному order
    for (int i = order_ind - 1; i >= 0; i--) 
    {
        int v = order[i];
        if (!visit[v]) 
        {
            comp_num++;
            dfs2(v);
        }
    }
    printf("%d\n", comp_num);

    // Сортировки вершин по номеру компоненты через массив индексов
    int *increase = malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++)
        increase[i] = i; 
    qsort(increase + 1, N, sizeof(int), cmp);

    for (int i = 1; i <= N; i++)
        printf("%d ", component[increase[i]]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
