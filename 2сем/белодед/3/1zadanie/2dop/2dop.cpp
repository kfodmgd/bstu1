#include <iostream>//Скопировать из файла FILE1 в файл FILE2 строки, начиная с к до к+3. Подсчитать количество гласных букв в FILE2.
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, i, j, l,len;
	k = 0;
	i = 1;
	j = 0;
	l = 0;
	len = 0;
	cout << "Введите номер строки с которой надо вывести текст ";
	cin >> k;
	char buff[50], buffgl[100];
	ofstream fout("output.txt");
	ifstream fin("t.txt");
	if (!fin.is_open()) {
		cout << "\nОшибка открытия файла";
	}
	else {
		while (!fin.eof()) {
				fin.getline(buff, 50);
				if (i >= k && i <= k + 3) {
					fout << buff << endl;//запись в файл
					len = strlen(buff);
					strcpy_s(buffgl, buff);
					//подсчёт гласных букв
					for (j = 0; j < len; j++) {
						if (buffgl[j] == 'a' || buffgl[j] == 'e' || buffgl[j] == 'i' || buffgl[j] == 'o' || buffgl[j] == 'u' || buffgl[j] == 'y' ||
							buffgl[j] == 'A' || buffgl[j] == 'E' || buffgl[j] == 'I' || buffgl[j] == 'O' || buffgl[j] == 'U' || buffgl[j] == 'Y') {
							l++;
						}
					}


				}
			i++;
		}
		fin.close();
		cout << l;
	}
	return 0;
}