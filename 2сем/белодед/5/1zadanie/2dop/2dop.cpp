#include <iostream>//Наименование, столица, численность населения, площадь. Выбор государства по занимаемой площади (> за-данного значения). Форму правления 
//реализовать с помощью перечисления.
#include <windows.h>
using namespace std;

struct gos {
	char name[100];
	char capital[100];
	int people;
	float square;
};

enum Form {
	monarx = 1,
	republik,
	unitarnoe,
	federatsiya,
	totalitarn,
	avtoritar,
	democratik,
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k,i,d;
	float sq;
	gos a[50];
	cout << "Введите количество государств:";
	cin >> k;
	for (i = 0; i < k; i++) {
		cout << "Введите наименование государства:";
		cin >> a[i].name;
		cout << "Введите столицу:";
		cin >> a[i].capital;
		cout << "Введите численность населения:";
		cin >> a[i].people;
		cout << "Введите площадь государства:";
		cin >> a[i].square;
		cout << "введите форму правления:" << endl;
		cout << "1-монархия" << endl << "2-республика" << endl << "3-унитарное госудаство" << endl << "4-федеративное государство" << endl << "5-тоталитаризм" << endl;
		cout << "6-авторитаризм" << endl << "7-демократия" << endl;
		cin >> d;
		cout << endl;
	}
	cout << endl << "Введите площадь государства:";
	cin >> sq;
	cout << "Государства с площадью равной или больше введённой:" << endl;
	for (i = 0; i < k; i++) {
		if (a[i].square >= sq) {
			cout << "Наименование:" << a[i].name << endl;
			cout << "Столица:" << a[i].capital << endl;
			cout << "Численность населения:" << a[i].people << endl;
			cout << "Площадь:" << a[i].square << endl;
		}
	}


	return 0;
}