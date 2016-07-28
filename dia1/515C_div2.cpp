#include <iostream>
using namespace std;

int main () {
	int n;
	int res[4] = {0, 0, 0, 0}, fact[10][4];
	int num[4] = {2, 3, 5, 7};
	char c;
	
	fact[0][0] = 0;
	fact[0][1] = 0;
	fact[0][2] = 0;
	fact[0][3] = 0;
	for (int i = 1; i < 10; i++) {
		for (int d = 0; d < 4; d++) {			
			fact[i][d] = 0;			
			int aux = i;
			while (aux % num[d] == 0) {
				fact[i][d]++;
				aux /= num[d];
			}

			fact[i][d] += fact[i-1][d];
		}
		//cout << fact[i][0] << " " << fact[i][1] << " " << fact[i][2] << " " << fact[i][3] << endl;
	}

	//cout << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;

		for (int d = 0; d < 4; d++) {		
			res[d] += fact[c-'0'][d];
		}
		//cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
	}

	for (int k = 3; k >= 0; k--) {
		for (int i = 0; i < res[k]; i++) {
			cout << num[k];
			for (int j = 0; j < k; j++) {
				res[j] -= fact[num[k]][j];
			}
		}
	}
	cout << endl;
}
