#include <iostream>//13.Разработать программу, реализующую рекурсивную функцию подсчета количества всех положительных делителей натурального числа n.  
using namespace std;

int q = 1;

int dnx(int n, int x) {
	if (x == 1) {
		return q;
	}
	if ((n % x) == 0 && x>1) {
		q++;
		dnx(n, x - 1);
	}
	else {
		if ((n % x) != 0 && x > 1) {
			dnx(n, x - 1);
		}
	}
	return q;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int x,n,zn;
	cout << "Введите чиcло"<<endl;
	cin >> n;
	cout << "Введите число, до которого нужно считать делители натурального числа" << endl;
	cin >> x;
	zn=dnx(n, x);
	cout <<endl<< "Количество положительных делителей для введённого числа " << zn;
	return 0;
}