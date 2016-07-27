#include <iostream>
using namespace std;

int main () {
	int n, aux, apariciones[2001];
	cin >> n;

	for (int i = 0; i <= 2001; i++) {
		apariciones[i] = 0;		
	}

	for (int i = 0; i < n; i++) {
		cin >> aux;
		apariciones[aux]++;		
	}

	for (int i = 0; i <= 2000; i++) {
		if (apariciones[i] > 0)
			cout << i << " aparece " << apariciones[i] << " vez(es)" << endl;		
	}
}
