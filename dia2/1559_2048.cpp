#include <bits/stdc++.h>

using namespace std;

int main() {
  int testes = 0;
  cin >> testes;

  while (testes) {
    testes--;
    int m[4][4];
    bool formo_2048 = false;

    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        cin >> m[i][j];
        if (m[i][j] == 2048) {
          formo_2048 = true;
        }
      }

    //              DOWN,  LEFT RIGHT  UP
    const int cl[] = {1,   0,     0,   -1};
    const int cc[] = {0,   -1,    1,   0};
    const string direcciones[] = {"DOWN", "LEFT", "RIGHT", "UP"};

    bool resp[4] = {false, false, false, false};

    for (int d = 0; d < 4; d++) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if ((i + cl[d] >= 0 && i + cl[d] < 4 &&
               j + cc[d] >= 0 && j + cc[d] < 4 &&
               m[i][j] != 0) &&
              (m[i+cl[d]][j+cc[d]] == 0 ||
               m[i+cl[d]][j+cc[d]] == m[i][j])) {
            resp[d] = true;
          }
        }
      }
    }

    bool primera = true;

    for (int d = 0; d < 4; d++) {
      if (!formo_2048 && resp[d]) {
        if (!primera) {
          cout << " ";
        }
        cout << direcciones[d];
        primera = false;
      }
    }

    if (primera) {
      cout << "NONE";
    }

    cout << "\n";
  }

  return 0;
}













