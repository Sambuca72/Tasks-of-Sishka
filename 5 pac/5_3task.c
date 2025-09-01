#include <stdio.h>
#include <string.h>
typedef struct Label_s 
{
    char name[16]; // имя автора (заканчивается нулём)
    int age;       // возраст автора (целое число)
} Label;
typedef struct NameStats_s 
{
    int cntTotal; // общее количество подписей
    int cntLong;  // количество подписей с именами длиннее 10 символов
} NameStats;
typedef struct AgeStats_s 
{
    int cntTotal;  // сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids;   //сколько подписей детей (меньше 14 лет)
} AgeStats;
//функция calcStats вычисляет статистику по именам и возрастам
/* Параметры: 
    arr - массив подписей (Label)
    cnt - количество подписей в массиве
    oNames - структура для записи статистики по именам
    oAges - структура для записи статистики по возрастам*/
void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) 
{
    //задаем значения статистики, которые будут по умолчанию
    oNames->cntTotal = cnt;
    oNames->cntLong = 0;
    oAges->cntTotal = cnt;
    oAges->cntAdults = 0;
    oAges->cntKids = 0;
    //проход по каждому элементу массива подписей
    for (int i = 0; i < cnt; i++) 
    {
        //если длина имени больше 10 символов, увеличиваем счётчик длинных имён
        if (strlen(arr[i].name) > 10) 
        {
            oNames->cntLong++;
        }
        //если возраст автора больше или равен 18, это взрослый
        if (arr[i].age >= 18) 
        {
            oAges->cntAdults++;
        }
        //если возраст меньше 14, это ребёнок
        else if (arr[i].age < 14) 
        {
            oAges->cntKids++;
        }
    }
}
int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int podpisi;
    scanf("%d", &podpisi); 
    //объявляем массив структур Label для хранения подписей
    Label arr[podpisi];
    //читаем все подписи: имя и возраст
    for (int i = 0; i < podpisi; i++) 
    {
        //читаем имя и возраст, в формате "[имя] [возраст] let"
        scanf("%s %d let", arr[i].name, &arr[i].age);
    }
    //объявляем переменные для хранения статистики по именам и возрастам
    NameStats nameStats;
    AgeStats ageStats;
    //вызываем функцию для вычисления статистики имён и возраста
    calcStats(arr, podpisi, &nameStats, &ageStats);
    printf("names: total = %d\n", nameStats.cntTotal); //общее количество имён
    printf("names: long = %d\n", nameStats.cntLong);   //количество длинных имён (более 10 символов)
    // Выводим статистику по возрастам
    printf("ages: total = %d\n", ageStats.cntTotal);   //общее количество возрастов
    printf("ages: adult = %d\n", ageStats.cntAdults);  //количество взрослых (>=18 лет)
    printf("ages: kid = %d\n", ageStats.cntKids);      //количество детей (<14 лет)
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
