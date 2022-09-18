#include <iostream>//Ввести целые числа в массив A[n, m] (n, m > 0) и все отрицательные элементы в нечетных строках заменить на такие же положительные.
using namespace std;
int ii(int** A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] < 0 && i % 2 == 0) {
				A[i][j] = abs(A[i][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			return A[i][j];
		}
	}
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int** A, i, j, n;
	cout << "Введите размер одномерного массива ";
	cin >> n;
	srand(time(NULL));
	A = new int* [n];
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
		for (j = 0; j < n; j++) {
			A[i][j] = 1 + rand() % 40 - 20;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	**A = ii(A, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;
	return 0;
}