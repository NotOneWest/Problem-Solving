#include <stdio.h>

int main(){
	
	int w[10], k[10];
	int w_sum=0,k_sum=0,temp;
	
	for(int i=0; i<20; i++){
		if(i<10) scanf("%d", &w[i]);
		else scanf("%d", &k[i-10]);
	}
	
	for(int j = 1; j < 10; j++){
		for(int t = 0; t < 10; t++){
			if(w[j] > w[t]){
				temp = w[j];
				w[j] = w[t];
				w[t] = temp;
			}
			if(k[j] > k[t]){
				temp = k[j];
				k[j] = k[t];
				k[t] = temp;
			}
		}
	}
	w_sum = w[0] + w[1] + w[2];
	k_sum = k[0] + k[1] + k[2];
	
	printf("%d %d", w_sum, k_sum);
	
	return 0;
}