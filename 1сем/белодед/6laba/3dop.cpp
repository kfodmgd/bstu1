#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a = 0, a1, a2, f, k;
	k = 0;
	for (a; a < 150; a++) {
		//a1 = a / 10;
		//a2 = a % 10;
		if (a%5==0) {
			k = k + a;
		}
	}
	cout << k;
	return 0;
}
