#include <iostream>
#include <algorithm>
using namespace std;

long long int mejor[10001][10001], sumaPrefijo[10001], cartaActual;
int main () {
	/* ATENCION: ESTE CODIGO UTILIZA DEMASIADA MEMORIA Y DA WRONG ANSWER

	   mejor(i, j) va a ser la opcion de mayor suma que tengo si me toca jugar y el intervalo es (i, j)
	   Puedo sacar i o sacar j, y en funcion de eso le dejo la jugada al otro. Quiero minimizar la suma del otro,
	   que como hay solo dos jugadores es lo mismo que maximizar la mia.
	
	   mejor(i, j) = max((sumaIntervalo[i][j-1] - mejor(i, j-1)) + cards[j],
			     (sumaIntervalo[i+1][j] - mejor(i+1, j)) + cards[i])
		       = sumaIntervalo[i][j] - min(mejor(i, j-1), mejor(i+1, j))
		       = sumaPrefijo[j] - sumaPrefijo[i-1] - min(mejor(i, j-1), mejor(i+1, j))

 	   Al final quiero mejor(0, n).
	*/

	int n;
	while (cin >> n) {
		cin >> cartaActual;
		sumaPrefijo[0] = cartaActual;
		for (int i = 1; i < n; i++) {
			cin >> cartaActual;
			sumaPrefijo[i] = sumaPrefijo[i-1] + cartaActual;
		}

		mejor[0][0] = sumaPrefijo[0];
		for (int i = 1; i < n; i++) {
			mejor[i][i] = sumaPrefijo[i] - sumaPrefijo[i-1]; // = cards[i]
		}

		/* ESTO ESTA MAL PUES RECORRE LA MATRIZ EN UN MAL ORDEN (mejor[i+1][j] no esta calculado)
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				mejor[i][j] = sumaPrefijo[j] - sumaPrefijo[i-1] - min(mejor[i][j-1], mejor[i+1][j]);
			}
		}
		*/

		// Lleno ordenandome por la longitud del intervalo k = j - i >= 1
		for (int k = 1; k < n; k++) {
			mejor[0][k] = sumaPrefijo[k] - min(mejor[0][k-1], mejor[1][k]);			
			for (int i = 1; i < n - k; i++) {
				mejor[i][k+i] = sumaPrefijo[k+i] - sumaPrefijo[i-1] - min(mejor[i][k+i-1], mejor[i+1][k+i]);
			}
		}

		cout << mejor[0][n-1] << endl;
	}
}
