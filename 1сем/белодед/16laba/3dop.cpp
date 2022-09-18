#include <iostream>//Найти количество отрицательных элементов, стоящих на чётных местах в одномерном массиве.
using namespace std;
int ch(int* a, int n) {
	int h = 0;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && i % 2 == 1) {
			h++;
		}
	}
	return h;
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int* a, n,h;
	h = 0;
	cout << "Введите размер массива ";
	cin >> n;
	srand(time(NULL));
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 20-10;
		cout << a[i] << " ";
	}


	h = ch(a, n);
	cout << endl << "колво отр элементов, стоящик на чётных местах " << h;
	return 0;
}