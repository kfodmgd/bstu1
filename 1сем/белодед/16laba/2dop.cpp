#include <iostream>//6.Найти сумму минимального и максимального элементов одномерного массива.
using namespace std;
int mas(int** a, int m, int n) {
    int min = a[0][0];
	int max = a[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
			}
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	int mm;
	mm = min + max;
	return mm;
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int** a, n, m,max,min, mm;
	cout << "Введите размер массива ";
	cin >> m >> n;
	srand(time(NULL));
	a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			a[i][j] =1+ rand() % 40;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	

	mm = mas(a, m, n);
	cout << endl << "Сумма минимального и максимального значений массива " <<mm;
	for (int i = 0; i < m; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}