#include <iostream>//Разработать функцию, которая по одному стеку строит два новых: Stack1 из положительных элементов и Stack2 из отрицательных
using namespace std;

struct Stack {
	int data;
	Stack* next;
};

struct Stack1 {
	int data;
	Stack1* next;
};

struct Stack2 {
	int data;
	Stack2* next;
};

void insert(Stack*&);//ввод значений
void sort(Stack*&);//сортировка
void print(Stack*&);//вывод исх стека
void clear();//очистка стеков



int main()
{
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));
	int i, size,znach;
	Stack* first = NULL;
	/*Stack* st;
	Stack1* st1;
	Stack2* st2;
	Stack1* first1 = nullptr;
	Stack2* first2 = nullptr;
	cout << "Введите значения в стеке" << endl;
	for (;;) {
		cin >> znach;
		if (!znach) {
			break;
		}
		st = new Stack;
		st->data = znach;
		st->next = first;
		first = st;
	}
	st = first;
	while (st != NULL) {
		cout << st->data << " ";
		st = st->next;
	}
	st = first;
	while (st != NULL) {
		if (st->data > 0) {
			st1 = new Stack1;
			st1->data = st->data;
			st1->next = first1;
			first1 = st1;
			st = st->next;
		}
		else {
			st2 = new Stack2;
			st2->data = st->data;
			st2->next = first2;
			first2 = st2;
			st = st->next;
		}
	}
		st1 = first1;
		st2 = first2;
		cout << "Стэк со значениями, больших 0" << endl;
		while (st1 != NULL) {
			cout << st1->data << " ";
			st1 = st1->next;
		}
		cout << endl << endl << "Стэк со значениями, меньших 0" << endl;
		while (st2 != NULL) {
			cout << st2->data << " ";
			st2 = st2->next;
		}*/
	insert(first);
	print(first);
	sort(first);
	return 0;
}

void insert(Stack*& first) {
	int znach;
	Stack* st;
	st = new Stack;
	Stack* fir=nullptr;
	cout << "Введите значения в стеке" << endl;
	for (;;) {
		cin >> znach;
		if (!znach) {
			break;
		}
		st->data = znach;
		st->next = first;
		first = st;
	}
	st = first;
}

void print(Stack*& first) {
	if (first == NULL) {
		cout << "Список пуст";
	}
	else {
		while (first != NULL) {
			cout << first->data << " ";
			first = first->next;
		}
	}
}




/*void insert(Stack*& first, int znach)
{
	Stack* st = new Stack;
	if (st != NULL) {
		cout << "Введите значения" << endl;
		for (;;) {
			st = new Stack;
			cin >> znach;
			if (!znach)  break;
			st->data = znach;
			st->next = first;
			first = st;
		}
		st = first;
	}
	else {
		cout << "Операция добавления не выполнена" << endl;
	}
}


void sort(Stack* &first) {
	Stack* st = new Stack;
	st = new Stack;
	Stack1* st1 = new Stack1;
	Stack2* st2 = new Stack2;
	Stack1* first1 = NULL;
	Stack2* first2 = NULL;
	if (first == NULL) {
		cout << "Стэк пуст";
	}
	else {
		while (first != NULL) {
			if (first->data > 0) {
				st1 = new Stack1;
				st1->data = first->data;
				st->next = first;
				first = st->next;
				st1->next = first1;
				first1 = st1->next;
			}
			/*else {
				st2 = new Stack2;
				st2->data = first->data;
				st2->next = first;
				first = st2->next;
			}
		}
	}
}*/