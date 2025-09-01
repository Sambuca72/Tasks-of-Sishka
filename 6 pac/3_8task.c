#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Функция для преобразования строки из p-ичной системы в десятичное число
long long convertToDecimal(const char *numStr, int base) 
{
    long long decimal = 0;  //хранение десятичного значения
    int length = strlen(numStr);  //длина строки числа
    //проходим по каждой цифре, начиная с первой
    for (int i = 0; i < length; i++) 
    {
        char digit = numStr[i]; //текущая цифра в строке
        int value;
        /*определяем значение цифры: 
        если цифра от 0 до 9, вычитаем 0 для получения числового значения*/
        if (isdigit(digit)) 
        {
            value = digit - '0';
        } else 
        {
            //если буква от a до z, вычитаем a и прибавляем 10 для получения значения
            value = digit - 'a' + 10;
        }

        //переводим из p-ичной системы в десятичную
        decimal = decimal * base + value;
    }
    return decimal; //возвращаем полученное десятичное значение
}
//функция для преобразования десятичного числа в q-ичную систему
void convertFromDecimal(long long decimal, int base, char *result) 
{
    char temp[40]; //временный массив для хранения результата в обратном порядке
    int index = 0; //индекс для заполнения временного массива

    //специальный случай для нуля
    if (decimal == 0) 
    {
        result[0] = '0'; //если число 0, записываем 0
        result[1] = '\0'; //завершаем строку
        return;
    }
    //преобразование десятичного числа в q-ичную систему
    while (decimal > 0) 
    {
        int remainder = decimal % base; //остаток от деления
        if (remainder < 10) 
        {
            temp[index++] = '0' + remainder; //преобразуем в символ от 0 до 9
        } else 
        {
            temp[index++] = 'a' + (remainder - 10); //преобразуем в символ от a до z
        }
        decimal /= base; //переходим к следующей цифре
    }
    //переворачиваем результат, чтобы получить правильный порядок цифр
    for (int i = 0; i < index; i++) 
    {
        result[i] = temp[index - i - 1]; //копируем цифры из temp в result в обратном порядке
    }
    result[index] = '\0'; //завершаем строку
}
int main() 
{
    int p, q;  //основания p и q систем счисления
    char N[40]; //строка для хранения входного числа N в системе счисления p
    scanf("%d %d %s", &p, &q, N);
    //переводим число N из p-ичной системы в десятичную
    long long decimalValue = convertToDecimal(N, p);
    //переводим десятичное число в q-ичную систему
    char result[40];
    convertFromDecimal(decimalValue, q, result);
    printf("%s\n", result);
    return 0;
}
