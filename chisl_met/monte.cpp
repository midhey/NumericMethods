#include <iostream>
#include <random>
#include "monte.h"

using namespace std;

//Функция
float f(float x)
{
	return (x + 1)*sin(x);
}

//Метод Монте-Карло
void Monte(float a, float b, float N)
{
	//Формирует случайную последовательность с помощью внешнего устройства
	random_device rd;
	//Генерирует случайное число
	mt19937 gen(rd());
	//Формирует равномерное распределение (каждое значение одинаково вероятно) чисел с плавающей запятой в выходном диапазоне,
	//который является включающим и исключающим.
	uniform_real_distribution<> dis(0, 1);
	//Шаг между узлами
	float H = (b - a) / N;
	float x;
	float sum = 0;
	for (int i = 0; i < N; i++)
	{
		//Вычисляем x по формуле
		x = a + (b - a) * dis(gen);
		//Вычисляем сумму по формуле
		sum += f(x) * H;
	}
	cout << sum;
}


