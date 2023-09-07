#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int maps[1001][1001] ,visit[1001][1001][2];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct wall_point{
	int x, y, chance ,distance;
	wall_point(int yy, int xx, int ch, int d){
		x = xx;
		y = yy;
		chance = ch;
		distance = d;
	}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m ,dis=-1; cin >> n >> m;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			maps[i][j]=s[j]-'0';
		}
	}
	queue<wall_point> q;
	q.push(wall_point(0,0,1,1));
	visit[0][0][0]=1;
	while(!q.empty()){
		int x = q.front().x, y = q.front().y, ch = q.front().chance ,d = q.front().distance;
		q.pop();
		if(x==m-1 && y==n-1){
			dis = d;
			break;
		}
		for(int t=0; t<4; t++){
			int col = y + dxy[t][0];
			int row = x + dxy[t][1];
			if((col >=0 && col<n) && (row>=0 && row<m)){
				if(ch == 1 && maps[col][row] == 1){
					visit[col][row][ch]=1;
					q.push(wall_point(col, row, 0, d+1));
				}
				else if(maps[col][row]==0 && visit[col][row][ch]==0){
					visit[col][row][ch]=1;
					q.push(wall_point(col, row, ch, d+1));
				}
			}
		}
	}
	cout << dis;
	return 0;
}