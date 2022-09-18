#include <iostream>
#include <math.h>
using namespace std;
int main() {
	double d, f, i = -6, x = 4.5, z = 1.5e-6;
	d = tan(-x * i) / sqrt(x - z);
	f = sin(2 * d) / d;
	cout << "d=" << d << "\n";
	cout << "f=" << f;
	return 0;
}