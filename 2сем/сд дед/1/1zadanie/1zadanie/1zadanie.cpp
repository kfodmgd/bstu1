#include <iostream>//2,Написать программу, которая, в зависимости от выбора пользователя, в консоли должна выводить цвета радуги, с использованием перечислений.
using namespace std;

enum Colors {
    RED=1,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    DARKBLUE,
    PURPLE,
};

int main()
{
    setlocale(LC_ALL, "rus");

    int a;
    cout << "Введите номер цвета радуги ";
    cin >> a;
    switch (a) {
    case (RED):
        cout << "красный";
        break;
    case (ORANGE):
        cout << "оранжевый";
        break;
    case (YELLOW):
        cout << "жёлтый";
        break;
    case (GREEN):
        cout << "зелёный";
        break;
    case (BLUE):
        cout << "голубой";
        break;
    case (DARKBLUE):
        cout << "синий";
        break;
    case (PURPLE):
        cout << "фиолетовый";
        break;
    }

    return 0;
}