#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int chess[301][301]={0,}, d[301][301]={0,};
int dxy[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int k; cin >> k;
		for(int t=0; t<k; t++){
			for(int p=0; p<k; p++) d[t][p]=-1;
		}
		int x,y; cin >> x >> y;
		int px,py; cin >> px >> py;
		queue<pii > q;
		q.push(mp(x,y));
		d[x][y]=0;
		while(!q.empty()){
			int xx=q.front().first, yy=q.front().second;
			q.pop();
			for(int j=0; j<8; j++){
				int xxx=xx+dxy[j][0];
				int yyy=yy+dxy[j][1];
				if( (xxx>=0 && xxx<k) && (yyy>=0 && yyy<k) && d[xxx][yyy] < 0){
					q.push(mp(xxx,yyy));
					d[xxx][yyy] = d[xx][yy]+1;
				}
			}
			if(d[px][py] >=0 ) break;
		}
		cout << d[px][py] << '\n';
	}
	return 0;
}
