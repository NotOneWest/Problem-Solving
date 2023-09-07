#include <stdio.h>
#include <string.h>

int main(){
	
	char str[101];
	scanf("%s", &str);
	
	int len = strlen(str);
	
	for(int i=0; i<len; i++){
		if(i%10 == 9) printf("%c\n", str[i]);
		else printf("%c", str[i]);
	}
	
	return 0;
}