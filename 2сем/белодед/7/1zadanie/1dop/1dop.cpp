#include <iostream>//Разработать функцию удаления элементов стека, кратных 3, если такие есть.
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

void insert(Stack*&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
void printList(Stack*);      //функция вывода
void del(Stack*&,int);//удаление элементов кратные 3

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Stack* first = NULL;
    int choice;
    int value = -1;
    insert(first, value);
    printList(first);
    del(first,value);
    //printList(first);
    return 0;
}

void del(Stack*& p, int value)  // Удаление числа 
{
    cout << "Отсортированный список"<<endl;
    Stack* previous, * current, * temp;
    while (p != NULL) {
        if (p->data%3==0)
        {
            temp = p;
            p = p->next;    // отсоединить узел 
            delete temp;    //освободить отсоединенный узел 
        }
        else
        {
            cout << p->data<<"-->";
            p = p->next;
        }
    }
    cout << "NULL" << endl;
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
    p = nullptr;
}