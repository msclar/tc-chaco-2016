#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int n, l, pos[1001];
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	sort(pos, pos+n);

	double maxDist = pos[0]; // distancia desde la primera lantern al comienzo
	for (int i = 1; i < n; i++) {
		maxDist = max (maxDist, (pos[i] - pos[i-1]) / 2.0);	
	}
	maxDist = max (maxDist, (double) (l - pos[n-1]));
	
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << maxDist << endl;
}
