#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);    
    double d, vf, vg;

    while (cin >> d >> vf >> vg)
        cout << (hypot(12, d) / vg <= 12 / vf + 1e-9 ? 'S' : 'N') << '\n';

    return 0;
}
