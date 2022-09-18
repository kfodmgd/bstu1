#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int l = 10;
	int k, i, max,n;
	int a[l];
	cout << "Введите размер массива ";
	cin >> n;
	i = 1;
	k = 0;
	max = rand()%10;
	srand(time(NULL));
	for (i; i <= n; i++) {
		a[i] = rand() % 10;
		if (a[i] == max) {
			k++;
		}
		max = a[i];
		cout << a[i] << " ";
	}
	cout << endl << k;
	return 0;
}