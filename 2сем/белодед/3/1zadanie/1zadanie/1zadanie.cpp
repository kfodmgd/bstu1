#include <iostream>//Скопировать в файл FILE2(output) только четные строки из FILE1(t). Подсчитать размер файлов FILE1 и FILE2 (в байтах).
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
            k++;
            fin.getline(buff, 50); // считывание строки из файла
            if (k%2==0) {
                fout << buff << "\n";
            }
            i++;
        }
        fin.close();
    }
    return 0;
}