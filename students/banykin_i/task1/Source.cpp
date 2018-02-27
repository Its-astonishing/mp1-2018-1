#include <iostream>
#include <string>

using namespace std;

class LongNumber {
	char nullArray[20];
	bool longChecker;
private:
	//��������� ������ ������
	void ZeroArray() {
		for (char i = 0; i < 20; i++)
			nullArray[i] = '0';
	}
	//�������� ������ �����(������� � ������� � ��.)
	void UpRank() {
		for (int i = 20; i > 0; i--)
			nullArray[i] = nullArray[i - 1];
		nullArray[0] = '0';
	}
	//�-��� ��������������� ����� ���� char � ����� ���� int
	int ChangeChar(char number) {
		switch (number) {
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
	//���� ����� ������ ��������
	char ChangeCharBack(int number) {
		switch (number) {
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
public:
	LongNumber() {
		ZeroArray();
	}
	//������������� ��������� ������, ��������� ������� �������� � ������ �������
	LongNumber(char number[]) {
		int sLength = strlen(number);
		ZeroArray();

		if (sLength <= 20) {
			for (int i = 0, j = sLength - 1; i < 20 && number[j] != '\0'; i++, j--) {
				nullArray[i] = number[j];
			}
		}
	}
	//��������
	LongNumber operator+(const LongNumber &number) {
		LongNumber tmp;
		int temp = 0;
		int remainder;
		for (int i = 0; i < 20; i++) {
			temp = (ChangeChar(nullArray[i])) + (ChangeChar(number.nullArray[i])) + temp;//�������� � ���������� ��������� �������� ����� ���� �������� 
			remainder = temp % 10;//����������� ��������� ����� �� �����
			if (remainder < 0) {
				remainder += 10;
				temp -= 10;
			}
			tmp.nullArray[i] = ChangeCharBack(remainder);//�������� � "������ �������" 
			temp /= 10;//�������� ����� �����
		}
		return tmp;//���������� �����
	}
	//���������
	LongNumber operator-(const LongNumber &number) {
		if (*this < number)
			return "Negative";
		LongNumber tmp;
		int temp = 0;
		int remainder;
		for (int i = 0; i < 20; i++) {
			temp = (ChangeChar(nullArray[i])) - (ChangeChar(number.nullArray[i])) + temp;//�������� � ���������� ��������� ��������� ����� ���� �������� 
			remainder = temp % 10;//����������� ��������� ����� �� �����
			if (remainder < 0) {
				remainder += 10;
				temp -= 10;
			}
			tmp.nullArray[i] = ChangeCharBack(remainder);//�������� � "������ �������"
			temp /= 10;
		}
		return tmp;//���������� ���������
	}
	//���������
	LongNumber operator*(const LongNumber &number) {
		LongNumber	temporary;
		LongNumber tmp;
		int	temp = 0;//������� �������
		int	temp2 = 0;//������� ������

		for (int j = 0; j < 20; j++) {
			for (int i = 0; i < 20 - j; i++) {
				if (number.nullArray[j] == '0')//���������� ����
					continue;
				temp2 = ChangeChar(nullArray[i]) * ChangeChar(number.nullArray[j]);//��������� ��������� ����� ���� ��������
				temporary.nullArray[i + j] = ChangeCharBack((temp2 += temp) % 10);//���������� ��������� � ������
				temp = temp2 / 10;//�������� ������ �����
			}
			tmp = tmp + temporary;//�����
			temporary = "0";//�������� ��������� ���������
		}
		return tmp;//���������� ���������
	}
	//�������
	LongNumber operator/(const LongNumber &number) {
		int i = 20;
		LongNumber tmp;
		LongNumber dividendPart;//����� �� ������� 
		LongNumber divider(number);// �������� 
		LongNumber dividend(*this);// ������� 
		bool started = false;

		if (divider == (LongNumber)"0") {
			return 0;
		}

		do {
			while (dividendPart < divider && i-- > 0) {
				dividendPart.UpRank();
				dividendPart.nullArray[0] = dividend.nullArray[i];
				if (dividend.nullArray[i] != '0')
					started = true;

				if (dividendPart < divider && started && i > 0)
					if (dividend.nullArray[i] != '0' || (dividend.nullArray[i] == '0' && (i > 0)))
						tmp.UpRank();
			}
			while (dividendPart >= divider) {
				dividendPart = dividendPart - divider;
				tmp = tmp + "1";
			}
			if (i <= 0)
				break;

			tmp.UpRank();
		} while (i > 0);
		return tmp;
	}
	//������� � ��������
	LongNumber operator%(const LongNumber &number) {

		int i = 20;
		LongNumber tmp;
		LongNumber dividendPart;//������������� ������������ 
		LongNumber divider(number);// �������� 
		LongNumber dividend(*this);// ������� 
		bool started = false;

		if (divider == (LongNumber)"0") {
			throw 0;
		}

		do {
			while (dividendPart < divider && i-- > 0) {
				dividendPart.UpRank();
				dividendPart.nullArray[0] = dividend.nullArray[i];
				if (dividend.nullArray[i] != '0')
					started = true;

				if (dividendPart < divider && started && i > 0)
					if (dividend.nullArray[i] != '0' || (dividend.nullArray[i] == '0' && (i > 0)))
						tmp.UpRank();
			}
			while (dividendPart >= divider) {
				dividendPart = dividendPart - divider;
				tmp = tmp + "1";
			}
			if (i <= 0)
				break;

			tmp.UpRank();
		} while (i > 0);
		tmp = (*this) - tmp * number;
		return tmp;
	}

	//�������� ������������		
	LongNumber operator=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--)
			nullArray[i] = number.nullArray[i];
		return *this;
	}
	//�������� �� ���������
	bool operator==(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� �����-�� �������� �������� �� ����� , ���������� false
			if (ChangeChar(nullArray[i]) != ChangeChar(number.nullArray[i])) {
				return false;
			}
		}
		return true;
	}
	//�������� �� �����������
	bool operator!=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� �����-�� �������� �������� �� ����� , ���������� true
			if (ChangeChar(nullArray[i]) != ChangeChar(number.nullArray[i])) {
				return true;
			}
		}
		return false;
	}
	//�������� �� ���������
	bool operator<(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� ������� ������� ������ , ���������� true
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return true;
			//���� ������� ������� ������ , ���������� false
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return false;
		}
		//����� �����, ����� �����, ����� � ������� �����
		return false;
	}
	//�������� �� ���������/��������
	bool operator<=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� ������� ������� ������ , ���������� true
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return true;
			//���� ������� ������� ������ , ���������� false
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return false;
		}
	}
	//�������� �� ���������
	bool operator>(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� ������� ������� ������ , ���������� true
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return true;
			//���� ������� ������� ������ , ���������� false
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return false;
		}
		//����� �����, ����� �����, ����� � ������� �����
		return false;
	}
	//�������� �� ���������/��������
	bool operator>=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//���� ������� ������� ������ , ���������� true
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return true;
			//���� ������� ������� ������ , ���������� false
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return false;
		}
	}

	friend ostream& operator<<(ostream& os, const LongNumber &number);
};
//�������� ������
ostream& operator<<(ostream& os, const LongNumber &number) {
	bool trigger = false;
	for (int i = 0; i < 20; i++) {
		if (number.nullArray[19 - i] != '0')
			trigger = true;
		if (trigger)
			os << number.nullArray[19 - i];
	}
	if (!trigger)
		os << 0;
	return os;
}

int main() {
	LongNumber t1 = "500000";
	LongNumber t2 = "5";
	LongNumber t;

	t = t1 + t2;
	cout << t1 << " + " << t2 << " = " << t << endl << endl;
	t = t1 - t2;
	cout << t1 << " - " << t2 << " = " << t << endl << endl;
	t = t1 * t2;
	cout << t1 << " * " << t2 << " = " << t << endl << endl;
	t = t1 / t2;
	cout << t1 << " / " << t2 << " = " << t << endl << endl;
	t = t1 % t2;
	cout << t1 << " % " << t2 << " = " << t << endl << endl;

	system("pause");
	return 0;
}