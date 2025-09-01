#include <stdio.h>
#include <string.h> 
//функция для подсчета времени
int readtime(char *inputStr, int *hourPtr, int *minutePtr, int *secondPtr) 
{
    int hours = -1;
    int minutes = -1;
    int seconds = -1;
    int parsedValues = 0;
   parsedValues  = sscanf(inputStr, "%d:%d:%d", &hours, &minutes, &seconds);

    if (parsedValues < 2) {
        return 0; //в случае некорректного ввода
    }

    if (parsedValues == 2) {
        seconds = 0; //если секунды не указаны, то считаем их нулевыми
    }
    //проверка на соблюдение норм времени
    if ((hours < 0 || hours > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59)) 
    {
        return 0; //время некорректно
    }
    //заполнение выходных переменных
    if (hourPtr != NULL) *hourPtr = hours;
    if (minutePtr != NULL) *minutePtr = minutes;
    if (secondPtr != NULL) *secondPtr = seconds;
    return 1; //если успешный разбор строки
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char input[50];
    int hours = -1;
    int minutes = -1;
    int seconds = -1;
    scanf("%s", input);
    // Первый вызов функции
    printf("%d ", readtime(input, &hours, &minutes, &seconds));
    printf("%d %d %d\n", hours, minutes, seconds);
    // Второй вызов функции, где мы игнорируем секунды
    seconds = 0; //обнуляем значение
    printf("%d ", readtime(input, &hours, &minutes, NULL));
    printf("%d %d\n", hours, minutes);
    //третий вызов функции, игнорируем минуты и секунды
    minutes = 0; //обнуляем значение
    printf("%d ", readtime(input, &hours, NULL, NULL));
    printf("%d\n", hours);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
