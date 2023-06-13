#include <iostream>
#include <cmath>
#include <algorithm>
#include "hord.h"

using namespace std;

//�������
float f(float x)
{
    return x*x*x+1.34*x-2.54;
}

//����������� �������
float f1(float x)
{
    return 3*x*x+1.34;
}

//������ ����������� �������
float f2(float x)
{
    return 6*x;
}


float hord(float a, float b, float e)
{
    //��������� m
    float m = min(abs(f1(a)), abs(f1(b)));
    float x;

    int i = 0;

    //���������� ��������� �����������
    if (f(b) * f2(b) > 0)
    {
        x = a;
    }
    else
    {
        x = b;
        b = a;
        a = x;
    }


    while (abs(f(x) / m) > e)
    {
        //������� - ����� ��������; ���������� x; ���������� y; �����������; ���������, ������� �������� ��� ����� ��������
        cout << "\t\t" << i << "\t\t" << x << "\t\t" << f(x) << "\t\t" << f1(x) << "\t\t" << abs(f(x)) / m << endl;
        //����� x ��� ��������� ��������
        x = x - f(x) * ((b - x) / (f(b) - f(x)));
        i++;
    }


    //���������� �������� x
    return (x);
}