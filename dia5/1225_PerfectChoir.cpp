#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  while (cin >> n) {
    vector<int> v(n);
    int s = 0;

    for (int i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
    }

    if (s % n != 0) {
      cout << "-1\n";
    } else {
      int k = s / n;
      int resp = 0;

      for (int i = 0; i < n; i++) {
        resp += abs(v[i] - k);
      }

      cout << (1 + resp/2) << '\n';
    }
  }

  return 0;
}












