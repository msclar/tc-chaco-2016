#include <iostream>
using namespace std;

int main () {
	string str;
	while (cin >> str) {
		int cantX = 0, XVistas = 0, ultimaX;
		for (int i = 0; i < (int) str.size(); i++)
			if (str[i] == 'x')
				cantX++;		
	
		int res = 0;
		for (int i = 0; i < (int) str.size(); i++) {
			if (str[i] == 'x') {
				if (XVistas == 0) {
					res = i;
				}
				else {
					res = max (res, (i - ultimaX - 1) / 2);
				}

				XVistas++;
				ultimaX = i;
			}
		}
		res = max (res, (int) str.size() - ultimaX - 1);
		cout << res << endl;
	}
}
