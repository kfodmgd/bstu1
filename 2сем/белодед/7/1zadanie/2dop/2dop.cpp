#include <iostream>//Разработать функцию, которая удаляет из стека первый отрицательный элемент, если такой есть.

using namespace std;

struct Stack
{
    int number;
    Stack* head;
    Stack* next;
};

void insert(Stack*&); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
float del(Stack*&);   //функция удаления, передается адрес списка и символ, который удаляется 
void printList(Stack*);      //функция вывода

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Stack* first = NULL;
    int value=0;
    insert(first);
    printList(first);
    del(first);
    printList(first);
    return 0;
}


void insert(Stack*& p) //Добавление числа value в список 
{
    cout << "Введите значения стека"<<endl;
    Stack* newP = new Stack;
    Stack* plist = nullptr;
    int value;
    if (newP != NULL)     //проверка места
    {
        for (;;) {
            newP = new Stack;
            cin >> value;
            if (!value)  break;
            newP->number = value;
            newP->next = p;
            p = newP;
        }
        newP = p;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(Stack*& p)   //Извлечение (удаление) элемента из стека
{
    int value = 0;
    Stack* previous, * current, * temp;
    if (p->number<0)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number >0)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
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
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}