#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[500001];
int main () {
	int n;
	cin >> n;

	long long int suma = 0LL, prefijo = 0, sufijo = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		suma += a[i];
	}

	if (suma % 3 != 0) {
		cout << 0 << endl;		
		return 0;	
	}
	suma /= 3;

	vector<int> prefijosBuenos, sufijosBuenos;

	for (int i = 0; i < n; i++) {
		prefijo += a[i];
		if (prefijo == suma) {
			prefijosBuenos.push_back(i);
		}
	}

	for (int i = n-1; i >= 0; i--) {
		sufijo += a[i];
		if (sufijo == suma) {
			sufijosBuenos.push_back(i);
		}
	}

	sort(prefijosBuenos.begin(), prefijosBuenos.end());
	sort(sufijosBuenos.begin(), sufijosBuenos.end());

	long long int res = 0;
	for (int i = 0; i < (int) prefijosBuenos.size(); i++) {
		// prefijo + 1 < sufijo (no pueden ser indices consecutivos, si no la seccion del medio es vacia)		
		res += sufijosBuenos.end() - upper_bound(sufijosBuenos.begin(), sufijosBuenos.end(), (int) prefijosBuenos[i]+1); 
	}
	cout << res << endl;
}
