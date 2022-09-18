#include <iostream>//В одномерном массиве, состоящем из n вещественных элементов, вычислить количество элементов 
//массива, равных 0, и сумму элементов массива, расположённых после минимального элемента.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int **A, i, j, n, k,sum,min,mi;
	cout << "Введите размер одномерного массива ";
	cin >> n;
	k = 0;
	sum = 0;
	srand(time(NULL));		
	A = new int*[n];
	for (i = 0; i < n; i++) {			
		A[i] = new int[n];
		for (j = 0; j <= 0; j++) {
			A[i][j] =1+ rand() % 40 - 20;
			cout << A[i][j]<<" ";
		}
	}
	min = A[0][0];
	for (i = 0; i < n; i++) {
		for (j = 0; j <= 0; j++) {
			if (A[i][j] == 0) {
				k++;
			}
			if (A[i][j] <= min) {
				mi = i;
			}
		}
	}
	for (i = mi; i < n; i++) {
		for (j = 0; j <= 0; j++) {
			sum += A[i][j];
		}
	}
	cout << endl << "Количество элементов равных 0 " << k << endl << "Сумма элементов массива, расположенных после минимального " << sum;
	for (int l = 0; l < n; l++) {
		delete[] A[l];
	}
	delete A;
	return 0;
}