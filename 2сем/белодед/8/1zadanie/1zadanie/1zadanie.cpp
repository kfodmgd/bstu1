#include <iostream>//Создать очередь для символов и функции для ввода, вывода и удаления элементов очереди. Ввести эталонный символ. Вводить символы с экрана в очередь до встречи 
//эталонного. После встречи с эталон-ным, вывести всю очередь, удалить два элемента и посчитать оставшееся количество элементов очереди. 
using namespace std;

struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p); //формирование элементов очереди
int view(Number* begin); //функция вывода элементов очереди 
void DeltoMin(Number** begin); //функция удаления до минимального элемента 

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Number* begin = NULL, * end, * t;
    t = new Number;
    int p,sr,numb;
    cout << "\nВведите эталонное число:";
    cin >> sr;
    cout << endl << "Введите числа";
    cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    numb = 0;
    while(p!=sr) //создание очереди
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
    DeltoMin(&begin);   //удаление до минимального
    cout << "\nНовая очередь:\n";
    numb=view(begin);
    cout <<endl<< "Колво элементов очереди:" << numb;
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

int view(Number* begin) //Вывод элементов очереди 
{
    int numb = 0;
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return 0;
    }
    else
        while (t != NULL)
        {
            numb++;
            cout << t->info << " ";
            t = t->next;
        }
    return numb;
}

void DeltoMin(Number** begin) //Удаление до минимального элемента 
{
    Number* t;
    t = new Number;
    for(int i=0;i<2;i++)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
