#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define MAX_SIZE 1001

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    int ways[MAX_SIZE];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;

    // перебираем все возможные слагаемые от 1 до N
    for (int i = 1; i <= N; i++) 
    {
        for (int j = i; j <= N; j++) 
        {
            ways[j] = (ways[j] + ways[j - i]) % MOD;
        }
    }

    printf("%d\n", ways[N]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
