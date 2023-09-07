#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int v, h; cin >> v >> h;
	int draw[502][502];
	for(int i=0; i<v; i++){
		for(int j=0; j<h; j++) cin >> draw[i][j];
	}
	int num=0, bigarea=0;
	for(int i=0; i<v; i++){
		for(int j=0; j<h; j++){
			if(draw[i][j] != 1) continue;
			num++;
			queue< pii > q;
			draw[i][j] = -1;
			q.push(mp(i,j));
			
			int area=0;
			while(!q.empty()){
				area++;
				int row,col;
				row = q.front().second;
				col = q.front().first;
				q.pop();
				if(col+1 < v){
					if(draw[col+1][row] == 1){
						draw[col+1][row] = -1;
						q.push(mp(col+1, row));
					}
				}
				if(row+1 < h){
					if(draw[col][row+1] == 1){
						draw[col][row+1] = -1;
						q.push(mp(col, row+1));
					}
				}
				if(col-1 >= 0){
					if(draw[col-1][row] == 1){
						draw[col-1][row] = -1;
						q.push(mp(col-1, row));
					}
				}
				if(row-1 >= 0){
					if(draw[col][row-1] == 1){
						draw[col][row-1] = -1;
						q.push(mp(col, row-1));
					}
				}
			}
			
			if(area > bigarea) bigarea = area;
		}
	}
	cout << num << '\n' << bigarea;
	return 0;
}
