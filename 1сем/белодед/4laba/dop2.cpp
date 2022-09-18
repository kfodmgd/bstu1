#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int a;
	cout << "Привет, не хотел бы присоединиться к нашему клубу литературы?(1-да, 2-нет)";
	cin >> a;
	switch (a) {
	case 1: {cout << "Правда? Я рада. Ты предпочитаешь мангу или классическую литературу?(1-манга, 2-классика)";
		cin >> a;
		switch (a) {
		case 1:cout << "Манга тоже литература! Добро подаловать в клуб!"; break;
		case 2:cout << "Не плохо. Добро пожаловать в клуб!"; break;
		}break;
	}
	case 2:cout << "Очень жаль, надеюсь ты найдёшь то, что будет тебе по душе..."; break;
	}
	return 0;
}