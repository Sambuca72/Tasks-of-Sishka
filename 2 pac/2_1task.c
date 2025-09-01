#include<stdio.h>
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, d;
    scanf("%d",&b);
    for(d=2;d<=b;d++)
    {
        a=2;
        c=0;
        while(a<d)
        {
            if(d%a==0)
            {
                c++;
            }
            a++;
        }
        if(c==0)
        {
            printf("%d\n",d);
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}