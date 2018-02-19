#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

void inp(int *_h, int  *_m, int *_s); //воспомогательная функция, ввод

class TTime
{
	int hour;
	int minut;
	int sec;
public:
	TTime(int _hour = 0, int _min = 0, int _sec = 0);
	void set_time(int *_hour, int *_min, int *_sec);
	void change_time(int *_hour, int *_min, int *_sec, bool *side);
	void correct();
	void set_sys_time();
	void show();
	void difference(int *_hour, int *_min, int *_sec);
};

void main() {
	TTime t1;
	bool cont = true;
	int choise;
	int input;
	int _h = 0;
	int _m = 0;
	int _s = 0;
	bool side = false;
	while (cont)
	{
	input:
		system("cls");
		cout << "1. Set system time\n"
			<< "2. Input your own time\n"
			<< "3. Exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
			t1.set_sys_time();
			break;
		case 2:
			inp(&_h, &_m, &_s);
			t1.set_time(&_h, &_m, &_s);
			break;
		case 3:
			cont = 0;
			break;
		}
		while (cont)
		{
			system("cls");
			cout << "Current TTime: \n"; t1.show();
			cout << "\n1. Input new value and then calculate the difference\n"
				<< "2. Change TTime\n"
				<< "3. Move TTime\n"
				<< "4. Exit\n";
			cin >> choise;
			switch (choise)
			{
			case 1:
				inp(&_h, &_m, &_s);
				t1.difference(&_h, &_m, &_s);
				break;
			case 2: 
				goto input;
			case 3:
				inp(&_h, &_m, &_s);
				cout << "\n5.Forward? \n6.Backward?\n";
				cin >> choise;
				switch (choise) {
				case 5:
					side = true;
					break;
				case 6:
					side = false;
					break;
				}
				t1.change_time(&_h, &_m, &_s, &side);
				break;
			case 4:
				cont = 0;
				break;
			}
		}
	}
}

TTime::TTime(int _hour, int _min, int _sec)
	: hour(_hour), minut(_min), sec(_sec)
{
	correct();
}

void TTime::set_time(int *_hour, int *_min, int *_sec)
{
	sec = *_sec;
	minut = *_min;
	hour = *_hour;
	correct();
}

void TTime::change_time(int *_hour, int *_min, int *_sec, bool *side)
{ //side: true == forward, false == backward
	if (*side)
	{
		hour += *_hour;
		minut += *_min;
		sec += *_sec;
	}
	else
	{
		hour -= *_hour;
		minut -= *_min;
		sec -= *_sec;
	}
	correct();
}

void TTime::correct() //optimize
{
	//seconds
	if (sec > 59)
	{
		minut += sec / 60;
		sec = sec % 60;
	}
	if (sec < 0)		// 12.06.15 - 0.0.20 = 12.06.(-5).. 
	{
		minut -= 1 + abs(sec / 60);
		sec = 60 - sec % 60;
	}
	//minutes
	if (minut > 59)
	{
		hour += minut / 60;
		minut = minut % 60;
	}
	if (minut < 0)
	{
		hour -= 1 + abs(minut / 60);
		minut = 60 - minut % 60;
	}
	//hours
	if (hour > 23)
		hour = hour % 24;
	if (hour == -24)
		hour = 0;
	if (hour < 0) // 01.00.00 - 3.00.00 = -2.00.00
		hour = 24 + hour % 24;
}

void TTime::set_sys_time() //get system time
{
	time_t current_time;
	struct tm  local_time;

	time(&current_time);
	localtime_s(&local_time, &current_time);
	hour = local_time.tm_hour;
	minut = local_time.tm_min;
	sec = local_time.tm_sec;
}

void TTime::show() //show current time
{
	cout << "It's " << hour << " hours " << minut << " minutes and " << sec << " seconds";
}

void TTime::difference(int *_hour, int *_min, int *_sec) //calculate difference
{
	cout << "Difference between input and set time is " << abs(hour - *_hour) << " hours "
		<< abs(minut - *_min) << " minutes " << abs(sec - *_sec) << "seconds";
	_getch();
}

void inp(int *_h, int  *_m, int *_s) 
{
	cout << "Input hour ";
	cin >> *_h;
	cout << "\nInput minute ";
	cin >> *_m;
	cout << "\nInput sec ";
	cin >> *_s;

}