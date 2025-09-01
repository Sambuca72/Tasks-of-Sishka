#include<stdio.h>
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a1, a2, b1, b2, c1, c2 = 0;
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
    if ((b1 + c1 <= a1 && b2 <= a2 && c2 <= a2) || (b1 + c1 <= a2 && b2 <= a1 && c2 <= a1) || (b2 + c2 <= a2 && b1 <= a1 && c1 <= a1) || (b2 + c2 <= a1 && b1 <= a2 && c1 <= a2) ||  (b2 + c1 <= a1 && b1 <= a2 && c2 <= a2) || (b2 + c1 <= a2 && b1 <= a1 && c2 <= a1) || (b1 + c2 <= a1 && b2 <= a2 && c1 <= a2) || (b1 + c2 <= a2 && b2 <= a1 && c1 <= a1) || (b2 + c2 <= a1 && b1 <= a2 && c1 <= a2) || (b2 + c2 <= a2 && b1 <= a1 && c1 <= a1))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;   
}
