#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct loc{
	int x,y,z;
	loc(int zz, int yy, int xx){
		x=xx;
		y=yy;
		z=zz;
	}
};

int tower[31][31][31], cnt[31][31][31];
int dxyz[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};

int main(){
	int l,r,c;
	while(1){
		int al=0,ar=0,ac=0;
		cin >> l >> r >> c;
		if((l+r+c)==0) break;
		queue<loc> q;
		for(int i=0; i<l; i++){
			for(int j=0; j<r; j++){
				for(int t=0; t<c; t++){
					char ch; cin >> ch;
					if(ch=='S'){
						q.push(loc(i,j,t));
						cnt[i][j][t]=0;
					}
					else if(ch=='E'){
						al=i;
						ar=j;
						ac=t;
					}
					tower[i][j][t]=ch;
					cnt[i][j][t]=-1;
				}
			}
		}
		while(!q.empty()){
			int x=q.front().x, y=q.front().y, z=q.front().z;
			q.pop();
			for(int t=0; t<6; t++){
				int hei = z + dxyz[t][2];
				int col = y + dxyz[t][0];
				int row = x + dxyz[t][1];
				if((col >=0 && col<r) && (row>=0 && row<c) && (hei>=0 && hei<l)){
					if( (tower[hei][col][row]=='.' || tower[hei][col][row]=='E') && cnt[hei][col][row] < 0){
						cnt[hei][col][row] = cnt[z][y][x]+1;
						q.push(loc(hei,col,row));	
					}
				}
			}
		}
		if(cnt[al][ar][ac] < 0) cout << "Trapped!\n";
		else {
			cout << "Escaped in ";
			cout << cnt[al][ar][ac]+1;
			cout << " minute(s).\n";
		}
	}
	return 0;
}
