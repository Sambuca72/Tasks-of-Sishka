#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Данная функция подсчитывает количество заглавных (oUpperCnt) и строчных (oLowerCnt) букв в переданной строке iStr.
void calcLetters(const char *iStr, int *oLowerCnt, int *oUpperCnt) 
{
    // Проход по каждому символу строки
    for (int i = 0; i < strlen(iStr); i++) 
    {
        //если символ заглавный - увеличиваем счетчик заглавных букв
        if (isupper(iStr[i])) (*oUpperCnt)++;
        //если символ строчный - увеличиваем счетчик строчных букв
        else if (islower(iStr[i])) (*oLowerCnt)++;
    }
}
int main(void) 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int lowerCount = 0, upperCount = 0; 
    char buffer[10000]; //буфер для хранения считанных строк
    int len = 0; //отслеживание текущей длины строки
    char c; //хранения для текущего считанного символа

    //основной цикл для обработки символов входного файла
    while (1) 
    {
        //если считывание символа не удалось, проверяем буфер и завершаем цикл
        if (scanf("%c", &c) != 1) 
        {
            if (len > 0) 
            {
                //добавляем символ конца строки, чтобы завершить текущую строку в буфере
                buffer[len] = '\0';
                //подсчитываем количество строчных и заглавных букв в буфере
                calcLetters(buffer, &lowerCount, &upperCount);
                printf("%d/%d %s\n", upperCount, lowerCount + upperCount, buffer);
            }
            break;
        }
        //проверяем, является ли символ буквой
        if (isalpha(c)) 
        {
            //если да, добавляем его в буфер и увеличиваем длину строки
            buffer[len++] = c;
            buffer[len] = '\0'; //завершаем строку нулевым символом
        } 
        //если встречается неалфавитный символ и буфер содержит буквы
        else if (len > 0) 
        {
            buffer[len] = '\0'; //завершаем строку нулевым символом
            //вызываем функцию для подсчета заглавных и строчных букв
            calcLetters(buffer, &lowerCount, &upperCount);
            //выводим количество заглавных/общих букв и строку из буфера
            printf("%d/%d %s\n", upperCount, lowerCount + upperCount, buffer);
            //обнуляем длину строки и счетчики для следующей строки
            len = 0;
            lowerCount = upperCount = 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
