#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

void inp(int *_h, int  *_m, int *_s);

class TTime
{
    int hour;
    int min;
    int sec;
public:
    TTime(int _hour = 0, int _min = 0, int _sec = 0); //constructor
    TTime& operator=(const TTime& time1)  //assignment
    {
        hour = time1.hour;
        min = time1.min;
        sec = time1.sec;
        return *this;
    }
    void SetTime(int _hour, int _min, int _sec);
    void ChangeTime(int _hour, int _min, int _sec, int side);
    void SetSysTime();
    void ShowTime();
    void Difference(int * _hour, int * _min, int * _sec);
};

void main() {
    TTime t1;
    bool cont = true;
    int choice;
    int input;
    int _h = 0;
    int _m = 0;
    int _s = 0;
    int side = 1;
    while (cont)
    {
    input:
        system("cls");
        cout << "1. Set system time\n"
            << "2. Input your own time\n"
            << "3. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t1.SetSysTime();
            break;
        case 2:
            inp(&_h, &_m, &_s);
            t1.SetTime(_h, _m, _s);
            break;
        case 3:
            cont = 0;
            break;
        }
        while (cont)
        {
            system("cls");
            cout << "Current TTime: \n"; t1.ShowTime();
            cout << "\n1. Input new value and then calculate the Difference\n"
                << "2. Change TTime\n"
                << "3. Move TTime\n"
                << "4. Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                inp(&_h, &_m, &_s);
                t1.Difference(&_h, &_m, &_s);
                cout << "\nThe difference between set and input time is "
                    << _h << " hours "
                    << _m << " minutes "
                    << _s << " seconds";
                _getch();
                break;
            case 2:
                goto input;
            case 3:
                inp(&_h, &_m, &_s);
                cout << "\n5.Forward? \n6.Backward?\n";
                cin >> choice;
                switch (choice) {
                case 5:
                    side = 1;
                    break;
                case 6:
                    side = -1;
                    break;
                }
                t1.ChangeTime(_h, _m, _s, side);
                break;
            case 4:
                cont = 0;
                break;
            }
        }
    }
}

TTime::TTime(int _hour, int _min, int _sec)
{
    hour = _hour;
    min = _min;
    sec = _sec;
}

void TTime::SetTime(int _hour, int _min, int _sec)
{
    sec = _sec;
    min = _min;
    hour = _hour;
}

void TTime::ChangeTime(int _hour, int _min, int _sec, int side)
{ //side: 1 == forward, -1 == backward
    if (side == 1)
    {
        hour += _hour;
        min += _min;
        sec += _sec;
    }
    else
    {
        hour -= _hour;
        min -= _min;
        sec -= _sec;
    }
    //correct seconds
    if (sec > 59)
    {
        min += sec / 60;
        sec = sec % 60;
    }
    if (sec < 0)		// 12.06.15 - 0.0.20 = 12.06.(-5).. 
    {
        min -= 1 + abs(sec / 60);
        sec = 60 - sec % 60;
    }
    //correct minutes
    if (min > 59)
    {
        hour += min / 60;
        min = min % 60;
    }
    if (min < 0)
    {
        hour -= 1 + abs(min / 60);
        min = 60 - min % 60;
    }
    //correct hours
    if (hour > 23)
        hour = hour % 24;
    if (hour == -24)
        hour = 0;
    if (hour < 0) // 01.00.00 - 3.00.00 = -2.00.00
        hour = 24 + hour % 24;
}

void TTime::SetSysTime() //get system time
{
    time_t current_time;
    struct tm  local_time;

    time(&current_time);
    localtime_s(&local_time, &current_time);
    hour = local_time.tm_hour;
    min = local_time.tm_min;
    sec = local_time.tm_sec;
}

void TTime::ShowTime() //show current time
{
    cout << "It's " << hour << " hours " << min << " minutes and " << sec << " seconds";
}

void TTime::Difference(int *_hour, int *_min, int *_sec) //calculate Difference
{
    int TotalSec1 = hour * 3600 + min * 60 + sec;
    int TotalSec2 = *_hour * 3600 + *_min * 60 + *_sec;
    int Diff = abs(TotalSec1 - TotalSec2);
    *_hour = Diff / 3600;
    Diff = Diff - *_hour * 3600;
    *_min = Diff / 60;
    *_sec = Diff % 60;
}

void inp(int *_h, int  *_m, int *_s)
{
    cout << "Input hour between 0 and 23\n";
    cin >> *_h;
    cout << "\nInput minute between 0 and 59\n";
    cin >> *_m;
    cout << "\nInput second between 0 and 59\n";
    cin >> *_s;

}