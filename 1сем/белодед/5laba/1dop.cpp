#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int q, i;
	float p, k;
	cout << "Введите на сколько тыс. руб. реализовано товара ";
	cin >> p;
	cout << "Введите заданную выручку ";
	cin>>q;
	k = 0.03;
	i = 1;
	while (q>=p) {
		p = p + k * p;
		k = k + 0.03;
		i = i + 1;
	}
	cout << "Первая выручка, превысившая значение q равна " << p <<"\n"<<"Это произойдёт на " << i<<" день";
	return 0;
}