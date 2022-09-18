#include <iostream>//Создать список, содержащий элементы целого типа. Найти сумму положительных элементов или выдать со-общение, что положительных элементов нет. 
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

void insert(Stack*&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
void printList(Stack*);      //функция вывода
int sort(Stack*&);//сортирвка

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int sum = 0;
    Stack* first = NULL;
    int choice;
    int value = 0;
    insert(first, value);
    printList(first);
    sum=sort(first);
    cout << sum;
    return 0;
}

int sort(Stack*& p) {
    int sum = 0;
    while (p != NULL) {
        if (p->data > 0) {
            sum += p->data;
            p = p->next;
        }
        else {
            p = p->next;
        }
    }
    return sum;
}

void insert(Stack*& p, int value) //Добавление числа value в список 
{
    Stack* st = new Stack;
    Stack* plist = nullptr;
    cout << "Введите значения стека" << endl;
    if (st != NULL)     //проверка места
    {
        for (;;) {
            st = new Stack;
            cin >> value;
            if (!value)  break;
            st->data = value;
            st->next = p;
            p = st;
        }
        st = p;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}


void printList(Stack* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->data;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}