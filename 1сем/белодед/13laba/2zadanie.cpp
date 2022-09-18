#include <iostream>//Задана матрица размером nxm и число a. Вывести элементы, находящиеся в столбце а. 
using namespace std;
int  main() {
	setlocale(LC_CTYPE, "Russian");
	const int k = 100, l = 100;
	int A[k][l], m, n, a, b,i,j;
	cout << "Введите размер массива ";
	cin >> m >> n;
	cout << "Введите номер столбца ";
	cin >> a;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (j == a) {
				cout << A[i][j]<<" ";
			}
		}
	}
	return 0;
}