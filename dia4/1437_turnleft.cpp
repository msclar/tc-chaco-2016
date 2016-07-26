#include <iostream>
using namespace std;

int main () {
	int n, a, b;
	string str;

	char dir[4] = {'N', 'L', 'S', 'O'};
	while (cin >> n) {
		if (n == 0)
			break;
		
		int res = 0;
		cin >> str;
		for (int i = 0; i < (int) str.size(); i++) {
			if (str[i] == 'D') {
				res++;
			}
			else {
				res += 3;
			}
		}
		cout << dir[res % 4] << endl;
	}
}
