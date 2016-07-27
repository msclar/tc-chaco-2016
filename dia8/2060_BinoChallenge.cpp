#include <iostream>
using namespace std;

int main () {
	int n, aux, mult[6] = {0, 0, 0, 0, 0, 0};
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> aux;
		for (int div = 2; div <= 5; div++) {
			if (aux % div == 0)
				mult[div]++;
		}
	}

	for (int div = 2; div <= 5; div++) {
		cout << mult[div] << " Multiplo(s) de " << div << endl;	
	}
	
}
