#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int l = 10;
	int k, i, max, n;
	int a[l];
	i = 3;
	k = ++i * ++i;
	cout << k;
	/*i = 3;
	k = i++ * i++;
	cout <<"i++*i++  " << k<<endl;

	int i1 = 3;
	k = ++i1 * ++i1;
	cout << "++i*++i  " << k << endl;

	int i2 = 3;
	k = ++i2 * i2++;
	cout << "++i*i++  " << k << endl;

	int i3 = 3;
	k = i3++ * ++i3;
	cout << "i++*++i  " << k << endl;*/


	//cout << "Введите размер массива ";
	//cin >> n;
	//i = 1;
	//k = 1;
	//max = rand() % 10;
	//srand(time(NULL));
	//for (i; i < n; i++) {
	//	a[i] = rand() % 5;
	//	if (a[i] == max) {
	//		k++;
	//	}
	//	max = a[i];
	//	cout << a[i] << " ";
	//}
	//cout << endl << k;
	return 0;
}