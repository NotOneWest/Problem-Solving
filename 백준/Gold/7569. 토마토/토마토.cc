#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct tri{
	int x,y,z;
	tri(int a, int b, int c){
		z=a;
		y=b;
		x=c;
	}
};

int box[101][101][101];
int dxyz[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
queue< tri > q;

int main(){
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	
	int m,n,h,cnt=0; cin >> m >> n >> h;
	bool check = true;
	for(int t=0; t<h; t++){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> box[t][i][j];
				if(box[t][i][j] == 0) cnt++;
				else if(box[t][i][j] == 1) q.push(tri(t,i,j));
			}
		}
	}
	if(cnt==0) cout << 0;
	else{
		int day=0;
		while(!q.empty()){
			int size = q.size();
			for(int s=0; s<size; s++){
				int xx = q.front().x, yy = q.front().y, zz = q.front().z;
				q.pop();
				for(int t=0; t<6; t++){
					int hei = zz + dxyz[t][2];
					int col = yy + dxyz[t][0];
					int row = xx + dxyz[t][1];
					if((col >=0 && col<n) && (row>=0 && row<m) && (hei>=0 && hei<h)){
						if(box[hei][col][row] == 0){
							box[hei][col][row] = 1;
							q.push(tri(hei,col,row));
							cnt--;	
						}
					}
					if(cnt==0) break;
				}
			}
			day++;
		}
		if(cnt!=0) cout << -1;
		else cout << day-1;
	}
	return 0;
}