#include <iostream>//В одномерном массиве, состоящем из n элементов, вычислить количество отрицательных элемен-тов массива и 
//сумму модулей элементов, расположенных после минимального по модулю элемента.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 100;
	int j,i,size,min,k,mm,sum,**B;//mem-указатель адреса 
	k = 0;
	cout << "Введите размер одномерного массива ";
	cin >> size;
	cout << "Введите его значения " << endl;
	B = new int* [size];//выделение памяти
	for (i = 0; i < size; i++) {
		B[i] = new int[size];
		for (j = 0; j <=0; j++) {
			cin >> B[i][j];
		}
	}
	min = abs(B[0][0]);
	mm = 0;//номер мин элемента
	sum = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j <= 0; j++) {
			if (B[i][j] < 0) {
				k++;
			}
			if (abs(B[i][j]) <= min) {
				B[i][j] = abs(B[i][j]);
				min = abs(B[i][j]);
				min = abs(min);
				mm = i;
			}
		}
	}
	for (i = mm; i < size; i++) {
		for (j = 0; j <= 0; j++) {
			B[i][j] = abs(B[i][j]);
			sum += B[i][j];
		}
	}
	cout << endl<<"Минимальное значение " << min << endl;
	cout << endl << "Колво отрицательных элементов " << k << endl << "Сумма чисел после максимального (по модулю) " << sum-min;
	for (int k = 0; k < size; k++) {
		delete[] B[k];
	}
	delete B;
	return 0;
}