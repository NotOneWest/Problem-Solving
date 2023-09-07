#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct tri{
	int first,second,t;
	tri(int firsts, int seconds, int ts){
		first = firsts;
		second = seconds;
		t = ts;
	}
};

char maps[1001][1001];
int visit[1001][1001], fired[1001][1001];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void clear() {
    for(int i=0; i<1001; i++) {
        fill(visit[i], visit[i]+1001, 0);
        fill(maps[i], maps[i]+1001, 0);
        fill(fired[i], fired[i]+1001, 0);
    }
}

int main(){
	int t; cin >> t;
	for(int p=0; p<t; p++){
		clear();
		int w,h,time=0; cin >> w >> h;
		bool check=false;
		queue<tri > q,qq,qqq;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				char ch; cin >> ch;
				if(ch=='@'){
					q.push(tri(i,j,0));
					visit[i][j]=1;
				}
				else if(ch=='*'){
					qq.push(tri(i,j,0));
					fired[i][j]=1;
				}
				maps[i][j]=ch;
			}
		}
		while(1){
			while(!q.empty()){
				int x=q.front().first, y=q.front().second, z=q.front().t;
				q.pop();
				if(maps[x][y]=='@'){
					if(x==0 || x==h-1 || y==0 || y==w-1){
						time=z+1;
						check=true;
						break;
					}
				}
				time++;
				for(int i=0; i<4; i++){
					int col=x+dxy[i][0];
					int row=y+dxy[i][1];
					if((0<=col && col<h) && (0<=row && row<w)){
						if(maps[col][row]=='.' && visit[col][row]==0){
							qqq.push(tri(col,row,z+1));
							visit[col][row]=1;
							maps[col][row]='@';
						}
					}
				}
			}
			if(qqq.empty()) break;
			if(check) break;
			while(!qqq.empty()){
				q.push(qqq.front());
				qqq.pop();
			}
			while(!qq.empty()){
				int x=qq.front().first, y=qq.front().second,z=qq.front().t;
				qq.pop();
				for(int i=0; i<4; i++){
					int col=x+dxy[i][0];
					int row=y+dxy[i][1];
					if((0<=col && col<h) && (0<=row && row<w)){
						if(maps[col][row]!='#' && fired[col][row]==0){
							qqq.push(tri(col,row,z+1));
							fired[col][row]=1;
							maps[col][row]='*';
						}
					}
				}
			}
			while(!qqq.empty()){
				qq.push(qqq.front());
				qqq.pop();
			}
		}
		if(!check) cout << "IMPOSSIBLE\n";
		else cout << time << '\n';
	}
	return 0;
}