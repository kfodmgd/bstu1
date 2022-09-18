#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a;
	cout << "Привет, ты не хочешь сходить сегодня куда-нибудь?(1-да, 2-нет)";
	cin >> a;
	switch (a) {
	case 1: {cout << "Куда бы ты хотел сходить?(1-Парк, 2-Кино, 3-Театр, 4-Музей)";
		cin >> a;
		switch (a) {
		case 1:cout << "Дышать свежим воздухом полезно"; break;
		case 2:cout << "Отлично, как раз вышел новый фильм"; break;
		case 3:cout << "Никогда там не была, думаю будет интересно"; break;
		case 4:cout << "Отличный выбор, обожаю музеи"; break;
		}break;
	}
	case 2:cout << "Очень жаль, надеюсь в следующий раз выйдет"; break;
	}
	return 0;
}