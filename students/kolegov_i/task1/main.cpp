#include <iostream>

using namespace std;

class LengthConverter
{
private:
	double meters;
public:
	LengthConverter(int m); 

	LengthConverter& operator=(const LengthConverter& lc)
	{
		meters = lc.meters;
		return *this;
	}

	LengthConverter& operator=(const double& a)
	{
		if (a >= 0)
			meters = a;
		else
			meters = -1;
		return *this;
	}

	//Мне показалась такая реализация наиболее интересной
	//Возможно как-то можно использовать enum
	const int FOOT = 1;
	const int YARD = 2;
	const int ARSHIN = 3;
	const int SAZHEN = 4;
	double ConvertTo(int MeraType);

	double GetLength();
	void SetLength(double m);
	
	void ToConsole(int MeraType);
	void ToConsole();
};


LengthConverter::LengthConverter(int m)
{
	if (m >= 0)
		meters = m;
	else
		meters = -1;
}

double LengthConverter::GetLength()
{
	return meters;
}

void LengthConverter::SetLength(double m)
{
	if (m >= 0)
		meters = m;
	else
		meters = -1;
}

double LengthConverter::ConvertTo(int param)
{
	switch (param)
	{
	default: return -1;
		case 1: return meters * 3.28084;
		case 2: return meters * 1.09361;
		case 3: return meters * 1.4060742407;
		case 4: return meters * 0.546807;
	}

}

void LengthConverter::ToConsole()
{
	cout << "\tMeters: " << ConvertTo(FOOT);
	cout << "\n\tYard: " << ConvertTo(YARD);
	cout << "\n\tArshin: " << ConvertTo(ARSHIN);
	cout << "\n\tSazhen: " << ConvertTo(SAZHEN);
}

//Добавил новый вывод в консоль
void LengthConverter::ToConsole(int param)
{
	cout << ConvertTo(param);
}

int main()
{
	LengthConverter a(5);
	a = 15;
	LengthConverter b(-8);
	b = a;

	double i[5];
	i[0] = b.ConvertTo(b.ARSHIN);
	i[1] = b.ConvertTo(b.YARD);
	i[2] = b.ConvertTo(b.SAZHEN);
	i[3] = b.ConvertTo(b.FOOT);
	i[4] = b.GetLength();

	cout << "Object b:\n{\n";
	for (int j = 0; j < 5; j++)
	{
		cout <<"\t"<< i[j] << "\n";
	}

	cout << "}\nObject a:\n{\n";
	a.ToConsole();

	cout << "\n";

	a.ToConsole(a.ARSHIN);

	cout << "\n}\n";
	system("pause");

	return 0;
}
