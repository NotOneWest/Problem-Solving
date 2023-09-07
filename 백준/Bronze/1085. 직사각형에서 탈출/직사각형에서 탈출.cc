#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,w,h;
	cin >> x >> y >> w >> h;
	
	int num[4];
	num[0] = x;
	num[1] = y;
	num[2] = w-x;
	num[3] = h-y;
	sort(num, num+4);
	
	printf("%d", num[0]);
	return 0;
}