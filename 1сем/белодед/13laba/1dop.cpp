#include <iostream>//Дана матрица A(n, m). Найти количество элементов этой матрицы, больших среднего арифметического всех её элементов.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100, b=100;
	int A[a][b];
	int n, m, i, j, sum, k, sr,ss;
	sum = 0;
	k = 0;
	sr = 0;
	ss = 0;
	cout << "Введите размер массива ";
	cin >> m >> n;
	srand(time(NULL));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = rand() % 40;
			cout << A[i][j] << " ";
			k++;
			sum += A[i][j];
		}
		cout << endl;
	}
	sr = sum / k;
	cout << endl << "Среднее арифметическое " << sr;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if(A[i][j]>sr){
				ss++;
			}
		}
	}
	cout << endl << "Колво элементов больших среднего арифметического в массиве " << ss;
	return 0;
}