#include <iostream>//Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только строки из F1, которые 
//начинаются с цифры.
#include <fstream>
using namespace std;
int main()
{
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
            if (buff[i] == '1' || buff[i] == '2' || buff[i] == '3' || buff[i] == '4' || buff[i] == '5' || buff[i] == '6' || buff[i] == '7' || buff[i] == '8' || buff[i] == '9') {
                fout << buff << "\n";
                k++;
            }
        }
    }
}