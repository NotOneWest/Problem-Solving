#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int geminis[9], startlink[9];
	
	for(int i=0; i<9; i++) scanf("%d", &geminis[i]);
	for(int i=0; i<9; i++) scanf("%d", &startlink[i]);
	
	int ug=0, sg=0, check=0;
	
	for(int i=0; i<9; i++){
		ug += geminis[i];
		if(ug > sg) check ++;
		sg += startlink[i];	
	}
	
	if(check > 0) printf("Yes");
	else printf("No");
	
	return 0;
}