#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int room[101][101], light[101][101], visit[101][101];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, n, m, cnt=1;
vector< pii > v[101][101];
queue<pii > q;

bool bfs(){
	bool no_light=true;
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		if(light[x][y]==1){
			for(int t=0; t<v[x][y].size(); t++){
				if(room[v[x][y][t].first][v[x][y][t].second]==0){
					room[v[x][y][t].first][v[x][y][t].second]=1;
					cnt++;
				}		
			}
			light[x][y]=0;
			no_light=false;
		}
		for(int j=0; j<4; j++){
			int col = x + dxy[j][0];
			int row = y + dxy[j][1];
			if((0<=col && col<n) && (0<=row && row<n) && room[col][row]==1 && visit[col][row]==0){
				q.push(mp(col,row));
				visit[col][row]=1;
			}
		}
	}
	return no_light;
}

int main(){
	room[0][0]=1;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x,y,a,b; cin >> x >> y >> a >> b;
		light[x-1][y-1]=1;
		v[x-1][y-1].pb(mp(a-1,b-1));
	}
	while(1){
		for(int i=0; i<n; i++){
			fill(visit[i], visit[i]+n, 0);
		}
		q.push(mp(0,0));
		visit[0][0]=1;
		if(bfs()) break;	
	}
	printf("%d", cnt);
	return 0;
}
