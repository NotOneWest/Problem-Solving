#include <stdio.h>

int main(){
	
	int N;
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(j<N-i) printf("*");
		}
		if(i<N-1) printf("\n");
	}
	
	return 0;
}