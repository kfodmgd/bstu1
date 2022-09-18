#include <iostream>//8.Написать программу, в которой нужно найти минимальный элемент дэкa и добавить его в начало, с выводом на экран
				   //12.Написать программу, в которой нужно найти произведение всех элементов деки и вывести его на экран.
#include <deque>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int dequeSize,min,i,proizv;
    dequeSize = 0;
    i = 0;
    min = 0;
    proizv = 1;
    cout << "Введите размер дека: ";
    cin >> dequeSize;

    deque<int> deq(dequeSize);

    cout << "Введите элементы дека: ";
    for (i=0; i < deq.size(); i++) {
        min = deq[1];
        cin >> deq[i];
        proizv *= deq[i];
    }

    for (i = 0; i < deq.size(); i++) {
        if (deq[i] < min) {
            min = deq[i];
        }
    }
    deq.push_front(min);
    cout << "Минимальное значение:" << min << endl;
    cout << "произведение значений в деке:" << proizv << endl;
    for (i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }
	return 0;
}