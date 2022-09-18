#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a = 10, a1, a2,f,k;
	k = 0;
	cout << "¬ведите число, которому должна быть равна сумма чисел ";
	cin >> f;
	for (a; a > 100; a++) {
		a1 = a / 10;
		a2 = a % 10;
		if (a1+a2==f) {
			k = k + 1;
		}
	}
	cout << k;
	return 0;
}
