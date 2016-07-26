#include <iostream>
using namespace std;

int main () {
	int t, pa, pb;
	double g1, g2;

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> pa >> pb >> g1 >> g2;
		
		int anos = 0;
		while (pa <= pb && anos <= 100) {
			anos++;
			pa += pa * g1 / 100;
			pb += pb * g2 / 100;
		}

		if (anos > 100) {
			cout << "Mais de 1 seculo." << endl;
		}
		else {
			cout << anos << " anos." << endl;
		}
	}
}
