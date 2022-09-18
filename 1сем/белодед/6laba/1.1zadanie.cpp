#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	float a = 1.1774, m = 5, x=3,y,z;
	for (x; x <= 5; x = x + 0.2) {
		y = sqrt(a + m * m * x * x) / ((a + x) * m);
		if (abs(y) < 1) {
			z = y + 1;
			cout <<"z="<< z<<"\n";
		}
		else {
			z = sin(y) * sin(y);
			cout << "z=" << z<<"\n";
		}
		cout << "y=" << y<<"\n";
	}
	return 0;
}