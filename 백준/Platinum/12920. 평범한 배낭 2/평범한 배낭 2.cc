#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pii> vv;
int dp[2345][12345];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
  for(int i=0; i<n; i++){
    int v,c,k; cin >> v >> c >> k;
    int temp=1, flag=0;
    while((temp+flag)<=k){
			if(v*temp>m) break;
      vv.pb(mp(v*temp, c*temp));
			flag+=temp;
      temp=temp*2;
    }
		vv.pb(mp(v*(k-flag), c *(k-flag)));
  }
	sort(all(vv));
	int size=vv.size();
  for(int i=1; i<=size; i++){
    for(int j=1; j<=m; j++){
      if(j>=vv[i-1].first) dp[i][j]=max(dp[i-1][j], vv[i-1].second+dp[i-1][j-vv[i-1].first]);
      else dp[i][j]=dp[i-1][j];
    }
  }
	// for(int i=1; i<=size; i++){
  //   for(int j=1; j<=m; j++){
  //     cout << dp[i][j] << ' ';
  //   }
	// 	cout << '\n';
  // }
  cout << dp[size][m] << '\n';
	return 0;
}
