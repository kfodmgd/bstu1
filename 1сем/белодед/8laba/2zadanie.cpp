#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	double y1, y2,e,a,b,x;
	cout << "Введите отрезок для функции x^3+x-3 ";
	cin >> a >> b;
	e = 0.0001;
	x = 0;
	//x = a;
	//while (a <= b) {
	//	y1 = pow(a, 3);
	//	y2 = 3-a;
	//	if (y1 == y2) {
	//		cout << "корем уравнения является " << a;
	//	}
	//	a = a + e;
	//}


	while (abs(a - b) >= 2 * e) {
		x = (a + b) / 2;
	    if ((pow(x, 3) + x - 3) * (pow(a, 3) + a - 3) <= 0) {
		    b = x;
	    }
	    else {
		    a = x;
	    }
	}
	cout << "Корнем являет " << x;
	return 0;
}