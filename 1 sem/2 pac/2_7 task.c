#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int L, R, K, i, d, j, k, a1, a2;
    scanf ("%d %d %d", &L, &R, &K);
    a1=a2=d=k=0;
    d=R-L;
    for (j=1; j<=d; j++)
    {
        for (i=L; i<R; i++)
    {
     a1 = i+j*(K-1);
     a2 = i+j*K;
     if ((a1<=R) && (a2>R) )
     k=k+1;
    }
}
    printf ("%d", k);
    fclose(stdin);
    fclose(stdout);   
    return 0;   
}