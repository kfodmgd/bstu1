#include <iostream>
#include<Windows.h>
#include <fstream>

using namespace std;
int a, person, category, type, curSize=0;
string type1,cost;

struct Pers {
	char f[100];
	char i[100];
	char o[100];
	char datezas[11];
	char komment[500];
	char qwe[500]="";
	string persons;
	string type;
	string cost;
};

void Menu() {
	do { 
		cout << "Здравствуйте! Выберите необходимый пункт:" << endl << "1. Выбор номера" << endl << "2. Поиск по фамилии" << endl << "3. Вывод списка" << endl << "4. Чтение из файла" << endl << "5. Запись в файл" << endl<<"6. Удалить один элемент"<<endl<<"7. Удалить все элементы"<<endl<<"8. Изменить элемент"<<endl << "9. Выход" << endl;
		cin >> a;
	} while (a < 1 || a>9);
	system("cls");

}

int pers(int size, struct Pers* people) {
	system("cls");
	cout << "На сколько персон вы хотели бы снять номер?" << endl << "1. 1 персона" << endl << "2. 2 персоны" << endl << "3. 3 персоны" << endl << "4. 4 персоны" << endl;
	cin >> person;
	switch (person) {
	case 1:
		cout << "Вы выбрали номер на 1 персону." << endl;
		people[size].persons = "Номер на 1 персону";
		break;
	case 2:
		cout << "Вы выбрали номер на 2 персоны." << endl;
		people[size].persons = "Номер на 2 персоны";
		break;
	case 3:
		cout << "Вы выбрали номер на 3 персоны." << endl;
		people[size].persons = "Номер на 3 персоны";
		break;
	case 4:
		cout << "Вы выбрали номер на 4 персоны." << endl;
		people[size].persons = "Номер на 4 персоны";
		
		break;
	default:
		cout << "Неверно введены данные." << endl;
		system("pause");
		pers(size, people);
		break;
	}
	return person;
}

int hotel(int size, struct Pers* people) {
	system("cls");
	cout << "Какой номер вы хотели бы снять?" << endl << "1. люкс" << endl << "2. полулюкс" << endl << "3. обычный" << endl;
	cin >> type;
	switch (type) {
	case 1:
		cout << "Номер класса люкс.";
		people[size].type ="Номер класса Люкс";
		break;
	case 2:
		cout << "Номер класса полулюкс.";
		people[size].type = "Номер класса Полуюкс";
		break;
	case 3:
		cout << "Обычный номер.";
		people[size].type = "Номер класса Обычный";
		break;
	default:
		cout << "Неверно введены данные.";
		system("pause");
		hotel(size,people);
	}
	return type;
}



bool choose(int size, struct Pers* people) {
	int k;
	string money;
	person=pers(size, people);
	type=hotel(size, people);
	system("cls");
	cout << "Вы выбрали " << people[size].persons << ". " << people[size].type << endl;

	switch (person) {
	case 1:
	case 2:
		switch (type) {
		case 1:
			cout << "Цена:более 1000"<<endl;
			people[size].cost = "Цена более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000" << endl;
			people[size].cost = "Цена от 500 до 1000";
			break;
		case 3:
			cout << "Цена: менее 500" << endl;
			people[size].cost = "Цена менее 500";
			break;
		}
		break;
	case 3:
		switch (type) {
		case 1:
			cout << "Цена:более 1000" << endl;
			people[size].cost = "Цена более 1000";
			break;
		case 2:
			cout << "Цена:от 500 до 1000" << endl;
			people[size].cost = "Цена от 500 до 1000";
			break;
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				choose(size, people);
			}
			else {
				return false;
			}
			break;
		}
		break;
	case 4:
		switch (type) {
		case 1:
			cout << "Цена:более 1000" << endl;
			break;
		case 2:
		case 3:
			cout << "По заданным критериям не было найдено ни одной комнаты. Хотите выбрать ещё раз? 1-да, 2-нет" << endl;
			cin >> k;
			if (k == 1) {
				choose(size, people);
			}
			else {
				return false;
			}
			break;
		}
		break;
	}
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
		system("cls");
		cout << "Итого:" << endl << people[size].persons << ". "<<endl << people[size].type <<". "<<endl << people[size].cost<<". " << endl << "Оформлено на " << people[size].f << " " << people[size].i << " ";
		cout << people[size].o <<". "<<endl << "Проживание с " << people[size].datezas << " на 7 дней включительно." << endl << "Комментарий:" << people[size].komment << endl << endl << endl << endl;
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
		cout << "ФИО:" << people[i].f << " " << people[i].i << " " << people[i].o << endl;
		cout << "Дата заселения:" << people[i].datezas<<endl;
		cout << people[i].persons << endl;
		cout << people[i].type<<endl; 
		cout<<people[i].cost<<endl;
		cout << "Комментарий:" << people[i].komment << endl<<endl;
	}
}


