#include <iostream>
using namespace std;

int main () {
	int n;
	cin >> n;

	string str, one = "one";
	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str.size() == 5) {
			cout << 3 << endl;
			continue;
		}

		int similarities = 0;
		for (int j = 0; j < 3; j++) {
			if (str[j] == one[j])			
				similarities++;
		}
		
		if (similarities >= 2)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
}
