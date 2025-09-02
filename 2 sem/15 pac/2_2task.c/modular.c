#include "modular.h"
#include <stdlib.h>
#include <assert.h>
int MOD; 
int pnorm(int a) 
{
    a %= MOD;
    if (a < 0) a += MOD;
    return a;
}

int padd(int a, int b) 
{
    return pnorm(a + b);
}

int psub(int a, int b) 
{
    return pnorm(a - b);
}

int pmul(int a, int b) 
{
    return pnorm((long long)a * b % MOD);
}

int power(int base, int exp) 
{
    int result = 1;
    while (exp) 
    {
        if (exp % 2)
            result = pmul(result, base);
        base = pmul(base, base);
        exp /= 2;
    }
    return result;
}

int pdiv(int a, int b) 
{
    assert(b != 0);
    return pmul(a, power(b, MOD - 2));
}
