#include <iostream>
using namespace std;

int main () {
	int t, n, lastNumber, nextNumber;
	char lastSuit, nextSuit;

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		bool shuffled = true;

		cin >> nextNumber >> nextSuit;
		for (int i = 1; i < n; i++) {
			lastNumber = nextNumber;
			lastSuit = nextSuit;
			cin >> nextNumber >> nextSuit;

			if (nextNumber == lastNumber || nextSuit == lastSuit) {
				shuffled = false;
			}
		}

		if (shuffled)
			cout << "B" << endl;
		else
			cout << "M" << endl;
	}
}

