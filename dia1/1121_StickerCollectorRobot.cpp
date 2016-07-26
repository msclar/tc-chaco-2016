#include <iostream>

using namespace std;

char g[100][100];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int dir(char c) {
    switch(c) {
        case 'N': return 2;
        case 'S': return 0;
        case 'L': return 1;
        case 'O': return 3;
        default: return -1;
    }
}

int main() {

    int n, m, s;
    
    while (cin >> n >> m >> s && s) {
        cin >> ws;

        int r, c, d;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                if (dir(g[i][j]) != -1) {
                    r = i;
                    c = j;
                    d = dir(g[i][j]);
                }
            }
            cin >> ws;
        }

        int score = 0;

        for (int i = 0; i < s; i++) {
            char a;
            cin >> a;

            if (a == 'F') {
                int nr = r + dr[d],
                    nc = c + dc[d];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#') {
                    r = nr;
                    c = nc;
                }
                if (g[r][c] == '*') {
                    g[r][c] = '.';
                    score++;
                }
            }
            else {
                if (a == 'D')
                    d = (d + 3) % 4;
                else
                    d = (d + 1) % 4;
            }
        }

        cout << score << '\n';
    }

    return 0;
}
