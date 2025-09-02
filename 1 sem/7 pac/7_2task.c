#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef uint64_t bitword; //используем 64-битное слово для хранения битов
#define BITS_PER_WORD 64  //количество битов в одном слове
//функция для установки массива битов, устанавливая все биты в 0
void bitsetZero(bitword *arr, int num) //к ЧАРУ
{
    int words = (num + BITS_PER_WORD - 1) / BITS_PER_WORD; //количество слов в массиве
    for (int i = 0; i < words; i++) 
    {
        arr[i] = 0; //устанавливаем все слова в 0
    }
}
//функция для получения значения бита с индексом 0 или 1
int bitsetGet(const bitword *arr, int idx) 
{
    int wordIndex = idx / BITS_PER_WORD; //индекс слова
    int bitIndex = idx % BITS_PER_WORD; //индекс бита в слове
    return (arr[wordIndex] >> bitIndex) & 1; //возвращаем значение бита
}
//функция для установки значения бита с индексом 0 или 1
void bitsetSet(bitword *arr, int idx, int newval) 
{
    int wordIndex = idx / BITS_PER_WORD; //индекс слова
    int bitIndex = idx % BITS_PER_WORD; //индекс бита в слове
    if (newval) {
        arr[wordIndex] |= ((bitword)1 << bitIndex); //устанавливаем бит в 1
    } else {
        arr[wordIndex] &= ~((bitword)1 << bitIndex); //устанавливаем бит в 0
    }
}
//функция для проверки наличия хотя бы одного единичного бита на отрезке [left, right)
int bitsetAny(const bitword *arr, int left, int right) 
{
    int leftWord = left / BITS_PER_WORD; //слово, в котором начинается отрезок
    int rightWord = (right - 1) / BITS_PER_WORD; //слово, в котором заканчивается отрезок
    int leftBit = left % BITS_PER_WORD; //начальная позиция в слове
    int rightBit = (right - 1) % BITS_PER_WORD; //конечная позиция в слове

    if (leftWord == rightWord) //если отрезок лежит в пределах одного слова
    {  
        bitword mask = ((bitword)1 << (rightBit - leftBit + 1)) - 1; //создаем маску
        mask <<= leftBit;
        return (arr[leftWord] & mask) != 0; //возвращаем 1, если есть единичный бит
    }
    //проверяем начальное слово от левого бита до конца слова
    bitword startMask = ~((bitword)0) << leftBit;
    if (arr[leftWord] & startMask) 
    {
        return 1;
    }
    //проверяем полностью заполненные слова между leftWord и rightWord
    for (int i = leftWord + 1; i < rightWord; i++) 
    {
        if (arr[i] != 0) 
        {
            return 1;
        }
    }
    //проверяем конечное слово от начала до правого бита
    bitword endMask = ((bitword)1 << (rightBit + 1)) - 1;
    if (arr[rightWord] & endMask) 
    {
        return 1;
    }
    return 0; //возвращаем 0, если нет единичных битов на отрезке
}
int main() 
{
    int q_operation;
    scanf("%d", &q_operation);
    bitword *arr = NULL; //указатель на массив битов
    int num = 0; //текущее количество битов

    for (int i = 0; i < q_operation; i++) 
    {
        int t;
        scanf("%d", &t); //тип операции

        if (t == 0) //операция bitsetZero
        {  
            scanf("%d", &num); //считываем размер массива
            int words = (num + BITS_PER_WORD - 1) / BITS_PER_WORD; //количество слов
            arr = (bitword *)realloc(arr, words * sizeof(bitword)); //выделяем память
            bitsetZero(arr, num); //инициализируем массив нулями

        } else if (t == 1) //операция bitsetGet 
        { 
            int index;
            scanf("%d", &index);
            printf("%d\n", bitsetGet(arr, index));

        } else if (t == 2) //операция bitsetSet
        {  
            int index, newval;
            scanf("%d %d", &index, &newval); //считываем индекс и новое значение
            bitsetSet(arr, index, newval); //устанавливаем бит в значение newval

        } else if (t == 3) //операция bitsetAny
        {  
            int left, right;
            scanf("%d %d", &left, &right); //считываем границы отрезка
            printf("%s\n", bitsetAny(arr, left, right) ? "some" : "none");
        }
    }
    free(arr);
    return 0;
}
