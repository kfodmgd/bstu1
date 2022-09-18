#include <iostream>
#include<Windows.h>
using namespace std;
int a, person, category,type;
string type1;
void Menu() {
	cout << "Здравствуйте! Выберите необходимый пункт:" <<endl<< "1. Выбор номера" <<endl<< "2.Выход"<<endl;
	cin >> a;
	system("cls");
}

void pers() {
abc:system("cls");
	cout << "На сколько персон вы хотели бы снять номер?" << endl << "1. 1 персона" << endl << "2. 2 персоны" << endl << "3. 3 персоны" << endl << "4. 4 персоны" << endl;
	cin >> person;
	switch (person) {
	case 1:
		cout << "Вы выбрали номер на 1 персону."<<endl;
		break;
	case 2:
		cout << "Вы выбрали номер на 2 персоны."<<endl;
		break;
	case 3:
		cout << "Вы выбрали номер на 3 персоны."<<endl;
		break;
	case 4:
		cout << "Вы выбрали номер на 4 персоны."<<endl;
		break;
	default:
		cout << "Неверно введены данные."<<endl;
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
		type1="обычный";
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
	char f[50], i[50], o[50],data[100],infa[100],comment[100];
	int k;
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
				cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет"<<endl;
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
			switch(type){
			case 1:
				cout << "Цена:более 1000";
				break;
			case 2:
			case 3:
				cout<< "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет"<<endl;
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


		/*if (person == 1 || person == 2 && type == 1) {
			cout << "Цена:более 1000" << endl;
			cost = "более 1000";
		}
		else if (person == 1 || person == 2 && type == 2) {
			cout << "Цена:от 500 до 1000" << endl;
			cost = "от 500 до 1000";
		}
		else if (person == 1 || person == 2 && type == 3) {
			cout << "Цена: менее 500" << endl;
			cost = "менее 500";
		}
		else if (person == 3 && type == 1) {
			cout << "Цена:более 1000" << endl;
			cost = "более 1000";
		}
		else if (person == 3 && type == 2) {
			cout << "Цена:от 500 до 1000" << endl;
			cost = "от 500 до 1000";
		}
		else if (person == 3 && type == 3) {
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				goto start;
			}
		}
		else if (person == 4 && type == 1) {
			cout << "Цена:более 1000" << endl;
			cost = "более 1000";
		}
		else if (person == 4 && type == 2) {
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				goto start;
			}
		}
		else if (person == 4 && type == 3) {
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				goto start;
			}*/
		}
		system("pause");
		system("cls");
		cout << "Введите своё ФИО" << endl;
		cin.ignore(4096, '\n');
		cin.getline(infa, 100);
		cout << "Введите дату заселения"<<endl;
		cin.getline(data, 100);
		cout << "Введите комментарий(если такового нет, поставьте -)" << endl;
		cin.getline(comment, 100);
		cout << endl << "Итого:" << endl << "номер на " << person << "персону, класса " << type1 << ".Цена:" << cost << ". Оформлено на " << infa<< ". Проживание с " << data << " на 7 дней включительно. Комментарий:"<<comment << endl << endl << endl << endl;
		Menu();
		break;
	case 2:
		cout << "Bye";
		break;
	}
	return 0;
}