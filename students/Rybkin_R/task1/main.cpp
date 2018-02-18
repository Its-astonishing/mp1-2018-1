#include <iostream>
using namespace std;
class Converter {
	double t = 0.0; // �� ��������� ���������� ����� 0 � C
public:
	Converter(double a) : t(a) {}
	Converter operator=(double d)
	{
		t = d;
		return *this;
	} // ���������� ��������� ������������
	void TempC()
	{
		cout << "����������� = " << t << "C \n";
	}
	void TempF()
	{
		cout << "����������� = " << Farengeit() << "F \n";
	}
	void TempK()
	{
		cout << "����������� = " << Kelvin() << "K \n";
	}
	void TempRa()
	{
		cout << "����������� = " << Rankin() << "Ra \n";
	}
	void TempR()
	{
		cout << "����������� = " << Reomyr() << "R \n";
	}
	void PrintAll()
	{
		cout << "����������� �� ����� ������� = " << t << "\n";
		cout << "����������� �� ����� �������� = " << Kelvin() << "\n";
		cout << "����������� �� ����� ���������� = " << Farengeit() << "\n";
		cout << "����������� �� ����� ������� = " << Rankin() << "\n";
		cout << "����������� �� ����� ������� = " << Reomyr() << "\n";
	}  //������� �� ������� ����������� �� ���� �����
	void Print()
	{
		int id;
		cout << "�� ����� ����� �� ������ ������ �����������: \n";
		cout << "0 - �� ����� ������� \n";
		cout << "1 - �� ����� ���������� \n";
		cout << "2 - �� ����� �������� \n";
		cout << "3 - �� ����� ������� \n";
		cout << "4 - �� ����� ������� \n";
		cout << "5 - ����� �� ���� \n";

		cin >> id;
		switch (id)
		{
		case 0: TempC(); break;
		case 1: TempF(); break;
		case 2: TempK(); break;
		case 3: TempRa(); break;
		case 4: TempR(); break;
		case 5: PrintAll(); break;
		}
	}
	double Farengeit()
	{
		return (9.0 / 5.0)*t + 32.0;
	}
	double Kelvin()
	{
		return t + 273.0;
	}
	double Rankin()
	{
		return (t + 273.0)*(9.0 / 5.0);
	}
	double Reomyr()
	{
		return (4.0 / 5.0)*t;
	}
	double Celc()
	{
		return t;
	}

};
int main()
{
	double a;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����������� : ";//������������  �����������
	cin >> a;
	Converter Monday(a);
	Monday.Print();
	Monday = 7.0;//������������
	Monday.Print();
	system("pause");
	return 0;
}
