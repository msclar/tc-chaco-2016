#include <bits/stdc++.h>

using namespace std;

bool valid(string &s, int i, int j) {
  int sz = j - i + 1;
  if (sz % 3)
    return true;
  sz /= 3;

  for (int k = 0; k < sz; k++) {
    if (s[i+k] != s[i+k+sz] || s[i+k+sz] != s[i+k+2*sz] ||
        s[i+k] == '*' || s[i+k+sz] == '*' || s[i+k+2*sz] == '*')
      return true;
  }

  return false;
}

bool valid(string &s, int j = -1) {
  if (j == -1)
    j = (int)s.size();
  for (int i = 0; i < j; i++) {
    if (!valid(s, i, j-1)) {
      return false;
    }
  }
  return true;
}

int backtracking(string &s, int i) {
  if (!valid(s, i))
    return 0;

  if (i == s.size())
    return 1;
  if (s[i] == '*') {
    s[i] = '1';
    int q = backtracking(s, i+1);
    s[i] = '0';
    q += backtracking(s, i+1);
    s[i] = '*';
    return q;
  } else {
    return backtracking(s, i+1);
  }
}

int main() {
  int n, tc = 1;
  string s;

  while (cin >> n >> s && n) {
    cout << "Case " << (tc++) << ": " << backtracking(s, 0) << endl;
  }

  return 0;
}
