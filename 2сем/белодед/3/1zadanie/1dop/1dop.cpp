#include <iostream>//Скопировать в файл FILE2 только те строки из FILE1,  которые начинаются с буквы «А». Подсчитать ко-личество слов в FILE2.
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
    setlocale(LC_ALL, "rus");
    int i = 0;
    int k = 0;
    char buff[50];            // буфер для хранения считываемого из файла текста
    ofstream fout("output.txt");   // создание объекта fout класса ofstream для записи 
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
		while (!fin.eof()) {
            fin.getline(buff, 50); // считывание строки из файла
            if (buff[i] == 'A') {
                fout << buff << "\n";
                k++;
            }
            //cout << buff << endl;   // печать строки
        }
        fin.close();
    }
    cout << "количество строк начинающихся с буквы А = " << k;
	return 0;
}