int readFromFile(Pers* people,string fileName,int size){
	int n;
	char buff[500];
	ifstream fin(fileName);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 0;
	} else {
		fin >> n;
		for (int i = 0; i < n; i++) {
			size++;
			fin.getline(buff, 500);
			fin >> people[size - 1].f;
			fin >> people[size - 1].i;
			fin >> people[size - 1].o;
			fin.getline(buff, 500);
			fin.getline(people[size - 1].komment, 100);
			fin >> people[size - 1].datezas;
			fin.getline(buff, 500); fin.getline(buff, 500);
			people[size - 1].persons = buff;
			fin.getline(buff, 500);
			people[size - 1].type = buff;
			fin.getline(buff, 500);
			people[size - 1].cost = buff;
		}
		cout << "Данные считаны!" << endl;
	}
	fin.close();
	return n;
}



void writeInFile(Pers* people,int size,string fileNameOut){
	ofstream fout(fileNameOut);

	// условие: если файл открылся
	if (fout) {
		fout << size << endl;

		for (int i = 0; i < size; i++) {
			fout << people[i].f << endl;
			fout << people[i].i << endl;
			fout << people[i].o << endl;
			fout << people[i].komment << endl;
			fout << people[i].datezas;
			fout << people[i].persons << endl;
			fout << people[i].type << endl;
			fout << people[i].cost << endl << endl;
		}
		cout << "Данные записаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	fout.close();
}

int delElem( struct Pers* people, int size) {
	int n;
	cout << "Введите номер элемента, который надо удалить (от 1 до " << size << " )" << endl;
	cin >> n;
	--n;
	Pers noneStruct;
	if (n >= 0 && n < size) {
		for (int i = n; i < size; i++) {
			people[i] = people[i+1];
		}
		size--;
		cout << "Элемент удалён" << endl;
	}
	else {
		cout << "Номер введён неверно" << endl;
	}
	return size;
}

int delAll(struct Pers* people, int size) {
	size = 0;
	cout << "Структура очищена" << endl;
	return size;
}

void changeElem(struct Pers* people, int size) {
	int n;
	string buf;
	cout << "Введите номер элемента, который надо изменить. Номера от 1 до "<<size << endl;
	cin >> n;
	--n;
	if (n<0 || n>size) {
		cout << "Неверно введённое число";
	}
	else {
		for (int i = 0; i < size; i++) {
			if (i == n) {
				cout << "ФИО:";
				cin >> people[i].f;
				cin >> people[i].i;
				cin >> people[i].o;
				cout << "Дата заселения:";
				cin >> people[i].datezas;
				cout << "Количество персон:";
				cin >> buf;
				people[i].persons="Номер на "+buf+" персон";
				cout << "Класс номера:";
				cin >> buf;
				people[i].type="Номер класса "+buf;
				cout << "Цена:";
				cin >> buf;
				people[i].cost="Цена:"+buf;
				cout << "Комментарий:";
				cin.getline(people[i].komment, 500);
				cin.getline(people[i].komment,500);
			}
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string cost,fileName,fileNameOut;
	int check = 0, size = curSize, n;
	//Pers* people=new Pers[size];
	Pers people[50];
	Pers* people1 = new Pers[size];
	do {
	Menu();
	switch (a) {
	case 1:
		if (choose(size, people)) {
			system("pause");
			system("cls");
			vvod(people, size);
			size++;
		}
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
		size=delElem(people,size);
		break;

	case 7:
		size=delAll(people,size);
		break;

	case 8:
		changeElem(people,size);
		break;

	case 9:
		cout << "Bye";
		break;
	}
} while (a>0 && a<9);
return 0;
}