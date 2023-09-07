#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[301], num[301];
void sum(int n){
	dp[1]=num[1];
	dp[2]=(num[1]+num[2]);
	dp[3]=max(num[1]+num[3], num[2]+num[3]);
	for(int i=4; i<=n; i++){
		dp[i]=max(dp[i-2]+num[i], num[i]+num[i-1]+dp[i-3]);	
	}
}

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	sum(n);
	cout << dp[n];
	return 0;
}
