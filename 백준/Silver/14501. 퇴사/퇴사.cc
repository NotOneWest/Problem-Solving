#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int t[16], p[16], dp[16];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0; i<16; i++) dp[i]=0;
	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> t[i] >> p[i];
	
	for(int j=(n-1); j>=0; j--){
		if(t[j] > (n-j)) dp[j] = dp[j+1];
		else dp[j] = max(dp[j+1], p[j]+dp[j+t[j]]);
	}
	cout << dp[0] << '\n';
	return 0;
}