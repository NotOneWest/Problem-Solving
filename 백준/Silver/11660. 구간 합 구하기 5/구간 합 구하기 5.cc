#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[1025][1025], num[1025][1025];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  for(int j=1; j<=n; j++){
    for(int i=1; i<=n; i++){
      ll x; cin >> x;
      num[j][i]=x;
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i==1) dp[i][j]=dp[i][j-1]+num[i][j];
      if(j==1) dp[i][j]=dp[i-1][j]+num[i][j];
      else dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+num[i][j]);
    }
  }
  for(int i=0; i<m; i++){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<< '\n';
  }
	return 0;
}
