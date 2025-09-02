#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat(char *pref, char *suff) 
{
    //ищем конец первой строки (pref)
    char *end = pref + strlen(pref);
    //копируем вторую строку в конец первой
    strcpy(end, suff);
    //возвращаем указатель на конец строки т.е нулевой символ
    return end + strlen(suff);
}
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    //массив для строки с результатом
    //делаем предположение, что длина всех строк <= 100, и их кол-во <= 10000
    char *result = (char *)malloc(N * 100 + 1); //место под все строки и нулевой символ
    result[0] = '\0';  //запускаем результат как пустую строку
    //буфер для чтения строк
    char buffer[101];  //максимальная длина строки 100 символов + 1 для нуля
    for (int i = 0; i < N; i++) 
    {
        scanf("%s", buffer);
        //конкатенируем строку с результатом
        concat(result, buffer);
    }
    printf("%s\n", result);
    free(result);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
