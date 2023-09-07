#include <stdio.h>

int main(){
	
	int N;
	scanf("%d", &N);
	int mid = N/2;
	int draw = mid-1;
	if(N%2==0) printf("I LOVE CBNU");
	else{
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if (i==0) printf("*");
				else{
					if(i == 1){
						if(j != mid && j<mid) printf(" ");
						else if(j == mid) printf("*");
					}
					else{
						if(j==draw || j==(N-draw-1)){
							printf("*");
							if(j==(N-draw-1)) j++;
						}
						else if(j<(N-draw-1)) printf(" ");
					}
				}
			}
			if(i<N-mid) printf("\n");
			if(i>1) draw--;
		}
	}
		
	return 0;
}