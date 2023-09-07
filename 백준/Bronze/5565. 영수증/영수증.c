#include <stdio.h>

int main(){
	
	int all;
	scanf("%d",&all);
	int sum = 0;
	int price[9];
	
	for(int i=0; i<9; i++) scanf("%d",&price[i]);
	for(int j=0; j<9; j++) sum += price[j];
	
	printf("%d",all-sum);
	return 0; 
}