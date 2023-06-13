#include <iostream>
#include <iomanip>
#include "simpson.h"

using namespace std;

//Функция sin(x)
double f(double x)
{
    return sin(x);
}

//Функция вычисления интеграла  
double integr(double a, double b, int N)
{
    //Вычисляем длину отрезка между узлами
    double h = (b - a) / (2 * N);
    //Создаём массив для хранений значений f(x) в узлах
    double* tau = new double[2 * N + 1];
    //Создаём переменную для вычисления значения интеграла 
    double sum = 0;

    //Цикл заполнения массива
    for (int i = 0; i < 2 * N; i++)
    {
        tau[i] = f(a + ((i - 1) * h));
    }

    //По формуле вычисляем значение sum
    {
        sum += (h / 3) * tau[0];

        for (int i = 1; i < 2 * N; i++)
        {
            sum += ((4 * h) / 3) * tau[i];
            sum += ((2 * h) / 3) * tau[i];
        }
    }

    delete[] tau;
    return sum;
}