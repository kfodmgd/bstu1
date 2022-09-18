#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, i = 1 ;
	float d = 12.5e-4, a, h,m;
	m = 0;
	h = 0;
	n = 5;
	for (i; i <= n; i++) {
		cout << "Введите первое число a ";
		cin >> a;
		m = m + a*a;
	}
	h = d + m;
	cout << h;
	return 0;
}