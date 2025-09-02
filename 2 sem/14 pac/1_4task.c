#include <stdio.h>
#include <stdlib.h>
#define MAX_N 2000        
static int dp[MAX_N+1][MAX_N+1];

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long long m;
    int zaprosi;
    scanf("%lld %d", &m, &zaprosi);
    dp[0][0] = 1 % m;

for (int n = 1; n <= MAX_N; n++) 
{
    dp[n][0] = 1;        
    dp[n][n] = 1;        

    for (int k = 1; k < n; k++) 
    {
        long long sum = (long long)dp[n-1][k-1] + dp[n-1][k];
        sum %= m;
        dp[n][k] = (int)sum;
    }
}

    while (zaprosi--) 
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);

        if (k < 0 || k > n) 
        {
            printf("0\n");
            continue;
        }
        int answer = dp[(int)n][(int)k];
        printf("%d\n", answer);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
