#include <iostream>
using namespace std;

int main () {
	int barras[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int res = 0;
		for (int j = 0; j < (int) str.size(); j++) {
			res += barras[str[j] - '0'];
		}
		cout << res << " leds" << endl;
	}
	return 0;
}
