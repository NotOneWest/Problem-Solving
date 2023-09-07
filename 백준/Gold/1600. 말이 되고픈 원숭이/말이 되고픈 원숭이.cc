#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int trip[201][201], visit[201][201][31];
int hxy[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int mxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct monkey{
	int x, y, chance, step;
	monkey(int yy, int xx, int ch, int s){
		x = xx;
		y = yy;
		chance = ch;
		step = s;
	}
};

int main(){
	int k, turn=-1; cin >> k;
	int w,h; cin >> w >> h;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> trip[i][j];
		}
	}
	queue<monkey> q;
	q.push(monkey(0,0,k,0));
	visit[0][0][k]=1;
	while(!q.empty()){
		int x=q.front().x, y=q.front().y, ch=q.front().chance , s=q.front().step;
		q.pop();
		if(y==h-1 && x==w-1){
			turn = s;
			break;
		}
		for(int t=0; t<4; t++){
			int col = y + mxy[t][0];
			int row = x + mxy[t][1];
			if((col>=0 && col<h) && (row>=0 && row<w)){
				if(trip[col][row]==0 && visit[col][row][ch]==0){
					visit[col][row][ch]=1;
					q.push(monkey(col, row, ch, s+1));
				}
			}
		}
		if(ch>0){
			for(int t=0; t<8; t++){
				int col = y + hxy[t][0];
				int row = x + hxy[t][1];
				if((col >=0 && col<h) && (row>=0 && row<w)){
					if(trip[col][row]==0 && visit[col][row][ch-1]==0){
						visit[col][row][ch-1]=1;
						q.push(monkey(col, row, ch-1, s+1));
					}
				}
			}
		}
	}
	cout << turn;
	return 0;
}
