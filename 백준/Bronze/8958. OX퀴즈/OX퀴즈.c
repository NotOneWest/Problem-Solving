#include <stdio.h>
#include <string.h>

int main(){
	
	int num, sum, score;
	scanf("%d", &num);
	for(int i=0; i<num; i++){
		char str[80];
		scanf("%s", str);
		sum = 0;
		score = 1;
		for(int j=0; j<strlen(str); j++){
			if(str[j] == 'O'){
				sum += score;
				score++;
			}
			else score = 1;
		}
		printf("%d\n", sum);
	}
	
	return 0;

}