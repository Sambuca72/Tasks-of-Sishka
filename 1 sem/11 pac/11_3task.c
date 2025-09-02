#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  

#define TABLE_SIZE 1000000  // определение размера хеш-таблицы

// структура для хранения состояния, индекса и указателя на следующий элемент в списке
typedef struct State {
    uint64_t state;  // состояние
    int index; 
    struct State* next;  // указатель на следующий элемент
} State;

// функция для вычисления нового состояния
uint64_t func(uint64_t s, uint64_t a, uint64_t b, uint64_t c, uint64_t M) {
    return (s * s * a + s * b + c) % M;  // вычисление нового состояния по формуле
}

// хеш-таблица для хранения состояний
State* hash_table[TABLE_SIZE];

// функция для вычисления хеш-ключа
unsigned int hash(uint64_t state) {
    return state % TABLE_SIZE;  // вычисление хеш-ключа как остаток от деления состояния на размер таблицы
}

// функция для добавления состояния в хеш-таблицу
void add_to_hash_table(uint64_t state, int index) {
    unsigned int key = hash(state);  // вычисление хеш-ключа
    State* new_state = (State*)malloc(sizeof(State));  // создание нового элемента
    new_state->state = state;  // установка состояния
    new_state->index = index;  // установка индекса
    new_state->next = hash_table[key];  // добавление нового элемента в начало списка
    hash_table[key] = new_state;  // обновление хеш-таблицы
}

// функция для поиска состояния в хеш-таблице
int find_in_hash_table(uint64_t state) {
    unsigned int key = hash(state);  // вычисление хеш-ключа
    State* current = hash_table[key];  // начало списка
    while (current != NULL) {  // пока не достигнут конец списка
        if (current->state == state) {  // если состояние найдено
            return current->index;  // возвращение индекса
        }
        current = current->next;  // переход к следующему элементу списка
    }
    return -1;  // возвращение -1, если состояние не найдено
}

int main() {
    uint64_t M, a, b, c;
    scanf("%lu %lu %lu %lu", &M, &a, &b, &c);  // ввод параметров

    uint64_t state = 1;  // начальное состояние
    int index = 0;  // начальный индекс
    int l = -1, r = -1;  // переменные для хранения индексов начала и конца цикла

    // инициализация хеш-таблицы
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;  // установка всех элементов таблицы в NULL
    }

    // основной цикл для поиска цикла
    while (r == -1) {
        int existing_index = find_in_hash_table(state);  // поиск состояния в хеш-таблице
        if (existing_index != -1) {  // если состояние найдено
            l = existing_index;  // установка начала цикла
            r = index;  // установка конца цикла
        } else {
            add_to_hash_table(state, index);  // добавление состояния в хеш-таблицу
            state = func(state, a, b, c, M);  // вычисление нового состояния
            index++;  // увеличение индекса
        }
    }

    printf("%d %d\n", l, r);  // вывод индексов начала и конца цикла

    // освобождение памяти
    for (int i = 0; i < TABLE_SIZE; i++) {
        State* current = hash_table[i];  // начало списка
        while (current != NULL) {  // пока не достигнут конец списка
            State* temp = current;  // временная переменная для освобождения памяти
            current = current->next;  // переход к следующему элементу
            free(temp);  
        }
    }

    return 0;  
}
