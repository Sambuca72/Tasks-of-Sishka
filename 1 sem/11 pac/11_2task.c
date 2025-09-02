#include<stdio.h>
#include<stdlib.h>

//определение типа указателя на функцию-callback
typedef void(*callback)(void*ctx,int*value);

//определение структуры для узла связного списка
typedef struct Node{
    int value; //значение узла
    struct Node*next; //указатель на следующий узел
}Node;

//функция для обхода массива и вызова callback для каждого элемента
void arrayForeach(void*ctx,callback func,int*arr,int n){
    //цикл по всем элементам массива
    for(int i=0;i<n;i++){
        func(ctx,&arr[i]); //вызов callback для текущего элемента
    }
}

//функция для обхода связного списка и вызова callback для каждого элемента
void listForeach(void*ctx,callback func,Node*head){
    Node*current=head; //указатель на текущий узел
    //идём по всем узлам списка
    while(current!=NULL){
        func(ctx,&current->value); //вызов callback для текущего узла
        current=current->next; //переход к следующему узлу
    }
}

//функция-callback для подсчёта суммы чётных элементов
void сallback(void*ctx,int*value){
    int*sum=(int*)ctx; //контекст - указатель на сумму
    //если значение чётное
    if(*value%2==0){ 
        *sum+=*value; //добавить значение к сумме
    }
}

int main(){
    int N; //количество элементов последовательности
    scanf("%d",&N);

    int*arr=(int*)malloc(N*sizeof(int)); //выделение памяти для массива
    Node*head=NULL; //голова связного списка
    Node*current=NULL;//текущий узел связного списка

    //проходим всем элементам последовательности
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]); //чтение элемента в массив

        Node*newNode=(Node*)malloc(sizeof(Node)); //создание нового узла
        newNode->value=arr[i]; //установка значения узла
        newNode->next=NULL; //установка следующего узла в NULL

        if(head==NULL){ //если список пустой
            head=newNode; //установить новый узел как голову
            current=newNode; //установить новый узел как текущий
        }else{
            current->next=newNode; //добавить новый узел в конец списка
            current=newNode; //установить новый узел как текущий
        }
    }

    int sumArray=0; //сумма чётных элементов массива
    int sumList=0; //сумма чётных элементов списка

    arrayForeach(&sumArray,сallback,arr,N); //обход массива и подсчёт суммы чётных элементов
    listForeach(&sumList, сallback,head); //обход списка и подсчёт суммы чётных элементов

    printf("%d %d\n",sumArray,sumList); //вывод результатов

    free(arr);
    //цикл по всем узлам списка
    while(head!=NULL){
        Node*temp=head; //временный указатель на текущий узел
        head=head->next; //переход к следующему узлу
        free(temp);
    }

    return 0;
}
