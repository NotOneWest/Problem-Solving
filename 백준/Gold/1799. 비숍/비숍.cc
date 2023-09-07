#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, ans[2]={0,0}, board[11][11], l[21], r[21];

void chess(int x, int y, int cnt, int color){
	if(y>=n){
		x++;
		if(y%2==0) y=1;
		else y=0;
	}
	if(x>=n){
		ans[color]=max(ans[color],cnt);
		return;
	}
	if(board[x][y]==1 && l[y-x+n-1]==0 && r[x+y]==0){
		l[y-x+n-1]=1; // =인데 ==으로 씀;;;;;;
		r[x+y]=1;
		chess(x,y+2,cnt+1,color);
		l[y-x+n-1]=0;
		r[x+y]=0;
	}
	chess(x,y+2,cnt,color); // 불가능할때 다음 넘겨주는 것을 안해줫었음.
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> board[i][j];
	}
	chess(0,0,0,0);
	chess(0,1,0,1);
	cout << ans[0]+ans[1] << '\n';
	return 0;
}
