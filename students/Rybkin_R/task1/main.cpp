#include <iostream>
using namespace std;
class ConverterTemperature {
	double t;
public:
	ConverterTemperature(double a = 0) : t(a) {}
	ConverterTemperature &operator=(double _t)
	{
		t = _t;
		return *this;
	} // ���������� ��������� ������������ ��� �����
	ConverterTemperature &operator=(const ConverterTemperature &temperature)
	{
		t = temperature.t;
		return *this;
	}//�������� ������������ ����� ��������� ������ ������
	void TemperatureC()
	{
		cout << "����������� = " << t << "C \n";
	}
	void TemperatureF()
	{
		cout << "����������� = " << Farengeit() << "F \n";
	}
	void TemperatureK()
	{
		cout << "����������� = " << Kelvin() << "K \n";
	}
	void TemperatureRa()
	{
		cout << "����������� = " << Rankin() << "Ra \n";
	}
	void TemperatureR()
	{
		cout << "����������� = " << Reomyr() << "R \n";
	}
	void TemperatureAll()
	{
		TemperatureC();
		TemperatureF();
		TemperatureK();
		TemperatureRa();
		TemperatureR();
	}  //������� �� ������� ����������� �� ���� �����
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
	ConverterTemperature Monday(a);
	ConverterTemperature Tuesday(5);
	Monday.TemperatureC();
	Monday.TemperatureF();
	Monday.TemperatureK();
	Monday.TemperatureRa();
	Monday.TemperatureR();
	cout << "\n";
	Monday = 7.0; // ������������ ����� ������
	Monday.TemperatureAll();
	cout << "\n";
	Monday = Tuesday;//������������ ����� ��������
	Monday.TemperatureAll();
	system("pause");
	return 0;
}