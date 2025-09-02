#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 300
#define MAXM 50000
#define INF 1000000

typedef struct Node 
{
    int to, weight;
    struct Node* next;
} Node;


// Граф в виде списка смежности
Node* adj[MAXN];

// Массивы для алгоритма Дейкстры
int dist[MAXN];     // кратчайшие расстояния
int prev[MAXN];     // массив для восстановления пути
char used[MAXN];    // какие вершины уже обработаны

// Запросы
typedef struct {
    int from, to;
} Query;

Query time_queries[10000];   // R штук — только время
Query path_queries[10000];   // K штук — с восстановлением пути

int R, K;  // количество запросов

// Добавление ребра в граф (двустороннее)
void add_edge(int u, int v, int w) {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->to = v;
    node1->weight = w;
    node1->next = adj[u];
    adj[u] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->to = u;
    node2->weight = w;
    node2->next = adj[v];
    adj[v] = node2;
}

// Алгоритм Дейкстры
void dijkstra(int start, int n) {
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        prev[i] = -1;
        used[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;

        // ищем неиспользованную вершину с минимальным расстоянием
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if (dist[v] == INF) break;  // все оставшиеся вершины недостижимы
        used[v] = 1;

        // проходим по соседям
        for (Node* e = adj[v]; e != NULL; e = e->next) {
            int to = e->to;
            int len = e->weight;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                prev[to] = v;
            }
        }
    }
}

// Восстанавливаем путь и печатаем
void print_path(int from, int to) {
    int path[MAXN];
    int length = 0;
    int cur = to;
    while (cur != -1) {
        path[length++] = cur;
        cur = prev[cur];
    }

    printf("%d ", dist[to]);       // общее время
    printf("%d ", length);         // количество вершин в пути

    for (int i = length - 1; i >= 0; --i)
        printf("%d ", path[i] + 1);  // +1, потому что вершины с 1
    printf("\n");
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d %d %d", &N, &M, &R, &K);

    // читаем рёбра
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u - 1, v - 1, w);  // -1, чтобы были индексы от 0
    }

    // читаем R запросов только времени
    for (int i = 0; i < R; ++i) {
        scanf("%d %d", &time_queries[i].from, &time_queries[i].to);
        time_queries[i].from--;
        time_queries[i].to--;
    }

    // читаем K запросов с путём
    for (int i = 0; i < K; ++i) {
        scanf("%d %d", &path_queries[i].from, &path_queries[i].to);
        path_queries[i].from--;
        path_queries[i].to--;
    }

    // обрабатываем R запросов
    for (int i = 0; i < R; ++i) {
        int from = time_queries[i].from;
        int to = time_queries[i].to;
        dijkstra(from, N);
        printf("%d\n", dist[to]);
    }

    // обрабатываем K запросов
    for (int i = 0; i < K; ++i) {
        int from = path_queries[i].from;
        int to = path_queries[i].to;
        dijkstra(from, N);
        print_path(from, to);
    }

    return 0;
}
