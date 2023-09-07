#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int n; cin >> n;
    int dp[2][n];
    int cost[2][n];
    for(int j=0; j<2; j++){
      for(int c=0; c<n; c++){
        int x; cin >> x;
        cost[j][c]=x;
      }
    }
    if(n>=2){
			dp[0][0]=cost[0][0];
	    dp[1][0]=cost[1][0];
	    dp[0][1]=(dp[1][0]+cost[0][1]);
	    dp[1][1]=(dp[0][0]+cost[1][1]);
	    for(int j=2; j<n; j++){
	      dp[0][j]=max(dp[1][j-1]+cost[0][j], dp[1][j-2]+cost[0][j]);
	      dp[1][j]=max(dp[0][j-1]+cost[1][j], dp[0][j-2]+cost[1][j]);
	    }
	    cout << max(dp[1][n-1], dp[0][n-1]) << '\n';
		} else cout << max(cost[0][0], cost[1][0]) << '\n';
  }
  return 0;
}
