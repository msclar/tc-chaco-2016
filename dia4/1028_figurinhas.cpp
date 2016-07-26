#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}

int main () {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		cout << gcd(a, b) << endl;
	}
}
