#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int m, n, p,k;
	k = 0;
	cout << "Введите 3 числа ";
	cin >> m >> n >> p;
	if (m < 0) {
		k = k + 1;
	}
	if (n < 0) {
		k = k + 1;
	}
	if (p < 0) {
		k = k + 1;
	}
	cout << k;
	return 0;
}