#include <stdio.h> 
#include <stdlib.h>

// структура узла списка
typedef struct Node_s {
    struct Node_s *prev, *next; // указатели на предыдущий и следующий узлы
    void *value; // указатель на значение, хранимое в узле
} Node;

// вспомогательный узел(голова списка)
typedef Node List;
// инициализация пустого списка
void initList(List *list) {
    list->prev = list->next = list; //голова списка ссылается сама на себя
    list->value = NULL; //значение головы списка не используется, т.к нужен только для управления списком
}

//создание нового узла со значением ptr и вставка его после узла node
Node *addAfter(Node *node, void *ptr) {
    Node *newNode = (Node *)malloc(sizeof(Node)); //выделяем память под новый узел
    newNode->value = ptr; //присваиваем указатель на значение

    newNode->next = node->next; //следующий узел нового узла — следующий узел node
    newNode->prev = node; //предыдущий узел нового узла — это node

    node->next->prev = newNode; //обновляем указатель предыдущего у старого следующего узла
    node->next = newNode; //обновляем указатель следующего у node

    return newNode; //возвращаем указатель на созданный узел
}

//создание нового узла со значением ptr и вставка его перед узлом node
Node *addBefore(Node *node, void *ptr) {
    Node *newNode = (Node *)malloc(sizeof(Node)); //выделяем память под новый узел
    newNode->value = ptr; //присваиваем указатель на значение

    newNode->prev = node->prev; //предыдущий узел нового узла — предыдущий узел node
    newNode->next = node; //следующий узел нового узла — это node

    node->prev->next = newNode; //обновляем указатель следующего у старого предыдущего узла
    node->prev = newNode; //обновляем указатель предыдущего у node

    return newNode; //возвращаем указатель на созданный узел
}

// удаление узла из списка и возврат значения
void *erase(Node *node) {
    void *value = node->value; //сохраняем значение удаляемого узла

    node->prev->next = node->next; //обновляем указатель следующего у предыдущего узла
    node->next->prev = node->prev; //обновляем указатель предыдущего у следующего узла

    free(node); //освобождаем память, выделенную для узла

    return value; //возвращаем значение удалённого узла
}

// печать списка
void printList(List *list) {
    Node *current = list->next; //начинаем с первого узла после головы
    while (current != list) {   //идём до тех пор, пока не вернёмся к голове
        printf("%d\n", *(int *)current->value); //печатаем значение текущего узла
        current = current->next; //переходим к следующему узлу
    }
}

#define MAX_NODES 100005 //максимальное количество узлов

int main() {
    int T; //количество тестов
    scanf("%d", &T); //считываем количество тестов

    for (int t = 0; t < T; ++t) { //цикл по тестам
        int Q; //количество операций в текущем тесте
        scanf("%d", &Q); //считываем количество операций

        List list; //создаём вспомогательный узел (голова списка)
        initList(&list); //инициализируем пустой список

        Node *nodes[MAX_NODES] = {NULL}; //массив указателей для отслеживания узлов
        int currentIndex = 0; //текущий индекс для нового узла

        for (int i = 0; i < Q; ++i) { // цикл обработки операций
            int op, index, value; // тип операции, индекс узла, значение узла
            scanf("%d", &op); // считываем тип операции

            if (op == 1) { //добавление спереди
                scanf("%d %d", &index, &value); //считываем индекс и значение

                int *newValue = (int *)malloc(sizeof(int)); //выделяем память под значение
                *newValue = value;  //сохраняем значение

                if (index == -1) { //добавляем в начало списка
                    nodes[currentIndex] = addAfter(&list, newValue);
                } else { //добавляем после указанного узла
                    nodes[currentIndex] = addAfter(nodes[index], newValue);
                }
                currentIndex++; //увеличиваем текущий индекс

            } else if (op == -1) { //добавление сзади
                scanf("%d %d", &index, &value); //считываем индекс и значение

                int *newValue = (int *)malloc(sizeof(int)); //выделяем память под значение
                *newValue = value; //сохраняем значение

                if (index == -1) { //добавляем в конец списка
                    nodes[currentIndex] = addBefore(&list, newValue);
                } else { //добавляем перед указанным узлом
                    nodes[currentIndex] = addBefore(nodes[index], newValue);
                }
                currentIndex++; //увеличиваем текущий индекс

            } else if (op == 0) { //удаление узла
                scanf("%d", &index); //считываем индекс удаляемого узла

                int *deletedValue = (int *)erase(nodes[index]); //удаляем узел
                free(deletedValue); //освобождаем память, выделенную под значение
            }
        }

        printList(&list); //печатаем список после всех операций
        printf("===\n");  //разделитель для тестов

        Node *current = list.next; //начинаем с первого узла после головы
        while (current != &list) { //проходим весь список
            Node *next = current->next; //сохраняем указатель на следующий узел
            free(current->value); //освобождаем память значения узла
            free(current); //освобождаем память самого узла
            current = next; //переходим к следующему узлу
        }
    }

    return 0; 
}
