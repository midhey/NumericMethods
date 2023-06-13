#include <iostream>
#include <random>
#include "monte.h"

using namespace std;

//�������
float f(float x)
{
	return (x + 1)*sin(x);
}

//����� �����-�����
void Monte(float a, float b, float N)
{
	//��������� ��������� ������������������ � ������� �������� ����������
	random_device rd;
	//���������� ��������� �����
	mt19937 gen(rd());
	//��������� ����������� ������������� (������ �������� ��������� ��������) ����� � ��������� ������� � �������� ���������,
	//������� �������� ���������� � �����������.
	uniform_real_distribution<> dis(0, 1);
	//��� ����� ������
	float H = (b - a) / N;
	float x;
	float sum = 0;
	for (int i = 0; i < N; i++)
	{
		//��������� x �� �������
		x = a + (b - a) * dis(gen);
		//��������� ����� �� �������
		sum += f(x) * H;
	}
	cout << sum;
}


