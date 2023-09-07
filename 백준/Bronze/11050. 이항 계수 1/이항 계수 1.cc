#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	int ans=1;
	for(int i=n; i>n-k; i--) ans*=i;
	for(int i=1; i<=k; i++) ans/=i;
	printf("%d", ans);
	return 0; 
}