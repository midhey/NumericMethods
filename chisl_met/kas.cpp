#include <iostream>
#include <cmath>
#include <iomanip>
#include "kas.h"

using namespace std;

//Функция пункт А
float f_a(float x) {
	return x * x * x - 0.2 * x * x + 0.3 * x - 1;
}

//Производная функции под пунктом А
float f1_a(float x) {
	return 3 * x * x - 0.4 * x + 0.3;
}

//Функция реализующая метод касательных для пункта A
void kas_a(float a, float b, float e, float x) {

	//Вычисляем m по формуле
	float m = min(abs(f1_a(a)), abs(f1_a(b)));
	int i = 0;

	cout << fixed << setprecision(6);
	cout << "\t\ti\t\tXi\t\t\tf(Xi)\t\t\tf'(Xi)\t\t\t|f(Xi)|/m" << endl;
	cout << "\t\t" << i << "\t\t" << x << "\t\t" << f_a(x) << "\t\t" << f1_a(x) << "\t\t" << abs(f_a(x)) / m << endl;

	while (abs(f_a(x)) / m > e)
	{
		i++;
		//Находим следующий x по формуле
		x = x - f_a(x) / f1_a(x);
		cout << "\t\t" << i << "\t\t" << x << "\t\t" << f_a(x) << "\t\t" << f1_a(x) << "\t\t" << abs(f_a(x)) / m << endl;
	}


}


//Функция пункт B
float f_b(float x) {
	return (1 / (tan(1.05 * x))) - x * x;
}

//Производная функции под пунктом B
float f1_b(float x) {
	return (-1.05 * x / (sin(1.05 * x) * sin(1.05 * x))) - 2 * x;
}

//Функция реализующая метод касательных для пунта B
void kas_b(float a, float b, float e, float x) {

	//Вычисляем m по формуле
	float m = min(abs(f1_b(a)), abs(f1_b(b)));
	int i = 0;

	cout << fixed << setprecision(6);
	cout << "\t\ti\t\tXi\t\t\tf(Xi)\t\t\tf'(Xi)\t\t\t|f(Xi)|/m" << endl;
	cout << "\t\t" << i << "\t\t" << x << "\t\t" << f_b(x) << "\t\t" << f1_b(x) << "\t\t" << abs(f_b(x)) / m << endl;

	while (abs(f_b(x)) / m > e)
	{
		i++;
		//Находим следующий x по формуле
		x = x - f_b(x) / f1_b(x);
		cout << "\t\t" << i << "\t\t" << x << "\t\t" << f_b(x) << "\t\t" << f1_b(x) << "\t\t" << abs(f_b(x)) / m << endl;
	}


}
