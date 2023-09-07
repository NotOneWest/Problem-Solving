#include <stdio.h>

int main(){
	
	int N,X;
	scanf("%d %d", &N, &X);
	
	int num[N];
	for(int i=0; i<N; i++) scanf("%d", &num[i]);
	
	for(int j=0; j<N; j++){
		if(num[j]<X) printf("%d ", num[j]);
	}
	return 0;
}