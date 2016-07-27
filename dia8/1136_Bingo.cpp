#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n, b, balls[100];
	bool posible[100];

	while ((cin >> n >> b) && !(n == 0 && b == 0)) {
		for (int i = 0; i <= n; i++)
			posible[i] = false;

		for (int i = 0; i < b; i++)
			cin >> balls[i];
		
		for (int i = 0; i < b; i++)
			for (int j = 0; j < b; j++)
				posible[(int) abs(balls[i] - balls[j])] = true;

		int res = 0;
		for (int i = 0; i <= n; i++)
			res += posible[i];

		if (res == n+1)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
