#include <stdio.h>
//структура для связаного списка
struct Node 
{
    double value; //вещ число
    int next; //индекс следующего узла в массиве
};
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, F;
    scanf("%d %d", &N, &F);
    //массив в виде связанного списка
    struct Node list[N];
    //чтение данных для каждого узла
    //считываем значение и индекс следующего элемента
    for (int i = 0; i < N; i++) 
    {
        scanf("%lf %d", &list[i].value, &list[i].next);
    }
    //вывод значений узлов в порядке следования в связном списке
    int currentIndex = F; //начинаем с узла, индекс которого равен F
    while (currentIndex != -1) //пока не дойдём до конца списка т.е где индекс -1 
    {  
        printf("%.3lf\n", list[currentIndex].value);
        currentIndex = list[currentIndex].next; //переходим к следующему узлу
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

