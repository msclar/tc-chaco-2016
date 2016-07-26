#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n, res = 0;
	char lastChar, nextChar;

	cin >> n;	
	cin >> nextChar;
	for (int i = 1; i < n; i++) {
		lastChar = nextChar;		
		cin >> nextChar;
		if (lastChar == nextChar)
			res++;
	} 
	cout << res << endl;
}
