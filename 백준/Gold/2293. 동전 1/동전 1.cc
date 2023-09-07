#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[10001]={1,}, num[101];

int main(){
	int n,k; cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> num[i];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(j>=num[i]) dp[j]+=dp[j-num[i]];
		}
	}
	cout << dp[k];
	return 0;
}
