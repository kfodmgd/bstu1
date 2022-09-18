#include <windows.h>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a, b = ' ';
	cout << "Введите переменную ";
	cin >> a;
	cout << setw(35) << setfill(b) << b << setw(12) << setfill(a) << a << endl;
	cout << setw(35) << setfill(b) << b << setw(14) << setfill(a) << a << endl;
	cout << setw(35) << setfill(b) << b << setw(16) << setfill(a) << a << endl;
	cout << setw(35) << setfill(b) << b << setw(18) << setfill(a) << a << endl;
	cout << setw(35) << setfill(b) << b << setw(20) << setfill(a) << a << endl;
	cout << setw(35) << setfill(b) << b << setw(22) << setfill(a) << a << endl;

	// 2 пункт
	float l, r, s;
	cout << "Введите длину окружности ";
	cin >> l;
	r = l / (2 * 3.14);
	cout << 3.14 * r * r;
	return 0;
}