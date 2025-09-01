#include <stdio.h>
#include <stdint.h>
#define MAX_MASKS 30000
//функция для проверки, совместимы ли две маски
int areNonConflicting(uint64_t mask1, uint64_t mask2) 
{
    return (mask1 & mask2) == 0; //если побитовое &(И) равно 0, то маски совместимы
}
int main() 
{
    int q_maski;
    scanf("%d", &q_maski);
    uint64_t masks[MAX_MASKS]; //массив для хранения масок
    for (int i = 0; i < q_maski; i++) 
    {
        scanf("%llx", &masks[i]); //считываем маску в шестнадцатеричном формате
    }
    int count = 0; //счетчик совместимых пар
    //перебираем каждую маску
    for (int i = 0; i < q_maski; i++) 
    {
        //перебираем оставшиеся маски
        for (int j = i + 1; j < q_maski; j++) 
        {
            //проверяем, являются ли маски совместимыми
            if (areNonConflicting(masks[i], masks[j])) 
            {
                count++; //увеличиваем счетчик, если маски совместимы
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
