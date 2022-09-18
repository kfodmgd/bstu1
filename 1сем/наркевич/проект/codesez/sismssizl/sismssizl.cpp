#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int a = 100;
	int b,d,k;
	char c[a];
	cout << "Введите число в десятичной системе счисления ";
	cin>>b;
	_itoa_s(b, c, 2);
	cout << "число в двоичной системе счисления " << c << endl;
	_itoa_s(b, c, 8);
	cout << "число в восимиричной системе счисления "<<c<<endl;
	_itoa_s(b, c, 10);
	cout << "число в десятичной системе счисления "<<c<<endl;
	_itoa_s(b, c, 16);
	cout << "число в шестнадцатиричной системе счисления "<<c<<endl;
	cout << "Не та система счисления?1-да 2-нет";
	cin>>d;
	switch (d) {
	case 1:
		cout << "введите необходимую систему счисления ";
		cin >> k;
		_itoa_s(b, c, k);
		cout << "число в " << k << " системе счисления " << c << endl;
		break;
	case 2:
		cout << "пока";
		break;
	}
	return 0;
}