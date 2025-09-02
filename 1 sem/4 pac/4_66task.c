#include <stdio.h>
#include <string.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds) {
    char *token;
    int hours = -1, minutes = -1, seconds = -1;

    // Первый токен (часы)
    token = strtok(iStr, "|:");
    if (token != NULL) {
        sscanf(token, "%d", &hours);
        if (hours < 0 || hours > 23) {
            hours = -1;
        }
    }

    // Второй токен (минуты)
    token = strtok(NULL, "|:");
    if (oMinutes != NULL && token != NULL) {
        sscanf(token, "%d", &minutes);
        if (minutes < 0 || minutes > 59) {
            minutes = -1;
        }
    }

    // Третий токен (секунды)
    token = strtok(NULL, "|:");
    if (oSeconds != NULL && token != NULL) {
        sscanf(token, "%d", &seconds);
        if (seconds < 0 || seconds > 59) {
            seconds = -1;
        }
    }

    // Установка результатов
    if (oHours) *oHours = hours;
    if (oMinutes) *oMinutes = minutes;
    if (oSeconds) *oSeconds = seconds;

    return 0;  // Возвращаем 0 для формата
}

int main() {
    char timeStr[16];
    int hours = -1, minutes = -1, seconds = -1, result;

    // Считывание строки времени
    scanf("%15s", timeStr);

    // Первый вызов: все указатели ненулевые
    result = readTime(timeStr, &hours, &minutes, &seconds);
    printf("%d %d %d %d\n", result, hours, minutes, seconds);

    // Второй вызов: oSeconds нулевой
    result = readTime(timeStr, &hours, &minutes, NULL);
    printf("%d %d %d\n", result, hours, minutes);

    // Третий вызов: oMinutes и oSeconds нулевые
    result = readTime(timeStr, &hours, NULL, NULL);
    printf("%d %d\n", result, hours);

    return 0;
}
