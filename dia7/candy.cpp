#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, input;
    while (cin >> n){
        if (n == -1)
		return 0;
       
        int total = 0, falta = 0;
        vector<int> v;
       
        for(int i = 0; i < n; i++){
            cin >> input;
            v.push_back(input);
            total += input;
        }
       
        if(total % n == 0){
            for(int i = 0; i < n; i++){
                falta += abs(v[i] - (total/n));
            }
           
            cout << falta/2 << endl;
        } else {
            cout << -1 << endl;
        }
       
       
    }
}
