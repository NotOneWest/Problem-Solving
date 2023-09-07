#include <bits/stdc++.h>
using namespace std;

int main(){
	int x1[2]={0,1}, x2[2]={0,}, y1[2]={0,1}, y2[2]={0,};
	scanf("%d %d", &x1[0], &y1[0]);
	for(int i=0; i<2; i++){
		int x,y; cin >> x >> y;
		if(x != x1[0]){
			x2[0] = x;
			x2[1]++;
		}
		else x1[1]++;		
		
		if(y != y1[0]){
			y2[0] = y;
			y2[1]++;
		}
		else y1[1]++;
	}
	if(x1[1] == 2) printf("%d ", x2[0]);
	else printf("%d ", x1[0]);
	if(y1[1] == 1) printf("%d ", y1[0]);
	else printf("%d ", y2[0]);
	return 0;
}