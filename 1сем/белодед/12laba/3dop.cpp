#include <iostream>//после каждой а вывести !
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a[100];
	int i, b;
	cout << "Введите строку на англ ";
	cin.getline(a, 100);
	b = strlen(a);
	for (i = 0; i < b; i++) {
		cout << a[i];
		if (a[i] == 'a') {
			cout << "!";
		}
	}
	return 0;
}