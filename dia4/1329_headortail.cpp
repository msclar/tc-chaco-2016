#include <iostream>
using namespace std;

int main () {
	int n, a;
	int res[2];
	while (cin >> n) {
		if (n == 0)
			break;

		res[0] = 0;
		res[1] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			res[a]++;
		}

		cout << "Mary won " << res[0] << " times and John won " << res[1] << " times" << endl;
	}
}
