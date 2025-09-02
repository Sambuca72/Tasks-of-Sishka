#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100005
int N, M;
int *adj[MAX_SIZE];
int adj_size[MAX_SIZE];
int degree[MAX_SIZE];
int order[MAX_SIZE];
int queue[MAX_SIZE];
int start = 0, finish = 0;

// Добавление ребра (u v)
void add_edge(int u, int v) 
{
    adj[u] = realloc(adj[u], (adj_size[u] + 1) * sizeof(int));
    adj[u][adj_size[u]++] = v;
    degree[v]++;
}

// Вставка вершин в очередь, где порядок по возрастанию
void insert(int v)
{
    int i = finish;
    while (i > start && queue[i - 1] > v) 
    {
        queue[i] = queue[i - 1];
        i--;
    }
    queue[i] = v;
    finish++;
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

    // Задаём очередь вершинами с нулевой входящей степенью
    for (int i = 1; i <= N; i++) 
    {
        if (degree[i] == 0) 
        {
            insert(i);
        }
    }

    // Порядковый номер в топологической сортировке
    int index = 1;
    while (start < finish)
    {
        int u = queue[start++];
        order[u] = index++;

        for (int i = 0; i < adj_size[u]; i++) 
        {
            int v = adj[u][i];
            degree[v]--;
            if (degree[v] == 0) 
            {
                insert(v);
            }
        }
    }

    // Если не все вершины были добавлены в порядок => в графе есть цикл
    if (index <= N) 
    {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= N; i++) 
        {
            printf("%d ", order[i]);
        }
        printf("\n");
    }

    for (int i = 1; i <= N; i++) 
    {
        free(adj[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
