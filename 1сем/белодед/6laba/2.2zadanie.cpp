#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a = 100, a1, a2, a3;
	/*a1 = a / 100;
	a2 = a / 10 % 10;
	a3 = a % 10;*/
	for (a; a < 1000; a++) {
		a1 = a / 100;
		a2 = a / 10 % 10;
		a3 = a % 10;
		if (a1 == a2 || a1 == a3 || a2 == a3) {
		}
		else {
			cout << a << "\n";
		}
	}
	return 0;
}