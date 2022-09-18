#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 5,i=1;
	float z, x, y, t = 0.45,m,q,m1;
	m = 0;
	m1 = 0;
	for (i; i <= n; i++) {
		cout << "Введите x ";
		cin >> x;
		m = m + x * x * x;
		m1 = m1 + ((x + 1) / x);
	}
	y = t * m;
	q = t + m1;
	cout << y<<endl<<q;
	return 0;
}