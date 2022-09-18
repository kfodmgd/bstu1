#include <iostream>//11.Написать программу, в которой удалить n элемент из двусвязного списка и добавить такой же в начало, с выводом на экран
#include <list>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int m, n,i,zn,temp;
	i = 1;
	list<int> myList{};
	cout << "введите колво элементов ";
	cin >> m;
	cout << "Введите номер элемента, который надо удалить ";
	cin >> n;
	cout << "Введите элементы списка ";
	while(i!=m+1) {
		cin >> zn;
		if (n == i) {
			temp = zn;
		}
		myList.push_back(zn);
		i++;
	}

	myList.remove(n);
	myList.push_back(temp);
	for (int m : myList)
	{
		cout << m << " ";
	}
	return 0;
}