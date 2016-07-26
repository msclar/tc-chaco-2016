#include <iostream>
using namespace std;

int main () {
	int n;
	while ((cin >> n) && n != -1) {
		int acum = 0, res = 0, aux;
		
		for (int i = 0; i < n; i++) {
			cin >> aux;			
			acum += aux;
			if (acum % 100 == 0)
				res++;
		}
		cout << res << endl;
	}
}
