#include <iostream>//вставка n символов в строку с позиции m
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	char a[51],b[51];
	int len,i,lenb,m;
	i = 0;
	cout << "Введите строку ";
	cin.getline(a, 52);//принимаем на вход всю строку а не одно слово как делает cin
	cout << "Введите символы, которые нужно вставить ";
	cin >> b;
	cout << "Введите с какой позиции нужно вставить строку ";
	cin >> m;
	len = strlen(a);
	for (i; i < m; i++) {
		cout << a[i];
	}
	cout << b;
	for (i; i < len; i++) {
		cout << a[i];
	}
	return 0;
}