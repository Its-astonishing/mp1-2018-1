#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class LongNumber
{
public:
	LongNumber() {}
	LongNumber(char *str)//����������� ������� ���� ��������� ������ � ���������� ����� ������� ��� �������� 
	{
		if (strlen(str) <= 20)
		{
			for (int i = 0, j = strlen(str) - 1; i < 20 && str[j] != '\0'; i++, j--)
			{
				arr[i] = str[j];
				//cout << arr[i];
			}
		}
	}
	LongNumber operator+(const LongNumber &cons)// �������� ����������� ������� "� �������"
	{
		int r = 0;
		int temp1 = 0;
		LongNumber t1;
		for (int i = 0; i < 20; i++)
		{
			temp1 = atoi1(arr[i]) + (atoi1(cons.arr[i])) + temp1;//��������� �������� ����� ���� ��������
			r = temp1 % 10;//�������� ������� �� ����� ��� �������� �� 10
			if (r < 0)//����� ������� ����� ����������� 
			{
				r = 10 + r;
				temp1 = temp1 - 10;
			}
			t1.arr[i] = itoa1(r);
			temp1 = temp1 / 10;
		}return t1;
	}
	LongNumber operator-(const LongNumber &cons)//��� �� ����� ������ ��� � �� ���������
	{
		int r = 0;
		int temp1 = 0;
		LongNumber t1;
		for (int i = 0; i < 20; i++)
		{
			temp1 = atoi1(arr[i]) - (atoi1(cons.arr[i])) + temp1;
			r = temp1 % 10;
			if (r < 0)
			{
				r = 10 + r;
				temp1 = temp1 - 10;
			}
			t1.arr[i] = itoa1(r);
			temp1 = temp1 / 10;
		}return t1;
	}
	LongNumber operator*(const LongNumber &cons)
	{
		LongNumber t1;
		LongNumber t2;
		int	remnant1 = 0;//������� �������
		int	remnant2 = 0;//������� ������

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20 - i; j++) {
				if (cons.arr[i] == '0')//���������� ����
					continue;
				remnant2 = atoi1(arr[j]) * atoi1(cons.arr[i]);//�������� ��������� ��������� 
				t1.arr[j + i] = itoa1((remnant2 += remnant1) % 10);//��������������� ��������� � ������
				remnant1 = remnant2 / 10;
			}
			t2 = t2 + t1;//�������� �����
			t1 = "0";
		}
		return t2;
	}
	LongNumber operator/(LongNumber &cons)
	{
		if (cons == (LongNumber)"0")
			throw;
		int j = 20;
		bool begin = false;
		LongNumber answer;
		LongNumber dividend(*this);//�������
		LongNumber divider(cons);//��������
		LongNumber dividendPart;
		if (divider == (LongNumber)0)
		{
			throw "������� �� ���� �� �����������";
			return 0;
		}
		do {
			//���� ����� �������� ������ ��������
			while (dividendPart < divider &&j--> 0)
			{
				dividendPart.rank();//�������� ������ ����� �� ��������
				dividendPart.arr[0] = dividend.arr[j];
				if (dividend.arr[j] != '0')
					begin = true;
				if ((dividendPart < divider) && begin && dividend.arr[j] != '0')
					answer.rank();
			}
			while (dividendPart >= divider)
			{
				dividendPart = dividendPart - divider;
				answer = answer + "1";
			}
			//��������� ���� ����� ������� �����������
			if (j < 0)
				break;

			answer.rank();
		} while (j > 0);
		return answer;
	}
	LongNumber operator%(LongNumber &cons)
	{
		if (cons == (LongNumber)"0")
			throw;
		int j = 20;
		bool begin = false;
		LongNumber answer;
		LongNumber dividend(*this);//�������
		LongNumber divider(cons);//��������
		LongNumber dividendPart;
		do {

			while (dividendPart < divider &&j--> 0)
			{
				dividendPart.rank();//�������� ������ ����� �� ��������
				dividendPart.arr[0] = dividend.arr[j];//���� ������ ������ ����� �������� ��������� ������ ��������
				if (dividend.arr[j] != '0')//�������� ������ , ����� ���������� �� �����
					begin = true;
				if ((dividendPart < divider) && begin && dividend.arr[j] != '0')
					answer.rank();
			}
			while (dividendPart >= divider) {
				dividendPart = dividendPart - divider;
				answer = answer + "1";
			}
			if (j <= 0)
				break;
			answer.rank();
		} while (j > 0);
		answer = (*this) - answer * cons;//�������
		return answer;//���������� ���������
	}
	bool operator==(const LongNumber &cons)//��������� �����
	{
		for (int i = 20; i >= 0; i--)// ���� ������� �� ������ ����� ���������� false
		{
			if (atoi1(arr[i]) != atoi1(cons.arr[i]))
				return false;
		}
		return true;
	}
	LongNumber operator=(const LongNumber&cons)//������������
	{
		for (int i = 0; i <= 20; i++)
			arr[i] = cons.arr[i];
		return *this;
	}
	bool operator>(const LongNumber &cons) //�������� �� ������, ����� ��� �������
	{
		for (int i = 20; i >= 0; i--)
		{

			if (atoi1(arr[i]) > atoi1(cons.arr[i]))
				return true;
			if (atoi1(arr[i]) <atoi1(cons.arr[i]))
				return false;
		}
		return false;//���� ����� �����
	}
	bool operator>=(const LongNumber &cons)
	{
		for (int i = 20; i >= 0; i--) {

			if (atoi1(arr[i]) > atoi1(cons.arr[i]))
				return true;
			if (atoi1(arr[i]) <atoi1(cons.arr[i]))
				return false;
		}
	}
	bool operator<(const LongNumber &cons) //�������� �� ������, ����� ��� �������
	{
		for (int i = 20; i >= 0; i--)
		{
			if (atoi1(arr[i]) <atoi1(cons.arr[i]))
				return true;
			if (atoi1(arr[i]) > atoi1(cons.arr[i]))
				return false;
		}
		return false;
	}
	void print() //����� �������� ��������� ���� ����� �� ��������� 20 ��������
	{
		if (!limit) {
			bool impact = false;
			for (int i = 0; i < 20; i++)
			{
				if (arr[19 - i] != '0')//��� ����� 
					impact = true;
				if (impact)
					cout << arr[19 - i];

			}cout << endl;
		}
		else
			cout << "����� ������� �������" << endl;
	}
