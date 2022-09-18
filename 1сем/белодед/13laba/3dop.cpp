#include <iostream>//. Дана целочисленная матрица A(n, m). Вычислить сумму и произведение тех её элементов, которые при делении на 
                   //два дают нечётное число.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100, b = 100;
	int A[a][b], i, j, m, n, sum,pro,kx;
	cout << "Введите размер массива ";
	cin >> m >> n;
	sum = 0;
	pro = 1;
	kx = 0;
	srand(time(NULL));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] =5+ rand() % 40;//рандомно от 5 до 40
			cout<< A[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (A[i][j] % 2 == 0) {
				kx=A[i][j] / 2;	
				if (kx%2==1) {
				    sum += A[i][j];
				    pro *= A[i][j];
			    }
			}
		}
	}
	cout << "Сумма " << sum << endl << "Произведение " << pro;
	return 0;
}