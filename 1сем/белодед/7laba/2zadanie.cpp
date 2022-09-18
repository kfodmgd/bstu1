#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 5, i = 1;
	float x, y, m,max;
	m = 0;
	y = 0;
	for (i; i <= n; i++) {
		cout << "Введите первое число x";
		cin >> x;
		max = x;
		if (x > max) {
			max = x;
		}
		m = m + x * x;
	}
	y = max *m;
	cout << y;
	return 0;
}