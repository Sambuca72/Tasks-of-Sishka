#include <stdio.h>
void printTime(int h, int m, int s) {
    printf("%02d:%02d:%02d\n", h, m, s);
}
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);  // Чтение количества времени

    int times[N][3];  // Двумерного массив для хранения времён

    for (int i = 0; i < N; i++) {  // Чтение всех времён в массив
        scanf("%d %d %d", &times[i][0], &times[i][1], &times[i][2]);
    }

    for (int i = 0; i < N; i++) { // Вывод всех времён из массива
        printTime(times[i][0], times[i][1], times[i][2]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
