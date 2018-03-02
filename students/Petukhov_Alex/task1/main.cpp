#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

void Input(int &, int &, int &);
class TTime {

private : 
	int hour, min, sec;
public :
	TTime(int _hour = 0, int _min = 0, int _sec = 0);
	string showTime();
	void setTime(int _hour, int _min, int _sec);
	void timeDiff(int &_hour, int &_min, int &_sec);
	void getTime(int &, int &, int &);
	void changeTime(int _hour, int _min, int _sec, int d);

	TTime& operator=(const TTime& obj) {
		hour = obj.hour;
		min = obj.min;
		sec = obj.sec;
		return *this;
	}
};
int main(){
	int cur = 1, mode1, mode2, mode3, d = 0;
	int _h = 0, _m = 0, _s = 0;
	int hd = 0, md = 0, sd = 0;
	TTime T1;
	system("cls");
	while (cur) {
		
		cout << "1. Set time" << endl;
		cout << "2. Exit" << endl;
		cout << "Your choice: ";
		cin >> mode1;

		switch (mode1) {
		case 1: {
		settime:
			Input(_h, _m, _s);
			T1.setTime(_h, _m, _s);
			system("pause");
			system("cls");
			break;

		}
		case 2: {
			cur = 0;
			break;
		}
		}

		while (cur) {
			system("cls");
			cout << "Current Time: ";
			cout << T1.showTime() << endl;
			cout << "1. Move time" << endl;
			cout << "2. Enter time and calculate difference" << endl;
			cout << "3. Exit" << endl;
			cout << "4. Set new time" << endl;
			cout << "Your choice: ";
			cin >> mode2;

			switch (mode2) {
			case 1: {
				cout << "Enter time you want to change it" << endl << endl;
				Input(_h, _m, _s);
				cout << "Select direction" << endl;
				cout << "1. Forward" << endl;
				cout << "2. Backward" << endl;
				cout << "Your choice: ";
				cin >> mode3;
				switch (mode3) {
				case 1: {
					d = 1;
					break;
				}
				case 2: {
					d = 0;
					break;
				}
				
				}
				T1.changeTime(_h, _m, _s, d);
				break;


			}
			case 2: {
				Input(hd, md, sd);
				T1.timeDiff(hd, md, sd);
				cout << "Difference between entered time and set time is ";
				cout << hd << ":" << md << ":" << sd << endl;
				system("pause");
				break;

			}
			case 3: {
				cur = 0;
				break;
			}
			case 4: {
				goto settime;

			}
			}


		}
		
	}
	system("pause");
}
void Input(int &_hour, int &_min, int &_sec) {
	cout << "Enter hour minutes and seconds separately" << endl;
	do {
		cout << "hours from 0 to 23: ";

		cin >> _hour;
	} while (_hour < 0 || _hour > 23);

	do {
		cout << "minutes from 0 to 59: ";
		cin >> _min;
	} while (_min < 0 || _min > 59);
	do {
		cout << "seconds from 0 to 59: ";
		cin >> _sec;
	} while (_sec < 0 || _sec > 59);
	
}
string TTime::showTime() {
	return to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
}
void TTime::timeDiff(int &_hour, int &_min, int &_sec)
{
	int sec1 = hour * 3600 + min * 60 + sec; // set time in seconds
	int sec2 = _hour * 3600 + _min * 60 + _sec; // entered time in seconds
	int diff = abs(sec1 - sec2); 
	_sec = diff % 60;
	_min = (diff - _sec) / 60;
	diff = _min;
	_min %= 60;
	_hour = (diff - _min) / 60;

	/*if (_sec >= 60) {
		_min += _sec / 60;
		_sec %= 60;
	}
	if (_min >= 60) {
		_hour += _min / 60;
		_min %= 60;
	}
	if (_hour >= 24)_hour %= 24;
	_hour = abs(hour - _hour);
	_min = abs(min - _min);
	_sec = abs(sec - _sec);*/
	
}
TTime::TTime(int _hour, int _min, int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}
void TTime::changeTime(int _hour, int _min, int _sec, int d) {
	if (d) {
		hour += _hour;
		min += _min;
		sec += _sec;
	}
	else {
		hour -= _hour;
		min -= _min;
		sec -= _sec;
	}

	if (sec >= 60) {
		min += sec / 60;
		sec %= 60;
	}
	if (min >= 60) {
		hour += min / 60;
		min %= 60;
	}

	if (sec < 0) {
		min--;
		sec += 60;
	}
	if (min < 0) {
		hour--;
		min += 60;
	}

	hour += 24;
	hour %= 24;
}
void TTime::setTime(int _hour, int _min, int _sec) {
	hour = _hour;
	min = _min;
	sec = _sec;
}
void TTime::getTime(int &h, int &m, int &s) {
	h = hour;
	m = min;
	s = sec;
}