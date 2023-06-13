#include <iostream>
#include <cmath>
#include <algorithm>
#include "hord.h"

using namespace std;

//�������
float f_hord(float x)
{
    return x*x*x+1.34*x-2.54;
}

//����������� �������
float f1_hord(float x)
{
    return 3*x*x+1.34;
}

//������ ����������� �������
float f2_hord(float x)
{
    return 6*x;
}


float hord(float a, float b, float e)
{
    //��������� m
    float m = min(abs(f1_hord(a)), abs(f1_hord(b)));
    float x;

    int i = 0;

    //���������� ��������� �����������
    if (f_hord(b) * f2_hord(b) > 0)
    {
        x = a;
    }
    else
    {
        x = b;
        b = a;
        a = x;
    }


    while (abs(f_hord(x) / m) > e)
    {
        //������� - ����� ��������; ���������� x; ���������� y; �����������; ���������, ������� �������� ��� ����� ��������
        cout << "\t\t" << i << "\t\t" << x << "\t\t" << f_hord(x) << "\t\t" << f1_hord(x) << "\t\t" << abs(f_hord(x)) / m << endl;
        //����� x ��� ��������� ��������
        x = x - f_hord(x) * ((b - x) / (f_hord(b) - f_hord(x)));
        i++;
    }


    //���������� �������� x
    return (x);
}