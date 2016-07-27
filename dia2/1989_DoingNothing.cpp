#include <iostream>
using namespace std;

int main () {
	int n, m, arr[100001];
	while ((cin >> n >> m) && !(n == -1 && m == -1)) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		long long int res = 0;
		for (int i = 0; i < n; i++)
			res += arr[i] * (n - i);

		cout << res * m << endl;
	}
}
