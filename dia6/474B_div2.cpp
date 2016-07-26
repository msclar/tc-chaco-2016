#include <iostream>
using namespace std;

int main () {
	int pila[1000001], n, m, label, aux;
	cin >> n;

	int next = 1;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		for (int j = 0; j < aux; j++) {
			pila[next] = i + 1;
			next++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> label;
		cout << pila[label] << endl;
	}
}
