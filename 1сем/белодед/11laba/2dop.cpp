#include <iostream>//вывести элементы массива которые больше меньше и равны k
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int m = 10;
	int A[m];
	int i = 0;
	int n,k;
	cout << "Введите размер массива ";
	cin >> n;
	cout << "Введите число относительно которого надо сравнивать ";
	cin >> k;
	srand(time(NULL));
	for (i; i < n; i++) {
		A[i] = rand() % 30;
		cout << A[i] << " ";
	}
	i = 0;
	for (i; i < n; i++) {
		if (A[i] == k) {
			cout << endl << "число " << A[i] << " равно k";
		}
		if (A[i] < k) {
			cout << endl << "число " << A[i] << " меньше k";
		}
		if (A[i] > k) {
			cout << endl << "число " << A[i] << " больше k";
		}
	}
	return 0;
}