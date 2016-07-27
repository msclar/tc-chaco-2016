#include <iostream>
using namespace std;

int main () {
	string str;
	while (cin >> str) {
		int res = 0;
		for (int i = 0; i < (int) str.size(); i++) {
			if (str[i] == ')' && res == 0) {
				res = -1;
				break;
			}

			if (str[i] == '(')
				res++;

			if (str[i] == ')')
				res--;
		}
		if (res == 0)
			cout << "correct" << endl;
		else
			cout << "incorrect" << endl;
	}
}
