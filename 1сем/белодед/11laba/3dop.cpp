#include <iostream>//вывести одинаковые значения массивов на одних позициях
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int m = 10;
	int A[m], B[m];
	int x, y,i=0,j=0;
	cout << "Введите кол-во элементов в первом массиве ";
	cin >> x;
	cout << "Введите кол-во элементов во втором массиве ";
	cin >> y;
	srand(time(NULL));
	for (i; i < x; i++) {
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;
	for (j; j < y; j++) {
		B[j] = rand() % 100;
		cout << B[j] << " ";
	}
	cout << endl;
	i = 0;
	j = 0;
	if (x >= y) {
		for (j; j < y; j++) {
			for (i; i < x; i++) {
				if (B[j] == A[i]) {
					cout << B[j]<<" ";
				}
			}
		}
	}
	else {
		for (i; i < x; i++) {
			for (j; j < y; j++) {
				if (A[i] == B[j]) {
					cout << A[i]<<" ";
				}
			}
		}
	}
	return 0;
}