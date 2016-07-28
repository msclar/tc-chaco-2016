#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int main () {
	int n;
	while ((cin >> n) && n != 0) {
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int maximo = -1, segundoMaximo = -1, res = -1;
		for (int i = 0; i < n; i++)
			maximo = max (maximo, a[i]);

		for (int i = 0; i < n; i++) {
			if (maximo != a[i] && segundoMaximo < a[i]) {
				segundoMaximo = a[i];
				res = i;
			}
		}
		cout << res+1 << endl;
	}
}
