#include <stdio.h>
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int H, M, S, K;
    scanf("%d %d %d %d", &H, &M, &S, &K);
    // Добавляем секунды
    S += K;
    // Если секунд больше 60, пересчитываем минуты и секунды
    M += S / 60;
    S = S % 60;
    // Если минут больше 60, пересчитываем часы и минуты
    H += M / 60;
    M = M % 60;
    // Если часов больше 24, пересчитываем количество часов
    H = H % 24;
    printf("%d %d %d\n", H, M, S);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

