#include <iostream>//y=cosx+cos2x+...+cosnx
#include <cmath>
using namespace std;

int n;
float y = 0;

int x(int n,float a) {
	if (n == 0) {
		return y;
	}
	const double PI = acos(-1.0);
	y += cos(n*a*PI/180);
	x(n - 1, a);
	return y;
}

int main()
{
	int a;
	float y;
	setlocale(LC_CTYPE, "Russian");
	cout << "введите число"<<endl;
	cin >> n;
	cout << "Введите угол" << endl;
	cin >> a;
	y=x(n,a);
	cout << "результат:" << y;
	return 0;
}