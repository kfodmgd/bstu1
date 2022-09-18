#include <iostream>//В одномерном массиве, состоящем из n целых элементов, вычислить количество положительных 
//элементов мас-сива и сумму элементов массива, расположенных после последнего элемента, равного нулю.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int** A, i, j, n, k, sum, min, mi;
	cout << "Введите размер одномерного массива ";
	cin >> n;
	k = 0;
	sum = 0;
	srand(time(NULL));
	A = new int* [n];
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
		for (j = 0; j <= 0; j++) {
			A[i][j] =  rand() % 40 - 5;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	min = A[0][0];
	mi = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= 0; j++) {
			if (A[i][j] == 0) {
				mi = i;
			}
			if (A[i][j] >0) {
				k++;
			}
		}
	}
	if (mi == 0) {
		cout << "Нет элементов равных 0";
	}
	else {
		for (i = mi; i < n; i++) {
			for (j = 0; j <= 0; j++) {
				sum += A[i][j];
			}
		}
	}
	cout << endl << "Количество элементов больших нуля " << k << endl << "Сумма элементов массива, расположенных после последнего элемента массива, равного 0 " << sum;
	for (int l = 0; l < n; l++) {
		delete[] A[l];
	}
	delete A;	return 0;
}