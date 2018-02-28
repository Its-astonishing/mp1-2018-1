#include <iostream>
using namespace std;
class ConverterTemperature
{
	double temp;
public:
	ConverterTemperature(double T = 0) : temp(T) {}
	ConverterTemperature& operator=(double _t)
	{
		temp = _t;
		return *this;
	}
	ConverterTemperature& operator=(const ConverterTemperature& temperatura)
	{
		temp = temperatura.temp;
		return *this;
	}
	void CelsShow()
	{
		cout << "����������� � �������� ����� " << temp << " ��������" << endl;
	}
	void FarShow()
	{
		cout << "����������� � ����������� ����� " << Faringeit() << " ��������" << endl;
	}
	void KelvShow()
	{
		cout << "����������� � ��������� ����� " << Kelvin() << " ��������" << endl;
	}
	void RanShow()
	{
		cout << "����������� � �������� ����� " << Rankin() << " ��������" << endl;
	}
	void Show()
	{
		CelsShow();
		FarShow();
		KelvShow();
		RanShow();
	}
	double Faringeit()
	{
		return (9.0 / 5.0)*temp + 32.0;
	}
	double Kelvin()
	{
		return temp + 273.0;
	}
	double Rankin()
	{
		return (temp + 273.0)*(9.0 / 5.0);
	}
};
int main()
{
	double T;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����������� : ";
	cin >> T;
	ConverterTemperature day1(T);
	ConverterTemperature day2(24);
	day1.CelsShow();
	day1.FarShow();
	day1.KelvShow();
	day1.RanShow();
	cout << endl;
	day1 = 14;
	day1.Show();
	cout << endl;
	day1 = day2;
	day1.Show();
	system("pause");
	return 0;
}