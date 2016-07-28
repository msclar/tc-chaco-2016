#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int distancia[501][501], n, m;
char tablero[501][501];

int dirx[] = {1, -1,  0,  0};
int diry[] = {0,  0,  1, -1};

const int INF = 1e9;

pair<int, int> bfs (pair<int, int> nodoInicial) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			distancia[i][j] = INF;		

	queue< pair<int, int> > cola;
	cola.push(nodoInicial);
	distancia[nodoInicial.first][nodoInicial.second] = 0;

	int distanciaMaxima = 0;
	pair<int, int> nodoMasLejano;

	while (!cola.empty()) {
		pair<int, int> actual = cola.front();
		cola.pop();

		if (distanciaMaxima < distancia[actual.first][actual.second]) {
			distanciaMaxima = distancia[actual.first][actual.second];
			nodoMasLejano = actual;
		}

		for (int d = 0; d < 4; d++) {
			int nextx = actual.first + dirx[d];
			int nexty = actual.second + diry[d];
			if (0 <= nextx && nextx < n && 
				0 <= nexty && nexty < m &&
				tablero[actual.first][actual.second] == tablero[nextx][nexty] &&
				distancia[nextx][nexty] == INF) {
				cola.push(make_pair(nextx, nexty));
				distancia[nextx][nexty] = distancia[actual.first][actual.second] + 1;
			}
		}
	}
	return nodoMasLejano;
}

int main () {
	pair<int, int> nodoInicial;

	while ((cin >> n >> m) && !(n == 0 && m == 0)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tablero[i][j];
				if (tablero[i][j] == '.')
					nodoInicial = make_pair(i, j);
			}
		}

		pair<int, int> nodoMasLejano = bfs(nodoInicial);
		pair<int, int> nuevoNodoMasLejano = bfs(nodoMasLejano);

		cout << distancia[nuevoNodoMasLejano.first][nuevoNodoMasLejano.second] << endl;
	}
}
