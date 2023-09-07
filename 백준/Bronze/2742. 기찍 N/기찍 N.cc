#include <stdio.h>

int main(){
	
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<N-1; i++) printf("%d\n", N-i);
	printf("%d", 1);
	
	return 0;
}