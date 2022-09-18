#include <iostream>//Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл. Прочитать из файла данные, посчитать и вывести количество скобок различного вида.
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
    int i,sk1,sk2,sk3;
    char buff[50], a[100];            // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи 
    i = 0;
    sk1 = 0;
    sk2 = 0;
    sk3 = 0;
    cout << "Введите строку, состоящую из цифр и скобок\n";
    cin.getline(a, 100);
    fout << a;
    fout.close();
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        fin.getline(buff, 100); // считывание строки из файла
        while (buff[i] != '\0') {
            if (buff[i] == '{' || buff[i] == '}'){
                sk1++;
            }
            if (buff[i] == '[' || buff[i] == ']') {
                sk2++;
            }
            if (buff[i] == '(' || buff[i] == ')') {
                sk3++;
            }
            i++;
        }
        fin.close();
        cout << "{} скобок = " <<sk1<< endl << "[] скобок = " <<sk2<< endl << "() скобок = " <<sk3<< endl;
    }
	return 0;
}