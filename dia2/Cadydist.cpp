#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main(){

    int ns[100000], ps[100000];
    
    while(true){
	int N;
	scanf("%d", &N);
	if(!N) break;
	for(int j = 0; j < N; ++j)
	    scanf("%d", &ns[j]);

	for(int j = 0; j < N; ++j)
	    scanf("%d", &ps[j]);

	sort(ns, ns + N, less<int>());
	sort(ps, ps + N, greater<int>());

	long long t = 0;

	for(int j = 0; j < N; ++j) t += ((long long)ns[j]) * ps[j];
	printf("%lld\n", t);
    }
    
    
    return 0;
}

