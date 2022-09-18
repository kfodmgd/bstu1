#include <iostream>

	/*
	 *	Создать одномерный массив, содержащий 15 элементов, наполнить его случайными значениями в интервале от 1 до 200. Определить
	 *	произведение элементов массива с индексами от 2 до 5.
	 */

using namespace std;
int MultiplicationOfArray(int* size)
{
	double multiplication = 1;
	for (int i = 2; i < 5; i++) 
	{
		multiplication *= size[i];
	}
	return multiplication;
}

using namespace std;
int main() 
{
	setlocale(LC_CTYPE, "Russian");
	int* size;
	double multiplication = 1;
	srand(time(NULL));
	size = new int[15];

	for (int i = 0; i < 15; i++) 
	{
		size[i] = 1 + rand() % 201;
		cout << size[i] << " ";
	}
	multiplication = MultiplicationOfArray(size);
	cout << endl << "Произведение элементов с индексами от 2 до 5 " << multiplication;
	delete[] size;
	return 0;
}
