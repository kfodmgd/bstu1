#include <iostream>//Написать программу, в которой в односвязнаом списке удаляется 1 элемент после введённого и вывести на экран.
#include <forward_list>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
    forward_list<int> newlist = { 6, 2, 8, 4, 5 };
    int n, i, a;
    cout << "введите значение элемента после которого надо удалить элемент";
    cin >> a;
    i = 0;
    auto iter = newlist.begin();
    while (newlist != a) {
        newlist.erase_after(iter);
        iter++;
        i++;
    }


    //ввод списка и удаление по номеру элемента
    //также нр вставка элемента
    //удаление части списка


/*    cout << "введите колво элементов, которые надо добавить в начало/конец списка ";
    cin >> n;
    i = 0;
    a = 0;
    cout << "Введите значения, которые надо добавить в список ";
    while (i != n) {
        cin >> a;
        newlist.erase_after("6");
        i++;
    }*/
    for (int n : newlist)
    {
        cout << n << " ";
    }
    return 0;
}
