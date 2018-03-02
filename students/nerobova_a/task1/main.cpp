#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Rational
{
	int ch;
	int zn;
	int nod;
	int Chislit(int ch, int nod);
	int Znamenat(int zn, int nod);
public:
	int NOD(int ch, int zn);
	int NOK(int zn, int zn1);
	void PrintRational();
	Rational() : ch(1), zn(1) {}
	Rational(int _ch) : ch(_ch), zn(1) {}
	Rational(int _ch, int _zn) : ch(_ch), zn(_zn)
	{
		nod = NOD(ch, zn);
		ch = Chislit(ch, nod);
		zn = Znamenat(zn, nod);
	}
	Rational operator+(const Rational& r)
	{
		Rational sum(*this);
		if (zn == r.zn)
		{
			sum.ch = ch + r.ch;
			sum.zn = zn;
			return sum;
		}
		else {
			sum.zn = NOK(zn, r.zn);
			sum.ch = (sum.zn / zn*ch) + (sum.zn / r.zn*r.ch);
			return sum;
		}
	}

	Rational operator-(const Rational& r)
	{
		Rational sub(*this);
		if (zn == r.zn)
		{
			sub.ch = ch - r.ch;
			sub.zn = zn;
			return sub;
		}
		else {
			sub.zn = NOK(zn, r.zn);
			sub.ch = (sub.zn / zn*ch) - (sub.zn / r.zn*r.ch);
			return sub;
		}
	}


	Rational operator*(const Rational& r)
	{
		Rational multi(*this);
		int zn1, ch1;
		zn1 = zn * r.zn;
		ch1 = ch * r.ch;
		nod = NOD(ch1, zn1);
		multi.ch = Chislit(ch1, nod);
		multi.zn = Znamenat(zn1, nod);
		return multi;
	}

	Rational operator/(const Rational& r)
	{
		Rational div(*this);
		int zn1, ch1;
		ch1 = ch*r.zn;
		zn1 = zn*r.ch;
		nod = NOD(ch1, zn1);
		div.ch = Chislit(ch1, nod);
		div.zn = Znamenat(zn1, nod);
		return div;
	}

	Rational& operator=(const Rational& r)
	{
		ch = r.ch;
		zn = r.zn;
		return *this;
	}
};


void  Rational::PrintRational()
{
	cout << ch << "/" << zn << "\n";
}

int Rational::Chislit(int ch, int nod)
{
	ch = ch / nod;
	return ch;
}

int Rational::Znamenat(int zn, int nod)
{
	zn = zn / nod;
	return zn;
}


int Rational::NOD(int ch, int zn)
{
	int a, b, tmp;
	if (ch > zn)
	{
		a = ch;
		b = zn;
	}
	else
	{
		a = zn;
		b = ch;
	}

	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
	if (a != 1)
	{
		zn = zn / a;
		ch = ch / a;
	}
}

int Rational::NOK(int zn, int zn1)
{
	return zn*zn1 / NOD(zn, zn1);
}


int main()
{
	Rational r, r1(0), r1_1(0), r1_2(0), r1_3(0), r2(3, 7), r3(8, 9);
	r.PrintRational();
	r1.PrintRational();
	r2.PrintRational();
	r3.PrintRational();


	r1 = r2 + r3;
	cout << "sum = ";
	r1.PrintRational();
	r1_1 = r3 - r2;
	cout << "sub =";
	r1_1.PrintRational();
	r1_2 = r2*r3;
	cout << "multi = ";
	r1_2.PrintRational();
	r1_3 = r2 / r3;
	cout << "div = ";
	r1_3.PrintRational();

	return 0;
}