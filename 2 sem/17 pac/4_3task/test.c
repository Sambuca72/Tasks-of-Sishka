#include <stdio.h>
#include "sol.h"

// Пример графа как в условии
Edge testEdges[] = {
    {0, 2, 178},
    {3, 4, 207},
    {1, 1, 356},
    {2, 0, 101},
    {4, 1, 286},
    {4, 1, 213}
};

int edgeCount = sizeof(testEdges) / sizeof(testEdges[0]);
int edgeIndex = 0;

int getVerticesCount() {
    return 5;
}

int readEdge(Edge* oEdge) {
    if (edgeIndex < edgeCount) {
        *oEdge = testEdges[edgeIndex++];
        return 1;
    }
    return 0;
}

int main() {
    printf("init()\n");
    init();

    int count;

    count = getEdgesCount(0);
    printf("%d = getEdgesCount(0)\n", count);
    for (int i = 0; i < count; ++i) {
        Edge e = getIncidentEdge(0, i);
        printf("[%d, %d, %d] = getIE(0, %d)\n", e.from, e.to, e.weight, i);
    }

    count = getEdgesCount(1);
    printf("%d = getEdgesCount(1)\n", count);
    for (int i = 0; i < count; ++i) {
        Edge e = getIncidentEdge(1, i);
        printf("[%d, %d, %d] = getIE(1, %d)\n", e.from, e.to, e.weight, i);
    }

    count = getEdgesCount(2);
    printf("%d = getEdgesCount(2)\n", count);
    for (int i = 0; i < count; ++i) {
        Edge e = getIncidentEdge(2, i);
        printf("[%d, %d, %d] = getIE(2, %d)\n", e.from, e.to, e.weight, i);
    }

    count = getEdgesCount(3);
    printf("%d = getEdgesCount(3)\n", count);
    for (int i = 0; i < count; ++i) {
        Edge e = getIncidentEdge(3, i);
        printf("[%d, %d, %d] = getIE(3, %d)\n", e.from, e.to, e.weight, i);
    }

    count = getEdgesCount(4);
    printf("%d = getEdgesCount(4)\n", count);
    for (int i = 0; i < count; ++i) {
        Edge e = getIncidentEdge(4, i);
        printf("[%d, %d, %d] = getIE(4, %d)\n", e.from, e.to, e.weight, i);
    }

    return 0;
}
