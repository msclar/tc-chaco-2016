#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int main () {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort (a, a+n);

	int mexActual = 1; // este es el valor que busco asignarle al proximo elemento del arreglo
	for (int i = 0; i < n; i++) {
		if (mexActual <= a[i])
			mexActual++;
	}
	cout << mexActual << endl;
}
