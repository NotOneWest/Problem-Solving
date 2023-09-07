#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int board[101][101], times=0, dir=0, turn[10001];
deque<pii> dq;

void turnD(){
  if(dir==3) dir=0;
  else dir++;
}

void turnL(){
  if(dir==0) dir=3;
  else dir--;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,k,l; cin >> n >> k;
  for(int i=0; i<k; i++){
    int x,y; cin >> x >> y;
    board[x][y]=2;
  }
  cin >> l;
  for(int i=0; i<l; i++){
    int x;
    char y; cin >> x >> y;
    if(y == 'D') turn[x]=1;
    else turn[x]=2;
  }

  dq.push_front(mp(1,1));

  while(1){
    pii cur = dq.front();
    board[cur.first][cur.second] = 1;
    times++;

    int nx=cur.first, ny=cur.second;
    if(dir==0) ny++;
    else if(dir==1) nx++;
    else if(dir==2) ny--;
    else nx--;

    if(nx>n || nx<1 || ny>n || ny<1) break;
    if(board[nx][ny]==1) break;

    if(board[nx][ny]!=2){
      pii tail = dq.back();
      board[tail.first][tail.second] = 0;
      dq.pop_back();
    }
    if(turn[times]!=0){
      if(turn[times]==1) turnD();
      else turnL();
    }
    dq.push_front(mp(nx,ny));
  }
  cout << times << '\n';
	return 0;
}
