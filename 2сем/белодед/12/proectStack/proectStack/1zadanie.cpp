#include <iostream>
#include "add.h"
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp, k;
	Node* rc;
	Node* tree = nullptr;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите число  ";	cin >> temp;
		insert(temp, &tree);
	}
	cout << "Ваше дерево" << endl;
	print(tree, 0);
	cout << endl << "Введите значение которое нужно подсчитать в дереве ";
	cin >> k;
	rc = search(tree, k);
	return 0;
}
