#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

char lake[1501][1501];
int visit[1501][1501], melt[1501][1501], r, c;
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<pii > q, qq, qqq;

void find_melt_point(){ // 처음 녹는 위치 저장 
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(lake[i][j]=='X'){
				for(int t=0; t<4; t++){
					int col = i + dxy[t][0];
					int row = j + dxy[t][1];
					if((0<=col && col<r) && (0<=row && row<c)){
						if(lake[col][row]!='X'){
							melt[i][j]=1;
							qq.push(mp(i,j));
							break;
						}
					}	
				}
			}
		}
	}
} 

void melts(){
	while(!qq.empty()){
		int x=qq.front().first, y=qq.front().second;
		lake[x][y]='.';
		qq.pop();
		for(int j=0; j<4; j++){
			int col = x + dxy[j][0];
			int row = y + dxy[j][1];
			if((0<=col && col<r) && (0<=row && row<c) && melt[col][row]==0){
				if(lake[col][row]=='X'){
					melt[col][row]=1;
					qqq.push(mp(col,row)); // 다음 녹는 얼음 위치 미리 저장
				}
			}	
		}
	}
	while(!qqq.empty()){ // 다음 녹는 얼음 위치 미리 저장 
		qq.push(qqq.front());
		qqq.pop();
	}
}

int main(){
	cin >> r >> c;
	int ar=0,ac=0, day=0;
	for(int i=0; i<r; i++){
		string s; cin >> s;
		for(int j=0; j<c; j++){
			lake[i][j]=s[j];
			if(s[j]=='L'){
				if(q.empty()){
					q.push(mp(i,j));
					visit[i][j]=1;
				}
				else{
					ar=i;
					ac=j;
				}
			}
		}
	}
	find_melt_point();
	while(1){
		while(!q.empty()){
			int x=q.front().first, y=q.front().second;
			q.pop();
			for(int j=0; j<4; j++){
				int col = x + dxy[j][0];
				int row = y + dxy[j][1];
				if((0<=col && col<r) && (0<=row && row<c) && visit[col][row]==0){
					if(lake[col][row]!='X') q.push(mp(col,row));
					if(lake[col][row]=='X') qqq.push(mp(col,row)); // 미리 이동 가능한 백조 위치 저장 
					visit[col][row]=1;
				}	
			}
		}
		if(visit[ar][ac]) break;
		while(!qqq.empty()){ // 미리 이동 가능한 백조 위치 저장
			q.push(qqq.front());
			qqq.pop();
		}
		melts();
		day++;
	}
	cout << day;
	return 0;
}