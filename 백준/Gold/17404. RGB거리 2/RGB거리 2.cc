#include <bits/stdc++.h>
using namespace std;

int cost[1001][3];
int dp[1001][3];
int INF = 1000*1000 + 1;

void init(){
	for(int i=0; i<1001; i++){
		for(int j=0; j<3; j++) dp[i][j] = INF;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++) cin >> cost[i][j];
	}
	
	int ans = INF;
	for(int k=0; k<3; k++){
		init();
		dp[0][k] = cost[0][k];
		
		for(int i=1; i<n; i++){
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
			dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[i][2];		
		}
		dp[n-1][k] = INF;
		ans = min(min(ans, dp[n-1][0]), min(dp[n-1][1], dp[n-1][2]));	
	}
	
	cout << ans << '\n';
	return 0;
}
