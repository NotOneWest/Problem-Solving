#include <bits/stdc++.h>
using namespace std;

int n, h[51], dp[51][500001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> h[i];
	
	dp[0][0] = 0;
	for(int i=1; i<=500000; i++) dp[0][i] = -1;
	
	// dp[i][j] : i번째 block 까지 고려했을 때 
	//			  h1, h2의 차이가 j 일 때의 최대 높이 (h1 >= h2 >= 0) 
	for(int i=1; i<=n; i++){
		for(int j=0; j<=500000; j++){
			// 1. i 번째 block 사용 X 
			// 		dp[i][j] = dp[i-1][j] (높이 차 유지)
			//(무조건 h1 >= h2 라고 하면) 
			// 2. h1에 쌓인 경우 : 
			//		j = h1 + h[i] - h2
			// 		h1 - h2 = j - h[i] (원래 높이 차) 
			// 		dp[i][j] = d[i-1][j-h[i]] + h[i] (최대 높이는 h1 + h[i])
			// 3. h2에 쌓인 경우 :
			//		1) h1 >= (h2 + h[i])
			//			j = h1 - (h2 + h[i])
			//			h1 - h2 = j + h[i] (원래 높이 차)
			//			dp[i][j] = dp[i-1][j+h[i]] (최대 높이는 그대로 h1) 
			//		2) h1 < (h2 + h[i])
			//			j = (h2 + h[i]) - h1
			//			h1 - h2 = h[i] - j (원래 높이 차)
			//			dp[i][j] = dp[i-1][h[i]-j] + j (최대 높이는 h2 + h[i] = h1 + j) 			
			dp[i][j] = dp[i-1][j];
			if(j>=h[i] && dp[i-1][j-h[i]] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] + h[i]);
			if((j+h[i])<=500000 && dp[i-1][j+h[i]] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j+h[i]]);
			if(j<=h[i] && dp[i-1][h[i]-j] != -1) dp[i][j] = max(dp[i][j], dp[i-1][h[i]-j] + j);
		}
	}
	
	if(dp[n][0] == 0) dp[n][0] = -1;
	cout << dp[n][0];
	return 0;
}
