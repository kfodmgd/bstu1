#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	//метод трапеций
	double h, s, x, a, b, n = 200, s1, s2, i;
	x = 0;
	cout << "Введите границы отрезков для функции x^3+3 ";
	cin >> a >> b;


	//h = (b - a) / 200;
	//x = a;
	//s = 0;
	//while (x < (b - h)) {
	//	s = s + h * ((pow(x,3) + 3) + (pow(x+h,3) + 3)) / 2;
	//	x = x + h;
	//}
	//cout << "Площадь трапеции равна " << s;


	//метод парабол
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	s1 = 0; s2 = 0;
	i = 1;
	while (i < n) {
		s2 = s2 + (pow(x, 3) + 3);
		x = x + h;
		s1 = s1 + (pow(x, 3) + 3);
		x = x + h;
		i++;
	}
	s = (h / 3) * ((pow(a, 3) + 3) + 4 * (pow(a + h, 3) + 3) + 4 * s1 + 2 * s2 + (pow(b, 3) + 3));
	cout << "Площадь трапеции равна " << s;
	return 0;
}