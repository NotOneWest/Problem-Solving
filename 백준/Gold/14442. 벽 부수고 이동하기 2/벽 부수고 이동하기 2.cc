#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int board[1001][1001], visited[1001][1001][11];
// 방문 표시를 하나로 하는게 아니라 꺠진 벽 개수에 따라 따로 해줘야했음...

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,k,result=-1; cin >> n >> m >> k;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(int j=0; j<m; j++){
      board[i][j]=(s[j]-'0');
    }
  }
  queue< pair<pii,pii> > q;
  q.push(mp(mp(0,0),mp(0,0)));
  visited[0][0][0]=1;
  while(!q.empty()){
    int curx=q.front().first.first, cury=q.front().first.second, curk=q.front().second.first, curdis=q.front().second.second;
    if(curx==(n-1) && cury==(m-1)){
      result=curdis+1;
      break;
    }
    q.pop();
    for(int i=0; i<4; i++){
      int nx=(curx+dx[i]), ny=(cury+dy[i]);
      if(0<=nx && nx<n && 0<=ny && ny<m && visited[nx][ny][curk]==0){
        if(board[nx][ny]==1 && curk<k){
          visited[nx][ny][curk]=1;
          q.push(mp(mp(nx,ny),mp(curk+1,curdis+1)));
        }
        else if(board[nx][ny]==0){
          visited[nx][ny][curk]=1;
          q.push(mp(mp(nx,ny),mp(curk,curdis+1)));
        }
      }
    }
  }
  cout << result << '\n';
	return 0;
}
