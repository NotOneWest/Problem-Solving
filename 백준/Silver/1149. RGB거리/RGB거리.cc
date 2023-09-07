#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[1001][3], money[1001][3];

void sum(int n){
	for(int i=0; i<3; i++) dp[1][i]=money[1][i];
	for(int i=2; i<=n; i++){
		dp[i][0]=min(dp[i-1][1], dp[i-1][2])+money[i][0];
		dp[i][1]=min(dp[i-1][0], dp[i-1][2])+money[i][1];	
		dp[i][2]=min(dp[i-1][0], dp[i-1][1])+money[i][2];
	}
}

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> money[i][0] >> money[i][1] >> money[i][2];
	}
	sum(n);
	int cost=0;
	cost=min({dp[n][0], dp[n][1], dp[n][2]});
	cout << cost;
	return 0;
}
