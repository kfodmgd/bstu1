#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int i = 1, n,p;
	cout << "Введите кол-во элементов ";
	cin >> n;
	cout << "Введите элемент ";
	for (i; i <= n; i++) {
		cin >> p;
		if (i % 2 == 0) {
			cout << p << endl;
		}
	}
	return 0;
}