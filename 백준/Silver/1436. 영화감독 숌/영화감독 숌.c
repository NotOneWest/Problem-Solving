#include <stdio.h>

int main(){
	
	int N, k=0, t=666, check, six=0;
	scanf("%d",&N);
	
	int title[N];
	for(int i=0; i<N; i++) title[i]=0;
	
	while(k<N){
		
		check=t;
		while(check>10){
			if(check%10 == 6) six++;
			else if(six>0 && six<3){
				if(check%10 == 6) six++;
				else six=0;
			}
			check = check/10;
		}
		if(check == 6) six++;
		
		if(six >= 3){
			title[k] += t;
			k++;
		}
		
		six=0;
		t++;	
	}
	six=0;
	
	printf("%d", title[N-1]);
	
	return 0;
	
}