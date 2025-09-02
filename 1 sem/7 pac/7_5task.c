#include <stdio.h> 
#include <stdlib.h> 

// Функция для поиска индекса элемента массива, который ближе всего к числу b
// mass - указатель на массив, a - размер массива, b - число, для которого ищем ближайшее
int closest(int *mass, int a, int b) { 
    int left = 0;           // левая граница списка (начало массива)
    int right = a - 1;      // правая граница списка (конец массива)
    
    // Пока между left и right больше одного элемента
    while (right - left > 1) { 
        int middle = left + (right - left) / 2; // вычисляем средний индекс
        
        // Если текущий средний элемент меньше b, сдвигаем левую границу
        if (mass[middle] < b) { 
            left = middle; 
        } else { 
            // Иначе сдвигаем правую границу
            right = middle; 
        } 
    } 
    
    // Проверяем, равен ли элемент на left или right числу b
    if (mass[left] == b) { 
        return left; 
    } 
    if (mass[right] == b) { 
        return right; 
    } 
    
    // Если число b не найдено, возвращаем индекс элемента, который ближе
    if (abs(mass[left] - b) < abs(mass[right] - b)) { 
        return left; 
    } else { 
        return right; 
    } 
} 

int main() { 
    int n; 
    scanf("%d", &n); // Считываем размер массива
    
    // Выделяем память для массива
    int *mass = (int *)malloc(n * sizeof(int)); 
    
    // Считываем элементы массива
    for (int i = 0; i < n; i++) { 
        scanf("%d", &mass[i]); 
    } 
    
    int q; 
    scanf("%d", &q); // Считываем количество запросов
    
    // Обрабатываем q запросов
    for (int j = 0; j < q; j++) { 
        int y; 
        scanf("%d", &y); // Считываем число, для которого ищем ближайший элемент
        
        // Ищем индекс ближайшего элемента
        int index = closest(mass, n, y); 
        
        // Рассчитываем разницу между найденным элементом и числом y
        int lena = abs(mass[index] - y); 
        
        // Выводим индекс ближайшего элемента и разницу
        printf("%d %d\n", index, lena); 
    } 
    
    // Освобождаем выделенную память
    free(mass); 
    
    return 0; 
}

