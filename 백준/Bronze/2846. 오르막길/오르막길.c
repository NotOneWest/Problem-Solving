#include <stdio.h>

int main(){
	
	int n, count=0, k=0;
	scanf("%d",&n);
	
	int pi[n], distance=0;
	for(int i=0; i<n; i++) scanf("%d", &pi[i]);
	
	int now = pi[0];
	
	for(int j=0; j<n; j++){
		
		if(pi[j]>now){
			count = count + (pi[j]-now);
			now = pi[j];
		}
		else{
			now=pi[j];
			if(distance < count) distance = count;
			count = 0;
		}
	}
	if(distance < count) distance = count;
	
	printf("%d", distance);
	
	return 0;
}