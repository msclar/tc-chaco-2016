#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int b, n;

    while (cin >> b >> n && b) {
        int r[30];

        for (int i = 0; i < b; i++)
            cin >> r[i];

        bool possible = true;

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            r[a-1] -= c;
            r[b-1] += c;
        }

        for (int i = 0; i < b; i++)
            if (r[i] < 0)
                possible = false;

        cout << (possible ? 'S' : 'N') << '\n';
    }

    return 0;
}
