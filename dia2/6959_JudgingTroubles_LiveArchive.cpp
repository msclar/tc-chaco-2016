#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int n;
	string judge1[100001], judge2[100001];
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> judge1[i];

		for (int i = 0; i < n; i++)
			cin >> judge2[i];

		sort(judge1, judge1 + n);
		sort(judge2, judge2 + n);

		int i = 0, j = 0, res = 0;
		while (i < n && j < n) {
			if (judge1[i] == judge2[j]) {
				res++;
				i++; j++;
			}
			else if (judge1[i] < judge2[j]) {
				i++;
			}
			else {
				j++;
			}
		}
		cout << res << endl;
	}
}
