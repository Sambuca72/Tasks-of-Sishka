#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_N 100000
#define MAX_SIZE_M 100000
int N, M;
int adj_size[MAX_SIZE_N] = {0};
int enter[MAX_SIZE_N], low[MAX_SIZE_N]; // enter - время входа, low - самое раннее достижимое время вершины
int visit[MAX_SIZE_N];
int bridge[MAX_SIZE_M];
int timer = 0; // Счётчик времени для DFS


typedef struct
{
    int to, num;
} Edge;
Edge *smezh[MAX_SIZE_N];

void add_edge(int u, int v, int id)
{
    // Добавляем ребро (u v)
    smezh[u] = realloc(smezh[u], (adj_size[u] + 1) * sizeof(Edge));
    smezh[u][adj_size[u]].to = v;
    smezh[u][adj_size[u]++].num = id;

    // Добавляем ребро (v u)
    smezh[v] = realloc(smezh[v], (adj_size[v] + 1) * sizeof(Edge));
    smezh[v][adj_size[v]].to = u;
    smezh[v][adj_size[v]++].num = id;
}

// DFS для поиска мостов
void dfs(int v, int parent_edge)
{
    visit[v] = 1; 
    enter[v] = low[v] = timer++; 

    for (int i = 0; i < adj_size[v]; i++) 
    {
        int to = smezh[v][i].to; 
        int id = smezh[v][i].num;

        if (id == parent_edge)
        continue; // не идем по ребру, по которому только что пришли

        if (visit[to]) 
        {
            // Обновляем low, если это обратное ребро
            if (low[v] > enter[to])
                low[v] = enter[to];
        } else 
        {
            dfs(to, id);

            // Обновляем low после выхода из рекурсии
            if (low[v] > low[to])
                low[v] = low[to];

            // Если ни через какие обходные пути нельзя вернуться вверх - мост
            if (low[to] > enter[v]) 
            {
                bridge[id] = 1;
            }
        }
    }
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v, i);
    }

    for (int i = 1; i <= N; i++) 
    {
        if (!visit[i])
            dfs(i, -1); // -1 — нет родительского ребра на старте
    }

    int count_bridge = 0;
    for (int i = 1; i <= M; i++) 
    {
        if (bridge[i])
        count_bridge++;
    }
    printf("%d\n", count_bridge);

    for (int i = 1; i <= M; i++) 
    {
        if (bridge[i])
            printf("%d ", i);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
