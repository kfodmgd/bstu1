#include <iostream>//найти корни методом дихотомии
using namespace std;

float f(float x) {
	return (x * x + 4 * x - 2);
}

float findRes(float(fun) (float), float e, float a, float b) {
	float z;
	while (abs(a - b) >= 2 * e) {
		z = 0;
		z = (a + b) / 2;
		if ((pow(z, 2) + 4*z - 2) * (pow(a, 2) + 4*a - 2) <= 0) {
			b = z;
		}
		else {
			a = z;
		}
	}
	return z;
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	float y1, y2, e, a, b, x,z;
	cout << "Введите отрезок для функции x^2 + 4x – 2 ";
	cin >> a >> b;
	z = 0;
	e = 0.001;
	x = 0;
	z = findRes(f, e, a, b);
	cout << "Корнем(и) является " << z;
    return 0;
}