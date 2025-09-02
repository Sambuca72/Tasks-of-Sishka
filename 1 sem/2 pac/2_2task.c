#include<stdio.h>
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char day[7];
    scanf("%3s",day);
    if (day[0] =='M' && day[1] == 'o' && day[2]=='n')
    {
        printf("1");
    }
    else if (day[0] =='T' && day[1] == 'u' && day[2]=='e')
    {
        printf("2");
    }
    else if (day[0] =='W' && day[1] =='e' && day[2] =='d')
    {
        printf("3");
    }
    else if (day[0] =='T' && day[1] == 'h' && day[2]=='u')
    {
        printf("4");
    }
    else if (day[0] =='F' && day[1] == 'r' && day[2]=='i')
    {
        printf("5");
    }
    else if (day[0] =='S' && day[1] == 'a' && day[2]=='t')
    {
        printf("6");
    }
    else if (day[0] =='S' && day[1] == 'u' && day[2]=='n')
    {
        printf("7");
    }
    //fclose(stdin);
    //fclose(stdout); 
    return 0;
}