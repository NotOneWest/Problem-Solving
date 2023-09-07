#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MAX=100001;

int dp[101][101], p[101][101], cnt;
void floyd(int n){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dp[i][j] > dp[i][k]+dp[k][j]){
					p[i][j]=k;
					dp[i][j]=dp[i][k]+dp[k][j];
				} 
			}
		}	
	}
}

void path(int s, int e){
	if(p[s][e]!=0){
		path(s,p[s][e]);
		cout << p[s][e] << ' ';
		cnt++;
		path(p[s][e],e);
	}
}

void findroute(int s, int e){
	if(p[s][e]!=0){
		cnt++;
		findroute(s,p[s][e]);
		findroute(p[s][e],e);
	}
}

int main(){
	int n,m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j) dp[i][j]=MAX;
		}
	}
	for(int i=0; i<m; i++){
		int x,y,w; cin >> x >> y >> w;
		dp[x][y]=min(dp[x][y],w);
	}
	floyd(n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dp[i][j]==MAX) dp[i][j]=0; // 갈 수 없을 때 처리 해줘야함. 
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dp[i][j]==0) cout << "0\n";
			else{
				cnt=2;
				findroute(i,j);
				cout << cnt << ' ';
				cout << i << ' ';
				path(i,j);
				cout << j << '\n';
			}
		}
	}
	return 0;
}
