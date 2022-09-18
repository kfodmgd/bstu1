#include <iostream>//Разработать программу, реали-зующую рекурсивную функцию подсчета количества x(m) разбие-ний натурального числа m в виде суммы натуральных чисел
using namespace std;

int i=1, num=0;

int x(int a) {
	if (a == 1) {
		return 1; 
	}
	i++;
	num++;
	if (num != a / 2) {
		x(a);
	}
	return i;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a,numb;
	cout << "Введите число"<<endl;
	cin >> a;
	numb = x(a);
	cout<<endl << "Колиество разложений числа" << numb;
	return 0;
}