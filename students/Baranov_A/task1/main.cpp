#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Vlogenie(int &hor, int &min, int &sec)//ввод данных
{
	cout << "Введите ЧЧ : ММ: СС " << endl;
	cin >> hor;cin >> min;cin >> sec;
}


class Time
{
private:
	int hor, min, sec;

public:
	//конструктор
	Time(int _hor = 0, int _min = 0, int _sec = 0) :hor(_hor), min(_min), sec(_sec) {}
	void setTime(int _hor, int _min, int _sec)
	{
		hor = _hor;
		min = _min;
		sec = _sec;
	}
	//Вывод на экран
	void ShowTime()
	{
		cout << hor << " : " << min << " : " << sec << endl;
	}
	//Оператор присваивания
	Time operator = (const Time& obj)
	{
		hor = obj.hor;
		min = obj.min;
		sec = obj.sec;
		return *this;
	}
	//Сдвиг времени 
	void Change(int _hor, int _min, int _sec, int change)
	{
		if (change == 1)
		{
			hor += _hor;
			min += _min;
			sec += _sec;
		}
		if (change == 2)
		{
			hor -= _hor;
			min -= _min;
			sec -= _sec;
		}
		if (sec > 59)
		{
			min = min + sec / 60;
			sec = sec % 60;
		}
		if (sec < 0)
		{
			min = min - (1 + abs(_sec / 60));
			sec = 60 - sec % 60;
		}
		if (min > 59)
		{
			hor = hor + min / 60;
			min = min % 60;
		}
		if (min < 0)
		{
			hor = hor - (1 + abs(min / 60));
			min = 60 - min % 60;
		}
		if (hor > 23)
			hor = hor % 24;
		if (hor == -24)
			hor = 0;
		if (hor < 0)
			hor = 24 + hor % 24;
	}
	//Разница
	void Raznica(int hor2, int min2, int sec2)
	{
		int Secfirst;
		int Secsecond;
		int Razn;
		Secfirst = hor * 3600 + min * 60 + sec;
		Secsecond = hor2 * 3600 + min2 * 60 + sec2;
		Razn = abs(Secfirst - Secsecond);
		hor = Razn / 3600;
		Razn = Razn - hor * 3600;
		min = Razn / 60;
		sec = Razn % 60;
	}
};
int main()
{
	int choice, change;
	int hor = 0;
	int min = 0;
	int sec = 0;
	Time T;
	system("chcp 1251>nul");
	cout << "Желаете задать время?" << endl;
in:		cout << "1-Да,2-Нет" << endl;
	cin >> choice;
	if (choice == 1)
	{
		Vlogenie(hor, min, sec);
		T.setTime(hor, min, sec);
		T.ShowTime();
		system("pause");
	}
	if (choice != 1)
		goto in;
	choice = 0;
	cout << "Какие операции хотите сделать" << endl;
	cout << "1-сдвинуть время,2-вычислить разницу,3-выход" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "В большую сторону-1,в меньшую сторону-2" << endl;
		cin >> change;
		Vlogenie(hor, min, sec);
		T.Change(hor, min, sec, change);
		T.ShowTime();
		system("pause");
	}
	if (choice == 2)
	{
		Vlogenie(hor, min, sec);
		T.Raznica(hor, min, sec);
		T.ShowTime();
		system("pause");
	}
	if (choice == 3)
		return 0;
}
