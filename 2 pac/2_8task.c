#include <stdio.h>
int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int  days_m, number_m, year, quantity_d;
    scanf("%d %d %d %d", &days_m, &number_m, &year, &quantity_d);
    int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (quantity_d > 0) 
    {
        // Проверка на високосный год
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) 
        {
            days_in_month[2] = 29; 
        } else 
        {
            days_in_month[2] = 28;
        }
        //добавляем дни пока не выходим за кол-во дней в месяце
        if (days_m + quantity_d <= days_in_month[number_m]) 
        {
            days_m += quantity_d;
            quantity_d = 0;
        } else {
            //или же переходим в следующий месяц
            quantity_d -= (days_in_month[number_m] - days_m + 1); //
            days_m = 1;
            number_m++;
            // Переход на следующий год, если текущий месяц больше 12
            if (number_m > 12) 
            {
                number_m = 1;
                year++;
            }
        }
    }
    printf("%d %d %d", days_m, number_m, year);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
