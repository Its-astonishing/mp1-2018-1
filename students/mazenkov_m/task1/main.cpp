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
		cout << "Температура в Цельсиях равна " << temp << " градусов" << endl;
	}
	void FarShow()
	{
		cout << "Температура в Фаренгейтах равна " << Faringeit() << " градусов" << endl;
	}
	void KelvShow()
	{
		cout << "Температура в Кельвинах равна " << Kelvin() << " градусов" << endl;
	}
	void RanShow()
	{
		cout << "Температура в Ранкинах равна " << Rankin() << " градусов" << endl;
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
		return (9 / 5)*temp + 32;
	}
	double Kelvin()
	{
		return temp + 273;
	}
	double Rankin()
	{
		return (temp + 273)*(9 / 5);
	}
};
int main()
{
	double T;
	setlocale(LC_ALL, "Russian");
	cout << "Введите температуру : ";
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