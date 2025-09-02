#include <stdio.h>
#include <string.h>
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int qua_bits; //количество битов в последовательности
    scanf("%d", &qua_bits);

    char bits[qua_bits + 1]; //массив для битовой послед-ти
    scanf("%s", bits); 

    int byte_value = 0; //переменная для хранения значения текущего байта
    int bit_count = 0;
    //обработка каждого бита
    for (int i = 0; i < qua_bits; i++) 
    {
        //рассматриваем биты поринципу, что младшие биты идут первыми
        if (bits[i] == '1') 
        {
            byte_value += (1 << bit_count);  //добавляем бит в соответствующую позицию
        }
        bit_count++;  //увеличиваем счетчик битов в байте

        //если набрано 8 битов, то выводим полученное значение байта
        if (bit_count == 8) 
        {
            printf("%d ", byte_value);
            byte_value = 0;  //обнуляем переменную для следующего байта
            bit_count = 0;   //сбрасываем счетчик битов
        }
    }

    //если остались биты, которые не набрали полный байт
    if (bit_count > 0) 
    {
        printf("%d", byte_value);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
