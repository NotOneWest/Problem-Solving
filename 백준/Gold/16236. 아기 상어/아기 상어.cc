#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int maps[21][21], dis[21][21], shark_x, shark_y, shark_size=2, eat=0, fish_x=21, fish_y=21, fish_dis=401;
int movx[4]={0,-1,1,0}, movy[4]={-1,0,0,1}, n;

void bfs(int x, int y){
  queue<pii> q;
  q.push(mp(x,y));
  dis[x][y]=0;
  while(!q.empty()){
    int posx=q.front().first, posy=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int nx=posx+movx[i], ny=posy+movy[i];
      if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
      if(dis[nx][ny]!=-1 || maps[nx][ny]>shark_size) continue; // 방문 조건 헷갈림...
      dis[nx][ny]=dis[posx][posy]+1;
      if(maps[nx][ny]!=0 && maps[nx][ny]<shark_size){ // 물고기 없는 곳을 안지나침...
        if(fish_dis>dis[nx][ny]){
          fish_dis=dis[nx][ny];
          fish_x=nx;
          fish_y=ny;
        } else if(fish_dis == dis[nx][ny]){
          if(fish_x==nx){
            if(fish_y > ny) fish_y=ny;
          } else if(fish_x > nx){
            fish_x=nx;
            fish_y=ny;
          }
        }
      }
      q.push(mp(nx,ny));
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int x; cin >> x;
      maps[i][j]=x;
      if(x==9){
        shark_x=i;
        shark_y=j;
        maps[i][j]=0;
      }
    }
  }
  ll ans=0;
  while(true){
    fish_dis=401;
    fish_x=21;
    fish_y=21;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++) dis[i][j]=-1;
    }
    bfs(shark_x, shark_y);
    if(fish_x!=21 && fish_y!=21){
      ans+=dis[fish_x][fish_y];
      eat++;
      if(eat==shark_size){
        eat=0;
        shark_size++;
      }
      maps[fish_x][fish_y]=0;
      shark_x=fish_x; // 물고기 먹은 뒤 위치 바꿔주는것 잊음....
      shark_y=fish_y;
    } else break;
  }
  cout << ans << '\n';
	return 0;
}
