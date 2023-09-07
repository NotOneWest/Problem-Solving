#include <bits/stdc++.h>
using namespace std;

int main(){
	int rock; cin >> rock;
	int routine[1000] = {0,1,0,1,};
	
	for(int i=4; i<1000; i++){
		if(routine[i-1] + routine[i-3] + routine[i-4] == 3) routine[i]=0;
		else routine[i]=1;
	}
	if(routine[rock-1] == 1) printf("SK");
	else printf("CY");
	return 0;
}