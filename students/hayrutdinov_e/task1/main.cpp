#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class ConverterLength
{
	double metre;

public:
	ConverterLength(double met = 1) : metre(met) {} //Constructor//

	ConverterLength& operator=(double m)
	{
		metre = m;
		return *this;
	}
	ConverterLength& operator=(const ConverterLength& length)
	{
		metre = length.metre;
		return *this;
	}
	double GetMetre()
	{
		return metre;
	}
	double GetArshin()
	{
		return metre*1.41;
	}
	double GetFoot()
	{
		return metre*3.28;
	}
	double GetYard()
	{
		return metre*1.0936;
	}
	double GetSazhen()
	{
		return metre*0.47;
	}
	double GetPyad()
	{
		return metre*5.62;
	}
	double GetInch()
	{
		return metre*39.37;
	}
	double GetMile()
	{
		return metre*0.00062;
	}

	void SetMetre(int met)
	{
		metre = met;
	}
	void Metre()
	{
		cout << "Length in metres =" << GetMetre() << "\n";
	}
	void Arshin()
	{
		cout << "Length in arshin`s =" << GetArshin() << "\n";
	}
	void Foot()
	{
		cout << "Length in foot =" << GetFoot() << "\n";
	}
	void Yard()
	{
		cout << "Length in yard =" << GetYard() << "\n";
	}
	void Sazhen()
	{
		cout << "Length in sazhen`s =" << GetSazhen() << "\n";
	}
	void Pyad()
	{
		cout << "Length in pyad =" << GetPyad() << "\n";
	}
	void Inch()
	{
		cout << "Length in Inch =" << GetInch() << "\n";
	}
	void Mile()
	{
		cout << "Length in mile =" << GetMile() << "\n";
	}
	void SeeAllLength()
	{
		cout << "Length in metres =" << GetMetre() << "\n";
		cout << "Length in arshin`s =" << GetArshin() << "\n";
		cout << "Length in foot =" << GetFoot() << "\n";
		cout << "Length in yard =" << GetYard() << "\n";
		cout << "Length in sazhen`s =" << GetSazhen() << "\n";
		cout << "Length in pyad =" << GetPyad() << "\n";
		cout << "Length in inch =" << GetInch() << "\n";
		cout << "Length in mile =" << GetMile() << "\n";
	}
};

void main()
{
	double _m = 0;
	int a, b, c = 1, f = 1;
	ConverterLength K;
menu: while (c == 1)
{
	cout << "Select section:" << "\n" << "1 - Set lenght in meters" << "\n" << "2 - Get lenght in metres" << "\n" << "3 - Get length in other values" << "\n" << "4 - Exit" << "\n";
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "Length in metres =";
		cin >> _m;
		K.SetMetre(_m);
		system("pause");
		system("cls");
		break;
	}
	case 2:
	{
		K.Metre();
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		while (f == 1)
		{
			cout << "Select value:" << "\n" << "1 - Arshin\n" << "2 - Foot\n" << "3 - Yard\n" << "4 - Sazhen\n" << "5 - Pyad\n" << "6 - Inch\n" << "7 - Mile\n" << "8 - All Values\n" << "9 - Back to menu\n";;
			cin >> b;
			switch (b)
			{
			case 1:
			{
				K.Arshin();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				K.Foot();
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				K.Yard();
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				K.Sazhen();
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				K.Pyad();
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				K.Inch();
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				K.Mile();
				system("pause");
				system("cls");
				break;
			}
			case 8:
			{
				K.SeeAllLength();
				system("pause");
				system("cls");
				break;
			}
			case 9:
			{
				system("cls");
				goto menu;
			}
			}
		}
	}
	case 4:
	{
		c = 0;
	}
	}
}
	  system("pause");

}
