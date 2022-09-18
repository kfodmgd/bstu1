#include <iostream>//Дана матрица размером 4x4. Найти сумму наименьших элементов ее нечетных строк и наибольших элементов ее четных строк.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int a = 4, b = 4;
	int  i, j, min,min1,min2,min3,**B;
	int size = 4,k;
	cout << "Введите значения массива "<<endl;
	B = new int* [size];//выделение памяти
	for (i = 0; i < size; i++) {
		B[i] = new int [size];
		for (j = 0; j < size; j++) {
			cin >> B[i][j];
		}
	}
			min = B[0][0];
			min1 = B[1][0];
			min2 = B[2][0];
			min3 = B[3][0];
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {

			if (B[0][j] <= min) {
				min = B[0][j];
			}
			if (B[1][j] <= min1) {
				min1 = B[1][j];
			}
			if (B[2][j] <= min2) {
				min2 = B[2][j];
			}
			if (B[3][j] <= min3) {
				min3 = B[3][j];
			}
		}
	}
	cout << endl << "Сумма минимальных элементов нечётных строк "<< min+ min2<<endl<< "Сумма минимальных элементов чётных строк " << min1 + min3;
	for (k = 0; k < size; k++) {
		delete[]B[k];
	}
	delete[] B;
	return 0;
}