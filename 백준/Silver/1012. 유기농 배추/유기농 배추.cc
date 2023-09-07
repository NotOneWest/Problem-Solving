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
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int field[502][502];
		int m,n,k; cin >> m >> n >> k;
		for(int j=0; j<k; j++){
			int r,c; cin >> r >> c;
			field[c][r] = 1;
		}
		int num=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(field[i][j] != 1) continue;
				num++;
				queue< pii > q;
				field[i][j] = -1;
				q.push(mp(i,j));
				
				while(!q.empty()){
					int row,col;
					row = q.front().second;
					col = q.front().first;
					q.pop();
					if(col+1 < n){
						if(field[col+1][row] == 1){
							field[col+1][row] = -1;
							q.push(mp(col+1, row));
						}
					}
					if(row+1 < m){
						if(field[col][row+1] == 1){
							field[col][row+1] = -1;
							q.push(mp(col, row+1));
						}
					}
					if(col-1 >= 0){
						if(field[col-1][row] == 1){
							field[col-1][row] = -1;
							q.push(mp(col-1, row));
						}
					}
					if(row-1 >= 0){
						if(field[col][row-1] == 1){
							field[col][row-1] = -1;
							q.push(mp(col, row-1));
						}
					}
				}
			}
		}
		cout << num << '\n';
	}
	return 0;
}
