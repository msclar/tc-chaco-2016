#include <iostream>
using namespace std;

int main () {
	int n, costo, aux;
	int gan[64];
		
	while (cin >> n) {
		cin >> costo;
		
		for (int i = 0; i < n; i++) {
			cin >> aux;
			gan[i] = aux - costo;		
		}		

		int sumaAct, mejorAct = 0;
		for (int i = 0; i < n; i++) {
			for (int f = i; f < n; f++) {
				sumaAct = 0;
				for (int d = i; d <= f; d++) {
					sumaAct += gan[d];
				}
				mejorAct = max(sumaAct, mejorAct);
			}
		}
		cout << mejorAct << endl;
	}
}
