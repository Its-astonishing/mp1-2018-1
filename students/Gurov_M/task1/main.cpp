#include <iostream>
#include <conio.h>
using namespace std;
class Converter
{
private:
	int a;
	double c;
	double b;
	double m;
public:
	void GetA();
	void check(int *_a)
	{
		cout << *_a;
	}

};
void Converter::GetA()
{
	cin >> a;
}






int main()
{
	Converter �1;

	�1.check(&a);
	system("pause");
}