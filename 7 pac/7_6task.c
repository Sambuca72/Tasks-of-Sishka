#include <stdio.h>
#include <stdlib.h>
//структура узла для представления каждого человека в круге
typedef struct Node 
{
    int person; //номер человека
    struct Node *next; //указатель на следующий узел
} Node;

//функция для создания нового узла с номером человека
Node* createNode(int person) 
{
    Node* newNode = (Node*)malloc(sizeof(Node)); //выделяем память для нового узла
    newNode->person = person; //присваиваем номер человека
    newNode->next = NULL; //изначально указатель на следующий узел равен NULL
    return newNode; //возвращаем созданный узел
}
//функция для создания кругового связного списка из N человек
Node* createCircularList(int N) 
{
    Node* head = createNode(1); //создаем первый узел т.е первого человека
    Node* prev = head; //указатель prev будет отслеживать предыдущий узел

    //цикл для создания остальных узлов с номерами от 2 до N
    for (int i = 2; i <= N; i++) {
        Node* newNode = createNode(i); //создаем новый узел с текущим номером
        prev->next = newNode; //присоединяем новый узел к предыдущему
        prev = newNode; //обновляем prev для следующего повторения
    }
    prev->next = head; //замыкаем круг, присоединив последний узел к первому
    return head; //возвращаем указатель на первый узел т.е голову списка
}

//функция для удаления узла из кругового списка и возврата следующего узла
Node* removeNode(Node* prev, Node* curr) 
{
    prev->next = curr->next; //пропускаем текущий узел, соединяя предыдущий с следующим
    int personOut = curr->person; //сохраняем номер человека, который выходит из круга
    free(curr);
    return prev->next; //возвращаем указатель на следующий узел после удаленного
}

int main() 
{
    int people, K;
    scanf("%d %d", &people, &K);
    //создаем круговой список из какого-либо человек
    Node* head = createCircularList(people);
    Node* prev = head;
    //ставим указатель prev на последний узел, чтобы подготовиться к первому удалению
    while (prev->next != head) 
    {
        prev = prev->next;
    }
    //основной цикл для постройки процесса выбывания людей
    while (people > 0) 
    {
        //проходим K-1 шагов, чтобы достичь K-ого человека
        for (int i = 1; i < K; i++) 
        {
            prev = head; //prev указывает на текущий узел
            head = head->next; //head переходит к следующему узлу
        }
        printf("%d\n", head->person);
        //удаляем текущий узел и обновляем указатель head на следующий узел
        head = removeNode(prev, head);
        // уменьшаем количество оставшихся людей в круге
        people--;
    }
    return 0;
}
