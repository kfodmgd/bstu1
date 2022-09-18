#include <iostream>////Написать программу, которая вводит несколько слов текста и определяет общее количество слов. Слова разде-лены пробелами.
#include<Windows.h>
using namespace std;
int sr(char* a, int h) {
	int k = 1;
	for (int i = 0; i < h + 1; i++) {
		if (a[i-1]==' ' && a[i] != ' ') {
			k++;
		}
	}
	return k;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* a, b[100];
	int h, k, m;
	cout << "Введите строку ";
	cin.getline(b, 100);
	h = strlen(b);
	a = new char[h + 1];
	a = b;


	k = sr(a, h);
	cout <<"Слов в строке "<< k;
	return 0;
}