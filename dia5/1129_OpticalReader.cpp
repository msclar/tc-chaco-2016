#include <iostream>
using namespace std;

int main () {
	char letras[5] = {'A', 'B', 'C', 'D', 'E'};

	int n, aux;	
	while ((cin >> n) && n != 0) {
		for (int i = 0; i < n; i++) {		
			int respuesta = -1, negros = 0;
			for (int j = 0; j < 5; j++) {
				cin >> aux;
				if (aux <= 127) {
					negros++;
					respuesta = j;
				}
			}

			if (negros == 1)
				cout << letras[respuesta] << endl;
			else
				cout << "*" << endl;
		}
	}
}
