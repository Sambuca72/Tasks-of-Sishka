#include <stdio.h>
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testi, A, B;
    scanf("%d", &testi);
    
    for (int i = 0; i < testi; i++) 
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
