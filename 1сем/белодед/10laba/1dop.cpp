#include <iostream>//вывести число со 2 позиции по nнную
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	unsigned int a;
	char a1[32];
	string l;
	int n;
	cout << "Ввести число ";
	cin >> a;
	cout << "Ввести кол-во смещённых знаков ";
	cin >> n;
	_itoa_s(a, a1, 2);
	l = a1;
	cout << a1 << "число в двоичном коде со 2 по n позицию" << l.substr(1, n);
	return 0;
}