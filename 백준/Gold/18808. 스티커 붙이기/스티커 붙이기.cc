#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,k,r,c,ans=0;
int note[41][41], sticker[11][11], copy_sticker[11][11];

void rotate(){ // 90도 회전 시키기
	for(int i=0; i<11; i++) memset(copy_sticker[i], 0, sizeof(copy_sticker[i]));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) copy_sticker[i][j]=sticker[i][j];
	}
	for(int i=0; i<c; i++){
		for(int j=0; j<r; j++) sticker[i][j]=copy_sticker[r-j-1][i];
	}
	swap(r,c);
}

bool check(int x, int y){ // x,y 노트 시작 위치
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(note[x+i][y+j]==1 && sticker[i][j]==1) return false;
		}
	}
	for(int i=0; i<r; i++){ // 스티커 자리만 바꿔야 했는데 그냥 0인 부분도 바꿔버리는 미스...
		for(int j=0; j<c; j++){
			if(sticker[i][j]==1) note[x+i][y+j]=1;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for(int sticker_num=0; sticker_num<k; sticker_num++){
		cin >> r >> c;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++) cin >> sticker[i][j];
		}
		for(int angle=0; angle<4; angle++){
			bool flag = false;
			for(int i=0; i<=n-r; i++){ // 전부 탐색하는 것이 아니라 스티커가 범위를 안 벗어나게 탐색;;
				if(flag) break;
				for(int j=0; j<=m-c; j++){
					if(check(i,j)){
						flag=true;
						break;
					}
				}
			}
			if(flag) break;
			rotate();
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(note[i][j]) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
