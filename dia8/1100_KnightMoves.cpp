#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 8;

int main () {
	string str[2];
	pair<int, int> pos[2];

	int dirx[] = {1, 2,  1, -2, -1,  2, -1, -2};
	int diry[] = {2, 1, -2,  1,  2, -1, -2, -1};

	bool visitado[MAX_N][MAX_N];
	int distancia[MAX_N][MAX_N];

	queue< pair<int,int> > cola;
	while (cin >> str[0] >> str[1]) {
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				visitado[i][j] = false;

		for (int i = 0; i < 2; i++) {
			pos[i] = make_pair(MAX_N - (str[i][1]- '0'), str[i][0] - 'a');
		}		

		visitado[pos[0].first][pos[0].second] = true;
		distancia[pos[0].first][pos[0].second] = 0;
		cola.push(pos[0]);

		while (!cola.empty()) {
			pair<int, int> actual = cola.front();
			cola.pop();

			for (int v = 0; v < 8; v++) {
				int nextx = actual.first + dirx[v];
				int nexty = actual.second + diry[v];
				if (0 <= nextx && nextx < MAX_N &&
				    0 <= nexty && nexty < MAX_N &&
				    !visitado[nextx][nexty]) {
					cola.push(make_pair(nextx, nexty));
					distancia[nextx][nexty] = distancia[actual.first][actual.second] + 1;				
					visitado[nextx][nexty] = true;
				}
			}
		}
		cout << "To get from " << str[0] << " to " << str[1] << " takes " << distancia[pos[1].first][pos[1].second] << " knight moves." << endl;
	}
}
