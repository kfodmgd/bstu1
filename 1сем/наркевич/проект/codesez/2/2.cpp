#include <iostream>
#include <Windows.h>
using namespace std;
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int c = 100;
	char a[c],rez[c];
	int k, b, len,rot;
	cout << "введите строку ";
	cin.getline(a, 100);
	cout << "ROT ";
	cin >> rot;
	cout << "язык 1-англ, 2-рус ";
	cin >> k;
	len = strlen(a);

	if (rot == 0) {
		cout << "Ты дурак? тебе вообще сдвигать надо или нет?";
		return 0;
	}

	switch (k) {
	case 1:
		if (rot > 0) {
			for (int i = 0; i < len; i++) {
				if ((int)a[i] + rot >= 122 && (int)a[i] <= 122 && (int)a[i] >= 97) {
					int l = (int)a[i] + rot - 122;
					rez[i] = 96 + l;
					cout << rez[i];
				}

				if ((int)a[i] + rot >= 90 && (int)a[i] <= 90 && (int)a[i] >= 65) {
					int l = (int)a[i] + rot - 90;
					rez[i] = 64 + l;
					cout << rez[i];
				}

				if ((int)a[i] <= 90 && (int)a[i] >= 65 && (int)a[i] + rot <= 90 || (int)a[i] <= 122 && (int)a[i] >= 97 && (int)a[i] + rot <= 122) {
					rez[i] = (int)a[i] + rot;
					cout << rez[i];
				}
			}
		}
		if (rot < 0) {
			for (int i = 0; i < len; i++) {
				if ((int)a[i] + rot < 97 && (int)a[i] <= 122 && (int)a[i] >= 97) {
					int l = 96 - ((int)a[i] + rot);
					rez[i] = 122 - l;
					cout << rez[i];
				}
				if ((int)a[i] + rot < 65 && (int)a[i] <= 90 && (int)a[i] >= 65) {
					int l = 64 - ((int)a[i] + rot);
					rez[i] = 90 - l;
					cout << rez[i];
				}
				if ((int)a[i] <= 90 && (int)a[i] >= 65 && (int)a[i] + rot <= 90 && (int)a[i] + rot >= 65 || (int)a[i] <= 122 && (int)a[i] >= 97 && (int)a[i] + rot <= 122 && (int)a[i] + rot >= 97) {
					rez[i] = (int)a[i] + rot;
					cout << rez[i];
				}
			}
		}
		break;
	case 2:
		cout << "буквы ё и Ё не учитываются" << endl;
		if (rot > 0) {
			for (int i = 0; i < len; i++) {
				if ((int)a[i] + rot >= -1 && (int)a[i] >= -32 && (int)a[i] <= -1) {
					int l = (int)a[i] + rot + 1;
					rez[i] = -33 + l;
					cout << rez[i];
				}

				if ((int)a[i] + rot >= -33 && (int)a[i] >= -64 && (int)a[i] <= -33) {
					int l = (int)a[i] + rot + 33;
					rez[i] = -65 + l;
					cout << rez[i];
				}

				if ((int)a[i] >= -64 && (int)a[i] <= -33 && (int)a[i] + rot <= -33 || (int)a[i] >= -32 && (int)a[i] <= -1 && (int)a[i] + rot <= -1) {
					rez[i] = (int)a[i] + rot;
					cout << rez[i];
				}
			}
		}
		if (rot < 0) {
			for (int i = 0; i < len; i++) {
				if ((int)a[i] + rot < -32 && (int)a[i] >= -32 && (int)a[i] <= -1) {
					int l = (int)a[i] + rot + 32;
					rez[i] = l;
					cout << rez[i];
				}
				if ((int)a[i] + rot < -64 && (int)a[i] >= -64 && (int)a[i] <= -33) {
					int l = (int)a[i] + rot + 64;
					rez[i] = -32 + l;
					cout << rez[i];
				}
				if ((int)a[i] >= -64 && (int)a[i] <= -33 && (int)a[i] + rot <= -33 && (int)a[i] + rot >= -64 || (int)a[i] >= -32 && (int)a[i] <= -1 && (int)a[i] + rot <= -1 && (int)a[i] + rot >= -32) {
					rez[i] = (int)a[i] + rot;
					cout << rez[i];
				}
			}
		}
		break;
	}
	return 0;
}
