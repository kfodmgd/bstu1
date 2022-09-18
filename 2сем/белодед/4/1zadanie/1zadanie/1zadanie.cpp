#include <iostream>//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения. 
#include <Windows.h>
using namespace std;

struct Worker
{
	char fio[30];
	char addres[30];
	char who[2];
	int year;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	const int currentYear = 2022;
	int i, b, counter = 0;
	cout << "Введите количество людей" << endl;
	cin >> size;

	Worker a[50];
	for (i = 0; i < size; i++)
	{
		cout << "Введите ФИО " << i + 1 << "-ого человека ";
		cin.ignore(4096, '\n');
		cin.getline(a[i].fio, 30);
		cout << "Адрес: ";
		cin >> a[i].addres;
		cout << "Пол:";
		cin >> a[i].who;
		cout << "Год рождения: ";
		cin >> a[i].year;
	}
	cout << endl << "Введите год рождения ";
	cin >> b;
	cout << endl;
	for (i = 0; i < size; i++)
	{
		if (b == a[i].year)
		{
			cout << a[i].fio << " ";
			counter++;
		}
		else
			if (i == size - 1 && counter == 0)
				cout << "Людей с такой датой рождения нету.";
	}
	return 0;
}
