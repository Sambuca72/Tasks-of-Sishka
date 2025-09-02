#include <stdio.h>
//функция для бинарного поиска последнего вхождения числа в отсортированном массиве
int binary_search_last(int arr[], int n, int target) 
{
    int left = 0, right = n - 1;
    int result = -1; //задаём результат как -1 на случай отсутствия элемента
    while (left <= right) 
    {
        int mid = left + (right - left) / 2; //вычисляем середину поиска
        if (arr[mid] == target) //проверяем, равен ли элемент в середине массива искомому знач. target 
        {
            result = mid; //при совпадении, обновляем результат на текущий индекс
            left = mid + 1; //продолжаем поиск вправо, чтобы найти последний индекс
        } else if (arr[mid] < target) 
        {
            left = mid + 1; //если элемент < target, смещаем левую границу
        } else {
            right = mid - 1; //если элемент > target, смещаем правую границу
        }
    }
    return result; //возвращаем последний индекс target, если элемент не найден
}
int main()
{
    int N, Q; 
    scanf("%d", &N); //считываем количество элементов
    int arr[N];
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arr[i]); //считываем элементы массива
    }
    scanf("%d", &Q); //считываем количество запросов
    int previous_result = 0; //начальное значение для предыдущего результата
    for (int i = 0; i < Q; i++) 
    {
        int X;
        scanf("%d", &X);
        int Y = X + previous_result; //вычисляем Y с учетом предыдущего результата
        int index = binary_search_last(arr, N, Y); //ищем индекс элемента Y
        printf("%d\n", index);
        previous_result = index == -1 ? 0 : index; //обновляем previous_result если элемент найден, запись идет в индекс или же обнуляем его
    }
    return 0;
}
//проверка и вывод -1