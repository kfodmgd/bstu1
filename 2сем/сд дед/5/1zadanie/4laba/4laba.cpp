#include <iostream>
#include<Windows.h>
#include <fstream>

using namespace std;
int a, person, category, type, size=0;
string type1,cost;

struct Pers {
	char f[100];
	char i[100];
	char o[100];
	char datezas[11];
	char komment[500];
};

void Menu() {
	do { 
		cout << "Здравствуйте! Выберите необходимый пункт:" << endl << "1. Выбор номера" << endl << "2. Поиск по фамилии" << endl << "3. Вывод списка" << endl << "4. Чтение из файла" << endl << "5. Запись в файл" << endl << "6. Выход" << endl;
		cin >> a;
	} while (a < 1 || a>6);
	system("cls");

}

int pers() {
	system("cls");
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
		pers();
		break;
	}
	return person;
}

int hotel() {
	system("cls");
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
		hotel();
	}
	return type;
}



string choose() {
	int k;
	string money;
	person=pers();
	type=hotel();
	system("cls");
	cout << "Вы выбрали номер на " << person << " персон, класса " << type1 << endl;

	switch (person) {
	case 1:
	case 2:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			money = "более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000";
			money = "от 500 до 1000";
			break;
		case 3:
			cout << "Цена: менее 500";
			money = "менее 500";
			break;
		}
		break;
	case 3:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			money = "более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000";
			money = "от 500 до 1000";
			break;
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				choose();
			}
			else {
				cout << "no";
			}
			break;
		}
		break;
	case 4:
		switch (type) {
		case 1:
			cout << "Цена:более 1000";
			money = "более 1000";
			break;
		case 2:
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				choose();
			}
			else {
				cout << "no";
			}
			break;
		}
		break;
	}
	return money;
}


void vvod(struct Pers* people, int size) {
		cout << "Введите своё ФИО" << endl;
		cin >> people[size].f;
		cin >> people[size].i;
		cin >> people[size].o;
		cout << "Введите дату заселения" << endl;
		cin.ignore(4096, '\n');
		cin.getline(people[size].datezas, 100);
		cout << "Введите комментарий(если такового нет, поставьте -)" << endl;
		cin.getline(people[size].komment, 100);
		cout << endl << "Итого:" << endl << "номер на " << person << " персону, класса " << type1 << ".Цена:" << cost << ". Оформлено на " << people[size].f << " " << people[size].i << " ";
		cout << people[size].o << ". Проживание с " << people[size].datezas << " на 7 дней включительно. Комментарий:" << people[size].komment << endl << endl << endl << endl;
		size++;
}

void search(struct Pers* people, int size) {	char poiskFam[100];
int len, check = 0;
		system("cls");
		cout << "Введите необхоидимую фамилию" << endl;
		cin >> poiskFam;
		len = strlen(poiskFam);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < len; j++) {
				if (poiskFam[j] == people[i].f[j]) {
					check++;
				}
			}
			if (check == len && strlen(poiskFam) == strlen(people[i].f)) {
				cout << endl << "ФИО:" << people[i].f << " " << people[i].i << " " << people[i].o << endl << "Дата заселения:" << people[i].datezas << endl << "Комментарий:" << people[i].komment << endl << endl;
				check = 0;
			}
		}

}


void out(struct Pers* people, int size) {
	for (int i = 0; i <= size-1; i++) {
		cout << endl << "ФИО:" << people[i].f << " " << people[i].i << " " << people[i].o << endl;
		cout << "Дата заселения:" << people[i].datezas << endl;
		cout << "Комментарий:" << people[i].komment << endl;
	}
}


int readFromFile(Pers * people,string fileName,int size){
	ifstream fin(fileName);
	int n;
	if (fin.is_open()) {
		fin >> n;
		//people = new Pers[n];

		for (int i = 0; i < n; i++) {
			size++;

			fin >> people[size-1].f;
			fin >> people[size-1].i;
			fin >> people[size-1].o;
			fin.getline(people[size-1].komment,100);
			fin >> people[size-1].datezas;
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	//cout << people[size].datezas;

	fin.close();
	return n;
}



void writeInFile(Pers* people,int size,string fileNameOut){
	ofstream fout(fileNameOut/*, ios::out*/);

	// условие: если файл открылся
	if (fout) {
		fout << size << endl;

		for (int i = 0; i < size; i++) {
			fout << people[i].f << endl;
			fout << people[i].i << endl;
			fout << people[i].o << endl;
			fout << people[i].komment << endl;
			fout << people[i].datezas << endl;
		}
		cout << "Данные записаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	fout.close();

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string cost,fileName,fileNameOut;
	int k, check = 0, len, size = 0, size1,n;
	Pers people[50];
	do {
	Menu();
	switch (a) {
	case 1:
		cost = choose();
		system("pause");
		system("cls");
		vvod(people, size);
		size++;
		break;

	case 2:
		search(people, size);
		break;

	case 3:
		out(people, size);
		break;

	case 4:
		cout << "Введите название файла с которого надо считать"<<endl;
		cin >> fileName;

		n=readFromFile(people,fileName,size);
		size += n;
		break;

	case 5:
		cout << "Введите название файла в который нужно записать"<<endl;
		cin >> fileNameOut;
		writeInFile(people,size,fileNameOut);
		break;

	case 6:
		cout << "Bye";
		break;
	}
} while (a>0 && a<6);
return 0;
}