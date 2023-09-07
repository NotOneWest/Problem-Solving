#include <stdio.h>

int main(){
	int time[4];
	int length = sizeof(time)/sizeof(time[0]);
	int sum =0;
	
	for(int i=0; i<length; i++) scanf("%d",&time[i]);
	for(int j=0; j<length; j++) sum += time[j];
	
	printf("%d\n", sum/60);
	printf("%d", sum%60);
	
	return 0; 
}