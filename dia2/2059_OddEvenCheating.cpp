#include <iostream>
using namespace std;

int main () {
	int p, j1, j2, r, a;
	cin >> p >> j1 >> j2 >> r >> a;

	int paridad = (j1 + j2) % 2;
	p = 1 - p; // para que p = 0 si eligio par y p = 1 si eligio impar

	// r = 1, a = 1 gana 2
	// r = 1, a = 0 gana 1
	// r = 0, a = 1 gana 1
	// r = 0, a = 0 es el juego normal

	if (r == a && (r == 1 || (r == 0 && paridad != p))) {
		cout << "Jogador 2 ganha!" << endl;
	}
	else {
		cout << "Jogador 1 ganha!" << endl;
	}
}
