#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, s, i, p;
	float ost,k,y;
	ost = 0;
	k = 0;
	cout << "¬ведите кол-во лет ";
	cin >> n;
	cout << "введите процент на который оборудование ежегодно уцениваетс€ ";
	cin >> p;
	cout << "¬ведите стоимость на которую было закуплено оборудование ";
	for (i = 1; i <= n; i++) {
		cin >> s;
		y = s * p/100;
		ost = s - y;
		k = k + ost;
		cout << "Ѕыло уценено "<<y<<"\n";
	}
	cout << k;
	return 0;
}