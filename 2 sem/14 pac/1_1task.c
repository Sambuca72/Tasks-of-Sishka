#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error() 
{
    fprintf(stderr, "No parameters specified.\n");
    exit(13);
}
int main(int argc, char *argv[]) 
{
    int modyl = 0;
    int num1, num2, res;
    int index = 1;
    if (argc >= 4 && strcmp(argv[1], "-m") == 0) 
    {
        modyl = atoi(argv[2]);
        index = 3; 
    } 
    else if (argc >= 4 && strcmp(argv[argc - 2], "-m") == 0) 
    {
        modyl = atoi(argv[argc - 1]);
        argc -= 2;
    }
    
    if (argc - index < 3) 
    {
        error();
    }
    
    char *oper = argv[index];
    num1 = atoi(argv[index + 1]);
    num2 = atoi(argv[index + 2]);
    
    if (strcmp(oper, "add") == 0) 
    {
        res = num1 + num2;
    } else if (strcmp(oper, "sub") == 0) 
    {
        res = num1 - num2;
    } else if (strcmp(oper, "mul") == 0) 
    {
        res = num1 * num2;
    } else {
        error();
    }
    
    if (modyl > 1) 
    {
        res = (res % modyl + modyl) % modyl;
    }
    printf("%d\n", res);
    return 0;
}
