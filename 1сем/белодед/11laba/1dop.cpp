#include <iostream>//слодить числа в разных массивах 
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int m = 10;
	int A[m], B[m],S[m];
	int i = 0;
	int j = 0;
	int u = 0;
	int max = 0;
	int n;
	cout << "Введите размер массива ";
	cin >> n;
	srand(time(NULL));
	for (i; i < n; i++) {
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;
	for (j; j < n; j++) {
		B[j] = rand() % 100;
		cout << B[j] << " ";
	}
	cout << endl;
	i = 0;
	j = 0;
	u = 0;


	while((i<n)&(j<n)){
		cout << A[i] + B[j] << " ";
		i++;
		j++;
	}
	return 0;
}