#pragma comment(linker, "/STACK:500000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000
int N;
char lab[MAX_N][MAX_N]; 
int visit[MAX_N][MAX_N];
typedef struct 
{
    int x, y;
} Point;

Point queue[MAX_N * MAX_N];
int start, finish;

void bfs(int x, int y) 
{
    start = finish = 0;
    queue[finish++] = (Point){x, y};
    visit[x][y] = 1;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (start < finish) 
    {
        Point p = queue[start++]; 
        for (int dir = 0; dir < 4; dir++) 
        {
            int nx = p.x + dx[dir]; 
            int ny = p.y + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && lab[nx][ny] == ' ' && !visit[nx][ny]) 
                {
                visit[nx][ny] = 1; 
                queue[finish++] = (Point){nx, ny}; 

            }
        }
    }
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) 
    {
        fgets(lab[i], MAX_N, stdin);
        lab[i][strcspn(lab[i], "\r\n")] = '\0';
    }

    int start_y = -1;
    for (int j = 0; j < N; j++) 
    {
        if (lab[0][j] == ' ')
        {
            start_y = j;
            break;
        }
    }

    if (start_y != -1) 
    {
        bfs(0, start_y);
    }

    int neVxod = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (lab[i][j] == ' ' && !visit[i][j]) 
            {
                bfs(i, j);
                neVxod++;
            }
        }
    }
    printf("%d\n", neVxod);
    return 0;
}