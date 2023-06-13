#include <iostream>
#include <iomanip>
#include "simpson.h"

using namespace std;

//������� sin(x)
double f(double x)
{
    return sin(x);
}

//������� ���������� ���������  
double integr(double a, double b, int N)
{
    //��������� ����� ������� ����� ������
    double h = (b - a) / (2 * N);
    //������ ������ ��� �������� �������� f(x) � �����
    double* tau = new double[2 * N + 1];
    //������ ���������� ��� ���������� �������� ��������� 
    double sum = 0;

    //���� ���������� �������
    for (int i = 0; i < 2 * N; i++)
    {
        tau[i] = f(a + ((i - 1) * h));
    }

    //�� ������� ��������� �������� sum
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