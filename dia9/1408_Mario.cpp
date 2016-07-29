#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
#define DEBUGN(x) printf("%s = %d\n", #x, x)
#define DEBUGM printf
#define DEBUG_PAUSE() getchar(); getchar();
#else
#define DEBUGN(x)
#define DEBUGM(x...)
#define DEBUG_PAUSE()
#endif

#define DEBUGS() DEBUGM("\n\n********************\n\n")

int main(){

    int vazios[100000];
    
    for(;;){
	
	int n, l, max_vazios = 0;

	scanf("%d %d", &n, &l);

	if(!n && !l) break;
	
	for(int j = 0; j < l; j++){
	    scanf("%d", &vazios[j]);
	}

	for(int j = 0; j < l; j++){
	    
	    int i_ultimo = lower_bound(vazios, vazios + l, vazios[j] + n - 1) - vazios;
	    
	    if(i_ultimo < l){
		DEBUGM("Último de %d: %d\n", vazios[j], vazios[i_ultimo]);
		DEBUGN(j);
		int passou = (vazios[i_ultimo] >= vazios[j] + n ? 1 : 0);
		DEBUGN(passou);
		int n_vazios = i_ultimo - j - passou + 1;
		DEBUGM("n_vazios: %d\n", n_vazios);
		max_vazios = max(max_vazios, n_vazios);
	    }
	    else {
		DEBUGM("De %d até o final\n", vazios[j]);
		max_vazios = max(max_vazios, l - j);
		DEBUGN(l - j);
		break;
	    }
	    
	}
	

	printf("%d\n", n - max_vazios);

	DEBUGS();

    }

    return 0;
}
