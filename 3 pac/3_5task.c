#include <stdio.h>
int main(void) 
{
    int numArgs, numPairs, arg, val;
    int hasDuplicateArgs = 0, hasDuplicateVals = 0;
    int isInjective = 1; //флаг для проверки инъективности

    scanf("%d %d", &numArgs, &numPairs);
    int pairs[numPairs][2];  //объявляем двумерный массив для хранения пар
    //вводим пары аргумент-значение
    for (int i = 0; i < numPairs; i++) 
    {
        scanf("%d", &pairs[i][0]);  //вводим аргумент
        scanf("%d", &pairs[i][1]);  //вводим значение для этого аргумента
    }
    //проверка на дублирующиеся аргументы с разными значениями
    for (int i = 0; i < numPairs - 1; i++) 
    {
        for (int j = i + 1; j < numPairs; j++) 
        {
            //если аргументы одинаковые, но значения разные, то это не функция
            if (pairs[i][0] == pairs[j][0]) 
            {  
                if (pairs[i][1] != pairs[j][1]) 
                {  
                    hasDuplicateArgs = 1;   
                }
            }
        }
    }
    //если есть дубликаты с разными значениями, выводим 0 и завершаем программу
    if (hasDuplicateArgs)
    {
        printf("0\n");
        return 0;
    }
    //если нет дубликатов с разными значениями, это корректная функция
    printf("1 ");  // Выводим 1, если функция корректна
    // Проверка, совпадает ли количество аргументов с количеством пар(функция сюръективна)
    if (numArgs == numPairs) 
    {
        printf("2 ");  // Если да, выводим 2
    }
    // Проверка на инъективность (функция инъективна, если одно и то же значение не присваивается разным аргументам)
    for (int i = 0; i < numPairs - 1; i++) 
    {
        for (int j = i + 1; j < numPairs; j++) 
        {
            // Если значения одинаковые для разных аргументов, то функция не инъективна
            if (pairs[i][1] == pairs[j][1]) 
            {  
                isInjective = 0;  
            }
        }
    }
    // Если функция инъективна, выводим 3
    if (isInjective) 
    {
        printf("3");
    }
    // Доп проверка: если количество аргументов совпадает с количеством пар и функция инъективна
    if (numArgs == numPairs && isInjective) 
    {
        printf("4"); 
    }
    // Еще одна проверка на инъективность и количество аргументов
    if (isInjective && numArgs == numPairs) 
    {
        printf("5");  
    }
    return 0;
}
