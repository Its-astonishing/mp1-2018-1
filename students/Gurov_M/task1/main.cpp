# include <iostream>
# include <conio.h>
using namespace std;

class Converter
{
private:
	double w;
	double b;
	double m;
	int a;	// ���������� ���������� �� ������� ��� � �����������
public:
	Converter()
	{
		a = 0;
		cout << "������ ������������ ��� �������� ������ �������: " << endl;
		cout << "a = " << a << endl;

	}
	void setConverter()
	{
		cout << "������� ��� � ����������� = �: ";
		cin >> a;
	}
	void getConverter() //������� �� ����� ���������� ��������
	{
		cout << "������� ��� � ����������� a = " << a << endl;
	}
};
int main()
{
	int a = 0;
	setlocale(LC_ALL, "rus");
	Converter C1;

	C1.setConverter();
	C1.getConverter();
	system("pause");
}