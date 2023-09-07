#include <stdio.h>

int main(){
	
	int score[4];
	int sum=0, max=0, rank;
	
	for(int i=0; i<5; i++){
		for(int j=0; j<4; j++){
			scanf("%d", &score[j]);
			sum += score[j];
		}
		if(max<sum){
			max = sum;
			rank = i+1;
		}
		sum=0;
	}
	
	printf("%d %d", rank, max);
	
	return 0;
}