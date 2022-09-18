#include <iostream>////Создать одномерный массив, содержащий 15 элементов, наполнить его случайными значениями в интервале от 1 до 200. Определить 
//произведение всех элементов массива, значения которых меньше 50.
using namespace std;
int mas (int* a) {
	int pr = 1;
	for (int i = 0; i < 15; i++) {
		if (a[i] < 50) {
			pr *= a[i];
		}
	}
	return pr;
}

int main() {
	int* a, pr;
	pr = 1;
	srand(time(NULL));
	a = new int[15];
	for (int i = 0; i < 15; i++) {
		a[i] =1+ rand() % 201;
		cout << a[i] << " ";
	}

	pr = mas(a);
	cout <<endl<< pr;
	delete[] a;
	return 0;
}