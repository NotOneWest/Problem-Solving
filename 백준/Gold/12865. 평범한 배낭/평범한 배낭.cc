#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[101][100001];
vector<pii> vv;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,k; cin >> n >> k;
  for(int i=0; i<n; i++){
    int w,v; cin >> w >> v;
    vv.pb(mp(w,v));
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<=k; j++){
      if(j>=vv[i-1].first) dp[i][j]=max(dp[i-1][j], vv[i-1].second+dp[i-1][j-vv[i-1].first]); // 배낭 불러올떄 담기 전으로 했어야 했는데 그냥 그 직전으로함
      else dp[i][j]=dp[i-1][j];                                                               // dp[i][j-vv[i-1].first] -> 잘못된 것
    }
  }
	cout << dp[n][k] << '\n';
	return 0;
}
