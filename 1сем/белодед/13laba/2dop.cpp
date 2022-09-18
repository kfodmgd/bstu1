#include <iostream>//Задана числовая матрица размером nxm. Определить количество таких элементов матрицы, 
                   //у которых в строке слева от элемента находятся числа, меньшие его, а справа – большие. 
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100, b = 100;
	int A[a][b],j, i, n, m, min,max,t,l;
	cout << "Введите массив ";
	cin >> m >> n;
	l = -1;
	srand(time(NULL));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = rand() % 40;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			t = A[i][j];
			min = A[i][j - 1];
			max = A[i][j + 1];
			if (min < t && t < max) {
				l++;
			}
		}
	}
	cout <<endl<< l;
	return 0;
}