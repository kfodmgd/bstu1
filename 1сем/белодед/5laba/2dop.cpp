#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, s, i, p;
	float ost,k,y;
	ost = 0;
	k = 0;
	cout << "������� ���-�� ��� ";
	cin >> n;
	cout << "������� ������� �� ������� ������������ �������� ����������� ";
	cin >> p;
	cout << "������� ��������� �� ������� ���� ��������� ������������ ";
	for (i = 1; i <= n; i++) {
		cin >> s;
		y = s * p/100;
		ost = s - y;
		k = k + ost;
		cout << "���� ������� "<<y<<"\n";
	}
	cout << k;
	return 0;
}