#include <stdio.h>
#include <stdint.h>
//функция для применения операции XOR к doublе, используя маску
double xor_double(double x, uint64_t mask) {
    //преобразуем указатель на double в указатель на 64-битное целое число
    uint64_t* p = (uint64_t*)&x;
    //применяем XOR между значением double и маской
    *p ^= mask;
    //возвращаем результат обратно как double
    return x;
}
int main() {
    int test; //количество тестов
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        int P, Q; //числитель и знаменатель
        uint64_t M; //маска
        scanf("%d/%d xor %llx", &P, &Q, &M);
        //вычисляем X как P / Q, используя double
        double X = (double)P / (double)Q;
        //получаем результат после операции XOR
        double result = xor_double(X, M);
        printf("%0.15g\n", result);
    }
    return 0;
}
