#include <iostream>//Создать текстовый файл F1 не менее, чем из 4 строк, и записать в него информацию. Скопировать из файла F1 в файл F2 строки, количество символов в 
//которых больше, чем заданное число.
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, min, max, razn, razn2,num,sr,k;
	i = 0;
	razn = 0;
	char buff[50];            // буфер для хранения считываемого из файла текста
	ofstream fout("output.txt");   // создание объекта fout класса ofstream для записи 
	ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
	cout << "введите число ";
	cin >> k;
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		while (!fin.eof()) {
			fin.getline(buff, 50);
			sr = strlen(buff);
			if (sr > k) {
				fout << buff << "\n";
			}
		}
	}


	return 0;
}