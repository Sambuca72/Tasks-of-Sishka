#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REQUESTS 100000
//массив указателей для хранения строк
char *strings[MAX_REQUESTS] = {NULL};
//массив для хранения длины строк
size_t lengths[MAX_REQUESTS] = {0};
int main() 
{
    int N; //количество запросов
    scanf("%d", &N);

    int current_string_id = 0; //идентификатор текущей строки

    for (int i = 0; i < N; i++) 
    {
        int t; //тип запроса
        scanf("%d", &t);
        if (t == 0) {
            //запрос создания строки
            int l; //длина новой строки
            scanf("%d", &l);

            //выделяем память для строки, включая место для терминального символа '\0'
            strings[current_string_id] = (char *)malloc((l + 1) * sizeof(char));
            if (strings[current_string_id] == NULL) 
            {
                //если выделение памяти не удалось, выводим ошибку и завершаем программу
                perror("Ошибка выделения памяти");
                return 1;
            }
            //считываем строку и сохраняем её в массив
            scanf("%s", strings[current_string_id]);
            lengths[current_string_id] = l; //сохраняем длину строки

            //увеличиваем идентификатор строки для следующего запроса
            current_string_id++;
        } else if (t == 1) 
        {
            //запрос удаления строки
            int k; //индекс строки, который нужно удалить
            scanf("%d", &k);

            //освобождаем память для строки с идентификатором k
            free(strings[k]);
            strings[k] = NULL; //указываем, что строка удалена
        } else if (t == 2) 
        {
            //запрос вывода строки
            int k; //индекс строки для вывода
            scanf("%d", &k);

            //если строка существует, печатаем её
            if (strings[k] != NULL) 
            {
                printf("%s\n", strings[k]);
            }
        } else if (t == 3) 
        {
            //запрос подсчета количества символов в строке
            int k; //индекс строки для анализа
            char c; //символ, который нужно подсчитать
            scanf("%d %c", &k, &c);

            //подсчитываем количество символов c в строке с идентификатором k
            if (strings[k] != NULL) 
            {
                int count = 0; //счетчик символов
                for (size_t j = 0; j < lengths[k]; j++) 
                {
                    if (strings[k][j] == c) 
                    {
                        count++; //увеличиваем счетчик, если символ совпадает
                    }
                }
                printf("%d\n", count); //выводим количество найденных символов
            }
        }
    }

    //освобождаем память для всех оставшихся строк
    for (int i = 0; i < current_string_id; i++) {
        if (strings[i] != NULL) 
        {
            free(strings[i]); //удаляем строку, если она еще существует
        }
    }
    return 0;
}
