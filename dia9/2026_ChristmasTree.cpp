#include <iostream>
using namespace std;

int main () {
	int t, p, w;
	int e[101], pc[101], dp[101][1001];
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> p >> w;

		for (int i = 0; i < p; i++) {
			cin >> e[i] >> pc[i];
			dp[i][0] = 0;
		}

		for (int j = 0; j < w; j++)
			dp[0][j] = e[0] * (j >= pc[0]);

		for (int i = 1; i < p; i++) {
			for (int j = 0; j <= w; j++) {
				dp[i][j] = dp[i-1][j];

				if (j >= pc[i])			
					dp[i][j] = max (dp[i][j], dp[i-1][j-pc[i]] + e[i]);
			}
		}
		cout << "Galho " << tc << ":" << endl;
		cout << "Numero total de enfeites: " << dp[p-1][w] << endl << endl;
	}
}
