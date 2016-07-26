#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, c;

  while (cin >> a >> c) {
    if (a == 0 && c == 0) {
      break;
    }

    int anterior = a, r = 0;

    for (int i = 0; i < c; i++) {
      int a_i;
      cin >> a_i;
      r += abs(a_i - anterior);
      anterior = a_i;
    }

    r += abs(anterior - a);


    cout << (r / 2) << '\n';
  }
}














