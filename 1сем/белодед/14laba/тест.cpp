#include <iostream>//В одномерном массиве, состоящем из n вещественных элементов, вычислить количество отрицательных элемен-тов массива и 
//сумму модулей элементов, расположенных после минимального по модулю элемента.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100;
	int i, A[a], n, min, k, mm, sum;
	float m;
	k = 0;
	cout << "Введите размер массива ";
	cin >> n;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i] = rand() % 41 - 20;// от - 20  до 20
		cout << A[i] << " ";
	}
	min = abs(A[0]);
	mm = 0;
	sum = 0;
	for (i = 0; i < n; i++) {
		if (A[i] < 0) {
			k++;
		}
		if (abs(A[i]) <= min) {
			A[i] = abs(A[i]);
			min = abs(A[i]);
			min = abs(min);
			mm = i;
		}
	}
	for (i = mm; i < n; i++) {
		A[i] = abs(A[i]);
		sum += A[i];
	}
	cout << endl << min << endl;
	cout << endl << "Колво отрицательных элементов " << k << endl << "Сумма чисел после максимального (по модулю) " << sum - min;
	return 0;
}