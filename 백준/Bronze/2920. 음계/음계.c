#include <stdio.h>

int main(){
	
	int scale[8], as=0, des=0, mix=0;
	for(int i=0; i<8; i++) scanf("%d", &scale[i]);
	
	for(int j=0; j<8; j++){
		if(scale[j] == j+1) as++;
		else if(scale[j] == 8-j) des++;
		else mix++;
	}
	
	if(as==8) printf("ascending");
	else if(des==8) printf("descending");
	else printf("mixed");
	
	return 0;
}