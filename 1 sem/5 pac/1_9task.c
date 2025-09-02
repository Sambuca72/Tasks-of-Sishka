#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long N;
    scanf("%lld", &N);
    long long count = 0;  // Переменная для хранения ответа
    // Перебираем все возможные значения сторон a, b, c
    for (long long a = 1; a * a * a <= N; ++a) {
        for (long long b = a; a * b * b <= N; ++b) {
            long long max_c = N / (a * b);  //максимальное значение c для текущих a и b
            count += max_c - b + 1;         //добавляем все возможные значения c, начиная с b до max_c
        }
    }
    printf("%lld\n", count);
    fclose(stdin);
    fclose(stdout);
    return 0;
}