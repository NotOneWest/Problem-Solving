#include <stdio.h>

int main(){
	
	int day;
	scanf("%d",&day);
	int car_num[5];
	int count = 0;
	scanf("%d %d %d %d %d", &car_num[0], &car_num[1], &car_num[2], &car_num[3], &car_num[4]);
	
	for(int i=0; i<5; i++){
		if(car_num[i] == day) count ++;
	}
	
	printf("%d", count);
	return 0;
}