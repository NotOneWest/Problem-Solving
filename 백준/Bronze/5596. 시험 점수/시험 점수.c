#include <stdio.h>

int main(){
	
	int min[4], man[4], s=0, t=0;
	
	scanf("%d %d %d %d", &min[0], &min[1], &min[2], &min[3]);
	scanf("%d %d %d %d", &man[0], &man[1], &man[2], &man[3]);
	
	for(int i=0; i<4; i++){
		s += min[i];
		t += man[i];
	}
	
	if(s>=t) printf("%d", s);
	else printf("%d", t);
	
	return 0;
}