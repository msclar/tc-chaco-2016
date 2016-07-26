#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int dif[1001], pos[1001], n, k, res;

	while (cin >> n >> k) {
		pos[0] = 0;
		for (int i = 1; i < n; i++) {
			cin >> pos[i];
			dif[i-1] = - pos[i] + pos[i-1];
		}
		sort(dif, dif+n-1);
		
		res = pos[n-1] - pos[0];
		for (int i = 0; i < k-1; i++) {
			res += dif[i];
		}
		cout << res << endl;
	}
	return 0;
}
