#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 10000
#define MAX_STRING_LEN 8
//структура для хранения одной записи
typedef struct 
{
    int key; //целочисленный ключ
    char value[MAX_STRING_LEN]; //значение (строка)
    int index; //индекс для сохранения исходного порядка при равных ключах
} Record;
//функция сравнения для qsort
int compareRecords(const void *a, const void *b) 
{
    Record *recordA = (Record *)a;
    Record *recordB = (Record *)b;
    //сравниваем записи по ключу
    if (recordA->key != recordB->key) 
    {
        return recordA->key - recordB->key; //сравнение по ключу: по возрастанию
    } else {
        //если ключи равны, сравниваем по исходному порядку т.е индексу
        return recordA->index - recordB->index;
    }
}
int main() 
{
    int quanityZapisi;
    scanf("%d", &quanityZapisi);
    Record records[MAX_RECORDS]; //массив для хранения записей
    //считываем записи
    for (int i = 0; i < quanityZapisi; i++) 
    {
        scanf("%d %s", &records[i].key, records[i].value); //считываем ключ и значение
        records[i].index = i; //сохраняем исходный порядок записи
    }
    //сортируем записи по ключу, с сохранением исходного порядка при равных ключах
    qsort(records, quanityZapisi, sizeof(Record), compareRecords);
    //выводим отсортированные записи
    for (int i = 0; i < quanityZapisi; i++) 
    {
        printf("%d %s\n", records[i].key, records[i].value);
    }
    return 0;
}
