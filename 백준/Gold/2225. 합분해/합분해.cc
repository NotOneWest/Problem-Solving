#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll MOD = 1000000000;
ll dp[201][201]; // k, N

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,k; cin >> n >> k;
  for(int i=0; i<201; i++){
    dp[0][i]=1;
    dp[1][i]=1;
    dp[i][0]=1;
  }
  for(int i=2; i<=k; i++){
    for(int j=1; j<=n; j++){
      for(int k=0; k<=j; k++){
        dp[i][j] += dp[i-1][k]%MOD;
      }
    }
  }
  cout << dp[k][n]%MOD << '\n';
	return 0;
}
