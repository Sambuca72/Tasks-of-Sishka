#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //для функции isalpha
//структура для хранения количества слов и массива указателей на слова
typedef struct Tokens_s {
    int num;   //количество слов
    char **arr; //массив указателей на слова
} Tokens;

//функция для выделения слов из строки
void tokensSplit(Tokens *tokens, const char *str, const char *delims) {
    if (tokens->arr == NULL) {
        //первый проход это мы ведем подсчет количества слов
        tokens->num = 0; //обнуляем счетчик слов
        const char *token = str; //начальная позиция в строке
        while (*token) {
            //пропускаем символы-разделители
            token += strspn(token, delims);
            if (*token) {
                //если обнаружили начало слова, увеличиваем счетчик слов
                tokens->num++;
                //переходим к следующему разделителю
                token += strcspn(token, delims);
            }
        }
    } else {
        //второй проход это мы записываем слова в массив
        const char *token = str; //начальная позиция в строке
        int index = 0; //индекс текущего слова в массиве
        while (*token) {
            //пропускаем символы-разделители
            token += strspn(token, delims);
            if (*token) {
                //если нашли слово, определяем его длину
                size_t len = strcspn(token, delims); //длина слова
                //выделяем память под слово
                tokens->arr[index] = (char *)malloc((len + 1) * sizeof(char));
                if (tokens->arr[index] == NULL) {
                    //если выделение памяти не удалось, выводим ошибку и завершаем
                    perror("Ошибка выделения памяти");
                    exit(1);
                }
                //копируем слово в выделенную память
                strncpy(tokens->arr[index], token, len);
                tokens->arr[index][len] = '\0'; //добавляем завершающий символ '\0'
                index++; //переходим к следующему слову
                //переходим к следующему разделителю
                token += len;
            }
        }
    }
}

//функция для освобождения памяти
void tokensFree(Tokens *tokens) {
    if (tokens->arr != NULL) {
        //освобождаем память для каждого слова
        for (int i = 0; i < tokens->num; i++) {
            free(tokens->arr[i]);
        }
        //освобождаем память для массива указателей
        free(tokens->arr);
        tokens->arr = NULL; //обнуляем указатель, чтобы избежать повторного освобождения
        tokens->num = 0; //сбрасываем количество слов
    }
}

int main() {
    //входная строка (максимальная длина 1,000,000 символов)
    char input[1000001];
    //считываем входную строку
    scanf("%s", input);

    //символы-разделители
    const char *delims = ".,;:";

    //создаем структуру Tokens для хранения результата
    Tokens tokens = {0, NULL};

    //первый вызов tokensSplit для подсчета слов
    tokensSplit(&tokens, input, delims);

    //выделяем память для массива указателей на слова
    tokens.arr = (char **)malloc(tokens.num * sizeof(char *));
    if (tokens.arr == NULL) {
        //если выделение памяти не удалось, выводим ошибку и завершаем
        perror("Ошибка выделения памяти");
        return 1;
    }

    //второй вызов tokensSplit для извлечения слов
    tokensSplit(&tokens, input, delims);

    //выводим количество слов
    printf("%d\n", tokens.num);

    //выводим сами слова
    for (int i = 0; i < tokens.num; i++) {
        printf("%s\n", tokens.arr[i]);
    }
    //освобождаем память, выделенную под массив и строки
    tokensFree(&tokens);
    return 0;
}
