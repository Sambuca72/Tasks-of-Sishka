#include <stdio.h>

int main() {
    int character = 0;
    int charCount[128] = {0}; // Массив для подсчета символов 

    FILE *fileIn = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout); 
    // Читаем символы из файла
    while ((character = fgetc(fileIn)) != EOF) 
    {
        if (character >= 32 && character < 128) 
        {
            charCount[character]++;
        }
    }
    // Проходим по диапазону символов от 32 до 127
    for (int i = 32; i < 128; i++) {
        if (charCount[i] > 0) {
            printf("%c ", i); // Выводим символ

            // Выводим количество в виде '#'
            for (int k = 0; k < charCount[i]; k++) 
            {
                printf("#");
            }

            printf("\n");
        }
    }
    fclose(fileIn);
    fclose(stdout);
    return 0;
}
