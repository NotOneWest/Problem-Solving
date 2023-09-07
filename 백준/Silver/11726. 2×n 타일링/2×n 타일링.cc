#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[1001], mod=10007;

void sum(int n){
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=n; i++) dp[i]=(dp[i-2]%mod+dp[i-1]%mod);
}

int main(){
	int n; cin >> n;
	sum(n);
	cout << dp[n]%mod;
	return 0;
}
