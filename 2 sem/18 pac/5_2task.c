#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 200001

int N, M;
int head[MAX_SIZE];
int dist[MAX_SIZE];
int queue[MAX_SIZE];
int start_1 = 0, finish = 0;

typedef struct Edge 
{
    int to; // Конечная вершина ребра
    int next;
} Edge;
Edge edges[MAX_SIZE];
int quantity_e = 0;

void add_edge(int u, int v) 
{
    edges[quantity_e].to = v;
    edges[quantity_e].next = head[u];
    head[u] = quantity_e++;
}

void bfs(int start) 
{
    for (int i = 1; i <= N; i++) 
    {
        dist[i] = -1;
    }

    dist[start] = 0;
    queue[finish++] = start;

    while (start_1 < finish)
    {
        int u = queue[start_1++];
        for (int i = head[u]; i != -1; i = edges[i].next) // Обходим все рёбра, исходящие из u
        {
            int v = edges[i].to;
            if (dist[v] == -1) 
            {
                dist[v] = dist[u] + 1;
                queue[finish++] = v;
            }
        }
    }
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &M, &N);
    
    for (int i = 1; i <= N; i++) 
    {
        head[i] = -1;
    }

    for (int i = 0; i < M; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    bfs(1);

    for (int i = 1; i <= N; i++) 
    {
        printf("%d\n", dist[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
