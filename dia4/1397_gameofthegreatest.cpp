#include <iostream>
using namespace std;

int main () {
	int n, won[2], a, b;
	while (cin >> n) {
		if (n == 0)
			break;

		won[0] = 0;
		won[1] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;

			if (a > b) {
				won[0]++; 
			}
			else if (a < b) {
				won[1]++;
			}
		}
		cout << won[0] << " " << won[1] << endl;
	}
}
