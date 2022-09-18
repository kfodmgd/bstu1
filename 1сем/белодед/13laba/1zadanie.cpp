#include <iostream>//вывод макс в матрице
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int m=100, n=100;
	int long A[m][n];
	int i, j, k, l, max, ni, nj;
	ni = 0;
	nj = 0;
	cout << "Введите размер матрицы ";
	cin >> k >> l;
	cout << "Введите значения массива " << endl;
	srand(time(NULL));
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			cin >> A[i][j];
		}
	}
	max = A[0][0];
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			if (A[i][j] >= max) {
				max = A[i][j];
				ni = i;
				nj = j;
			}
		}
	}
	cout << "Максимальное значение " << max << endl << "Его номер в массиве " << ni << " " << nj;
	return 0;
}