#include <iostream>
using namespace std;

int dp[100001], arr[100001];
int main () {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// dp[i] = el orden es valido si el archivo empieza en el indice i
	// dp[i] = dp[i+arr[i]] es valido

	dp[n] = true; // no tener nada es valido
	for (int i = n-1; i >= 0; i--) {
		dp[i] = (i + arr[i] <= n) && dp[i+arr[i]+1];
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i]) {
			cout << i << endl;
		}
	}
}
