#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1}, visited[26], Max=0, r, c;
char board[21][21];

void dfs(int x, int y, int cnt){
  if(cnt>Max) Max=cnt;
  for(int i=0; i<4; i++){
    int nx=(x+dx[i]), ny=(y+dy[i]);
    if(nx>=0 && nx<r && ny>=0 && ny<c){
      if(visited[board[nx][ny]-'A']==0){
        visited[board[nx][ny]-'A']=1;
        dfs(nx,ny,cnt+1);
        visited[board[nx][ny]-'A']=0; // 처음 루트로 탐색하고 다른 루트 가기 위해 초기화...
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++) cin >> board[i][j];
  }
  visited[board[0][0]-'A']=1; // 처음 위치는 무조건 방문 표시
  dfs(0,0,1);
  cout << Max << '\n';
	return 0;
}
