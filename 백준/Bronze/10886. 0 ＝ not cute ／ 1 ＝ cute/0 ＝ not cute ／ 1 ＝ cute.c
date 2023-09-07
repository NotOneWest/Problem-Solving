#include <stdio.h>

int main(){
	
	int num, zero=0, one=0;
	scanf("%d",&num);
	
	int answer[num];
	
	for(int i=0; i<num; i++) scanf("%d",&answer[i]);
	
	for(int j=0; j<num; j++){
		if(answer[j]==0) zero ++;
		else one++;
	}
	if(zero>one) printf("Junhee is not cute!");
	else printf("Junhee is cute!");
	
	return 0;
	
}