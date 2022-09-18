#include <iostream>//Создать список, содержащий элементы целого типа. Найти сумму положительных элементов или выдать со-общение, что положительных элементов нет. 
using namespace std;

struct list
{
    int number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu();     //функция, показывающая меню
void sumPol(list*);  //функция подсчета суммы чисел, больших 7  

int main()
{
    setlocale(LC_CTYPE, "Russian");
     list* first = NULL;
    int choice;
    int value;
    menu();    // вывести меню 
    cout << endl;
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите значения, но первым числом 0"<<endl;
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   
            if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   
            sumPol(first);	// вычисление суммы	
            break;
        default:  
            cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu()  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы положительных чисел" << endl;
    cout << " 4 - Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    list* plist = nullptr;
    if (newP != NULL)     //проверка места
    {
        for (;;) {
            newP = new list;
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

float del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
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
        while (current != NULL && current->number != value)
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

int IsEmpty(list* p)
{
    return p == NULL;
}

void printList(list* p)  //Вывод списка 
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

void sumPol(list* p)  
{
    float sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0) {
                sm = sm + (p->number);
            }
            p = p->next;
        }
        cout << "Сумма положижетельных чисел= " << sm << endl;
    }
}