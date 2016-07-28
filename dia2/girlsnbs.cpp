#include <iostream>
using namespace std;

int main () {
	int g, b;
	while ((cin >> g >> b) && !(g == -1 && b == -1)) {
		if (g < b)
			swap(g, b);

		/* Tengo b varones para separar a las mujeres en b+1 grupos, luego la respuesta
		   es ceil(g / (b+1)) */
		cout << (g + b) / (b + 1) << endl;
	}
}
