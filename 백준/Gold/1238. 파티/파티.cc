#include <bits/stdc++.h>
using namespace std;

int cost[1001][1001];
int INF = 9999999;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, x; cin >> n >> m >> x;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}
	
	for(int i=0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		cost[a][b] = c;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i == j || cost[i][k] == INF || cost[k][j] == INF) continue;
				cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
			}
		}
	}

	int answer = 0;
	for(int i=1; i<=n; i++){
		if(i == x) continue;
		answer = max(answer, cost[i][x] + cost[x][i]);
	}
	cout << answer << '\n';

	return 0;
}
