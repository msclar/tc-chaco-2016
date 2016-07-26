#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int n, a, b, c;
	cin >> n;

	int solved = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			solved++;
	}
	cout << solved << endl;
}
