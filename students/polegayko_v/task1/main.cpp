#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class DlinConventer
{
	double metr;

public:
	DlinConventer(double metry = 1)
	{
		metr = metry;
	}
	DlinConventer& operator=(double m)
	{
		metr = m;
		return *this;
	}
	DlinConventer& operator=(const DlinConventer& m)
	{
		metr = m.metr;
		return *this;
	}
	double VozvrMetr()
	{
		return metr;
	}
	double PreobFut()
	{
		return metr * 3.28;
	}
	double PreobYard()
	{
		return metr * 1.09;
	}
	double PreobSaj()
	{
		return metr * 0.54;
	}
	double PreobPyad()
	{
		return metr * 4.37;
	}
	double PreobDuym()
	{
		return metr * 39.37;
	}
	double PreobMil()
	{
		return metr * 0.00062;
	}
	void SetMetr(int met)
	{
		metr = met;
	}
	void DlinaMetry()
	{
		cout << "Dlina v metrah =" << VozvrMetr() << "\n";
	}
	void Fut()
	{
		cout << "Dlina v futah =" << PreobFut() << "\n";
	}
	void Yard()
	{
		cout << "Dlina v yardah =" << PreobYard() << "\n";
	}
	void Sajen()
	{
		cout << "Dlina v sajeni =" << PreobSaj() << "\n";
	}
	void Pyad()
	{
		cout << "Dlina v pyadi =" << PreobPyad() << "\n";
	}
	void Duym()
	{
		cout << "Dlina v duymah =" << PreobDuym() << "\n";
	}
	void Milya()
	{
		cout << "Dlina v milyah =" << PreobMil() << "\n";
	}
	void VseMery()
	{
		cout << "Dlina v futah =" << PreobFut() << "\n";
		cout << "Dlina v yardah =" << PreobYard() << "\n";
		cout << "Dlina v sajeni =" << PreobSaj() << "\n";
		cout << "Dlina v pyadi =" << PreobPyad() << "\n";
		cout << "Dlina v duymah =" << PreobDuym() << "\n";
		cout << "Dlina v milyah =" << PreobMil() << "\n";

	}

};
void main()
{
	double _m = 0;
	int a = 1;
	int b = 1;
	int c = 1;
	DlinConventer K;
	while (c == 1)
	{
		cout << "Vyberete razdel:" << "\n" << "1 - Nazhachit' dlinu v metrah" << "\n" << "2 - Poluchit dlinu v razlichnyh edinicah " << "\n" << "3 - Vyhod" << "\n";
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "Dlina v metrah -";
			cin >> _m;
			K.SetMetr(_m);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Vyberete edinicy izmereniya" << "\n" << "1 - Futy\n" << "2 - Yard\n" << "3 - Sajen\n" << "4 - Pyad\n" << "5 - Duymy\n" << "6 - Mili\n" << "7 - Vernut' dlinu v metrah\n";
			cin >> b;
			switch (b)
			{
			case 1:
			{
				K.Fut();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				K.Yard();
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				K.Sajen();
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				K.Pyad();
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				K.Duym();
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				K.Milya();
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				K.DlinaMetry();
				system("pause");
				system("cls");
				break;
			}
			}
		case 3:
		{
			c = 0;
		}
		}
	}
	system("pause");


}