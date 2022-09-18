#include <iostream>
#include<Windows.h>
using namespace std;
int a, person, category, type,size;
string type1;

struct Pers {
	char f[100];
	char i[100];
	char o[100];
	char datezas[11];
	char komment[500];
};

void Menu() {
	cout << "Здравствуйте! Выберите необходимый пункт:" << endl << "1. Выбор номера" << endl<<"2. Поиск по фамилии"<<endl << "3. Выход" << endl;
	cin >> a;
	system("cls");
}

void pers() {
abc:system("cls");
	cout << "На сколько персон вы хотели бы снять номер?" << endl << "1. 1 персона" << endl << "2. 2 персоны" << endl << "3. 3 персоны" << endl << "4. 4 персоны" << endl;
	cin >> person;
	switch (person) {
	case 1:
		cout << "Вы выбрали номер на 1 персону." << endl;
		break;
	case 2:
		cout << "Вы выбрали номер на 2 персоны." << endl;
		break;
	case 3:
		cout << "Вы выбрали номер на 3 персоны." << endl;
		break;
	case 4:
		cout << "Вы выбрали номер на 4 персоны." << endl;
		break;
	default:
		cout << "Неверно введены данные." << endl;
		system("pause");
		goto abc;
		break;
	}
}

void hotel() {
abc:system("cls");
	cout << "Какой номер вы хотели бы снять?" << endl << "1. люкс" << endl << "2. полулюкс" << endl << "3. обычный" << endl;
	cin >> type;
	switch (type) {
	case 1:
		cout << "Номер класса люкс.";
		type1 = "люкс";
		break;
	case 2:
		cout << "Номер класса полулюкс.";
		type1 = "полулюкс";
		break;
	case 3:
		cout << "Обычный номер.";
		type1 = "обычный";
		break;
	default:
		cout << "Неверно введены данные.";
		system("pause");
		goto abc;
		return;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string cost;
	int k, size=0,check=0,len;
	char poiskFam[100];
	Pers people[50];
ifDisagree:Menu();
start:switch (a) {
case 1:
	pers();
	hotel();
	system("cls");
	cout << "Вы выбрали номер на " << person << " персон, класса " << type1 << endl;

	switch (person) {
	case 1:
	case 2:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000";
			break;
		case 3:
			cout << "Цена: менее 500";
			break;
		}
		break;
	case 3:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000";
			break;
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				goto start;
			}
			else {
				goto ifDisagree;
			}
			break;
		}
		break;
	case 4:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			break;
		case 2:
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				goto start;
			}
			else {
				goto ifDisagree;
			}
			break;
		}
		break;
	}
	system("pause");
	system("cls");
	cout << "Введите своё ФИО" << endl;
	cin >> people[size].f;
	cin >> people[size].i;
	cin >> people[size].o;
	cout << "Введите дату заселения" << endl;
	cin.ignore(4096, '\n');
	cin.getline(people[size].datezas, 100);
	cout << "Введите комментарий(если такового нет, поставьте -)" << endl;
	cin.getline(people[size].komment, 100);
	cout << endl << "Итого:" << endl << "номер на " << person << "персону, класса " << type1 << ".Цена:" << cost << ". Оформлено на " << people[size].f << " " << people[size].i << " ";
	cout<<people[size].o << ". Проживание с " << people[size].datezas << " на 7 дней включительно. Комментарий:" << people[size].komment << endl << endl << endl << endl;
	size++;
	cout << "Хотите выбрать ещё 1 номер?" << endl << "1-да;2-нет"<<endl;
	cin >> k;
	if (k == 1) {
		goto start;
	}
	else {
		goto ifDisagree;
	}
	break;

case 2:
	system("cls");
	cout << "Введите необхоидимую фамилию"<<endl;
	cin >> poiskFam;
	len = strlen(poiskFam);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < len; j++) {
			if (poiskFam[j]==people[i].f[j]) {
				check++;
			}
		}
		if (check==len && strlen(poiskFam)==strlen(people[i].f)) {
			cout << endl <<"ФИО:"<< people[i].f<<" "<<people[i].i<<" "<<people[i].o << endl << "Дата заселения:" << people[i].datezas << endl << "Комментарий:" << people[i].komment << endl << endl;
			check = 0;
		}
	}
	break;

case 3:
	cout << "Bye";
	break;
}
return 0;
}