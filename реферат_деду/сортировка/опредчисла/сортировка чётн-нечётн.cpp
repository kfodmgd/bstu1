#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int a = 100;
    int array[a], elements, i, between, j, k;
    cout << "Введите колиество элементов массива ";
    cin >> elements;
    cout << "Какие элементы вы хотите отсортировать в массиве? 1-нечётные 2-чётные ";
    cin >> k;

    srand(time(NULL));
    for (i = 0; i < elements; i++) {
        array[i] = rand() % 40;
        cout << array[i] << " ";
    }

    switch (k) {
    case 1:
        for (i = 0; i < elements; i++) {
            if (i % 2 == 1) {
                array[i] = 0;
            }
        }
        break;
    case 2:
        for (i = 0; i < elements; i++) {
            if (i % 2 == 0) {
                array[i] = 0;
            }
        }
        break;
    }

    between = 0;
    for (i = 0; i < elements; i++) {
        for (j = 0; j < elements; j++) {
            if (array[j] < array[j - 1]) {
                between = array[j];
                array[j] = array[j - 1];
                array[j - 1] = between;
            }
        }
    }
    cout << endl << "Отсортированный массив " << endl;
    if (elements % 2 == 1 && k==2) {
        for (i = 1 + (elements / 2); i < elements; i++) {
            cout << array[i] << " ";
        }
    }
    else {
        for (i = (elements / 2); i < elements; i++) {
            cout << array[i] << " ";
        }
    }
    return 0;
}