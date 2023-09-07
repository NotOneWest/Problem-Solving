#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[501][501], num[501][501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      int x; cin >> x;
      num[i][j]=x;
    }
  }
	dp[0][0]=num[0][0];
	for(int i=1; i<n; i++) dp[i][0]=dp[i-1][0]+num[i][0];
	for(int i=1; i<n; i++) dp[i][i]=dp[i-1][i-1]+num[i][i];
	for(int i=2; i<n; i++){
		for(int j=1; j<i; j++){
			dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+num[i][j];
		}
	}
	ll maxnum=0;
	for(int i=0; i<n; i++) maxnum=max(maxnum, dp[n-1][i]);
	cout << maxnum << '\n';
	return 0;
}
