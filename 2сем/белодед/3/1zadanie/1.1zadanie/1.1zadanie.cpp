#include <iostream>//Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные и вывести нечетные числа строки
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    char buff[50], a[100];            // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи 
    i = 0;
    cout << "Введите строку, состоящую из цифр и слов, разелённых пробелами\n";
    cin.getline(a, 100);
    fout << a;
    fout.close();
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        fin.getline(buff, 50); // считывание строки из файла
        while (buff[i] != '\0') {
            if (buff[i] == '1' || buff[i] == '3' || buff[i] == '5' || buff[i] == '7' || buff[i] == '9') {
                cout << buff[i] << endl;
            }
            i++;
        }
        fin.close();
    }
	return 0;
}