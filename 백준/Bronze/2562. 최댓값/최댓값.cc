#include <bits/stdc++.h>
using namespace std;

int main(){
	int num[9];
	for(int i=0; i<9; i++) scanf("%d", &num[i]);
	int max = num[0], index=0;
	for(int j=0; j<9; j++){
		if(max < num[j]){
			max = num[j];
			index = j;
		}
	}
	
	printf("%d\n", max);
	printf("%d", index+1);
	return 0;
}