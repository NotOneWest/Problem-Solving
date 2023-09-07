#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int board[1001][1001], visited[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,p; cin >> n >> m >> p;
  int si[10], cnt[10]={0,};
  queue<pii> q[10];
  for(int i=1; i<=p; i++) cin >> si[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char c; cin >> c;
      if(c>'0' && c<='9'){
        board[i][j]=(c-'0');
        q[c-'0'].push(mp(i,j));
        cnt[c-'0']++;
      } else{
        if(c=='.') board[i][j]=0;
        else board[i][j]=-1;
      }
    }
  }
  while(1){
    for(int i=1; i<=p; i++){
      int cursi=si[i];
      while(!q[i].empty() && cursi--){
        int size=q[i].size();
        for(int t=0; t<size; t++){
          int curx=q[i].front().first, cury=q[i].front().second;
          q[i].pop();
          for(int j=0; j<4; j++){
            int nx=curx+dx[j], ny=cury+dy[j];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]==0){
              board[nx][ny]=i;
              q[i].push(mp(nx,ny));
              cnt[i]++;
            }
          }
        }
      }
    }
    int check=0;
    for(int i=1; i<=p; i++){
      if(q[i].size()>0){
        check=1;
        break;
      }
    }
    if(check==0) break;
  }
  for(int i=1; i<=p; i++) cout << cnt[i] << ' ';
  cout << '\n';
	return 0;
}
