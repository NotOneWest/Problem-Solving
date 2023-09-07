#include <stdio.h>

int main(){
	
	int n,num,count=0;
	scanf("%d %d",&n,&num);
	
	int a[100000];
	for(int i=1; i<=n; i++) a[i-1] = i;
	
	for(int j=0; j<n; j++){
		
		while(1){
			
			if(a[j]<10){
				if(a[j] == num) count++;
				break;
			}
			
			else{
				int b = a[j]%10;
				if(b == num) count++;
				a[j] = a[j]/10;
			}
		}
	}
	
	printf("%d",count);
	
	return 0;
}