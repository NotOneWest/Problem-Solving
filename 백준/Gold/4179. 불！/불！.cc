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
  int r,c,result=0,flag=-1; cin >> r >> c;
  queue<pii> q, fire;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      char x; cin >> x;
      if(x=='#') board[i][j]=2;
      else if(x=='.') board[i][j]=0;
      else if(x=='F'){
        fire.push(mp(i,j));
        board[i][j]=-1;
      } else{
        q.push(mp(i,j));
        visited[i][j]=1;
        board[i][j]=3;
      }
    }
  }
  while(!q.empty()){
    int check=0, size=fire.size(); // 변수로 지정을 안해서 계속 for문 안 i 조건이 바뀌어서 for문이 의도한 것 보다 더 돌아감
    for(int i=0; i<size; i++){
      int curx=fire.front().first, cury=fire.front().second;
      fire.pop();
      for(int j=0; j<4; j++){
        int nx=(curx+dx[j]), ny=(cury+dy[j]);
        if(0<=nx && nx<r && 0<=ny && ny<c){
          if(board[nx][ny]==0 || board[nx][ny]==3){
            board[nx][ny]=-1;
            fire.push(mp(nx,ny));
          }
        }
      }
    }
    size=q.size(); // 변수로 지정을 안해서 계속 for문 안 i 조건이 바뀌어서 for문이 의도한 것 보다 더 돌아감
    for(int i=0; i<size; i++){
      int curx=q.front().first, cury=q.front().second;
      q.pop();
      if(curx==0 || curx==(r-1) || cury==0 || cury==(c-1)){
        result+=1;
        check=1;
        flag=0;
        break;
      }
      for(int j=0; j<4; j++){
        int nx=curx+dx[j], ny=cury+dy[j];
        if(0<=nx && nx<r && 0<=ny && ny<c && visited[nx][ny]==0){
          if(board[nx][ny]==0){
            board[nx][ny]=3;
            visited[nx][ny]=1;
            q.push(mp(nx,ny));
          }
        }
      }
    }
    if(check) break;
    else result++;
  }
  if(flag==-1) cout << "IMPOSSIBLE\n";
  else cout << result << "\n";
	return 0;
}
