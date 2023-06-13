#include <iostream>
#include <cmath>
#include <iomanip>
#include "iter.h"
#include "kas.h"
#include "hord.h"
#include "simpson.h"
#include "monte.h"

using namespace std;

void menu() {
	int choice;
	choice = 100;
	do
	{
		cout << "1. Метод итераций\n2. Метод касательных\n3. Метод хорд\n4. Метод Симпсона\n5. Метод Монте-Карло";

		cout << "\n\nВыберите пункт меню:";
		cin >> choice;

		system("\n\ncls");

		switch (choice)
		{
		case 1:
			iteration();
			break;
		case 2:
			kas_a(0, 2, 0.1, 0);
			cout << "\n\n\n\n";
			kas_b(0.5, 4, 0.000001, 0.5);
			break;
		case 3:
			cout << endl << "\t" << hord(0, 1, 0.000001) << endl;
			break;
		case 4:
			//В цикле вызываем функцию, увеличивая количество узлов с каждой итерацией
			for (int i = 1; i < 1001; i++)
			{
				cout << setprecision(10) << i << "\t\t" << integr(0, 3.14, i) << endl;
			}
			break;
		case 5:
			Monte(1.6, 2.4, 1000);
			cout << "\n\nExact value - 0.3993030487103553";
			break;

		default:
			break;
		}

		cout << "\n\n\n";
	} while (choice != 0);
}


int main()
{
	setlocale(LC_ALL(), "rus");
	menu();

	return(0);
}
