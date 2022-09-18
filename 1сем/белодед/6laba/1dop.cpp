#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a = 99, a1, a2;
	for (a; a > 9; a--) {
		a1 = a / 10;
		a2 = a % 10;
		if (a1 == a2) {
		}
		else {
			cout << a << "\n";
		}
	}
	return 0;
}
