#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 5;

int main () {
	int t, mat[MAX_N][MAX_N];
	bool visitado[MAX_N][MAX_N];

	int dirx[4] = {1, 0, -1, 0};
	int diry[4] = {0, 1,  0, -1};

	cin >> t;
	queue< pair<int,int> > cola;
	for (int tc = 0; tc < t; tc++) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				cin >> mat[i][j];
				visitado[i][j] = false;
			}
		}

		if (mat[0][0] == 0) {
			cola.push(make_pair(0,0));			
			visitado[0][0] = true;
		}

		while (!cola.empty()) {
			pair<int, int> actual = cola.front();
			cola.pop();
			
			for (int d = 0; d < 4; d++) {
				int actx = actual.first + dirx[d];
				int acty = actual.second + diry[d];
				if (actx >= 0 && actx < MAX_N &&
				    acty >= 0 && acty < MAX_N &&
				    mat[actx][acty] == 0 &&
				    !visitado[actx][acty]) {
					cola.push(make_pair(actx, acty));
					visitado[actx][acty] = true;
				}
			}
		}

		if (visitado[MAX_N-1][MAX_N-1]) {
			cout << "COPS" << endl;
		}
		else {
			cout << "ROBBERS" << endl;
		}
	}
}
