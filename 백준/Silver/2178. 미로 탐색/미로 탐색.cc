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
	int n, m; cin >> n >> m;
	int miro[502][502];
	int d[502][502]={0,};
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			miro[i][j] = s[j]-'0';
			d[i][j] = -1;
		}
	}
	queue< pii > q;
	d[0][0] = 1;
	q.push(mp(0,0));		
	while(1){
		int row,col;
		row = q.front().second;
		col = q.front().first;
		if(row == m-1 && col == n-1) break;
		q.pop();
		if(col+1 < n){
			if(miro[col+1][row] == 1 && d[col+1][row] < 0){
					d[col+1][row] = d[col][row]+1;
					q.push(mp(col+1, row));
			}
		}
		if(row+1 < m){
			if(miro[col][row+1] == 1 && d[col][row+1] < 0){
				d[col][row+1] = d[col][row]+1;
				q.push(mp(col, row+1));
			}
		}
		if(col-1 >= 0){
			if(miro[col-1][row] == 1 && d[col-1][row] < 0){
				d[col-1][row] = d[col][row]+1;
				q.push(mp(col-1, row));
			}
		}
		if(row-1 >= 0){
			if(miro[col][row-1] == 1 && d[col][row-1] < 0){
				d[col][row-1] = d[col][row]+1;
				q.push(mp(col, row-1));
			}
		}
	}
	cout << d[n-1][m-1];
	return 0;
}