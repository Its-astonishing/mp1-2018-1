#include <iostream>
#include <locale.h>

using namespace std;

class TWeighingScales
{
private:
	double kg; // ��� � ������������
public:
	TWeighingScales(double _kg = 0)// �����������
	{
		kg = _kg;
	}
	TWeighingScales & operator=(const TWeighingScales & kg1) //�������� ������������
	{
		kg = kg1.kg;
		return *this;
	}
	void display() //����� �� �����
	{
		cout << "��� � ������������: " << kg << endl;
	}
	double killograms() //�������� ��� � ������������
	{
		return kg;
	}
	double pharmacyPound() //�������������� � �������� ���� 
	{
		return kg * 2.2679;
	}

	double troyOunce() // �������������� � �������� ����� 
	{
		return kg * 35.2739;
	}
	double pood() // �������������� � ��� 
	{
		return kg * 0.061;
	}
	void displayPharmacyPound()
	{
		cout << "��� � ������� ��������� �������� ����:" << pharmacyPound() << endl;
	}
	void displayTroyOunce()
	{
		cout << "��� � ������� ��������� �������� �����:" << troyOunce() << endl;
	}
	void displayPood()
	{
		cout << "��� � ������� ��������� ���:" << pood() << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	double flag;
	int a, b;
metka2:cout << "������� ��� � ������������:";
	cin >> flag;
	TWeighingScales weight1, weight2(flag);
	weight1.operator=(weight2);
metka3:cout << "\n �������� ��������:\n" << endl;
	cout << "1. ������ ������� ��� � �����������\n" << endl;
	cout << "2. ������ ��� � ��������� ������� ���������\n" << endl;
	cout << "3. �������� ��� � �����������\n" << endl;
	cin >> a;
	switch (a)
	{
	case 1: weight2.display(); break;
	case 2:
	{
	metka1:cout << "� ����� ������� ��������� �� ������������� ������ ���?\n" << endl;
		cout << "1. �������� ����" << endl;
		cout << "2. �������� �����" << endl;
		cout << "3. ���" << endl;
		cin >> b;
		switch (b)
		{
		case 1: weight2.displayPharmacyPound(); break;
		case 2: weight2.displayTroyOunce(); break;
		case 3: weight2.displayPood(); break;
		default: cout << "������������ ����. ��������� �������.\n"; goto metka1;
		}
		break;
	}
	case 3: goto metka2;
	default: cout << "������������ ����. ��������� �������.\n"; goto metka3;
	}
}