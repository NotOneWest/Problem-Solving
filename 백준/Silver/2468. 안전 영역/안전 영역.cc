#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int area[101][101], visit[101][101];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int n, max_h=0; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int h; cin >> h;
			area[i][j]=h;
			if(max_h < h) max_h = h;
		}
	}
	int max_num=0;
	for(int p=0; p<max_h; p++){
		for(int k=0; k<n; k++){
			fill(visit[k], visit[k]+n, 0);
		}
		queue< pii > q;
		int num=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(area[i][j]>p && visit[i][j]==0){
					num++;
					visit[i][j]=1;
					q.push(mp(i,j));
				}
				while(!q.empty()){
					int y = q.front().first, x = q.front().second;
					q.pop();
					for(int t=0; t<4; t++){
						int col = y + dxy[t][1];
						int row = x + dxy[t][0];
						if((col >=0 && col<n) && (row>=0 && row<n)){
							if(area[col][row] > p && visit[col][row]==0){
								visit[col][row]=1;
								q.push(mp(col,row));	
							}
						}
					}
				}
			}
		}
		if(max_num < num) max_num = num;
	}
	cout << max_num;
	return 0;
}
