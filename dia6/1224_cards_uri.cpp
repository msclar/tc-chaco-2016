#include <iostream>
#include <algorithm>
using namespace std;

long long int mejor[10001][2], sumaPrefijo[10001], cartaActual;
int main () {
	/* mejor(i, j) va a ser la opcion de mayor suma que tengo si me toca jugar y el intervalo es (i, j)
	   Puedo sacar i o sacar j, y en funcion de eso le dejo la jugada al otro. Quiero minimizar la suma del otro,
	   que como hay solo dos jugadores es lo mismo que maximizar la mia.
	
	   mejor(i, j) = max((sumaIntervalo[i][j-1] - mejor(i, j-1)) + cards[j],
			     (sumaIntervalo[i+1][j] - mejor(i+1, j)) + cards[i])
		       = sumaIntervalo[i][j] - min(mejor(i, j-1), mejor(i+1, j))
		       = sumaPrefijo[j] - sumaPrefijo[i-1] - min(mejor(i, j-1), mejor(i+1, j))

 	   Al final quiero mejor(0, n).

	   Ahora, el juez no lo acepta con memoria cuadratica, entonces necesitamos mejorar la cantidad de memoria
           que utilizamos. Notemos que si k = j - i, al momento de calcular cualquier intervalo de longitud k
	   solo uso calculos sobre intervalos de longitud k-1. Asi, solo utilizamos dos filas de memoria. Este es
           el k%2 y (k+1)%2 que se observa: referencia a que fila estamos tratando (si es la actual o la anterior).
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
			mejor[i][0] = sumaPrefijo[i] - sumaPrefijo[i-1]; // = cards[i]
		}

		/* ESTO ESTA MAL PUES RECORRE LA MATRIZ EN UN MAL ORDEN (mejor[i+1][j] no esta calculado)
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				mejor[i][j] = sumaPrefijo[j] - sumaPrefijo[i-1] - min(mejor[i][j-1], mejor[i+1][j]);
			}
		}
		*/

		// Lleno ordenandome por la longitud del intervalo k = j - i >= 1
		for (int k = 1; k < n; k++) {
			mejor[0][k%2] = sumaPrefijo[k] - min(mejor[0][(k+1)%2], mejor[1][(k+1)%2]);			
			for (int i = 1; i < n - k; i++) {
				mejor[i][k%2] = sumaPrefijo[k+i] - sumaPrefijo[i-1] - min(mejor[i][(k+1)%2], mejor[i+1][(k+1)%2]);
			}
		}

		cout << mejor[0][(n-1)%2] << endl;
	}
}
