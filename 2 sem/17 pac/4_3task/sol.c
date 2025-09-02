#include "sol.h"
#include <stdlib.h>
#define MAXN 300000

static Edge *adj[MAXN];  // массив указателей на массив рёбер инцидентных каждой вершине
static int deg[MAXN];
static int cap[MAXN]; // текущая вместимость выделенной памяти под рёбра у каждой вершины

void init() 
{
    int n = getVerticesCount();

    // Инициализация массивов для каждой вершины
    for (int i = 0; i < n; ++i) 
    {
        deg[i] = 0;
        cap[i] = 4; // стартовая вместимость под 4 ребра
        adj[i] = (Edge *)malloc(cap[i] * sizeof(Edge));
    }
    Edge e;
    
    // Читаем рёбра по одному, пока есть
    while (readEdge(&e)) 
    {

        // Если памяти под рёбра недостаточно — увеличиваем в 2 раза
        if (deg[e.from] >= cap[e.from]) 
        {
            cap[e.from] *= 2;
            adj[e.from] = (Edge *)realloc(adj[e.from], cap[e.from] * sizeof(Edge));
        }

        // Копируем ребро как есть с сохранением to, weight
        Edge edge1 = e;
        edge1.to = e.to; 
        adj[e.from][deg[e.from]++] = edge1;  // сохраняем и увеличиваем счётчик рёбер

        // === Добавляем это же ребро в список инцидентности вершины e.to ===
        if (deg[e.to] >= cap[e.to]) 
        {
            cap[e.to] *= 2;
            adj[e.to] = (Edge *)realloc(adj[e.to], cap[e.to] * sizeof(Edge));
        }

        Edge edge2 = e;
        edge2.to = e.from;  // зеркальное отображение — чтобы в списке у вершины to "другой конец" был from
        adj[e.to][deg[e.to]++] = edge2;
    }
}

// Возвращает количество рёбер, инцидентных вершине iVertex
int getEdgesCount(int iVertex) 
{
    return deg[iVertex];
}

// Возвращает iIndex-е ребро из списка рёбер, инцидентных вершине iVertex
Edge getIncidentEdge(int iVertex, int iIndex) 
{
    Edge e = adj[iVertex][iIndex];  // получаем ребро из массива
    e.from = iVertex;
    return e;
}

