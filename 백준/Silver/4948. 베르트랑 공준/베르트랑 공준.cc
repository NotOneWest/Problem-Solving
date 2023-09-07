#include <bits/stdc++.h>
using namespace std;

int check[123456*2+1]={1,0,};

int main(){
	while(1){
		int n, cnt=0; cin >> n;
		if(n == 0) break;
		for(long long i=2; i<=n; i++){
			for(long long j=i; i*j<=2*n; j++) check[i*j] = 1;
		}
		for(int t=n+1; t<=2*n; t++){
			if(check[t] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}