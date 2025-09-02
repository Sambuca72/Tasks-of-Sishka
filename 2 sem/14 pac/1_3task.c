#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
void line(const char *input) 
{
    int vnutri = 0; 
    const char *start = NULL; 
    
    for (const char *ptr = input; ; ptr++) 
    {
        if (*ptr == '"') 
        {
            vnutri = !vnutri;
            if (vnutri) 
            {
                start = ptr + 1;
            } else 
            {
                printf("[%.*s]\n", (int)(ptr - start), start);
                start = NULL;
            }
        }
        else if ((*ptr == ' ' || *ptr == '\0') && !vnutri) 
        {
            if (start) 
            {
                printf("[%.*s]\n", (int)(ptr - start), start);
                start = NULL;
            }
        }
        else if (!start) 
        {
            start = ptr;
        }
        if (*ptr == '\0') break;
    }
}

int main() 
{
    char input[MAX];
    FILE *file = fopen("input.txt", "r");
    fgets(input, MAX, file);
    fclose(file);
    
    char *start = input;
    while (*start == ' ') start++;
    char *end = start + strlen(start) - 1;
    while (end > start && *end == ' ') *end-- = '\0';
    
    line(start);
    return 0;
}
