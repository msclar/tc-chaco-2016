#include <iostream>
#include <algorithm>
using namespace std;

int tiles[101][101], best[101][101];
int main () {
	int t, h, w;

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> tiles[i][j];
			}
		}

		// best[i][j] = max (best[i-1][j-1], best[i-1][j], best[i-1][j+1]) + tiles[i][j] 

		for (int j = 0; j < w; j++)
			best[0][j] = tiles[0][j];

		for (int i = 1; i < h; i++) {
			for (int j = 0; j < w; j++) {
				best[i][j] = best[i-1][j];

				if (j >= 1)
					best[i][j] = max (best[i][j], best[i-1][j-1]);

				if (j+1 < w)
					best[i][j] = max (best[i][j], best[i-1][j+1]);

				best[i][j] += tiles[i][j];
			}
		}

		int maximo = 0;
		for (int j = 0; j < w; j++)
			maximo = max (maximo, best[h-1][j]);

		cout << maximo << endl;
	}
}
