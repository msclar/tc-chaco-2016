#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];
int main () {
	int n, r;
	while (cin >> n >> r) {
		for (int i = 0; i < r; i++) {
			cin >> a[i];
		}
		sort(a, a+r);

		int x = 0;
		for (int i = 1; i <= n; i++) {
			if (x < r && i == a[x]) {
				x++;
			}
			else {
				cout << i << " ";
			}
		}

		if (n == r) {
			cout << "*";
		}
		cout << endl;
	}
}
