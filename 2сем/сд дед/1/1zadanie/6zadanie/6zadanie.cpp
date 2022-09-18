#include <iostream>//13.Написать программу, в которой нужно удалить все элементы односвязного списка и добавить n новых, с выводом на экран.
#include <forward_list>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, n, a;
	i = 0;
	forward_list<int> oldlist = { 6, 2, 8, 4, 5 };
	cout << "старый список " << endl;
	for (int n : oldlist)
	{
		cout << n << " ";
	}
	oldlist.clear();
	cout << endl;

	cout << "Введите количество символов ";
	cin >> n;
	cout << "Введите значения ";
	while (i != n) {
		cin >> a;
		oldlist.push_front(a);
		i++;
	}

	cout << "новый список" << endl;
	for (int n : oldlist)
	{
		cout << n << " ";
	}
	return 0;
}