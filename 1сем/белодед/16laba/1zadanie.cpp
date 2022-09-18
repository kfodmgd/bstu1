#include <iostream>//Создать одномерный массив, содержащий 15 элементов, наполнить его случайными значениями в интервале от 1 до 200. Определить сумму всех 
//нечетных элементов массива.
int mas(int* b) {
	int sum = 0;
	for (int i = 0; i < 15; i++) {
		if (i % 2 == 0) {
			sum += b[i];
		}
	}
	return sum;
}

using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int* b, sum;
	srand(time(NULL));
	b = new int[15];
	for (int i = 0; i < 15; i++) {
		b[i] = 1 + rand() % 201;
		cout << b[i]<<" ";
	}
	sum = mas(b);
	cout <<endl<<"Сумма нечётных элементов "<< sum;
	delete[] b;
	return 0;
}