#include <iostream>//Компоненты файла f – целые двухзначные числа. Получить файл g, образованный из f включением только чисел больших некоторого числа, вводимого с клавиатуры
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    setlocale(LC_ALL, "rus");
    int i = 0;
    int k = 0;
    int num;
    char buff[50];            // буфер для хранения считываемого из файла текста
    ofstream fout("output.txt");   // создание объекта fout класса ofstream для записи 
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    cout << "Введите число которому должно быть больше ";
    cin >> k;
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        while (!fin.eof()) {
            fin.getline(buff, 50);
            num = atoi(buff);
            if (num > k) {
                fout << num << "\n";
            }
        }
    }
    return 0;
}