#include <iostream>//Написать программу, которая вводит несколько строк текста и символ «m» и использует функцию, чтобы опре-делить 
//суммарное число вхождений символа в текст.
#include <Windows.h>
using namespace std;
int sr(char *a,char *b,int h){
	int k = 0;
	for (int i = 0; i < h+1; i++) {
		if (a[i] == *b) {
			k++;
		}
	}
	return k;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char *a,*b,c[100];
	int h,k,m;
	k = 0;
	cout << "Введите строку ";
	cin.getline(c, 100);
	b = new char[2];
	cout << "Введите символ ";
	cin >> b;
	h = strlen(c);
	a = new char[h + 1];
	a = c;


	k = sr(a,b, h);
	cout << k;
	return 0;
}