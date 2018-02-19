#include <iostream>
#define CONST_PHARMACY_POUND 2,2679
#define CONST_TROY_OUNCE 35,2739
#define CONST_POOD 0,061

using namespace std;

int main()
{
	class TWeighing_scales
	{
	private:
		double kg; // ��� � ������������
	public:
		TWeighing_scales(double _kg)// �����������
		{
			kg = _kg;
		}
		TWeighing_scales & operator=(TWeighing_scales & kg1) //�������� ������������
		{
			kg = kg1.kg;
			return *this;
		}
		void withdraw() //����� ���� �� �����
		{
			cout << "weight: " << kg << endl;
		}
		void pharmacy_pound() //�������������� � �������� ����
		{
			kg = kg * CONST_PHARMACY_POUND;
		}
		void troy_ounce() // �������������� � �������� �����
		{
			kg = kg * CONST_TROY_OUNCE;
		}
		void pood() // �������������� � ���
		{
			kg = kg * CONST_POOD;
		}
		void transfer_kg(int flag) // ��������� � ��: ������������ ������ �������, � ����� ������� ��������� ���������� ������ ���������:1-���.���� 2-����� 3-��� 
		{

			switch (flag)
			{
			case 1:
				kg = kg / CONST_PHARMACY_POUND;
				break;
			case 2:
				kg = kg / CONST_TROY_OUNCE;
				break;
			case 3:
				kg = kg / CONST_POOD;
				break;
			}

		}
		void discover_kg(int flag) // ������ ��� � ��. ���������� ���� �������� ����������
		{

			switch (flag)
			{
			case 1: cout << "weight in kilograms: " << (kg / CONST_PHARMACY_POUND) << endl;
				break;
			case 2: cout << "weight in kilograms: " << (kg / CONST_TROY_OUNCE) << endl;
				break;
			case 3: cout << "weight in kilograms: " << (kg / CONST_POOD) << endl;
				break;
			}
		}
		void selected_unit(int flag) // ������� ������ ��� � ��������� ������� ���������. �� ��������� ��������� � ��.  1-���.���� 2-����� 3-���
		{
			switch (flag)
			{
			case 1: cout << "weight in pharmacy pound: " << (kg * CONST_PHARMACY_POUND) << endl;
				break;
			case 2: cout << "weight in troy ounce: " << (kg * CONST_TROY_OUNCE) << endl;
				break;
			case 3: cout << "weight in pood: " << (kg * CONST_POOD) << endl;
				break;
			}
		}
	};
}
