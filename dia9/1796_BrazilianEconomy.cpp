#include <iostream>
using namespace std;

int main () {
	int q, x, suma[] = {0, 0};
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> x;		
		suma[x]++;
	}

	if (suma[0] > suma[1])
		cout << "Y" << endl;
	else
		cout << "N" << endl;
}
