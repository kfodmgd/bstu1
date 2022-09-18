#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Создаем структуру из элементов типа string
struct Initial {
	string surname,
		name,
		patronymic;
};

void ReadingData(Initial* (&d), int& n, string fileName)
{
	//создаём поток для чтения
	ifstream reading(fileName);

	// условие: если файл открылся
	if (reading) {
		reading >> n;

		d = new Initial[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].surname;
			reading >> d[i].name;
			reading >> d[i].patronymic;

		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}

void SavingData(Initial* d, int n, string fileName)
{
	// создается поток для записи
	// открывает fileName и делает так, чтобы он был пустой
	ofstream record(fileName, ios::out);

	// условие: если файл открылся
	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].surname << endl;
			record << d[i].name << endl;
			record << d[i].patronymic << endl;
		}
		cout << "Данные записаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}

int main()
{

	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодов страницы win-cp 1251 в поток вывода
	int size = 0;
	// Массив структур
	Initial* arr = new Initial[size];
	ReadingData(arr, size, "Input.txt");
	SavingData(arr, size, "Output.txt");
}
