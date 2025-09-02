#include "modular.h"
#include <stdio.h>
#include <assert.h>

int main() 
{
    MOD = 13; 
    int a = 45;
    a = pnorm(a);
    assert(a == 6);

    int x = pmul(padd(7, psub(2, 3)), 5);
    assert(x == 4); 

    int y = pdiv(7, x);
    assert(pmul(x, y) == 7);

    MOD = 2; 
    assert(pnorm(5) == 1);

    printf("Pobeda!\n");
    return 0;
}
