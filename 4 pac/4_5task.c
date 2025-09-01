#include <stdio.h>
#include <string.h>
#include <ctype.h>
//данная функция считает заглавных (oUpperCnt) и строчных (oLowerCnt) букв в переданной строке iStr.
void calcLetters(const char *iStr, int *oLowerCnt, int *oUpperCnt) 
{
    //проход по строке
    for (int i = 0; i < strlen(iStr); i++) 
    {
        if (isupper(iStr[i])) (*oUpperCnt)++;
        else if (islower(iStr[i])) (*oLowerCnt)++;
    }
}
int main(void) 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int lowerCount = 0, upperCount = 0;
    char buffer[10000];
    int len = 0; //отслеживание длины строки
    char c; //хранение текущего считанного символач

    while (1)/* идет счет символов, самое интересное, что если считывание строки не удается значит входные данные законч => 
    вывод результата для последней строки(если имеется) и завершает выполнение*/ 
    {
        if (scanf("%c", &c) != 1) 
        {
            if (len > 0) 
            {
                buffer[len] = '\0';
                calcLetters(buffer, &lowerCount, &upperCount);
                printf("%d/%d %s\n", upperCount, lowerCount + upperCount, buffer);
            }
            break;
        }
        //проверка буквы на символ функцией isalpha, добавляя его в  buffer, увеличавая на длину на len
        if (isalpha(c)) 
        {
            buffer[len++] = c;
            buffer[len] = '\0'; // Обновляем строку с нулевым символом
        } 
        //если встречается неалфавитный символ и в буфере уже есть буквы
        else if (len > 0) 
        {
            buffer[len] = '\0'; //обновление конца строки
            calcLetters(buffer, &lowerCount, &upperCount); //подсчет заглавных и строчных букв
            printf("%d/%d %s\n", upperCount, lowerCount + upperCount, buffer);
            len = 0;
            lowerCount = upperCount = 0; // Обнуляем счетчики для новой строки
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