private:
	char arr[20];
	bool  limit = false;
	int atoi1(char elem1)//������� ������ ��� char �� int(atoi �� �������� ��� ��� �� �������� �� ��������)
	{
		switch (elem1)
		{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default:  return 0;
		}
	}
	char itoa1(int elem2) //������� ������ ��� int �� char
	{
		switch (elem2)
		{
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		default:return '0';
		}
	}
	LongNumber(int cons)
	{
		if (cons < 0)
			limit = true;

		for (int i = 0; i <20; i++)
		{
			arr[i] = itoa1(cons % 10);
			cons /= 10;
		}
	}

	LongNumber(long cons)
	{
		if (cons < 0)
			limit = true;

		for (int i = 0; i < 20; i++)
		{
			arr[i] = itoa1(cons % 10);
			cons /= 10;
		}
	}

	LongNumber(long long cons)
	{
		if (cons < 0)
			limit = true;

		for (int i = 0; i < 20; i++)
		{
			arr[i] = itoa1(cons % 10);
			cons /= 10;
		}
	}
	void rank()
	{
		bool minus = limit;
		for (int i = 20; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = '0';
		limit = minus;
	}
};
void main()
{
	LongNumber a("19673577792");
	LongNumber b("123456");
	LongNumber c = a*b;//true 
	LongNumber d = a + b;//true
	LongNumber k = a - b;//true
	LongNumber g = a / b;
	LongNumber l = a%b;
	/*LongNumber k1("25");
	LongNumber k2("5");
	LongNumber k3 = k1 / k2;
	k3.print();*/
	g.print();
	l.print();
}
