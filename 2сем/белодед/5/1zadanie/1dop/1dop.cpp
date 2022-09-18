#include <iostream>//Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения.
#include <windows.h>
using namespace std;

struct People {
	char fio[300];
	int d;
	int m;
	int y;
	char address[300];
	char flor[2];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k,i,year;
	People a[50];
	cout << "Введите колво людей:";
	cin >> k;
	for (i = 0; i < k; i++) {
		cout << "Введите ФИО:";
		cin.ignore(4096, '\n');
		cin.getline(a[i].fio,300);
		cout << "Введите дату рождения через пробел:";
		cin >> a[i].d >> a[i].m >> a[i].y;
		cout << "Введите адрес:";
		cin.ignore(4096, '\n');
		cin.getline(a[i].address, 300);
		cout << "Введите пол(м, ж):";
		cin >> a[i].flor;
		cout << endl;
	}
	cout << "Введите год рождения по которому надо найти человека:";
	cin >> year;
	cout << "Найденные люди:" << endl;
	for (i = 0; i < k; i++) {
		if (a[i].y == year) {
			cout << endl << "ФИО:" << a[i].fio << endl << "Дата рождения:" << a[i].d << " " << a[i].m << " " << a[i].y << " " << endl << "Адрес:" << a[i].address << endl << "Пол:" << a[i].flor << endl << endl;
		}
	}
	return 0;
}