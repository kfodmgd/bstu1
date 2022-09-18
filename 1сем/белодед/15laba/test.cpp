#include<iostream>
using namespace std;
void ii(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = a[i][j] + i;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = i; 
            ii(a, n);
        }
    }
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}