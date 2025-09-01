#include <stdio.h>
#include <string.h>
void reverse(char *start, int len) 
{
    int left = 0;
    int right = len - 1;   
    //поменяем местами символы с начала и конца строки
    while (left < right) 
    {
        char temp = start[left];
        start[left] = start[right];
        start[right] = temp;
        left++;
        right--;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    //считаем количество строк
    scanf("%d", &N);
    //создаем массив строк, где каждая строка будет длиной до 101 символа (даже 0)
    char strings[N][101];
    //считаем каждую строку
    for (int i = 0; i < N; i++) 
    {
        scanf("%s", strings[i]);
    }
    for (int i = 0; i < N; i++) 
    {
        int len = strlen(strings[i]); //находим длину строки
        reverse(strings[i], len);     //разворачиваем строку
        printf("%s\n", strings[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
