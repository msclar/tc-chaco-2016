#include <iostream>
#include <algorithm>
using namespace std;

int men[1001], women[1001];
int main () {
	int t, n;

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> men[i];

		for (int i = 0; i < n; i++)
			cin >> women[i];

		sort(men, men + n);
		sort(women, women + n);

		long long int res = 0;
		for (int i = 0; i < n; i++) 
			res += men[i] * women[i];
	
		cout << res << endl;
	}
}
