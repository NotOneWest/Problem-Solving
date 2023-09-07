#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int box[1001][1001];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue< pii > q;

int main(){
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	
	int m,n,cnt=0; cin >> m >> n;
	bool check = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> box[i][j];
			if(box[i][j] == 0) cnt++;
			else if(box[i][j] == 1) q.push(mp(i,j));
		}
	}
	if(cnt==0) cout << 0;
	else{
		int day=0;
		while(!q.empty()){
			int size = q.size();
			for(int s=0; s<size; s++){
				int x = q.front().first, y = q.front().second;
				q.pop();
				for(int t=0; t<4; t++){
					int col = x + dxy[t][0];
					int row = y + dxy[t][1];
					if((col >=0 && col<n) && (row>=0 && row<m) && box[col][row] == 0){
						box[col][row] = 1;
						cnt--;
						q.push(mp(col,row));
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