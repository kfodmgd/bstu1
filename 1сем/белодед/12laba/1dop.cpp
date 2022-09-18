#include <iostream>//вывести часть строки с позиции p и n знаков
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a[100];
	int n, k, i,p;
	cout << "Введите строку ";
	cin.getline(a, 100);
	cout << "Введите количество символов ";
	cin >> n;
	cout << "Введите номер позиции ";
	cin >> p;
	k = strlen(a);
	cout << "Выделенная часть строки ";
	for (i = p-1; i < p+n-1; i++) {
		cout << a[i];
	}

	return 0;
}