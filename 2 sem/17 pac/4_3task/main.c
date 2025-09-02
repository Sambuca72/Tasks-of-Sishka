#include <stdio.h>
#include "sol.h"

//  Массив рёбер графа
Edge edges[] = 
{
    {0, 2, 178},
    {3, 4, 207},
    {1, 1, 356},
    {2, 0, 101},
    {4, 1, 286},
    {4, 1, 213}
};

int edge_idx = 0; // индекс текущего ребра

// Возвращаем количество вершин в графе
int getVerticesCount() 
{
    return 5; // в нашем примере вершин от 0 до 4
}

// Возвращаем следующее ребро из списка edges
// Если рёбра есть — кладёт в *oEdge
// Если рёбер больше нет — 0
int readEdge(Edge *oEdge) 
{
    if (edge_idx < sizeof(edges) / sizeof(edges[0])) 
    {
        *oEdge = edges[edge_idx++]; // копируем следующее ребро
        return 1;
    }
    return 0;
}

int main() 
{
    printf("init()\n");
    init(); // инициализируем граф — вызываем функцию из sol.c

    for (int v = 0; v < getVerticesCount(); ++v) 
    {
        // Получаем количество рёбер, инцидентных вершине v
        int cnt = getEdgesCount(v);
        printf("%d = getEdgesCount(%d)\n", cnt, v);

        // Выводим каждое инцидентное ребро
        for (int i = 0; i < cnt; ++i) 
        {
            Edge e = getIncidentEdge(v, i);
            printf("[%d, %d, %d] = getIE(%d, %d)\n", e.from, e.to, e.weight, v, i);
        }
    }
    return 0;
}
//gcc -o graph.exe sol.c main.c