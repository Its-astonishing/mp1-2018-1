#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class Converter
{
private:
	int a;	// ���������� ���������� �� ������� ��� � �����������
public:
	Converter()
	{
		a = 0;
		cout << "������ ������������ ��� �������� ������ �������: " << endl;
		cout << "a = " << a << " ������� ��� � ������������" << endl;

	}
	void setConverter()
	{
		cout << "������� ��� � ����������� = �: ";
		cin >> a;
	}

	void getConverter()
	{
		cout << "������� ��� � ����������� a = " << a << endl;
	}
	void Conversion()
	{
		cout << "� ������� = " << a * 5000 << endl;
		cout << "� ������� = " << a * 1000 << endl;
		cout << "� ������� = " << a * 1000 << endl;
		cout << "� ������������ = " << a * 1000000 << endl;
		cout << "� ������� = " << a * 5000 << endl;
		cout << "� ������ = " << a * 35.27396194958 << endl;
		cout << "� ����� = " << a * 0.061 << endl;
		cout << "� ������ = " << a * 2.2046226218 << endl;
		cout << "� �������� ������  = " << a * 2.2679229035769 << endl;
	}
};
int main()
{
	int b = 0;
	int c = 1;
	setlocale(LC_ALL, "rus");
	Converter C1;
	system("pause");
	system("cls");
	while (c == 1)
	{
		cout << "����� �������� ������� ��� � ����������� ������� 1 = b " << endl;
		cout << "����� ������ ������� ��� � ����������� ������� 2 = b " << endl;
		cout << "����� ������ ������� ��� � �������� �� ����������� �������� ���� ������� 3 = b" << endl;
		cout << "����� ����� ����� �� ��������� ������� ����� ����� �������� �� ������������ ����" << endl;
		cout << "������� b =" << " ";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			C1.setConverter();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			C1.getConverter();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			C1.Conversion();
			system("pause");
			system("cls");
			break;
		}
		default:
		{

			c++;
		}
		}
	}
	system("pause");
}