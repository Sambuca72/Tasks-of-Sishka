#include <stdio.h>
#include <string.h>
#define MAX_DIGITS 1000 
//функция для умножения двух длинных чисел, в виде строк
void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1); //длина первого числа
    int len2 = strlen(num2); //длина второго числа
    int tempResult[MAX_DIGITS * 2] = {0}; //массив для хранения промежуточных результатов
    //умножение цифр первого числа на цифры второго числа
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            //умножаем цифры и добавляем результат к tempResult с учётом позиции
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int posLow = i + j + 1; //позиция младшего разряда
            int posHigh = i + j; //позиция старшего разряда
            //добавляем значение к текущей позиции в tempResult
            mul += tempResult[posLow];
            tempResult[posLow] = mul % 10; //сохраняем младший разряд
            tempResult[posHigh] += mul / 10; //добавляем перенос к старшему разряду
        }
    }
    //находим начало числа, пропуская ведущие нули
    int start = 0;
    while (start < len1 + len2 && tempResult[start] == 0) {
        start++;
    }
    //формируем строку результата, превращая каждое число в символ
    int index = 0;
    for (int i = start; i < len1 + len2; i++) {
        result[index++] = tempResult[i] + '0';
    }
    result[index] = '\0'; //завершаем строку нулевым символом
    //при умножении на 0, записываем 0
    if (index == 0) {
        strcpy(result, "0");
    }
}
int main() {
    //объявление строк для ввода чисел и хранения результата
    char num1[MAX_DIGITS + 1], num2[MAX_DIGITS + 1];
    char result[MAX_DIGITS * 2 + 1] = {0};  //массив для хранения результата умножения
    scanf("%s", num1);
    scanf("%s", num2); 
    multiply(num1, num2, result);
    printf("%s\n", result);
    return 0;
}
