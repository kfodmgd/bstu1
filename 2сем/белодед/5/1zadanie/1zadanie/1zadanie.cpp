#include <iostream>//Ф.И.О. работника, образование, специальность, должность, оклад, дата поступления на пред-приятие. Выбор по стражу работы. Даты 
//реализовать с помощью битового поля, должность - с помощью пе-речисления.
#include <windows.h>
using namespace std;

struct date {
	int d:2;
	int m:2;
	int y:2;
} ;

enum dol {
	storosh=1,
	inshener,
	byxgalter,
	dispetcher,
	zamDir,
	director,
};

struct infa {
	char f[50];
	char i[50];
	char o[50];
	char obr[50];
	char spec[50];
	int oklad;
	bool check;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size, i, d, day, m, y, year = 2022, stag;
	infa a[50];
	date dat;
	cout << "Введите колво сотрудников:";
	cin >> size;
	cout << "Введите стаж работы(год/лет):";
	cin >> stag;	
	for (i = 0; i < size; i++) {
		cout << "Введите ФИО сотрудника:";
		cin >> a[i].f >> a[i].i >> a[i].o;
		cout << "Введите образование сотрудника:";
		cin >> a[i].obr;
		cout << "Введите специальность:";
		cin >> a[i].spec;
		cout << "Введите должность сотрудника(где"<<endl;
		cout<<"сторож = 1,\n инженер=2,\n бухгалтер=3,\n диспетчер=4,\n зам. директора=5,\n директор=6):";
		cin >> d;
		cout << "Введите оклад сотрудника:";
		cin >> a[i].oklad;
		cout << "Введите дату поступления сотрудника на предприятие(через пробел):";
		cin >> day;
		dat.d = day;
		cin >> m;
		dat.m = m;
		cin >> y;
		dat.y=y;
		if ( (year-y)>= stag) {
			a[i].check = true;
		}
		else {
			a[i].check = false;
		}
		cout << endl;

	}
		cout << endl << endl << "Сотрудники с необходимым стажем:" << endl;
		for (i = 0; i < size; i++) {
			if (a[i].check) {
				cout << "ФИО сотрудника:" << a[i].f <<" "<< a[i].i <<" "<< a[i].o << endl;
				cout << "Обазование:" << a[i].obr<<endl;
				cout << "Специальность:" << a[i].spec<<endl;
				cout << "Оклад:" << a[i].oklad<<endl<<endl;
			}
			else {
				cout << "";
			}
		}
	return 0;
}