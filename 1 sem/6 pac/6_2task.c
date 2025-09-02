#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

//cтруктура Node представляет узел односвязного списка
typedef struct Node {
    char value[8]; //cтроковое значение узла (до 7 символов + '\0')
    int next; //индекс следующего узла (или -1, если следующего узла нет)
} Node;

Node nodes[MAX_NODES]; //массив для хранения всех узлов списка
int node_count; //отслеживание количества узлов в списке

//функция для представления списка
//принимает начальное количество узлов и устанавливает node_count в это значение
void init_list(int n) 
{
    node_count = n;
}
//функция для добавления нового узла в список
int add_node(int index, const char *value) 
{
    strcpy(nodes[node_count].value, value); //копируем строковое значение в новый узел
    nodes[node_count].next = nodes[index].next; //новый узел указывает на следующий узел после исходного узла
    nodes[index].next = node_count; //изменяем указатель исходного узла на новый узел
    return node_count++; 
}
//функция для удаления узла
char* delete_node(int index) 
{
    int to_delete = nodes[index].next; //находим индекс узла, который нужно удалить
    nodes[index].next = nodes[to_delete].next; //обновляем указатель текущего узла, пропуская удаляемый узел
    return nodes[to_delete].value; //возвращаем строковое значение удаленного узла
}
//функция для вывода значений узлов списка
//принимает индекс первого узла и выводит значения узлов в порядке следования
void print_list(int first) 
{
    int current = first;  //начинаем с первого узла
    while (current != -1) //идем по списку, пока не достигнем конца (next == -1)
    {                       
        printf("%s\n", nodes[current].value);
        current = nodes[current].next; //переходим к следующему узлу
    }
}
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, F, Q;
        scanf("%d %d %d", &N, &F, &Q);
        //чтение начальных узлов
        init_list(N);
        for (int i = 0; i < N; i++) 
        {
            scanf("%s %d", nodes[i].value, &nodes[i].next);
        }

        //обработка операций
        while (Q--) 
        {
            int type, index;
            scanf("%d %d", &type, &index);

            if (type == 0) //операция добавления
            { 
                char new_value[8];
                scanf("%s", new_value);

                if (index == -1) //вставка в начало
                { 
                    int new_index = node_count++;
                    strcpy(nodes[new_index].value, new_value);
                    nodes[new_index].next = F;
                    F = new_index;
                    printf("%d\n", new_index);
                } else 
                {   // Вставка после указанного узла
                    int new_index = add_node(index, new_value);
                    printf("%d\n", new_index);
                }
            } else if (type == 1) //операция удаления 
            { 
                if (index == -1) //удаление первого элемента
                { 
                    int old_first = F;
                    F = nodes[F].next;
                    printf("%s\n", nodes[old_first].value);
                } else //удаление после указанного узла 
                { 
                    printf("%s\n", delete_node(index));
                }
            }
        }
        printf("===\n");
        print_list(F);
        printf("===\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
