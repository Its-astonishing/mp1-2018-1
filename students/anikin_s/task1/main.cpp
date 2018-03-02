#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <locale.h>

using namespace std;

class TFraction
{
private:
	int num;
	int denom;
	int nod(int x, int y);
	void total()
	{
		int q;
		if (nod(abs(num), abs(denom)) > 1)
		{
			q = nod(abs(num), abs(denom));
			num /= q;
			denom /= q;
		}
	}
	bool exist;
	TFraction add(const TFraction& s);
	TFraction subt(const TFraction& s);
	TFraction mult(const TFraction& s);
	TFraction dev(const TFraction& s);
public:
	TFraction(int x, int y);
	bool IsExist();
	void Print();
	TFraction operator=(const TFraction& s)
	{
		num = s.num;
		denom = s.denom;
		return *this;
	}
	TFraction operator+=(const TFraction& s)
	{
		add(s);
		return *this;
	}
	TFraction operator-=(const TFraction& s)
	{
		subt(s);
		return *this;
	}
	TFraction operator*=(const TFraction& s)
	{
		mult(s);
		return *this;
	}
	TFraction operator/= (const TFraction& s)
	{
		dev(s);
		return *this;
	}

	TFraction operator+(const TFraction& s)
	{
		TFraction a1(num *s.denom + s.num *denom, denom *s.denom);
		return a1;
	}
	TFraction operator-(const TFraction& s)
	{
		TFraction a1(num *s.denom - s.num * denom, denom *s.denom);
		return a1;
	}
	TFraction operator*(const TFraction& s)
	{
		TFraction a1(num *s.num, denom *s.denom);
		return a1;
	}
	TFraction operator/(const TFraction& s)
	{
		TFraction a1(num *s.denom, denom *s.num);
		return a1;
	}
};
TFraction::TFraction(int x, int y)
{
	num = x;
	if (y != 0)
	{
		exist = true;
		denom = y;
		total();
	}
	else
		exist = false;
}
TFraction TFraction::add(const TFraction& s)
{
	num = num * s.denom + s.num *denom;
	denom *= s.denom;
	total();
	TFraction a1(num, denom);
	return a1;
}
TFraction TFraction::subt(const TFraction& s)
{
	num = num * s.denom - s.num *denom;
	denom *= s.denom;
	total();
	TFraction a1(num, denom);
	return a1;
}
TFraction TFraction::mult(const TFraction& s)
{
	num *= s.num;
	denom *= s.denom;
	total();
	TFraction a1(num, denom);
	return a1;
}
TFraction TFraction::dev(const TFraction& s)
{
	num *= s.denom;
	denom *= s.num;
	total();
	TFraction a1(num, denom);
	return a1;
}
int TFraction::nod(int x, int y)
{
	int n = 1;
	for (int i = x; i > 0; i--)
	{
		if ((x % i == 0) && (y % i == 0))
		{
			n = i;
			break;
		}
	}
	return n;
}
bool TFraction::IsExist()
{
	return exist;
}
void TFraction::Print()
{
	cout << "" << num << "/" << denom << endl;
}
void main()
{
	setlocale(LC_ALL, "rus");
	int p, l, m, j;
	cout << "¬ведите числитель и знаменатель первой дроби" << endl;
	cin >> p;
	cin >> l;
	cout << "¬ведите числитель и знаменатель первой дроби" << endl;
	cin >> m;
	cin >> j;
	TFraction a(p,l);
	TFraction s(m,j);
	if (a.IsExist() && s.IsExist())
	{
		(a+s).Print();
		cout << "\n";
		(a-s).Print();
		cout << "\n";
		(a*s).Print();
		cout << "\n";
		(a / s).Print();
		cout << "\n";
	}
	system("pause");
}