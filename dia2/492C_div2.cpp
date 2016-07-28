#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	/* Hallar min puntosAPedir tal que (sumaNotas + puntosAPedir) / n >= avg
	   puntosAPedir >= n * avg - sumaNotas */

	pair<int, int> examenes[100001];
	long long int n, r, avg, a, b, sumaNotas = 0, puntosAPedir, trabajosRealizados = 0;

	cin >> n >> r >> avg;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sumaNotas += a;

		examenes[i] = make_pair(b, a);
	}
	puntosAPedir = n * avg - sumaNotas;

	sort(examenes, examenes + n);

	int proximo = 0;
	while (puntosAPedir > 0) {
		long long int puntosSubidos = min((long long) r - examenes[proximo].second, puntosAPedir);		

		puntosAPedir -= puntosSubidos;
		trabajosRealizados += puntosSubidos * examenes[proximo].first;

		if (examenes[proximo].second + puntosSubidos == r)
			proximo++;
	}
	cout << trabajosRealizados << endl;
}
