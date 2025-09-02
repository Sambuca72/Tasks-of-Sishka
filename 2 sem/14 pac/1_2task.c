#include <stdio.h>
long long modExp(long long base, long long exp, long long mod) 
{
    long long res = 1;
    base %= mod;
    while (exp > 0) 
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    long long modyl;
    scanf("%d %lld", &test, &modyl);
    
    for (int i = 0; i < test; i++) 
    {
        long long A;
        scanf("%lld", &A);
        
        if (A == 0) 
        {
            printf("-1\n");
        } else 
        {
            long long inv = modExp(A, modyl - 2, modyl);
            printf("%lld\n", inv);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
