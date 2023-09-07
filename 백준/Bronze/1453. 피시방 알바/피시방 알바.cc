#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int cnt=0, seat[100]={0,};
	for(int k=0; k<n; k++){
		int p; cin >> p;
		if(seat[p-1]==0) seat[p-1]++;
		else cnt++;
	}
	printf("%d", cnt);
	return 0;
}