#include <iostream>//Создать список, содержащий символы. Найти символ, равный введенному с клавиатуры, вывести его и предыдущисимвол. 
using namespace std;

struct Item {
     char value;
     Item* next;
};

int main()
{
    setlocale(LC_CTYPE, "Russian");

	Item* plist = nullptr;   //указатель на начало списка
	Item* p;
	bool ch=false;
	char vvCh, nado;
	cout << "Введите необходимую букву:";
	cin >> nado;
	cout << endl<< "Введите строку из букв: ";
	for (;;)                 // создание списка
	{
		p = new Item;

		cin >> vvCh;	   //ввод чисел, пока не введен 0
		if (vvCh=='0')  break;
		p->value = vvCh;
		p->next = plist;
		plist = p;
	}
	p = plist;

	while (p != NULL)                  // перебор списка c выводом элементов
	{
		if (p->value == nado) {
			cout << endl << p->value;
			ch = true;
		}

		p = p->next;
		if (ch) {
			cout<<p->value;
			ch = false;
		}

	}

	while (plist)              // перебор списка и удаление элементов
	{
		p = plist;
		plist = plist->next;
		delete p;
	}
    return 0;
}
