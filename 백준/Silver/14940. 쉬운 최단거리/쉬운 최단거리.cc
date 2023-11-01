#include <bits/stdc++.h>
using namespace std;

int maps[1001][1001];
int dist[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, x, y; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> maps[i][j];
			dist[i][j] = -1;
			if(maps[i][j] == 2){ x = i; y = j; }
		}
	}
	
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	dist[x][y] = 0;
	
	while(!q.empty()){
		x = q.front().first, y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(dist[nx][ny] != -1 || maps[nx][ny] == 0) continue;
			
			dist[nx][ny] = dist[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(maps[i][j] == 0) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
