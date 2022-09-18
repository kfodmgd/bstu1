#include <fstream>//выводит в другой файл строки которые начинаются с буквы s + читает всё из файла, в консоль выводит только ошибки открытия
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0;
    char buff[50];            // буфер для хранения считываемого из файла текста
    ofstream fout("output.txt");   // создание объекта fout класса ofstream для записи 
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        while (!fin.eof()) {
            fin.getline(buff, 50); // считывание строки из файла
            if (buff[i] == 's') {
                fout << buff << "\n";
            }
            //cout << buff << endl;   // печать строки
        }
            fin.close();
    }
    return 0;
}