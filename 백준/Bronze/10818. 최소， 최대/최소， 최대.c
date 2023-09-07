#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int nums[n];
	for(int i=0; i<n; i++) scanf("%d", &nums[i]);
	
	int max = nums[0], min = nums[0];
	
	for(int j=0; j<n; j++){
		if(nums[j]>max) max = nums[j];
		if(nums[j]<min) min = nums[j];
	}
	
	printf("%d %d", min, max);
	
	return 0;
}