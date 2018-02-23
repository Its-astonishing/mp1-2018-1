#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;

class TFraction
{
private:
	int num1; //��������� ������ �����
	int denom1; //����������� ������ �����
	int num2; //��������� ������ �����
	int denom2; //����������� ������ �����
	int numtot;
	int denomtot;
public:
	TFraction() : num1(0), denom1(0), num2(0), denom2(0)
	{}
	void set()
	{
		cout << "������� ��������� � ����������� ������ ����� (����� ����� ���� ������������, � ����������� �� ����� ����)\n" << endl;
		cin >> num1;
		cin >> denom1;
		cout << "������� ��������� � ����������� ������ ����� (����� ����� ���� ������������, � ����������� �� ����� ����)\n" << endl;
		cin >> num2; 
		cin >> denom2;
		if (((denom2 = 0) || (num2 >= denom2))||((denom1 = 0) || (num1 >= denom1)))
			return;
		/*if (num1 % denom1 == 0)
		{
			denom1 = denom1 / num1;
			num1 = num1 / num1;
		}
		if (num2 % denom2 == 0)
		{
			denom2 = denom2 / num2;
			num2 = num2 / num2;
		}*/
	}
	void operation()
	{
		char op;
		cout << "�������� ��������: ��������(+), ���������(-), ���������(*) ��� �������(:)\n";
		cin >> op;
		switch (op)
		{
		case '+':
			if (denom1 == denom2)
			{
				numtot = num1 + num2;
				denomtot = denom1;
			}
			else
			{
				denomtot = denom1 * denom2;
				numtot = (num1 * denom2) + (num2 * denom1);
			}
			break;
		case '-':
			if (denom1 == denom2)
			{
				numtot = num1 - num2;
				denomtot = denom1;
			}
			else
			{
				denomtot = denom1 * denom2;
				numtot = (num1 * denom2) - (num2 * denom1);
			}
			break;
		case '*':
			numtot = num1 * num2;
			denomtot = denom1 * denom2;
			break;
		case ':':
			numtot = num1 * denom2;
			denomtot = denom1 * num2;
			break;
		}
	}
	void show()
	{
		cout << "����: " << numtot << "/" << denomtot << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	TFraction a1;
	a1.set();
	a1.operation();
	a1.show();
	system("pause");
	return 0;
 }