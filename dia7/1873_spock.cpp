#include <iostream>
using namespace std;

int main () {
	// rock, paper, scissors, lizard, spock
	string names[5] = {"pedra", "papel", "tesoura", "lagarto", "spock"}, str[2];
	int winners[5][5] = {{0, 0, 1, 1, 0},
						 {1, 0, 0, 0, 1},
						 {0, 1, 0, 1, 0},
						 {0, 1, 0, 0, 1},
						 {1, 0, 1, 0, 0}};

	int n, index[2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[0] >> str[1];
		
		if (str[0] == str[1]) {
			cout << "empate" << endl;
			continue;
		}	

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 5; k++) {
				if (str[j] == names[k]) {
					index[j] = k;
					break;
				}
			}
		}

		if (winners[index[0]][index[1]])
			cout << "rajesh" << endl;
		else
			cout << "sheldon" << endl;
	}
}
