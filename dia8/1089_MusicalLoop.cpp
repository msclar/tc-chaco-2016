#include <iostream>
using namespace std;

int a[10001];
int main () {
	int n;
	while ((cin >> n) && n != 0) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		a[0] = a[n];
		a[n+1] = a[1];

		int res = 0;
		for (int i = 1; i <= n; i++) {
			if ((a[i] > a[i-1] && a[i] > a[i+1]) ||
			    (a[i] < a[i-1] && a[i] < a[i+1]))
					res++;
		}
		cout << res << endl;
	}
}
