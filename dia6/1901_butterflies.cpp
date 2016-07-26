#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int especiesConocidas[401], pos[201][201], n, a, b;

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {			
				cin >> pos[i][j];
			}		
		}

		for (int i = 0; i < 2*n; i++) {
			cin >> a >> b;			
			especiesConocidas[i] = pos[a-1][b-1];
		}
		sort(especiesConocidas, especiesConocidas + 2*n);

		int res = 1;
		for (int i = 1; i < 2*n; i++) {
			if (especiesConocidas[i] != especiesConocidas[i-1])
				res++;
		}
		cout << res << endl;
	}
	return 0;
}
