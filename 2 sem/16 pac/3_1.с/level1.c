#include "myblas.h"

//dcopy — копируем вектор
void dcopy(int n, const double *X, double *Y)
{
    while(n--)
    {
        *Y++ = *X++;
    }
}

//dswap — меняем элементы местами
void dswap(int n, double *X, double *Y)
{
    double temp;
    while(n--)
    {
        temp = *X;
        *X++ = *Y;
        *Y++ = temp;
    }
}

//dscal — умножаем каждый элемент X на alpha
void dscal(int n, double alpha, double *X)
{
    while(n--)
    {
        *X++ *= alpha;
    }
}

//daxpy — прибавляем alpha * X к Y 
void daxpy(int n, double alpha, const double *X, double *Y)
{
    while(n--)
    {
        *Y++ += alpha * (*X++);
    }
}

//ddot — скалярное произведение
double ddot(int n, const double *X, const double *Y){
    double res = 0.0;
    while(n--){
        res += (*X++) * (*Y++);
    }
    return res;
}