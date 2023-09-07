#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, m, r, c, d, house[51][51], ans=0;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  cin >> r >> c >> d;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) cin >> house[i][j];
  }
  while(true){
    if(house[r][c]==0){
      ans++;
      house[r][c]=-1;
    }
    int cleaned=0;
    for(int i=0; i<4; i++){
      d=(d+3)%4;
      if(house[r+dx[d]][c+dy[d]]==0){
        r+=dx[d];
        c+=dy[d];
        cleaned=1;
        break;
      }
    }
    if(cleaned) continue; // 청소 되었으면 계속 진행
    if(house[r-dx[d]][c-dy[d]]==1) break;
    r-=dx[d];
    c-=dy[d];
  }
  cout << ans << "\n";
	return 0;
}
