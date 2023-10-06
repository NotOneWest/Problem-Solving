#include <bits/stdc++.h>
using namespace std;

int n, k, loc[10001], dis[10001], ans=0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> loc[i];
	
	if(n == 1) cout << 0 << '\n';
	else{
		sort(loc, loc+n);
		for(int i=0; i<(n-1); i++) dis[i] = (loc[i+1] - loc[i]);
		sort(dis, dis+n-1);
		
		for(int i=0; i<(n-k); i++) ans += dis[i];
		cout << ans << '\n';
	}
	return 0;
}