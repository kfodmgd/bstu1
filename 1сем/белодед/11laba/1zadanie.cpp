#include <iostream>//Ввести целое число N. Выделить из этого числа цифры, кратные m
using namespace std;
int main(){
	setlocale(LC_CTYPE,"Russian");
	int  m,d,k,l;
	//size_t n;
	//int* a = nullptr;
	//int* p = nullptr;
	//int* second;//указатель на массив
	l = 0;
	cout << "Введите число ";
	cin >> k;
	cout << "Введите число, которому должны быть кратны цифры предыдущего числа ";
	cin >> m;
	while (k != 0) {
		d = k % 10;
		k /= 10;
		if (d % m == 0) {
			cout << d<<endl;
		//	l++;
		//	if (l >= n) {//проверка на переполнение массива
		//		size_t new_n=l+1;//добавление памяти с последующим расширением массива
		//		int* new_a = new int[new_n];
		//		//КОПИРОВАНИЕ МАССИВА
		//		p = *memcpy( *n, *new_n, sizeof l);
		//	}
		}
	}
	return 0;
}