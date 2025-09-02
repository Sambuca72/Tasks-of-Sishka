#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 5000
#define MAX_M 50000
#define INF 1000000000

typedef struct 
{
    int from, to, weight;
} Edge;

Edge edges[MAX_M];
int dist[MAX_N]; // кратчайшие расстояния от вершины 1
int prev[MAX_N]; // восстановление пути т.е предыдущие вершины
int path[MAX_N]; 

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int friends[K]; // вершины-дома друзей
    for (int i = 0; i < K; ++i)
        scanf("%d", &friends[i]);

    for (int i = 0; i < M; ++i)
        scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);

    // все расстояния считаем бесконечными, кроме начальной вершины
    for (int i = 1; i <= N; ++i) 
    {
        dist[i] = INF;
        prev[i] = -1;                                
    }
    dist[1] = 0; // Живём в вершине 1, там расстояние 0

    // Алгоритм Беллмана-Форда
    for (int i = 0; i < N - 1; ++i) 
    {
        for (int j = 0; j < M; ++j) 
        {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;

            // если от u до v можно дойти короче через текущее ребро
            if (dist[u] != INF && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w; // обновляем расстояние
                prev[v] = u; // запоминаем путь
            }
        }
    }

    // Для каждого друга восстанавливаем путь
    for (int i = 0; i < K; i++) 
    {
        int v = friends[i]; // вершина, где живёт i-й друг
        int len = 0;
        int current = v;
        while (current != -1) 
        {
            path[len++] = current; // добавляем текущую вершину в путь
            current = prev[current]; // переходим к предыдущей вершине
        }
        printf("%d %d", dist[v], len);

        for (int j = len - 1; j >= 0; j--)
            printf(" %d", path[j]);
        printf("\n");
    }

    return 0;
}
