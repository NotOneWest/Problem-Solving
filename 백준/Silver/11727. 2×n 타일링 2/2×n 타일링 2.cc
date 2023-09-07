#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MOD = 10007;

int dp[1001];

void nums(int n){
	dp[1]=1;
	dp[2]=3;
	for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + 2*dp[i-2])%MOD;
}

int main(){
	int n; cin >> n;
	nums(n);
	cout << dp[n];
	return 0;
}