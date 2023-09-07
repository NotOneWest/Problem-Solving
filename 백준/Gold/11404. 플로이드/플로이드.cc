#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MAX=999999999;

int dp[101][101];
void floyd(int n){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
}

int main(){
	int n,m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j) dp[i][j]=MAX;
      else dp[i][j]=0;
		}
	}
	for(int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		dp[x][y]=min(dp[x][y],w);
	}
	floyd(n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dp[i][j]==MAX) dp[i][j]=0;
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
