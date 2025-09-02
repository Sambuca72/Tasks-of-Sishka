#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE_N 101
#define MAX_SIZE_K 10001
#define PASS 1000000

int N, M;
int capacity[MAX_SIZE_N][MAX_SIZE_N]; // Mатрица пропускных способностей
int flow[MAX_SIZE_N][MAX_SIZE_N];
int parent[MAX_SIZE_N];
int queue[MAX_SIZE_K]; 
int visited[MAX_SIZE_N];

// BFS: поиск увеличивающего пути от вершины s до t
int bfs(int s, int t) 
{
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    int start = 0, finish = 0;
    queue[finish++] = s;
    visited[s] = 1;

    // Пока очередь не пуста
    while (start < finish)
    {
        int current = queue[start++]; // Берём текущую вершину из очереди
        for (int next = 1; next <= N; next++)
        {
            int residual = capacity[current][next] - flow[current][next]; // Остаточная пропускная способность
            if (!visited[next] && residual > 0) 
            {
                queue[finish++] = next; // Добавляем в очередь
                parent[next] = current; // Запоминаем предка
                visited[next] = 1;
                if (next == t) 
                return 1;
            }
        }
    }
    return 0;
}

// Эдмондс-Карп: поиск максимального потока из s в t
int karp(int s, int t) 
{
    int res_flow = 0;
    while (bfs(s, t))
    {
        int path_flow = PASS; // Пропускная способность т.е сколько можно пропустить

        // Идём от стока к истоку и ищем минимальную остаточную пропускную способность
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            int residual = capacity[u][v] - flow[u][v];
            if (residual < path_flow)
                path_flow = residual;
        }

        // Идём от стока к истоку и обновляем потоки
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            flow[u][v] += path_flow; // Увеличиваем поток
            flow[v][u] -= path_flow;
        }
        res_flow += path_flow;
    }
    return res_flow;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        capacity[u][v] += c; // Неориентированный граф, то добавляем в обе стороны
        capacity[v][u] += c;
    }

    int result = karp(1, N);
    printf("%d\n", result);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
