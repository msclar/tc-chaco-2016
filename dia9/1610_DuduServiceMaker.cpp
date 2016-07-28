#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main () {
	// Esta implementación es un Topological Sort del grafo
	// Otra opción sería hacer un DFS

	int t, a, b, n, m;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;

		vector<set<int> > out(n);
		vector<set<int> > in(n);
		
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a--; b--;
			out[a].insert(b);
			in[b].insert(a);
		}

		queue<int> colaVacios;
		for (int i = 0; i < n; i++)
			if (in[i].size() == 0)
				colaVacios.push(i);

		int analizados = 0;
		while (!colaVacios.empty()) {
			int t = colaVacios.front();
			colaVacios.pop();
			analizados++;

			for (std::set<int>::iterator it=out[t].begin(); it!=out[t].end(); ++it) {
				in[*it].erase(t);
				if (in[*it].size() == 0)
					colaVacios.push(*it);
			}
		}

		if (analizados == n)
			cout << "NAO" << endl;
		else
			cout << "SIM" << endl;
	}
}
