#include <iostream>
using namespace std;
void main() {
    double t, u, k = 4, a = 8.1, x = 2e-4;
    t = 2 * k / a + log(2 + x);
    u = sqrt(k - 1) / (t + 1);
    cout << "t=" << t << "\n";
    cout << "u=" << u;
}