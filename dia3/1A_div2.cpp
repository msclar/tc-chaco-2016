#include <iostream>
using namespace std;

int main () {
	long long int n, m, a;
	cin >> n >> m >> a;

	// cuenta: techo(n/a) * techo(m/a)
	cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
}
