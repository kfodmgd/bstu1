#include <iostream>//Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: ФИО студента, число экзаменов, полученные 
//оценки. Определить функции для обработки отдельного объекта (например, для проверки, сда-ны ли все экзамены на 4 и 5). Написать функцию для обработки массива 
//структур. В результате обработки требуется вычис-лить характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к 
//общему числу студентов, в процентах. 
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct Student
{
	char f[30];
	char i[30];
	char o[30];
	int exams;
	int marks[20];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	const int currentYear = 2022;
	int i, b = 0, counter = 0, j, num, len = 0, srMark1, srMark2, usp = 0, rezUsp = 0;
	char sravn[50],famil[30];
	cout << "Введите количество людей:";
	cin >> size;

	Student a[50];
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " студент:" << endl;
		cout << "Введите фамилию студента ";
		cin>>a[i].f;
		cout << "Введите имя студента ";
		cin >> a[i].i;
		cout << "Введите отчество студента ";
		cin >> a[i].o;
		cout << "Количество экзаменов: ";
		cin >> a[i].exams;
		cout << "Введите оценки:";
		for (j = 0; j < a[i].exams; j++) {
			cin >> a[i].marks[j];
		}
		cout << endl << endl;
	}

	cout << "Что вы хотите сделать с этими данными?" << endl;
	cout << "1. Найти студента по фамилии" << endl;
	cout << "2. Найти студента по 2 оценке" << endl;
	cout << "3. Успеваемость группы" << endl;
	cin >> num;
	switch (num) {
	case 1:
		cout << endl << "Введите фамилию:";
		cin >> famil;
		len=strlen(famil);
		cout << endl << endl;
		for (i = 0; i < size; i++) {
			for (j = 0; j < len; j++) {
				if (famil[j] == a[i].f[j]) {
					cout << a[i].f << " ";
					i++;
				}
			}
		}
		cout << endl;
		break;
	case 2:
		cout << "Введите 2 оценки на которую должны быть сданы все экзамены: ";
		cin >> srMark1 >> srMark2;
		cout << "студенты с оценками за экзамены " << srMark1 << " и " << srMark2;
		for (i = 0; i < size; i++) {
			b = 0;
			for (j = 0; j < a[i].exams; j++) {
				if (a[i].marks[j] == srMark1 || a[i].marks[j] == srMark2) {
					b++;
				}
				if (b == a[i].exams) {
					cout <<endl<< a[i].f<<" "<<a[i].i <<" "<< a[i].o << " ";
				}
			}
		}
		cout << endl;
		break;
	case 3:
		for (i = 0; i < size; i++) {
			b = 0;
			for (j = 0; j < a[i].exams; j++) {
				if (a[i].marks[j] == 4 || a[i].marks[j] == 5) {
					b++;
				}
				if (b == a[i].exams) {
					usp++;
				}
			}
		}
			rezUsp = usp*100/size;
			cout << "Успеваемость группы:" << rezUsp<<"%";
		
	}
	return 0;
}
