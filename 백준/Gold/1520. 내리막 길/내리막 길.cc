#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[501][501], num[501][501], n, m;
int dxy[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int dfs(int x, int y){
	if(x==1 && y==1) return 1; // 맨 처음이면 무조건 1가지. 
	
	if(dp[y][x]==-1){ // 방문 체크 
		dp[y][x]=0;
		for(int i=0; i<4; i++){
			int col=dxy[i][1]+y;
			int row=dxy[i][0]+x;
			if((1<=row && row<=m) && (1<=col && col<=n)){
				if(num[col][row]>num[y][x]){ // 뒤에서 부터 탐색 -- 큰거만 허용. 
					dp[y][x]+=dfs(row, col); // 길이 나눠지면 그만큼 더해줘야함. 
				}
			}
		}
	}
	return dp[y][x]; // 여기 까지 오는 경우의 수 
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> num[i][j];
			dp[i][j]=-1;
		}
	}
	cout << dfs(m,n);
	return 0;
}
