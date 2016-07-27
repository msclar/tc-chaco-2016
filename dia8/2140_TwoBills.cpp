#include <iostream>
using namespace std;

int main () {
	int bills[6] = {2, 5, 10, 20, 50, 100};
	
	int n, m, vuelto, CANT_BILLS = 6;
	bool posible;

	while ((cin >> n >> m) && !(n == 0 || m == 0)) {
		vuelto = m - n;
		posible = false;
		for (int i = 0; i < CANT_BILLS; i++) {
			for (int j = 0; j < CANT_BILLS; j++) {
				if (bills[i] + bills[j] == vuelto && i != j)
					posible = true;
			}
		}

		if (posible)
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
	}
}
