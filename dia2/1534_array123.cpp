#include <iostream>
using namespace std;

int main () {
	int n, arr[71][71];
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = 3;

		for (int i = 0; i < n; i++)
			arr[i][i] = 1;

		for (int i = 0; i < n; i++)
			arr[n-1-i][i] = 2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
}
