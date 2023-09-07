#include <bits/stdc++.h>
using namespace std;

int main(){
	int y; cin >> y;
	if(y==1) printf("J7");
	else if(y==2) printf("K8");
	else if(y==3) printf("L9");
	else{
		y-=4;
		printf("%c%d", 65+y%12, y%10);
	}
	return 0;	
}