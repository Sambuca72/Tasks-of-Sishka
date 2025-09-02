#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KEY 1000000 
#define MAX_VALUE_LENGTH 8 //максимальная длина строки + 1 для '\0'
//структура узла связного списка
typedef struct Node {
    int key; //ключ записи
    char value[MAX_VALUE_LENGTH]; //значение записи
    struct Node *next; //указатель на следующий элемент списка
} Node;

//массив указателей на списки, один список для каждого возможного ключа
Node *lists[MAX_KEY + 1] = {NULL};

//функция добавления записи в связный список
void add_to_list(int key, const char *value) {
    //выделяем память для нового узла
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        //если память не выделилась, завершаем программу с ошибкой
        perror("Ошибка выделения памяти");
        exit(1);
    }
    new_node->key = key; //устанавливаем ключ записи
    strcpy(new_node->value, value); //копируем строку в узел
    new_node->next = NULL; //новый узел пока не связан с другими

    //добавляем узел в конец списка для данного ключа
    if (lists[key] == NULL) {
        //если список пуст, делаем новый узел его началом
        lists[key] = new_node;
    } else {
        //иначе находим последний узел и связываем его с новым
        Node *current = lists[key];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
int main() {
    int N; //количество записей
    scanf("%d", &N);

    //считываем записи и распределяем их по соответствующим спискам
    for (int i = 0; i < N; i++) {
        int key; //ключ записи
        char value[MAX_VALUE_LENGTH]; //значение записи
        scanf("%d %s", &key, value);

        //добавляем запись в список с индексом key
        add_to_list(key, value);
    }

    //проходим по массиву списков и выводим все записи
    for (int i = 0; i <= MAX_KEY; i++) {
        Node *current = lists[i]; //указатель на текущий узел списка
        while (current != NULL) {
            //выводим ключ и значение текущего узла
            printf("%d %s\n", current->key, current->value);
            current = current->next; //переходим к следующему узлу
        }
    }

    //освобождаем память для всех узлов в списках
    for (int i = 0; i <= MAX_KEY; i++) {
        Node *current = lists[i]; //указатель на текущий узел списка
        while (current != NULL) {
            Node *temp = current; //сохраняем указатель на текущий узел
            current = current->next; //переходим к следующему узлу
            free(temp); 
        }
    }

    return 0;
}
