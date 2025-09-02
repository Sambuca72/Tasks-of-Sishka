#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h> 

// структура узла для двоичного дерева поиска
typedef struct Node {
    int32_t data; // значение узла
    struct Node *left; // указатель на левое поддерево
    struct Node *right; // указатель на правое
} Node;

// функция для создания нового узла
Node* create_node(int32_t value) {
    Node *new_node = (Node *)malloc(sizeof(Node)); // выделяем память для нового узла
    // проверка на выделение памяти
    if (!new_node) { 
        fprintf(stderr, "ошибка\n");
        exit(1); 
    }
    new_node->data = value; // задаём значение узла
    new_node->left = NULL;  // левый подузел отсутствует
    new_node->right = NULL; // правый подузел также
    return new_node; // возвращаем указатель на созданный узел
}

// функция для подстановки значения в двоичное дерево поиска
Node* insert(Node *root, int32_t value) {
    // если дерево пустое, создаём новый узел
    if (root == NULL) { 
        return create_node(value); 
    }

    // если значение меньше или равно корню, вставляем в левое поддерево
    if (value <= root->data) { 
        root->left = insert(root->left, value);
    // иначе вставляем в правое поддерево
    } else { 
        root->right = insert(root->right, value);
    }

    return root; // возвращаем указатель на корень дерева
}

// функция для обхода дерева (in-order) и записи результата в массив
void in_order_traversal(Node *root, int32_t *arr, int *index) {
    // если узел не пуст
    if (root != NULL) { 
        in_order_traversal(root->left, arr, index); // обходим левое поддерево
        arr[(*index)++] = root->data;              // записываем значение текущего узла в массив
        in_order_traversal(root->right, arr, index); // обходим правое поддерево
    }
}

// функция для освобождения памяти, выделенной для дерева
void free_tree(Node *root) {
    // если узел не пуст
    if (root != NULL) {       
        free_tree(root->left); 
        free_tree(root->right); 
        free(root); // освобождаем память для текущего узла
    }
}

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    // если файл не удалось открыть
    if (!input_file) { 
        perror("ошибка"); 
        return 1; 
    }

    // читаем размер массива из файла
    int32_t N;
    fread(&N, sizeof(int32_t), 1, input_file);

    // если массив пустой, создаём пустой выходной файл и завершаем программу
    if (N == 0) {
        FILE *output_file = fopen("output.bin", "wb"); 
        fclose(output_file); 
        fclose(input_file);  
        return 0; 
    }

    // выделяем память для массива
    int32_t *arr = (int32_t *)malloc(N * sizeof(int32_t));
    // проверка на выделение памяти
    if (!arr) { 
        fprintf(stderr, "ошибка\n");
        fclose(input_file); 
        return 1; 
    }

    // читаем массив из входного файла
    fread(arr, sizeof(int32_t), N, input_file);
    fclose(input_file); 

    // создаём двоичное дерево поиска и заполняем его элементами массива
    Node *root = NULL; // корень дерева
    for (int i = 0; i < N; i++) {
        root = insert(root, arr[i]); // вставляем элемент в дерево
    }

    // выполняем обход дерева (in-order) для получения отсортированного массива
    int index = 0;
    in_order_traversal(root, arr, &index);

    FILE *output_file = fopen("output.bin", "wb");
    // если файл не удалось открыть
    if (!output_file) { 
        perror("ошибка"); 
        free(arr); 
        free_tree(root); // освобождаем память, выделенную для дерева
        return 1;
    }

    // записываем отсортированный массив в выходной файл
    fwrite(arr, sizeof(int32_t), N, output_file);
    fclose(output_file); 

    free(arr);      
    free_tree(root); 

    return 0; 
}