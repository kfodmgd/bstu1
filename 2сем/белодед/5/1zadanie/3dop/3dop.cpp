#include <iostream>//Фамилия преподавателя, название экзамена, дата экзамена. Выбор по дате экзамена. Дату экзамена реализо-вать с помощью битового поля.
#include <windows.h>
using namespace std;

struct date {
	int d : 2;
	int m : 2;
	int y : 2;
};

struct Prepod {
	char f[50];
	char ex[50];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Prepod a[50];
	date dat;
	int k,i,d,m,y,abc,sch[50];
	cout << "Введите колво экзаменов:";
	cin >> k;
	cout <<endl<< "Введите необходимую дату экзамена через пробел:";
	cin >> d >> m >> y;
	for (i = 0; i < k; i++) {
		cout << "Введите фамилию преподавателя:";
		cin >> a[i].f;
		cout << "Введите название экзамена:";
		cin >> a[i].ex;
		cout << "Введите дату экзамена:";
		cin >> abc;
		sch[i] = 0;
		dat.d = abc;
		if (abc == d) {
			sch[i]++;
		}
		cin >> abc;
		dat.m = abc;
		if (abc == m) {
			sch[i]++;
		}
		cin >> abc;
		dat.y = abc;
		if (abc == y) {
			sch[i]++;
		}
		cout << endl;
	}
	
	cout << "Экзамены в ведённый день"<<endl;
	for (i = 0; i < k; i++) {
		if (sch[i] == 3) {
			cout << "Фамилия преподавателя:" << a[i].f << endl << "Название экзамена:" << a[i].ex << endl;
		}
	}
	return 0;
}