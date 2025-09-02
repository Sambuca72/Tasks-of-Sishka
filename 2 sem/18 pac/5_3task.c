#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct 
{
    int x, y;
} Point;

typedef struct 
{
    Point position;
    int distance; // Количество шагов от старта до этой клетки
} Node;

// Направления движения - вверх, вниз, влево, вправо
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char maze[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
Node queue[MAX_SIZE * MAX_SIZE];
int front = 0, end = 0;
int rows, cols;

void enqueue(Point pos, int dist) {
    queue[end++] = (Node){pos, dist};
}

Node dequeue() {
    return queue[front++];
}

int empty() {
    return front == end;
}

int bfs(Point start, Point finish) 
{
    enqueue(start, 0);
    visit[start.x][start.y] = 1;

    while (!empty()) 
    {
        Node current = dequeue();
        Point p = current.position;

        if (p.x == finish.x && p.y == finish.y) 
        {
            return current.distance;
        }

        for (int i = 0; i < 4; ++i) 
        {
            int newRow = p.x + dx[i];
            int newCol = p.y + dy[i];

            // Проверка: в пределах ли лабиринта, не посещено ли уже и не стена ли
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                !visit[newRow][newCol] && maze[newRow][newCol] != 'X') 
                {
                visit[newRow][newCol] = 1;
                enqueue((Point){newRow, newCol}, current.distance + 1);
            }
        }
    }
    return -1;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &rows, &cols);
    Point start, goal;

    for (int i = 0; i < rows; ++i) 
    {
        scanf("%s", maze[i]);
        for (int j = 0; j < cols; ++j) 
        {
            if (maze[i][j] == 'S') 
            {
                start = (Point){i, j};
            }
            if (maze[i][j] == 'F') 
            {
                goal = (Point){i, j};
            }
        }
    }

    int res = bfs(start, goal);
    printf("%d\n", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
