#include <iostream>//Создать очередь для целых чисел и функции для ввода, вывода, удаления и определения размера оче-реди. Разработать функцию, которая удаляет из очереди 
//первый отрицательный элемент, если такой есть.
using namespace std;

struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
void DeltoMin(Number** begin); //функция удаления 1 отр элем
int size(Number* begin);
Number* maxElem(Number* begin);//определение минимального элемента

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Number* begin = NULL, * end, * t, * max;
    t = new Number;
    max = new Number;
    int p, numb;
    cout << "Введите числа до первого нулевого" << endl;
    cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    numb = 0;
    while (p != 0) //создание очереди
    {
        cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nЭлементы очереди \n";
    if (begin == NULL) {   //вывод на экран
        cout << "No elements" << endl;
    }
    else {
        view(begin);
    }
    numb = size(begin);
    cout << endl << "Колво элементов в очереди:" << numb - 1 << endl;
    t = maxElem(begin);
    cout << "Максимальный элемент очережи:" << t->info;
    DeltoMin(&begin);
    cout << endl << "Очередь после удаления первого отрицательного элемента" << endl;
    view(begin);
    return 0;
}

void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}

void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << " ";
            t = t->next;
        }
}

Number* maxElem(Number* begin) //Опрделение минимального элемента
{
    Number* t = begin, * mn = 0;
    int max;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        max = t->info;
        while (t->info != 0)
        {
            if (t->info > max)
            {
                max = t->info;
                mn = t;
            }
            t = t->next;
        }
    }
    return mn;
}

int size(Number* begin) {
    Number* t = begin;
    int numb = 0;
    if (t == NULL) {
        return numb;
    }
    else {
        while (t != NULL) {
            numb++;
            t = t->next;
        }
        return numb;
    }
}

void DeltoMin(Number** begin) //Удаление первого отр
{
    Number* t, *previous, *current;
    t = new Number;
    if (*begin < 0) {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
        return;
    }
    else {
        previous = (*begin);
        current = (*begin)->next;
        while (current != NULL && current->info > 0) {
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            t = current;
            previous->next = current->next;
            free(t);
            return;
        }
    }
}
