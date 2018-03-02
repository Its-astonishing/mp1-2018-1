#include <iostream>

using namespace std;
	class TTemperature
	{
		double tC;
	public:
		TTemperature(double t = 0):tC(t)
		{
			
		}
		TTemperature &operator=(double _tC)
		{
			tC = _tC;
			return *this;
		}
		TTemperature &operator=(const TTemperature &temper)
		{
			tC = temper.tC;
			return *this;
		}
		void set_T(double tC1)
		{
			tC = tC1;
		}
		double get_tC()
		{
			return tC;
		}
		double get_tF()
		{
			double tF;
			tF = tC * 9 / 5 + 32;
			return tF;
		}
		double get_tK()
		{
			double tK;
			tK = tC + 273;
			return tK;
		}
		double get_tRe()
		{
			double tRe;
			tRe = tC * 0.8;
			return tRe;
		}
		double get_tR()
		{
			double tR;
			tR = tC * 493.47;
			return tR;
		}	
		void see_T()
		{
			cout << "Temperature in Celsius " << get_tC() << endl;
			cout << "Temperature in Fahrenheit " << get_tF() << endl;
			cout << "Temperature in Kelvin " << get_tK() << endl;
			cout << "Temperature in Remyure " << get_tRe() << endl;
			cout << "Temperature in Rankin " << get_tR() << endl;
		}
	};
	int main()
	{
		double t;
		TTemperature temp;
		TTemperature temp1(15);
		cout << "Enter temperature in Celsius\n";
		cin >> t;
		temp.set_T(t);
		temp.see_T();
		temp = 5;
		cout << endl;
		temp.see_T();
		temp = temp1;
		cout << endl;
		temp.see_T();
		system("pause");
		return 0;
	}