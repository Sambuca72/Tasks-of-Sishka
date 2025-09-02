#include <stdio.h>
#include <stdlib.h>
#define MAX_VIDEOS 1001
//определяем структуру видео
typedef struct 
{
    int count;    //кол-во фрагментов
    int duration; //длительность фрагментов
} VideoStats;
int main() 
{
    int N;
    int videoID, duration; //хранение ID видео и длительности фрагмента
    
    //массив для хранения статистики каждого видео, где все значения будут 0
    VideoStats videos[MAX_VIDEOS] = {0};
    // Чтение количества фрагментов
    scanf("%d", &N);
    //чтение фрагментов и обновление статистики
    for (int i = 0; i < N; i++) 
    {
        scanf("%d %d", &videoID, &duration);
        videos[videoID].count++; //увеличиваем количество фрагментов для этого видео
        videos[videoID].duration += duration; //добавляем длительность фрагмента
    }
    //определение ширины для каждого столбца
    int idWidth = 3;  //ширина для ID видео
    int countWidth = 3;  //ширина для количества фрагментов
    int durationWidth = 6;  //ширина для суммарной длительности
    //заголовок таблицы
    printf("+-----+-----+--------+\n");
    //вывод данных по каждому видео, если оно имеет фрагменты
    for (int i = 0; i < MAX_VIDEOS; i++) 
    {
        if (videos[i].count > 0)
        {
            printf("| %3d | %3d | %6d |\n", i, videos[i].count, videos[i].duration);
            printf("+-----+-----+--------+\n");
        }
    }
    return 0;
}