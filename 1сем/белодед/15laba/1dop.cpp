#include <iostream>}//Дана строка. Все русские буквы привести к верхнему регистру, латинские  заменить символом «?». 
//Вывести ре-зультат на экран.
#include <Windows.h>
using namespace std;
int st(char* a, int h) {
	for (int i = 0; i < h; i++) {
		if ((int)a[i] <= 90 && (int)a[i] >= 65 || (int)a[i] <= 122 && (int)a[i] >= 97) {
			a[i] = '?';
		}
		if ((int)a[i] <= -1 && (int)a[i] >= -32) {
			a[i] = (int)a[i] - 32;
		}
	}
	for (int i = 0; i < h; i++) {
		return a[i];
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* a, b[100];
	int h;
	cout << "Введите строку из латинских и русских букв ";
	cin.getline(b, 100);
	h = strlen(b);
	a = new char[h + 1];
	a = b;


	*a = st(a, h);
	for (int i = 0; i < h; i++) {
		cout << a[i]<<" ";
	}
	return 0;
}