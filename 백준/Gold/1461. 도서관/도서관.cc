#include <bits/stdc++.h>
using namespace std;

int n, m;
int pos[52];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> pos[i];
	sort(pos, pos+n+1);
	
	int zero=0;
	for(int i=0; i<=n; i++){
		if(pos[i] == 0){
			zero = i;
			break;
		}
	}
	
	int ans = 0;
	for(int i=0; i<zero; i+=m) ans -= (pos[i]*2);
	for(int i=n; i>zero; i-=m) ans += (pos[i]*2);
	
	ans -= max(abs(pos[0]), pos[n]);
	cout << ans << '\n';
	return 0;
}
