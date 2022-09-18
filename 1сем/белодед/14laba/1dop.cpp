#include <iostream>//Задан массив A из n элементов. Проверить, есть ли в нём отрицательные элементы. Если есть, то 
//найти наибольшее значение k, при котором A[k] < 0.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100;
	int i, j, n, ** A,k,max;
	cout << "Введите размер одномерного массива ";
	cin >> n;
	k = 0;
	srand(time(NULL));
	A = new int* [n];
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
		for (j = 0; j <= 0; j++) {
			A[i][j] = rand() % 40 - 20;
			cout << A[i][j]<<" ";
		}
	}
	max = A[0][0];
	for (i = 0; i < n; i++) {
		for (j = 0; j <= 0; j++) {
			if (A[i][j] < 0) {
				k++;
			}
		}
	}
	cout << endl;
	if (k == 0) {
		cout << "Отрицательных элементов нет";
	}
	else {
		for (i = 0; i < n; i++) {
			for (j = 0; j <= 0; j++) {
				if (A[i][j] < 0) {
					if (A[i][j] < max) {
						max = A[i][j];
					}
				}
			}
		}
	}
	cout << "Минимальное значение в массиве из отрицательных " << max;
	for (int l = 0; i < n; l++) {
		delete[] A[l];
	}
	delete A;
	return 0;
}