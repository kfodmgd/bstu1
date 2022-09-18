#include <iostream>//Написать функцию fmin с переменным числом параметров, в которой определяется минимальное из чисел типа int. 
using namespace std;

int fmin(int k, int *A)
{
	int min = A[0];
	for (int i = 1; i < k; i++) {
		if (A[i] < min) {
			min = A[i];
		}
	}
	return min;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n, k, i, j, * A, min;
	cout << "введите количество функций, в которых надо найти минимальное значение ";
	cin >> n;
	j = 0;
	i = 0;
	while (j < n) {
		cout << "Введите количество значений в функции" << endl;
		cin >> k;
		cout << "Введите значения функции " << endl;
		A = new int[k];
		for (i = 0; i < k; i++) {
			cin >> A[i];
		}
		cout <<"Минимальное значение "<< fmin(k, A) << endl;
		j++;
	}
	return 0;
}
