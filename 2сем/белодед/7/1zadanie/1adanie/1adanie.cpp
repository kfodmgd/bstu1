#include <iostream>//Разработать функцию, которая по одному стеку строит два новых: Stack1 из положительных элементов и Stack2 из отрицательных
using namespace std;

struct Stack
{
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

void insert(Stack*&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
void printList(Stack*);      //функция вывода
void sort(Stack*&, Stack1*&, Stack2*&);//сортирвка
void printCh(Stack1*);
void printNech(Stack2*);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Stack* first = NULL;
    Stack1* first1 = NULL;
    Stack2* first2 = NULL;
    int choice;
    int value=0;
            insert(first, value);
            printList(first);
            sort(first, first1, first2);
            printCh(first1);
            printNech(first2);
    return 0;
}

void sort(Stack*& p, Stack1*& p1, Stack2*& p2) {
    Stack1* st1 = new Stack1;
    Stack1* plist1 = nullptr;
    Stack2* st2 = new Stack2;
    Stack2* plist2 = nullptr;
    while (p != NULL) {
        if (p->data > 0) {
            st1 = new Stack1;
            st1->data = p->data;
            st1->next = p1;
            p1 = st1;
            p = p->next;
        }
        else {
            st2 = new Stack2;
            st2->data = p->data;
            st2->next = p2;
            p2 = st2;
            p = p->next;
        }
    }
    st1 = p1;
    st2 = p2;
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

void printCh(Stack1* p1)  //Вывод списка 
{
    cout << "Список со значениями, больше 0" << endl;
    if (p1 == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p1 != NULL)
        {
            cout << "-->" << p1->data;
            p1 = p1->next;
        }
        cout << "-->NULL" << endl;
    }
}

void printNech(Stack2* p2)  //Вывод списка 
{
    cout << "Список со значениями, меньше 0" << endl;
    if (p2 == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p2 != NULL)
        {
            cout << "-->" << p2->data;
            p2 = p2->next;
        }
        cout << "-->NULL" << endl;
    }
}