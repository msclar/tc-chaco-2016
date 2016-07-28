#include <iostream>
using namespace std;

int main () {
	// 2^n - 1 grains
	// (2^n - 1) / 12 grams
	// (2^n - 1) / 12000 kilograms

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		unsigned long long int potenciaMenosUno = (((1ULL << (x-1)) - 1) << 1) + 1;
		cout << potenciaMenosUno / 12000 << " kg" << endl;
	}
}
