#include <stdio.h>
//определяем DateTime для хранения даты и времени
typedef struct DateTime_s 
{
    int year, month, day;      
    int hours, minutes, seconds;
} DateTime;
//функция для сравнения двух дат
//возвращает отрицательное значение, если d1 появляется раньше d2
//возвращает 0, если даты равны
//возвращает положительное значение, если d1 появляется позже d2
int compareDates(const DateTime *d1, const DateTime *d2) 
{
    //сравнение по году
    if (d1->year != d2->year)
        return d1->year - d2->year; //если год отличается, то разница в годах определяет результат 
    //сравнение по месяцу
    if (d1->month != d2->month)
        return d1->month - d2->month; //если год одинаковый, сравниваем месяц
    //сравнение по дню
    if (d1->day != d2->day)
        return d1->day - d2->day; //если месяц одинаковый, сравниваем день
    //сравнение по часам
    if (d1->hours != d2->hours)
        return d1->hours - d2->hours; //если день одинаковый, сравниваем часы
    //сравнение по минутам
    if (d1->minutes != d2->minutes)
        return d1->minutes - d2->minutes; //если часы одинаковые, сравниваем минуты
    //сравнение по секундам
    return d1->seconds - d2->seconds; //если минуты одинаковые, сравниваем секунды
}
//функция для поиска самой ранней даты в массиве
//принимает указатель на массив дат и количество элементов в массиве
DateTime min(const DateTime *arr, int cnt) 
{
    //задаем минимальную дату первым элементом массива
    DateTime minDate = arr[0];
    //перебираем все даты начиная со второй (i = 1)
    for (int i = 1; i < cnt; i++) {
        //если текущая дата меньше минимальной, обновляем минимальную дату
        if (compareDates(&arr[i], &minDate) < 0) 
        {
            minDate = arr[i];
        }
    }
    //возвращаем самую раннюю найденную дату
    return minDate;
}
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int quantity_d; //даты
    scanf("%d", &quantity_d);
    //делаем массив для хранения наших дат
    DateTime dates[quantity_d];
    //ввод данных для каждой даты
    for (int i = 0; i < quantity_d; i++) 
    {
        scanf("%d %d %d %d %d %d", 
              &dates[i].year, &dates[i].month, &dates[i].day, 
              &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
    }
    //вызов функции для поиска самой ранней даты
    DateTime earliestDate = min(dates, quantity_d);
    //вывод : "год месяц день часы минуты секунды"
    printf("%d %d %d %d %d %d\n", 
           earliestDate.year, earliestDate.month, earliestDate.day, 
           earliestDate.hours, earliestDate.minutes, earliestDate.seconds);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
