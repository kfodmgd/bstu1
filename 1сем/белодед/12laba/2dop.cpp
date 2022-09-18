#include <iostream>//вывод содержимого строки между *
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a[100];
	int i, b;
	cout << "Введте строку c * ";
	cin.getline(a, 100);
	b = strlen(a);
	for (i = 0; i < b-1; i++) {
		if (a[i] == '*') {
			i++;
			while (a[i] != '*'){
				cout << a[i];
				i++;
		    }
		}
	}
	return 0;
}