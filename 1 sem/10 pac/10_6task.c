#include <stdio.h>
#include <stdlib.h>

#define MAXN 400  //максимальное количество вершин

//структура для представления узла списка смежности
typedef struct Node {
    int vertex;  //номер вершины, на которую указывает ребро
    struct Node* next;  //указатель на следующий узел в списке смежности
} Node;

//структура для представления списка смежности
typedef struct {
    Node* head;  //голова списка смежности
} AdjList;

//структура для представления графа
typedef struct {
    AdjList* array;  //массив списков смежности
    int size;  //количество вершин в графе
} Graph;

//функция для создания нового узла списка смежности
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));  //выделение памяти для нового узла
    newNode->vertex = v;  //установка номера вершины
    newNode->next = NULL;  //установка следующего узла на NULL
    return newNode;  //возврат созданного узла
}

//функция для создания графа с заданным количеством вершин
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));  //выделение памяти для графа
    graph->size = vertices;  //установка количества вершин
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));  //выделение памяти для массива списков смежности
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;  //задаем голову списка смежности для каждой вершины
    }
    return graph;  //возврат созданного графа
}

//функция для добавления ребра в граф
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);  //создание нового узла для вершины dest
    newNode->next = graph->array[src].head;  //добавление нового узла в начало списка смежности вершины src
    graph->array[src].head = newNode;  //обновление головы списка смежности вершины src
}

//функция для топологической сортировки графа
void topologicalSort(Graph* graph, int inDegree[], int N) {
    int queue[MAXN], front = 0, rear = 0;  //очередь для хранения вершин с нулевой входящей степенью
    int topoOrder[MAXN], index = 0;  //массив для хранения топологического порядка и индекс текущей позиции

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {  //если входящая степень вершины равна 0
            queue[rear++] = i;  //добавление вершины в очередь
        }
    }

    while (front < rear) {  //пока очередь не пуста
        int u = queue[front++];  //извлечение вершины из очереди
        topoOrder[index++] = u;  //добавление вершины в топологический порядок

        Node* node = graph->array[u].head;  //получение головы списка смежности вершины u
        while (node != NULL) {  //пока есть смежные вершины
            int v = node->vertex;  //получение номера смежной вершины
            inDegree[v]--;  //уменьшение входящей степени смежной вершины
            if (inDegree[v] == 0) {  //если входящая степень смежной вершины стала 0
                queue[rear++] = v;  //добавление смежной вершины в очередь
            }
            node = node->next;  //переход к следующему узлу в списке смежности
        }
    }

    if (index == N) {  //если все вершины были добавлены в топологический порядок
        for (int i = 0; i < N; i++) {
            printf("%d ", topoOrder[i]);  //вывод топологического порядка
        }
        printf("\n");
    } else {
        printf("bad course\n");  //вывод bad course, если граф содержит цикл
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d", &N, &M);  //чтение количества вершин и ребер

    Graph* graph = createGraph(N + 1);  //создание графа с N+1 вершинами (индексация с 1)
    int inDegree[MAXN] = {0};  //задаем массив входящих степеней с нулями

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);  //чтение ребра (A, B)
        addEdge(graph, A, B);  //добавление ребра в граф
        inDegree[B]++;  //увеличение входящей степени вершины B
    }

    topologicalSort(graph, inDegree, N);  //топологическая сортировка графа
    fclose(stdin);
    fclose(stdout);
    return 0;
}
