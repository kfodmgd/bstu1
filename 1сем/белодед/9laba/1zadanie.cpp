#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int sz = 100;
	int i, n,k,l,j,m;
	i = 1;
	k = 0;
	l = 0;
	int a[sz], b[sz], c[sz];
	cout << "Введите размер массива ";
	cin >> n;
	srand(time(NULL));
	for (i; i <= n; i++) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
		
	}
	cout << endl;
	i = 2;
	while (i <= n) {
		cout << a[i]<<" ";
		i = i + 2;
	}
	i = 1;
	cout << endl;
	while (i <= n) {
		cout << a[i] << " ";
		i = i + 2;
	}
	cout << endl;	cout << endl;	cout << endl;	cout << endl;
	
	
	//2задание
	//const int m = 100;
	//int k,i,l;
	//i = 1;
	//l = 0;
	//int a[m];
	//int b[m];
	//cout << "Введите размер массива ";
	//cin >> k;
	//srand(time(NULL));
	//for (i; i <= k; i++) {
	//	a[i] = rand() % 100;
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	//i = 1;
	//b[1] = a[k - 2];
	//b[2] = a[k - 1];
	//b[3] = a[k];
	//cout << b[1] << " " << b[2] << " " << b[3] << " ";
	//i = 1;
	//l = k - 3;
	//for (i; i <= l;i++) {
	//	cout << a[i]<<" ";
	//}
	return 0;
}