#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct five{
  int x;
  int y;
  int k_num;
  int dis;
  string day;
};

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
  // queue< pair< tuple<int, int, int>, pair<int, string> > > q;
  queue< five > q;
  struct five start={0,0,0,0,"morning"};
  q.push(start);
  visited[0][0][0]=1;
  while(!q.empty()){
    int curx=q.front().x, cury=q.front().y, curk=q.front().k_num, curdis=q.front().dis;
    string curt=q.front().day;
    if(curx==(n-1) && cury==(m-1)){
      result=curdis+1;
      break;
    }
    q.pop();
    for(int i=0; i<4; i++){
      int nx=(curx+dx[i]), ny=(cury+dy[i]);
      if(0<=nx && nx<n && 0<=ny && ny<m){
        if(board[nx][ny]==1 && curk<k && visited[nx][ny][curk+1]==0){
          if(curt=="morning"){
            visited[nx][ny][curk+1]=1;
            struct five f={nx,ny,curk+1,curdis+1,"night"};
            q.push(f);
          }
          else{
            struct five f={curx,cury,curk,curdis+1,"morning"};
            q.push(f);
          }
        }
        else if(board[nx][ny]==0 && visited[nx][ny][curk]==0){
          visited[nx][ny][curk]=1;
          if(curt=="morning"){
            struct five f={nx,ny,curk,curdis+1,"night"};
            q.push(f);
          } else{
            struct five f={nx,ny,curk,curdis+1,"morning"};
            q.push(f);
          }
        }
      }
    }
  }
  cout << result << '\n';
	return 0;
}
