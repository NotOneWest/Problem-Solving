#include <stdio.h>

int main(){
	
	int N, count=0;
	scanf("%d", &N);
	int score[N];
	for(int i=0; i<N; i++) scanf("%d", &score[i]);
	
	for(int j=0; j<N-1; j++){
		while(score[N-1-j]<=score[N-j-2]){
			score[N-2-j]--;
			count++;		
		}
	}
	
	printf("%d", count);
	return 0;
}