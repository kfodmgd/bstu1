#include <iostream>
#include <math.h>
using namespace std;
int main() {
	double y, s, z = 1.7, m = 3,n=3, a = 4e-8;
	y = (z + log(z)) / (exp(-3) + sqrt(a));
	s = (1 + m * n) / log(1 + z);
	cout << "y=" << y << "\n";
	cout << "s=" << s;
	return 0;
}