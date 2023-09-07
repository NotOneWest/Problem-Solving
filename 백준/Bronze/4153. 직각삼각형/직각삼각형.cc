#include <bits/stdc++.h>
using namespace std;

int main(){
	int num[3];
	while(1){
		for(int i=0; i<3; i++) scanf("%d", &num[i]);
		if( (num[0] + num[1] + num[2]) == 0 ) break;
		sort(num, num+3);
		if( pow(num[2], 2) == pow(num[1], 2) + pow(num[0], 2)) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}