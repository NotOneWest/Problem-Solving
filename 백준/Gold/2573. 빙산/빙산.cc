#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int area[301][301], visit[301][301], n, m, year=0, num=0;
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void melt(int x, int y){
	queue<pii > q;
	visit[x][y]=1;
	q.push(mp(x,y));
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();
		for(int t=0; t<4; t++){
			int col = y + dxy[t][1];
			int row = x + dxy[t][0];
			if((col >=0 && col<n) && (row>=0 && row<m)){
				if(area[col][row] > 0 && visit[col][row]==0){
					visit[col][row]=1;
					q.push(mp(col,row));	
				}
				else if(area[col][row]==0 && visit[col][row]==0){
					if(area[y][x] > 0) area[y][x]--;
				}
			}
		}
	}
}

void bfs(int x, int y){
	queue<pii > q;
	visit[x][y]=1;
	q.push(mp(x,y));
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();
		for(int t=0; t<4; t++){
			int col = y + dxy[t][1];
			int row = x + dxy[t][0];
			if((col >=0 && col<n) && (row>=0 && row<m) && area[col][row] > 0 && visit[col][row]==0){
				visit[col][row]=1;
				q.push(mp(col,row));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> area[i][j];
	}
	while(1){
		for(int k=0; k<n; k++){
			fill(visit[k], visit[k]+m, 0);
		}
		year++;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(area[i][j]>0 && visit[i][j]==0) melt(i,j);
			}
		}
		for(int k=0; k<n; k++){
			fill(visit[k], visit[k]+m, 0);
		}
		num=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(area[i][j]>0 && visit[i][j]==0){
					bfs(i,j);
					num++;
				}
			}
		}
		if(num >= 2 || num==0) break;	
	}
	if(num==0) cout << 0;
	else cout << year;
	return 0;
}
