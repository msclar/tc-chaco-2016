#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main () {
	string str;
	cin >> str;

	int indicePunto = str.find('.'), indiceExponente = str.find('e');	
	int exponente = atoi(str.substr(indiceExponente+1).c_str());
	int decimales = atoi(str.substr(indicePunto+1, indiceExponente-indicePunto-1).c_str());
	int parteEntera = atoi(str.substr(0, indicePunto).c_str());

	for (int i = 0; i < indicePunto; i++)
		cout << str[i];

	// casos especiales: 0.0 o 1.0e0
	if ((parteEntera == 0 && decimales == 0) ||
	    (decimales == 0 && exponente == 0)) {
		cout << endl;		
		return 0;
	}

	for (int i = indicePunto + 1; i < indicePunto + 1 + exponente; i++) {
		if (i < indiceExponente)
			cout << str[i];
		else
			cout << 0;
	}
	if (indicePunto + 1 + exponente < indiceExponente)
		cout << '.';

	for (int i = indicePunto + 1 + exponente; i < indiceExponente; i++)
		cout << str[i];	

	cout << endl;
}
