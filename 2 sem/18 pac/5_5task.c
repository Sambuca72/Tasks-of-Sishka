#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 200001
int N, M;
int *adj[MAX_SIZE]; // Списки смежности
int adj_size[MAX_SIZE] = {0};
int parent[MAX_SIZE];
bool visit[MAX_SIZE];
bool dfs_stack[MAX_SIZE];
int start = -1, end = -1; // Начало и конец цикла

void add_edge(int u, int v) 
{
    adj[u] = realloc(adj[u], (adj_size[u] + 1) * sizeof(int));
    adj[u][adj_size[u]++] = v;
}

// DFS для поиска цикла
bool dfs(int v) 
{
    visit[v] = true;
    dfs_stack[v] = true;

    for (int i = 0; i < adj_size[v]; i++) 
    {
        // Берём i-го соседа вершины v
        int neigbor = adj[v][i];
        if (!visit[neigbor])
        {
            parent[neigbor] = v; 
            if (dfs(neigbor))
            return true; 
        }
        else if (dfs_stack[neigbor]) // Нашли цикл
        {
            start = neigbor;
            end = v;
            return true;
        }
    }
    dfs_stack[v] = false;
    return false;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    // Запускаем DFS из каждой непосещённой вершины
    for (int i = 1; i <= N; i++) 
    {
        if (!visit[i]) 
        {
            if (dfs(i)) 
                break;
        }
    }

    if (start == -1)
    {
        printf("-1\n");
    } 
    else 
    {
        int cycle[MAX_SIZE];
        int vertex = 0;

        // Восстановление пути от конца до начала
        for (int v = end; v != start; v = parent[v]) 
        {
            cycle[vertex++] = v;
        }
        cycle[vertex++] = start;

        // Разворачиваем массив, чтобы получить ответ по возрастанию
        for (int i = 0; i < vertex / 2; i++) 
        {
            int tmp = cycle[i];
            cycle[i] = cycle[vertex - 1 - i];
            cycle[vertex - 1 - i] = tmp;
        }

        // Ищем индекс минимальной вершины, чтобы начать вывод с неё
        int index = 1;
        for (int i = 1; i < vertex; i++) 
        {
            if (cycle[i] < cycle[index]) 
            {
                index = i;
            }
        }
        printf("%d\n", vertex);
        
        for (int i = 0; i < vertex; i++) 
        {
            printf("%d ", cycle[(index + i) % vertex]);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}