#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
    const int l = 100, n = 100;
	int i, j, player, str, stol,vert,goriz;
	char fir, sec, A[l][n];
    string a, b, s;
    a = "крестики";
    b = "нолики";
    cout << "Введите размер поля"<<endl<<"Количество строк ";
    cin >> goriz;
    cout << "Количество столбцов";
    cin >> vert;
    cout << "Кто ходит первым? 1-крестики 2-нолики";
    cin >> player;
	fir = 'X';
	sec = 'O';
	for (i = 0; i < goriz; i++) {
		for (j = 0; j < vert; j++) {
			A[i][j] = '?';
			cout << A[i][j]<<" ";
		}
		cout << endl;
	}

    for (int i = 0; i < (goriz*vert); i++){
        if ((!(i % 2)) && (player == 1)) { s = a; }//рассматриваем 2 случая когда у нас ходит первым крестик и когда первым нолик
        if ((!(i % 2)) && (player == 2)) { s = b; }
        if ((i % 2) && (player == 1)) { s = b; }
        if ((i % 2) && (player == 2)) { s = a; }
    mylabel:
        cout << "Сделайте ваш ход (" << s << ")" << endl;
        cout << "Строка: ";
        cin >> str;
        cout << "Столбец: ";
        cin >> stol;
        str--;
        stol--;
        if (A[str][stol] != '?'){/*вариант если мы вырбали строку которая занята*/
            system("cls");
            for (int i = 0; i < goriz; i++){
                for (int j = 0; j < vert; j++){
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Данная позиция занята!" << endl;
            goto mylabel;
        }
        if ((!(i % 2)) && (player == 1)) { A[str][stol] = fir; }/*строка если мы выбрали позицию пустую*/
        if ((!(i % 2)) && (player == 2)) { A[str][stol] = sec; }
        if ((i % 2) && (player == 1)) { A[str][stol] = sec; }
        if ((i % 2) && (player == 2)) { A[str][stol] = fir; }
        system("cls");/*перепись поля на пустой*/

        for (int i = 0; i < goriz; i++){
            for (int j = 0; j < vert; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < goriz; i++) {
            for (int j = 0; j < vert; j++) {
                if (A[i][j] == 'X' && A[i][j - 1] == 'X' && A[i][j + 1] == 'X' ||
                    A[i][j] == 'X' && A[i - 1][j] == 'X' && A[i + 1][j] == 'X' ||
                    A[i][j] == 'X' && A[i + 1][j + 1] == 'X' && A[i - 1][j - 1] == 'X' ||
                    A[i][j] == 'O' && A[i][j - 1] == 'O' && A[i][j + 1] == 'O' ||
                    A[i][j] == 'O' && A[i - 1][j] == 'O' && A[i + 1][j] == 'O' ||
                    A[i][j] == 'O' && A[i + 1][j + 1] == 'O' && A[i - 1][j - 1] == 'O')
                {

                    cout << "Игра закончена! ";
                    if ((A[str][stol] == fir) && (player == 1)) cout << fir << " победили!" << endl;
                    if ((A[str][stol] == sec) && (player == 2)) cout << sec << " победили!" << endl;
                    if ((A[str][stol] == sec) && (player == 1)) cout << sec << " победили!" << endl;
                    if ((A[str][stol] == fir) && (player == 2)) cout << fir << " победили!" << endl;
                    return 0;
                }
            }
        }
    }
	return 0;
}