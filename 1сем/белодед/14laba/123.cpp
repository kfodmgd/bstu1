#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, * pk,*A;
	srand(time(NULL));
	for (pk = A; pk < A;pk++) {
		*pk = rand() % 40;
		cout << pk;
	}
	return 0;
}