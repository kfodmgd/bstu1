#include <iostream>//вывести инвертированное число с позиции p и знаков n
#include <string>//для перевода из string в int
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	unsigned int a;
	unsigned int b;
	char a1[64];
	string l,ch,zn;
	int n, p, h, f, size, i, size1,temp,num;
	i = 0;
	size = 0;
	ch = "";
	cout << "Ввести число ";
	cin >> a;
	b = a;
	cout << "Ввести позицию с которой нужно сдвинуть число ";
	cin >> p;
	cout << "Ввести кол-во смещённых знаков ";
	cin >> n;
	_itoa_s(b, a1, 2);
	cout << "Число в двоичном представлении " << a1;
	b = a >> p;
	l = a1;
	h = l.length();
	f = h - n;
	l = l.substr(f - 1, n);
	cout << endl<<"Изначальное число " << l << endl<<"инвертированное число ";

	size = stoi(l);
	num = size;//поворот числа т.к. дальше оно вновь повернёться
	while (i<n) {
		temp = num % 10;
		size = size * 10 + temp;
		num = num / 10;
		i++;
	}

	for(i=0;i<n;i++) {//вывод инвертированного кода
		size1= size % 10;
		size = size / 10;
		if (size1 == 0) {
			cout << "1";
		}
		else {
			cout << "0";
		}
	}
	cout << ch << endl;
	return 0;
}