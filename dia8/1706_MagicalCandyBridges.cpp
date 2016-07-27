#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

int componente[1001], cantNegros[1001];
char torre[1001];

void marcarComponente (vector<vector<int> > &listaVecinos, int nodoActual, int compActual) {
	queue<int> cola;
	cola.push(nodoActual);
	componente[nodoActual] = compActual;

	while (!cola.empty()) {
		int t = cola.front();
		cola.pop();

		for (int i = 0; i < (int) listaVecinos[t].size(); i++) {
			if (componente[listaVecinos[t][i]] == INF) {
				componente[listaVecinos[t][i]] = compActual;
				cola.push(listaVecinos[t][i]);
			}
		}
	}
}

int main () {
	int m, n, a, b;
	while (cin >> n >> m) {
		vector<vector<int> > listaVecinos(n);

		// leo notas iniciales de cada torre
		for (int i = 0; i < n; i++) {
			cin >> torre[i];
			componente[i] = INF;
			cantNegros[i] = 0;
		}

		// leo vecindades
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a--; b--;

			listaVecinos[a].push_back(b);
			listaVecinos[b].push_back(a);
		}

		// marco componentes conexas
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (componente[i] == INF) {
				marcarComponente(listaVecinos, i, c);
				c++;
			}
		}

		// cuento paridad por vecindades
		for (int i = 0; i < n; i++)
			if (torre[i] == 'B')
				cantNegros[componente[i]]++;

		// veo si todos los negros son pares (si no, es imposible)
		bool posible = true;
		for (int i = 0; i < c; i++) {
			if (cantNegros[i] % 2 == 1) {
				posible = false;
				break;			
			}
		}

		if (posible)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
