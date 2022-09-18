#include<iostream>//подсчёт слов которые состоят из 5 символов
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a[100];
	int k, n, m,i,dl;
	cout << "Введите строку состоящую из 0 и 1 в конце строки обязательно поставьте пробел ";
	cin.getline(a, 100);
	m = strlen(a);
	dl = 0;
	k = 0;
	for (i = 0; i < m; i++) {
		if (a[i] == ' ' && dl == 5) {
			k++;
			dl = 0;
		}
		if (a[i] != ' ') {
			dl++;
		}
		if (a[i] == ' ') {
			dl = 0;
		}
	}
	cout << endl << k;
	return 0;
}