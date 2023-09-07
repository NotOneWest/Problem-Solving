#include <stdio.h>
#include <string.h>

int main(){
	
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	
	for(int i=0; i<len; i++){
		if(str[i] < 90 ) str[i]+=32;
		else str[i]-=32;
	}
	
	printf("%s\n", str);
	return 0;
	
}