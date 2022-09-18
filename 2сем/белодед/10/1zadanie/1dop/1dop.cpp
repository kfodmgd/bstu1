#include <iostream>//3.Вычислить выражение в правой части, используя рекурсию.(корень из 1+(n+1)*корень из 1+(n+2)...корень из 1+(n+n))
using namespace std;

float zn = 1,pr=0,cur=0;

int x(float n,float k) {
	if (n == 0) {
		return zn;
	}
	pr = n + k;
	cur = n + k-1;
	zn *= sqrt(1+n+k);
	x(n-1,k);
	return zn;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float a,zn,k;
	cout << "Введите число:" << endl;
	cin >> a;
	k = a;
	zn = x(a,k);
	cout << "Значние выражения=" << zn;
	return 0;
}
