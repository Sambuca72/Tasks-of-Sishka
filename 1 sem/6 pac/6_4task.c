#include <stdio.h> 
#include <stdlib.h> 

#define MAX_NODES 100005 

//структура узла списка
typedef struct Node {
    int value; //значение, хранимое в узле
    int next;  //индекс следующего узла
    int prev;  //индекс предыдущего узла
} Node;

Node list[MAX_NODES]; //массив узлов
int freeIndex; //индекс следующего свободного места в массиве
int firstNode, lastNode; //индексы первого и последнего узлов списка

//функция для инициализации узла
void initializeNode(int index, int value, int next, int prev) {
    list[index].value = value; //устанавливаем значение узла
    list[index].next = next; //устанавливаем индекс следующего узла
    list[index].prev = prev; //устанавливаем индекс предыдущего узла
}

//функция для добавления узла после заданного индекса
int addNodeAfter(int index, int value) {
    int newIndex = freeIndex++; //получаем новый свободный индекс
    initializeNode(newIndex, value, -1, -1); //инициализируем новый узел

    if (index == -1) { //вставляем новый узел в начало списка
        list[newIndex].next = firstNode; //новый узел указывает на текущий первого узла
        
        //если список не пуст, то обновляем ссылку предыдущего узла
        if (firstNode != -1) {
            list[firstNode].prev = newIndex; 
        }
        firstNode = newIndex; //обновляем указатель на первый узел
        
        //если список был пуст, то новый узел становится последним
        if (lastNode == -1) { 
            lastNode = newIndex; 
        }
    } else { //вставляем новый узел после указанного узла
        list[newIndex].next = list[index].next; //новый узел указывает на следующий узел
        list[newIndex].prev = index; //новый узел указывает на текущий узел

        /*если текущий узел не последний, 
        обновляем ссылку предыдущего у следующего узла*/
        if (list[index].next != -1) { 
            list[list[index].next].prev = newIndex;
        } else {
            lastNode = newIndex; //если вставляем в конец, обновляем последний узел
        }

        list[index].next = newIndex; //обновляем ссылку следующего у текущего узла
    }
    return newIndex; //возвращаем индекс нового узла
}

//функция для добавления узла перед заданным индексом
int addNodeBefore(int index, int value) {
    int newIndex = freeIndex++; //получаем новый свободный индекс
    initializeNode(newIndex, value, -1, -1); //инициализируем новый узел

    if (index == -1) { //вставляем в конец списка
        list[newIndex].prev = lastNode; //новый узел указывает на текущий последний узел
        if (lastNode != -1) { //если список не пуст
            list[lastNode].next = newIndex; //обновляем ссылку следующего у последнего узла
        }
        lastNode = newIndex; //обновляем указатель на последний узел
        if (firstNode == -1) { //если список был пуст
            firstNode = newIndex; //новый узел становится первым
        }
    } else {
        list[newIndex].prev = list[index].prev; //новый узел указывает на предыдущий узел
        list[newIndex].next = index; //новый узел указывает на текущий узел

        if (list[index].prev != -1) {  //если текущий узел не первый
            list[list[index].prev].next = newIndex; //обновляем ссылку следующего у предыдущего узла
        } else {
            firstNode = newIndex; //если вставка в начало, обновляем firstNode
        }

        list[index].prev = newIndex; //обновляем ссылку предыдущего у текущего узла
    }
    return newIndex; //возвращаем индекс нового узла
}

//функция для удаления узла
int deleteNode(int index) {
    int value = list[index].value; //сохраняем значение узла

    if (list[index].prev != -1) { //если узел не первый
        list[list[index].prev].next = list[index].next; //обновляем ссылку следующего у предыдущего узла
    } else {
        firstNode = list[index].next; //если узел первый, обновляем firstNode
    }

    if (list[index].next != -1) { //если узел не последний
        list[list[index].next].prev = list[index].prev; //обновляем ссылку предыдущего у следующего узла
    } else {
        lastNode = list[index].prev; //если узел последний, обновляем lastNode
    }

    return value; //возвращаем значение удалённого узла
}

//функция для печати значений списка
void printList() {
    int current = firstNode; //начинаем с первого узла
    while (current != -1) {  //пока не дойдём до конца списка
        printf("%d\n", list[current].value); //печатаем значение текущего узла
        current = list[current].next; //переходим к следующему узлу
    }
}

int main() {
    int T;
    scanf("%d", &T); //считываем количество тестов

    for (int t = 0; t < T; ++t) {
        int N, F, L, Q;
        scanf("%d %d %d %d", &N, &F, &L, &Q); //читаем параметры теста

        freeIndex = N;      //устанавливаем начальный свободный индекс
        firstNode = F;      //устанавливаем первый узел
        lastNode = L;       //устанавливаем последний узел

        for (int i = 0; i < N; ++i) { //читаем данные узлов
            int value, next, prev;
            scanf("%d %d %d", &value, &next, &prev);
            initializeNode(i, value, next, prev); //инициализируем узел
        }

        for (int i = 0; i < Q; ++i) { //выполняем операции
            int op, index, value;
            scanf("%d %d", &op, &index);

            if (op == 1) { //добавить узел после
                scanf("%d", &value);
                int newIndex = addNodeAfter(index, value); //вставляем узел
                printf("%d\n", newIndex); //печатаем индекс нового узла
            } else if (op == -1) { //добавить узел перед
                scanf("%d", &value);
                int newIndex = addNodeBefore(index, value); //вставляем узел
                printf("%d\n", newIndex); //печатаем индекс нового узла
            } else if (op == 0) { //удалить узел
                int deletedValue = deleteNode(index); //удаляем узел
                printf("%d\n", deletedValue); //печатаем значение удалённого узла
            }
        }

        printf("===\n");
        printList(); 
        printf("===\n");
    }

    return 0;
}
