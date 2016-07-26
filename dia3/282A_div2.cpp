#include <iostream>
using namespace std;

int main () {
	int n, res = 0;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str[1] == '+')
			res++;
		else
			res--;
	}
	cout << res << endl;
}

