#include <bits/stdc++.h>
using namespace std;

int campus[601][601];
int visited[601][601];
int n, m;

int move(int i, int j){
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	int cnt = 0;
		
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		visited[i][j] = 1;
		for(int i=0; i<4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || campus[nx][ny] == 2) continue;
			if(!visited[nx][ny]){
				if(campus[nx][ny] == 1) cnt++;
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int x, y; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c; cin >> c;
			if(c == 'O') campus[i][j] = 0;
			else if(c == 'P') campus[i][j] = 1;
			else if(c == 'X') campus[i][j] = 2;
			else{ campus[i][j] = 0; x = i; y = j; }
			visited[i][j] = 0;
		}
	}
	
	int ans = move(x, y);
	if(ans == 0) cout << "TT";
	else cout << ans;
	
	return 0;
}
