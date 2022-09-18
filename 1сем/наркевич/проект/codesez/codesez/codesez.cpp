#include <iostream>
#include <Windows.h>
using namespace std;
int main(){
	const int c = 100;
	char str[100],rez[c];
	int rot,len,k;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*cout << "Введите строку для перевода ";
	cin.getline(str, 100); 	
	cout << "какой это язык? 1-русский 2-английский ";
	cin >> k;
	cout << "Введите ROT ";
	cin >> rot;
	len = strlen(str);
	if (rot == 0) {
		cout << "Ты дурак? тебе вообще сдвигать надо или нет?";
	}

	for (int i = 0; i < len; i++) {
		if ((int)str[i] < -32 && (int)str[i]>-1 || (int)str[i] < -64 && (int)str[i] > -33 || (int)str[i] < 97 && (int)str[i] > 122 || (int)str[i] < 65 && (int)str[i] > 90) {
			cout << "nope";
			return 0;
		}
	}

	switch(k) {
		case 1:
				for (int i = 0; i < len; i++) {
					rez[i] = (int)str[i] + rot;
					if ((int)str[i] == -1) {
						rez[i] = -33 + rot;
					}
					else
						if ((int)str[i] == -33) {
							rez[i] = -65 + rot;
						}
					cout << rez[i];
				}
			break;
		case 2:
			for (int i = 0; i < len; i++) {
				for (int i = 0; i < len; i++) {


					if ((int)str[i] + rot >= 90 && (int)str[i]<=90 && (int)str[i]>=65) {//big letters
						int l = (int)str[i] + rot;
						l = l - 90;
						rez[i] = 65 + l;
						cout << rez[i];
					}
					else if ((int)str[i] < 90 && (int)str[i] >= 65) {
						rez[i] = (int)str[i] + rot;
						cout << rez[i];
					}


					//rez[i] = (int)str[i] + rot;
					/*if ((int)str[i] == 90) {
						rez[i] = 64 + rot;
					}
					else
						if ((int)str[i] == 122) {
							rez[i] = 96 + rot;
						}*/
					//cout << rez[i];
				//}	
			//}
			//break;
	//}



	/*for (int i = 0; i < len; i++) {
		if ((int)str[i] < -32 && (int)str[i]>-1 || (int)str[i] < -64 || (int)str[i] > -33 || (int)str[i] > 97 || (int)str[i] < 122 || (int)str[i] > 65 || (int)str[i] < 90) {
			switch (k) {
			case 1:
				for (int i = 0; i < len; i++) {
					rez[i] = (int)str[i] + rot;
					if ((int)str[i] == -1) {
						rez[i] = -31 + rot;
					}
					else
						if ((int)str[i] == -33) {
							rez[i] = -65 + rot;
						}
					cout << rez[i];
				}
			case 2:
				for (int i = 0; i < len; i++) {
					rez[i] = (int)str[i] + rot;
					if ((int)str[i] == 90) {
						rez[i] = 64 + rot;
					}
					else
						if ((int)str[i] == 122) {
							rez[i] = 96 + rot;
						}
					cout << rez[i];
				}
			}
		}
	}*/

	cout << endl << endl;
	cout << ((int)'Z');
	return 0;
}