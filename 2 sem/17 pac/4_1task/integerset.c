#include "integerset.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned long long hashtype; // тип для хэшей это будет 64-битное число

struct IntegerSet {
    int length; // количество элементов в множестве
    int* intMas; // указатель на массив уникальных отсортированных чисел
};

static IntegerSet* HashTable[hashTableSize];

// Простейшая хэш-функция на основе полинома
static hashtype getHash(int* intSet, int len)
{
    hashtype hash = 0;
    for(int i = 0; i < len; i++){
        hash = hash * P + intSet[i]; // P — заранее заданное простое число
    }
    return hash;
}

// Компаратор для сортировки и бинарного поиска
int compare(const void* a, const void* b) 
{
    int iA = *(const int*)a;
    int iB = *(const int*)b;

    return (iA > iB) - (iA < iB); // эквивалентно return iA - iB, но безопаснее
}

// Создание множества, который возвращет указатель на IntegerSet
IntegerSet* CreateSet(int* intSet, int len)
{
    int flag = 0;

    // Обработка пустого множества
    if(len == 0)
    {
        IntegerSet *empty = (IntegerSet*)malloc(sizeof(IntegerSet));
        empty->length = 0;
        empty->intMas = NULL;
        return empty;
    }

    // Копируем входной массив во временный
    int* temp = (int*)malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++)
    {
        temp[i] = intSet[i];
    }

    // Сортируем, чтобы обнаружить дубликаты и убрать их
    qsort(temp, len, sizeof(int), compare);

    // Проверяем на дубликаты
    for(int i = 1; i < len; i++)
    {
        if(temp[i] == temp[i-1])
        {
            free(temp);
            return 0; 
        }
    }

    // Вычисляем хэш и ищем в хэш-таблице есть ли такое множество
    hashtype curr_hash = getHash(temp, len);
    int idx = curr_hash % hashTableSize;

    while (HashTable[idx] != NULL) 
    {
        if (HashTable[idx]->length == len) 
        {
            // Сравниваем содержимое массивов
            int same = 1;
            for(int i = 0; i < len; i++)
            {
                if(temp[i] != HashTable[idx]->intMas[i])
                {
                    same = 0;
                    break;
                }
            }
            if(same){
                free(temp);
                return HashTable[idx]; // возвращаем уже созданное множество
            }
        }
        idx = (idx + 1) % hashTableSize; // открытая адресация
    }

    //Такого множества ещё не было — создаём новое
    IntegerSet* IntNumSet = (IntegerSet*)malloc(sizeof(IntegerSet));
    IntNumSet->length = len;
    IntNumSet->intMas = temp; // сохраняем отсортированный массив

    // Записываем его в хэш-таблицу
    HashTable[idx] = IntNumSet;

    return IntNumSet;
}

// Проверяет, входит ли число num в множество
int IsInSet(IntegerSet* intSet, int num)
{
    if(intSet == NULL)
    {
        return 0;
    }

    // Используем бинарный поиск, т.к. массив отсортирован
    return bsearch(&num, intSet->intMas, intSet->length, sizeof(int), compare) != NULL;
}
