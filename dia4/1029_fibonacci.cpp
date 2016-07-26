#include <iostream>
using namespace std;

int main () {
	int n, a, b;
	string str;

	int fib[64], rec[64];
	fib[0] = 0;
	fib[1] = 1;

	rec[0] = 0;
	rec[1] = 0;

	for (int i = 2; i < 40; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		rec[i] = rec[i-1] + rec[i-2] + 2;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cout << "fib(" << a << ") = " << rec[a] << " calls = " << fib[a] << endl;
	}
}

