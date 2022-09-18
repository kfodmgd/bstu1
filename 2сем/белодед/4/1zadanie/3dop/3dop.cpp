#include <iostream>//Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.
#include <windows.h>
using namespace std;

struct Prepod {
	char f[50];
	char ex[50];
	char data[50];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size,i;
	char fam;
	Prepod a[50];
	cout << "Введите количество экзаменов:";
	cin >> size;
	for (i = 0; i < size; i++) {
		cout << "Введите фамилию преподавателя:";
		cin >> a[i].f;
		cout << "Введите название экзамена:";
		cin >> a[i].ex;
		cout << "Введите полностью дату экзамена(через точку):";
		cin >> a[i].data;
		cout << endl;
	}

	cout << "Введите необходимую фамилию:";
	cin >> fam;
	for (i = 0; i < size; i++) {
		if (*a[i].f == fam) {
			cout << "Экзамен у этого преподавателя назначен на " << a[i].data << ". Предмет:" << a[i].ex << endl;
		}
	}
	return 0;
}