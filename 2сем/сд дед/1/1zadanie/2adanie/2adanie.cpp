#include <iostream>//5.Написать программу, в которой в конец односвязного списка добавляется n элементов и вывести на экран.
				   //6.Написать программу, в которой в начало двусвязного списка добавляется n элементов и вывести на экран.
#include <list>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    list<int> newlist = { 6, 2, 8, 4, 5 };
    int n,i,a;
    cout << "введите колво элементов, которые надо добавить в начало/конец списка ";
    cin >> n;
    i = 0;
    a = 0;
    cout << "Введите значения, которые надо добавить в список ";
    while (i != n) {
        cin >> a;
        newlist.push_back(a);
        newlist.push_front(a);
        i++;
    }
    for (int n : newlist)
    {
        cout << n << " ";
    }
    return 0;
}
