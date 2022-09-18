#include <iostream>//Создать список, содержащий элементы вещественного типа. Найти среднее значение положительных элементов
using namespace std;
struct Item
{
	float value;
	Item* next;
};
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Item* plist = nullptr;   //указатель на начало списка
	Item* p;  	float number;
	int k = 0;
	float sum = 0;
	cout << "Input number ";
	for (;;)                 // создание списка
	{
		p = new Item;
		cin >> number;
		if (!number)  break;
		p->value = number;
		p->next = plist;
		plist = p;
	}
	p = plist;

	while (p!=NULL)                  // перебор списка c выводом элементов
	{
		cout << p->value << ' ';

		if (p->value > 0) {
			sum += p->value;
			k++;
		}
		p = p->next;

	}

	while (plist)              // перебор списка и удаление элементов
	{
		p = plist;
		plist = plist->next;
		delete p;
	}
	
	cout << endl << endl << "Сумма положительных чисел равна:" << sum/k << endl;
	return 0;
}
