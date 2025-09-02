#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int64_t rashir_gcd(int64_t a, int64_t b, int64_t *x, int64_t *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t gcd = rashir_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int64_t theor(int k, int64_t M[], int64_t A[])
 {
    int64_t M_prod = 1;
    for (int i = 0; i < k; i++) 
    {
        M_prod *= M[i];
    }
    
    int64_t result = 0;
    for (int i = 0; i < k; i++) 
    {
        int64_t Mi = M_prod / M[i];
        int64_t inv, y;
        rashir_gcd(Mi, M[i], &inv, &y);
        if (inv < 0) {
            inv += M[i]; 
        }
        result += A[i] * Mi * inv;
    }
    
    return (result % M_prod + M_prod) % M_prod;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int modyli;
    scanf("%d", &modyli); 
    
    int64_t *M = (int64_t*)malloc(modyli * sizeof(int64_t)); 
    int64_t *A = (int64_t*)malloc(modyli * sizeof(int64_t)); 
    
    for (int i = 0; i < modyli; i++) 
    {
        scanf("%lld", &M[i]); 
    }
    
    for (int i = 0; i < modyli; i++) 
    {
        scanf("%lld", &A[i]); 
    }
    
    int64_t X = theor(modyli, M, A);
    printf("%lld\n", X); 
    free(M); 
    free(A);
    fclose(stdin);
    fclose(stdout); 
    return 0;
}
