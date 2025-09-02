#include <stdio.h>
#include <assert.h>
#include "primes.h"
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    assert(prime(2) == 1);
    assert(prime(3) == 1);
    assert(prime(4) == 0);
    assert(prime(97) == 1);
    assert(prime(100) == 0);

    assert(nextprime(2) == 2);
    assert(nextprime(4) == 5);
    assert(nextprime(98) == 101);
    assert(nextprime(10000000) == 10000019);

    assert(primescount(1, 10) == 4);
    assert(primescount(10, 20) == 4);
    assert(primescount(1, 100) == 25);
    printf("Pobeda!\n");
     
    fclose(stdin);
    fclose(stdout);
    return 0;
}
