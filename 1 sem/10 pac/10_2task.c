#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

//структура для хранения записи
typedef struct {
    int key; //ключ записи
    char value[8]; //значение записи
} Record;

//функция для добавления записи в массив переменного размера
void add_record(Record ***arrays, int key, const char *value) {
    //если массив для данного ключа еще не создан, создаем его
    if (arrays[key] == NULL) {
        arrays[key] = (Record **)malloc(sizeof(Record *)); //выделяем память для массива указателей
        arrays[key][0] = NULL; //задаем первый элемент как NULL
    }

    //находим количество элементов в массиве
    int count = 0;
    while (arrays[key][count] != NULL) {
        count++; //увеличиваем счетчик, пока не достигнем NULL
    }

    //перевыделяем память для нового элемента
    arrays[key] = (Record **)realloc(arrays[key], (count + 2) * sizeof(Record *)); //перевыделяем память для массива указателей
    arrays[key][count] = (Record *)malloc(sizeof(Record)); //выделяем память для новой записи
    arrays[key][count]->key = key; //устанавливаем ключ
    strcpy(arrays[key][count]->value, value); //копируем значение
    arrays[key][count + 1] = NULL; //завершающий NULL
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N); //считываем количество записей

    //создаем массив указателей на массивы переменного размера
    Record ***arrays = (Record ***)malloc(1000001 * sizeof(Record **)); //выделяем память для массива указателей
    for (int i = 0; i <= 1000000; i++) {
        arrays[i] = NULL; //задаем все указатели как NULL
    }

    //считываем записи и добавляем их в соответствующие массивы
    for (int i = 0; i < N; i++) {
        int key;
        char value[8];
        scanf("%d %s", &key, value); //считываем ключ и значение
        add_record(arrays, key, value); //добавляем запись в массив
    }

    //выводим записи в порядке возрастания ключа
    for (int i = 0; i <= 1000000; i++) {
        if (arrays[i] != NULL) { //если массив для данного ключа существует
            int j = 0;
            while (arrays[i][j] != NULL) { //пока не достигнем NULL
                printf("%d %s\n", arrays[i][j]->key, arrays[i][j]->value); //выводим ключ и значение
                j++;
            }
        }
    }

    //освобождаем память
    for (int i = 0; i <= 1000000; i++) {
        if (arrays[i] != NULL) { //если массив для данного ключа существует
            int j = 0;
            while (arrays[i][j] != NULL) { //пока не достигнем NULL
                free(arrays[i][j]); //освобождаем память для каждой записи
                j++;
            }
            free(arrays[i]); //освобождаем память для массива записей
        }
    }
    free(arrays); //освобождаем память для массива указателей
    fclose(stdin);
    fclose(stdout);
    return 0; 
}
