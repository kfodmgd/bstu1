#include <iostream>////Создать одномерный массив, содержащий 15 элементов, наполнить его случайными значениями в интервале от 1 до 200. Определить 
//произведение элементов массива с индексами от 2 до 7.
using namespace std;
int mas(int* b) {
	double pr = 1;
	for (int i = 2; i <7; i++) {
		
			pr =pr* b[i];
		
	}

	return pr;//инт в строку
}

using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int* b;
	double pr=1;
	srand(time(NULL));
	b = new int[15];
	for (int i = 0; i < 15; i++) {
		b[i] = 1 + rand() % 201;
		cout << b[i] << " ";
	}
	pr = mas(b);
	cout << endl << "Произведение элементов с индексами от 2 до 7 " << pr;
	delete[] b;
	return 0;
}
