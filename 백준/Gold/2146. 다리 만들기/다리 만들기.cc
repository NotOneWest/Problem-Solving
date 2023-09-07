#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int maps[101][101], visit[101][101],n,cnt=1,res=20000;
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

queue<pii > q;

void rabeling(int x, int y){
	q.push(mp(x,y));
	visit[x][y]=1;
	while(!q.empty()){
		int xx=q.front().first, yy=q.front().second;
		q.pop();
		maps[xx][yy]=cnt;
		for(int i=0; i<4; i++){
			int col=xx+dxy[i][0];
			int row=yy+dxy[i][1];
			if((0<=col && col<n) && (0<=row && row<n) && visit[col][row]==0 && maps[col][row]==1){
				q.push(mp(col,row));
				visit[col][row]=1;
			}
		}
	}
	cnt++;
}

int distance(int rabel){
	queue<pii > qq;
	for(int i=0; i<n; i++) fill(visit[i], visit[i]+n, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(maps[i][j]==rabel){
				qq.push(mp(i,j));
				visit[i][j]=1;
			}
		}
	}
	int d=0;
	while(!qq.empty()){
		int size=qq.size();
		for(int i=0; i<size; i++){
			int xx=qq.front().first, yy=qq.front().second;
			qq.pop();
			for(int j=0; j<4; j++){
				int col=xx+dxy[j][0];
				int row=yy+dxy[j][1];
				if((0<=col && col<n) && (0<=row && row<n)){
					if(maps[col][row]!=rabel && maps[col][row]>0) return d;
					else if(maps[col][row]==0 && visit[col][row]==0){
						visit[col][row]=1;
						qq.push(mp(col,row));
					}
				}
			}
		}
		d++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> maps[i][j];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visit[i][j]==0 && maps[i][j]==1) rabeling(i,j);
		}
	}
	for(int i=1; i<cnt; i++){
		int dis=distance(i);
		if(res>dis) res=dis;
	}
	cout << res;
	return 0;
} 