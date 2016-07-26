#include <iostream>
using namespace std;

int abs (int n) {
	return (n > 0) ? n : -n;
} 

int main () {
	int k, origx, origy, x, y, vx, vy;
	int dirx[]     = {   1,    1,  -1,    -1};
	int diry[]     = {   1,   -1,  -1,     1};
	string names[] = {"NE", "SE", "SO", "NO"};
	while (cin >> k) {
		cin >> origx >> origy;
		if (k == 0)
			break;
		
		for (int i = 0; i < k; i++) {
			cin >> x >> y;			

			vx = x - origx;
			vy = y - origy;

			if (vx == 0 || vy == 0) {
				cout << "divisa" << endl;
				continue;			
			}

			vx /= abs(vx);
			vy /= abs(vy); // lo dejo como vectores unitarios
		
			for (int d = 0; d < 4; d++) {
				if (dirx[d] == vx && diry[d] == vy) {
					cout << names[d] << endl;
					break;
				}
			}
		}
	}
}
