#include "primes.h" 
#define MAX_N 10000020 

static char is_prime[MAX_N + 1];
static int prime_s[MAX_N + 1];
static void sieve()
{
    for (int i = 0; i <= MAX_N; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= MAX_N; i++) 
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_N; j += i) 
            {
                is_prime[j] = 0;
            }
        }
    }
    prime_s[0] = 0;
    for (int i = 1; i <= MAX_N; i++) 
    {
        prime_s[i] = prime_s[i - 1] + is_prime[i];
    }
}
int prime(int x) 
{
    if (x > MAX_N) return 0;
    return is_prime[x];
}
int nextprime(int x)
{
    if (x > MAX_N) return -1;

    while (x <= MAX_N && !is_prime[x]) 
    {
        x++;
    }
    return x;
}
int primescount(int l, int r) 
{
    return prime_s[r - 1] - (l > 0 ? prime_s[l - 1] : 0);
}
__attribute__((constructor)) void init() 
{
    sieve();
}
