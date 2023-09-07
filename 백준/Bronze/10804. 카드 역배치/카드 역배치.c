#include <stdio.h>

int main(){
	
	int card[20], range[10][2];
	for(int i=0; i<20; i++) card[i] = i+1;
	
	for(int j=0; j<10; j++){
		
		for(int i=0; i<2; i++) scanf("%d", &range[j][i]);
		
		int len = range[j][0]+range[j][1]-2;
		
		for(int k=range[j][0]-1; k<len/2+1; k++){
			int temp=card[k];
			card[k] = card[len-k];
			card[len-k] = temp;				
		}
	}
	
	for(int t=0; t<20; t++) printf("%d ", card[t]);
	
	return 0;
}