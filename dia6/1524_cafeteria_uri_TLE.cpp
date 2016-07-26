#include <iostream>
using namespace std;

const int inf = 1500000000;
int main () {
	/* minSum(i, k) = minima suma de los grupos dado que hay k grupos en el intervalo [0..i)
	   minSum(n, k) = min_{a>0 && a <= n}{minSum(n-a, k-1) + distancia del grupo actual}
	   minSum(n, k) = min_{a>0 && a <= n}{minSum(n-a, k-1) + pos[n-1] - pos[n-a]}

           minSum(0, 0) = 0
	   minSum(i, 0) = inf si i > 0
	*/

	int minSum[1001][1001], pos[1001], n, k;

	while (cin >> n >> k) {
		pos[0] = 0;
		for (int i = 1; i < n; i++) {
			cin >> pos[i];
		}

		for (int i = 1; i < n; i++) {
			minSum[i][0] = inf;
			minSum[0][i] = inf;	
		}
		minSum[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i && j <= k; j++) {
				minSum[i][j] = inf;
				for (int a = 1; a <= i; a++) {
					minSum[i][j] = min(minSum[i][j], minSum[i-a][j-1] + pos[i-1] - pos[i-a]);
					// cout << i << " " << j << " " << a << " " << minSum[i][j] << endl;
				}
				// cout << "minSum " << i << " " << j << " " << minSum[i][j] << endl;
			}
		}

		cout << minSum[n][k] << endl;
	}
	return 0;
}
