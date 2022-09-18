#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int a = 100;
	int array[a], elements, i, between, j;
    cout << "Введите колиество элементов массива ";
    cin >> elements;
    srand(time(NULL));
    for (i = 0; i < elements; i++) {
            array[i] = rand() % 40;
            cout << array[i] <<" ";
        }

    between = 0;
    for (i = 0; i < elements; i++) {
        for (j = 0; j < elements; j++) {
            if (array[j] < array[j-1]) {
                between = array[j];
                array[j] = array[j-1];
                array[j - 1] = between;
            }
        }
    }
    cout << endl << "Отсортированный массив " << endl;
    for (i = 0; i < elements; i++) {
        cout << array[i] << " ";
    }
	return 0;
}