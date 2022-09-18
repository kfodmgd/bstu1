#include <fstream>
#include <cstdio>  
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	char str[40],a[100];
	cout << "Введите название файла ";
	cin.getline(str, 40);
	ofstream fout(str);
	ifstream fin(str);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла";
	}
	else {
		cout << "Введите строку, которую надо записать в файл ";
		cin.getline(a, 100);
		fout << a;
		fout.close();
		system("pause");
		fout.open(str, ios_base::trunc);
		system("pause");
		remove("abc.txt");
	}
	return 0;
}