#include <iostream>
#include <queue>
using namespace std;

int componente[2001], n, m;
bool vecinos[2001][2001];
const int INF = 1000000000;

bool bfs () {
	bool posible = true;
	for (int i = 0; i < n; i++)
		componente[i] = INF;

	queue<int> cola;
	cola.push(0);
	componente[0] = 0;

	while (!cola.empty()) {
		int t = cola.front();
		cola.pop();

		for (int i = 0; i < n; i++) {
			if (vecinos[t][i] && componente[i] == INF) {
				componente[i] = 0;
				cola.push(i);
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (componente[i] == INF)
			posible = false;

	return posible;
}

int main () {
	int v, w, p;
	while ((cin >> n >> m) && !(n == 0 && m == 0)) {
		// limpio la matriz de vecinos
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				vecinos[i][j] = false;

		// armo la matriz de adyacencias
		for (int i = 0; i < m; i++) {		
			cin >> v >> w >> p;
			v--; w--;
			vecinos[v][w] = true;
		
			if (p == 2)
				vecinos[w][v] = true;
		}

		bool posible = bfs();

		// veo si desde 0 puedo llegar a todos los demas con el grafo invertido
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				swap(vecinos[i][j], vecinos[j][i]);
		
		posible = posible && bfs();

		cout << posible << endl;
	}
}
