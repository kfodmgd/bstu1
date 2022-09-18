#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int l=10;
	int i,max;
	int a[l];
	i = 1;
	max = -1;
	srand(time(NULL));
	for (i; i <= 7; i++) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
		if (max<=a[i]) {
			max = a[i];
		}
	}
	cout <<endl<< max;
	return 0;
}