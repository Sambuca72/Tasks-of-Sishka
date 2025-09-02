#include <stdio.h>   
#include <stdlib.h>  
#include <stdint.h> 

// функция для обмена значений двух переменных
void swap(int32_t *a, int32_t *b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

// функция для восстановления свойства кучи
void heapify(int32_t *arr, int n, int i) {
    int largest = i; // текущий узел считаем самым большим
    int left = 2 * i + 1; // индекс левого элемента в поддереве
    int right = 2 * i + 2; // индекс правого элемента в поддереве

    if (left < n && arr[left] > arr[largest]) { // если левый элемент больше текущего
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) { // если правый элемент больше текущего
        largest = right;
    }

    if (largest != i) { // если самый большой элемент не текущий
        swap(&arr[i], &arr[largest]); // меняем местами
        heapify(arr, n, largest); // рекурсивно восстанавливаем кучу
    }
}

// функция для сортировки массива методом пирамидальной сортировки (heap sort)
void heap_sort(int32_t *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) { // строим максимальную кучу
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) { // сортируем массив
        swap(&arr[0], &arr[i]); // переносим текущий корень в конец
        heapify(arr, i, 0); // восстанавливаем кучу на уменьшенном массиве
    }
}

int main() {
    FILE *input_file = fopen("input.bin", "rb"); // открываем входной файл
    if (!input_file) {                           
        perror("ошибка");
        return 1;
    }

    int32_t N; //размера массива
    fread(&N, sizeof(int32_t), 1, input_file); // читаем размер массива из файла

    if (N == 0) { // если массив пустой
        FILE *output_file = fopen("output.bin", "wb"); // создаём выходной файл
        fclose(output_file);
        fclose(input_file);
        return 0;                               
    }

    int32_t *arr = (int32_t *)malloc(N * sizeof(int32_t)); // выделяем память для массива
    if (!arr) { // проверка на ошибку выделения памяти
        fprintf(stderr, "ошибка.\n");
        fclose(input_file);
        return 1;
    }

    fread(arr, sizeof(int32_t), N, input_file); // читаем массив из файла
    fclose(input_file);

    heap_sort(arr, N); // сортируем массив методом heap sort

    FILE *output_file = fopen("output.bin", "wb"); 
    if (!output_file) { //открываем выходной файл                         
        perror("ошибка");
        free(arr);
        return 1;
    }

    fwrite(arr, sizeof(int32_t), N, output_file); // записываем отсортированный массив в файл
    fclose(output_file);                          
    free(arr); 

    return 0; 
}
