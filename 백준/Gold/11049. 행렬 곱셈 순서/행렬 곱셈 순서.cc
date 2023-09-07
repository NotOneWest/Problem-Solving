#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[501][501], num[501][2];
int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> num[i][0] >> num[i][1];
	}
	
	for(int i=1; i<n; i++){ // 두개인 경우 연산 수 계산. 
		dp[i][i+1]=(num[i][0]*num[i][1]*num[i+1][1]);
	}
	// 두개 이상인 경우
	for(int d=2; d<n; d++){ // 행렬의 개수... (k+1)개 
		for(int i=1; i<=n-d; i++){
			int j=i+d;
			for(int k=i; k<j; k++){ // i부터 j까지 경유하여 모든 경우 계산. 
				ll sum=(dp[i][k]+dp[k+1][j]+(num[i][0]*num[k][1]*num[j][1]));
				if(dp[i][j]==0 || dp[i][j]>sum) dp[i][j]=sum;
			}
		}
	}
	cout << dp[1][n];
	return 0;
}