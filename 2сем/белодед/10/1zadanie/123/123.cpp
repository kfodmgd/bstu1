#include <iostream>//y=cosx+cos2x+...+cosnx
#include <cmath>
using namespace std;

int n;
float y = 0;

int x(int n) {
	if (n == 1 || n==2) {
		return 1;
	}
	return 	x(n-1)+x(n-2);
}

int main()
{
	int a;
	float y;
	setlocale(LC_CTYPE, "Russian");
	cout << "введите число" << endl;
	cin >> n;
	y = x(n);
	cout << "результат:" << y;
	return 0;
}