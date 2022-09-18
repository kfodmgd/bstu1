#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	float  h, y, c = 2.1, r = 4e-4, m = 7,j=0;
	while (j <= 1.7) {

		h = (10 * r - j) / (c * c + exp(-m));
		y = (h * m - j * j) + pow((1 / 10 * c), 2);
		cout << "h=" << h << "y=" << y << "\n";
		j = j + 0.1;
	}
	return 0;
}