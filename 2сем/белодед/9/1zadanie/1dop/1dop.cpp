#include <iostream>//countX (int x) – функция подсчёта числа элементов списка с заданным значением x.
#include<Windows.h>//findMax() – функция поиска максимального  элемента списка по одному из выбранных полей. 
using namespace std;//changeX (int i, x) – функция замены i-го элемента списка элементом с заданным значением x.
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	int numb;
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод числа" << endl;
	cout << "2. Подсчёт числа элементов из списка с заданным значением х" << endl;
	cout << "3. Поиск максимального элемента в списке" << endl;
	cout << "4. Замена определённого элемента на введённое число" << endl;
	cout << "5. Вывод на экран" << endl;
	cout << "6. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin >> c;
	} while (c < 0 || c > 6);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите число: ";
	cin >> temp->numb;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->numb << ' ' << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void countX(Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t;
	t = new Address;
	int k,count;
	count = 0;
	cout << "Введите число которое нужно посчитать";
	cin >> k;
	t = *phead;
	while (t) {
		if (t->numb == k) {
			count++;
		}
		t = t->next;
	}
	cout << endl << "Количество чисел, совпадающие с введённым:" << count<<endl;
}
//-----------------------------------------------------------
void findMax(Address** phead, Address** plast) {
	struct Address* t;
	t = new Address;
	int max;
	t = *phead;
	max = t->numb;
	while (t) {
		if (t->numb > max) {
			max = t->numb;
		}
		t = t->next;
	}
	cout << endl << "Максимальный элемент:" << max<<endl;
}
//-----------------------------------------------------------
void changeX(Address** phead, Address** plast) {
	struct Address* t;
	t = new Address;
	t = *phead;
	int k,i,z;
	cout <<endl<< "Введите номер элемента, который надо заменить"<<endl;
	cin >> k;
	cout << "Введите значение на которое надо заменить число" << endl;
	cin >> z;
	i = 1;
	while (t) {
		if (i == k) {
			t->numb = z;
		}
		i++;
		t = t->next;
	}
}
//-----------------------------------------------------------
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {
			countX(&head, &last);
			break;
		}
		case 3: {
			findMax(&head, &last);
			break;
		}
		case 4: {
			changeX(&head, &last);
			break;
		}
		case 5: {
			outputList(&head, &last);
			break;
		}
		case 6:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
