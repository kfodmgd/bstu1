#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a;
	cout << "Привет, видел новый кинотеатр?(1-да, 2-нет)";
	cin >> a;
	switch (a) {
	case 1: {cout << "Отлично! Какие фильмы там есть?(1-назвать фильмы, 2-я не знаю)";
		cin >> a;
		switch (a) {
		case 1:cout << "Давай сходим на один из них"; break;
		case 2:cout << "Давай посмотрим и выберем что-нибудь"; break;
		}break;
	}
	case 2:cout << "Самое время туда сходить!"; break;
	}
	return 0;
}