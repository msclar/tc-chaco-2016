#include <cstdio>
using namespace std;

int vals[101];

int sq(int x){ return x * x; }

void calcular(){
    int f;
    for(int j = 0; j < 101; j++){
        f = 0;
        for(int t = 1; t <= j; t++){
            f += sq(j-t+1);
        }
        vals[j] = f;
    }
}

int main(){
    calcular();
    int n = 0;
    for(;;){
        scanf("%d", &n);
        if(n) printf("%d\n", vals[n]);
        else break;
    }

    return 0;
}

