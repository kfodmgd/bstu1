#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int i, a,b, k;
	k = 1;
	cout << "Введите первое число из последовательность чисел, которая оканивается 0 ";
	cin >> b;
	a = b;
	//cout << "Введите остальные числа последоваетльности ";
	while (a != 0) {
		cout << "Введите остальные числа последоваетльности ";
		cin >> a;
		if (a > 0 && b < 0 || a<0 && b>0) {
			k = k + 1;
		}
		b = a;
	}
	cout << k;
	return 0;
}