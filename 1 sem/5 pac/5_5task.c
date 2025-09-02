#include <stdio.h>
#include <string.h>
#define MAX_DIGITS 500
typedef struct LongNum_s 
{
    int len; //количество цифр в числе
    int arr[MAX_DIGITS]; //массив десятичных цифр числа (в обратном порядке)
} LongNum;
//функция для старта длинного числа (устанавливаем его в 0)
void initLongNum(LongNum *num) 
{
    num->len = 1;  //изначально число состоит из одной цифры - ноль
    memset(num->arr, 0, sizeof(num->arr));  //обнуляем все цифры числа
}

//функция для копирования одного длинного числа в другое
void copyLongNum(LongNum *dest, const LongNum *src) 
{
    dest->len = src->len; //копируем длину числа
    memcpy(dest->arr, src->arr, sizeof(src->arr)); //копируем массив цифр
}

//функция для сложения двух длинных чисел в столбик
void addLongNum(LongNum *res, const LongNum *a, const LongNum *b) 
{
    int carry = 0; //переменная для хранения переноса при сложении
    int max_len = a->len > b->len ? a->len : b->len;  //берём максимальную длину из двух чисел
    res->len = 0;  //начальная длина результирующего числа
    //выполняем сложение поразрядно
    for (int i = 0; i < max_len || carry != 0; i++) 
    {
        int sum = carry;  //начинаем с переноса
        if (i < a->len) sum += a->arr[i];  //если разряд существует у числа a, добавляем его к сумме
        if (i < b->len) sum += b->arr[i];  //если разряд существует у числа b, добавляем его к сумме

        res->arr[res->len++] = sum % 10;  //текущая цифра суммы (единицы)
        carry = sum / 10;  //переносим оставшуюся часть суммы в следующий разряд
    }
}

//функция для печати длинного числа
void printLongNum(const LongNum *num) 
{
    //печатаем цифры в обратном порядке (от старшей к младшей)
    for (int i = num->len - 1; i >= 0; i--) 
    {
        printf("%d", num->arr[i]);
    }
    printf("\n");
}

//функция для вычисления N-го числа Фибоначчи
void fibonacci(int N) 
{
    LongNum fib1, fib2, fibN;
    //старт для первых двух чисел Фибоначчи
    initLongNum(&fib1);  // fib1 = 0
    initLongNum(&fib2);  // fib2 = 0
    fib1.arr[0] = 1; // F(1) = 1
    fib2.arr[0] = 1; // F(2) = 1
    //если N равно 1 или 2, то результат — это 1
    if (N == 1 || N == 2) {
        printLongNum(&fib1);
        return;
    }
    //основной цикл для вычисления N-го числа Фибоначчи
    for (int i = 3; i <= N; i++) 
    {
        initLongNum(&fibN);  //обнуляем fibN перед каждым новым шагом
        addLongNum(&fibN, &fib1, &fib2);  //вычисляем fibN = fib1 + fib2
        copyLongNum(&fib1, &fib2);  //сдвигаем fib1: теперь fib1 = fib2
        copyLongNum(&fib2, &fibN);  //сдвигаем fib2: теперь fib2 = fibN
    }
    printLongNum(&fibN);
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);  //вводим N => нужное число фибоначчи
    fibonacci(N);  //вызываем функцию для вычисления N-го числа Фибоначчи
    fclose(stdin);
    fclose(stdout);
    return 0;
}
