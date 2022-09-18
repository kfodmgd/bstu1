#include <iostream>//Создать очередь для символов и функции для ввода, вывода, удаления и определения размера очереди. Ввести символы с экрана в очередь. В случае совпадения 
//вводимого символа с первым элементом очереди вывести очередь и ее размер. 
using namespace std;

struct Number
{
    int info;
    Number* next;
};

int create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
int size(Number* begin);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Number* begin = NULL, * end, * t, * max;
    t = new Number;
    max = new Number;
    int p, numb,sr=0;
    cout << "Введите числа до первого нулевого или до числа, равного первому" << endl;
    cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    numb = 0;
    while (p != 0) //создание очереди
    {
        cin >> p;
        if (!create(&begin, &end, p)) {
            break;
        }
    }
    return 0;
}

int create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* start;
    Number* t = new Number;
    start = *begin;
    t->next = NULL;
    int numb = 0;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
        if(start->info == t->info) {
            cout << "Получившаяся очередь:" << endl;
            view(*begin);
            numb= size(*begin);
            cout <<endl<< "Колво элементов в очереди:" << numb;
            return true;
        }
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