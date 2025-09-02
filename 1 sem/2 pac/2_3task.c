#include<stdio.h>
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i, N, k;
    int a=0,b=0,c=0;
    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &k);
        if (k==0) 
        {
            b++;
        }

        if (k>0) 
        {
            c++;
        }

        if (k<0) 
        {
            a++;
        }
    }
    double A=a/(double)N;
    double B=b/(double)N;
    double C=c/(double)N;
    printf("%0.15lf %0.15lf %0.15lf",A,B,C);
    //fclose(stdin);
    //fclose(stdout); 
    return 0;
}