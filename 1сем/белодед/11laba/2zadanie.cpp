#include <iostream>//Заданы два массива по 10 целых чисел в каждом. Найти наибольшее среди чисел первого массива, которое не входит во второй массив. 
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A[10], B[10];
	int i = 0;
	int j = 0;
	int max = 0;
	srand(time(NULL));
	for (i; i < 10; i++) {
		A[i] = rand() % 100;
		cout << A[i]<<" ";
	}
	cout << endl;
	for (j; j < 10; j++) {
		B[j] = rand() % 100;
		cout << B[j] << " ";
	}

	i = 0;
	j = 0;
	for (j; j < 10; j++) {
		for (i; i < 10; i++) {
			if (A[i] == B[j]) {
				A[i] = 0;
			}
		}
	}
	i = 0;
	j = 0;
	max = A[1];
	for (i; i < 10; i++) {
		if (A[i] >= max) {
			max = A[i];
		}
	}
	cout <<endl<< max;
	return 0;
}