#include <stdio.h>
#include <string.h>

int main(){
	
	int players;
	scanf("%d", &players);
	
	char name[players][30], alpabet[26];
	for(int i=0; i<26; i++) alpabet[i]=0;
	for(int i=0; i<players; i++) scanf("%s", &name[i]);
	
	for(int j=0; j<players; j++){
		alpabet[name[j][0]-97]++;
	}
	int check=0;
	for(int k=0; k<26; k++){
		if(alpabet[k]>=5){
			check=1;
			printf("%c", k+97);
		}
	}
	if(check==0) printf("PREDAJA");
	
	return 0;
}