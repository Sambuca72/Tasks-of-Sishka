#include <stdio.h>
#include <ctype.h> 
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char symbol;           //переменная для хранения текущего символа
    int in_word = 0;       //флаг для отслеживания находимся ли мы внутри слова
    int word_count = 0;    //счетчик слов
    //чтение символов по одному, пока не встретится символ новой строки '\n'
    while (scanf("%c", &symbol) == 1 && symbol != '\n') 
    {
        //если текущий символ является буквой латинского алфавита
        if (isalpha(symbol)) 
        {
            //если до этого мы не были в начале нового слова
            if (!in_word) 
            {
                word_count++; 
                in_word = 1; //устанавливаем флаг, что мы находимся внутри слова
            }
        } 
        else if (symbol == '.') 
        {
            //если встретили точку, то считаем, что слово завершилось (или продолжается разделение точками)
            in_word = 0; //сбрасываем флаг in_word, так как точка разделяет слова
        }
    }
    printf("%d\n", word_count);
    fclose(stdin);
    fclose(stdout);
    return 0; 
}
