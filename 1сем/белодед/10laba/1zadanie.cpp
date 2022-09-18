#include <iostream>//кол-во нулей
#include <stdlib.h>
using namespace std;
int main(){
	setlocale(LC_CTYPE, "Russian");
    unsigned int a;
    char b[32];
    char buffer[32];
    int k, c, b1, c1,n0,n1;
    k = 0;
    n0 = 0;
    n1 = 0;
    cout << "Введите значение ";
    cin >> a;
    while (a > 0) {
        if (a % 2 == 0) {
            n0++;
        }
        else {
            n1++;
        }
        a = a / 2;
    }
    cout <<"Количество нулей"<< n0;


    //unsigned int a;
    //char a1[32];
    //cin >> a;
    //_itoa_s(a, a1, 2);
    //cout << a1<<endl;
    //a = a << 1;
    //_itoa_s(a, a1, 2);
    //cout << a1;
    return 0;
}