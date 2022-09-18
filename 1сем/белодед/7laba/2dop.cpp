#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int i = 1, n, p;
	cout << "Введите кол-во элементов ";
	cin >> n;
	cout << "Введите элемент ";
	for (i; i <= n; i++) {
		cin >> p;
		if (p<0) {
			n = i;
		}
	}
	cout << n;
	return 0;
}